#include QMK_KEYBOARD_H
#include "enum.h"

static void render_layer_status(void) {
  #define X(a,b) b,
  static const char* impression[]= {_LAYERS 0};
  oled_write(impression[get_highest_layer(layer_state)], false);
  }

static void render_logo(void) {
  static const char PROGMEM logo[] = {
    // 'cornia', 32x32px
  255,255,255,255,255,255,255,255,63,223,239,255,255,255,255,255,255,255,255,255,255,239,223,63,255,255,255,255,255,255,255,255,255,255,255,127,127,63,31,0,0,15,31,55,123,123,249,249,249,249,123,123,51,31,15,0,0,31,63,63,127,255,255,255,255,243,248,252,254,255,255,227,143,63,254,254,252,252,254,31,31,238,252,252,254,254,63,143,227,255,255,254,254,248,243,255,255,255,255,255,255,255,255,191,191,191,158,157,141,199,195,224,224,195,199,141,157,158,191,191,191,255,255,255,255,255,255,255  };
  oled_write_raw_P(logo, sizeof(logo));
}

// oled_rotation_t oled_init_user(oled_rotation_t rotation) { return OLED_ROTATION_270; }

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_left()) {
        return OLED_ROTATION_0;
    } else {
        return OLED_ROTATION_180;
    }
}

bool oled_task_user() {
  oled_set_cursor(0, 0);
  render_logo();
  oled_set_cursor(0, 7);
  render_layer_status();
  return false;
}

void oled_render_boot(bool bootloader) {
  oled_clear();
  oled_set_cursor(0, 2);
  if (bootloader) {
    oled_write_P(PSTR("FLASH"), false);
  } else {
    oled_write_P(PSTR("RESET"), false);
  }
  oled_render_dirty(true);
}



