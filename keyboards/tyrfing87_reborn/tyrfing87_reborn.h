/*
Copyright 2024 Vaarai

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include "quantum.h"

/* This a shortcut to help you visually see your layout.
 *
 * The first section contains all of the arguments representing the physical
 * layout of the board and position of the keys.
 *
 * The second converts the arguments into a two-dimensional array which
 * represents the switch matrix.
 */

#define LAYOUT( \
    KC_0_00,          KC_0_01, KC_0_02, KC_0_03, KC_0_04, KC_0_05, KC_0_06, KC_0_07, KC_0_08, KC_0_09, KC_0_10, KC_0_11, KC_0_12,    KC_6_03, KC_6_04, KC_6_06, \
    KC_1_00, KC_1_01, KC_1_02, KC_1_03, KC_1_04, KC_1_05, KC_1_06, KC_1_07, KC_1_08, KC_1_09, KC_1_10, KC_1_11, KC_1_12, KC_5_12,    KC_6_07, KC_6_08, KC_6_09, \
    KC_2_00, KC_2_01, KC_2_02, KC_2_03, KC_2_04, KC_2_05, KC_2_06, KC_2_07, KC_2_08, KC_2_09, KC_2_10, KC_2_11, KC_2_12, KC_3_12,    KC_6_10, KC_6_11, KC_6_12, \
    KC_3_00, KC_3_01, KC_3_02, KC_3_03, KC_3_04, KC_3_05, KC_3_06, KC_3_07, KC_3_08, KC_3_09, KC_3_10, KC_3_11,          KC_4_12,                               \
    KC_4_00,          KC_4_01, KC_4_02, KC_4_03, KC_4_04, KC_4_05, KC_4_06, KC_4_07, KC_4_08, KC_4_09, KC_4_10,          KC_4_11,             KC_5_11,          \
    KC_5_00, KC_5_01, KC_5_02,                   KC_5_03,                            KC_5_04, KC_5_05, KC_5_06, KC_5_07,             KC_5_08, KC_5_09, KC_5_10  \
) { \
    { KC_0_00, KC_0_01, KC_0_02, KC_0_03, KC_0_04, KC_0_05, KC_0_06, KC_0_07, KC_0_08, KC_0_09, KC_0_10, KC_0_11, KC_0_12 }, \
    { KC_1_00, KC_1_01, KC_1_02, KC_1_03, KC_1_04, KC_1_05, KC_1_06, KC_1_07, KC_1_08, KC_1_09, KC_1_10, KC_1_11, KC_1_12 }, \
    { KC_2_00, KC_2_01, KC_2_02, KC_2_03, KC_2_04, KC_2_05, KC_2_06, KC_2_07, KC_2_08, KC_2_09, KC_2_10, KC_2_11, KC_2_12 }, \
    { KC_3_00, KC_3_01, KC_3_02, KC_3_03, KC_3_04, KC_3_05, KC_3_06, KC_3_07, KC_3_08, KC_3_09, KC_3_10, KC_3_11, KC_3_12 }, \
    { KC_4_00, KC_4_01, KC_4_02, KC_4_03, KC_4_04, KC_4_05, KC_4_06, KC_4_07, KC_4_08, KC_4_09, KC_4_10, KC_4_11, KC_4_12 }, \
    { KC_5_00, KC_5_01, KC_5_02, KC_5_03, KC_5_04, KC_5_05, KC_5_06, KC_5_07, KC_5_08, KC_5_09, KC_5_11, KC_5_10, KC_5_12 }, \
    { KC_NO,   KC_NO,   KC_NO,   KC_6_03, KC_6_04, KC_NO,   KC_6_06, KC_6_07, KC_6_08, KC_6_09, KC_6_10, KC_6_11, KC_6_12 }, \
}
