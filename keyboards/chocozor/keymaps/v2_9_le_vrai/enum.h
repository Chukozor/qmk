#ifndef ENUM_H_
#define ENUM_H_
#include QMK_KEYBOARD_H

//constantes

extern bool trace_operations; 


#define _LAYERS \
  X(_COLEMAK_FR,   "      COLEMAK      ")\
  X(_GAME,         "        GAME       ")\
  X(_GAME_QWERTY,  "    GAME  QWERTY   ")\
  X(_AUX_GAME,     "     AUX  GAME     ")\
  X(_CAPS_LOCK,    "     CAPS_LOCK     ")\
  X(_F_KEYS,       "      F_  KEYS     ")\
  X(_NUMPAD_RIGHT, "   NUMPAD  RIGHT   ")\
  X(_NAV,          "       NAV         ")\
  X(_OPERATIONS,   "    OPERATEURS     ")\
  X(_WEB_BROWSER,  "       WEB_        ")\
  X(_MOUSE_LAYER,  "      MOUSE        ")\
  X(_ACCENTS,      "     ACCENTS       ")\
  X(_REG_SPE,      "     REG _SPE      ")\
  X(_MULTIMEDIA,   "    MULTIMEDIA     ")\
  X(_RGB,          "       RGB         ")

// AJOUT: Texte court pour affichage en gros sur l'OLED jusqu'à 7 lettres
#define _LAYERS_BIG \
  X(_COLEMAK_FR,   " COLMAK")\
  X(_GAME,         "  GAME ")\
  X(_GAME_QWERTY,  "GAMEQWE")\
  X(_AUX_GAME,     "AUXGAME")\
  X(_CAPS_LOCK,    "  CAPS ")\
  X(_F_KEYS,       " F_KEYS")\
  X(_NUMPAD_RIGHT, "  NUM  ")\
  X(_NAV,          "  NAV  ")\
  X(_OPERATIONS,   " OPERAT")\
  X(_WEB_BROWSER,  "  WEB  ")\
  X(_MOUSE_LAYER,  " MOUSE ")\
  X(_ACCENTS,      "ACCENTS")\
  X(_REG_SPE,      "REG_SPE")\
  X(_MULTIMEDIA,   " MEDIA ")\
  X(_RGB,          "  RGB  ")

#define X(a,b) a,
enum layers{
 _LAYERS
};
#undef X

#define _ACCENTS_RANGE \
 Y(HT_E)\
 Y(HT_A)\
 Y(HT_U)\
 Y(HT_I)\
 X(MY_CEDIL)\
 X(MY_OCIRC)

#define HT_E     TT(16)
#define HT_A     TT(17)
#define HT_U     TT(18)
#define HT_I     TT(19)


//Characteres speciaux
#define MY_SLH LSFT(KC_DOT)
#define MY_BSLH RALT(KC_8)
#define MY_DOLL KC_RBRC
#define MY_DIESE RALT(KC_3)
#define MY_EURO RALT(KC_E)
// #define MY_TILD RALT(KC_2)
#define MY_BQUOT RALT(KC_7)
#define MY_PIPE RALT(KC_6)
#define ____SUP S(KC_NUBS)
#define ____INF KC_NUBS
#define TG_NUMP KC_NUM
#define __MOINS KC_PMNS
#define ___PLUS KC_PPLS
#define ___FOIS KC_PAST
#define _DIVISE KC_PSLS
#define __EQUAL KC_EQL
#define ___CIRC ALGR(KC_9)
#define _BACKSL ALGR(KC_8)

//Office

#define MY_PRT_S KC_PSCR
#define MY_PRT_P LSFT(KC_PSCR)
#define MY_PRT_Z RCTL(KC_PSCR)
#define MY_COMENT LCTL(KC_DOT)
#define MY_COPY LCTL(KC_C)
#define MY_CUT LCTL(KC_X)
#define MY_PASTE LCTL(KC_V)
#define MY_UNDO LCTL(FR_Z)
#define MY_REDO LCTL(KC_Y)
#define MY_SAVE LCTL(KC_S)
#define SEL_ALL LCTL(FR_A)

#define _WEB_RANGE \
 X(AUX_WEB)\
 X(WEB_D)\
 X(WEB_G)\
 X(WEB_DUP)\
 Y(WEB_TAB)\
 Y(FF_FENE)\
 Y(FF_T_ST)

#define WEB_TAB TT(20)
#define FF_T_ST  TT(21)
#define FF_FENE TT(22)
#define TABTO_L RCS(KC_PGUP)
#define TABTO_R RCS(KC_PGDN)
#define BOOKMAR C(KC_D)
#define THEBOOK RCS(KC_O)
#define OPENBOOK RCS(KC_O)
#define PRIVATE RCS(KC_P)
#define MO_OP MO(_OPERATIONS)

#define _NUMPAD_RANGE \
 X(KY_P1)\
 X(KY_P2)\
 X(KY_P3)\
 X(KY_P5)\
 X(KY_P8)\
 X(NAV_F_OP)

#define _GAMING_RANGE \
 X(TG_GAME)\
 X(TG_GAME_QWERTY)\
 Y(APEX_I)\
 Y(APEX_CTL)

#define APEX_I   TT(23)
#define APEX_CTL TT(24)



#define X(x) x,
#define Y(y) 
enum custom_keycodes{
  STARTER=SAFE_RANGE,
  _ACCENTS_RANGE
  _WEB_RANGE
  _NUMPAD_RANGE
  _GAMING_RANGE
  MY_ALT_T,
  DBL_SHIFT,
  K_SNIPE,
  K_BLITZ,
  K_SCROL,
  TG_SCROL,
  ZOOM_TR,
  DPI_INC,
  DPI_DEC,
  ACEL_OFF,
  ACEL_ON,
  MY_BQUOT2,
  MY_TILD,
  SOL_TOG,
  L_ENC,
  L_ENC_BIS,
  };
#undef X
#undef Y

enum combos {
  COMBO_ACTIVE_NUMPAD,
  COMBO_ACTIVE_NUMPAD2,
  COMBO_MULTIMEDIA,
  COMBO_OSM_SHIFT,
  COMBO_CAPSLOCK,
  COMBO_BOOT,
  COMBO_BOOT2,
  TOGGLE_GAME,
  TOGGLE_GAME_QWERTY,
  TOGGLE_WEB,
  COMBO_CLEAR_EEPROM,
  COMBO_WEB,
  COMBO_PRINT_SCREEN,
  COMBO_NUMPAD_RIGHT,
  COMBO_NUMPAD_RIGHT2,
  COMBO_RGB,
  COMBO_QKBOOT1,
  COMBO_QKBOOT2
};

#define HT_SPC LT(_ACCENTS, KC_SPC)
#define MY_ESC  TT(25)
#define CSTM_ENT TT(26)
#define CSTM_WIN TT(27)

#define IMGLASS_CP LCTL(LSFT(KC_C))

#define MY_LCTL KC_LCTL
#define MY_RCTL KC_RCTL
#define MOFKEYS MO(_F_KEYS)
#define MO_WEBBR MO(_WEB_BROWSER)
#define MO_OX_G MO(_AUX_GAME)


//RGB

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



#endif // ENUM_H_