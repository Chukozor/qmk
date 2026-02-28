#include QMK_KEYBOARD_H
#include "enum.h"
#include <string.h>

// =====================================================================
// 32x32 logo (128 bytes) stored as 4 pages of 32 bytes (each page = 8px tall)
// =====================================================================
static const uint8_t PROGMEM logo_cornia_32x32[] = {
    0, 0, 0, 0, 0, 0, 0, 0, 192, 32, 16, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 16, 32, 192, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 128, 128, 192, 224, 255, 255, 240, 224, 200, 132, 132, 6, 6,
    6, 6, 132, 132, 204, 224, 240, 255, 255, 224, 192, 192, 128, 0, 0, 0,
    0, 12, 7, 3, 1, 0, 0, 28, 112, 192, 1, 1, 3, 3, 1, 224,
    224, 17, 3, 3, 1, 1, 192, 112, 28, 0, 0, 1, 3, 7, 12, 0,
    0, 0, 0, 0, 0, 0, 0, 64, 64, 64, 97, 98, 114, 56, 60, 31,
    31, 60, 56, 114, 98, 97, 64, 64, 64, 0, 0, 0, 0, 0, 0, 0
};

// =====================================================================
// Screen layout (128x32):
// - 16 text cols total (each = 8px)
// - 4 text rows total (each = 8px)
// Logo is 32px wide => 4 text cols
// We'll start text at col 5 (1 col gap) => 11 cols remain
// =====================================================================
#define TEXT_COL_START 5
#define TEXT_ROW       1
#define TEXT_MAX_COLS  11

static void render_logo_left(void) {
    // Draw 32x32 as 4 slices (pages) of 32 bytes each
    // Page 0..3, each page is 8px tall
    for (uint8_t page = 0; page < 4; page++) {
        oled_set_cursor(0, page);

        // each slice is 32 bytes wide (32 columns)
        const uint8_t *slice = logo_cornia_32x32 + (page * 32);

        // oled_write_raw_P expects const char*, cast to avoid pointer-sign -Werror
        oled_write_raw_P((const char *)slice, 32);
    }
}

static void render_highest_layer_next_to_logo(void) {
#   define X(a,b) b,
    static const char *layer_names[] = { _LAYERS 0 };
#   undef X

    const char *src = layer_names[get_highest_layer(layer_state)];

    // fixed-width (11 chars) clipped/padded
    char buf[TEXT_MAX_COLS + 1];
    memset(buf, ' ', TEXT_MAX_COLS);
    buf[TEXT_MAX_COLS] = '\0';

    size_t n = strlen(src);
    if (n > TEXT_MAX_COLS) n = TEXT_MAX_COLS;
    memcpy(buf, src, n);

    // clear that line area then write
    oled_set_cursor(TEXT_COL_START, TEXT_ROW);
    oled_write_P(PSTR("           "), false); // 11 spaces
    oled_set_cursor(TEXT_COL_START, TEXT_ROW);
    oled_write(buf, false);
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return is_keyboard_left() ? OLED_ROTATION_0 : OLED_ROTATION_180;
}

bool oled_task_user(void) {
    // no oled_clear() to avoid flicker
    render_logo_left();
    render_highest_layer_next_to_logo();
    return false;
}

void oled_render_boot(bool bootloader) {
    oled_clear();
    oled_set_cursor(0, 1);
    oled_write_P(bootloader ? PSTR("FLASH") : PSTR("RESET"), false);
    oled_render_dirty(true);
}