#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QButtonGroup>                 // Necesario para QButtonGroup
#include <QtSerialPort/QSerialPort>     // Incluir para QSerialPort
#include <QtSerialPort/QSerialPortInfo> // Incluir para QSerialPortInfo
#include "Comunicacion/unerbusparser.h"
#include <QtNetwork/QUdpSocket>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui
{
    class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_navigationButtonClicked(QAbstractButton *button); // Nuevo slot para manejar clics de botones de navegación

    // --- Slots para la comunicación serie ---
    void on_btnConnectSerie_clicked();
    void on_btnDisconnectSerie_clicked();
    void on_btnRefreshPorts_clicked();
    void onSerialPort_ReadyRead();
    void handleSerialError(QSerialPort::SerialPortError error);
    void on_btnConnectUDP_clicked();
    void on_btnDisconnectUDP_clicked();
    void onUDPReadyRead();

    // --- Slot para procesar paquetes del micromouse ---
    void onPacketReceived(quint8 command, const QByteArray &payload);

    // --- Slots para enviar comandos ---
    void on_btnSendCMD_clicked();

    // --- Slots para la página de sensores ---
    void on_btnRefreshSensorsValues_clicked();
    void on_chkBoxAutoRefreshSensorsValues_toggled(bool checked);
    void requestSensorData();

    // --- Slots para calibración y configuración ---
    void on_btnCalibrateMPU_clicked();

    // --- Slots para la página de control de motores ---
    void on_btnApplyPWM_clicked();
    void on_btnStopMotor_clicked();
    void on_btnGetPWM_clicked();
    void on_chkAutoGetPWM_toggled(bool checked);
    void on_chkRealTimeSetPWM_toggled(bool checked);
    void on_control_widget_valueChanged(); // Slot para seteo en tiempo real del PWM de los motores
    void on_btnConfigurePeriod_clicked();
    void on_btnSendTurnAngle_clicked();

    // --- Slots para la página de configuración ---
    void on_btnGetBaseMotorsSpeeds_clicked();
    void on_btnSetBaseMotorsSpeeds_clicked();
    void on_btnGetPidNavConfig_clicked();
    void on_btnSetPidNavConfig_clicked();
    void on_btnGetPidTurnConfig_clicked();
    void on_btnSetPidTurnConfig_clicked();
    void on_btnGetMpuConfig_clicked();
    void on_btnSetMpuConfig_clicked();
    void on_btnGetRobotStatus_clicked();
    void on_btnSetRobotStatus_clicked();
    void on_btnGetCruiseParams_clicked();
    void on_btnSetCruiseParams_clicked();
    void on_btnGetPidBrakingConfig_clicked();
    void on_btnSetPidBrakingConfig_clicked();

private:
    Ui::MainWindow *ui;
    QButtonGroup *navigationButtonGroup; // Nuevo miembro para agrupar los botones de navegación
    QSerialPort *serialPort;             // Miembro para manejar el puerto serie
    UnerbusParser *m_parser;             // Nuevo miembro para manejar el parser

    QUdpSocket *udpSocket;
    QString remoteIp;
    quint16 remotePort;
    quint16 localPort;

    QTimer *sensorUpdateTimer; // Temporizador para actualizaciones automáticas
    QTimer *pwmUpdateTimer;    // Temporizador para actualizaciones de PWM

    quint16 m_pwmPeriod = 1000; // Almacena el período máximo de PWM para escalar los valores de la UI.

    // --- Constantes para configuración ---
    static const int SENSOR_UPDATE_INTERVAL_MS = 200;
    static const int PWM_UPDATE_INTERVAL_MS = 200; // Intervalo para pedir PWM (5 Hz)
    static const int MAX_LOG_LINES = 200;

    // --- Funciones de ayuda ---
    void updateSerialPortList();
    void updateUIState(bool serialConnected, bool udpConnected);
    void populateCMDComboBox();
    void sendUnerbusCommand(Unerbus::CommandId cmd, const QByteArray &payload = QByteArray()); // Helper para enviar comandos
    void updateIrSensorsUI(const QByteArray &payload);
    void updateMpuSensorsUI(const QByteArray &payload);
    void updateConnectionStatus(const QString &text, const QString &colorName); // Helper para actualizar el estado de conexión
    void setupControlPage();                                                    // Función de configuración del control
    void requestPwmData();                                                      // Nueva función para pedir datos de PWM
    void updatePwmUI(const QByteArray &payload);                                // Nueva función para actualizar la UI de PWM
    void updatePwmControlRanges(quint16 new_period);

    void setupConfigPage();
    void updatePidNavUI(const QByteArray &payload);
    void updatePidTurnUI(const QByteArray &payload);
    void updateMotorBaseSpeedsUI(const QByteArray &payload);
    void updateTurnMaxSpeedUI(const QByteArray &payload);
    void updateTurnMinSpeedUI(const QByteArray &payload);
    void updateMpuConfigUI(const QByteArray &payload);
    void populateMpuConfigComboBoxes();
    void updateWallThresholdsUI(const QByteArray &payload);
    void updateWallTargetAdcUI(const QByteArray &payload);
    void updateMaxPwmCorrectionUI(const QByteArray &payload);
    void setupActivitiesTab();
    void populateRobotStatusComboBoxes();
    void updateRobotStatusUI(const QByteArray &payload);
    void updateCruiseParamsUI(const QByteArray &payload);
    void updatePidBrakingUI(const QByteArray &payload);
    void updateBrakingParamsUI(const QByteArray &payload);
    void updateBrakingMaxSpeedUI(const QByteArray &payload);
    void updateBrakingMinSpeedUI(const QByteArray &payload);
    void updateBrakingDeadZoneUI(const QByteArray &payload);
    void updateYawAngleUI(const QByteArray &payload);
    void updateSmoothTurnSpeedsUI(const QByteArray &payload);
    void updateTurnSpeedPID(const QByteArray &payload);
    void updateTurnTargetDps(const QByteArray &payload);
    void updateDelayTicksUI(const QByteArray &payload);
};
#endif // MAINWINDOW_H
