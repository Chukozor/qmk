
        case MY_SLH:
          if (record->event.pressed) {
            register_code(KC_LSFT);
            tap_code(KC_DOT);
            unregister_code(KC_LSFT);
            // here we override its «press» behavior (hence, return false)
            return false;
          } else {
            // here we don't alter its «release» default behavior (hence, return true)
            return true;
          }

        case MY_BSLH:
          if (record->event.pressed) {
            register_code(KC_RALT);
            tap_code(KC_8);
            unregister_code(KC_RALT);
            // here we override its «press» behavior (hence, return false)
            return false;
          } else {
            // here we don't alter its «release» default behavior (hence, return true)
            return true;
          }

        case MY_DOLL:
          if (record->event.pressed) {
            tap_code(KC_RBRC);
            // here we override its «press» behavior (hence, return false)
            return false;
          } else {
            // here we don't alter its «release» default behavior (hence, return true)
            return true;
          }
          
        case MY_DIESE:
          if (record->event.pressed) {
            add_mods(MOD_BIT_RALT);
            tap_code(KC_3);
            unregister_mods(MOD_BIT_RALT);
            // here we override its «press» behavior (hence, return false)
            return false;
          } else {
            // here we don't alter its «release» default behavior (hence, return true)
            return true;
          }

        case MY_EURO:
          if (record->event.pressed) {
            add_mods(MOD_BIT_RALT);
            tap_code(KC_E);
            unregister_mods(MOD_BIT_RALT);
            // here we override its «press» behavior (hence, return false)
            return false;
          } else {
            // here we don't alter its «release» default behavior (hence, return true)
            return true;
          }

        case MY_TILD:
          if (record->event.pressed) {
            // add_mods(MOD_BIT_LALT);
            // tap_code(KC_KP_1);
            // tap_code(KC_KP_2);
            // tap_code(KC_KP_6);
            // unregister_mods(MOD_BIT_LALT);
            add_mods(MOD_BIT_RALT);
            tap_code(KC_2);
            unregister_mods(MOD_BIT_RALT);
            add_mods(MOD_BIT_RALT);
            tap_code(KC_2);
            unregister_mods(MOD_BIT_RALT);
            tap_code(KC_BSPC);
            // here we override its «press» behavior (hence, return false)
            return false;
          } else {
            // here we don't alter its «release» default behavior (hence, return true)
            return true;
          }

        
        case MY_BQUOT2:
          if (record->event.pressed) {
            switch(detected_host_os()){
              case OS_LINUX:
                register_mods(MOD_MASK_SHIFT | MOD_MASK_CTRL);
                tap_code(KC_U);
                unregister_mods(MOD_MASK_SHIFT | MOD_MASK_CTRL);
                tap_code(KC_P6);
                tap_code(KC_P0);
                tap_code(KC_SPC);
                return false;

              case OS_WINDOWS:
                  add_mods(MOD_BIT_LALT);
                  tap_code(KC_P0);
                  tap_code(KC_P9);
                  tap_code(KC_P6);
                  unregister_mods(MOD_BIT_LALT);
                  return false;
              default:
                return false;
              }
              return false;
          }

        case MY_PIPE:
          if (record->event.pressed) {
            // add_mods(MOD_BIT_LCTRL);
            add_mods(MOD_BIT_RALT);
            tap_code(KC_6);
            // tap_code(KC_KP_9);
            // tap_code(KC_KP_6);
            unregister_mods(MOD_BIT_RALT);
            // unregister_mods(MOD_BIT_LCTRL);
            // here we override its «press» behavior (hence, return false)
            return false;
          } else {
            // here we don't alter its «release» default behavior (hence, return true)
            return true;
          }