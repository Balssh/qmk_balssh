/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

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

#include QMK_KEYBOARD_H

enum layers {
    BASE,
    MED,
    NAV,
    MOUS,
    SYM,
    NUM,
    FUN,
};

// The "magic" key is the Alternate Repeat Key.
#define MAGIC QK_AREP
// F20 mutes the mic on my system.
// #define MUTEMIC KC_F20

// Short aliases for home row mods and other tap-hold keys.
#define HRM_N LGUI_T(KC_N)
#define HRM_R LALT_T(KC_R)
#define HRM_T LCTL_T(KC_T)
#define HRM_S LSFT_T(KC_S)

#define HRM_H RSFT_T(KC_H)
#define HRM_A RCTL_T(KC_A)
#define HRM_E RALT_T(KC_E)
#define HRM_I LGUI_T(KC_I)

#define LT_MED LT(MED, KC_TAB)
#define LT_NAV LT(NAV, KC_ESC)
#define LT_MOUS LT(MOUS, KC_SPC)
#define LT_SYM LT(SYM, KC_ENT)
#define LT_NUM LT(NUM, KC_BSPC)
#define LT_FUN LT(FUN, KC_DEL)

// Defining the layers
// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT_split_3x6_3(
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        XXXXXXX,    KC_B,    KC_L,    KC_D,    KC_W,    KC_Z,                         KC_J,    KC_F,    KC_O,    KC_U,   KC_QUOT,  XXXXXXX,
        //|-------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--+-----|
        XXXXXXX,    HRM_N,   HRM_R,   HRM_T,   HRM_S,   KC_G,                         KC_Y,    HRM_H,   HRM_A,   HRM_E,  HRM_I,    XXXXXXX,
        //|-------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--+-----|
        XXXXXXX,    KC_Q,    KC_X,    KC_M,    KC_C,    KC_V,                         KC_K,    KC_P,    KC_COMM, KC_DOT, KC_SLSH,  XXXXXXX,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                            LT_MED,   LT_NAV,  LT_MOUS,     LT_SYM,   LT_NUM, LT_FUN
                                            //`--------------------------'  `--------------------------'
    ),

    [MED] = LAYOUT_split_3x6_3(
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                            KC_LGUI, XXXXXXX,  KC_SPC,     KC_ENT, XXXXXXX,   QK_LLCK
                                            //`--------------------------'  `--------------------------'
    ),

    [NAV] = LAYOUT_split_3x6_3(
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        XXXXXXX,  XXXXXXX,   XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+-------|
        XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, XXXXXXX,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+-------|
        XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX, KC_HOME, KC_PGDN, KC_PGUP, KC_END, XXXXXXX,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                            QK_LLCK,   XXXXXXX,  KC_SPC,     KC_ENT, KC_BSPC, KC_DEL
                                            //`--------------------------'  `--------------------------'
    ),

    [MOUS] = LAYOUT_split_3x6_3(
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, MS_LEFT, MS_DOWN, MS_UP, MS_RGHT, XXXXXXX,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, MS_WHLL, MS_WHLD, MS_WHLU, MS_WHLR, XXXXXXX,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                            QK_LLCK, XXXXXXX,  KC_SPC,     MS_BTN2, MS_BTN1, MS_BTN3
                                            //`--------------------------'  `--------------------------'
    ),

    [SYM] = LAYOUT_split_3x6_3(
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT, XXXXXXX, XXXXXXX,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_LEFT, KC_DOWN,   KC_UP, KC_RIGHT, XXXXXXX, XXXXXXX,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                            KC_LGUI, XXXXXXX,  KC_SPC,     KC_ENT,   MO(3), QK_LLCK
                                            //`--------------------------'  `--------------------------'
    ),

    [NUM] = LAYOUT_split_3x6_3(
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        XXXXXXX, KC_PAST,  KC_7, KC_8,  KC_9, KC_PPLS,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        XXXXXXX, LSFT(KC_5), KC_4, KC_5, KC_6, KC_PEQL,                    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        XXXXXXX, KC_PSLS, KC_1, KC_2, KC_3, KC_PMNS,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                            XXXXXXX,   KC_0,  KC_SPC,     KC_ENT, XXXXXXX, QK_LLCK
                                            //`--------------------------'  `--------------------------'
    ),

    [FUN] = LAYOUT_split_3x6_3(
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        XXXXXXX, KC_F12,  KC_F7, KC_F8,  KC_F9, KC_PSCR,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        XXXXXXX, KC_F11, KC_F4, KC_F5, KC_F6, XXXXXXX,                    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        XXXXXXX, KC_F10, KC_F1, KC_F2, KC_F3, XXXXXXX,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                            XXXXXXX,   KC_0,  KC_SPC,     KC_ENT, XXXXXXX, QK_LLCK
                                            //`--------------------------'  `--------------------------'
    ),

};
// clang-format on

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] =
        {
            ENCODER_CCW_CW(KC_VOLD, KC_VOLU),
            ENCODER_CCW_CW(KC_MPRV, KC_MNXT),
            ENCODER_CCW_CW(RM_VALD, RM_VALU),
            ENCODER_CCW_CW(KC_RGHT, KC_LEFT),
        },
    [1] =
        {
            ENCODER_CCW_CW(KC_VOLD, KC_VOLU),
            ENCODER_CCW_CW(KC_MPRV, KC_MNXT),
            ENCODER_CCW_CW(RM_VALD, RM_VALU),
            ENCODER_CCW_CW(KC_RGHT, KC_LEFT),
        },
    [2] =
        {
            ENCODER_CCW_CW(KC_VOLD, KC_VOLU),
            ENCODER_CCW_CW(KC_MPRV, KC_MNXT),
            ENCODER_CCW_CW(RM_VALD, RM_VALU),
            ENCODER_CCW_CW(KC_RGHT, KC_LEFT),
        },
    [3] =
        {
            ENCODER_CCW_CW(KC_VOLD, KC_VOLU),
            ENCODER_CCW_CW(KC_MPRV, KC_MNXT),
            ENCODER_CCW_CW(RM_VALD, RM_VALU),
            ENCODER_CCW_CW(KC_RGHT, KC_LEFT),
        },
};
#endif
