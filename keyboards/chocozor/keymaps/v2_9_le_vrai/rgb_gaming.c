#include "rgb_gaming.h"
#include "enum.h"

// To light up the whole board instead of just the WARS cluster, comment out
// this define (or comment it back in to go back to the per-key version).
#define GAMING_RGB_WARS_ONLY

// W, A, R, S move keys of the _GAME layout (matrix [1,2] [2,1] [2,2] [2,3]),
// translated to RGB matrix LED indices via v2_9_folder/keyboard.json's
// rgb_matrix.layout table.
static const uint8_t wars_leds[] = {15, 10, 9, 8};

static void set_gaming_color(uint8_t hue) {
    HSV hsv = {hue, 255, rgb_matrix_get_val()};
    RGB rgb = hsv_to_rgb(hsv);

#ifdef GAMING_RGB_WARS_ONLY
    for (uint8_t i = 0; i < sizeof(wars_leds); ++i) {
        rgb_matrix_set_color(wars_leds[i], rgb.r, rgb.g, rgb.b);
    }
#else
    rgb_matrix_set_color_all(rgb.r, rgb.g, rgb.b);
#endif
}

bool rgb_matrix_indicators_user(void) {
    switch (get_highest_layer(layer_state)) {
        case _GAME:
            set_gaming_color(0); // red
            break;
        case _GAME_QWERTY:
            set_gaming_color(28); // orange
            break;
        case _AUX_GAME:
            set_gaming_color(170); // blue
            break;
    }
    return true;
}