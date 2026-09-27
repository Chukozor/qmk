#ifndef RGB_GAMING_H
#define RGB_GAMING_H
#include QMK_KEYBOARD_H
bool rgb_matrix_indicators_user(void);

// LEDs dont la luminosité doit être augmentée de 75%, quel que soit l'effet
// RGB Matrix actif (digital_rain, breathing, couleur gaming fixe, etc.).
// Défini dans rgb_gaming.c, réutilisé par rgb_matrix_custom_driver.c pour
// appliquer le boost au niveau du driver, en dessous de tous les effets.
extern const uint8_t boosted_leds[];
extern const uint8_t boosted_leds_count;
bool is_boosted_led(uint8_t index);

#endif