#include QMK_KEYBOARD_H
#include "timer.h"
#include "drivers/haptic/solenoid.h"
#include "keymap.h"
#include "keymap_french.h"

// -----------------------------------
// -----------------------------------
// TODO : decommenter la ligne du dessous
// #include "process_record_user.h"
// -----------------------------------



static uint16_t last_fire = 0;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        if (timer_elapsed(last_fire) > 80) {  // 80 ms entre deux activations
            solenoid_fire(0);
            last_fire = timer_read();
        }
    }
    return true;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // _DEBUGLAYER
    [_DEBUGLAYER] = LAYOUT_2_7_regular(
  //--------------------------------------.    --------------------------------------.
       FR_A, KC_B, KC_C, KC_D, KC_E, KC_F,     S(FR_A), S(KC_B), S(KC_C), S(KC_D), S(KC_E), S(KC_F), 
  //|--------+--------+--------+--------+-|    |--------+--------+--------+--------+-|
       KC_G, KC_H, KC_I, KC_J, KC_K, KC_L,     S(KC_G), S(KC_H), S(KC_I), S(KC_J), S(KC_K), S(KC_L), 
  //|--------+--------+--------+--------+-|    |--------+--------+--------+--------+-|
       KC_M, KC_N, KC_O, KC_P, FR_Q, KC_R,     S(KC_M), S(KC_N), S(KC_O), S(KC_P), S(FR_Q), S(KC_R), 
  //|-------------------------------------|    |-------------------------------------|
       KC_U, KC_V, FR_W, KC_X, KC_Y, FR_Z,     S(KC_U), S(KC_V), S(FR_W), S(KC_X), S(KC_Y), S(FR_Z), 
  //|-------------------------------------|    |-------------------------------------|
      KC_P1,KC_P2,KC_P3,KC_P4,KC_P5,KC_P6,       KC_P7,   KC_P8,   KC_P9, KC_LEFT, KC_DOWN, KC_RIGHT
  //|-------------------------------------|    |-------------------------------------|
  ),
  // _COLEMAK_FR
    [_COLEMAK_FR] = LAYOUT_2_7_regular(
  //-----------------------------------------------------.                      -----------------------------------------------------.
       KC_ESC,    FR_Q,    FR_W,    KC_F,    KC_P,    KC_G,                           KC_J,    KC_L,    KC_U,    KC_Y, FR_QUOT,  KC_TAB,
  //|--------+--------+--------+--------+--------+--------|                      |--------+--------+--------+--------+--------+--------|
      KC_LCTL,    FR_A,    KC_R,    KC_S,    KC_T,    KC_D,                           KC_H,    KC_N,    KC_E,    KC_I,    KC_O, KC_RCTL,
  //|--------+--------+--------+--------+--------+--------|                      |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    FR_Q,    KC_X,    KC_C,    KC_V,    KC_B,                           KC_K,    FR_M, FR_COMM,  FR_DOT, FR_QUES, KC_RSFT,
  //|--------------------------------------------------------------|     |-------------------------------------------------------------|
      KC_LSFT,    FR_Q,    KC_X,    KC_C,    KC_V,    KC_B,                           KC_K,    FR_M, FR_COMM,  FR_DOT, FR_QUES, KC_RSFT,
  //|--------------------------------------------------------------|     |-------------------------------------------------------------|
      KC_LSFT,    FR_Q,    KC_X,    KC_C,    KC_V,    KC_B,                           KC_K,    FR_M, FR_COMM,  FR_DOT, FR_QUES, KC_RSFT
  //|--------------------------------------------------------------|     |-------------------------------------------------------------|
  ),
    [_REG_QWERTY] = LAYOUT_2_7_regular(
  //-----------------------------------------------------.                      -----------------------------------------------------.
       KC_ESC,    FR_Q,    FR_W,    KC_F,    KC_P,    KC_G,                           KC_J,    KC_L,    KC_U,    KC_Y, FR_QUOT,  KC_TAB,
  //|--------+--------+--------+--------+--------+--------|                      |--------+--------+--------+--------+--------+--------|
      KC_LCTL,    FR_A,    KC_R,    KC_S,    KC_T,    KC_D,                           KC_H,    KC_N,    KC_E,    KC_I,    KC_O, KC_RCTL,
  //|--------+--------+--------+--------+--------+--------|                      |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    FR_Q,    KC_X,    KC_C,    KC_V,    KC_B,                           KC_K,    FR_M, FR_COMM,  FR_DOT, FR_QUES, KC_RSFT,
  //|--------------------------------------------------------------|     |-------------------------------------------------------------|
      KC_LSFT,    FR_Q,    KC_X,    KC_C,    KC_V,    KC_B,                           KC_K,    FR_M, FR_COMM,  FR_DOT, FR_QUES, KC_RSFT,
  //|--------------------------------------------------------------|     |-------------------------------------------------------------|
      KC_LSFT,    FR_Q,    KC_X,    KC_C,    KC_V,    KC_B,                           KC_K,    FR_M, FR_COMM,  FR_DOT, FR_QUES, KC_RSFT
  //|--------------------------------------------------------------|     |-------------------------------------------------------------|
  )
};


// // ==============================================
// ENCODERS :
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
        // Mappings for 1st Encoder          // Mappings for 2nd Encoder
  [_DEBUGLAYER]   = { ENCODER_CCW_CW(KC_WH_U, KC_WH_D),  ENCODER_CCW_CW(KC_VOLD, KC_VOLU)  }, // Mapping for Base layer
  [_COLEMAK_FR]   = { ENCODER_CCW_CW(KC_WH_U, KC_WH_D),  ENCODER_CCW_CW(KC_VOLD, KC_VOLU)  }, // Mapping for Base layer
  [_REG_QWERTY]   = { ENCODER_CCW_CW(KC_WH_U, KC_WH_D),  ENCODER_CCW_CW(KC_VOLD, KC_VOLU)  }, // Mapping for Base layer
};
