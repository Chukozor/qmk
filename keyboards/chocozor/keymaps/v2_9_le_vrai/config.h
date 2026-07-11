#pragma once
// =====================================================================
// ======= Typing =======
#define TAPPING_TERM 160
#define TAPPING_TERM_PER_KEY
// #define PERMISSIVE_HOLD
#define HOLD_ON_OTHER_KEY_PRESS
#define HOLD_ON_OTHER_KEY_PRESS_PER_KEY

#define QUICK_TAP_TERM 0
#define QUICK_TAP_TERM_PER_KEY

#define COMBO_TERM 50
#define COMBO_TERM_PER_COMBO
#define COMBO_SHOULD_TRIGGER
// ======= Solenoid =====
#define SOLENOID_COUNT 1
#define SOLENOID_PIN GP25
#define SOLENOID_DEFAULT_DWELL 15
#define SOLENOID_MIN_DWELL 15
#define SOLENOID_MAX_DWELL 20
#define SOLENOID_DWELL_STEP_SIZE 1
#define HAPTIC_OFF_IN_LOW_POWER 1
#define NO_HAPTIC_MOD
// #define SOLENOID_PIN_ACTIVE_LOW
// ======= Encoder ======
// #define SPLIT_TRANSACTION_IDS_USER USER_SYNC_A
// #define ENCODERS_PAD_A { B2 }
// #define ENCODERS_PAD_B { B6 }

// #define ENCODERS_PAD_A_RIGHT { B6 }
// #define ENCODERS_PAD_B_RIGHT { B2 }

#define ENCODER_RESOLUTIONS {4}
#define ENCODER_RESOLUTIONS_RIGHT {4}
#define ENCODER_MAP_KEY_DELAY 10

// #define ENCODER_RESOLUTIONS {4}
// #define ENCODER_RESOLUTIONS_RIGHT {4}
// =========== OLED =============
#define SPLIT_OLED_ENABLE
#define SPLIT_LAYER_STATE_ENABLE
#define SPLIT_LED_STATE_ENABLE
#define SPLIT_WPM_ENABLE
#define OLED_BRIGHTNESS 1
#define SPLIT_MODS_ENABLE
#define OLED_TIMEOUT 2000 //in ms
// ==============================

// =========== CIRQUE TRACKPAD =============
// SPI pins (if your keyboard/MCU doesn’t already define them elsewhere)
#define SPI_DRIVER SPID0
#define SPI_SCK_PIN  GP6
#define SPI_MOSI_PIN GP3
#define SPI_MISO_PIN GP4
// Trackpad chip select
#define POINTING_DEVICE_CS_PIN GP5
#define SPLIT_POINTING_ENABLE
#define POINTING_DEVICE_COMBINED

// rotation
// #define POINTING_DEVICE_ROTATION_180
#define POINTING_DEVICE_ROTATION_180


// Cirque options (optional)
#define CIRQUE_PINNACLE_DIAMETER_MM 40
#define TRACKPAD_DEFAULT_DPI 1300
#define CIRQUE_PINNACLE_CURVED_OVERLAY
// #define CIRQUE_PINNACLE_ATTENUATION EXTREG__TRACK_ADCCONFIG__ADC_ATTENUATE_4X
#define CIRQUE_PINNACLE_ATTENUATION EXTREG__TRACK_ADCCONFIG__ADC_ATTENUATE_3X
// #define CIRQUE_PINNACLE_ATTENUATION EXTREG__TRACK_ADCCONFIG__ADC_ATTENUATE_2X
// #define CIRQUE_PINNACLE_ATTENUATION EXTREG__TRACK_ADCCONFIG__ADC_ATTENUATE_1X
// #define POINTING_DEVICE_CIRQUE_PINNACLE_DPI 4500
// #define DEBOUNCE 5
#define F_SCL 100000L // Limit I2C bandwidth

// Auto Mouse
#define POINTING_DEVICE_AUTO_MOUSE_ENABLE
#define MOUSE_EXTENDED_REPORT
#define AUTO_MOUSE_DEFAULT_LAYER 10
#define AUTO_MOUSE_TIME 40
#define AUTO_MOUSE_DELAY 5
#define AUTO_MOUSE_THRESHOLD 10
#define AUTO_MOUSE_DEBOUNCE 25

// SPI setting :
// #define CIRQUE_PINNACLE_CLOCK_SPEED 1000000
#define CIRQUE_PINNACLE_CLOCK_SPEED 500000

// // absolute mode
#define CIRQUE_PINNACLE_POSITION_MODE CIRQUE_PINNACLE_ABSOLUTE_MODE
#define CIRQUE_PINNACLE_TAP_ENABLE
// #define CIRQUE_PINNACLE_TAPPING_TERM 0.75 // default value is TAPPING_TERM/200
// #define CIRQUE_PINNACLE_TOUCH_DEBOUNCE 0.75 // default value is TAPPING_TERM/200

// Trackpad acceleration
#define MAXIMUM_ACCELERATION_ZONE 250.0f // (integer from 0 to 2^16 - 1)
#define DEADZONE 0.25


// relative mode settings
// #define CIRQUE_PINNACLE_POSITION_MODE CIRQUE_PINNACLE_RELATIVE_MODE
// #define CIRQUE_PINNACLE_TAP_ENABLE
// #define CIRQUE_PINNACLE_SECONDARY_TAP_ENABLE
// #define POINTING_DEVICE_GESTURES_SCROLL_ENABLE





















// =============== RGB ===============
#ifdef RGB_MATRIX_ENABLE
#   define RGB_MATRIX_KEYPRESSES // reacts to keypresses
// // #   define RGB_MATRIX_KEYRELEASES // reacts to keyreleases (instead of keypresses)
#   define RGB_DISABLE_WHEN_USB_SUSPENDED // turn off effects when suspended
#   define RGB_MATRIX_FRAMEBUFFER_EFFECTS
// // #   define RGB_MATRIX_LED_PROCESS_LIMIT (RGB_MATRIX_LED_COUNT + 4) / 5 // limits the number of LEDs to process in an animation per task run (increases keyboard responsiveness)
// // #   define RGB_MATRIX_LED_FLUSH_LIMIT 16 // limits in milliseconds how frequently an animation will update the LEDs. 16 (16ms) is equivalent to limiting to 60fps (increases keyboard responsiveness)
#    define RGB_MATRIX_MAXIMUM_BRIGHTNESS 150 // limits maximum brightness of LEDs to 150 out of 255. Higher may cause the controller to crash. 
#    define RGB_MATRIX_HUE_STEP 8
#    define RGB_MATRIX_SAT_STEP 8
#    define RGB_MATRIX_VAL_STEP 8
#    define RGB_MATRIX_SPD_STEP 10
#undef RGB_MATRIX_DEFAULT_VAL
#    define RGB_MATRIX_DEFAULT_VAL 68
#undef RGB_MATRIX_DEFAULT_SPD
#    define RGB_MATRIX_DEFAULT_SPD 70
#undef RGB_MATRIX_DEFAULT_HUE
#    define RGB_MATRIX_DEFAULT_HUE 21 // orange
#undef RGB_MATRIX_DEFAULT_MODE
// #    define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_PIXEL_RAIN
#    define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_ALPHAS_MODS

// /* Enable the animations you want/need.  You may need to enable only a small number of these because       *
//  * they take up a lot of space.  Enable and confirm that you can still successfully compile your firmware. */
// // RGB Matrix Animation modes. Explicitly enabled
// // For full list of effects, see:
// // https://docs.qmk.fm/#/feature_rgb_matrix?id=rgb-matrix-effects
// #    define ENABLE_RGB_MATRIX_ALPHAS_MODS // Static dual hue, speed is hue for secondary hue
// #    define ENABLE_RGB_MATRIX_GRADIENT_UP_DOWN // Static gradient top to bottom, speed controls how much gradient changes
// #    define ENABLE_RGB_MATRIX_GRADIENT_LEFT_RIGHT // Static gradient left to right, speed controls how much gradient changes
// #    define ENABLE_RGB_MATRIX_BREATHING // Single hue brightness cycling animation
// #    define ENABLE_RGB_MATRIX_BAND_SAT // Single hue band fading saturation scrolling left to right
// #    define ENABLE_RGB_MATRIX_BAND_VAL // Single hue band fading brightness scrolling left to right
// #    define ENABLE_RGB_MATRIX_BAND_PINWHEEL_SAT // Single hue 3 blade spinning pinwheel fades saturation
// #    define ENABLE_RGB_MATRIX_BAND_PINWHEEL_VAL  // Single hue 3 blade spinning pinwheel fades brightness
// #    define ENABLE_RGB_MATRIX_BAND_SPIRAL_SAT // Single hue spinning spiral fades saturation
// #    define ENABLE_RGB_MATRIX_BAND_SPIRAL_VAL  // Single hue spinning spiral fades brightness
// #    define ENABLE_RGB_MATRIX_CYCLE_ALL  // Full keyboard solid hue cycling through full gradient
// #    define ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT // Full gradient scrolling left to right
// #    define ENABLE_RGB_MATRIX_CYCLE_UP_DOWN // Full gradient scrolling top to bottom
// #    define ENABLE_RGB_MATRIX_CYCLE_OUT_IN // Full gradient scrolling out to in
// #    define ENABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL // Full dual gradients scrolling out to in
// #    define ENABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON // Full gradient Chevron shapped scrolling left to right
// #    define ENABLE_RGB_MATRIX_CYCLE_PINWHEEL // Full gradient spinning pinwheel around center of keyboard
// #    define ENABLE_RGB_MATRIX_CYCLE_SPIRAL // Full gradient spinning spiral around center of keyboard
// #    define ENABLE_RGB_MATRIX_DUAL_BEACON // Full gradient spinning around center of keyboard
// #    define ENABLE_RGB_MATRIX_RAINBOW_BEACON // Full tighter gradient spinning around center of keyboard
// #    define ENABLE_RGB_MATRIX_RAINBOW_PINWHEELS // Full dual gradients spinning two halfs of keyboard
// #    define ENABLE RGB_MATRIX_FLOWER_BLOOMING     // Full tighter gradient of first half scrolling left to right and second half scrolling right to left
// #    define ENABLE_RGB_MATRIX_RAINDROPS // Randomly changes a single key's hue
// #    define ENABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS // Randomly changes a single key's hue and saturation
// #    define ENABLE_RGB_MATRIX_HUE_BREATHING // Hue shifts up a slight ammount at the same time, then shifts back
// #    define ENABLE_RGB_MATRIX_HUE_PENDULUM // Hue shifts up a slight ammount in a wave to the right, then back to the left
// #    define ENABLE_RGB_MATRIX_HUE_WAVE // Hue shifts up a slight ammount and then back down in a wave to the right
// #    define ENABLE_RGB_MATRIX_PIXEL_FRACTAL // Single hue fractal filled keys pulsing horizontally out to edges
// #    define ENABLE_RGB_MATRIX_PIXEL_FLOW  // Pulsing RGB flow along LED wiring with random hues
// #    define ENABLE_RGB_MATRIX_PIXEL_RAIN // Randomly light keys with random hues
// // enabled only if RGB_MATRIX_FRAMEBUFFER_EFFECTS is defined
// // ======================================================================
// #    define ENABLE_RGB_MATRIX_TYPING_HEATMAP // How hot is your WPM!
// #define RGB_MATRIX_TYPING_HEATMAP_SPREAD 40 // Limit the distance the effect spreads to surrounding keys.
// #define RGB_MATRIX_TYPING_HEATMAP_SLIM // Remove the spread effect entirely.
// #define RGB_MATRIX_TYPING_HEATMAP_INCREASE_STEP 32 // Decreasing this value increases the number of keystrokes needed to fully heat up the key.
// // ======================================================================
// #    define ENABLE_RGB_MATRIX_DIGITAL_RAIN // That famous computer simulation
// // enabled only of RGB_MATRIX_KEYPRESSES or RGB_MATRIX_KEYRELEASES is defined
// #    define ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE // Pulses keys hit to hue & value then fades value out
// #    define ENABLE_RGB_MATRIX_SOLID_REACTIVE // Static single hue, pulses keys hit to shifted hue then fades to current hue
// #    define ENABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE // Hue & value pulse near a single key hit then fades value out
// #    define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE // Hue & value pulse near multiple key hits then fades value out
// #    define ENABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS // Hue & value pulse the same column and row of a single key hit then fades value out
// #    define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS // Hue & value pulse the same column and row of multiple key hits then fades value out
// #    define ENABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS // Hue & value pulse away on the same column and row of a single key hit then fades value out
// #    define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS // Hue & value pulse away on the same column and row of multiple key hits then fades value out
// #    define ENABLE_RGB_MATRIX_SPLASH // Full gradient & value pulse away from a single key hit then fades value out
// #    define ENABLE_RGB_MATRIX_MULTISPLASH // Full gradient & value pulse away from multiple key hits then fades value out
// #    define ENABLE_RGB_MATRIX_SOLID_SPLASH // Hue & value pulse away from a single key hit then fades value out
// #    define ENABLE_RGB_MATRIX_SOLID_MULTISPLASH // Hue & value pulse away from multiple key hits then fades value out
// #    define ENABLE_RGB_MATRIX_STARLIGHT           // LEDs turn on and off at random at varying brightness, maintaining user set color
// #    define ENABLE_RGB_MATRIX_STARLIGHT_DUAL_HUE  // LEDs turn on and off at random at varying brightness, modifies user set hue by +- 30
// #    define ENABLE_RGB_MATRIX_STARLIGHT_DUAL_SAT  // LEDs turn on and off at random at varying brightness, modifies user set saturation by +- 30
// #    define ENABLE_RGB_MATRIX_RIVERFLOW           // Modification to breathing animation, offset's animation depending on key location to simulate a river flowing
// #    define ENABLE_RGB_MATRIX_EFFECT_MAX    
#endif


// ===================================
