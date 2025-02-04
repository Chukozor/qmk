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
#include "custom_files/helpers.h"
#include "custom_files/french_symbols/french_symbols.h"
#include "custom_files/french_symbols/shift_behaviours.c"
#include "pointing_device.h"

// -----------------------------------
bool game_mode = 0;
bool test_game_mode(void){
 return game_mode;
}

void toggle_game_mode(bool value){
 game_mode = value;
}
// -----------------------------------
#include "custom_files/tap_dances/tap_dance.h"


// ------------- COMBO ---------------
enum combos {
  COMBO_ACTIVE_NUMPAD,
  COMBO_ACTIVE_NUMPAD2,
  COMBO_MULTIMEDIA,
  COMBO_OSM_SHIFT,
  // COMBO_OSM_SHIFT2,
  COMBO_CAPSLOCK,
  COMBO_BOOT,
  COMBO_BOOT2,
  // TOGGLE_GAMING,
  TOGGLE_GAME,
  // TOGGLE_GAME2,
  // FAST_SWITCH_GAME_COLEMAK_COMBO,
  // FAST_SWITCH_GAME_COLEMAK_COMBO2,
  TOGGLE_WEB,
  TOGGLE_RGB,
  COMBO_CLEAR_EEPROM,
  COMBO_WEB,
  COMBO_PRINT_SCREEN,
  COMBO_REG_QWERTY,
  COMBO_REG_QWERTY2,
  // ...,
  // COMBO_E_AIGU
};





// const uint16_t PROGMEM temp_active_RGB[] = {MY_ENT, HT_SPC, COMBO_END};
const uint16_t PROGMEM temp_active_numpad[] = {KC_N, HT_E, COMBO_END};
const uint16_t PROGMEM temp_active_numpad2[] = {S(KC_N), S(KC_E), COMBO_END};
const uint16_t PROGMEM temp_active_MULTIMEDIA[] = {KC_LGUI, MY_NAV, HT_SPC, COMBO_END};
const uint16_t PROGMEM temp_active_SHIFT[] = {CSTM_ENT, HT_SPC, COMBO_END};
// const uint16_t PROGMEM r[] = {MOFKEYS, CSTM_ENT, COMBO_END};
const uint16_t PROGMEM combo_capslock[] = {KC_LSFT, KC_RSFT, COMBO_END};
const uint16_t PROGMEM temp_active_boot[] = {MY_NAV,HT_SPC,KC_LGUI,KC_LALT,CSTM_ENT, COMBO_END};
const uint16_t PROGMEM temp_active_boot2[] = {KC_LGUI,MY_NAV,HT_SPC,MOFKEYS, CSTM_ENT,KC_LALT, COMBO_END};
// const uint16_t PROGMEM toggle_gaming[] = {FR_Q,FR_W,KC_F,KC_P,KC_G, COMBO_END};
const uint16_t PROGMEM toggle_game[] = {FR_A,KC_R,KC_S,KC_T,KC_D, COMBO_END};
// const uint16_t PROGMEM toggle_game2[] = {KC_LSFT,FR_A,FR_W,KC_D,KC_T, COMBO_END};
// const uint16_t PROGMEM fast_switch_game_colemak_combo[] = {MY_ESC,MY_LCTL,KC_LSFT, COMBO_END};
// const uint16_t PROGMEM fast_switch_game_colemak_combo2[] = {KC_ESC,KC_TAB, APEX_CTL, COMBO_END};
// const uint16_t PROGMEM combo_toggle_web[] = {KC_LGUI,MY_NAV, COMBO_END};
const uint16_t PROGMEM toggle_RGB[] = {MOFKEYS, CSTM_ENT,KC_LALT, COMBO_END};
const uint16_t PROGMEM combo_clear_eeprom[] = {RGB_TOG, ____MOD, _I_COUL, __I_LUM, __I_SAT, COMBO_END};
const uint16_t PROGMEM combo_web[] = {MY_LCTL, MY_RCTL, COMBO_END};
const uint16_t PROGMEM combo_print_screen[] = {KC_R, KC_S, KC_T, COMBO_END};
const uint16_t PROGMEM combo_reg_qwerty[] = {KC_LCTL,MY_ESC,KC_BSPC,KC_RCTL, COMBO_END};
const uint16_t PROGMEM combo_reg_qwerty2[] = {MY_ESC,KC_LSFT,KC_TAB,KC_RSFT, COMBO_END};
// const uint16_t PROGMEM ...[] = {..., ..., COMBO_END};
// const uint16_t PROGMEM toggle_gaming_2[] = {FR_Q, KC_R, KC_C, KC_F, KC_T, COMBO_END};
// const uint16_t PROGMEM temp_active_e_aigu[] = {HT_SPC, HT_E, COMBO_END};
// const uint16_t PROGMEM bis_temp_active_RGB[] = {HT_ENT, HT_SPC, COMBO_END};
// const uint16_t PROGMEM bis_x_temp_active_RGB[] = {CSTM_ENT, HT_SPC, COMBO_END};
// const uint16_t PROGMEM temp_active_RGB[] = {HT_ENT, HT_SPC, COMBO_END};
combo_t key_combos[] = {
    [COMBO_ACTIVE_NUMPAD]=COMBO(temp_active_numpad, MO_NUMPAD),
    [COMBO_ACTIVE_NUMPAD2]=COMBO(temp_active_numpad2, MO_NUMPAD),
    [COMBO_MULTIMEDIA]=COMBO(temp_active_MULTIMEDIA, MO(_MULTIMEDIA)),
    // [TOGGLE_GAMING]=COMBO(toggle_gaming, TG(_AUX_GAME)),
    [TOGGLE_GAME]=COMBO(toggle_game, TG_GAME),
    // [TOGGLE_GAME2]=COMBO(toggle_game2, TG_GAME),
    [COMBO_OSM_SHIFT]=COMBO(temp_active_SHIFT, OSM(MOD_LSFT)),
    // [COMBO_OSM_SHIFT2]=COMBO(temp_active_SHIFT2, OSM(MOD_LSFT)),
    [COMBO_CAPSLOCK]=COMBO(combo_capslock, DBL_SHIFT),
    [COMBO_BOOT]=COMBO(temp_active_boot, QK_BOOT),
    [COMBO_BOOT2]=COMBO(temp_active_boot2, QK_BOOT),
    // [FAST_SWITCH_GAME_COLEMAK_COMBO]=COMBO(fast_switch_game_colemak_combo, FAST_SWITCH_GAME_COLEMAK),
    // [FAST_SWITCH_GAME_COLEMAK_COMBO2]=COMBO(fast_switch_game_colemak_combo2, FAST_SWITCH_GAME_COLEMAK),
    // [TOGGLE_WEB]=COMBO(combo_toggle_web, TG(_WEB_BROWSER)),
    [TOGGLE_RGB]=COMBO(toggle_RGB, TG(_RGB)),
    [COMBO_CLEAR_EEPROM]=COMBO(combo_clear_eeprom, QK_CLEAR_EEPROM),
    [COMBO_WEB]=COMBO(combo_web, TG(_WEB_BROWSER)),
    [COMBO_PRINT_SCREEN]=COMBO(combo_print_screen, KC_PSCR),
    [COMBO_REG_QWERTY]=COMBO(combo_reg_qwerty, TG(_REG_QWERTY)),
    [COMBO_REG_QWERTY2]=COMBO(combo_reg_qwerty2, TG(_REG_QWERTY)),
    // [...]=COMBO(combo_my_bquote2, ...),
    // [COMBO_OSL_RGB]=COMBO(temp_active_RGB, OSL(_RGB)),
    // [TOGGLE_GAMING_2]=COMBO(toggle_gaming_2, TG(_GAMING)),
    // COMBO(temp_active_SHIFT, COMBO_SHIFT), 
    // COMBO(temp_active_SHIFT, CUSTOM_OSL_WITH_MOD),
    // [COMBO_E_AIGU]=COMBO(temp_active_e_aigu, E_AIGU),
//     COMBO(bis_temp_active_RGB, OSL(_RGB)),
//     COMBO(bis_x_temp_active_RGB, OSL(_RGB)),
};

bool combo_should_trigger(uint16_t combo_index, combo_t *combo, uint16_t keycode, keyrecord_t *record) {
    /* Disable combo `SOME_COMBO` on layer `_LAYER_A` */
    switch (combo_index) {
        // case SOME_COMBO:
        //   if (layer_state_is(_LAYER_A)) {
        //     return false;
        //   }
        case COMBO_ACTIVE_NUMPAD:
        case COMBO_ACTIVE_NUMPAD2:
        // case FAST_SWITCH_GAME_COLEMAK_COMBO:
        //   if (layer_state_is(_GAME)) {
        //     return false;
        //   }
        case TOGGLE_GAME:
          if (layer_state_is(_GAME)) {
            return true;
          }
        default:
          if (layer_state_is(_GAME)) {
            return false;
          }
    }

    return true;
}

// ------------- END COMBO ---------------

// -----------------------------------


// This globally defines all key overrides to be used
const key_override_t *key_overrides[] = {
    &ko_make_with_layers(MOD_MASK_SHIFT, FR_COMM, FR_COLN, 1 << _COLEMAK_FR), // check if it works
    &ko_make_with_layers(MOD_MASK_SHIFT, FR_DOT,  FR_SCLN, 1 << _COLEMAK_FR),
    &ko_make_with_layers(MOD_MASK_SHIFT, FR_QUES, FR_EXLM, 1 << _COLEMAK_FR),
    &ko_make_with_layers(MOD_MASK_SHIFT, FR_QUOT, FR_DQUO, 1 << _COLEMAK_FR),
    &ko_make_with_layers(MOD_MASK_SHIFT, FR_COMM, FR_COLN, 1 << _CAPS_LOCK), // check if it works
    &ko_make_with_layers(MOD_MASK_SHIFT, FR_DOT,  FR_SCLN, 1 << _CAPS_LOCK),
    &ko_make_with_layers(MOD_MASK_SHIFT, FR_QUES, FR_EXLM, 1 << _CAPS_LOCK),
    &ko_make_with_layers(MOD_MASK_SHIFT, FR_QUOT, FR_DQUO, 1 << _CAPS_LOCK),
    // &ko_make_with_layers(MOD_MASK_SHIFT, FR_COMM, FR_COLN, 1 << _SFT_COLEMAK_FR), // check if it works
    // &ko_make_with_layers(MOD_MASK_SHIFT, FR_DOT,  FR_SCLN, 1 << _SFT_COLEMAK_FR),
    // &ko_make_with_layers(MOD_MASK_SHIFT, FR_QUES, FR_EXLM, 1 << _SFT_COLEMAK_FR),
    // &ko_make_with_layers(MOD_MASK_SHIFT, FR_QUOT, FR_DQUO, 1 << _SFT_COLEMAK_FR),
    // &ko_make_with_layers(MOD_MASK_SHIFT, FR_AT,   FR_AGRV, 1 << 2);
    
    NULL // Null terminate the array of overrides!
};

// -----------------------------------
// -----------------------------------
#include "process_record_user.h"
// -----------------------------------

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // _COLEMAK_FR
    [_COLEMAK_FR] = LAYOUT_split_3x6_4(
  //,-----------------------------------------------------.                      ,-----------------------------------------------------.
       MY_ESC,    FR_Q,    FR_W,    KC_F,    KC_P,    KC_G,                           KC_J,    KC_L,    KC_U,    KC_Y, FR_QUOT,  KC_TAB,
  //|--------+--------+--------+--------+--------+--------|                      |--------+--------+--------+--------+--------+--------|
      MY_LCTL,    FR_A,    KC_R,    KC_S,    KC_T,    KC_D,                           KC_H,    KC_N,    HT_E,    KC_I,    KC_O, MY_RCTL,
  //|--------+--------+--------+--------+--------+--------|                      |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    FR_Q,    KC_X,    KC_C,    KC_V,    KC_B,                           KC_K,    FR_M, FR_COMM,  FR_DOT, FR_QUES, KC_RSFT,
  //|--------------------------------------------------------------|     |-------------------------------------------------------------|
                           FR_Z,          KC_LGUI,  MY_NAV,  HT_SPC,      MOFKEYS, CSTM_ENT,KC_LALT,          KC_LSFT
                     //`-------------------------------------------'     `-------------------------------------------'
  ),
    [_REG_QWERTY] = LAYOUT_split_3x6_4(
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       MY_ESC,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_TAB,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_RCTL,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                        KC_BSPC,          KC_LSFT,  MO_NAV,  KC_SPC,    TL_UPPR,  KC_ENT, KC_RSFT,           KC_DEL
                                      //`--------------------------'  `--------------------------'
  ),
    // OTHER_GAMING for gaming
    [_GAME] = LAYOUT_split_3x6_4(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_ESC,    FR_Q,  MY_W_H,    KC_F,    KC_P,    KC_G,                         KC_J,    KC_L,    KC_U,    KC_Y, FR_QUOT,  KC_TAB,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     APEX_CTL,    FR_A,    KC_R,    KC_S,    KC_T,    KC_D,                         KC_H,    KC_N,    KC_E,    KC_I,    KC_O, KC_LCTL,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_TAB,    FR_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_K,    FR_M, FR_COMM,  FR_DOT, FR_QUES, KC_LSFT,
  //|--------------------------------------------------------------|   |-------------------------------------------------------------|
                        KC_O,          MO_OX_G,    APEX_I,  KC_SPC,       XXXXXXX,  KC_ENT, KC_LALT,          XXXXXXX
                     //`-------------------------------------------'   `-------------------------------------------'
  ),
    // _AUX_GAME for gaming
    [_AUX_GAME] = LAYOUT_split_3x6_4(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_ESC, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL, XXXXXXX, KC_ACL0, KC_ACL1, KC_ACL2, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, XXXXXXX,   KC_F1,   KC_F2,   KC_F3, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------------------------------------------------------------|   |-------------------------------------------------------------|
                        XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX
                     //`-------------------------------------------'   `-------------------------------------------'
  ),
  //   // QWERTY
  //   [_QWERTY] = LAYOUT_split_3x6_4(
  // //,-----------------------------------------------------.                    ,-----------------------------------------------------.
  //      MY_ESC,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,   KC_TAB,
  // //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
  //     KC_LCTL,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_LCTL,
  // //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
  //     KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_LSFT,
  // //|--------------------------------------------------------------|  |--------------------------------------------------------------|
  //                       XXXXXXX,  KC_LGUI,MO(_NAV),  KC_SPC,             KC_LALT,  KC_ENT, XXXXXXX,  XXXXXXX
                        //`-------------------------------------------'   `-------------------------------------------'
  // ),
    [_LATEX] = LAYOUT_split_3x6_4(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       MY_ESC, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------------------------------------------------------------|   |-------------------------------------------------------------|
                        XXXXXXX,          XXXXXXX,  MY_NAV, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX,         XXXXXXX
                     //`-------------------------------------------'   `-------------------------------------------'
  ),
   // _CAPS_LOCK
    [_CAPS_LOCK] = LAYOUT_split_3x6_4(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       MY_ESC, S(FR_Q), S(FR_W), S(KC_F), S(KC_P), S(KC_G),                      S(KC_J), S(KC_L), S(KC_U), S(KC_Y), FR_QUOT,  KC_TAB,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      MY_LCTL, S(FR_A), S(KC_R), S(KC_S), S(KC_T), S(KC_D),                      S(KC_H), S(KC_N), S(KC_E), S(KC_I), S(KC_O), MY_RCTL,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, S(FR_Q), S(KC_X), S(KC_C), S(KC_V), S(KC_B),                      S(KC_K), S(FR_M), FR_COMM,  FR_DOT, FR_QUES, KC_RSFT,
  //|--------------------------------------------------------------|   |-------------------------------------------------------------|
                        S(FR_Z),          KC_LGUI,  MY_NAV,  HT_SPC,    XXXXXXX,CSTM_ENT, KC_LALT,           XXXXXXX
                     //`-------------------------------------------'   `-------------------------------------------'
  ),
    [_F_KEYS] = LAYOUT_split_3x6_4(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       MY_ESC,  KC_F16,   KC_F7,   KC_F8,   KC_F9,  KC_F12,                      XXXXXXX, KC_PGUP,   KC_UP, KC_PGDN, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      MY_LCTL,  KC_F15,   KC_F4,   KC_F5,   KC_F6,  KC_F11,                      KC_BSPC, KC_LEFT, KC_DOWN,KC_RIGHT,  KC_DEL, MY_RCTL,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,  KC_F14,   KC_F1,   KC_F2,   KC_F3,  KC_F10,                      XXXXXXX, KC_HOME, XXXXXXX,  KC_END, XXXXXXX, XXXXXXX,
  //|--------------------------------------------------------------|  |--------------------------------------------------------------|
                         KC_F13,          XXXXXXX, KC_LCTL, XXXXXXX,    XXXXXXX, KC_LCTL, KC_LALT,          XXXXXXX
                     //`-------------------------------------------'   `-------------------------------------------'
  ),
    [_NAV] = LAYOUT_split_3x6_4(
  //,--------------------------------------------------------.                    ,-----------------------------------------------------.
       MY_ESC, IMGLASS_CP,   KC_P7,   KY_P8,   KC_P9, KC_BSPC,                      XXXXXXX, KC_PGUP,   KC_UP, KC_PGDN, XXXXXXX, KC_TAB,
  //|--------+-----------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      MY_LCTL,    MOWEBBR,   KC_P4,   KY_P5,   KC_P6, KC_PDOT,                      KC_BSPC, KC_LEFT, KC_DOWN,KC_RIGHT,  KC_DEL, MY_RCTL,
  //|--------+-  --------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,   MY_ALT_T,   KY_P1,   KY_P2,   KY_P3,  KC_ENT,                      XXXXXXX, KC_HOME, XXXXXXX,  KC_END, XXXXXXX, KC_RSFT,
  //|-----------------------------------------------------------------|   |-------------------------------------------------------------|
                             KC_P0,          _______, _______, _______,    KC_LGUI, KC_LCTL, KC_LALT,           XXXXXXX
                        //`-------------------------------------------'   `-------------------------------------------'
  ),
    [_WEB_BROWSER] = LAYOUT_split_3x6_4(
  //,------------------------------------------------------.                    ,-----------------------------------------------------.
       MY_ESC,  XXXXXXX, TABTO_L, WEB_TAB, TABTO_R, PRIVATE,                      PRIVATE, TABTO_L, WEB_TAB, TABTO_R, XXXXXXX, XXXXXXX,
  //|--------+---------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      MY_LCTL,RCS(KC_O),   WEB_G, FF_T_ST,   WEB_D, FF_FENE,                      FF_FENE,   WEB_G, FF_T_ST,   WEB_D, XXXXXXX, MY_RCTL,
  //|--------+---------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,  XXXXXXX, XXXXXXX, THEBOOK, BOOKMAR, XXXXXXX,                      XXXXXXX, BOOKMAR, THEBOOK, XXXXXXX, XXXXXXX, XXXXXXX,
  //|---------------------------------------------------------------|   |------------------------------------------------------------|
                         XXXXXXX,           KC_LGUI, MY_NAV,  HT_SPC,    KC_LALT, AUX_WEB, XXXXXXX,          XXXXXXX
                      //`-------------------------------------------'   `-------------------------------------------'
  ),
    [_OP_NAV] = LAYOUT_split_3x6_4(
  //,------------------------------------------------------------.                    ,-----------------------------------------------------.
       MY_ESC,     KC_NUM, KC_NUBS,S(KC_NUBS),   XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+-----------+--------+----------+----------+--------|                    |--------+--------+--------+--------+--------+--------|
      MY_LCTL,    XXXXXXX, KC_PMNS,    KC_EQL,   KC_PPLS, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+-  --------+--------+----------+----------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    XXXXXXX, KC_PSLS,   MY_PIPE,   KC_PAST, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|---------------------------------------------------------------|               |-------------------------------------------------------|
                    XXXXXXX,          XXXXXXX, MY_NAV_FROM_OP,HT_SPC,          XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX
                  //`-----------------------------------------------'               `-------------------------------------------'
  ),
    [_MOUSE_LAYER] = LAYOUT_split_3x6_4(
  //,-----------------------------------------------------.                       ,-----------------------------------------------------.
       MY_ESC, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                         KC_BTN3, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                       |--------+--------+--------+--------+--------+--------|
      KC_LCTL, K_BLITZ, KC_BTN1, KC_BTN3, KC_BTN2, XXXXXXX,                         XXXXXXX, ZOOM_TR, XXXXXXX, XXXXXXX, XXXXXXX, KC_RCTL,
  //|--------+--------+--------+--------+--------+--------|                       |--------+--------+--------+--------+--------+--------|
      KC_LSFT, K_SNIPE, KC_BTN1, KC_BTN3, KC_BTN2, XXXXXXX,                         XXXXXXX, XXXXXXX, KC_BTN2, KC_BTN2, XXXXXXX, KC_RSFT,
  //|-----------------------------------------------------|    |----------------------------------------------------------|
                        XXXXXXX,          KC_LGUI, KC_LCTL, MO(_ACCENTS),  KC_BTN1, KC_BTN3, TG_SCROL,         KC_BTN2
                     //`------------------------------------------------'    `-------------------------------------------'
  ),
   // _ACCENTS_COLEMAK_FR
    [_ACCENTS] = LAYOUT_split_3x6_4(
  //,------------------------------------------------------.                    ,-----------------------------------------------------.
       MY_ESC, XXXXXXX,  MY_UNDO, MY_REDO, MY_CUT, MY_PRT_P,                      XXXXXXX, XXXXXXX,    HT_U, XXXXXXX, XXXXXXX,  KC_TAB,
  //|--------+---------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      MY_LCTL,     HT_A, SEL_ALL, MY_SAVE, MY_COPY,MY_PRT_Z,                      KC_BSPC, XXXXXXX, _______,    HT_I,MY_OCIRC, MY_RCTL,
  //|--------+---------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,MY_COMENT, XXXXXXX, C_CEDIL,MY_PASTE,MY_PRT_S,                      XXXXXXX, XXXXXXX, FR_COLN, FR_SCLN, FR_EXLM, KC_RSFT,
  //|---------------------------------------------------------------|   |-------------------------------------------------------------|
                         XXXXXXX,          KC_LGUI,  MY_NAV,  HT_SPC,    KC_LALT,CSTM_ENT, XXXXXXX,           XXXXXXX
                      //`-------------------------------------------'   `-------------------------------------------'
  ),
   // _REG_SPE_FR
    [_REG_SPE] = LAYOUT_split_3x6_4(
  //,-----------------------------------------------------.                    ,---------------------------------------------------------.
       MY_ESC, MY_TILD, FR_LBRC, XXXXXXX, FR_RBRC,MY_DIESE,                      FR_PERC, FR_LCBR,   FR_UNDS, FR_RCBR,   FR_AMPR,  KC_TAB,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+----------+--------+----------+--------|
      MY_LCTL,   FR_AT, KC_PMNS,  KC_EQL, KC_PPLS, MY_DOLL,                      FR_ASTR,MY_BQUOT2,   FR_QUOT, FR_DQUO,S(KC_MINS), MY_RCTL,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+----------+--------+----------+--------|
      _______, XXXXXXX, KC_PSLS, MY_PIPE, KC_PAST, MY_EURO,                   ALGR(KC_9), FR_LPRN,ALGR(KC_8), FR_RPRN,   XXXXXXX, _______,
  //|--------------------------------------------------------------|  |------------------------------------------------------------------|
                        XXXXXXX,          _______, _______, _______,   _______, CSTM_ENT, _______,            XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),
    [_MULTIMEDIA] = LAYOUT_split_3x6_4(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, KC_CALC, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_MSTP, KC_MPRV, KC_VOLD, KC_MNXT, KC_MUTE, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------------------------------------------------------------|  |--------------------------------------------------------------|
                        XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, KC_MPLY, XXXXXXX,           XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),
    [_RGB] = LAYOUT_split_3x6_4(
  //,------------------------------------------------------.                    ,-----------------------------------------------------.
       MY_ESC, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+---------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX,                      RGB_TOG, ____MOD, _I_COUL, __I_LUM, __I_SAT, __I_VIT,
  //|--------+--------+--------+--------+---------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|---------------------------------------------------------------|  |--------------------------------------------------------------|
                        XXXXXXX,           XXXXXXX, XXXXXXX,  XXXXXXX,    XXXXXXX, KC_LSFT, TG(_RGB),        XXXXXXX
                                      //`---------------------------'  `--------------------------'
  )
};

// |--------+--------+--------+--------+--------+--------|
//   RGB_TOG, ____MOD, _I_COUL, __I_LUM, __I_SAT, __I_VIT,
// |--------+--------+--------+--------+--------+--------|

  //   [_SPE] = LAYOUT_split_3x6_3(
  // //,-----------------------------------------------------.                    ,-----------------------------------------------------.
  //      MY_ESC, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
  // //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
  //     KC_LCTL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_MINS,  KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS,  KC_GRV,
  // //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
  //     KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, KC_TILD,
  // //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
  //                                         XXXXXXX, XXXXXXX,  MO_RGB,    XXXXXXX, _______, XXXXXXX
  //                                     //`--------------------------'  `--------------------------'

  // ),

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
    case _GAME :
      // -------|"-----00000-----00000-----00000-----00000-----"
      //         "                                             "
      oled_write(" GAME                                        ", false);
      break;
    case _AUX_GAME :
      // -------|"-----00000-----00000-----00000-----00000-----"
      //         "                                             "
      oled_write(" AUX  GAME                                   ", false);
      break;
    case _LATEX :
      // -------|"-----00000-----00000-----00000-----00000-----"
      //         "                                             "
      oled_write("LATEX                                        ", false);
      break;
    // case _SFT_COLEMAK_FR :
    //   // -------|"-----00000-----00000-----00000-----00000-----"
    //   //         "                                             "
    //   oled_write(" SFT                                         ", false);
    //   break;
    case _CAPS_LOCK :
      // -------|"-----00000-----00000-----00000-----00000-----"
      //         "                                             "
      oled_write(" CAPS_LOCK                                   ", false);
      break;
    // case _OSL_SHIFT :
    //   // -------|"-----00000-----00000-----00000-----00000-----"
    //   //         "                                             "
    //   oled_write(" OSL_SHIFT                                   ", false);
    //   break;
    case _F_KEYS :
      // -------|"-----00000-----00000-----00000-----00000-----"
      //         "                                             "
      oled_write("  F_  KEYS                                   ", false);
      break;
    case _NAV :
      // -------|"-----00000-----00000-----00000-----00000-----"
      //         "                                             "
      oled_write("  NAV                                        ", false);
      break;
    case _WEB_BROWSER :
      // -------|"-----00000-----00000-----00000-----00000-----"
      //         "                                             "
      oled_write(" WEB_                                        ", false);
      break;
    case _OP_NAV :
      // -------|"-----00000-----00000-----00000-----00000-----"
      //         "                                             "
      oled_write("OPERA TEUR                                   ", false);
      break;
    case _MOUSE_LAYER :
      // -------|"-----00000-----00000-----00000-----00000-----"
      //         "                                             "
      oled_write("MOUSELAYER                                   ", false);
      break;
    case _ACCENTS :
      // -------|"-----00000-----00000-----00000-----00000-----"
      //         "                                             "
      oled_write("ACCE-  NTS                                   ", false);
      break;
    case _REG_SPE :
      // -------|"-----00000-----00000-----00000-----00000-----"
      //         "                                             "
      oled_write("  REG _SPE                                   ", false);
      break;
    case _MULTIMEDIA :
      // -------|"-----00000-----00000-----00000-----00000-----"
      //         "                                             "
      oled_write("MULTIMEDIA                                   ", false);
      break;
    case _RGB :
      // -------|"-----00000-----00000-----00000-----00000-----"
      //         "                                             "
      oled_write(" RGB                                         ", false);
      break;
  }
}

// void render_logo(void) {
//   static const char PROGMEM logo[] = {
//     // 'cornia', 32x32px
    // 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 
    // 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xe0, 0x00, 
    // 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0xf8, 0xff, 0xff, 0xff, 0x3f, 0xff, 0xff, 0xff, 0xfd, 0xe1, 
    // 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 
    // 0x00, 0x00, 0xc0, 0xf8, 0xff, 0xff, 0xff, 0x3f, 0x07, 0x00, 0x00, 0x00, 0x07, 0x3f, 0xff, 0xff, 
    // 0xff, 0xf8, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    // 0x00, 0x1e, 0x1f, 0x1f, 0x1f, 0x07, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x07, 
    // 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x0e, 0x00
//   };
//   oled_write_raw_P(logo, sizeof(logo));
// }

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
// MOUSE AUTO-LAYER
void pointing_device_init_user(void) {
    set_auto_mouse_layer(_MOUSE_LAYER); // only required if AUTO_MOUSE_DEFAULT_LAYER is not set to index of <mouse_layer>
    set_auto_mouse_enable(true);         // always required before the auto mouse feature will work
    pointing_device_set_cpi(TRACKPAD_DEFAULT_DPI);
}

// // #include "custom_files/trackpad/scrolling.h"

report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
  // Check if _REG_SPE layer is active (for volume control)
  if (IS_LAYER_ON(_REG_SPE)) {
    // Accumulate vertical movement, scaled by VOLUME_DIVISOR for volume control
    volume_accumulated_v += (float)mouse_report.y / VOLUME_DIVISOR;

    // If accumulated vertical movement reaches the threshold, adjust the volume
    if (volume_accumulated_v >= VOLUME_THRESHOLD) {
        tap_code(KC_VOLD);  // Decrease volume
        volume_accumulated_v = 0;  // Reset accumulator after triggering
    } else if (volume_accumulated_v <= -VOLUME_THRESHOLD) {
        tap_code(KC_VOLU);  // Increase volume
        volume_accumulated_v = 0;  // Reset accumulator after triggering
    }

    // Prevent any cursor movement while controlling volume
    mouse_report.x = 0;
    mouse_report.y = 0;

  } else if (set_scrolling || IS_LAYER_ON(_F_KEYS)) {
    // SCROLLING FUNCTIONALITY
    // Accumulate scroll values based on mouse movement and divisors
    scroll_accumulated_h += (float)mouse_report.x / scroll_divisor_h;
    scroll_accumulated_v += (float)mouse_report.y / scroll_divisor_v;

    // Assign integer parts of accumulated scroll values to the mouse report
    mouse_report.h = (int8_t)scroll_accumulated_h;  // Horizontal scroll
    mouse_report.v = -(int8_t)scroll_accumulated_v; // Vertical scroll (negated for natural scroll)

    // Update accumulated scroll values by subtracting the integer parts
    scroll_accumulated_h -= (int8_t)scroll_accumulated_h;
    scroll_accumulated_v -= (int8_t)scroll_accumulated_v;

    // Prevent cursor movement while scrolling
    mouse_report.x = 0;
    mouse_report.y = 0;
  }
  
//   // else {
//   //   if (abs(mouse_report.x) < 2 && abs(mouse_report.y) < 2) {
//   //   // Ignore small movements
//   //   mouse_report.x = 0;
//   //   mouse_report.y = 0;
//   //   }
//   // }

//   // Return the modified or unmodified mouse report
  return mouse_report;
}
// // ==============================================
// // ==============================================
// ENCODERS :


// bool encoder_update_user(uint8_t index, bool clockwise) {
//     switch (get_highest_layer(layer_state)) {
//         case _MOUSE_LAYER:
//             if (index == 0) {(clockwise ? DPI_DEC : DPI_INC); }
//             else if (index == 1) { tap_code((clockwise ? KC_VOLU : KC_VOLD)); }
//             break;
//         default:
//           if (index == 0) { tap_code((clockwise ? KC_WH_D : KC_WH_U)); }
//           else if (index == 1) { tap_code((clockwise ? KC_VOLU : KC_VOLD)); }
//           break;
//     }
//     return false;
// }

// ==============================================
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
        // Mappings for 1st Encoder          // Mappings for 2nd Encoder
  [_COLEMAK_FR]   = { ENCODER_CCW_CW(KC_WH_U, KC_WH_D),  ENCODER_CCW_CW(KC_VOLD, KC_VOLU)  }, // Mapping for Base layer
  [_REG_QWERTY]   = { ENCODER_CCW_CW(KC_WH_U, KC_WH_D),  ENCODER_CCW_CW(KC_VOLD, KC_VOLU)  }, // Mapping for Base layer
  [_GAME]         = { ENCODER_CCW_CW(KC_WH_U, KC_WH_D),  ENCODER_CCW_CW(KC_VOLD, KC_VOLU)  }, // Mapping for Base layer
  [_AUX_GAME]     = { ENCODER_CCW_CW(KC_WH_U, KC_WH_D),  ENCODER_CCW_CW(KC_VOLD, KC_VOLU)  }, // Mapping for Base layer
  [_LATEX]        = { ENCODER_CCW_CW(KC_WH_U, KC_WH_D),  ENCODER_CCW_CW(KC_VOLD, KC_VOLU)  }, // Mapping for Base layer
  [_CAPS_LOCK]    = { ENCODER_CCW_CW(KC_WH_U, KC_WH_D),  ENCODER_CCW_CW(KC_VOLD, KC_VOLU)  }, // Mapping for Base layer
  [_F_KEYS]       = { ENCODER_CCW_CW(KC_WH_U, KC_WH_D),  ENCODER_CCW_CW(KC_VOLD, KC_VOLU)  }, // Mapping for Base layer
  [_NAV]          = { ENCODER_CCW_CW(KC_WH_U, KC_WH_D),  ENCODER_CCW_CW(KC_VOLD, KC_VOLU)  }, // Mapping for Base layer
  [_WEB_BROWSER]  = { ENCODER_CCW_CW(KC_WH_U, KC_WH_D),  ENCODER_CCW_CW(KC_VOLD, KC_VOLU)  }, // Mapping for Base layer
  [_OP_NAV]       = { ENCODER_CCW_CW(KC_WH_U, KC_WH_D),  ENCODER_CCW_CW(KC_VOLD, KC_VOLU)  }, // Mapping for Base layer
  [_MOUSE_LAYER]  = { ENCODER_CCW_CW(DPI_DEC, DPI_INC),  ENCODER_CCW_CW(KC_VOLD, KC_VOLU)  }, // Mapping for Base layer
  [_ACCENTS]      = { ENCODER_CCW_CW(KC_WH_U, KC_WH_D),  ENCODER_CCW_CW(KC_VOLD, KC_VOLU)  }, // Mapping for Base layer
  [_REG_SPE]      = { ENCODER_CCW_CW(KC_WH_U, KC_WH_D),  ENCODER_CCW_CW(KC_VOLD, KC_VOLU)  }, // Mapping for Base layer
  [_MULTIMEDIA]   = { ENCODER_CCW_CW(KC_WH_U, KC_WH_D),  ENCODER_CCW_CW(KC_VOLD, KC_VOLU)  }, // Mapping for Layer ...
  [_RGB]          = { ENCODER_CCW_CW(KC_WH_U, KC_WH_D),  ENCODER_CCW_CW(KC_VOLD, KC_VOLU)  }, // Mapping for Layer ...
};


// // Define the behavior of the rotary encoders
// // bool encoder_update_user(uint8_t index, bool clockwise) {
// //     if (index == 0) { // First encoder (usually the left half)
// //         if (clockwise) {
// //             tap_code(KC_VOLU); // Increase Volume
// //         } else {
// //             tap_code(KC_VOLD); // Decrease Volume
// //         }
// //     } else if (index == 1) { // Second encoder (usually the right half)
// //         if (clockwise) {
// //             tap_code(KC_MNXT); // Next Track
// //         } else {
// //             tap_code(KC_MPRV); // Previous Track
// //         }
// //     }
// //     return false;
// // }
