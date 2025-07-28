#ifndef UNERBUS_PROTOCOL_H
#define UNERBUS_PROTOCOL_H

#include <QObject> // Para Q_NAMESPACE
#include <QtGlobal>

namespace Unerbus
{
    Q_NAMESPACE

    // Definición del protocolo (constantes)
    const QByteArray HEADER = "UNER";
    const char TOKEN = ':';

    // Enumeración de los comandos, extraída de app_config.h en STM32
    enum class CommandId : quint8
    {
        CMD_ACK = 0x0D,
        CMD_GET_ALIVE = 0xF0,
        CMD_START_CONFIG = 0xEE,
        CMD_FIRMWARE = 0xF1,
        CMD_GET_BUTTON_STATE = 0x12,
        CMD_GET_MPU_DATA = 0xA2,
        CMD_GET_LAST_ADC_VALUES = 0xA0,
        CMD_TEST_MOTORS = 0xA1,
        CMD_GET_MOTOR_SPEEDS = 0xA4,
        CMD_SET_MOTOR_PWM = 0xA5,
        CMD_GET_MOTOR_PWM = 0xA6,
        CMD_GET_LOCAL_IP_ADDRESS = 0xE0,
        CMD_SET_UART_BYPASS_CONTROL = 0xDD,
        CMD_CALIBRATE_MPU = 0xA3,
        CMD_SET_PID_GAINS = 0x40,
        CMD_GET_PID_GAINS = 0x41,
        CMD_SET_MAX_PWM_CORRECTION = 0x42,
        CMD_GET_MAX_PWM_CORRECTION = 0x43,
        CMD_SET_MOTOR_BASE_SPEEDS = 0x44,
        CMD_GET_MOTOR_BASE_SPEEDS = 0x45,
        CMD_CALIBRATE_MOTORS = 0x46,
        CMD_TURN_DEGREES = 0x47,
        CMD_SET_TURN_PID_GAINS = 0x48,
        CMD_GET_TURN_PID_GAINS = 0x49,
        CMD_SET_TURN_MAX_SPEED = 0x4A,
        CMD_GET_TURN_MAX_SPEED = 0x4B,
        CMD_SET_PWM_PERIOD = 0x50,
        CMD_GET_PWM_PERIOD = 0x51,
        CMD_SET_MPU_CONFIG = 0xA7,
        CMD_GET_MPU_CONFIG = 0xA8,
        CMD_SET_TURN_MIN_SPEED = 0x4C,
        CMD_GET_TURN_MIN_SPEED = 0x4D,
        CMD_SET_WALL_THRESHOLDS = 0x60,
        CMD_GET_WALL_THRESHOLDS = 0x61,
        CMD_SET_WALL_TARGET_ADC = 0x62,
        CMD_GET_WALL_TARGET_ADC = 0x63,
        CMD_OTHERS
    };
    Q_ENUM_NS(CommandId)

} // namespace Unerbus

#endif // UNERBUS_PROTOCOL_H