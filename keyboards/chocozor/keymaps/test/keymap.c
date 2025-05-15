/* Copyright 2024 Vaarai
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H

#include "./keymap.h"
// #include "./tap_dances.h"

// /* Flag to enable/disable trackpad scroll */
// bool set_scrolling = false;

// /* Variables to store accumulated scroll values */
// float scroll_accumulated_h = 0;
// float scroll_accumulated_v = 0;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_ALPHA] = LAYOUT_split_3x6_4( /* Fire (Oxey) : https://bit.ly/layout-doc-v2 */
  //,-----------------------------------------------------.                      ,-----------------------------------------------------.
       KC_ESC,    FR_Q,    FR_W,    KC_F,    KC_P,    KC_G,                           KC_J,    KC_L,    KC_U,    KC_Y, FR_QUOT,  KC_TAB,
  //|--------+--------+--------+--------+--------+--------|                      |--------+--------+--------+--------+--------+--------|
      KC_LCTL,    FR_A,    KC_R,    KC_S,    KC_T,    KC_D,                           KC_H,    KC_N,    HT_E,    KC_I,    KC_O, KC_RCTL,
  //|--------+--------+--------+--------+--------+--------|                      |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    FR_Q,    KC_X,    KC_C,    KC_V,    KC_B,                           KC_K,    FR_M, FR_COMM,  FR_DOT, FR_QUES, KC_RSFT,
  //|--------------------------------------------------------------|     |-------------------------------------------------------------|
                           FR_Z,          KC_LGUI,  XXXXXXX,  KC_SPC,      XXXXXXX, KC_ENT,KC_LALT,          KC_LSFT
                     //`-------------------------------------------'     `-------------------------------------------'
  ),
};

bool shutdown_user(bool jump_to_bootloader) {
    oled_clear();
    oled_set_cursor(0, 2);
    if (jump_to_bootloader) {
        oled_write_P(PSTR("FLASH"), false);
    } else {
        oled_write_P(PSTR("RESET"), false);
    }
    oled_render_dirty(true);
    return false;
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_270;
}
