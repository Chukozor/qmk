#pragma once

/* I²C config */
// TODO VERIFY the driver
#define I2C_DRIVER I2CD0
#define I2C1_SDA_PIN GP12
#define I2C1_SCL_PIN GP13

#define SERIAL_USART_FULL_DUPLEX   // Enable full duplex operation mode.
#define SERIAL_USART_TX_PIN GP0     // USART TX pin
#define SERIAL_USART_RX_PIN GP1     // USART RX pin

// TODO : VERIFY
//#define	SPLIT_HAND_PIN_LOW_IS_LEFT

#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET // Activates the double-tap behavior
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 400U // Timeout window in ms in which the double tap can occur.

// RGB
// #ifdef RGB_MATRIX_ENABLE
#    define RGB_MATRIX_LED_COUNT 36
#    define RGB_MATRIX_SPLIT \
        { 18, 18 }
#    define SPLIT_TRANSPORT_MIRROR
// #endif


