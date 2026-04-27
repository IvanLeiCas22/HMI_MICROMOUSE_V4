/****************************************************************************
** Meta object code from reading C++ file 'unerbus_protocol.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.11.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../Comunicacion/unerbus_protocol.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'unerbus_protocol.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN7UnerbusE_t {};
} // unnamed namespace

template <> constexpr inline auto Unerbus::qt_create_metaobjectdata<qt_meta_tag_ZN7UnerbusE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "Unerbus",
        "CommandId",
        "CMD_ACK",
        "CMD_GET_ALIVE",
        "CMD_START_CONFIG",
        "CMD_FIRMWARE",
        "CMD_GET_BUTTON_STATE",
        "CMD_GET_MPU_DATA",
        "CMD_GET_IR_SENSOR_SNAPSHOT",
        "CMD_TEST_MOTORS",
        "CMD_GET_MOTOR_SPEEDS",
        "CMD_SET_MOTOR_PWM",
        "CMD_GET_MOTOR_PWM",
        "CMD_GET_LOCAL_IP_ADDRESS",
        "CMD_SET_UART_BYPASS_CONTROL",
        "CMD_CALIBRATE_MPU",
        "CMD_SET_PID_GAINS",
        "CMD_GET_PID_GAINS",
        "CMD_SET_MAX_PWM_CORRECTION",
        "CMD_GET_MAX_PWM_CORRECTION",
        "CMD_SET_MOTOR_BASE_SPEEDS",
        "CMD_GET_MOTOR_BASE_SPEEDS",
        "CMD_CALIBRATE_MOTORS",
        "CMD_TURN_DEGREES",
        "CMD_SET_TURN_PID_GAINS",
        "CMD_GET_TURN_PID_GAINS",
        "CMD_SET_TURN_MAX_SPEED",
        "CMD_GET_TURN_MAX_SPEED",
        "CMD_SET_PWM_PERIOD",
        "CMD_GET_PWM_PERIOD",
        "CMD_SET_MPU_CONFIG",
        "CMD_GET_MPU_CONFIG",
        "CMD_SET_TURN_MIN_SPEED",
        "CMD_GET_TURN_MIN_SPEED",
        "CMD_SET_WALL_THRESHOLDS",
        "CMD_GET_WALL_THRESHOLDS",
        "CMD_SET_WALL_TARGET_ADC",
        "CMD_GET_WALL_TARGET_ADC",
        "CMD_SET_APP_STATE",
        "CMD_GET_APP_STATE",
        "CMD_SET_MENU_MODE",
        "CMD_GET_MENU_MODE",
        "CMD_GET_ROBOT_STATUS",
        "CMD_SET_CRUISE_PARAMS",
        "CMD_GET_CRUISE_PARAMS",
        "CMD_SET_BRAKING_PID_GAINS",
        "CMD_GET_BRAKING_PID_GAINS",
        "CMD_SET_BRAKING_PARAMS",
        "CMD_GET_BRAKING_PARAMS",
        "CMD_SET_BRAKING_MAX_SPEED",
        "CMD_GET_BRAKING_MAX_SPEED",
        "CMD_SET_BRAKING_MIN_SPEED",
        "CMD_GET_BRAKING_MIN_SPEED",
        "CMD_SET_BRAKING_DEAD_ZONE",
        "CMD_GET_BRAKING_DEAD_ZONE",
        "CMD_GET_YAW_ANGLE",
        "CMD_GET_SMOOTH_TURN_CONFIG",
        "CMD_SET_SMOOTH_TURN_CONFIG",
        "CMD_SET_TURN_VELOCITY_PID_GAINS",
        "CMD_GET_TURN_VELOCITY_PID_GAINS",
        "CMD_SET_TURN_TARGET_DPS",
        "CMD_GET_TURN_TARGET_DPS",
        "CMD_GET_DELAY_TICKS",
        "CMD_SET_DELAY_TICKS",
        "CMD_UPDATE_MAZE_CELL",
        "CMD_SYNC_MAZE_COLUMN",
        "CMD_OTHERS"
    };

    QtMocHelpers::UintData qt_methods {
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
        // enum 'CommandId'
        QtMocHelpers::EnumData<CommandId>(1, 1, QMC::EnumIsScoped).add({
            {    2, CommandId::CMD_ACK },
            {    3, CommandId::CMD_GET_ALIVE },
            {    4, CommandId::CMD_START_CONFIG },
            {    5, CommandId::CMD_FIRMWARE },
            {    6, CommandId::CMD_GET_BUTTON_STATE },
            {    7, CommandId::CMD_GET_MPU_DATA },
            {    8, CommandId::CMD_GET_IR_SENSOR_SNAPSHOT },
            {    9, CommandId::CMD_TEST_MOTORS },
            {   10, CommandId::CMD_GET_MOTOR_SPEEDS },
            {   11, CommandId::CMD_SET_MOTOR_PWM },
            {   12, CommandId::CMD_GET_MOTOR_PWM },
            {   13, CommandId::CMD_GET_LOCAL_IP_ADDRESS },
            {   14, CommandId::CMD_SET_UART_BYPASS_CONTROL },
            {   15, CommandId::CMD_CALIBRATE_MPU },
            {   16, CommandId::CMD_SET_PID_GAINS },
            {   17, CommandId::CMD_GET_PID_GAINS },
            {   18, CommandId::CMD_SET_MAX_PWM_CORRECTION },
            {   19, CommandId::CMD_GET_MAX_PWM_CORRECTION },
            {   20, CommandId::CMD_SET_MOTOR_BASE_SPEEDS },
            {   21, CommandId::CMD_GET_MOTOR_BASE_SPEEDS },
            {   22, CommandId::CMD_CALIBRATE_MOTORS },
            {   23, CommandId::CMD_TURN_DEGREES },
            {   24, CommandId::CMD_SET_TURN_PID_GAINS },
            {   25, CommandId::CMD_GET_TURN_PID_GAINS },
            {   26, CommandId::CMD_SET_TURN_MAX_SPEED },
            {   27, CommandId::CMD_GET_TURN_MAX_SPEED },
            {   28, CommandId::CMD_SET_PWM_PERIOD },
            {   29, CommandId::CMD_GET_PWM_PERIOD },
            {   30, CommandId::CMD_SET_MPU_CONFIG },
            {   31, CommandId::CMD_GET_MPU_CONFIG },
            {   32, CommandId::CMD_SET_TURN_MIN_SPEED },
            {   33, CommandId::CMD_GET_TURN_MIN_SPEED },
            {   34, CommandId::CMD_SET_WALL_THRESHOLDS },
            {   35, CommandId::CMD_GET_WALL_THRESHOLDS },
            {   36, CommandId::CMD_SET_WALL_TARGET_ADC },
            {   37, CommandId::CMD_GET_WALL_TARGET_ADC },
            {   38, CommandId::CMD_SET_APP_STATE },
            {   39, CommandId::CMD_GET_APP_STATE },
            {   40, CommandId::CMD_SET_MENU_MODE },
            {   41, CommandId::CMD_GET_MENU_MODE },
            {   42, CommandId::CMD_GET_ROBOT_STATUS },
            {   43, CommandId::CMD_SET_CRUISE_PARAMS },
            {   44, CommandId::CMD_GET_CRUISE_PARAMS },
            {   45, CommandId::CMD_SET_BRAKING_PID_GAINS },
            {   46, CommandId::CMD_GET_BRAKING_PID_GAINS },
            {   47, CommandId::CMD_SET_BRAKING_PARAMS },
            {   48, CommandId::CMD_GET_BRAKING_PARAMS },
            {   49, CommandId::CMD_SET_BRAKING_MAX_SPEED },
            {   50, CommandId::CMD_GET_BRAKING_MAX_SPEED },
            {   51, CommandId::CMD_SET_BRAKING_MIN_SPEED },
            {   52, CommandId::CMD_GET_BRAKING_MIN_SPEED },
            {   53, CommandId::CMD_SET_BRAKING_DEAD_ZONE },
            {   54, CommandId::CMD_GET_BRAKING_DEAD_ZONE },
            {   55, CommandId::CMD_GET_YAW_ANGLE },
            {   56, CommandId::CMD_GET_SMOOTH_TURN_CONFIG },
            {   57, CommandId::CMD_SET_SMOOTH_TURN_CONFIG },
            {   58, CommandId::CMD_SET_TURN_VELOCITY_PID_GAINS },
            {   59, CommandId::CMD_GET_TURN_VELOCITY_PID_GAINS },
            {   60, CommandId::CMD_SET_TURN_TARGET_DPS },
            {   61, CommandId::CMD_GET_TURN_TARGET_DPS },
            {   62, CommandId::CMD_GET_DELAY_TICKS },
            {   63, CommandId::CMD_SET_DELAY_TICKS },
            {   64, CommandId::CMD_UPDATE_MAZE_CELL },
            {   65, CommandId::CMD_SYNC_MAZE_COLUMN },
            {   66, CommandId::CMD_OTHERS },
        }),
    };
    return QtMocHelpers::metaObjectData<void, qt_meta_tag_ZN7UnerbusE_t>(QMC::PropertyAccessInStaticMetaCall, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}

static constexpr auto qt_staticMetaObjectContent_ZN7UnerbusE =
    Unerbus::qt_create_metaobjectdata<qt_meta_tag_ZN7UnerbusE_t>();
static constexpr auto qt_staticMetaObjectStaticContent_ZN7UnerbusE =
    qt_staticMetaObjectContent_ZN7UnerbusE.staticData;
static constexpr auto qt_staticMetaObjectRelocatingContent_ZN7UnerbusE =
    qt_staticMetaObjectContent_ZN7UnerbusE.relocatingData;

Q_CONSTINIT const QMetaObject Unerbus::staticMetaObject = { {
    nullptr,
    qt_staticMetaObjectStaticContent_ZN7UnerbusE.stringdata,
    qt_staticMetaObjectStaticContent_ZN7UnerbusE.data,
    nullptr,
    nullptr,
    qt_staticMetaObjectRelocatingContent_ZN7UnerbusE.metaTypes,
    nullptr
} };

QT_WARNING_POP
