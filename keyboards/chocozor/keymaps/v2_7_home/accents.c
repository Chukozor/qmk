#include "accents.h"
#include "enum.h"

static inline void tap_e_grave(void) { tap_code(KC_7); }

static inline void tap_e_aigue(void) { tap_code(KC_2); }

static inline void tap_e_circ(void) {
  tap_code(KC_LBRC);
  tap_code(KC_E);
}

static inline void tap_c_ced(void) { tap_code(KC_9); }

static inline void tap_a_grave(void) { tap_code(KC_0); }

static inline void tap_a_circ(void) {
  tap_code(KC_LBRC);
  tap_code(KC_Q);
}

static inline void tap_i_circ(void) {
  tap_code(KC_LBRC);
  tap_code(KC_I);
}

static inline void tap_i_trema(void) {
  register_code(KC_LSFT);
  tap_code(KC_LBRC);
  unregister_code(KC_LSFT);
  tap_code(KC_I);
}

static inline void tap_u_grave(void) { tap_code(KC_QUOTE); }

static inline void tap_u_circ(void) {
  tap_code(KC_LBRC);
  tap_code(KC_U);
}

static inline void tap_o_circ(void) {
  tap_code(KC_LBRC);
  tap_code(KC_O);
}

enum {
  TAPPED_NO_ACCENT,
  TAPPED_ACCENT,
  INTERRUPTED_NO_ACCENT,
  INTERRUPTED_ACCENT,
  HELD_NO_ACCENT,
  HELD_ACCENT 
};

bool process_accents(uint16_t keycode, keyrecord_t* record){
  if (!record->event.pressed)
    return false;
  // Logique pour calculer dans quel etat on est.
  int etat;
  if (record->tap.count) {
    etat = 0;
  }
  // motion hold
  else if (record->tap.interrupted) {
    etat = 1;
  } else {
    etat = 2;
  }
  // not interrupted
  etat = etat * 2 + IS_LAYER_ON(_ACCENTS);
  // Gestion des accents.
  switch (keycode) {
  case HT_E:
    switch (etat) {
    case TAPPED_NO_ACCENT:
      tap_code(KC_E); return false;
    case TAPPED_ACCENT:
      tap_e_aigue(); return false;
    case INTERRUPTED_NO_ACCENT:
      tap_code(KC_E); return false;
    case INTERRUPTED_ACCENT:
      tap_e_aigue(); return false;
    case HELD_NO_ACCENT:
      tap_e_grave(); return false;
    case HELD_ACCENT:
      tap_e_circ(); return false;
    }

  case HT_A:
    switch (etat) {
    case TAPPED_ACCENT:
      tap_a_grave(); return false;
    case INTERRUPTED_ACCENT:
      tap_a_grave(); return false;
    case HELD_ACCENT:
      tap_a_circ(); return false;
    default:
      return true;
    }

    case HT_I:
    switch (etat) {
    case TAPPED_ACCENT:
      tap_i_circ(); return false;
    case INTERRUPTED_ACCENT:
      tap_i_circ(); return false;
    case HELD_ACCENT:
      tap_i_trema(); return false;
    default:
      return true;
    }

    case HT_U:
    switch (etat) {
    case TAPPED_ACCENT:
      tap_u_grave(); return false;
    case INTERRUPTED_ACCENT:
      tap_u_grave(); return false;
    case HELD_ACCENT:
      tap_u_circ(); return false;
    default:
      return true;
    }

  case MY_CEDIL:
    if (!record->event.pressed) {return false;}
    tap_c_ced(); return false;
  case MY_OCIRC:
    if (!record->event.pressed) {return false;}
    tap_o_circ(); return false;
  }


  return true;
}
