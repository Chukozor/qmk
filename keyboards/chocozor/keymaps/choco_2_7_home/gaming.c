#include "gaming.h"
#include "enum.h"
bool process_gaming(uint16_t keycode, keyrecord_t *record){
  switch (keycode) {
    case TG_GAME:
      if (record->event.pressed) {
        // logic when pressed
        layer_invert(_GAME);
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
