#include "globals.h"
#include "web.h"
#include "enum.h"

bool process_web(uint16_t keycode, keyrecord_t* record){
 switch (keycode) {
    case AUX_WEB:
      if (record->event.pressed) {
          // logic when pressed
          web_aux = true;
          // SEND_STRING(SS_DOWN(X_WSTP));
        } else {
          web_aux = false;
          // SEND_STRING(SS_UP(X_WSTP));
        }
        return false;

       case WEB_D:
      // if (spc_is_held) {
      //   if (record->event.pressed) {
      //     my_copy();
      //   }
      //   return false;
      // } else {
      if (get_mods() != MOD_BIT(KC_LALT)) {
        if (record->event.pressed) {
          register_code(KC_LCTL);
        } else {
          unregister_code(KC_LCTL);
        }
      }
      if (web_aux){
        if (record->event.pressed) {
          SEND_STRING(SS_DOWN(X_WFWD));
        } else {
          SEND_STRING(SS_UP(X_WFWD));
        }
      } else {
        if (record->event.pressed) {
          SEND_STRING(SS_DOWN(X_TAB));
          // tap_code(KC_TAB);
          // SEND_STRING(SS_LSFT(SS_TAP(X_TAB)));
        } else {
          SEND_STRING(SS_UP(X_TAB));
        }
      }
      return false;

    case WEB_G:
      // if (spc_is_held) {
      //   if (record->event.pressed) {
      //     my_selec_all();
      //   }
      //   return false;
      // } else {
      if (get_mods() != MOD_BIT(KC_LALT)) {
        if (record->event.pressed) {
          register_code(KC_LCTL);
        } else {
          unregister_code(KC_LCTL);
        }
      }
      
      if (web_aux){
        if (record->event.pressed) {
          SEND_STRING(SS_DOWN(X_WBAK));
        } else {
          SEND_STRING(SS_UP(X_WBAK));
        }
      } else {
        if (record->event.pressed) {
          // register_code(KC_LSFT);
          register_mods(MOD_BIT_LSHIFT);
          SEND_STRING(SS_DOWN(X_TAB));
          // SEND_STRING(SS_DOWN(X_LSFT));
          // SEND_STRING(SS_DOWN(X_TAB));
          // SEND_STRING(SS_LSFT(SS_TAP(X_TAB)));
          // SEND_STRING(SS_LSFT(SS_DOWN(X_TAB)));
        } else {
          SEND_STRING(SS_UP(X_TAB));
          unregister_mods(MOD_BIT_LSHIFT);
          // SEND_STRING(SS_LSFT(SS_UP(X_TAB)));
          // SEND_STRING(SS_UP(X_TAB));
          // SEND_STRING(SS_UP(X_LSFT));
        }
      }
      return false;

    case WEB_DUP:
    // Ctrl + L (or Cmd + L) — focuses the address bar.
    // Alt + Enter (or Cmd + Enter) 
      // if (record->tap.count) { // Tap
        if (record->event.pressed) {
            // logic when pressed
            SEND_STRING(SS_DOWN(X_LCTL));
            // SEND_STRING(SS_DOWN(X_LSFT));
            // SEND_STRING(SS_DELAY(1));
            SEND_STRING(SS_TAP(X_L));
            SEND_STRING(SS_UP(X_LCTL));
            SEND_STRING(SS_DELAY(1));
            // SEND_STRING(SS_UP(X_LSFT));
            SEND_STRING(SS_DOWN(X_LALT));
            SEND_STRING(SS_TAP(X_ENT));
            SEND_STRING(SS_UP(X_LALT));
          }
          // else {
          // }
      // } else { // Hold
      //   if (record->event.pressed) {
      //     // logic when pressed
      //     // if (record->tap.interrupted) {
      //     //   // logic when interrupted
      //     // } else {
      //     //   // logic when not interrupted
      //     // }
      //     SEND_STRING(SS_DOWN(X_WSTP)); // KC_WSTP = browser stop

      //   } else {
      //     // logic when released
      //     SEND_STRING(SS_UP(X_WSTP)); // KC_WSTP = browser stop
      //   }
      // }
      return false;

    case WEB_TAB:
      if (record->tap.count) { // tapped
        if (record->event.pressed) {
          SEND_STRING(SS_DOWN(X_LCTL));
          SEND_STRING(SS_DELAY(1));
          SEND_STRING(SS_TAP(X_Z));// CTRL + W, ici Z pcq langue francaise KC_Z = FR_W
          SEND_STRING(SS_UP(X_LCTL));
        }
      } else { // held
        if (record->event.pressed) {
          // if (record->tap.interrupted) {
          // } else {
          //   layer_on(_ACCENTS);
          // }
          SEND_STRING(SS_DOWN(X_LCTL));
          SEND_STRING(SS_DOWN(X_LSFT));
          SEND_STRING(SS_DELAY(1));
          SEND_STRING(SS_TAP(X_T));
          SEND_STRING(SS_UP(X_LSFT));
          SEND_STRING(SS_UP(X_LCTL));
        }
      }
      return false;
    
    case FF_FENE:
      if (record->tap.count) { // tapped
        if (record->event.pressed) {
          SEND_STRING(SS_DOWN(X_LCTL));
          SEND_STRING(SS_DELAY(1));
          SEND_STRING(SS_TAP(X_N));// CTRL + W, ici Z pcq langue francaise KC_Z = FR_W
          SEND_STRING(SS_UP(X_LCTL));
        }
      } else { // held
        if (record->event.pressed) {
          // if (record->tap.interrupted) {
          // } else {
          //   layer_on(_ACCENTS);
          // }
          SEND_STRING(SS_DOWN(X_LCTL));
          SEND_STRING(SS_DOWN(X_LSFT));
          SEND_STRING(SS_DELAY(1));
          SEND_STRING(SS_TAP(X_N));
          SEND_STRING(SS_UP(X_LSFT));
          SEND_STRING(SS_UP(X_LCTL));
        }
      }
      return false;

    case FF_T_ST:
      if (record->tap.count) { // Tap
        if (record->event.pressed) {
            // logic when pressed
            SEND_STRING(SS_DOWN(X_LCTL));
            // SEND_STRING(SS_DOWN(X_LSFT));
            SEND_STRING(SS_DELAY(1));
            SEND_STRING(SS_TAP(X_T));
            SEND_STRING(SS_DELAY(1));
            // SEND_STRING(SS_UP(X_LSFT));
            SEND_STRING(SS_UP(X_LCTL));
          } else {
          }
      } else { // Hold
        if (record->event.pressed) {
          // logic when pressed
          // if (record->tap.interrupted) {
          //   // logic when interrupted
          // } else {
          //   // logic when not interrupted
          // }
          SEND_STRING(SS_DOWN(X_WSTP)); // KC_WSTP = browser stop

        } else {
          // logic when released
          SEND_STRING(SS_UP(X_WSTP)); // KC_WSTP = browser stop
        }
      }
        return false;

     } 
 return true;
  
}
