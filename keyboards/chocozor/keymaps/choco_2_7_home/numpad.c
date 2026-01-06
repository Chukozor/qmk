#include "numpad.h"
#include "enum.h"
#include "globals.h"

bool process_numpad(uint16_t keycode, keyrecord_t *record){
 switch (keycode) {
       case KY_P1:
      if (record->event.pressed) {
        if (alt_tab_menu) {
          tap_code(KC_LEFT);
        } else {
          tap_code(KC_P1);
        }
      }
      return false;

    case KY_P2:
      if (record->event.pressed) {
        if (alt_tab_menu) {
          tap_code(KC_DOWN);
        } else {
          tap_code(KC_P2);
        }
      }
      return false;

    case KY_P3:
      if (record->event.pressed) {
        if (alt_tab_menu) {
          tap_code(KC_RIGHT);
        } else {
          tap_code(KC_P3);
        }
      }
      return false;

    case KY_P5:
      if (record->event.pressed) {
        if (alt_tab_menu) {
          tap_code(KC_UP);
        } else {
          tap_code(KC_P5);
        }
      }
      return false;

    case KY_P8:
      if (record->event.pressed) {
        if (alt_tab_menu) {
          tap_code(KC_DEL);
        } else {
          tap_code(KC_P8);
        }
      }
      return false;

    case NAV_F_OP:
      if (record->event.pressed) {
        layer_on(_NAV);
        trace_operations = true;
      } else {
        layer_off(_NAV);
      }
      // layer_move(_COLEMAK_FR);
      // set_oneshot_layer(_NAV, ONESHOT_START);
      return false;

     }
 return true;
  
}
