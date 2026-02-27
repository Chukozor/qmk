bool alt_tab_menu = false;
bool ky_webnav = false;
bool ky_spc = false;
bool web_aux = false;

#include "custom_files/functions_record_user.h"

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
      case HT_E:
        if (record->tap.count) { // tapped
          if (!record->event.pressed) {
            // your logic when released
            return false;
          }

          if (is_accent_layer()) {
            tap_e_aigue();
          } else {
            tap_code(KC_E);
          }
        } else { // held
          if (!record->event.pressed) {
            // your logic when released
            return false;
          }
          
          if (record->tap.interrupted) {
            if (is_accent_layer()) {
              tap_e_aigue();
            } else {
              tap_code(KC_E); // p-e a modifier avec un sendstring pour pouvoir le répéter lorsque maintenu
            }
          } else {
            if (is_accent_layer()) {
              tap_e_circ();
            } else {
              if (get_mods() == MOD_BIT(KC_LSFT)) {   // if (get_mods() != MOD_BIT(KC_LSFT)) {
                // unregister_mods(MOD_BIT_LSFT);
                tap_code(KC_E);
              } else {
                tap_e_grave();
              }
            }
          }
        }
        return false;
          
      case HT_C:
          if (!record->event.pressed) {
            return false;
          }

          if (is_accent_layer()) {
            tap_c_ced();
          } else {
            tap_code(KC_C);
          }
        return false;

      case C_CEDIL:
        // if (record->tap.count) { // tapped
          if (!record->event.pressed) {
            return false;
          }
            tap_c_ced();
        return false;

      case HT_A:
          if (record->tap.count) { // tapped
              if (record->event.pressed) {
                  tap_a_grave();
              }
          } else {
            if (!record->event.pressed) {
            // your logic when released
            return false;
            }
            if (record->tap.interrupted) {
              // logic when interrupted
              tap_a_grave();
            } else {
              tap_a_circ();
              // logic when not interrupted
            }
          }
      
          return false;
      
      case HT_U:
        if (record->tap.count) { // tapped
          if (!record->event.pressed) {
            return false;
          }

          if (is_accent_layer()) {
            tap_u_grave();
          } else {
            tap_code(KC_U);
          }
        } else { // held

          if (record->event.pressed) {
            // logic when pressed
            if (record->tap.interrupted) {
              // logic when interrupted
              tap_u_grave();
            } else {
              // logic when not interrupted
              if (is_accent_layer()) {
                tap_u_circ();
          }
            }
          } else {
            // logic when released
            return false;
          }
        }
        return false;
      
      case HT_I:
        if (record->tap.count) { // Tap
          if (!record->event.pressed) {
            // your logic when pressed
            return false;
          }
      
          if (is_accent_layer()) {
            tap_i_circ();
          } else {
            tap_code(KC_I);
          }
        } else { // held

          if (record->event.pressed) {
            // logic when pressed
            if (record->tap.interrupted) {
              // logic when interrupted
              tap_i_circ();
            } else {
              // logic when not interrupted
              if (is_accent_layer()) {
                tap_i_trema();
          }
            }
          } else {
            // logic when released
            return false;
          }
        }
        return false;

      case HT_O:
        if (record->tap.count) {
          if (!record->event.pressed) {
            return false;
          }
          if (is_accent_layer()) {
            tap_o_circ();
          } else {
            tap_code(KC_O);
          }
        } else {
          if (record->event.pressed) {
            if (is_accent_layer()) {
              tap_o_circ();
            }
          }
        }
        return false;

      case MY_OCIRC:
        // if (record->tap.count) {
          if (!record->event.pressed) {
            return false;
          }
            tap_o_circ();
        return false;
    #include "custom_files/my_specials_char_precuser.h"

    case MY_PRT_S:
      if (record->event.pressed) {
        tap_code(KC_PSCR);
        // here we override its «press» behavior (hence, return false)
        return false;
      } else {
        // here we don't alter its «release» default behavior (hence, return true)
        return true;
      }
      break;

    case MY_PRT_Z:
      if (record->event.pressed) {
        add_mods(MOD_BIT_RCTRL);
        tap_code(KC_PSCR);
        unregister_mods(MOD_BIT_RCTRL);
        // here we override its «press» behavior (hence, return false)
        return false;
      } else {
        // here we don't alter its «release» default behavior (hence, return true)
        return true;
      }
      break;

    case MY_PRT_P:
      if (record->event.pressed) {
        add_mods(MOD_BIT_LSHIFT);
        tap_code(KC_PSCR);
        unregister_mods(MOD_BIT_LSHIFT);
        // here we override its «press» behavior (hence, return false)
        return false;
      } else {
        // here we don't alter its «release» default behavior (hence, return true)
        return true;
      }
      break;

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
      break;

    case MY_COPY:
      if (record->event.pressed) {
        my_copy();
      }
      return false;
      
    case MY_CUT:
      if (record->event.pressed) {
        my_cut();
      }
      return false;

    case MY_PASTE:
      if (record->event.pressed) {
        my_paste();
      }
      return false;

    case MY_UNDO:
      if (record->event.pressed) {
        my_undo_down();
      } else {
        my_undo_up();
      }
      return false;

    case MY_REDO:
      if (record->event.pressed) {
        my_redo_down();
      } else {
        my_redo_up();
      }
      return false;

    case MY_SAVE:
      if (record->event.pressed) {
        my_save();
      }
      return false;

    case CSTM_ENT:
      if (record->tap.count) { // Tap
        if (record->event.pressed) {
          // your logic when pressed
          if (is_accent_layer()) {
            SEND_STRING(SS_LSFT(SS_TAP(X_ENT)));
          } else {
            tap_code(KC_ENT);
          }
        }
      } else { // Hold
        if (record->event.pressed) { // pressed
            if (is_accent_layer()) {
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

    case WEB_D:
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
        } else {
          SEND_STRING(SS_UP(X_TAB));
        }
      }
      return false;

    case WEB_G:
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
          register_mods(MOD_BIT_LSHIFT);
          SEND_STRING(SS_DOWN(X_TAB));
        } else {
          SEND_STRING(SS_UP(X_TAB));
          unregister_mods(MOD_BIT_LSHIFT);
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

    case SEL_ALL:
      if (record->event.pressed) {
        my_selec_all();
      }
      return false;

    case TEST1:
      if (record->event.pressed) {
        // À (a majuscule accent) = Ctrl + Alt + 7 puis Maj + A (le 7 est celui situé en haut du clavier et non celui du pavé numérique)
        SEND_STRING(SS_DOWN(X_LCTL));
        SEND_STRING(SS_DOWN(X_LALT));
        SEND_STRING(SS_DELAY(1));
        SEND_STRING(SS_TAP(X_7));
        SEND_STRING(SS_UP(X_LALT));
        SEND_STRING(SS_UP(X_LCTL));
        SEND_STRING(SS_LSFT(SS_TAP(X_Q)));// KC_Q = FR_A 
      }
      return false;

    case TEST2:
      if (record->event.pressed) {
        // É (e majuscule accent aigu) = Ctrl + 4 puis Maj + E
        SEND_STRING(SS_DOWN(X_LCTL));
        // SEND_STRING(SS_DOWN(X_LALT));
        SEND_STRING(SS_DELAY(1));
        SEND_STRING(SS_TAP(X_4));
        // SEND_STRING(SS_UP(X_LALT));
        SEND_STRING(SS_LSFT(SS_TAP(X_E)));// KC_Q = FR_A 
        SEND_STRING(SS_UP(X_LCTL));
      }
      return false;

    case TEST3:
      if (record->event.pressed) {
        // È (e majuscule accent grave) = Ctrl + Alt + 7 puis Maj + E
        SEND_STRING(SS_DOWN(X_LCTL));
        SEND_STRING(SS_DOWN(X_LALT));
        SEND_STRING(SS_DELAY(1));
        SEND_STRING(SS_TAP(X_7));
        SEND_STRING(SS_UP(X_LALT));
        SEND_STRING(SS_UP(X_LCTL));
        SEND_STRING(SS_LSFT(SS_TAP(X_E)));
      }
      return false;

    case TEST4:
      if (record->event.pressed) {
        // Ç (c cédille majuscule) = Ctrl+, puis Maj + C
        SEND_STRING(SS_DOWN(X_LCTL));
        // SEND_STRING(SS_DOWN(X_LALT));
        SEND_STRING(SS_DELAY(1));
        SEND_STRING(SS_TAP(X_M));// KC_M = "FR_VIRGULE"
        // SEND_STRING(SS_UP(X_LALT));
        SEND_STRING(SS_UP(X_LCTL));
        SEND_STRING(SS_LSFT(SS_TAP(X_C)));
      }
      return false;

    case TEST5:
      if (record->event.pressed) {
        // Ê = Ctrl + Alt + 9 puis Maj + E (le 9 est celui situé en haut du clavier et non celui du pavé numérique)
        SEND_STRING(SS_DOWN(X_LSFT));
        SEND_STRING(SS_DOWN(X_RSFT));
        SEND_STRING(SS_DELAY(1));
        SEND_STRING(SS_TAP(X_LBRC));
        SEND_STRING(SS_UP(X_RSFT));
        SEND_STRING(SS_UP(X_LSFT));
        SEND_STRING(SS_TAP(X_E));
        // SEND_STRING(SS_LSFT(SS_TAP(X_E)));
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

    case KY_WEBNAV:
      if (record->event.pressed) {
        ky_webnav = true;
        SEND_STRING(SS_DOWN(X_LCTL));
        // tap_code(KC_TAB);
      } else {
        SEND_STRING(SS_UP(X_LCTL));
        ky_webnav = false;
      }
      return false;

    case KY_SPC:
      if (record->event.pressed) {
        ky_spc = true;
      } else {
        ky_spc = false;
      }
      return false;
    
    case KY_LEFT:
      if (ky_webnav) {
        if (record->event.pressed) {
          SEND_STRING(SS_DOWN(X_LSFT));
          SEND_STRING(SS_DOWN(X_TAB));
        } else {
          SEND_STRING(SS_UP(X_TAB));
          SEND_STRING(SS_UP(X_LSFT));
        }
      } else if (ky_spc) {
        if (record->event.pressed) {
          SEND_STRING(SS_DOWN(X_LSFT));
          SEND_STRING(SS_DOWN(X_SPC));
        } else {
          SEND_STRING(SS_UP(X_SPC));
          SEND_STRING(SS_UP(X_LSFT));
        }
      } else {
        if (record->event.pressed) {
          SEND_STRING(SS_DOWN(X_LEFT));
        } else {
          SEND_STRING(SS_UP(X_LEFT));
        }
      }
      return false;
    
    case KY_RIGHT:
      if (ky_webnav) {
        if (record->event.pressed) {
          SEND_STRING(SS_DOWN(X_TAB));
        } else {
          SEND_STRING(SS_UP(X_TAB));
        }
      } else if (ky_spc) {
        if (record->event.pressed) {
          SEND_STRING(SS_DOWN(X_SPC));
        } else {
          SEND_STRING(SS_UP(X_SPC));
        }
      } else {
        if (record->event.pressed) {
          SEND_STRING(SS_DOWN(X_RIGHT));
        } else {
          SEND_STRING(SS_UP(X_RIGHT));
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
      return false;

    case TG_GAME:
      if (record->event.pressed) {
        layer_invert(_GAME);
        }
      return false;

    case HALF_PAGE_DOWN:
      if (IS_LAYER_ON(_WEB_BROWSER)) {
        if (record->event.pressed) {
          if (get_mods() != MOD_BIT(KC_LALT)) {
            if (record->event.pressed) {
              register_code(KC_LCTL);
              SEND_STRING(SS_TAP(X_TAB));
              unregister_code(KC_LCTL);
            } else {
            SEND_STRING(SS_TAP(X_TAB));
            }
          }
        }
      } else {
        if (record->event.pressed) {
          // Send multiple KC_DOWN keycodes to simulate "half page down"
          for (int i = 0; i < 10; i++) { // Adjust 10 to the number of lines you want to scroll
              tap_code(KC_DOWN);
          }
        }
      }
      return false; // Skip further processing of this key

    case HALF_PAGE_UP:
      if (IS_LAYER_ON(_WEB_BROWSER)) {
        if (record->event.pressed) {
          if (get_mods() != MOD_BIT(KC_LALT)) {
            if (record->event.pressed) {
              register_code(KC_LCTL);
              SEND_STRING(SS_LSFT(SS_TAP(X_TAB)));
              unregister_code(KC_LCTL);
            } else {
            SEND_STRING(SS_TAP(X_TAB));
            }
          }
        }
      } else {
        if (record->event.pressed) {
          // Send multiple KC_DOWN keycodes to simulate "half page down"
          for (int i = 0; i < 10; i++) { // Adjust 10 to the number of lines you want to scroll
              tap_code(KC_UP);
          }
        }
      }
      return false; // Skip further processing of this key

    case WEB_OFF:
      if (IS_LAYER_ON(_WEB_BROWSER)) {
        layer_off(_WEB_BROWSER);
      }
      return false;
    
    case MO_NUMPAD:
      if (record->event.pressed) {
        combo_nav_activated = true;
        layer_on(_NAV);
      } else if (!nav_verrouillee) {
        layer_off(_NAV);
        combo_nav_activated = false;
      }
      return false;
    
    case DBL_SHIFT:
      if (record->event.pressed) {
        if (layer_state_is(_CAPS_LOCK)) {
          //if already set, then switch it off
          layer_off(_CAPS_LOCK);
          caps_lock_activated = false;
        } else {
          //if not already set, then switch the layer on
          layer_on(_CAPS_LOCK);
          caps_lock_activated = true;
        }
      }
      return false;


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
          SEND_STRING(SS_DOWN(X_WSTP)); // KC_WSTP = browser stop
        } else {
          SEND_STRING(SS_UP(X_WSTP)); // KC_WSTP = browser stop
        }
      }
        return false;

    case APEX_I:
      if (record->tap.count) { // Tap
        if (record->event.pressed) {
          SEND_STRING(SS_DOWN(X_I));
          wait_ms(3);
        } else {
          SEND_STRING(SS_UP(X_I));
        }
      } else { // Hold
        if (record->event.pressed) {
          SEND_STRING(SS_DOWN(X_I));
          wait_ms(3);
          SEND_STRING(SS_UP(X_I));
        } else {
          SEND_STRING(SS_DOWN(X_I));
          wait_ms(3);
          SEND_STRING(SS_UP(X_I));
          wait_ms(3);
        }
      }
      return false;

    case APEX_CTL:
      if (record->tap.count) { // Tap
        if (record->event.pressed) {
          SEND_STRING(SS_DOWN(X_LCTL));
          wait_ms(3);
        } else {
          SEND_STRING(SS_UP(X_LCTL));
        }
      } else { // Hold
        if (record->event.pressed) {
          SEND_STRING(SS_DOWN(X_LCTL));
          wait_ms(3);
          SEND_STRING(SS_UP(X_LCTL));
        } else {
          SEND_STRING(SS_DOWN(X_LCTL));
          wait_ms(3);
          SEND_STRING(SS_UP(X_LCTL));
          wait_ms(3);
        }
      }
      return false;


  }
  return true;
}




// case MY_NAV: { // I am an alias for MO(_NAV)
//     static uint8_t pressed_count = 0;

//     if (record->event.pressed) {
//         pressed_count++;
//     } else {
//         pressed_count--;
//         if (pressed_count) {
//             return false;
//         }
//     }
//     return true;
// }