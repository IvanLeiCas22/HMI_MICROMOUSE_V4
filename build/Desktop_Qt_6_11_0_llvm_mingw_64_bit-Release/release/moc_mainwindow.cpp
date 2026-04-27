/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.11.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../mainwindow.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 69
#error "This file was generated using the moc from 6.11.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {
struct qt_meta_tag_ZN10MainWindowE_t {};
} // unnamed namespace

template <> constexpr inline auto MainWindow::qt_create_metaobjectdata<qt_meta_tag_ZN10MainWindowE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
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
        "on_btnSetMpuConfig_clicked",
        "on_btnGetRobotStatus_clicked",
        "on_btnSetRobotStatus_clicked",
        "on_btnGetCruiseParams_clicked",
        "on_btnSetCruiseParams_clicked",
        "on_btnGetPidBrakingConfig_clicked",
        "on_btnSetPidBrakingConfig_clicked",
        "on_btnSimTurnL_clicked",
        "on_btnSimFwd_clicked",
        "on_btnSimTurnR_clicked",
        "on_btnSimWallLeft_clicked",
        "on_btnSimWallFront_clicked",
        "on_btnSimWallRight_clicked",
        "on_btnSimReset_clicked",
        "on_btnRotMapL_clicked",
        "on_btnRotMapR_clicked",
        "on_btnToggleAutonomous_clicked",
        "on_btnSaveMaze_clicked",
        "on_btnLoadMaze_clicked",
        "on_btnSyncMaze_clicked"
    };

    QtMocHelpers::UintData qt_methods {
        // Slot 'on_navigationButtonClicked'
        QtMocHelpers::SlotData<void(QAbstractButton *)>(1, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { 0x80000000 | 3, 4 },
        }}),
        // Slot 'on_btnConnectSerie_clicked'
        QtMocHelpers::SlotData<void()>(5, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_btnDisconnectSerie_clicked'
        QtMocHelpers::SlotData<void()>(6, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_btnRefreshPorts_clicked'
        QtMocHelpers::SlotData<void()>(7, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'onSerialPort_ReadyRead'
        QtMocHelpers::SlotData<void()>(8, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'handleSerialError'
        QtMocHelpers::SlotData<void(QSerialPort::SerialPortError)>(9, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { 0x80000000 | 10, 11 },
        }}),
        // Slot 'on_btnConnectUDP_clicked'
        QtMocHelpers::SlotData<void()>(12, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_btnDisconnectUDP_clicked'
        QtMocHelpers::SlotData<void()>(13, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'onUDPReadyRead'
        QtMocHelpers::SlotData<void()>(14, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'onPacketReceived'
        QtMocHelpers::SlotData<void(quint8, const QByteArray &)>(15, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::UChar, 16 }, { QMetaType::QByteArray, 17 },
        }}),
        // Slot 'on_btnSendCMD_clicked'
        QtMocHelpers::SlotData<void()>(18, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_btnRefreshSensorsValues_clicked'
        QtMocHelpers::SlotData<void()>(19, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_chkBoxAutoRefreshSensorsValues_toggled'
        QtMocHelpers::SlotData<void(bool)>(20, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Bool, 21 },
        }}),
        // Slot 'requestSensorData'
        QtMocHelpers::SlotData<void()>(22, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_btnCalibrateMPU_clicked'
        QtMocHelpers::SlotData<void()>(23, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_btnApplyPWM_clicked'
        QtMocHelpers::SlotData<void()>(24, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_btnStopMotor_clicked'
        QtMocHelpers::SlotData<void()>(25, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_btnGetPWM_clicked'
        QtMocHelpers::SlotData<void()>(26, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_chkAutoGetPWM_toggled'
        QtMocHelpers::SlotData<void(bool)>(27, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Bool, 21 },
        }}),
        // Slot 'on_chkRealTimeSetPWM_toggled'
        QtMocHelpers::SlotData<void(bool)>(28, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Bool, 21 },
        }}),
        // Slot 'on_control_widget_valueChanged'
        QtMocHelpers::SlotData<void()>(29, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_btnConfigurePeriod_clicked'
        QtMocHelpers::SlotData<void()>(30, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_btnSendTurnAngle_clicked'
        QtMocHelpers::SlotData<void()>(31, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_btnGetBaseMotorsSpeeds_clicked'
        QtMocHelpers::SlotData<void()>(32, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_btnSetBaseMotorsSpeeds_clicked'
        QtMocHelpers::SlotData<void()>(33, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_btnGetPidNavConfig_clicked'
        QtMocHelpers::SlotData<void()>(34, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_btnSetPidNavConfig_clicked'
        QtMocHelpers::SlotData<void()>(35, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_btnGetPidTurnConfig_clicked'
        QtMocHelpers::SlotData<void()>(36, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_btnSetPidTurnConfig_clicked'
        QtMocHelpers::SlotData<void()>(37, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_btnGetMpuConfig_clicked'
        QtMocHelpers::SlotData<void()>(38, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_btnSetMpuConfig_clicked'
        QtMocHelpers::SlotData<void()>(39, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_btnGetRobotStatus_clicked'
        QtMocHelpers::SlotData<void()>(40, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_btnSetRobotStatus_clicked'
        QtMocHelpers::SlotData<void()>(41, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_btnGetCruiseParams_clicked'
        QtMocHelpers::SlotData<void()>(42, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_btnSetCruiseParams_clicked'
        QtMocHelpers::SlotData<void()>(43, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_btnGetPidBrakingConfig_clicked'
        QtMocHelpers::SlotData<void()>(44, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_btnSetPidBrakingConfig_clicked'
        QtMocHelpers::SlotData<void()>(45, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_btnSimTurnL_clicked'
        QtMocHelpers::SlotData<void()>(46, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_btnSimFwd_clicked'
        QtMocHelpers::SlotData<void()>(47, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_btnSimTurnR_clicked'
        QtMocHelpers::SlotData<void()>(48, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_btnSimWallLeft_clicked'
        QtMocHelpers::SlotData<void()>(49, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_btnSimWallFront_clicked'
        QtMocHelpers::SlotData<void()>(50, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_btnSimWallRight_clicked'
        QtMocHelpers::SlotData<void()>(51, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_btnSimReset_clicked'
        QtMocHelpers::SlotData<void()>(52, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_btnRotMapL_clicked'
        QtMocHelpers::SlotData<void()>(53, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_btnRotMapR_clicked'
        QtMocHelpers::SlotData<void()>(54, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_btnToggleAutonomous_clicked'
        QtMocHelpers::SlotData<void()>(55, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_btnSaveMaze_clicked'
        QtMocHelpers::SlotData<void()>(56, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_btnLoadMaze_clicked'
        QtMocHelpers::SlotData<void()>(57, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_btnSyncMaze_clicked'
        QtMocHelpers::SlotData<void()>(58, 2, QMC::AccessPrivate, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<MainWindow, qt_meta_tag_ZN10MainWindowE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN10MainWindowE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN10MainWindowE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN10MainWindowE_t>.metaTypes,
    nullptr
} };

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<MainWindow *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->on_navigationButtonClicked((*reinterpret_cast<std::add_pointer_t<QAbstractButton*>>(_a[1]))); break;
        case 1: _t->on_btnConnectSerie_clicked(); break;
        case 2: _t->on_btnDisconnectSerie_clicked(); break;
        case 3: _t->on_btnRefreshPorts_clicked(); break;
        case 4: _t->onSerialPort_ReadyRead(); break;
        case 5: _t->handleSerialError((*reinterpret_cast<std::add_pointer_t<QSerialPort::SerialPortError>>(_a[1]))); break;
        case 6: _t->on_btnConnectUDP_clicked(); break;
        case 7: _t->on_btnDisconnectUDP_clicked(); break;
        case 8: _t->onUDPReadyRead(); break;
        case 9: _t->onPacketReceived((*reinterpret_cast<std::add_pointer_t<quint8>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QByteArray>>(_a[2]))); break;
        case 10: _t->on_btnSendCMD_clicked(); break;
        case 11: _t->on_btnRefreshSensorsValues_clicked(); break;
        case 12: _t->on_chkBoxAutoRefreshSensorsValues_toggled((*reinterpret_cast<std::add_pointer_t<bool>>(_a[1]))); break;
        case 13: _t->requestSensorData(); break;
        case 14: _t->on_btnCalibrateMPU_clicked(); break;
        case 15: _t->on_btnApplyPWM_clicked(); break;
        case 16: _t->on_btnStopMotor_clicked(); break;
        case 17: _t->on_btnGetPWM_clicked(); break;
        case 18: _t->on_chkAutoGetPWM_toggled((*reinterpret_cast<std::add_pointer_t<bool>>(_a[1]))); break;
        case 19: _t->on_chkRealTimeSetPWM_toggled((*reinterpret_cast<std::add_pointer_t<bool>>(_a[1]))); break;
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
        case 31: _t->on_btnGetRobotStatus_clicked(); break;
        case 32: _t->on_btnSetRobotStatus_clicked(); break;
        case 33: _t->on_btnGetCruiseParams_clicked(); break;
        case 34: _t->on_btnSetCruiseParams_clicked(); break;
        case 35: _t->on_btnGetPidBrakingConfig_clicked(); break;
        case 36: _t->on_btnSetPidBrakingConfig_clicked(); break;
        case 37: _t->on_btnSimTurnL_clicked(); break;
        case 38: _t->on_btnSimFwd_clicked(); break;
        case 39: _t->on_btnSimTurnR_clicked(); break;
        case 40: _t->on_btnSimWallLeft_clicked(); break;
        case 41: _t->on_btnSimWallFront_clicked(); break;
        case 42: _t->on_btnSimWallRight_clicked(); break;
        case 43: _t->on_btnSimReset_clicked(); break;
        case 44: _t->on_btnRotMapL_clicked(); break;
        case 45: _t->on_btnRotMapR_clicked(); break;
        case 46: _t->on_btnToggleAutonomous_clicked(); break;
        case 47: _t->on_btnSaveMaze_clicked(); break;
        case 48: _t->on_btnLoadMaze_clicked(); break;
        case 49: _t->on_btnSyncMaze_clicked(); break;
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
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN10MainWindowE_t>.strings))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 50)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 50;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 50)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 50;
    }
    return _id;
}
QT_WARNING_POP
