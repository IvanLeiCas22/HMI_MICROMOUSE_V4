#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QButtonGroup>                 // Necesario para QButtonGroup
#include <QtSerialPort/QSerialPort>     // Incluir para QSerialPort
#include <QtSerialPort/QSerialPortInfo> // Incluir para QSerialPortInfo
#include "Comunicacion/unerbusparser.h"
#include <QtNetwork/QUdpSocket>

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

private:
    Ui::MainWindow *ui;
    QButtonGroup *navigationButtonGroup; // Nuevo miembro para agrupar los botones de navegación
    QSerialPort *serialPort;             // Miembro para manejar el puerto serie
    UnerbusParser *m_parser;             // Nuevo miembro para manejar el parser

    QUdpSocket *udpSocket;
    QString remoteIp;
    quint16 remotePort;
    quint16 localPort;

    // --- Funciones de ayuda ---
    void updateSerialPortList();
    void updateUIState(bool serialConnected, bool udpConnected);
    void populateCMDComboBox();
};
#endif // MAINWINDOW_H
