#pragma once

/* I²C config */
// TODO VERIFY the driver
// #define I2C_DRIVER I2CD0
// #define I2C0_SDA_PIN GP12
// #define I2C0_SCL_PIN GP13

#define SERIAL_USART_FULL_DUPLEX   // Enable full duplex operation mode.
#define SERIAL_USART_TX_PIN GP0     // USART TX pin
#define SERIAL_USART_RX_PIN GP1     // USART RX pin

// TODO : VERIFY
//#define	SPLIT_HAND_PIN_LOW_IS_LEFT

#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET // Activates the double-tap behavior
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 400U // Timeout window in ms in which the double tap can occur.

#define ENCODER_RESOLUTIONS {4}
#define ENCODER_RESOLUTIONS_RIGHT {4}
// ======= Typing =======
#define TAPPING_TERM 160
#define TAPPING_TERM_PER_KEY
#define HOLD_ON_OTHER_KEY_PRESS
#define HOLD_ON_OTHER_KEY_PRESS_PER_KEY
#define QUICK_TAP_TERM 0
#define QUICK_TAP_TERM_PER_KEY
// ======= Solenoid =====
#define SOLENOID_COUNT 1
#define SOLENOID_PIN GP25
#define SOLENOID_DEFAULT_DWELL 10
#define SOLENOID_MIN_DWELL 1
#define SOLENOID_MAX_DWELL 20
// #define SOLENOID_DWELL_STEP_SIZE 1
#define NO_HAPTIC_MOD