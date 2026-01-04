#pragma once

enum layers{
    _DEBUGLAYER,
    _COLEMAK_FR,
    _REG_QWERTY,
    _RGB
};

#define _I__MOD RGB_MOD
#define _D_RMOD RGB_RMOD
#define __I_LUM RGB_VAI
#define __D_LUM RGB_VAD
#define _I_COUL RGB_HUI
#define _D_COUL RGB_HUD
#define __I_SAT RGB_SAI
#define __D_SAT RGB_SAD
#define __I_VIT RGB_SPI
#define __D_VIT RGB_SPD


// custom independant definitions

#define MY_COPY LCTL(KC_C)
#define MY__CUT LCTL(KC_X)
#define MY_PAST LCTL(KC_V)
#define MY_UNDO LCTL(FR_Z) // because french keyboard OS
#define MY_REDO LCTL(KC_Y)
#define MY_SAVE LCTL(KC_S)
#define SEL_ALL LCTL(FR_A) // because french keyboard OS

