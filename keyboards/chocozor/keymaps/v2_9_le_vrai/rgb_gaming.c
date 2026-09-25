#include "rgb_gaming.h"
#include "enum.h"

// To light up the whole board instead of just the WARS cluster, comment out
// this define (or comment it back in to go back to the per-key version).
#define GAMING_RGB_RSTC

static const uint8_t rstc_leds[] = {2, 7, 8, 9};

// W, A, R, S move keys of the _GAME layout (matrix [1,2] [2,1] [2,2] [2,3]),
// translated to RGB matrix LED indices via v2_9_folder/keyboard.json's
// rgb_matrix.layout table.
// static const uint8_t wars_leds[] = {0, 11, 12, 13, 14, 15};

// LEDs dont la luminosité doit être augmentée de 80%
static const uint8_t boosted_leds[] = {12, 13, 14, 15, 16, 17, 30, 31, 32, 33, 34, 35};
static const uint8_t boosted_leds_count = sizeof(boosted_leds);

static bool is_boosted_led(uint8_t index) {
  for (uint8_t i = 0; i < boosted_leds_count; ++i) {
      if (boosted_leds[i] == index) {
          return true;
      }
  }
  return false;
}

static void set_gaming_color(uint8_t hue, uint8_t rstc_hue) {
    uint8_t base_val = rgb_matrix_get_val();

    // Couleur normale
    HSV hsv = {hue, 255, base_val};
    RGB rgb = hsv_to_rgb(hsv);

    // Couleur boostée (+80%, plafonnée à 255)
    uint16_t boosted_val = (uint16_t)base_val * 180 / 100;
    if (boosted_val > 255) boosted_val = 255;
    HSV hsv_boosted = {hue, 255, (uint8_t)boosted_val};
    RGB rgb_boosted = hsv_to_rgb(hsv_boosted);

    // Couleur RSTC
    HSV rstc_hsv = {rstc_hue, 255, base_val};
    RGB rstc_rgb = hsv_to_rgb(rstc_hsv);

  for (uint8_t i = 0; i < 36; ++i) {
      // rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
      // rgb_matrix_set_color_all(rgb.r, rgb.g, rgb.b);
    if (is_boosted_led(i)) {
      rgb_matrix_set_color(i, rgb_boosted.r, rgb_boosted.g, rgb_boosted.b);
    } else {
      rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
    }
  }

#ifdef GAMING_RGB_RSTC
  for (uint8_t i = 0; i < sizeof(rstc_leds); ++i) {
        rgb_matrix_set_color(rstc_leds[i], rstc_rgb.r, rstc_rgb.g, rstc_rgb.b);
  }
#endif
}

bool rgb_matrix_indicators_user(void) {
    switch (get_highest_layer(layer_state)) {
        case _GAME:
            set_gaming_color(85,0); // vert avec RSTC rouge
            break;
        case _GAME_QWERTY:
            set_gaming_color(149,0); // azur avec RSTC rouge
            break;
        case _AUX_GAME:
            set_gaming_color(234,0); // rose saumon avec RSTC rouge
            break;
        case _COLEMAK_FR:
            set_gaming_color(0,0); // Rouge avec RSTC rouge
            break;
        default:
            set_gaming_color(0,0); // Rouge avec RSTC rouge
            break;
    }
    return true;
}