/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../mainwindow.h"
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
namespace {
struct qt_meta_stringdata_MainWindow_t {
    uint offsetsAndSizes[80];
    char stringdata0[11];
    char stringdata1[27];
    char stringdata2[1];
    char stringdata3[17];
    char stringdata4[7];
    char stringdata5[27];
    char stringdata6[30];
    char stringdata7[27];
    char stringdata8[23];
    char stringdata9[18];
    char stringdata10[29];
    char stringdata11[6];
    char stringdata12[25];
    char stringdata13[28];
    char stringdata14[15];
    char stringdata15[17];
    char stringdata16[8];
    char stringdata17[8];
    char stringdata18[22];
    char stringdata19[35];
    char stringdata20[42];
    char stringdata21[8];
    char stringdata22[18];
    char stringdata23[27];
    char stringdata24[23];
    char stringdata25[24];
    char stringdata26[21];
    char stringdata27[25];
    char stringdata28[29];
    char stringdata29[31];
    char stringdata30[30];
    char stringdata31[28];
    char stringdata32[34];
    char stringdata33[34];
    char stringdata34[30];
    char stringdata35[30];
    char stringdata36[31];
    char stringdata37[31];
    char stringdata38[27];
    char stringdata39[27];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_MainWindow_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
        QT_MOC_LITERAL(0, 10),  // "MainWindow"
        QT_MOC_LITERAL(11, 26),  // "on_navigationButtonClicked"
        QT_MOC_LITERAL(38, 0),  // ""
        QT_MOC_LITERAL(39, 16),  // "QAbstractButton*"
        QT_MOC_LITERAL(56, 6),  // "button"
        QT_MOC_LITERAL(63, 26),  // "on_btnConnectSerie_clicked"
        QT_MOC_LITERAL(90, 29),  // "on_btnDisconnectSerie_clicked"
        QT_MOC_LITERAL(120, 26),  // "on_btnRefreshPorts_clicked"
        QT_MOC_LITERAL(147, 22),  // "onSerialPort_ReadyRead"
        QT_MOC_LITERAL(170, 17),  // "handleSerialError"
        QT_MOC_LITERAL(188, 28),  // "QSerialPort::SerialPortError"
        QT_MOC_LITERAL(217, 5),  // "error"
        QT_MOC_LITERAL(223, 24),  // "on_btnConnectUDP_clicked"
        QT_MOC_LITERAL(248, 27),  // "on_btnDisconnectUDP_clicked"
        QT_MOC_LITERAL(276, 14),  // "onUDPReadyRead"
        QT_MOC_LITERAL(291, 16),  // "onPacketReceived"
        QT_MOC_LITERAL(308, 7),  // "command"
        QT_MOC_LITERAL(316, 7),  // "payload"
        QT_MOC_LITERAL(324, 21),  // "on_btnSendCMD_clicked"
        QT_MOC_LITERAL(346, 34),  // "on_btnRefreshSensorsValues_cl..."
        QT_MOC_LITERAL(381, 41),  // "on_chkBoxAutoRefreshSensorsVa..."
        QT_MOC_LITERAL(423, 7),  // "checked"
        QT_MOC_LITERAL(431, 17),  // "requestSensorData"
        QT_MOC_LITERAL(449, 26),  // "on_btnCalibrateMPU_clicked"
        QT_MOC_LITERAL(476, 22),  // "on_btnApplyPWM_clicked"
        QT_MOC_LITERAL(499, 23),  // "on_btnStopMotor_clicked"
        QT_MOC_LITERAL(523, 20),  // "on_btnGetPWM_clicked"
        QT_MOC_LITERAL(544, 24),  // "on_chkAutoGetPWM_toggled"
        QT_MOC_LITERAL(569, 28),  // "on_chkRealTimeSetPWM_toggled"
        QT_MOC_LITERAL(598, 30),  // "on_control_widget_valueChanged"
        QT_MOC_LITERAL(629, 29),  // "on_btnConfigurePeriod_clicked"
        QT_MOC_LITERAL(659, 27),  // "on_btnSendTurnAngle_clicked"
        QT_MOC_LITERAL(687, 33),  // "on_btnGetBaseMotorsSpeeds_cli..."
        QT_MOC_LITERAL(721, 33),  // "on_btnSetBaseMotorsSpeeds_cli..."
        QT_MOC_LITERAL(755, 29),  // "on_btnGetPidNavConfig_clicked"
        QT_MOC_LITERAL(785, 29),  // "on_btnSetPidNavConfig_clicked"
        QT_MOC_LITERAL(815, 30),  // "on_btnGetPidTurnConfig_clicked"
        QT_MOC_LITERAL(846, 30),  // "on_btnSetPidTurnConfig_clicked"
        QT_MOC_LITERAL(877, 26),  // "on_btnGetMpuConfig_clicked"
        QT_MOC_LITERAL(904, 26)   // "on_btnSetMpuConfig_clicked"
    },
    "MainWindow",
    "on_navigationButtonClicked",
    "",
    "QAbstractButton*",
    "button",
    "on_btnConnectSerie_clicked",
    "on_btnDisconnectSerie_clicked",
    "on_btnRefreshPorts_clicked",
    "onSerialPort_ReadyRead",
    "handleSerialError",
    "QSerialPort::SerialPortError",
    "error",
    "on_btnConnectUDP_clicked",
    "on_btnDisconnectUDP_clicked",
    "onUDPReadyRead",
    "onPacketReceived",
    "command",
    "payload",
    "on_btnSendCMD_clicked",
    "on_btnRefreshSensorsValues_clicked",
    "on_chkBoxAutoRefreshSensorsValues_toggled",
    "checked",
    "requestSensorData",
    "on_btnCalibrateMPU_clicked",
    "on_btnApplyPWM_clicked",
    "on_btnStopMotor_clicked",
    "on_btnGetPWM_clicked",
    "on_chkAutoGetPWM_toggled",
    "on_chkRealTimeSetPWM_toggled",
    "on_control_widget_valueChanged",
    "on_btnConfigurePeriod_clicked",
    "on_btnSendTurnAngle_clicked",
    "on_btnGetBaseMotorsSpeeds_clicked",
    "on_btnSetBaseMotorsSpeeds_clicked",
    "on_btnGetPidNavConfig_clicked",
    "on_btnSetPidNavConfig_clicked",
    "on_btnGetPidTurnConfig_clicked",
    "on_btnSetPidTurnConfig_clicked",
    "on_btnGetMpuConfig_clicked",
    "on_btnSetMpuConfig_clicked"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_MainWindow[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      31,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,  200,    2, 0x08,    1 /* Private */,
       5,    0,  203,    2, 0x08,    3 /* Private */,
       6,    0,  204,    2, 0x08,    4 /* Private */,
       7,    0,  205,    2, 0x08,    5 /* Private */,
       8,    0,  206,    2, 0x08,    6 /* Private */,
       9,    1,  207,    2, 0x08,    7 /* Private */,
      12,    0,  210,    2, 0x08,    9 /* Private */,
      13,    0,  211,    2, 0x08,   10 /* Private */,
      14,    0,  212,    2, 0x08,   11 /* Private */,
      15,    2,  213,    2, 0x08,   12 /* Private */,
      18,    0,  218,    2, 0x08,   15 /* Private */,
      19,    0,  219,    2, 0x08,   16 /* Private */,
      20,    1,  220,    2, 0x08,   17 /* Private */,
      22,    0,  223,    2, 0x08,   19 /* Private */,
      23,    0,  224,    2, 0x08,   20 /* Private */,
      24,    0,  225,    2, 0x08,   21 /* Private */,
      25,    0,  226,    2, 0x08,   22 /* Private */,
      26,    0,  227,    2, 0x08,   23 /* Private */,
      27,    1,  228,    2, 0x08,   24 /* Private */,
      28,    1,  231,    2, 0x08,   26 /* Private */,
      29,    0,  234,    2, 0x08,   28 /* Private */,
      30,    0,  235,    2, 0x08,   29 /* Private */,
      31,    0,  236,    2, 0x08,   30 /* Private */,
      32,    0,  237,    2, 0x08,   31 /* Private */,
      33,    0,  238,    2, 0x08,   32 /* Private */,
      34,    0,  239,    2, 0x08,   33 /* Private */,
      35,    0,  240,    2, 0x08,   34 /* Private */,
      36,    0,  241,    2, 0x08,   35 /* Private */,
      37,    0,  242,    2, 0x08,   36 /* Private */,
      38,    0,  243,    2, 0x08,   37 /* Private */,
      39,    0,  244,    2, 0x08,   38 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::UChar, QMetaType::QByteArray,   16,   17,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   21,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   21,
    QMetaType::Void, QMetaType::Bool,   21,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.offsetsAndSizes,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_MainWindow_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>,
        // method 'on_navigationButtonClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QAbstractButton *, std::false_type>,
        // method 'on_btnConnectSerie_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_btnDisconnectSerie_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_btnRefreshPorts_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onSerialPort_ReadyRead'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'handleSerialError'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QSerialPort::SerialPortError, std::false_type>,
        // method 'on_btnConnectUDP_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_btnDisconnectUDP_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onUDPReadyRead'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onPacketReceived'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<quint8, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QByteArray &, std::false_type>,
        // method 'on_btnSendCMD_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_btnRefreshSensorsValues_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_chkBoxAutoRefreshSensorsValues_toggled'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'requestSensorData'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_btnCalibrateMPU_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_btnApplyPWM_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_btnStopMotor_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_btnGetPWM_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_chkAutoGetPWM_toggled'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'on_chkRealTimeSetPWM_toggled'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'on_control_widget_valueChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_btnConfigurePeriod_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_btnSendTurnAngle_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_btnGetBaseMotorsSpeeds_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_btnSetBaseMotorsSpeeds_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_btnGetPidNavConfig_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_btnSetPidNavConfig_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_btnGetPidTurnConfig_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_btnSetPidTurnConfig_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_btnGetMpuConfig_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_btnSetMpuConfig_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_navigationButtonClicked((*reinterpret_cast< std::add_pointer_t<QAbstractButton*>>(_a[1]))); break;
        case 1: _t->on_btnConnectSerie_clicked(); break;
        case 2: _t->on_btnDisconnectSerie_clicked(); break;
        case 3: _t->on_btnRefreshPorts_clicked(); break;
        case 4: _t->onSerialPort_ReadyRead(); break;
        case 5: _t->handleSerialError((*reinterpret_cast< std::add_pointer_t<QSerialPort::SerialPortError>>(_a[1]))); break;
        case 6: _t->on_btnConnectUDP_clicked(); break;
        case 7: _t->on_btnDisconnectUDP_clicked(); break;
        case 8: _t->onUDPReadyRead(); break;
        case 9: _t->onPacketReceived((*reinterpret_cast< std::add_pointer_t<quint8>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QByteArray>>(_a[2]))); break;
        case 10: _t->on_btnSendCMD_clicked(); break;
        case 11: _t->on_btnRefreshSensorsValues_clicked(); break;
        case 12: _t->on_chkBoxAutoRefreshSensorsValues_toggled((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 13: _t->requestSensorData(); break;
        case 14: _t->on_btnCalibrateMPU_clicked(); break;
        case 15: _t->on_btnApplyPWM_clicked(); break;
        case 16: _t->on_btnStopMotor_clicked(); break;
        case 17: _t->on_btnGetPWM_clicked(); break;
        case 18: _t->on_chkAutoGetPWM_toggled((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 19: _t->on_chkRealTimeSetPWM_toggled((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 20: _t->on_control_widget_valueChanged(); break;
        case 21: _t->on_btnConfigurePeriod_clicked(); break;
        case 22: _t->on_btnSendTurnAngle_clicked(); break;
        case 23: _t->on_btnGetBaseMotorsSpeeds_clicked(); break;
        case 24: _t->on_btnSetBaseMotorsSpeeds_clicked(); break;
        case 25: _t->on_btnGetPidNavConfig_clicked(); break;
        case 26: _t->on_btnSetPidNavConfig_clicked(); break;
        case 27: _t->on_btnGetPidTurnConfig_clicked(); break;
        case 28: _t->on_btnSetPidTurnConfig_clicked(); break;
        case 29: _t->on_btnGetMpuConfig_clicked(); break;
        case 30: _t->on_btnSetMpuConfig_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 31)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 31;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 31)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 31;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
