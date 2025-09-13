#pragma once

/* I²C config */
/*TO_VERIFY : the driver*/
#define I2C_DRIVER I2CD1
#define I2C1_SDA_PIN GP12
#define I2C1_SCL_PIN GP13

/*TO_VERIFY*/
#define	SPLIT_HAND_PIN_LOW_IS_LEFT

#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET // Activates the double-tap behavior
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 200U // Timeout window in ms in which the double tap can occur.
