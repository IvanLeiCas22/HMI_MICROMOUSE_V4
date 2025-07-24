#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QDebug>
#include <QDataStream>
#include <QTextBlock>
#include <QMetaEnum>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow),
      serialPort(new QSerialPort(this)),
      m_parser(new UnerbusParser(this)),
      udpSocket(nullptr),
      sensorUpdateTimer(new QTimer(this))
{
    ui->setupUi(this);

    // Inicializar QButtonGroup para los botones de navegación
    navigationButtonGroup = new QButtonGroup(this);
    navigationButtonGroup->setExclusive(true);           // Solo un botón puede estar checked a la vez
    navigationButtonGroup->addButton(ui->btnHome, 0);    // ID 0 para la página de Inicio
    navigationButtonGroup->addButton(ui->btnSensors, 1); // ID 1 para la página de Sensores
    navigationButtonGroup->addButton(ui->btnConfig, 2);  // ID 2 para la página de Configuración
    // Conectar la señal buttonClicked del grupo al slot on_navigationButtonClicked
    connect(navigationButtonGroup, &QButtonGroup::buttonClicked, this, &MainWindow::on_navigationButtonClicked);
    ui->stackedScreens->setCurrentIndex(0); // Página de inicio

    // Conectar señales y slots para la comunicación serie
    connect(serialPort, &QSerialPort::readyRead, this, &MainWindow::onSerialPort_ReadyRead);
    connect(serialPort, &QSerialPort::errorOccurred, this, &MainWindow::handleSerialError);

    // Conectar el parser
    connect(m_parser, &UnerbusParser::packetReceived, this, &MainWindow::onPacketReceived);

    // --- Conectar el temporizador de sensores ---
    connect(sensorUpdateTimer, &QTimer::timeout, this, &MainWindow::requestSensorData);

    updateSerialPortList();
    updateUIState(false, false);                   // Estado inicial: desconectado
    updateConnectionStatus("Desconectado", "red"); // Establecer estado inicial

    populateCMDComboBox();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete navigationButtonGroup; // Liberar la memoria del QButtonGroup
}

/**
 * @brief Slot para manejar los clics en los botones de navegación.
 *        Cambia la página del QStackedWidget y asegura que el botón clicado esté checked.
 * @param button Puntero al QAbstractButton que fue clicado.
 */
void MainWindow::on_navigationButtonClicked(QAbstractButton *button)
{
    // Obtener el ID del botón (que hemos configurado para que sea el índice de la página)
    int pageIndex = navigationButtonGroup->id(button);

    // Cambiar la página del stacked widget
    ui->stackedScreens->setCurrentIndex(pageIndex);

    // El QButtonGroup ya se encarga de que solo un botón esté checked si setExclusive(true)
    // Por lo tanto, no necesitamos setChecked(true) aquí explícitamente para el botón clicado.
}

// --- Implementación de la lógica del puerto serie ---

void MainWindow::updateSerialPortList()
{
    const auto ports = QSerialPortInfo::availablePorts();

    ui->comboBoxPorts->clear();
    for (const QSerialPortInfo &port : ports)
    {
        ui->comboBoxPorts->addItem(port.portName(), port.systemLocation());
    }
}

void MainWindow::updateUIState(bool serialConnected, bool udpConnected)
{
    // Serie
    ui->comboBoxPorts->setEnabled(!serialConnected && !udpConnected);
    ui->btnRefreshPorts->setEnabled(!serialConnected && !udpConnected);
    ui->btnConnectSerie->setEnabled(!serialConnected && !udpConnected);
    ui->btnDisconnectSerie->setEnabled(serialConnected);

    // UDP
    ui->RemoteIpLineEdit->setEnabled(false);
    ui->RemotePortLineEdit->setEnabled(false);
    ui->localPortLineEdit->setEnabled(!udpConnected && !serialConnected);
    ui->btnConnectUDP->setEnabled(!udpConnected && !serialConnected);
    ui->btnDisconnectUDP->setEnabled(udpConnected);
}

void MainWindow::on_btnConnectSerie_clicked()
{
    if (ui->comboBoxPorts->currentText().isEmpty())
    {
        QMessageBox::critical(this, "Error", "No hay un puerto serie seleccionado.");
        return;
    }

    serialPort->setPortName(ui->comboBoxPorts->currentText());
    serialPort->setBaudRate(QSerialPort::Baud115200);
    serialPort->setDataBits(QSerialPort::Data8);
    serialPort->setParity(QSerialPort::NoParity);
    serialPort->setStopBits(QSerialPort::OneStop);
    serialPort->setFlowControl(QSerialPort::NoFlowControl);

    if (serialPort->open(QIODevice::ReadWrite))
    {
        updateUIState(true, false);
        updateConnectionStatus("Conectado por Serie", "green");
    }
    else
    {
        QMessageBox::critical(this, "Error de Conexión", "No se pudo abrir el puerto: " + serialPort->errorString());
        updateUIState(false, false);
        updateConnectionStatus("Desconectado", "red"); // Asegurar estado en caso de error
    }
}

void MainWindow::on_btnDisconnectSerie_clicked()
{
    if (serialPort->isOpen())
    {
        serialPort->close();
    }
    updateUIState(false, false);
    updateConnectionStatus("Desconectado", "red");
}

void MainWindow::on_btnRefreshPorts_clicked()
{
    updateSerialPortList();
}

void MainWindow::handleSerialError(QSerialPort::SerialPortError error)
{
    if (error == QSerialPort::ResourceError)
    {
        QMessageBox::critical(this, "Error Crítico", "El puerto serie fue desconectado o cerrado inesperadamente.");
        on_btnDisconnectSerie_clicked(); // Llama a la lógica de desconexión para resetear la UI
    }
}

void MainWindow::onSerialPort_ReadyRead()
{
    // Pasamos los datos al parser
    const QByteArray data = serialPort->readAll();
    m_parser->processData(data);
    qDebug() << "Datos recibidos del puerto serie:" << data.toHex(' ');
}

// --- NUEVO SLOT PARA PROCESAR PAQUETES ---
void MainWindow::onPacketReceived(quint8 command, const QByteArray &payload)
{
    // Usamos QDataStream para leer datos binarios de forma segura
    QDataStream stream(payload);
    stream.setByteOrder(QDataStream::LittleEndian); // ¡Muy importante! El protocolo es Little Endian

    qDebug() << "Paquete válido recibido! CMD:" << Qt::hex << command << "Payload:" << payload.toHex(' ');

    // Obtener el nombre del comando desde el enum
    QMetaEnum metaEnum = QMetaEnum::fromType<Unerbus::CommandId>();
    const char *commandNameCStr = metaEnum.valueToKey(command);
    QString commandName = commandNameCStr ? QString(commandNameCStr) : QString("Desconocido (0x%1)").arg(command, 2, 16, QChar('0').toUpper());

    // Formateamos el mensaje y lo mostramos en el QPlainText "commsLog"
    QString logMessage = QString("Recibido CMD: %1, Payload: %2")
                             .arg(commandName)
                             .arg(QString(payload.toHex(' ')));
    ui->commsLog->appendPlainText(logMessage);

    if (ui->commsLog->document()->blockCount() > MAX_LOG_LINES) // Limita el número de líneas en el log
    {
        // Mueve el cursor al inicio del documento
        QTextCursor cursor(ui->commsLog->document()->findBlockByNumber(0));
        // Selecciona el bloque completo (la primera línea)
        cursor.select(QTextCursor::BlockUnderCursor);
        // Elimina la selección
        cursor.removeSelectedText();
        // Elimina el salto de línea que puede quedar al inicio
        cursor.deleteChar();
    }

    // Aquí va la lógica para manejar cada comando
    switch (static_cast<Unerbus::CommandId>(command))
    {
    case Unerbus::CommandId::CMD_GET_ALIVE:
    {
        qDebug() << "Comando GET_ALIVE recibido.";
        break;
    }
    case Unerbus::CommandId::CMD_GET_LAST_ADC_VALUES:
    {
        updateIrSensorsUI(payload);
        break;
    }

    case Unerbus::CommandId::CMD_GET_MPU_DATA:
    {
        updateMpuSensorsUI(payload);
        break;
    }

    case Unerbus::CommandId::CMD_ACK:
    {
        qDebug() << "Comando ACK recibido.";
        break;
    }

        // ... agregar más casos para otros comandos que quieras manejar ...

    default:
        qDebug() << "Comando desconocido:" << Qt::hex << command;
        break;
    }
}

/**
 * @brief Rellena el ComboBox de comandos manualmente.
 * @note Se rellena manualmente para incluir solo los comandos de tipo GET
 *       que no requieren un payload, simplificando la interfaz de envío rápido.
 */
void MainWindow::populateCMDComboBox()
{
    ui->CMDComboBox->clear();
    ui->CMDComboBox->addItem("GET_ALIVE (0xF0)", static_cast<quint8>(Unerbus::CommandId::CMD_GET_ALIVE));
    ui->CMDComboBox->addItem("GET_BUTTON_STATE (0x12)", static_cast<quint8>(Unerbus::CommandId::CMD_GET_BUTTON_STATE));
    ui->CMDComboBox->addItem("GET_MPU_DATA (0xA2)", static_cast<quint8>(Unerbus::CommandId::CMD_GET_MPU_DATA));
    ui->CMDComboBox->addItem("GET_LAST_ADC_VALUES (0xA0)", static_cast<quint8>(Unerbus::CommandId::CMD_GET_LAST_ADC_VALUES));
    ui->CMDComboBox->addItem("GET_MOTOR_SPEEDS (0xA4)", static_cast<quint8>(Unerbus::CommandId::CMD_GET_MOTOR_SPEEDS));
    ui->CMDComboBox->addItem("GET_MOTOR_PWM (0xA6)", static_cast<quint8>(Unerbus::CommandId::CMD_GET_MOTOR_PWM));
    ui->CMDComboBox->addItem("GET_LOCAL_IP_ADDRESS (0xE0)", static_cast<quint8>(Unerbus::CommandId::CMD_GET_LOCAL_IP_ADDRESS));
    ui->CMDComboBox->addItem("SET_UART_BYPASS_CONTROL (0xDD)", static_cast<quint8>(Unerbus::CommandId::CMD_SET_UART_BYPASS_CONTROL));
    ui->CMDComboBox->addItem("GET_PID_GAINS (0x41)", static_cast<quint8>(Unerbus::CommandId::CMD_GET_PID_GAINS));
    ui->CMDComboBox->addItem("GET_CONTROL_PARAMETERS (0x43)", static_cast<quint8>(Unerbus::CommandId::CMD_GET_CONTROL_PARAMETERS));
    ui->CMDComboBox->addItem("GET_MOTOR_BASE_SPEEDS (0x45)", static_cast<quint8>(Unerbus::CommandId::CMD_GET_MOTOR_BASE_SPEEDS));
    ui->CMDComboBox->addItem("GET_TURN_PID_GAINS (0x49)", static_cast<quint8>(Unerbus::CommandId::CMD_GET_TURN_PID_GAINS));
}

void MainWindow::on_btnSendCMD_clicked()
{
    if (!serialPort->isOpen() && !udpSocket)
    {
        QMessageBox::warning(this, "Error", "No hay un canal de comunicación activo (Serie o UDP).");
        return;
    }

    auto cmdId = static_cast<Unerbus::CommandId>(ui->CMDComboBox->currentData().toUInt());
    sendUnerbusCommand(cmdId);
}
void MainWindow::on_btnConnectUDP_clicked()
{
    if (udpSocket)
        return; // Ya está activo

    // 1. Abrir el puerto local para escuchar (siempre necesario)
    localPort = ui->localPortLineEdit->text().toUShort();
    if (localPort == 0)
    {
        QMessageBox::warning(this, "Puerto Inválido", "Por favor, ingrese un puerto local válido.");
        return;
    }

    udpSocket = new QUdpSocket(this);
    if (!udpSocket->bind(QHostAddress::Any, localPort))
    {
        QMessageBox::critical(this, "Error de Conexión", "No se pudo abrir el puerto UDP. Puede que ya esté en uso.");
        udpSocket->deleteLater();
        udpSocket = nullptr;
        updateConnectionStatus("Desconectado", "red"); // Asegurar estado en caso de error
        return;
    }
    connect(udpSocket, &QUdpSocket::readyRead, this, &MainWindow::onUDPReadyRead);

    // 2. Comprobar si ya tenemos datos para una reconexión rápida
    QString remoteIpFromUI = ui->RemoteIpLineEdit->text();
    quint16 remotePortFromUI = ui->RemotePortLineEdit->text().toUShort();

    if (!remoteIpFromUI.isEmpty() && remotePortFromUI > 0)
    {
        // --- LÓGICA DE RECONEXIÓN ---
        // Usar los datos existentes para conectar inmediatamente
        remoteIp = remoteIpFromUI;
        remotePort = remotePortFromUI;

        updateUIState(false, true);
        updateConnectionStatus("Conectado por UDP", "green");
        ui->commsLog->appendPlainText(QString("Reconectado directamente a %1:%2").arg(remoteIp).arg(remotePort));
    }
    else
    {
        // --- LÓGICA DE PRIMERA CONEXIÓN ---
        // No hay datos, esperar el primer paquete del robot
        updateUIState(false, true);
        updateConnectionStatus(QString("Escuchando en puerto %1...").arg(localPort), "orange");
    }
}

void MainWindow::on_btnDisconnectUDP_clicked()
{
    if (udpSocket)
    {
        udpSocket->close();
        udpSocket->deleteLater();
        udpSocket = nullptr;

        // Limpiar variables y campos de la UI
        remoteIp.clear();
        remotePort = 0;

        updateUIState(false, false);
        updateConnectionStatus("Desconectado", "red");
    }
}

void MainWindow::onUDPReadyRead()
{
    while (udpSocket->hasPendingDatagrams())
    {
        QByteArray datagram;
        QHostAddress senderIp;
        quint16 senderPort;
        datagram.resize(udpSocket->pendingDatagramSize());
        udpSocket->readDatagram(datagram.data(), datagram.size(), &senderIp, &senderPort);

        // Si es el primer paquete, establecemos la conexión
        if (remoteIp.isEmpty())
        {
            remoteIp = senderIp.toString();
            // Manejar direcciones IPv4 mapeadas a IPv6 (común en Windows)
            if (remoteIp.startsWith("::ffff:"))
            {
                remoteIp = remoteIp.mid(7);
            }
            remotePort = senderPort;

            // Actualizar la UI para reflejar la conexión establecida
            ui->RemoteIpLineEdit->setText(remoteIp);
            ui->RemotePortLineEdit->setText(QString::number(remotePort));
            ui->commsLog->appendPlainText(QString("Conexión establecida con %1:%2").arg(remoteIp).arg(remotePort));
            updateConnectionStatus("Conectado por UDP", "green");
        }

        // Procesar el paquete como siempre
        m_parser->processData(datagram);
    }
}

/**
 * @brief Slot para el botón "Actualizar" de la página de sensores.
 *        Solicita los datos de los sensores una sola vez.
 */
void MainWindow::on_btnRefreshSensorsValues_clicked()
{
    requestSensorData();
}

/**
 * @brief Slot para el checkbox "Actualización automática".
 *        Inicia o detiene el temporizador que solicita datos de sensores.
 * @param checked El estado del checkbox.
 */
void MainWindow::on_chkBoxAutoRefreshSensorsValues_toggled(bool checked)
{
    if (checked)
    {
        sensorUpdateTimer->start(SENSOR_UPDATE_INTERVAL_MS); // Actualiza cada 200 ms (5 Hz)
    }
    else
    {
        sensorUpdateTimer->stop();
    }
}

/**
 * @brief Solicita todos los datos de sensores al microcontrolador.
 */
void MainWindow::requestSensorData()
{
    sendUnerbusCommand(Unerbus::CommandId::CMD_GET_LAST_ADC_VALUES);
    sendUnerbusCommand(Unerbus::CommandId::CMD_GET_MPU_DATA);
}

/**
 * @brief Actualiza los QProgressBar de los sensores IR con los datos recibidos.
 * @param payload El payload del paquete CMD_GET_LAST_ADC_VALUES.
 */
void MainWindow::updateIrSensorsUI(const QByteArray &payload)
{
    if (payload.size() < 16)
        return; // 8 canales * 2 bytes/canal

    QDataStream stream(payload);
    stream.setByteOrder(QDataStream::LittleEndian);

    quint16 ir_front_left, ir_front_right, ir_diag_left, ir_diag_right,
        ir_side_left, ir_side_right, ir_gnd_front, ir_gnd_rear;

    // Orden: ADC0, ADC1, ADC2, ADC3, ADC4, ADC5, ADC6, ADC7.
    stream >> ir_side_right >> ir_diag_right >> ir_front_right >> ir_gnd_front >> ir_front_left >> ir_diag_left >> ir_side_left >> ir_gnd_rear;

    ui->progBarIrFrontLeft->setValue(ir_front_left);
    ui->progBarIrFrontRight->setValue(ir_front_right);
    ui->progBarIrLeftDiag->setValue(ir_diag_left);
    ui->progBarIrRightDiag->setValue(ir_diag_right);
    ui->progBarIrLeftSide->setValue(ir_side_left);
    ui->progBarIrRightSide->setValue(ir_side_right);
    ui->progBarIrGroundFront->setValue(ir_gnd_front);
    ui->progBarIrGroundRear->setValue(ir_gnd_rear);
}

/**
 * @brief Actualiza los QLineEdit del MPU6050 con los datos recibidos.
 * @param payload El payload del paquete CMD_GET_MPU_DATA.
 */
void MainWindow::updateMpuSensorsUI(const QByteArray &payload)
{
    if (payload.size() < 14)
        return; // 7 valores * 2 bytes/valor

    QDataStream stream(payload);
    stream.setByteOrder(QDataStream::LittleEndian);

    qint16 ax, ay, az, temp, gx, gy, gz;
    stream >> ax >> ay >> az >> temp >> gx >> gy >> gz;

    // Ignoramos 'temp' como solicitaste.

    ui->accelXLineEdit->setText(QString::number(ax));
    ui->accelYLineEdit->setText(QString::number(ay));
    ui->accelZLineEdit->setText(QString::number(az));
    ui->gyroXLineEdit->setText(QString::number(gx));
    ui->gyroYLineEdit->setText(QString::number(gy));
    ui->gyroZLineEdit->setText(QString::number(gz));
}

void MainWindow::sendUnerbusCommand(Unerbus::CommandId cmd, const QByteArray &payload)
{
    if (!serialPort->isOpen() && !udpSocket)
    {
        // No mostramos un error aquí para no ser intrusivos durante el auto-refresco
        return;
    }

    QByteArray packet;
    packet.append(Unerbus::HEADER); // "UNER"
    // El tamaño es: 1 (CMD) + N (payload) + 1 (Checksum)
    quint8 length = 1 + payload.size() + 1;
    packet.append(length);
    packet.append(Unerbus::TOKEN);           // ':'
    packet.append(static_cast<quint8>(cmd)); // CMD
    if (!payload.isEmpty())
    {
        packet.append(payload); // PAYLOAD
    }

    quint8 checksum = 0;
    // El checksum se calcula sobre todo el paquete antes de añadir el checksum mismo
    for (quint8 byte : packet)
    {
        checksum ^= byte;
    }
    packet.append(checksum); // CHECKSUM

    if (serialPort && serialPort->isOpen())
    {
        serialPort->write(packet);
    }
    else if (udpSocket)
    {
        // Si la IP remota no está seteada, no podemos enviar
        if (remoteIp.isEmpty() || remotePort == 0)
            return;
        udpSocket->writeDatagram(packet, QHostAddress(remoteIp), remotePort);
    }

    qDebug() << "Paquete enviado:" << packet.toHex(' ');
}

/**
 * @brief Actualiza el texto y el color de la etiqueta de estado de conexión.
 * @param text El mensaje a mostrar.
 * @param colorName El nombre del color (ej: "green", "red", "orange").
 */
void MainWindow::updateConnectionStatus(const QString &text, const QString &colorName)
{
    ui->labelCommStatus->setText(text);
    ui->labelCommStatus->setStyleSheet(QString("color: %1;").arg(colorName));
}