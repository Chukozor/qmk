#include QMK_KEYBOARD_H
#include "enum.h"
#include "timer.h"
#include "drivers/haptic/solenoid.h"
bool solenoid_actif = false;

void solenoid_helper(void){
  static uint16_t last_fire = 0;
   if(!solenoid_actif)
     return;
   if(timer_elapsed(last_fire) > 40){
     solenoid_fire(0); 
   last_fire = timer_read();
   }
}

void solenoid_toggle(void){
  solenoid_actif = !solenoid_actif;
}
