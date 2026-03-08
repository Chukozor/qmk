#include QMK_KEYBOARD_H
#include <math.h>
#include "print.h"
#include "enum.h"
#include "trackpad.h"
#include "arithmetic.h"

// Forward declarations.
static inline void xy_filter_apply(report_mouse_t*);
static float acceleration_factor(int8_t, int8_t, bool);

//Constants
#ifndef XY_FILTER_MAG_THRESHOLD
#define XY_FILTER_MAG_THRESHOLD  1    // only when abs(x)+abs(y) <= 1
#endif

#ifndef XY_FILTER_DIVISOR
#define XY_FILTER_DIVISOR 3.0f // 3.0 = light filtering (6.0+ starts to feel dead)
#endif

#ifndef SCROLL_DIVISOR_H_BASE 
#define SCROLL_DIVISOR_H_BASE 50.0   // Horizontal scroll speed
#endif

#ifndef SCROLL_DIVISOR_V_BASE
#define SCROLL_DIVISOR_V_BASE 30.0   // Vertical scroll speed
#endif

#ifndef VOLUME_DIVISOR
#define VOLUME_DIVISOR 18  // Adjust for volume control sensitivity (higher = more movement required)
#endif

#ifndef VOLUME_THRESHOLD
#define VOLUME_THRESHOLD 1  // Threshold for triggering volume change
#endif 

#ifndef DEADZONE
#define DEADZONE 0.25 // Movement distance for which mouse input will be ignored.
#endif

#ifndef MAXIMUM_ACCELERATION_ZONE
#define MAXIMUM_ACCELERATION_ZONE 200.0f
#endif

static float deadzone;
static float maximum_acceleration_zone;

void pointing_device_init_user(void){
  deadzone = DEADZONE;
  maximum_acceleration_zone = MAXIMUM_ACCELERATION_ZONE;
  if(deadzone < 0 || deadzone >= maximum_acceleration_zone){
    print("Wrong DEADZONE or MAXIMUM_ACCELERATION_ZONE variable setup")
    deadzone = 0.25;
    maximum_acceleration_zone = 200.0f; 
  }
   set_auto_mouse_layer(_MOUSE_LAYER); // only required if AUTO_MOUSE_DEFAULT_LAYER is not set to index of <mouse_layer>
   set_auto_mouse_enable(true);         // always required before the auto mouse feature will work
   pointing_device_set_cpi(TRACKPAD_DEFAULT_DPI);
}

static float aux_dpi = 0;
static bool set_scrolling = false;
static bool accel_off = false;

static float scroll_divisor_h = SCROLL_DIVISOR_H_BASE;
static float scroll_divisor_v = SCROLL_DIVISOR_V_BASE;

// Variables to store accumulated scroll values
static float scroll_accumulated_h = 0;
static float scroll_accumulated_v = 0;
// -------
// VOLUME CONTROL WITH TRACKPAD
// Define how sensitive the trackpad is for volume control


// Variables to store accumulated volume movement
static float volume_accumulated_v = 0;

bool process_trackpad(uint16_t keycode, keyrecord_t *record){
 switch (keycode) {
  case TG_SCROL:
    if (record->event.pressed) {
      // logic when pressed
      set_scrolling = !set_scrolling;
    }
    return false;

  case K_SCROL:
    if (record->event.pressed) {
      set_scrolling = true;
    } else {
      set_scrolling = false;
    }
    return false;
  case K_SNIPE: /* Decrease trackpad DPI*/
    if (record->event.pressed) {
      if (get_mods() == MOD_BIT(KC_LCTL)) {
        unregister_mods(MOD_BIT_LCTRL);
        alt_tab_menu = true;
        SEND_STRING(SS_DOWN(X_LALT));
        tap_code(KC_TAB);
        wait_ms(5);
        SEND_STRING(SS_UP(X_LALT));
      } else if (set_scrolling || IS_LAYER_ON(_F_KEYS)) {
        aux_dpi = pointing_device_get_cpi();
        pointing_device_set_cpi(200);
        scroll_divisor_h =  SCROLL_DIVISOR_H_BASE * 2.0;
        scroll_divisor_v =  SCROLL_DIVISOR_V_BASE * 2.0;
      } else {
        pointing_device_set_cpi(pointing_device_get_cpi()-300);
      }
    } else {
      if (set_scrolling || IS_LAYER_ON(_F_KEYS)) {
        pointing_device_set_cpi(aux_dpi);
        scroll_divisor_h = SCROLL_DIVISOR_H_BASE;
        scroll_divisor_v = SCROLL_DIVISOR_V_BASE;
      } else {
        if (alt_tab_menu == true) {
          alt_tab_menu = false;
        } else {
          pointing_device_set_cpi(pointing_device_get_cpi()+300);
        }
      }
    }
    return false;
case K_BLITZ: /* Decrease trackpad DPI*/
    if (set_scrolling || IS_LAYER_ON(_F_KEYS)) {
      if (record->event.pressed) {
        aux_dpi = pointing_device_get_cpi();
        pointing_device_set_cpi(1000);
        scroll_divisor_h = SCROLL_DIVISOR_H_BASE / 2.0;
        scroll_divisor_v = SCROLL_DIVISOR_V_BASE / 2.0;
      } else {
        pointing_device_set_cpi(aux_dpi);
        scroll_divisor_h = SCROLL_DIVISOR_H_BASE;
        scroll_divisor_v = SCROLL_DIVISOR_V_BASE;
      }
    } else if (record->event.pressed) {
      pointing_device_set_cpi(pointing_device_get_cpi()+300);
    } else {
      pointing_device_set_cpi(pointing_device_get_cpi()-300);
    }
  return false;

case ZOOM_TR:
  if (record->event.pressed) {
      // logic when pressed
      set_scrolling = true;
      SEND_STRING(SS_DOWN(X_LCTL));
      // SEND_STRING(SS_DOWN(X_LSFT));
      // SEND_STRING(SS_DELAY(1));
      // SEND_STRING(SS_TAP(X_T)));
    } else {
      set_scrolling = false;
      SEND_STRING(SS_UP(X_LCTL));
      // SEND_STRING(SS_UP(X_LSFT));
      // logic when released
    }
    // press(MY_LCTL AND MY_LSFT)
    return false;

case DPI_INC: /* Increase trackpad DPI*/
  if (record->event.pressed) {
    pointing_device_set_cpi(pointing_device_get_cpi()+100);
  }
  return false;
case DPI_DEC: /* Decrease trackpad DPI*/
  if (record->event.pressed) {
    pointing_device_set_cpi(pointing_device_get_cpi()-100);
  }
  return false;

case ACEL_OFF:
  if (record->event.pressed) {
    accel_off = true;
    // SEND_STRING(SS_DOWN(X_LCTL));
    // tap_code(KC_TAB);
  } else {
    // SEND_STRING(SS_UP(X_LCTL));
    // ky_webnav = false;
  }
  return false;

case ACEL_ON:
  if (record->event.pressed) {
    accel_off = false;
  }
      }
  
  return true;
}
// Smoothening and acceleration functions

static report_mouse_t process_trackpad_report(report_mouse_t mouse_report) {
    float accel_factor = 1.0f;
    // Check if _REG_SPE layer is active (for volume control)
    if (IS_LAYER_ON(_REG_SPE)) {
        volume_accumulated_v += (float)mouse_report.y / VOLUME_DIVISOR;
        if (volume_accumulated_v >= VOLUME_THRESHOLD) {
            tap_code(KC_VOLD);
            volume_accumulated_v = 0;
        } else if (volume_accumulated_v <= -VOLUME_THRESHOLD) {
            tap_code(KC_VOLU);
            volume_accumulated_v = 0;
        }

        mouse_report.x = 0;
        mouse_report.y = 0;

    } else if (set_scrolling || IS_LAYER_ON(_F_KEYS)) {
        scroll_accumulated_h += (float)mouse_report.x / scroll_divisor_h;
        scroll_accumulated_v += (float)mouse_report.y / scroll_divisor_v;

        mouse_report.h = (int8_t)scroll_accumulated_h;
        mouse_report.v = -(int8_t)scroll_accumulated_v;

        scroll_accumulated_h -= (int8_t)scroll_accumulated_h;
        scroll_accumulated_v -= (int8_t)scroll_accumulated_v;

        mouse_report.x = 0;
        mouse_report.y = 0;

    } else {

        // 1) mild anti-jitter "deadzone feel" on tiny movements
        xy_filter_apply(&mouse_report);
        accel_factor = acceleration_factor(mouse_report.x, mouse_report.y, !accel_off);
        int scaled_x = (int)((float)mouse_report.x * accel_factor);
        int scaled_y = (int)((float)mouse_report.y * accel_factor);

        if (scaled_x > 127) scaled_x = 127;
        if (scaled_x < -127) scaled_x = -127;
        if (scaled_y > 127) scaled_y = 127;
        if (scaled_y < -127) scaled_y = -127;

        mouse_report.x = (int8_t)scaled_x;
        mouse_report.y = (int8_t)scaled_y;
    }

    return mouse_report;
}

report_mouse_t pointing_device_task_combined_user(report_mouse_t left_report, report_mouse_t right_report) {
    left_report  = process_trackpad_report(left_report);
    right_report = process_trackpad_report(right_report);
    return pointing_device_combine_reports(left_report, right_report);
}




// ===============================
// Piecewise accel inspired by your "good" version
// - deadzone hard under dz
// - dz->m1 eased (smooth start/end)
// - m1->m2 linear
// - m2->m3 linear
// ===============================

static float acceleration_factor(int8_t x, int8_t y, bool accelerate){
  float mag = distance((float) x, (float) y);

  if(mag < deadzone) return 0.0f;
  if(mag < maximum_acceleration_zone && accelerate) {
    mag = (mag - DEADZONE)/(MAXIMUM_ACCELERATION_ZONE - DEADZONE);
    return smoothstep(mag);
  }
  return 1.0f;
}
// ===============================
// "Deadzone feel" via small-motion accumulator (very mild)
// ===============================
// IMPORTANT: keep this mild, otherwise it feels like glue.
// Apply only to tiny deltas (anti-jitter), not to normal movement.

static inline void xy_filter_apply(report_mouse_t *r) {
    static float xy_accum_x = 0.0f;
    static float xy_accum_y = 0.0f;
    float mag = distance((float) r->x, (float) r->y);
    if (mag <= XY_FILTER_MAG_THRESHOLD) {
        xy_accum_x += (float)r->x / XY_FILTER_DIVISOR;
        xy_accum_y += (float)r->y / XY_FILTER_DIVISOR;

        int8_t out_x = (int8_t)xy_accum_x;
        int8_t out_y = (int8_t)xy_accum_y;

        xy_accum_x -= (float)out_x;
        xy_accum_y -= (float)out_y;

        r->x = out_x;
        r->y = out_y;
    } else {
        // Reset to avoid delayed "leftover" after a fast move
        xy_accum_x = 0.0f;
        xy_accum_y = 0.0f;
    }
}

// ===============================
// TRACKPAD report processing
// ===============================


// Split + POINTING_DEVICE_COMBINED builds:

