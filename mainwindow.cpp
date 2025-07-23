#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox> // Para mostrar mensajes de error
#include <QDebug>      // Para imprimir en la consola de depuración
#include <QDataStream> // <-- AÑADIR ESTA LÍNEA

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), serialPort(new QSerialPort(this)), m_parser(new UnerbusParser(this))
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

    updateSerialPortList();
    updateUIState(false); // Estado inicial: desconectado
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

void MainWindow::updateUIState(bool connected)
{
    ui->comboBoxPorts->setEnabled(!connected);
    ui->btnRefreshPorts->setEnabled(!connected);
    ui->btnConnectSerie->setEnabled(!connected);
    ui->btnDisconnectSerie->setEnabled(connected);

    if (connected)
    {
        ui->labelCommStatus->setText(QString("Conectado a %1").arg(serialPort->portName()));
        ui->labelCommStatus->setStyleSheet("color: green; font-weight: bold;");
    }
    else
    {
        ui->labelCommStatus->setText("Desconectado");
        ui->labelCommStatus->setStyleSheet("color: red; font-weight: bold;");
    }
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
        updateUIState(true);
    }
    else
    {
        QMessageBox::critical(this, "Error de Conexión", "No se pudo abrir el puerto: " + serialPort->errorString());
        updateUIState(false);
    }
}

void MainWindow::on_btnDisconnectSerie_clicked()
{
    if (serialPort->isOpen())
    {
        serialPort->close();
    }
    updateUIState(false);
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
}

// --- NUEVO SLOT PARA PROCESAR PAQUETES ---
void MainWindow::onPacketReceived(quint8 command, const QByteArray &payload)
{
    // Usamos QDataStream para leer datos binarios de forma segura
    QDataStream stream(payload);
    stream.setByteOrder(QDataStream::LittleEndian); // ¡Muy importante! El protocolo es Little Endian

    qDebug() << "Paquete válido recibido! CMD:" << Qt::hex << command << "Payload:" << payload.toHex(' ');

    // Aquí va la lógica para manejar cada comando
    switch (command)
    {
    case Unerbus::CMD_GET_LAST_ADC_VALUES:
    {
        if (payload.size() >= 16)
        { // 8 canales * 2 bytes/canal
            quint16 adc_ch0, adc_ch1, adc_ch2, adc_ch3, adc_ch4, adc_ch5, adc_ch6, adc_ch7;
            stream >> adc_ch0 >> adc_ch1 >> adc_ch2 >> adc_ch3 >> adc_ch4 >> adc_ch5 >> adc_ch6 >> adc_ch7;
            // Ahora puedes usar estos valores para actualizar la UI
            // Ejemplo: ui->labelSensor1->setText(QString::number(adc_ch0));
            qDebug() << "ADC[0]:" << adc_ch0;
            qDebug() << "ADC[1]:" << adc_ch1;
            qDebug() << "ADC[2]:" << adc_ch2;
            qDebug() << "ADC[3]:" << adc_ch3;
            qDebug() << "ADC[4]:" << adc_ch4;
            qDebug() << "ADC[5]:" << adc_ch5;
            qDebug() << "ADC[6]:" << adc_ch6;
            qDebug() << "ADC[7]:" << adc_ch7;
        }
        break;
    }

    case Unerbus::CMD_GET_MPU_DATA:
    {
        if (payload.size() >= 14)
        { // 7 valores * 2 bytes/valor
            qint16 ax, ay, az, temp, gx, gy, gz;
            stream >> ax >> ay >> az >> temp >> gx >> gy >> gz;
            // Actualizar la UI con los datos del MPU
            qDebug() << "Accel X:" << ax << "Gyro Z:" << gz;
        }
        break;
    }

    case Unerbus::CMD_ACK:
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
