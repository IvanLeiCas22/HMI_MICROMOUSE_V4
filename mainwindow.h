#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QButtonGroup>                 // Necesario para QButtonGroup
#include <QtSerialPort/QSerialPort>     // Incluir para QSerialPort
#include <QtSerialPort/QSerialPortInfo> // Incluir para QSerialPortInfo
#include "Comunicacion/unerbusparser.h"

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

    // --- Slot para procesar paquetes del micromouse ---
    void onPacketReceived(quint8 command, const QByteArray &payload);

private:
    Ui::MainWindow *ui;
    QButtonGroup *navigationButtonGroup; // Nuevo miembro para agrupar los botones de navegación
    QSerialPort *serialPort;             // Miembro para manejar el puerto serie
    UnerbusParser *m_parser;             // Nuevo miembro para manejar el parser

    // --- Funciones de ayuda ---
    void updateSerialPortList();
    void updateUIState(bool connected);
};
#endif // MAINWINDOW_H
