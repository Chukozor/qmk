#include QMK_KEYBOARD_H
#include "enum.h"
#include <string.h>

// ==========================================================
// LOGO 32x32
// ==========================================================
static const uint8_t PROGMEM logo_cornia_32x32[] = {
  0,0,0,0,0,0,0,0,192,32,16,0,0,0,0,0,
  0,0,0,0,0,16,32,192,0,0,0,0,0,0,0,0,
  0,0,0,128,128,192,224,255,255,240,224,200,132,132,6,6,
  6,6,132,132,204,224,240,255,255,224,192,192,128,0,0,0,
  0,12,7,3,1,0,0,28,112,192,1,1,3,3,1,224,
  224,17,3,3,1,1,192,112,28,0,0,1,3,7,12,0,
  0,0,0,0,0,0,0,64,64,64,97,98,114,56,60,31,
  31,60,56,114,98,97,64,64,64,0,0,0,0,0,0,0
};

static void render_logo_left(void) {
    for (uint8_t page = 0; page < 4; page++) {
        oled_set_cursor(0, page);
        const uint8_t *slice = logo_cornia_32x32 + (page * 32);
        oled_write_raw_P((const char *)slice, 32);
    }
}

// ==========================================================
// BIG TEXT x2
// ==========================================================

#define BIG_TEXT_X_PX   40
#define BIG_TEXT_Y_PX   8
#define BIG_TEXT_W_PX   88
#define BIG_TEXT_H_PX   16
#define BIG_TEXT_MAX_CH 7
#define BIG_CHAR_STRIDE 12

static const uint8_t PROGMEM font5x7[][5] = {

    {0x00,0x00,0x00,0x00,0x00}, // space

    // '_'  -> BAS (bits 5 & 6 pour épaisseur)
    {0x60,0x60,0x60,0x60,0x60},

    // '0'..'9'
    {0x3E,0x51,0x49,0x45,0x3E},
    {0x00,0x42,0x7F,0x40,0x00},
    {0x62,0x51,0x49,0x49,0x46},
    {0x22,0x49,0x49,0x49,0x36},
    {0x18,0x14,0x12,0x7F,0x10},
    {0x2F,0x49,0x49,0x49,0x31},
    {0x3E,0x49,0x49,0x49,0x32},
    {0x01,0x71,0x09,0x05,0x03},
    {0x36,0x49,0x49,0x49,0x36},
    {0x26,0x49,0x49,0x49,0x3E},

    // 'A'..'Z'
    {0x7E,0x11,0x11,0x11,0x7E},
    {0x7F,0x49,0x49,0x49,0x36},
    {0x3E,0x41,0x41,0x41,0x22},
    {0x7F,0x41,0x41,0x22,0x1C},
    {0x7F,0x49,0x49,0x49,0x41},
    {0x7F,0x09,0x09,0x09,0x01},
    {0x3E,0x41,0x49,0x49,0x7A},
    {0x7F,0x08,0x08,0x08,0x7F},
    {0x00,0x41,0x7F,0x41,0x00},
    {0x20,0x40,0x41,0x3F,0x01},
    {0x7F,0x08,0x14,0x22,0x41},
    {0x7F,0x40,0x40,0x40,0x40},
    {0x7F,0x02,0x0C,0x02,0x7F},
    {0x7F,0x04,0x08,0x10,0x7F},
    {0x3E,0x41,0x41,0x41,0x3E},
    {0x7F,0x09,0x09,0x09,0x06},
    {0x3E,0x41,0x51,0x21,0x5E},
    {0x7F,0x09,0x19,0x29,0x46},
    {0x46,0x49,0x49,0x49,0x31},
    {0x01,0x01,0x7F,0x01,0x01},
    {0x3F,0x40,0x40,0x40,0x3F},
    {0x1F,0x20,0x40,0x20,0x1F},
    {0x3F,0x40,0x38,0x40,0x3F},
    {0x63,0x14,0x08,0x14,0x63},
    {0x07,0x08,0x70,0x08,0x07},
    {0x61,0x51,0x49,0x45,0x43}
};

static uint8_t glyph_index(char c) {
    if (c == ' ') return 0;
    if (c == '_') return 1;
    if (c >= '0' && c <= '9') return 2 + (c - '0');
    if (c >= 'A' && c <= 'Z') return 12 + (c - 'A');
    return 0;
}

static inline void set_px_16(uint8_t *top, uint8_t *bot, uint8_t x, uint8_t y) {
    if (x >= BIG_TEXT_W_PX || y >= BIG_TEXT_H_PX) return;
    if (y < 8) top[x] |= (1 << y);
    else       bot[x] |= (1 << (y - 8));
}

static void build_big_text_bitmap_x2(const char *s, uint8_t max_chars, uint8_t *top, uint8_t *bot) {
    memset(top, 0, BIG_TEXT_W_PX);
    memset(bot, 0, BIG_TEXT_W_PX);

    for (uint8_t i = 0; i < max_chars && s[i]; i++) {
        uint8_t idx = glyph_index(s[i]);
        uint8_t x0  = i * BIG_CHAR_STRIDE;

        for (uint8_t col = 0; col < 5; col++) {
            uint8_t bits = pgm_read_byte(&font5x7[idx][col]);

            for (uint8_t row = 0; row < 7; row++) {
                if (bits & (1 << row)) {
                    uint8_t y2 = row * 2;

                    for (uint8_t dx = 0; dx < 2; dx++)
                        for (uint8_t dy = 0; dy < 2; dy++)
                            set_px_16(top, bot, x0 + col*2 + dx, y2 + dy);
                }
            }
        }
    }
}

static void render_layer_big_next_to_logo(void) {
    #define X(a,b) b,
    static const char *layer_names_big[] = { _LAYERS_BIG 0 };
    #undef X

    const char *lbl = layer_names_big[get_highest_layer(layer_state)];

    static uint8_t top[BIG_TEXT_W_PX];
    static uint8_t bot[BIG_TEXT_W_PX];

    build_big_text_bitmap_x2(lbl, BIG_TEXT_MAX_CH, top, bot);

    uint8_t col8 = BIG_TEXT_X_PX / 8;
    uint8_t page = BIG_TEXT_Y_PX / 8;

    oled_set_cursor(col8, page);
    oled_write_raw((const char *)top, BIG_TEXT_W_PX);

    oled_set_cursor(col8, page + 1);
    oled_write_raw((const char *)bot, BIG_TEXT_W_PX);
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return is_keyboard_left() ? OLED_ROTATION_0 : OLED_ROTATION_180;
}

bool oled_task_user(void) {
    render_logo_left();
    render_layer_big_next_to_logo();
    return false;
}

void oled_render_boot(bool bootloader) {
    oled_clear();
    oled_set_cursor(0, 1);
    oled_write_P(bootloader ? PSTR("FLASH") : PSTR("RESET"), false);
    oled_render_dirty(true);
}