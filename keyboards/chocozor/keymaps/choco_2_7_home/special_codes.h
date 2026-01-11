#ifndef SPECIAL_CODES_H_
#define SPECIAL_CODES_H_
#include QMK_KEYBOARD_H

typedef struct SpecialCode{
  char* linux;
  char* windows;
} SpecialCode;

void special_code_helper(SpecialCode* code);
#endif // SPECIAL_CODES_H_

