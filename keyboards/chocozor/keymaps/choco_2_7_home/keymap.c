/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

// #include "print.h"
#include QMK_KEYBOARD_H
#include "keymap.h"
#include "keymap_french.h"
// #include "custom_files/helpers.h"
// #include "custom_files/french_symbols/french_symbols.h"
// #include "custom_files/french_symbols/shift_behaviours.c"
// #include "pointing_device.h"
// #include "math.h"  // for sqrtf()

// -----------------------------------
// -----------------------------------
// #include "custom_files/tap_dances/tap_dance.h"


// ------------- COMBO ---------------
// enum combos {
//   COMBO_ACTIVE_NUMPAD,
//   COMBO_ACTIVE_NUMPAD2,
//   COMBO_MULTIMEDIA,
//   COMBO_OSM_SHIFT,
//   // COMBO_OSM_SHIFT2,
//   COMBO_CAPSLOCK,
//   COMBO_BOOT,
//   COMBO_BOOT2,
//   // TOGGLE_GAMING,
//   TOGGLE_GAME,
//   TOGGLE_TF2,
//   // TOGGLE_GAME2,
//   // FAST_SWITCH_GAME_COLEMAK_COMBO,
//   // FAST_SWITCH_GAME_COLEMAK_COMBO2,
//   TOGGLE_WEB,
//   // TOGGLE_RGB,
//   COMBO_CLEAR_EEPROM,
//   COMBO_WEB,
//   COMBO_PRINT_SCREEN,
//   COMBO_REG_QWERTY,
//   COMBO_REG_QWERTY2,
//   COMBO_NUMPAD_RIGHT,
//   COMBO_NUMPAD_RIGHT2
//   // ...,
//   // COMBO_E_AIGU
// };





// // const uint16_t PROGMEM temp_active_RGB[] = {MY_ENT, HT_SPC, COMBO_END};
// const uint16_t PROGMEM temp_active_numpad[] = {KC_N, HT_E, KC_I, COMBO_END};
// const uint16_t PROGMEM temp_active_numpad2[] = {S(KC_N), S(KC_E), S(KC_I), COMBO_END};
// const uint16_t PROGMEM toggle_numpad_right[] = {MOFKEYS, KC_LALT, COMBO_END};
// const uint16_t PROGMEM toggle_numpad_right2[] = {MO(_OPERATIONS), KC_LALT, COMBO_END};
// const uint16_t PROGMEM temp_active_MULTIMEDIA[] = {KC_LGUI, MY_NAV, HT_SPC, COMBO_END};
// const uint16_t PROGMEM temp_active_SHIFT[] = {CSTM_ENT, HT_SPC, COMBO_END};
// // const uint16_t PROGMEM r[] = {MOFKEYS, CSTM_ENT, COMBO_END};
// const uint16_t PROGMEM combo_capslock[] = {KC_LSFT, KC_RSFT, COMBO_END};
// const uint16_t PROGMEM temp_active_boot[] = {MY_NAV,HT_SPC,KC_LGUI,KC_LALT,CSTM_ENT, COMBO_END};
// const uint16_t PROGMEM temp_active_boot2[] = {KC_LGUI,MY_NAV,HT_SPC,MOFKEYS, CSTM_ENT,KC_LALT, COMBO_END};
// // const uint16_t PROGMEM toggle_gaming[] = {FR_Q,FR_W,KC_F,KC_P,KC_G, COMBO_END};
// const uint16_t PROGMEM toggle_game[] = {FR_A,KC_R,KC_S,KC_T,KC_D, COMBO_END};
// const uint16_t PROGMEM toggle_tf2[] = {FR_Q,FR_W,KC_F,KC_P,KC_G,COMBO_END};
// // const uint16_t PROGMEM toggle_game2[] = {KC_LSFT,FR_A,FR_W,KC_D,KC_T, COMBO_END};
// // const uint16_t PROGMEM fast_switch_game_colemak_combo[] = {MY_ESC,MY_LCTL,KC_LSFT, COMBO_END};
// // const uint16_t PROGMEM fast_switch_game_colemak_combo2[] = {KC_ESC,KC_TAB, APEX_CTL, COMBO_END};
// // const uint16_t PROGMEM combo_toggle_web[] = {KC_LGUI,MY_NAV, COMBO_END};
// // const uint16_t PROGMEM toggle_RGB[] = {MOFKEYS, CSTM_ENT,KC_LALT, COMBO_END};
// const uint16_t PROGMEM combo_clear_eeprom[] = {RGB_TOG, ____MOD, _I_COUL, __I_LUM, __I_SAT, COMBO_END};
// const uint16_t PROGMEM combo_web[] = {MY_LCTL, MY_RCTL, COMBO_END};
// const uint16_t PROGMEM combo_print_screen[] = {KC_R, KC_S, KC_T, COMBO_END};
// const uint16_t PROGMEM combo_reg_qwerty[] = {KC_LCTL,MY_ESC,KC_BSPC,KC_RCTL, COMBO_END};
// const uint16_t PROGMEM combo_reg_qwerty2[] = {MY_ESC,KC_LSFT,KC_TAB,KC_RSFT, COMBO_END};
// // const uint16_t PROGMEM ...[] = {..., ..., COMBO_END};
// // const uint16_t PROGMEM toggle_gaming_2[] = {FR_Q, KC_R, KC_C, KC_F, KC_T, COMBO_END};
// // const uint16_t PROGMEM temp_active_e_aigu[] = {HT_SPC, HT_E, COMBO_END};
// // const uint16_t PROGMEM bis_temp_active_RGB[] = {HT_ENT, HT_SPC, COMBO_END};
// // const uint16_t PROGMEM bis_x_temp_active_RGB[] = {CSTM_ENT, HT_SPC, COMBO_END};
// // const uint16_t PROGMEM temp_active_RGB[] = {HT_ENT, HT_SPC, COMBO_END};
// combo_t key_combos[] = {
//     [COMBO_ACTIVE_NUMPAD]=COMBO(temp_active_numpad, MO_NUMPAD),
//     [COMBO_ACTIVE_NUMPAD2]=COMBO(temp_active_numpad2, MO_NUMPAD),
//     [COMBO_NUMPAD_RIGHT]=COMBO(toggle_numpad_right, TG(_NUMPAD_RIGHT)),
//     [COMBO_NUMPAD_RIGHT2]=COMBO(toggle_numpad_right2, TG(_NUMPAD_RIGHT)),
//     [COMBO_MULTIMEDIA]=COMBO(temp_active_MULTIMEDIA, MO(_MULTIMEDIA)),
//     // [TOGGLE_GAMING]=COMBO(toggle_gaming, TG(_AUX_GAME)),
//     [TOGGLE_GAME]=COMBO(toggle_game, TG_GAME),
//     [TOGGLE_TF2]=COMBO(toggle_tf2, TG(_TF2)),
//     // [TOGGLE_GAME2]=COMBO(toggle_game2, TG_GAME),
//     [COMBO_OSM_SHIFT]=COMBO(temp_active_SHIFT, OSM(MOD_LSFT)),
//     // [COMBO_OSM_SHIFT2]=COMBO(temp_active_SHIFT2, OSM(MOD_LSFT)),
//     [COMBO_CAPSLOCK]=COMBO(combo_capslock, DBL_SHIFT),
//     [COMBO_BOOT]=COMBO(temp_active_boot, QK_BOOT),
//     [COMBO_BOOT2]=COMBO(temp_active_boot2, QK_BOOT),
//     // [FAST_SWITCH_GAME_COLEMAK_COMBO]=COMBO(fast_switch_game_colemak_combo, FAST_SWITCH_GAME_COLEMAK),
//     // [FAST_SWITCH_GAME_COLEMAK_COMBO2]=COMBO(fast_switch_game_colemak_combo2, FAST_SWITCH_GAME_COLEMAK),
//     // [TOGGLE_WEB]=COMBO(combo_toggle_web, TG(_WEB_BROWSER)),
//     // [TOGGLE_RGB]=COMBO(toggle_RGB, TG(_RGB)),
//     [COMBO_CLEAR_EEPROM]=COMBO(combo_clear_eeprom, QK_CLEAR_EEPROM),
//     [COMBO_WEB]=COMBO(combo_web, TG(_WEB_BROWSER)),
//     [COMBO_PRINT_SCREEN]=COMBO(combo_print_screen, KC_PSCR),
//     [COMBO_REG_QWERTY]=COMBO(combo_reg_qwerty, TG(_REG_QWERTY)),
//     [COMBO_REG_QWERTY2]=COMBO(combo_reg_qwerty2, TG(_REG_QWERTY)),
//     // [...]=COMBO(combo_my_bquote2, ...),
//     // [COMBO_OSL_RGB]=COMBO(temp_active_RGB, OSL(_RGB)),
//     // [TOGGLE_GAMING_2]=COMBO(toggle_gaming_2, TG(_GAMING)),
//     // COMBO(temp_active_SHIFT, COMBO_SHIFT), 
//     // COMBO(temp_active_SHIFT, CUSTOM_OSL_WITH_MOD),
//     // [COMBO_E_AIGU]=COMBO(temp_active_e_aigu, E_AIGU),
// //     COMBO(bis_temp_active_RGB, OSL(_RGB)),
// //     COMBO(bis_x_temp_active_RGB, OSL(_RGB)),
// };

// bool combo_should_trigger(uint16_t combo_index, combo_t *combo, uint16_t keycode, keyrecord_t *record) {
//   if (combo_index == TOGGLE_GAME) {
//       return true;
//   }
//   if (combo_index == TOGGLE_TF2) {
//     return true;
// }
//   if (layer_state_is(_TF2)) {
//       return false;
//   }
//   if (layer_state_is(_GAME)) {
//     return false;
// }
//   return true;
// }

// // ------------- END COMBO ---------------

// -----------------------------------


// // This globally defines all key overrides to be used
// const key_override_t *key_overrides[] = {
//     &ko_make_with_layers(MOD_MASK_SHIFT, FR_COMM, FR_COLN, 1 << _COLEMAK_FR), // check if it works
//     &ko_make_with_layers(MOD_MASK_SHIFT, FR_DOT,  FR_SCLN, 1 << _COLEMAK_FR),
//     &ko_make_with_layers(MOD_MASK_SHIFT, FR_QUES, FR_EXLM, 1 << _COLEMAK_FR),
//     &ko_make_with_layers(MOD_MASK_SHIFT, FR_QUOT, FR_DQUO, 1 << _COLEMAK_FR),
//     &ko_make_with_layers(MOD_MASK_SHIFT, FR_COMM, FR_COLN, 1 << _CAPS_LOCK), // check if it works
//     &ko_make_with_layers(MOD_MASK_SHIFT, FR_DOT,  FR_SCLN, 1 << _CAPS_LOCK),
//     &ko_make_with_layers(MOD_MASK_SHIFT, FR_QUES, FR_EXLM, 1 << _CAPS_LOCK),
//     &ko_make_with_layers(MOD_MASK_SHIFT, FR_QUOT, FR_DQUO, 1 << _CAPS_LOCK),
//     // &ko_make_with_layers(MOD_MASK_SHIFT, FR_COMM, FR_COLN, 1 << _SFT_COLEMAK_FR), // check if it works
//     // &ko_make_with_layers(MOD_MASK_SHIFT, FR_DOT,  FR_SCLN, 1 << _SFT_COLEMAK_FR),
//     // &ko_make_with_layers(MOD_MASK_SHIFT, FR_QUES, FR_EXLM, 1 << _SFT_COLEMAK_FR),
//     // &ko_make_with_layers(MOD_MASK_SHIFT, FR_QUOT, FR_DQUO, 1 << _SFT_COLEMAK_FR),
//     // &ko_make_with_layers(MOD_MASK_SHIFT, FR_AT,   FR_AGRV, 1 << 2);
    
//     NULL // Null terminate the array of overrides!
// };

// -----------------------------------
// -----------------------------------
// TODO : decommentes la ligne du dessous
// #include "process_record_user.h"
// -----------------------------------

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // _COLEMAK_FR
    [_COLEMAK_FR] = LAYOUT_split_6x6(
  //-----------------------------------------------------.                      -----------------------------------------------------.
       KC_ESC,    FR_Q,    FR_W,    KC_F,    KC_P,    KC_G,                           KC_J,    KC_L,    KC_U,    KC_Y, FR_QUOT,  KC_TAB,
  //|--------+--------+--------+--------+--------+--------|                      |--------+--------+--------+--------+--------+--------|
      KC_LCTL,    FR_A,    KC_R,    KC_S,    KC_T,    KC_D,                           KC_H,    KC_N,    KC_E,    KC_I,    KC_O, KC_RCTL,
  //|--------+--------+--------+--------+--------+--------|                      |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    FR_Q,    KC_X,    KC_C,    KC_V,    KC_B,                           KC_K,    FR_M, FR_COMM,  FR_DOT, FR_QUES, KC_RSFT,
  //|--------------------------------------------------------------|     |-------------------------------------------------------------|
      KC_LSFT,    FR_Q,    KC_X,    KC_C,    KC_V,    KC_B,                           KC_K,    FR_M, FR_COMM,  FR_DOT, FR_QUES, KC_RSFT,
  //|--------------------------------------------------------------|     |-------------------------------------------------------------|
      KC_LSFT,    FR_Q,    KC_X,    KC_C,    KC_V,    KC_B,                           KC_K,    FR_M, FR_COMM,  FR_DOT, FR_QUES, KC_RSFT,
  //|--------------------------------------------------------------|     |-------------------------------------------------------------|
      KC_LSFT,    FR_Q,    KC_X,    KC_C,    KC_V,    KC_B,                           KC_K,    FR_M, FR_COMM,  FR_DOT, FR_QUES, KC_RSFT
  //|--------------------------------------------------------------|     |-------------------------------------------------------------|
  ),
    [_REG_QWERTY] = LAYOUT_split_6x6(
  //-----------------------------------------------------.                      -----------------------------------------------------.
       KC_ESC,    FR_Q,    FR_W,    KC_F,    KC_P,    KC_G,                           KC_J,    KC_L,    KC_U,    KC_Y, FR_QUOT,  KC_TAB,
  //|--------+--------+--------+--------+--------+--------|                      |--------+--------+--------+--------+--------+--------|
      KC_LCTL,    FR_A,    KC_R,    KC_S,    KC_T,    KC_D,                           KC_H,    KC_N,    KC_E,    KC_I,    KC_O, KC_RCTL,
  //|--------+--------+--------+--------+--------+--------|                      |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    FR_Q,    KC_X,    KC_C,    KC_V,    KC_B,                           KC_K,    FR_M, FR_COMM,  FR_DOT, FR_QUES, KC_RSFT,
  //|--------------------------------------------------------------|     |-------------------------------------------------------------|
      KC_LSFT,    FR_Q,    KC_X,    KC_C,    KC_V,    KC_B,                           KC_K,    FR_M, FR_COMM,  FR_DOT, FR_QUES, KC_RSFT,
  //|--------------------------------------------------------------|     |-------------------------------------------------------------|
      KC_LSFT,    FR_Q,    KC_X,    KC_C,    KC_V,    KC_B,                           KC_K,    FR_M, FR_COMM,  FR_DOT, FR_QUES, KC_RSFT,
  //|--------------------------------------------------------------|     |-------------------------------------------------------------|
      KC_LSFT,    FR_Q,    KC_X,    KC_C,    KC_V,    KC_B,                           KC_K,    FR_M, FR_COMM,  FR_DOT, FR_QUES, KC_RSFT
  //|--------------------------------------------------------------|     |-------------------------------------------------------------|
  )
};


void render_layer_status(void) {
  switch (get_highest_layer(layer_state)){
    case _COLEMAK_FR :
      // -------|"-----00000-----00000-----00000-----00000-----"
      //         "                                             "
      // -------|"-----00000-----00000-----00000-----00000-----"
      oled_write("COLE-  MAK       FR                          ", false);
      break;
    case _REG_QWERTY :
      // -------|"-----00000-----00000-----00000-----00000-----"
      //         "                                             "
      oled_write(" REG_ KEYB                                   ", false);
      break;
    }
  }


void render_logo(void) {
  static const char PROGMEM logo[] = {
    // 'cornia', 32x32px
  0, 0, 0, 0, 0, 0, 0, 0, 192, 32, 16, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 16, 32, 192, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 128, 128, 192, 224, 255, 255, 240, 224, 200, 132, 132, 6, 6, 6, 6, 132, 132, 204, 224, 240, 255, 255, 224, 192, 192, 128, 0, 0, 0, 0, 12, 7, 3, 1, 0, 0, 28, 112, 192, 1, 1, 3, 3, 1, 224, 224, 17, 3, 3, 1, 1, 192, 112, 28, 0, 0, 1, 3, 7, 12, 0, 0, 0, 0, 0, 0, 0, 0, 64, 64, 64, 97, 98, 114, 56, 60, 31, 31, 60, 56, 114, 98, 97, 64, 64, 64, 0, 0, 0, 0, 0, 0, 0
  };
  oled_write_raw_P(logo, sizeof(logo));
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) { return OLED_ROTATION_270; }

// Draw to OLED
bool oled_task_user() {
  oled_set_cursor(0, 0);
  render_logo();
  oled_set_cursor(0, 7);
  render_layer_status();
  return false;
}

void oled_render_boot(bool bootloader) {
  oled_clear();
  oled_set_cursor(0, 2);
  if (bootloader) {
    oled_write_P(PSTR("FLASH"), false);
  } else {
    oled_write_P(PSTR("RESET"), false);
  }
  oled_render_dirty(true);
}

bool shutdown_user(bool jump_to_bootloader) {
  oled_render_boot(jump_to_bootloader);
  return false;
}

// // ==============================================
// ENCODERS :
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
        // Mappings for 1st Encoder          // Mappings for 2nd Encoder
  [_COLEMAK_FR]   = { ENCODER_CCW_CW(KC_WH_U, KC_WH_D),  ENCODER_CCW_CW(KC_VOLD, KC_VOLU)  }, // Mapping for Base layer
  [_REG_QWERTY]   = { ENCODER_CCW_CW(KC_WH_U, KC_WH_D),  ENCODER_CCW_CW(KC_VOLD, KC_VOLU)  }, // Mapping for Base layer
};