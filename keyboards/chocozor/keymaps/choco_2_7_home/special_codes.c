#include QMK_KEYBOARD_H
#include "special_codes.h"

static void SEND_NUMERIC(char* code){
  while(*code){
    switch(*code){
        case 0: tap_code16(KC_KP_0); break;
        case 1: tap_code16(KC_KP_1); break;
        case 2: tap_code16(KC_KP_2); break;
        case 3: tap_code16(KC_KP_3); break;
        case 4: tap_code16(KC_KP_4); break;
        case 5: tap_code16(KC_KP_5); break;
        case 6: tap_code16(KC_KP_6); break;
        case 7: tap_code16(KC_KP_7); break;
        case 8: tap_code16(KC_KP_8); break;
        case 9: tap_code16(KC_KP_9); break;
    }
    code++;
  }  
}

void special_code_helper(char* code, int variant){
  if(variant==OS_LINUX){
    register_code(KC_LEFT_CTRL);
    register_code(KC_LSFT);
    register_code(KC_U);
    unregister_code(KC_LSFT);
    unregister_code(KC_LEFT_CTRL);
    unregister_code(KC_U);
    SEND_STRING(code);
    tap_code16(KC_ENTER);
  }
  else if(variant==OS_WINDOWS){
    register_code(KC_LEFT_ALT);
    SEND_NUMERIC(code);
    unregister_code(KC_LEFT_ALT);
  }
}
