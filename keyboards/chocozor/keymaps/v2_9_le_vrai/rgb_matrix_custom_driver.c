// Driver RGB Matrix "custom", adapté à L'API WS2812 de CETTE version de QMK
// (ws2812_setleds() qui pousse tout le buffer d'un coup, contrairement aux
// versions plus récentes de QMK qui exposent un ws2812_set_color() par LED).
//
// Ce fichier reproduit fidèlement la logique de
// quantum/rgb_matrix/rgb_matrix_drivers.c (buffer local rgb_led_t, gestion du
// split RGB_MATRIX_SPLIT, "dirty flag" pour n'envoyer que si ça a changé),
// en ajoutant UNE SEULE différence : le boost de luminosité +75% sur les LEDs
// listées dans boosted_leds (rgb_gaming.c), appliqué juste avant l'écriture
// dans le buffer. Comme TOUS les effets RGB Matrix (digital_rain, breathing,
// couleur fixe gaming, etc.) passent obligatoirement par ce point avant
// l'envoi physique aux LEDs, le boost s'applique quel que soit l'effet actif
// et quelle que soit la couche.
//
// Nécessite dans rules.mk :
//   RGB_MATRIX_DRIVER = custom
//   WS2812_DRIVER_REQUIRED = yes
//   WS2812_DRIVER = vendor
//   SRC += rgb_matrix_custom_driver.c

#include "rgb_matrix_drivers.h"
#include "ws2812.h"
#include "rgb_gaming.h" // pour is_boosted_led()
#include "keyboard.h"   // pour is_keyboard_left()
#include "util.h"       // pour ARRAY_SIZE
#include <stdint.h>
#include <stdbool.h>

// ws2812.h ne définit WS2812_LED_COUNT que si RGB_MATRIX_WS2812 est actif ;
// or on utilise RGB_MATRIX_DRIVER=custom, donc c'est désormais
// RGB_MATRIX_CUSTOM qui est défini, et ws2812.h ne fixe jamais cette macro.
// On la définit donc nous-mêmes, avec la même valeur que ws2812.h aurait
// utilisée (RGB_MATRIX_LED_COUNT).
#ifndef WS2812_LED_COUNT
#    define WS2812_LED_COUNT RGB_MATRIX_LED_COUNT
#endif

// Buffer local de couleurs, un par LED (même rôle que rgb_matrix_ws2812_array
// dans le rgb_matrix_drivers.c d'origine).
static rgb_led_t custom_ws2812_array[WS2812_LED_COUNT];
static bool      custom_ws2812_dirty = false;

static void custom_init(void) {
    ws2812_init();
    custom_ws2812_dirty = false;
}

static void custom_flush(void) {
    if (custom_ws2812_dirty) {
        ws2812_setleds(custom_ws2812_array, WS2812_LED_COUNT);
        custom_ws2812_dirty = false;
    }
}

// Écrit une LED dans le buffer, en appliquant le boost +75% si elle fait
// partie de boosted_leds, AVANT le test "dirty" et l'écriture.
static inline void custom_setled(int i, uint8_t r, uint8_t g, uint8_t b) {
#if defined(RGB_MATRIX_SPLIT)
    // Reprend exactement la logique split de rgb_matrix_drivers.c : chaque
    // moitié du clavier ne traite que les indices qui la concernent.
    const uint8_t k_rgb_matrix_split[2] = RGB_MATRIX_SPLIT;
    if (!is_keyboard_left()) {
        if (i >= k_rgb_matrix_split[0]) {
            i -= k_rgb_matrix_split[0];
        } else {
            return;
        }
    } else if (i >= k_rgb_matrix_split[0]) {
        return;
    }
#endif

    if (is_boosted_led((uint8_t)i)) {
        uint16_t rr = (uint16_t)r * 175 / 100;
        uint16_t gg = (uint16_t)g * 175 / 100;
        uint16_t bb = (uint16_t)b * 175 / 100;
        if (rr > 255) rr = 255;
        if (gg > 255) gg = 255;
        if (bb > 255) bb = 255;
        r = (uint8_t)rr;
        g = (uint8_t)gg;
        b = (uint8_t)bb;
    }

    if (custom_ws2812_array[i].r == r && custom_ws2812_array[i].g == g && custom_ws2812_array[i].b == b) {
        return;
    }

    custom_ws2812_dirty      = true;
    custom_ws2812_array[i].r = r;
    custom_ws2812_array[i].g = g;
    custom_ws2812_array[i].b = b;
}

static void custom_setled_all(uint8_t r, uint8_t g, uint8_t b) {
    for (int i = 0; i < WS2812_LED_COUNT; i++) {
        custom_setled(i, r, g, b);
    }
}

const rgb_matrix_driver_t rgb_matrix_driver = {
    .init          = custom_init,
    .flush         = custom_flush,
    .set_color     = custom_setled,
    .set_color_all = custom_setled_all,
};