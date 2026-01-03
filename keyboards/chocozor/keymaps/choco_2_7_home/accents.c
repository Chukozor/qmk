#include "accents.h"

enum {
  TAPPED_NO_ACCENT,
  TAPPED_ACCENT,
  INTERRUPTED_NO_ACCENT,
  INTERRUPTED_ACCENT,
  HELD_NO_ACCENT,
  HELD_ACCENT 
}

bool proccess_accents(uint16_t keycode, keyrecord_t* record){
  if(!record->event.pressed)
    return false;
  //Logique pour calculer dans quel etat on est.
  int etat;
  if(record->tap.count) 
    etat = 0 
    // motion hold
   else if(record->tap.interrupted){
      etat = 1
    }
   else{
      etat = 2 // no interrupted
    } 
  etat = etat * 2 + IS_LAYER_ON(_ACCENTS);  
  //Gestion des accents. 
  case HT_E:
    switch(etat){
     case TAPPED_NO_ACCENT:
       tap_code(KC_E);
       return false;

     case TAPPED_ACCENT:
       tap_e_aigue();
       return false;

     case INTERRUPTED_NO_ACCENT:
       tap_code(KC_E);
       return false;

     case INTERRUTED_ACCENT:
       tap_e_aigue();
       return false;

     case HELD_NO_ACCENT:
       tap_e_grave();
       return false;

     case HELD_ACCENT:
       tap_e_circ();
       return false;
     }
}
