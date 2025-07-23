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
    uint offsetsAndSizes[30];
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
    char stringdata12[17];
    char stringdata13[8];
    char stringdata14[8];
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
        QT_MOC_LITERAL(223, 16),  // "onPacketReceived"
        QT_MOC_LITERAL(240, 7),  // "command"
        QT_MOC_LITERAL(248, 7)   // "payload"
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
    "onPacketReceived",
    "command",
    "payload"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_MainWindow[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   56,    2, 0x08,    1 /* Private */,
       5,    0,   59,    2, 0x08,    3 /* Private */,
       6,    0,   60,    2, 0x08,    4 /* Private */,
       7,    0,   61,    2, 0x08,    5 /* Private */,
       8,    0,   62,    2, 0x08,    6 /* Private */,
       9,    1,   63,    2, 0x08,    7 /* Private */,
      12,    2,   66,    2, 0x08,    9 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Void, QMetaType::UChar, QMetaType::QByteArray,   13,   14,

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
        // method 'onPacketReceived'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<quint8, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QByteArray &, std::false_type>
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
        case 6: _t->onPacketReceived((*reinterpret_cast< std::add_pointer_t<quint8>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QByteArray>>(_a[2]))); break;
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
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 7;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
