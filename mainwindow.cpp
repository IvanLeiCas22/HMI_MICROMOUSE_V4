#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QDebug>
#include <QDataStream>
#include <QTextBlock>
#include <QMetaEnum>
#include <QIntValidator>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow),
      serialPort(new QSerialPort(this)),
      m_parser(new UnerbusParser(this)),
      udpSocket(nullptr),
      sensorUpdateTimer(new QTimer(this)),
      pwmUpdateTimer(new QTimer(this)) // Inicializar el nuevo temporizador
{
    ui->setupUi(this);

    // Inicializar QButtonGroup para los botones de navegación
    navigationButtonGroup = new QButtonGroup(this);
    navigationButtonGroup->setExclusive(true);           // Solo un botón puede estar checked a la vez
    navigationButtonGroup->addButton(ui->btnHome, 0);    // ID 0 para la página de Inicio
    navigationButtonGroup->addButton(ui->btnSensors, 1); // ID 1 para la página de Sensores
    navigationButtonGroup->addButton(ui->btnConfig, 2);  // ID 2 para la página de Configuración
    navigationButtonGroup->addButton(ui->btnControl, 3); // ID 3 para la página de control
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
    connect(pwmUpdateTimer, &QTimer::timeout, this, &MainWindow::requestPwmData);

    updateSerialPortList();
    updateUIState(false, false);                   // Estado inicial: desconectado
    updateConnectionStatus("Desconectado", "red"); // Establecer estado inicial

    populateCMDComboBox();
    setupControlPage(); // Configurar la página de control
    setupConfigPage();

    QIntValidator *turnAngleValidator = new QIntValidator(-360, 360, this);
    ui->editTurnAngle->setValidator(turnAngleValidator);
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
        // Solicitar período de PWM al conectar
        QTimer::singleShot(200, this, [this]()
                           { sendUnerbusCommand(Unerbus::CommandId::CMD_GET_PWM_PERIOD); });
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

    case Unerbus::CommandId::CMD_GET_MOTOR_PWM:
    {
        updatePwmUI(payload);
        break;
    }
    case Unerbus::CommandId::CMD_GET_PWM_PERIOD:
    {
        if (payload.size() >= 2)
        {
            quint16 period;
            stream >> period;
            updatePwmControlRanges(period);
        }
        break;
    }
    case Unerbus::CommandId::CMD_GET_PID_GAINS:
    {
        updatePidNavUI(payload);
        break;
    }
    case Unerbus::CommandId::CMD_GET_CONTROL_PARAMETERS:
    {
        updateControlParamsUI(payload);
        break;
    }
    case Unerbus::CommandId::CMD_GET_TURN_PID_GAINS:
    {
        updatePidTurnUI(payload);
        break;
    }
    case Unerbus::CommandId::CMD_GET_MOTOR_BASE_SPEEDS:
    {
        updateMotorBaseSpeedsUI(payload);
        break;
    }
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

            // Solicitar período de PWM al conectar
            QTimer::singleShot(200, this, [this]()
                               { sendUnerbusCommand(Unerbus::CommandId::CMD_GET_PWM_PERIOD); });
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

void MainWindow::on_btnCalibrateMPU_clicked()
{
    sendUnerbusCommand(Unerbus::CommandId::CMD_CALIBRATE_MPU);
}

/**
 * @brief Slot para el botón "Aplicar PWM".
 *        Construye y envía el comando CMD_SET_MOTOR_PWM con los valores de la UI.
 */
void MainWindow::on_btnApplyPWM_clicked()
{
    QByteArray payload;
    QDataStream stream(&payload, QIODevice::WriteOnly);
    stream.setByteOrder(QDataStream::LittleEndian); // El microcontrolador es Little Endian

    // Obtener los valores de los spinboxes
    quint16 right_neg = ui->spinBoxRightMotorNeg->value();
    quint16 right_pos = ui->spinBoxRightMotorPos->value();
    quint16 left_neg = ui->spinBoxLeftMotorNeg->value();
    quint16 left_pos = ui->spinBoxLeftMotorPos->value();

    // Escribir en el payload en el orden que espera el firmware:
    // CH1 (Derecho, Reversa), CH2 (Derecho, Avance), CH3 (Izquierdo, Reversa), CH4 (Izquierdo, Avance)
    stream << right_neg << right_pos << left_neg << left_pos;

    sendUnerbusCommand(Unerbus::CommandId::CMD_SET_MOTOR_PWM, payload);
}

/**
 * @brief Slot para el botón "Detener Motores".
 *        Envía un comando para poner todos los PWM a 0 y resetea la UI.
 */
void MainWindow::on_btnStopMotor_clicked()
{
    // 1. Resetear los controles de la UI a 0
    ui->hSliderRightMotorPos->setValue(0);
    ui->hSliderRightMotorNeg->setValue(0);
    ui->hSliderLeftMotorPos->setValue(0);
    ui->hSliderLeftMotorNeg->setValue(0);
    // Los spinboxes se actualizarán automáticamente gracias a las conexiones de señales

    // 2. Enviar comando con todos los PWM a 0
    // Creamos un payload de 8 bytes, todos inicializados a cero.
    QByteArray payload(8, 0);
    sendUnerbusCommand(Unerbus::CommandId::CMD_SET_MOTOR_PWM, payload);
}

/**
 * @brief Configura las conexiones de señales y slots para la página de control.
 */
void MainWindow::setupControlPage()
{
    // --- Sincronización de Sliders y SpinBoxes ---
    connect(ui->hSliderRightMotorPos, &QSlider::valueChanged, ui->spinBoxRightMotorPos, &QSpinBox::setValue);
    connect(ui->spinBoxRightMotorPos, QOverload<int>::of(&QSpinBox::valueChanged), ui->hSliderRightMotorPos, &QSlider::setValue);
    connect(ui->hSliderRightMotorNeg, &QSlider::valueChanged, ui->spinBoxRightMotorNeg, &QSpinBox::setValue);
    connect(ui->spinBoxRightMotorNeg, QOverload<int>::of(&QSpinBox::valueChanged), ui->hSliderRightMotorNeg, &QSlider::setValue);
    connect(ui->hSliderLeftMotorPos, &QSlider::valueChanged, ui->spinBoxLeftMotorPos, &QSpinBox::setValue);
    connect(ui->spinBoxLeftMotorPos, QOverload<int>::of(&QSpinBox::valueChanged), ui->hSliderLeftMotorPos, &QSlider::setValue);
    connect(ui->hSliderLeftMotorNeg, &QSlider::valueChanged, ui->spinBoxLeftMotorNeg, &QSpinBox::setValue);
    connect(ui->spinBoxLeftMotorNeg, QOverload<int>::of(&QSpinBox::valueChanged), ui->hSliderLeftMotorNeg, &QSlider::setValue);

    // --- Conexión para seteo en tiempo real ---
    // Conectar todos los widgets de control a un único slot
    connect(ui->hSliderRightMotorPos, &QSlider::valueChanged, this, &MainWindow::on_control_widget_valueChanged);
    connect(ui->hSliderRightMotorNeg, &QSlider::valueChanged, this, &MainWindow::on_control_widget_valueChanged);
    connect(ui->hSliderLeftMotorPos, &QSlider::valueChanged, this, &MainWindow::on_control_widget_valueChanged);
    connect(ui->hSliderLeftMotorNeg, &QSlider::valueChanged, this, &MainWindow::on_control_widget_valueChanged);
}

/**
 * @brief Slot para el botón "Obtener PWM". Solicita los datos una vez.
 */
void MainWindow::on_btnGetPWM_clicked()
{
    requestPwmData();
}

/**
 * @brief Slot para el checkbox "Obtención automática".
 *        Inicia o detiene el temporizador y bloquea/desbloquea los controles de PWM.
 */
void MainWindow::on_chkAutoGetPWM_toggled(bool checked)
{
    // Habilitar/deshabilitar controles para evitar conflictos con la entrada del usuario
    ui->hSliderRightMotorPos->setEnabled(!checked);
    ui->spinBoxRightMotorPos->setEnabled(!checked);
    ui->hSliderRightMotorNeg->setEnabled(!checked);
    ui->spinBoxRightMotorNeg->setEnabled(!checked);
    ui->hSliderLeftMotorPos->setEnabled(!checked);
    ui->spinBoxLeftMotorPos->setEnabled(!checked);
    ui->hSliderLeftMotorNeg->setEnabled(!checked);
    ui->spinBoxLeftMotorNeg->setEnabled(!checked);
    ui->chkRealTimeSetPWM->setEnabled(!checked); // Bloquear el seteo en tiempo real

    if (checked)
    {
        pwmUpdateTimer->start(PWM_UPDATE_INTERVAL_MS);
    }
    else
    {
        pwmUpdateTimer->stop();
    }
}

/**
 * @brief Slot para el checkbox "Seteo en tiempo real".
 *        Habilita/deshabilita el botón "Aplicar PWM" y el checkbox de obtención automática.
 */
void MainWindow::on_chkRealTimeSetPWM_toggled(bool checked)
{
    ui->btnApplyPWM->setEnabled(!checked);
    ui->chkAutoGetPWM->setEnabled(!checked); // Bloquear la obtención automática
}

/**
 * @brief Slot que se activa cuando cualquier slider o spinbox de control cambia.
 *        Si el modo "tiempo real" está activo, envía el comando de PWM.
 */
void MainWindow::on_control_widget_valueChanged()
{
    if (ui->chkRealTimeSetPWM->isChecked())
    {
        on_btnApplyPWM_clicked();
    }
}

/**
 * @brief Solicita los valores de PWM actuales al microcontrolador.
 */
void MainWindow::requestPwmData()
{
    sendUnerbusCommand(Unerbus::CommandId::CMD_GET_MOTOR_PWM);
}

/**
 * @brief Actualiza los sliders y spinboxes de PWM con los datos recibidos.
 * @param payload El payload del paquete CMD_GET_MOTOR_PWM.
 */
void MainWindow::updatePwmUI(const QByteArray &payload)
{
    if (payload.size() < 8)
        return; // 4 canales * 2 bytes/canal

    QDataStream stream(payload);
    stream.setByteOrder(QDataStream::LittleEndian);

    quint16 right_neg, right_pos, left_neg, left_pos;
    stream >> right_neg >> right_pos >> left_neg >> left_pos;

    // Bloquear señales para evitar bucles de actualización
    ui->hSliderRightMotorNeg->blockSignals(true);
    ui->spinBoxRightMotorNeg->blockSignals(true);
    ui->hSliderRightMotorPos->blockSignals(true);
    ui->spinBoxRightMotorPos->blockSignals(true);
    ui->hSliderLeftMotorNeg->blockSignals(true);
    ui->spinBoxLeftMotorNeg->blockSignals(true);
    ui->hSliderLeftMotorPos->blockSignals(true);
    ui->spinBoxLeftMotorPos->blockSignals(true);

    // Actualizar valores
    ui->hSliderRightMotorNeg->setValue(right_neg);
    ui->hSliderRightMotorPos->setValue(right_pos);
    ui->hSliderLeftMotorNeg->setValue(left_neg);
    ui->hSliderLeftMotorPos->setValue(left_pos);

    // Desbloquear señales
    ui->hSliderRightMotorNeg->blockSignals(false);
    ui->spinBoxRightMotorNeg->blockSignals(false);
    ui->hSliderRightMotorPos->blockSignals(false);
    ui->spinBoxRightMotorPos->blockSignals(false);
    ui->hSliderLeftMotorNeg->blockSignals(false);
    ui->spinBoxLeftMotorNeg->blockSignals(false);
    ui->hSliderLeftMotorPos->blockSignals(false);
    ui->spinBoxLeftMotorPos->blockSignals(false);
}

/**
 * @brief Actualiza los rangos máximos de los sliders y spinboxes de PWM.
 * @param new_period El nuevo valor máximo (período del timer).
 */
void MainWindow::updatePwmControlRanges(quint16 new_period)
{
    // Actualizar el campo de texto
    ui->lineEditPwmPeriod->setText(QString::number(new_period));

    // Actualizar los máximos de todos los controles de PWM
    ui->hSliderRightMotorPos->setMaximum(new_period);
    ui->spinBoxRightMotorPos->setMaximum(new_period);
    ui->hSliderRightMotorNeg->setMaximum(new_period);
    ui->spinBoxRightMotorNeg->setMaximum(new_period);
    ui->hSliderLeftMotorPos->setMaximum(new_period);
    ui->spinBoxLeftMotorPos->setMaximum(new_period);
    ui->hSliderLeftMotorNeg->setMaximum(new_period);
    ui->spinBoxLeftMotorNeg->setMaximum(new_period);

    qDebug() << "Rango de PWM actualizado a:" << new_period;
}

/**
 * @brief Slot para el botón "Configurar" del período del PWM.
 */
void MainWindow::on_btnConfigurePeriod_clicked()
{
    bool ok;
    quint16 new_period = ui->lineEditPwmPeriod->text().toUShort(&ok);

    if (ok && new_period > 100)
    { // Validar un mínimo razonable
        QByteArray payload;
        QDataStream stream(&payload, QIODevice::WriteOnly);
        stream.setByteOrder(QDataStream::LittleEndian);
        stream << new_period;
        sendUnerbusCommand(Unerbus::CommandId::CMD_SET_PWM_PERIOD, payload);

        // Solicitar de vuelta el valor para confirmar y actualizar la UI
        QTimer::singleShot(200, this, [this]()
                           { sendUnerbusCommand(Unerbus::CommandId::CMD_GET_PWM_PERIOD); });
    }
    else
    {
        QMessageBox::warning(this, "Valor Inválido", "Por favor, ingrese un número de período válido (mayor a 100).");
    }
}

/**
 * @brief Conecta las señales de los botones de la página de configuración a sus slots.
 */
void MainWindow::setupConfigPage()
{
    // Conexiones para el PID de Navegación
    connect(ui->btnGetPidNavConfig, &QPushButton::clicked, this, &MainWindow::on_btnGetPidNavConfig_clicked);
    connect(ui->btnSetPidNavConfig, &QPushButton::clicked, this, &MainWindow::on_btnSetPidNavConfig_clicked);

    // Conexiones para el PID de Giro
    connect(ui->btnGetPidTurnConfig, &QPushButton::clicked, this, &MainWindow::on_btnGetPidTurnConfig_clicked);
    connect(ui->btnSetPidTurnConfig, &QPushButton::clicked, this, &MainWindow::on_btnSetPidTurnConfig_clicked);

    // Conexiones para las Velocidades Base de los Motores
    connect(ui->btnGetBaseMotorsSpeeds, &QPushButton::clicked, this, &MainWindow::on_btnGetBaseMotorsSpeeds_clicked);
    connect(ui->btnSetBaseMotorsSpeeds, &QPushButton::clicked, this, &MainWindow::on_btnSetBaseMotorsSpeeds_clicked);
}

/**
 * @brief Solicita todos los parámetros de configuración del PID de navegación.
 *        Implementa la sugerencia de pedir todos los datos relacionados a la vez.
 */
void MainWindow::on_btnGetPidNavConfig_clicked()
{
    sendUnerbusCommand(Unerbus::CommandId::CMD_GET_PID_GAINS);
    // Se pide el segundo grupo de parámetros con un pequeño retardo para no saturar el micro
    QTimer::singleShot(100, this, [this]()
                       { sendUnerbusCommand(Unerbus::CommandId::CMD_GET_CONTROL_PARAMETERS); });
}

/**
 * @brief Envía todos los parámetros de configuración del PID de navegación.
 *        Implementa la sugerencia de enviar todos los datos relacionados a la vez.
 */
void MainWindow::on_btnSetPidNavConfig_clicked()
{
    // 1. Enviar Ganancias (Kp, Ki, Kd)
    QByteArray gainsPayload;
    QDataStream gainsStream(&gainsPayload, QIODevice::WriteOnly);
    gainsStream.setByteOrder(QDataStream::LittleEndian);

    // Convertimos de flotante (UI) a entero (protocolo) multiplicando por 1000
    gainsStream << static_cast<quint16>(ui->editKpNav->text().toFloat() * 1000.0f);
    gainsStream << static_cast<quint16>(ui->editKiNav->text().toFloat() * 1000.0f);
    gainsStream << static_cast<quint16>(ui->editKdNav->text().toFloat() * 1000.0f);
    sendUnerbusCommand(Unerbus::CommandId::CMD_SET_PID_GAINS, gainsPayload);

    // 2. Enviar Parámetros de Control (Setpoint, Corrección Máxima)
    QTimer::singleShot(100, this, [this]()
                       {
        QByteArray paramsPayload;
        QDataStream paramsStream(&paramsPayload, QIODevice::WriteOnly);
        paramsStream.setByteOrder(QDataStream::LittleEndian);

        paramsStream << static_cast<quint16>(ui->editSetpointNav->text().toUShort());
        paramsStream << static_cast<quint16>(ui->editMaxPwmOffsetNav->text().toUShort());
        sendUnerbusCommand(Unerbus::CommandId::CMD_SET_CONTROL_PARAMETERS, paramsPayload); });
}

/**
 * @brief Solicita los parámetros de configuración del PID de giro.
 */
void MainWindow::on_btnGetPidTurnConfig_clicked()
{
    sendUnerbusCommand(Unerbus::CommandId::CMD_GET_TURN_PID_GAINS);
}

/**
 * @brief Envía los parámetros de configuración del PID de giro.
 */
void MainWindow::on_btnSetPidTurnConfig_clicked()
{
    QByteArray payload;
    QDataStream stream(&payload, QIODevice::WriteOnly);
    stream.setByteOrder(QDataStream::LittleEndian);

    // Convertimos de flotante (UI) a entero (protocolo) multiplicando por 100
    stream << static_cast<quint16>(ui->editKpTurn->text().toFloat() * 100.0f);
    stream << static_cast<quint16>(ui->editKiTurn->text().toFloat() * 100.0f);
    stream << static_cast<quint16>(ui->editKdTurn->text().toFloat() * 100.0f);

    sendUnerbusCommand(Unerbus::CommandId::CMD_SET_TURN_PID_GAINS, payload);
}

/**
 * @brief Solicita las velocidades base de los motores.
 */
void MainWindow::on_btnGetBaseMotorsSpeeds_clicked()
{
    sendUnerbusCommand(Unerbus::CommandId::CMD_GET_MOTOR_BASE_SPEEDS);
}

/**
 * @brief Envía las velocidades base de los motores.
 */
void MainWindow::on_btnSetBaseMotorsSpeeds_clicked()
{
    QByteArray payload;
    QDataStream stream(&payload, QIODevice::WriteOnly);
    stream.setByteOrder(QDataStream::LittleEndian);

    stream << static_cast<quint16>(ui->editRightMotorBaseSpeed->text().toUShort());
    stream << static_cast<quint16>(ui->editLeftMotorBaseSpeed->text().toUShort());

    sendUnerbusCommand(Unerbus::CommandId::CMD_SET_MOTOR_BASE_SPEEDS, payload);
}

/**
 * @brief Actualiza la UI con las ganancias del PID de navegación.
 */
void MainWindow::updatePidNavUI(const QByteArray &payload)
{
    if (payload.size() < 6)
        return;
    QDataStream stream(payload);
    stream.setByteOrder(QDataStream::LittleEndian);

    quint16 kp_int, ki_int, kd_int;
    stream >> kp_int >> ki_int >> kd_int;

    // Convertimos de entero (protocolo) a flotante (UI) dividiendo por 1000
    ui->editKpNav->setText(QString::number(kp_int / 1000.0, 'f', 3));
    ui->editKiNav->setText(QString::number(ki_int / 1000.0, 'f', 3));
    ui->editKdNav->setText(QString::number(kd_int / 1000.0, 'f', 3));
}

/**
 * @brief Actualiza la UI con los parámetros de control (setpoint, etc.).
 */
void MainWindow::updateControlParamsUI(const QByteArray &payload)
{
    if (payload.size() < 4)
        return;
    QDataStream stream(payload);
    stream.setByteOrder(QDataStream::LittleEndian);

    quint16 setpoint, max_correction;
    stream >> setpoint >> max_correction;

    ui->editSetpointNav->setText(QString::number(setpoint));
    ui->editMaxPwmOffsetNav->setText(QString::number(max_correction));
}

/**
 * @brief Actualiza la UI con las ganancias del PID de giro.
 */
void MainWindow::updatePidTurnUI(const QByteArray &payload)
{
    if (payload.size() < 6)
        return;
    QDataStream stream(payload);
    stream.setByteOrder(QDataStream::LittleEndian);

    quint16 kp_int, ki_int, kd_int;
    stream >> kp_int >> ki_int >> kd_int;

    // Convertimos de entero (protocolo) a flotante (UI) dividiendo por 100
    ui->editKpTurn->setText(QString::number(kp_int / 100.0, 'f', 2));
    ui->editKiTurn->setText(QString::number(ki_int / 100.0, 'f', 2));
    ui->editKdTurn->setText(QString::number(kd_int / 100.0, 'f', 2));
}

/**
 * @brief Actualiza la UI con las velocidades base de los motores.
 */
void MainWindow::updateMotorBaseSpeedsUI(const QByteArray &payload)
{
    if (payload.size() < 4)
        return;
    QDataStream stream(payload);
    stream.setByteOrder(QDataStream::LittleEndian);

    quint16 right_speed, left_speed;
    stream >> right_speed >> left_speed;

    ui->editRightMotorBaseSpeed->setText(QString::number(right_speed));
    ui->editLeftMotorBaseSpeed->setText(QString::number(left_speed));
}

/**
 * @brief Slot para el botón "Girar".
 *        Construye y envía el comando CMD_TURN_DEGREES con el ángulo especificado.
 */
void MainWindow::on_btnSendTurnAngle_clicked()
{
    // 1. Validar que el campo de texto no esté vacío
    if (ui->editTurnAngle->text().isEmpty())
    {
        QMessageBox::warning(this, "Entrada Inválida", "Por favor, ingrese un ángulo de giro.");
        return;
    }

    // 2. Obtener el valor del ángulo como un entero de 16 bits con signo
    bool ok;
    qint16 angle = static_cast<qint16>(ui->editTurnAngle->text().toInt(&ok));

    if (!ok)
    {
        QMessageBox::warning(this, "Valor Inválido", "El valor del ángulo no es un número válido.");
        return;
    }

    // 3. Preparar el payload
    QByteArray payload;
    QDataStream stream(&payload, QIODevice::WriteOnly);
    stream.setByteOrder(QDataStream::LittleEndian); // El microcontrolador es Little Endian

    // Escribir el ángulo en el payload. El firmware espera un int16_t.
    stream << angle;

    // 4. Enviar el comando
    sendUnerbusCommand(Unerbus::CommandId::CMD_TURN_DEGREES, payload);

    // Opcional: Limpiar el campo de texto después de enviar
    // ui->editTurnAngle->clear();
}
