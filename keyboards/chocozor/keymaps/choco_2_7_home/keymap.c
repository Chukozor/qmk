#include QMK_KEYBOARD_H
#include "keymap_french.h"
#include "timer.h"
#include "enum.h"
#include "accents.h"
#include "gaming.h"
#include "globals.h"
#include "web.h"
#include "numpad.h"
#include "drivers/haptic/solenoid.h"

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
  TOGGLE_TF2,
  // TOGGLE_GAME2,
  // FAST_SWITCH_GAME_COLEMAK_COMBO,
  // FAST_SWITCH_GAME_COLEMAK_COMBO2,
  TOGGLE_WEB,
  // TOGGLE_RGB,
  COMBO_CLEAR_EEPROM,
  COMBO_WEB,
  COMBO_PRINT_SCREEN,
  COMBO_REG_QWERTY,
  COMBO_REG_QWERTY2,
  COMBO_NUMPAD_RIGHT,
  COMBO_NUMPAD_RIGHT2
  // ...,
  // COMBO_E_AIGU
};



// const uint16_t PROGMEM temp_active_RGB[] = {MY_ENT, HT_SPC, COMBO_END};
const uint16_t PROGMEM toggle_numpad_right[] = {MOFKEYS, KC_LALT, COMBO_END};
const uint16_t PROGMEM toggle_numpad_right2[] = {MO(_OPERATIONS), KC_LALT, COMBO_END};
const uint16_t PROGMEM temp_active_MULTIMEDIA[] = {KC_LGUI, MY_NAV, HT_SPC, COMBO_END};
const uint16_t PROGMEM temp_active_SHIFT[] = {CSTM_ENT, HT_SPC, COMBO_END};
// const uint16_t PROGMEM r[] = {MOFKEYS, CSTM_ENT, COMBO_END};
const uint16_t PROGMEM combo_capslock[] = {KC_LSFT, KC_RSFT, COMBO_END};
const uint16_t PROGMEM temp_active_boot[] = {MY_NAV,HT_SPC,KC_LGUI,KC_LALT,CSTM_ENT, COMBO_END};
const uint16_t PROGMEM temp_active_boot2[] = {KC_LGUI,MY_NAV,HT_SPC,MOFKEYS, CSTM_ENT,KC_LALT, COMBO_END};
// const uint16_t PROGMEM toggle_gaming[] = {FR_Q,FR_W,KC_F,KC_P,KC_G, COMBO_END};
const uint16_t PROGMEM toggle_game[] = {FR_A,KC_R,KC_S,KC_T,KC_D, COMBO_END};
const uint16_t PROGMEM toggle_tf2[] = {FR_Q,FR_W,KC_F,KC_P,KC_G,COMBO_END};
// const uint16_t PROGMEM toggle_game2[] = {KC_LSFT,FR_A,FR_W,KC_D,KC_T, COMBO_END};
// const uint16_t PROGMEM fast_switch_game_colemak_combo[] = {MY_ESC,MY_LCTL,KC_LSFT, COMBO_END};
// const uint16_t PROGMEM fast_switch_game_colemak_combo2[] = {KC_ESC,KC_TAB, APEX_CTL, COMBO_END};
// const uint16_t PROGMEM combo_toggle_web[] = {KC_LGUI,MY_NAV, COMBO_END};
// const uint16_t PROGMEM toggle_RGB[] = {MOFKEYS, CSTM_ENT,KC_LALT, COMBO_END};
const uint16_t PROGMEM combo_clear_eeprom[] = {RGB_TOG, _I__MOD, _I_COUL, __I_LUM, __I_SAT, COMBO_END};
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
    [COMBO_NUMPAD_RIGHT]=COMBO(toggle_numpad_right, TG(_NUMPAD_RIGHT)),
    [COMBO_NUMPAD_RIGHT2]=COMBO(toggle_numpad_right2, TG(_NUMPAD_RIGHT)),
    [COMBO_MULTIMEDIA]=COMBO(temp_active_MULTIMEDIA, MO(_MULTIMEDIA)),
    // [TOGGLE_GAMING]=COMBO(toggle_gaming, TG(_AUX_GAME)),
    [TOGGLE_GAME]=COMBO(toggle_game, TG_GAME),
    [TOGGLE_TF2]=COMBO(toggle_tf2, TG(_TF2)),
    // [TOGGLE_GAME2]=COMBO(toggle_game2, TG_GAME),
    [COMBO_OSM_SHIFT]=COMBO(temp_active_SHIFT, OSM(MOD_LSFT)),
    // [COMBO_OSM_SHIFT2]=COMBO(temp_active_SHIFT2, OSM(MOD_LSFT)),
    [COMBO_CAPSLOCK]=COMBO(combo_capslock, DBL_SHIFT),
    [COMBO_BOOT]=COMBO(temp_active_boot, QK_BOOT),
    [COMBO_BOOT2]=COMBO(temp_active_boot2, QK_BOOT),
    // [FAST_SWITCH_GAME_COLEMAK_COMBO]=COMBO(fast_switch_game_colemak_combo, FAST_SWITCH_GAME_COLEMAK),
    // [FAST_SWITCH_GAME_COLEMAK_COMBO2]=COMBO(fast_switch_game_colemak_combo2, FAST_SWITCH_GAME_COLEMAK),
    // [TOGGLE_WEB]=COMBO(combo_toggle_web, TG(_WEB_BROWSER)),
    // [TOGGLE_RGB]=COMBO(toggle_RGB, TG(_RGB)),
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
  if (combo_index == TOGGLE_GAME) {
      return true;
  }
  if (combo_index == TOGGLE_TF2) {
    return true;
}
  if (layer_state_is(_TF2)) {
      return false;
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


static uint16_t last_fire = 0;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        if (timer_elapsed(last_fire) > 80) {  // 80 ms entre deux activations
            solenoid_fire(0);
            last_fire = timer_read();
        }
    }
    return true;

    #define X(x) case x:
    #define Y(x) X(x)
    #define Z(x) X(x)
    switch(keycode){
     _ACCENTS_RANGE
      return(process_accents(keycode, record));
     _WEB_RANGE
       return(process_web(keycode, record));
     _NUMPAD_RANGE
       return(process_numpad(keycode, record));
     _GAMING_RANGE
       return(process_gaming(keycode, record));
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
      } else { // Hold
        if (record->event.pressed) { // pressed
          // if (!record->tap.interrupted) {
            if (IS_LAYER_ON(_ACCENTS)) {
              // layer_on(_RGB);
            } else {
              layer_on(_REG_SPE);
            }
        }
        else { // released
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
   }

    #undef X
    #undef Y
    #undef Z
    
  return(true);
}

#define WEB_BROWSER_LAYER_TIMEOUT 10000  //configure your timeout in milliseconds

void matrix_scan_user(void) {
  if (IS_LAYER_ON(_WEB_BROWSER)) {
    if (last_input_activity_elapsed() > WEB_BROWSER_LAYER_TIMEOUT) {
      layer_off(_WEB_BROWSER);
    }
  }
}


uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // case SFT_T(KC_SPC):
        //    return g_tapping_term + 1250;
        case MY_ESC:
            return 200;
        // case MY_LSFT:
        //     return 160;
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
        // case MY_W_H:
        //     return 140;
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
            // Do not force the mod-tap key press to be handled as a modifier
            // if any other key was pressed while the mod-tap key is held down.
            return false;
        case HT_I:
            // Do not force the mod-tap key press to be handled as a modifier
            // if any other key was pressed while the mod-tap key is held down.
            return false;
        case HT_U:
            // Do not force the mod-tap key press to be handled as a modifier
            // if any other key was pressed while the mod-tap key is held down.
            return false;
        case HT_A:
            // Do not force the mod-tap key press to be handled as a modifier
            // if any other key was pressed while the mod-tap key is held down.
            return false;
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
        // case COMBO_OSM_SHIFT2:
        //   return 30;
        case COMBO_PRINT_SCREEN:
          return 25;
        case COMBO_REG_QWERTY:
        case COMBO_REG_QWERTY2:
          return 25;
        default:
          return COMBO_TERM;
    }

    // // And if you're feeling adventurous, you can even decide by the keys in the chord,
    // // i.e. the exact array of keys you defined for the combo.
    // // This can be useful if your combos have a common key and you want to apply the
    // // same combo term for all of them.
    // if (combo->keys[0] == KC_ENT) { // if first key in the array is Enter
    //     return 150;
    // }

    return COMBO_TERM;
}

// When the user holds a key after tapping it, the tapping function is repeated by default, rather than activating the hold function. This allows keeping the ability to auto-repeat the tapping function of a dual-role key. QUICK_TAP_TERM enables fine tuning of that ability. If set to 0, it will remove the auto-repeat ability and activate the hold function instead.

// QUICK_TAP_TERM is set to TAPPING_TERM by default, which is the maximum allowed value for QUICK_TAP_TERM. To override its value (in milliseconds) add the following to your config.h: #define QUICK_TAP_TERM 120

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
  // _COLEMAK_FR
    [_COLEMAK_FR] = LAYOUT_2_7_regular(
         KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,                                              KC_7,    KC_8,    KC_9,    KC_0,   KC_1,    KC_2, 
  //|-----------------------------------------------------.                                           ,---------------------------------------------------.
       MY_ESC,    FR_Q,    FR_W,    KC_F,    KC_P,    KC_G,                                              KC_J,    KC_L,    KC_U,    KC_Y, FR_QUOT,  KC_TAB,
  //|--------+--------+--------+--------+--------+--------|                                           |------+--------+--------+--------+--------+--------|
      MY_LCTL,    FR_A,    KC_R,    KC_S,    KC_T,    KC_D,                                              KC_H,    KC_N,    HT_E,    KC_I,    KC_O, MY_RCTL,
  //|--------+--------+--------+--------+--------+--------|                                           |------+--------+--------+--------+--------+--------|
      KC_LSFT,    FR_Q,    KC_X,    KC_C,    KC_V,    KC_B,                                              KC_K,    FR_M, FR_COMM,  FR_DOT, FR_QUES, KC_RSFT,
  //|-----------------------------------------------------------------------|      |----------------------------------------------------------------------|
                           FR_Z,    KC_1,    KC_2, KC_LGUI,  MY_NAV, HT_SPC,       MOFKEYS, CSTM_ENT, KC_LALT,    KC_1,    KC_2,    KC_3
                     //`-----------------------------------------------------'     `-----------------------------------------------------'
  ),
  // _RGB
    [_RGB] = LAYOUT_2_7_regular(
  //--------------------------------------.    --------------------------------------.
       FR_A, KC_B, KC_C, KC_D, KC_E, KC_F,     S(FR_A), S(KC_B), S(KC_C), S(KC_D), S(KC_E), S(KC_F), 
  //|--------+--------+--------+--------+-|    |--------+--------+--------+--------+-|
       KC_G, KC_H, KC_I, KC_J, KC_K, KC_L,     RGB_TOG, _I__MOD, _I_COUL, __I_LUM, __I_SAT, __I_VIT, 
  //|--------+--------+--------+--------+-|    |--------+--------+--------+--------+-|
       KC_M, KC_N, KC_O, KC_P, FR_Q, KC_R,     XXXXXXX, _D_RMOD, _D_COUL, __D_LUM, __D_SAT, __D_VIT,
  //|-------------------------------------|    |-------------------------------------|
       KC_U, KC_V, FR_W, KC_X, KC_Y, FR_Z,     S(KC_U), S(KC_V), S(FR_W), S(KC_X), S(KC_Y), S(FR_Z), 
  //|-------------------------------------|    |-------------------------------------|
      KC_P1,KC_P2,KC_P3,KC_P4,TG(_RGB),KC_P6,    KC_P7,   KC_P8,   KC_P9, KC_LEFT, KC_DOWN, KC_RIGHT
  //|-------------------------------------|    |-------------------------------------|
  )
};


// // ==============================================
// ENCODERS :
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
        // Mappings for 1st Encoder          // Mappings for 2nd Encoder
  [_COLEMAK_FR]   = { ENCODER_CCW_CW(KC_WH_U, KC_WH_D),  ENCODER_CCW_CW(KC_VOLD, KC_VOLU)  }, // Mapping for Base layer
  [_RGB]   = { ENCODER_CCW_CW(KC_WH_U, KC_WH_D),  ENCODER_CCW_CW(KC_VOLD, KC_VOLU)  }, // Mapping for Base layer
};
