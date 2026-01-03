#ifndef ENUM_H_
#define ENUM_H_



#define _ACCENTS_RANGE \
 Y(HT_E)\
 Y(HT_A)\
 Y(HT_U)\
 Y(HT_I)\
 X(MY_CEDIL)\
 X(MY_OCIRC)


#define _CHAR_SPECIAUX_RANGE \
 X(MY_SLH)\
 X(MY_BSLH)\
 X(MY_DOLL)\
 X(MY_DIESE)\
 X(MY_EURO)\
 X(MY_TILD)\
 X(MY_BQUOT)\
 X(MY_BQUOT2)\
 X(MY_PIPE)

#define _OFFICE_RANGE \
 X(MY_PRT_S)\
 X(MY_PRT_P)\
 X(MY_COPY)\
 X(MY_CUT)\
 X(MY_PASTE)\
 X(MY_UNDO)\
 X(MY_REDO)\
 X(MY_SAVE)\
 X(MY_COMENT)\
 X(SEL_ALL)

#define _WEB_RANGE \
 X(AUX_WEB)\
 X(WEB_D)\
 X(WEB_G)\
 X(WEB_DUP)\
 X(WEB_TAB)\
 X(FF_FENE)\
 Y(FF_T_ST)

#define _NUMPAG_RANGE \
 X(KY_P1)\
 X(KY_P2)\
 X(KY_P3)\
 X(KY_P5)\
 X(KY_P8)\
 X(MY_NAV_FROM_OP)

#define _GAMING_RANGE \
 X(TG_GAME)\
 Y(APEX_I)\
 Y(APEX_CTL)


#define X(x) x,
#define Y(y) 
enum custom_keycodes{
  STARTER=SAFE_RANGE,
  _CHAR_SPECIAUX_RANGE
  _OFFICE_RANGE
  _WEB_RANGE
  _NUMPAG_RANGE
  _GAMING_RANGE
  CSTM_ENT,
  HT_SPC,
  MY_ALT_T,
  };
#undef X
#undef Y



#endif // ENUM_H_
