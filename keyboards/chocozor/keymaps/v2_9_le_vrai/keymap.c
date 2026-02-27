#include QMK_KEYBOARD_H
#include "accents.h"
#include "drivers/haptic/solenoid.h"
#include "enum.h"
#include "gaming.h"
#include "globals.h"
#include "keymap_french.h"
#include "numpad.h"
#include "oled.h"
#include "pointing_device.h"
#include "timer.h"
#include "web.h"
#include <stdlib.h> // abs()

#include "custom_files/tap_dances/tap_dance.h"

// ------------- COMBO ---------------

const uint16_t PROGMEM toggle_numpad_right[] = {MOFKEYS, KC_LALT, COMBO_END};
const uint16_t PROGMEM toggle_numpad_right2[] = {MO(_OPERATIONS), KC_LALT,
                                                 COMBO_END};
const uint16_t PROGMEM temp_active_MULTIMEDIA[] = {KC_LGUI, MY_NAV, HT_SPC,
                                                   COMBO_END};
const uint16_t PROGMEM temp_active_SHIFT[] = {CSTM_ENT, HT_SPC, COMBO_END};
const uint16_t PROGMEM combo_capslock[] = {KC_LSFT, KC_RSFT, COMBO_END};
const uint16_t PROGMEM temp_active_boot[] = {MY_NAV,  HT_SPC,   KC_LGUI,
                                             KC_LALT, CSTM_ENT, COMBO_END};
const uint16_t PROGMEM temp_active_boot2[] = {
    KC_LGUI, MY_NAV, HT_SPC, MOFKEYS, CSTM_ENT, KC_LALT, COMBO_END};
const uint16_t PROGMEM toggle_game[] = {FR_A, KC_R, KC_S,
                                        KC_T, KC_D, COMBO_END};
const uint16_t PROGMEM combo_clear_eeprom[] = {RGB_TOG, _I__MOD, _I_COUL,
                                               __I_LUM, __I_SAT, COMBO_END};
const uint16_t PROGMEM combo_web[] = {MY_LCTL, MY_RCTL, COMBO_END};
const uint16_t PROGMEM combo_print_screen[] = {KC_R, KC_S, KC_T, COMBO_END};

combo_t key_combos[] = {
    [COMBO_NUMPAD_RIGHT] = COMBO(toggle_numpad_right, TG(_NUMPAD_RIGHT)),
    [COMBO_NUMPAD_RIGHT2] = COMBO(toggle_numpad_right2, TG(_NUMPAD_RIGHT)),
    [COMBO_MULTIMEDIA] = COMBO(temp_active_MULTIMEDIA, MO(_MULTIMEDIA)),
    [TOGGLE_GAME] = COMBO(toggle_game, TG_GAME),
    [COMBO_OSM_SHIFT] = COMBO(temp_active_SHIFT, OSM(MOD_LSFT)),
    [COMBO_CAPSLOCK] = COMBO(combo_capslock, DBL_SHIFT),
    [COMBO_BOOT] = COMBO(temp_active_boot, QK_BOOT),
    [COMBO_BOOT2] = COMBO(temp_active_boot2, QK_BOOT),
    [COMBO_CLEAR_EEPROM] = COMBO(combo_clear_eeprom, QK_CLEAR_EEPROM),
    [COMBO_WEB] = COMBO(combo_web, TG(_WEB_BROWSER)),
    [COMBO_PRINT_SCREEN] = COMBO(combo_print_screen, KC_PSCR),

};

bool combo_should_trigger(uint16_t combo_index, combo_t *combo,
                          uint16_t keycode, keyrecord_t *record) {
  if (combo_index == TOGGLE_GAME) {
    return true;
  }
  if (layer_state_is(_GAME)) {
    return false;
  }
  return true;
}

// ------------- END COMBO ---------------

// -----------------------------------
// This globally defines all key overrides to be used
const key_override_t *key_overrides[] = {
    &ko_make_with_layers(MOD_MASK_SHIFT, FR_COMM, FR_COLN,
                         1 << _COLEMAK_FR), // check if it works
    &ko_make_with_layers(MOD_MASK_SHIFT, FR_DOT, FR_SCLN, 1 << _COLEMAK_FR),
    &ko_make_with_layers(MOD_MASK_SHIFT, FR_QUES, FR_EXLM, 1 << _COLEMAK_FR),
    &ko_make_with_layers(MOD_MASK_SHIFT, FR_QUOT, FR_DQUO, 1 << _COLEMAK_FR),
    &ko_make_with_layers(MOD_MASK_SHIFT, FR_COMM, FR_COLN,
                         1 << _CAPS_LOCK), // check if it works
    &ko_make_with_layers(MOD_MASK_SHIFT, FR_DOT, FR_SCLN, 1 << _CAPS_LOCK),
    &ko_make_with_layers(MOD_MASK_SHIFT, FR_QUES, FR_EXLM, 1 << _CAPS_LOCK),
    &ko_make_with_layers(MOD_MASK_SHIFT, FR_QUOT, FR_DQUO, 1 << _CAPS_LOCK),
    NULL // Null terminate the array of overrides!
};

static bool solenoid_enabled = false; // Solenoid off at start

static void solenoid_helper(void) {
  if (!solenoid_enabled) {
    return;
  }
  static uint16_t last_fire = 0;
  if (timer_elapsed(last_fire) > 80) {
    solenoid_fire(0);
    last_fire = timer_read();
  }
}

// some variables
float aux_dpi = 0;
#define SCROLL_DIVISOR_H_BASE 50.0   // Horizontal scroll speed
#define SCROLL_DIVISOR_V_BASE 30.0   // Vertical scroll speed
bool accel_off = false;

float scroll_divisor_h = SCROLL_DIVISOR_H_BASE;
float scroll_divisor_v = SCROLL_DIVISOR_V_BASE;

// Variables to store accumulated scroll values
float scroll_accumulated_h = 0;
float scroll_accumulated_v = 0;
// -------
// VOLUME CONTROL WITH TRACKPAD
// Define how sensitive the trackpad is for volume control
#define VOLUME_DIVISOR 18  // Adjust for volume control sensitivity (higher = more movement required)
#define VOLUME_THRESHOLD 1  // Threshold for triggering volume change

// Variables to store accumulated volume movement
float volume_accumulated_v = 0;

bool set_scrolling = false;


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (keycode == SOL_TOG) {
    if (record->event.pressed) {
      solenoid_enabled = !solenoid_enabled;
    }
    return false; // ne rien envoyer au PC
  }

  if (record->event.pressed) {
    solenoid_helper();
  }

#define X(x) case x:
#define Y(x) X(x)
#define Z(x) X(x)
  switch (keycode) {
    _ACCENTS_RANGE
    return (process_accents(keycode, record));
    _WEB_RANGE
    return (process_web(keycode, record));
    _NUMPAD_RANGE
    return (process_numpad(keycode, record));
    _GAMING_RANGE
    return (process_gaming(keycode, record));
  case CSTM_ENT:
    if (record->tap.count) { // Tap
      if (record->event.pressed) {
        // your logic when pressed
        if (IS_LAYER_ON(_ACCENTS)) {
          SEND_STRING(SS_LSFT(SS_TAP(X_ENT)));
        } else {
          tap_code(KC_ENT);
        }
      }
    } else {                       // Hold
      if (record->event.pressed) { // pressed
                                   // if (!record->tap.interrupted) {
        if (IS_LAYER_ON(_ACCENTS)) {
          // layer_on(_RGB);
        } else {
          layer_on(_REG_SPE);
        }
      } else { // released
        layer_off(_REG_SPE);
        // layer_off(_RGB);
      }
      return false;
    }
    return false;

  case MY_ALT_T:
    if (record->event.pressed) {
      alt_tab_menu = true;
      SEND_STRING(SS_DOWN(X_LALT));
      tap_code(KC_TAB);
    } else {
      SEND_STRING(SS_UP(X_LALT));
      alt_tab_menu = false;
    }
    return false;

  case MY_ESC:
    if (record->tap.count) { // Tap
      if (record->event.pressed) {
        // logic when pressed
        tap_code(KC_ESC);
        // soft_reset_keyboard();
        // eeconfig_init();
      } else {
        // logic when released
      }
    } else { // Hold
      if (record->event.pressed) {
        if (IS_LAYER_ON(_GAME)) {
        } else { // si la layer gaming n'est pas active
          clear_mods();
          layer_clear();
          nav_already_activated = false;
          capslock_was_activated = false;
          alt_tab_menu = false;
          ky_webnav = false;
          caps_lock_activated = false;
          shift_activated = false;
          trace_operations = false;
          nav_verrouillee = false;
          combo_nav_activated = false;
          web_aux = false;
          // spc_is_held = false;
          layer_move(_COLEMAK_FR);
          if (record->tap.interrupted) {
            // logic when interrupted
          } else {
            // logic when not interrupted
          }
        }
      } else {
        // logic when released
      }
    }
    return false;

  case DBL_SHIFT:
    if (record->event.pressed) {
      if (layer_state_is(_CAPS_LOCK)) {
        // if already set, then switch it off
        layer_off(_CAPS_LOCK);
        caps_lock_activated = false;
      } else {
        // if not already set, then switch the layer on
        layer_on(_CAPS_LOCK);
        caps_lock_activated = true;
      }
    }
    return false;

  case MY_COMENT:
    if (record->event.pressed) {
      add_mods(MOD_BIT_RCTRL);
      tap_code(KC_DOT);
      unregister_mods(MOD_BIT_RCTRL);
      // here we override its «press» behavior (hence, return false)
      return false;
    } else {
      // here we don't alter its «release» default behavior (hence, return true)
      return true;
    }

  case TG_SCROL:
    if (record->event.pressed) {
      // logic when pressed
      set_scrolling = !set_scrolling;
    }
    return false;

  case K_SCROL:
    if (record->event.pressed) {
      set_scrolling = true;
    } else {
      set_scrolling = false;
    }
    return false;

case K_BLITZ: /* Decrease trackpad DPI*/
    if (set_scrolling || IS_LAYER_ON(_F_KEYS)) {
      if (record->event.pressed) {
        aux_dpi = pointing_device_get_cpi();
        pointing_device_set_cpi(1000);
        scroll_divisor_h = SCROLL_DIVISOR_H_BASE / 2.0;
        scroll_divisor_v = SCROLL_DIVISOR_V_BASE / 2.0;
      } else {
        pointing_device_set_cpi(aux_dpi);
        scroll_divisor_h = SCROLL_DIVISOR_H_BASE;
        scroll_divisor_v = SCROLL_DIVISOR_V_BASE;
      }
    } else if (record->event.pressed) {
      pointing_device_set_cpi(pointing_device_get_cpi()+300);
    } else {
      pointing_device_set_cpi(pointing_device_get_cpi()-300);
    }
  return false;

case ZOOM_TR:
  if (record->event.pressed) {
      // logic when pressed
      set_scrolling = true;
      SEND_STRING(SS_DOWN(X_LCTL));
      // SEND_STRING(SS_DOWN(X_LSFT));
      // SEND_STRING(SS_DELAY(1));
      // SEND_STRING(SS_TAP(X_T));
    } else {
      set_scrolling = false;
      SEND_STRING(SS_UP(X_LCTL));
      // SEND_STRING(SS_UP(X_LSFT));
      // logic when released
    }
    // press(MY_LCTL AND MY_LSFT)
    return false;

case DPI_INC: /* Increase trackpad DPI*/
  if (record->event.pressed) {
    pointing_device_set_cpi(pointing_device_get_cpi()+100);
  }
  return false;
case DPI_DEC: /* Decrease trackpad DPI*/
  if (record->event.pressed) {
    pointing_device_set_cpi(pointing_device_get_cpi()-100);
  }
  return false;

case ACEL_OFF:
  if (record->event.pressed) {
    accel_off = true;
    // SEND_STRING(SS_DOWN(X_LCTL));
    // tap_code(KC_TAB);
  } else {
    // SEND_STRING(SS_UP(X_LCTL));
    // ky_webnav = false;
  }
  return false;
  }

#undef X
#undef Y
#undef Z

  return (true);
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  case MY_ESC:
    return 200;
  case HT_SPC:
    return 210;
  case MY_NAV:
    return 180;
  case HT_A:
    return 200;
  case HT_E:
    return 160;
  case WEB_TAB:
    return 230;
  case FF_T_ST:
    return 230;
  case APEX_I:
    return 80;
  case APEX_CTL:
    return 80;
  default:
    return g_tapping_term;
  }
}

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  case HT_E:
  case HT_I:
  case HT_U:
  case HT_A:
    return false;
    // Do not force the mod-tap key press to be handled as a modifier
    // if any other key was pressed while the mod-tap key is held down.
  default:
    // Force the dual-role key press to be handled as a modifier if any
    // other key was pressed while the mod-tap key is held down.
    return true;
  }
}

uint16_t get_combo_term(uint16_t index, combo_t *combo) {
  // // decide by combo->keycode
  // switch (combo->keycode) {
  //     case KC_X:
  //         return 50;
  // }

  // or with combo index, i.e. its name from enum.
  switch (index) {
  case COMBO_OSM_SHIFT:
    return 50;
  case COMBO_ACTIVE_NUMPAD:
  case COMBO_ACTIVE_NUMPAD2:
  case COMBO_NUMPAD_RIGHT:
  case COMBO_NUMPAD_RIGHT2:
    return 25;
  default:
    return COMBO_TERM;
  }

  // // And if you're feeling adventurous, you can even decide by the keys in
  // the chord,
  // // i.e. the exact array of keys you defined for the combo.
  // // This can be useful if your combos have a common key and you want to
  // apply the
  // // same combo term for all of them.
  // if (combo->keys[0] == KC_ENT) { // if first key in the array is Enter
  //     return 150;
  // }
}

// When the user holds a key after tapping it, the tapping function is repeated
// by default, rather than activating the hold function. This allows keeping the
// ability to auto-repeat the tapping function of a dual-role key.
// QUICK_TAP_TERM enables fine tuning of that ability. If set to 0, it will
// remove the auto-repeat ability and activate the hold function instead.

// QUICK_TAP_TERM is set to TAPPING_TERM by default, which is the maximum
// allowed value for QUICK_TAP_TERM. To override its value (in milliseconds) add
// the following to your config.h: #define QUICK_TAP_TERM 120

uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  case SFT_T(KC_SPC):
    return 10;
    // return QUICK_TAP_TERM - 20;
  default:
    return QUICK_TAP_TERM;
  }
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_COLEMAK_FR] = LAYOUT_2_9_regular(
      KC_P1,   KC_P2,   KC_P3,   KC_P4,   KC_P5,   KC_P6,                                              KC_P7,   KC_P8,   KC_P9,   KC_P0,   KC_P1, SOL_TOG,
     MY_ESC,    FR_Q,    FR_W,    KC_F,    KC_P,    KC_G,                                               KC_J,    KC_L,    KC_U,    KC_Y, FR_QUOT,  KC_TAB,
//|--------+--------+--------+--------+--------+--------|                                            |------+--------+--------+--------+--------+--------|
    MY_LCTL,    FR_A,    KC_R,    KC_S,    KC_T,    KC_D,                                               KC_H,    KC_N,    HT_E,    KC_I,    KC_O, MY_RCTL,
//|--------+--------+--------+--------+--------+--------|                                            |------+--------+--------+--------+--------+--------|
    KC_LSFT,    FR_Q,    KC_X,    KC_C,    KC_V,    KC_B,                                               KC_K,    FR_M, FR_COMM,  FR_DOT, FR_QUES, KC_RSFT,
//|-----------------------------------------------------------------------|       |----------------------------------------------------------------------|
                         FR_Z,    KC_1,    KC_2,                                                                 KC_1,    KC_2,    KC_3,
                                                 KC_LGUI,  MY_NAV,  HT_SPC,        MOFKEYS, CSTM_ENT, KC_LALT
),
[_GAME] = LAYOUT_2_9_regular(
      KC_P1,   KC_P2,   KC_P3,   KC_P4,   KC_P5,   KC_P6,                        KC_P7,   KC_P8,   KC_P9,   KC_P0,   KC_P1,   KC_P2,
     KC_ESC,    FR_Q,    FR_W,    KC_F,    KC_P,    KC_G,                         KC_J,    KC_L,    KC_U,    KC_Y, FR_QUOT,  KC_TAB,
//|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    KC_LCTL,    FR_A,    KC_R,    KC_S,    KC_T,    KC_D,                         KC_H,    KC_N,    KC_E,    KC_I,    KC_O, KC_LCTL,
//|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    KC_LSFT,    FR_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_K,    FR_M, FR_COMM,  FR_DOT, FR_QUES, KC_LSFT,
//|---------------------------------------------------------------------|   |-------------------------------------------------------------|
                         KC_O, XXXXXXX, XXXXXXX,                                        XXXXXXX, XXXXXXX, XXXXXXX,
                                                 MO_OX_G,  KC_I,  KC_SPC,      XXXXXXX,  KC_ENT, KC_LALT
//`-------------------------------------------'   `-------------------------------------------'
// keycodes utilisables : APEX_CTL, APEX_I, KC_LCTL, KC_I
),
[_AUX_GAME] = LAYOUT_2_9_regular(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    KC_P, XXXXXXX,                                                XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
//|-----------------------------------------------------.                                                ----------------------------------------------------.
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                                XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
//|--------+--------+--------+--------+--------+--------|                                                -------+--------+--------+--------+--------+--------|
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                                XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
//|--------+--------+--------+--------+--------+--------|                                                -------+--------+--------+--------+--------+--------|
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                                XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
//|-----------------------------------------------------------------------|            |---------------------------------------------------------------------|
                      XXXXXXX, XXXXXXX, XXXXXXX,                                                                  XXXXXXX, XXXXXXX, XXXXXXX,
                                                 XXXXXXX, XXXXXXX, XXXXXXX,            XXXXXXX, XXXXXXX, XXXXXXX
//|-----------------------------------------------------------------------|            |---------------------------------------------------------------------|
),
[_CAPS_LOCK] = LAYOUT_2_9_regular(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,XXXXXXX,  XXXXXXX,                                             XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
//|-----------------------------------------------------.                                            |----------------------------------------------------.
     MY_ESC, S(FR_Q), S(FR_W), S(KC_F), S(KC_P), S(KC_G),                                             S(KC_J), S(KC_L), S(KC_U), S(KC_Y), FR_QUOT,  KC_TAB,
//|--------+--------+--------+--------+--------+--------|                                            |------+--------+--------+--------+--------+---------|
    MY_LCTL, S(FR_A), S(KC_R), S(KC_S), S(KC_T), S(KC_D),                                             S(KC_H), S(KC_N), S(KC_E), S(KC_I), S(KC_O), MY_RCTL,
//|--------+--------+--------+--------+--------+--------|                                            |------+--------+--------+--------+--------+---------|
    KC_LSFT, S(FR_Q), S(KC_X), S(KC_C), S(KC_V), S(KC_B),                                             S(KC_K), S(FR_M), FR_COMM,  FR_DOT, FR_QUES, KC_RSFT,
//|-----------------------------------------------------------------------|       |-----------------------------------------------------------------------|
                      S(FR_Z), XXXXXXX, XXXXXXX,                                                               XXXXXXX, XXXXXXX, XXXXXXX,
                                                 KC_LGUI,  MY_NAV,  HT_SPC,        XXXXXXX,  CSTM_ENT, KC_LALT
),
[_F_KEYS] = LAYOUT_2_9_regular(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,XXXXXXX,  XXXXXXX,                                             XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
//|-----------------------------------------------------.                                            |----------------------------------------------------.
     MY_ESC,  KC_F16,   KC_F7,   KC_F8,   KC_F9,  KC_F12,                                             XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
//|--------+--------+--------+--------+--------+--------|                                             |------+--------+--------+--------+--------+--------|
    MY_LCTL,  KC_F15,   KC_F4,   KC_F5,   KC_F6,  KC_F11,                                             XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
//|--------+--------+--------+--------+--------+--------|                                             |------+--------+--------+--------+--------+--------|
    KC_LSFT,  KC_F14,   KC_F1,   KC_F2,   KC_F3,  KC_F10,                                             XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
//|-----------------------------------------------------------------------|        |----------------------------------------------------------------------|
                         KC_F13, XXXXXXX, XXXXXXX,                                                               XXXXXXX, XXXXXXX, XXXXXXX,
                                                 XXXXXXX, KC_LCTL, XXXXXXX,         XXXXXXX, KC_LCTL, KC_LALT
),
[_NUMPAD_RIGHT] = LAYOUT_2_9_regular(
    XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                             XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
//|--------------------------------------------------------.                                             |---------------------------------------------------.
     MY_ESC, IMGLASS_CP,   KC_P7,   KY_P8,   KC_P9, KC_BSPC,                                             XXXXXXX,   KC_P7,   KC_P8,   KC_P9, XXXXXXX,  KC_TAB,
//|--------+-----------+--------+--------+--------+--------|                                             |--------+------+--------+--------+--------+--------|
    MY_LCTL,   MO_WEBBR,   KC_P4,   KY_P5,   KC_P6, KC_PDOT,                                             KC_PDOT,   KC_P4,   KC_P5,   KC_P6, XXXXXXX, MY_RCTL,
//|--------+-  --------+--------+--------+--------+--------|                                             |--------+------+--------+--------+--------+--------|
    KC_LSFT,   MY_ALT_T,   KY_P1,   KY_P2,   KY_P3,  KC_ENT,                                              KC_ENT,   KC_P1,   KC_P2,   KC_P3,  KC_ENT, KC_RSFT,
//|--------------------------------------------------------------------------|           |-------------------------------------------------------------------|
                           KC_P0, XXXXXXX, XXXXXXX,                                                               XXXXXXX, XXXXXXX, XXXXXXX,
                                                    _______, _______, _______,           MO_OP, MO(_NAV), KC_LALT
//|--------------------------------------------------------------------------|           |-------------------------------------------------------------------|
 ),
[_NAV] = LAYOUT_2_9_regular(
    XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
//|--------------------------------------------------------.                                       |---------------------------------------------------.
     MY_ESC,IMGLASS_CP,   KC_P7,   KY_P8,   KC_P9, KC_BSPC,                                        XXXXXXX, KC_PGUP,   KC_UP, KC_PGDN, XXXXXXX,  KC_TAB,
//|--------+----------+--------+--------+--------+--------|                                        |------+--------+--------+--------+--------+--------|
    MY_LCTL,  MO_WEBBR,   KC_P4,   KY_P5,   KC_P6, KC_PDOT,                                        KC_BSPC, KC_LEFT, KC_DOWN,KC_RIGHT,  KC_DEL, MY_RCTL,
//|--------+  --------+--------+--------+--------+--------|                                        |------+--------+--------+--------+--------+--------|
    KC_LSFT,  MY_ALT_T,   KY_P1,   KY_P2,   KY_P3,  KC_ENT,                                        XXXXXXX, KC_HOME, XXXXXXX,  KC_END, XXXXXXX, KC_RSFT,
//|------------------------------------------------------------------------ |    |-------|-------------------------------------------------------------|
                           KC_P0, XXXXXXX, XXXXXXX,                                                         XXXXXXX, XXXXXXX, XXXXXXX,
                                                   _______, _______, _______,     XXXXXXX, KC_LCTL, KC_LALT
//|-------------------------------------------------------------------------|    |---------------------------------------------------------------------|
),
[_OPERATIONS] = LAYOUT_2_9_regular(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                              XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
//|-----------------------------------------------------.                                              |---------------------------------------------------.
     MY_ESC, TG_NUMP, ____INF, ____SUP, XXXXXXX, XXXXXXX,                                              XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
//|--------+--------+--------+--------+--------+--------|                                              |---------------------------------------------------.
    MY_LCTL, XXXXXXX, __MOINS, __EQUAL, ___PLUS, XXXXXXX,                                              XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
//|--------+--------+--------+ -------+--------+--------|                                              |------+--------+--------+--------+--------+--------|
    KC_LSFT, XXXXXXX, _DIVISE, MY_PIPE, ___FOIS, XXXXXXX,                                              XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
//|-----------------------------------------------------------------------|          |---------------------------------------------------------------------|
                      XXXXXXX, XXXXXXX, XXXXXXX,                                                                XXXXXXX, XXXXXXX, XXXXXXX,
                                                 XXXXXXX, NAV_F_OP, HT_SPC,           XXXXXXX, XXXXXXX, XXXXXXX
  //|---------------------------------------------------------------------|          |---------------------------------------------------------------------|
),
[_WEB_BROWSER] = LAYOUT_2_9_regular(
    XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,                                           XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
//|-----------------------------------------------------.                                          |-----------------------------------------------------.
     MY_ESC,  XXXXXXX, TABTO_L, WEB_TAB, TABTO_R, PRIVATE,                                           PRIVATE, TABTO_L, WEB_TAB, TABTO_R, XXXXXXX, XXXXXXX,
//|--------+---------+--------+--------+--------+--------|                                         |--------+--------+--------+--------+--------+--------|
    MY_LCTL, OPENBOOK,   WEB_G, FF_T_ST,   WEB_D, FF_FENE,                                           FF_FENE,   WEB_G, FF_T_ST,   WEB_D, XXXXXXX, MY_RCTL,
//|--------+---------+--------+--------+--------+--------|                                         |--------+--------+--------+--------+--------+--------|
    KC_LSFT,  XXXXXXX, WEB_DUP, THEBOOK, BOOKMAR, XXXXXXX,                                           XXXXXXX, BOOKMAR, THEBOOK, XXXXXXX, XXXXXXX, XXXXXXX,
//|-----------------------------------------------------------------------|                        |-----------------------------------------------------|
                       XXXXXXX, XXXXXXX, XXXXXXX,                                                             XXXXXXX, XXXXXXX, XXXXXXX,
                                                  KC_LGUI, MY_NAV,  HT_SPC,         KC_LALT, AUX_WEB, XXXXXXX
  //|---------------------------------------------------------------------|        |----------------------------------------------------------------------|
),
[_MOUSE_LAYER] = LAYOUT_2_9_regular(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                             XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
//|-----------------------------------------------------.                                           |-----------------------------------------------------.
     MY_ESC, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,ACEL_OFF,                                             KC_BTN3, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
//|--------+--------+--------+--------+--------+--------|                                           |--------+--------+--------+--------+--------+--------|
    KC_LCTL, K_BLITZ, KC_BTN1, KC_BTN3, KC_BTN2,XXXXXXX,                                              XXXXXXX, ZOOM_TR, XXXXXXX, XXXXXXX, XXXXXXX, KC_RCTL,
//|--------+--------+--------+--------+--------+--------|                                           |--------+--------+--------+--------+--------+--------|
    KC_LSFT, K_SNIPE, KC_BTN1, KC_BTN3, KC_BTN2, XXXXXXX,                                             XXXXXXX, XXXXXXX, KC_BTN2, KC_BTN2, XXXXXXX, KC_RSFT,
//|-----------------------------------------------------------------------|        |----------------------------------------------------------------------|
                      XXXXXXX, XXXXXXX, XXXXXXX,                                                               XXXXXXX, XXXXXXX, KC_BTN2,
                                                 KC_LSFT, KC_LCTL, MO(_ACCENTS),     KC_BTN1, KC_BTN3, TG_SCROL
//|-----------------------------------------------------------------------|        |----------------------------------------------------------------------|
),
[_ACCENTS] = LAYOUT_2_9_regular(
    XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,                                           XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
//|-----------------------------------------------------.                                          |-----------------------------------------------------.
     MY_ESC, XXXXXXX,  MY_UNDO, MY_REDO, MY_CUT, MY_PRT_P,                                           XXXXXXX, XXXXXXX,    HT_U, XXXXXXX, XXXXXXX,  KC_TAB,
//|--------+---------+--------+--------+--------+--------|                                         |--------+--------+--------+--------+--------+--------|
    MY_LCTL,     HT_A, SEL_ALL, MY_SAVE, MY_COPY,MY_PRT_Z,                                           KC_BSPC, XXXXXXX, _______,    HT_I,MY_OCIRC, MY_RCTL,
//|--------+---------+--------+--------+--------+--------|                                         |--------+--------+--------+--------+--------+--------|
    KC_LSFT,MY_COMENT, XXXXXXX,MY_CEDIL,MY_PASTE,MY_PRT_S,                                           XXXXXXX, XXXXXXX, FR_COLN, FR_SCLN, FR_EXLM, KC_RSFT,
  //|---------------------------------------------------------------------|        |----------------------------------------------------------------------|
                       XXXXXXX, XXXXXXX, XXXXXXX,                                                             XXXXXXX, XXXXXXX, XXXXXXX,
                                                  KC_LGUI, MY_NAV,  HT_SPC,         KC_LALT,CSTM_ENT,XXXXXXX
  //|---------------------------------------------------------------------|        |-----------------------------------------------------------------------|
),
[_REG_SPE] = LAYOUT_2_9_regular(
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                            XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,    XXXXXXX, XXXXXXX,
//|------------------------------------------------------.                                           |--------------------------------------------------------.
      MY_ESC, MY_TILD, FR_LBRC, XXXXXXX, FR_RBRC,MY_DIESE,                                             FR_PERC, FR_LCBR, FR_UNDS, FR_RCBR,    FR_AMPR,  KC_TAB,
//|---------+--------+--------+--------+--------+--------|                                           |--------+--------+--------+--------+-----------+--------|
     MY_LCTL,   FR_AT, KC_PMNS,  KC_EQL, KC_PPLS, MY_DOLL,                                             FR_ASTR,MY_BQUOT, FR_QUOT, FR_DQUO,S(KC_MINS),MY_RCTL,
//|---------+--------+--------+--------+--------+--------|                                           |--------+--------+--------+--------+-----------+--------|
     _______, XXXXXXX, KC_PSLS, MY_PIPE, KC_PAST, MY_EURO,                                             ___CIRC,  FR_LPRN, _BACKSL, FR_RPRN,   XXXXXXX, _______,
//| -----------------------------------------------------------------------|       |--------------------------------------------------------------------------|
                       XXXXXXX, XXXXXXX, XXXXXXX,                                                      XXXXXXX,  XXXXXXX, XXXXXXX,
                                                  _______, _______, _______,        _______, CSTM_ENT, _______
  //|-----------------------------------------------------------------------|      |-----------------------------------------------------------------------|
),
[_MULTIMEDIA] = LAYOUT_2_9_regular(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                             XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
//|-----------------------------------------------------.                                           |-----------------------------------------------------.
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                             XXXXXXX, XXXXXXX, KC_CALC, XXXXXXX, XXXXXXX, XXXXXXX,
//|--------+--------+--------+--------+--------+--------|                                           |--------+--------+--------+--------+--------+--------|
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                             KC_MSTP, KC_MPRV, KC_VOLD, KC_MNXT, KC_MUTE, XXXXXXX,
//|--------+--------+--------+--------+--------+--------|                                           |--------+--------+--------+--------+--------+--------|
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                             XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
//|-----------------------------------------------------------------------|        |----------------------------------------------------------------------|
                      XXXXXXX, XXXXXXX, XXXXXXX,                                                               XXXXXXX, XXXXXXX, XXXXXXX,
                                                 XXXXXXX, XXXXXXX, XXXXXXX,         XXXXXXX, KC_MPLY, XXXXXXX
//|-----------------------------------------------------------------------|        |----------------------------------------------------------------------|
),
[_RGB] = LAYOUT_2_9_regular(
    FR_A, KC_B, KC_C, KC_D, KC_E, KC_F,                                                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
//|-----+-----+-----+-----+-----+-----|                                                     |-------+--------+--------+--------+--------+--------|
    KC_G, KC_H, KC_I, KC_J, KC_K, KC_L,                                                      RGB_TOG, _I__MOD, _I_COUL, __I_LUM, __I_SAT, __I_VIT,
//|-----+-----+-----+-----+-----+-----|                                                     |-------+--------+--------+--------+--------+--------|
    KC_M, KC_N, KC_O, KC_P, FR_Q, KC_R,                                                      XXXXXXX, _D_RMOD, _D_COUL, __D_LUM, __D_SAT, __D_VIT,
//|-----+-----+-----+-----+-----+-----|                                                     |----------------------------------------------------|
    KC_U, KC_V, FR_W, KC_X, KC_Y, FR_Z,                                                        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
//|-----------------------------------------------------|                  |---------------------------------------------------------------------|
               KC_NO,KC_NO,KC_NO,                                                                     XXXXXXX, XXXXXXX, XXXXXXX,
                               XXXXXXX,TG(_RGB), XXXXXXX,                  XXXXXXX, XXXXXXX, XXXXXXX
//|-----------------------------------------------------|                  |-----------------------------------------------------------------------|
)
};


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
  } else if (!accel_off) {
    //     // Calculate magnitude of movement vector
    // float dx = (float)mouse_report.x;
    // float dy = (float)mouse_report.y;

    // float magnitude = sqrtf(dx * dx + dy * dy);

    // // // Don't apply acceleration if there's no movement
    // // if (magnitude == 0) {
    // //     return mouse_report;
    // // }
    
    // // // Don't apply acceleration if there's not enough movement
    // if (magnitude < 2.0f) {
    //     return mouse_report;
    // }

    // // Set acceleration factor based on movement speed
    // float accel_factor = 1.0f + 0.05f * magnitude;

    // // Apply the scaling
    // mouse_report.x = (int8_t)(dx * accel_factor);
    // mouse_report.y = (int8_t)(dy * accel_factor);

    // Calculate movement magnitude
    int magnitude = abs(mouse_report.x) + abs(mouse_report.y);


    // Apply a simple acceleration curve
    float accel_factor = 1.0f;
    if (magnitude > 5) {
        accel_factor = 2.5f;
    } else if (magnitude > 3) {
        accel_factor = 1.5f;
    }

    // Calculate magnitude of movement vector
    float dx = (float)mouse_report.x;
    float dy = (float)mouse_report.y;
    
    int scaled_x = (int)(dx * accel_factor);
    int scaled_y = (int)(dy * accel_factor);
    
    // Clamp to valid int8_t range [-127, 127]
    if (scaled_x > 127) scaled_x = 127;
    if (scaled_x < -127) scaled_x = -127;
    
    if (scaled_y > 127) scaled_y = 127;
    if (scaled_y < -127) scaled_y = -127;
    
        // Apply the acceleration
    mouse_report.x = (int8_t)scaled_x;
    mouse_report.y = (int8_t)scaled_y;

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
// ENCODERS :
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    // Mappings for 1st Encoder          // Mappings for 2nd Encoder
    [_COLEMAK_FR] = {ENCODER_CCW_CW(KC_WH_U, KC_WH_D),
                     ENCODER_CCW_CW(KC_VOLD,KC_VOLU)}, // Mapping for Base layer
    [_GAME] = {ENCODER_CCW_CW(KC_WH_U, KC_WH_D),
               ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [_AUX_GAME] = {ENCODER_CCW_CW(KC_WH_U, KC_WH_D),
                   ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [_CAPS_LOCK] = {ENCODER_CCW_CW(KC_WH_U, KC_WH_D),
                    ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [_F_KEYS] = {ENCODER_CCW_CW(KC_WH_U, KC_WH_D),
                 ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [_NUMPAD_RIGHT] = {ENCODER_CCW_CW(KC_WH_U, KC_WH_D),
                       ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [_NAV] = {ENCODER_CCW_CW(KC_WH_U, KC_WH_D),
              ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [_OPERATIONS] = {ENCODER_CCW_CW(KC_WH_U, KC_WH_D),
                     ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [_WEB_BROWSER] = {ENCODER_CCW_CW(KC_WH_U, KC_WH_D),
                      ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [_MOUSE_LAYER]  = {ENCODER_CCW_CW(DPI_DEC, DPI_INC),
                       ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [_ACCENTS] = {ENCODER_CCW_CW(KC_WH_U, KC_WH_D),
                  ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [_REG_SPE] = {ENCODER_CCW_CW(KC_WH_U, KC_WH_D),
                  ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [_MULTIMEDIA] = {ENCODER_CCW_CW(KC_WH_U, KC_WH_D),
                     ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [_RGB] = {ENCODER_CCW_CW(KC_WH_U, KC_WH_D),
              ENCODER_CCW_CW(KC_VOLD, KC_VOLU)}};

bool shutdown_user(bool jump_to_bootloader) {
  oled_render_boot(jump_to_bootloader);
  return false;
}
