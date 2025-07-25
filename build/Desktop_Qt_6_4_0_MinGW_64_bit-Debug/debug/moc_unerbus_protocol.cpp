/****************************************************************************
** Meta object code from reading C++ file 'unerbus_protocol.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../Comunicacion/unerbus_protocol.h"
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'unerbus_protocol.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_Unerbus_t {
    uint offsetsAndSizes[58];
    char stringdata0[8];
    char stringdata1[10];
    char stringdata2[8];
    char stringdata3[14];
    char stringdata4[17];
    char stringdata5[13];
    char stringdata6[21];
    char stringdata7[17];
    char stringdata8[24];
    char stringdata9[16];
    char stringdata10[21];
    char stringdata11[18];
    char stringdata12[18];
    char stringdata13[25];
    char stringdata14[28];
    char stringdata15[18];
    char stringdata16[18];
    char stringdata17[18];
    char stringdata18[27];
    char stringdata19[27];
    char stringdata20[26];
    char stringdata21[26];
    char stringdata22[21];
    char stringdata23[17];
    char stringdata24[23];
    char stringdata25[23];
    char stringdata26[19];
    char stringdata27[19];
    char stringdata28[11];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_Unerbus_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_Unerbus_t qt_meta_stringdata_Unerbus = {
    {
        QT_MOC_LITERAL(0, 7),  // "Unerbus"
        QT_MOC_LITERAL(8, 9),  // "CommandId"
        QT_MOC_LITERAL(18, 7),  // "CMD_ACK"
        QT_MOC_LITERAL(26, 13),  // "CMD_GET_ALIVE"
        QT_MOC_LITERAL(40, 16),  // "CMD_START_CONFIG"
        QT_MOC_LITERAL(57, 12),  // "CMD_FIRMWARE"
        QT_MOC_LITERAL(70, 20),  // "CMD_GET_BUTTON_STATE"
        QT_MOC_LITERAL(91, 16),  // "CMD_GET_MPU_DATA"
        QT_MOC_LITERAL(108, 23),  // "CMD_GET_LAST_ADC_VALUES"
        QT_MOC_LITERAL(132, 15),  // "CMD_TEST_MOTORS"
        QT_MOC_LITERAL(148, 20),  // "CMD_GET_MOTOR_SPEEDS"
        QT_MOC_LITERAL(169, 17),  // "CMD_SET_MOTOR_PWM"
        QT_MOC_LITERAL(187, 17),  // "CMD_GET_MOTOR_PWM"
        QT_MOC_LITERAL(205, 24),  // "CMD_GET_LOCAL_IP_ADDRESS"
        QT_MOC_LITERAL(230, 27),  // "CMD_SET_UART_BYPASS_CONTROL"
        QT_MOC_LITERAL(258, 17),  // "CMD_CALIBRATE_MPU"
        QT_MOC_LITERAL(276, 17),  // "CMD_SET_PID_GAINS"
        QT_MOC_LITERAL(294, 17),  // "CMD_GET_PID_GAINS"
        QT_MOC_LITERAL(312, 26),  // "CMD_SET_CONTROL_PARAMETERS"
        QT_MOC_LITERAL(339, 26),  // "CMD_GET_CONTROL_PARAMETERS"
        QT_MOC_LITERAL(366, 25),  // "CMD_SET_MOTOR_BASE_SPEEDS"
        QT_MOC_LITERAL(392, 25),  // "CMD_GET_MOTOR_BASE_SPEEDS"
        QT_MOC_LITERAL(418, 20),  // "CMD_CALIBRATE_MOTORS"
        QT_MOC_LITERAL(439, 16),  // "CMD_TURN_DEGREES"
        QT_MOC_LITERAL(456, 22),  // "CMD_SET_TURN_PID_GAINS"
        QT_MOC_LITERAL(479, 22),  // "CMD_GET_TURN_PID_GAINS"
        QT_MOC_LITERAL(502, 18),  // "CMD_SET_PWM_PERIOD"
        QT_MOC_LITERAL(521, 18),  // "CMD_GET_PWM_PERIOD"
        QT_MOC_LITERAL(540, 10)   // "CMD_OTHERS"
    },
    "Unerbus",
    "CommandId",
    "CMD_ACK",
    "CMD_GET_ALIVE",
    "CMD_START_CONFIG",
    "CMD_FIRMWARE",
    "CMD_GET_BUTTON_STATE",
    "CMD_GET_MPU_DATA",
    "CMD_GET_LAST_ADC_VALUES",
    "CMD_TEST_MOTORS",
    "CMD_GET_MOTOR_SPEEDS",
    "CMD_SET_MOTOR_PWM",
    "CMD_GET_MOTOR_PWM",
    "CMD_GET_LOCAL_IP_ADDRESS",
    "CMD_SET_UART_BYPASS_CONTROL",
    "CMD_CALIBRATE_MPU",
    "CMD_SET_PID_GAINS",
    "CMD_GET_PID_GAINS",
    "CMD_SET_CONTROL_PARAMETERS",
    "CMD_GET_CONTROL_PARAMETERS",
    "CMD_SET_MOTOR_BASE_SPEEDS",
    "CMD_GET_MOTOR_BASE_SPEEDS",
    "CMD_CALIBRATE_MOTORS",
    "CMD_TURN_DEGREES",
    "CMD_SET_TURN_PID_GAINS",
    "CMD_GET_TURN_PID_GAINS",
    "CMD_SET_PWM_PERIOD",
    "CMD_GET_PWM_PERIOD",
    "CMD_OTHERS"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_Unerbus[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       1,   14, // enums/sets
       0,    0, // constructors
       4,       // flags
       0,       // signalCount

 // enums: name, alias, flags, count, data
       1,    1, 0x2,   27,   19,

 // enum data: key, value
       2, uint(Unerbus::CommandId::CMD_ACK),
       3, uint(Unerbus::CommandId::CMD_GET_ALIVE),
       4, uint(Unerbus::CommandId::CMD_START_CONFIG),
       5, uint(Unerbus::CommandId::CMD_FIRMWARE),
       6, uint(Unerbus::CommandId::CMD_GET_BUTTON_STATE),
       7, uint(Unerbus::CommandId::CMD_GET_MPU_DATA),
       8, uint(Unerbus::CommandId::CMD_GET_LAST_ADC_VALUES),
       9, uint(Unerbus::CommandId::CMD_TEST_MOTORS),
      10, uint(Unerbus::CommandId::CMD_GET_MOTOR_SPEEDS),
      11, uint(Unerbus::CommandId::CMD_SET_MOTOR_PWM),
      12, uint(Unerbus::CommandId::CMD_GET_MOTOR_PWM),
      13, uint(Unerbus::CommandId::CMD_GET_LOCAL_IP_ADDRESS),
      14, uint(Unerbus::CommandId::CMD_SET_UART_BYPASS_CONTROL),
      15, uint(Unerbus::CommandId::CMD_CALIBRATE_MPU),
      16, uint(Unerbus::CommandId::CMD_SET_PID_GAINS),
      17, uint(Unerbus::CommandId::CMD_GET_PID_GAINS),
      18, uint(Unerbus::CommandId::CMD_SET_CONTROL_PARAMETERS),
      19, uint(Unerbus::CommandId::CMD_GET_CONTROL_PARAMETERS),
      20, uint(Unerbus::CommandId::CMD_SET_MOTOR_BASE_SPEEDS),
      21, uint(Unerbus::CommandId::CMD_GET_MOTOR_BASE_SPEEDS),
      22, uint(Unerbus::CommandId::CMD_CALIBRATE_MOTORS),
      23, uint(Unerbus::CommandId::CMD_TURN_DEGREES),
      24, uint(Unerbus::CommandId::CMD_SET_TURN_PID_GAINS),
      25, uint(Unerbus::CommandId::CMD_GET_TURN_PID_GAINS),
      26, uint(Unerbus::CommandId::CMD_SET_PWM_PERIOD),
      27, uint(Unerbus::CommandId::CMD_GET_PWM_PERIOD),
      28, uint(Unerbus::CommandId::CMD_OTHERS),

       0        // eod
};

Q_CONSTINIT const QMetaObject Unerbus::staticMetaObject = { {
    nullptr,
    qt_meta_stringdata_Unerbus.offsetsAndSizes,
    qt_meta_data_Unerbus,
    nullptr,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_Unerbus_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<void, std::true_type>
    >,
    nullptr
} };

QT_WARNING_POP
QT_END_MOC_NAMESPACE
