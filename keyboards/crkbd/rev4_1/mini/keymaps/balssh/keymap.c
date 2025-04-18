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

#include "custom_shift_keys.h"
#include "keycodes.h"
#include "keymap_us.h"
#include "quantum_keycodes.h"
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
enum custom_keycodes {
    ARROW = SAFE_RANGE,
    SRCHSEL,
    RGBNEXT,
    RGBHUP,
    RGBHRND,
    // Macros invoked through the Magic key.
    M_DOCSTR,
    M_EQEQ,
    M_INCLUDE,
    M_ION,
    M_MENT,
    M_MKGRVS,
    M_QUEN,
    M_THE,
    M_TMENT,
    M_UPDIR,
    M_NBSP,
    M_NOOP,
};
const custom_shift_key_t custom_shift_keys[] = {};
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
    [BASE] = LAYOUT_split_3x6_3_ex2(
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        XXXXXXX,    KC_B,    KC_L,    KC_D,    KC_W,    KC_Z, XXXXXXX,               XXXXXXX, KC_J,    KC_F,    KC_O,    KC_U,   KC_QUOT,  XXXXXXX,
        //|-------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--+-----|
        XXXXXXX,    HRM_N,   HRM_R,   HRM_T,   HRM_S,   KC_G, XXXXXXX,               XXXXXXX, KC_Y,    HRM_H,   HRM_A,   HRM_E,  HRM_I,    XXXXXXX,
        //|-------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--+-----|
        XXXXXXX,    KC_Q,    KC_X,    KC_M,    KC_C,    KC_V,                                 KC_K,    KC_P,    KC_COMM, KC_DOT, KC_SLSH,  XXXXXXX,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                            LT_MED,   LT_NAV,  LT_MOUS,     LT_SYM,   LT_NUM, LT_FUN
                                            //`--------------------------'  `--------------------------'
    ),

    [MED] = LAYOUT_split_3x6_3_ex2(
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,              XXXXXXX, LUMINO, KC_MPLY, KC_MPRV, KC_MNXT, XXXXXXX, XXXXXXX,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,              XXXXXXX, RGBHRND, KC_MUTE, KC_VOLD, KC_VOLU, XXXXXXX, XXXXXXX,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                RGBNEXT, RGBHUP, KC_BRID, KC_BRIU, XXXXXXX, XXXXXXX,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                            KC_LGUI, XXXXXXX,  KC_SPC,     KC_ENT, XXXXXXX,   QK_LLCK
                                            //`--------------------------'  `--------------------------'
    ),

    [NAV] = LAYOUT_split_3x6_3_ex2(
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,         XXXXXXX, XXXXXXX,  C(KC_H), C(KC_K), C(KC_J), C(KC_L), XXXXXXX,
        //|--------+--------+--------+--------+--------+--------|                      |--------+--------+--------+--------+--------+-------|
        XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,         XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, XXXXXXX,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+-------|
        XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                          XXXXXXX, KC_HOME, KC_PGDN, KC_PGUP, KC_END, XXXXXXX,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
        QK_LLCK,   XXXXXXX,  KC_SPC,     KC_ENT, KC_BSPC, KC_DEL
        //`--------------------------'  `--------------------------'
    ),

    [MOUS] = LAYOUT_split_3x6_3_ex2(
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,               XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,               XXXXXXX, XXXXXXX, MS_LEFT, MS_DOWN, MS_UP, MS_RGHT, XXXXXXX,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                 XXXXXXX, MS_WHLL, MS_WHLD, MS_WHLU, MS_WHLR, XXXXXXX,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
        QK_LLCK, XXXXXXX,  KC_SPC,     MS_BTN2, MS_BTN1, MS_BTN3
        //`--------------------------'  `--------------------------'
    ),

    [SYM] = LAYOUT_split_3x6_3_ex2(
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        XXXXXXX, KC_GRV, KC_LBRC, KC_RBRC, KC_EXLM, KC_BSLS, XXXXXXX,               XXXXXXX, XXXXXXX, KC_CIRC, KC_DLR, KC_PERC, XXXXXXX, XXXXXXX,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        XXXXXXX, KC_ASTR, KC_LPRN, KC_RPRN, KC_AT, KC_EQL, XXXXXXX,               XXXXXXX, XXXXXXX, KC_LSFT, KC_QUOT, KC_DQT, XXXXXXX,  XXXXXXX,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        XXXXXXX, KC_SLASH, KC_LT, KC_GT, KC_HASH, KC_AMPR,                                  XXXXXXX, KC_SCLN, KC_COMM, KC_DOT, KC_COLN, XXXXXXX,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                            QK_LLCK, KC_MINS,  KC_SPC,      XXXXXXX,   XXXXXXX, XXXXXXX
                                            //`--------------------------'  `--------------------------'
    ),

    [NUM] = LAYOUT_split_3x6_3_ex2(
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        XXXXXXX, KC_PERC,  KC_7, KC_8,  KC_9, KC_PPLS,  XXXXXXX,                    XXXXXXX, XXXXXXX, KC_DOWN, KC_UP, XXXXXXX, XXXXXXX, XXXXXXX,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        XXXXXXX, KC_ASTR, KC_4, KC_5, KC_6, KC_PEQL, XXXXXXX      ,                 XXXXXXX, XXXXXXX, KC_LSFT, KC_RCTL, KC_RALT, KC_RGUI, XXXXXXX,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        XXXXXXX, KC_SLSH, KC_1, KC_2, KC_3, KC_PMNS,                                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                            QK_LLCK,   KC_0,  KC_SPC,           XXXXXXX, XXXXXXX, XXXXXXX
                                            //`--------------------------'  `--------------------------'
    ),

    [FUN] = LAYOUT_split_3x6_3_ex2(
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        XXXXXXX, KC_F12,  KC_F7, KC_F8,  KC_F9, KC_PSCR,      XXXXXXX,                XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        XXXXXXX, KC_F11, KC_F4, KC_F5, KC_F6, XXXXXXX, XXXXXXX,                    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        XXXXXXX, KC_F10, KC_F1, KC_F2, KC_F3, XXXXXXX,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
        XXXXXXX,   KC_0,  KC_SPC,     KC_ENT, XXXXXXX, QK_LLCK
        //`--------------------------'  `--------------------------'
    ),

};
// clang-format on

#ifdef CHORDAL_HOLD
// Handedness for Chordal Hold.
// clang-format off
const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM =
    LAYOUT_split_3x6_3_ex2(
        //,-----------------------------------------------------.           ,-----------------------------------------------------.
        'L', 'L', 'L', 'L', 'L', 'L', 'L',                                      'R','R', 'R', 'R', 'R', 'R', 'R',
        //|--------+--------+--------+--------+--------+--------|           |--------+--------+--------+--------+--------+--------|
        'L', 'L', 'L', 'L', 'L', 'L',  'L',                                      'R','R', 'R', 'R', 'R', 'R', 'R',
        //|--------+--------+--------+--------+--------+--------|           |--------+--------+--------+--------+--------+--------|
        'L', 'L', 'L', 'L', 'L', 'L',                                               'R', 'R', 'R', 'R', 'R', 'R',
        //|--------+--------+--------+--------+--------+--------|           |--------+--------+--------+--------+--------+--------|
                                            'L', 'L', 'L',                      'R', 'R', 'R'
                                            //`--------------------------'  `--------------------------'
    );
#endif  // CHORDAL_HOLD
// clang-format on

// A cheap pseudorandom generator.
static uint8_t myrand(void) {
    static uint16_t state = 1;
#ifdef __CHIBIOS__ // Use high-res timer on ChibiOS.
    state += (uint16_t)chVTGetSystemTimeX();
#else
    state += timer_read();
#endif
    state *= UINT16_C(36563);
    return state >> 8;
}

///////////////////////////////////////////////////////////////////////////////
// RGB Matrix Lighting (https://docs.qmk.fm/features/rgb_matrix)
///////////////////////////////////////////////////////////////////////////////
#if RGB_MATRIX_ENABLE
static void lighting_set_palette(uint8_t palette) {
    if (lumino_get_value() == 0) {
        lumino_cycle_3_state();
    }
    rgb_matrix_enable_noeeprom();
    rgb_matrix_sethsv_noeeprom(RGB_MATRIX_HUE_STEP * palette, 255, rgb_matrix_get_val());
}

static void lighting_preset(uint8_t effect, uint8_t palette) {
    lighting_set_palette(palette);
    rgb_matrix_mode_noeeprom(effect);
    rgb_matrix_set_speed_noeeprom(100);
}
#endif // RGB_MATRIX_ENABLE

void keyboard_post_init_user(void) {
#if RGB_MATRIX_ENABLE
    lighting_preset(RGB_MATRIX_CUSTOM_PALETTEFX_FLOW + (myrand() % 4), myrand());
#endif // RGB_MATRIX_ENABLE

    // Play MUSHROOM_SOUND two seconds after init, if defined and audio enabled.
#if defined(AUDIO_ENABLE) && defined(MUSHROOM_SOUND)
    uint32_t play_init_song_callback(uint32_t trigger_time, void* cb_arg) {
        static float init_song[][2] = SONG(MUSHROOM_SOUND);
        PLAY_SONG(init_song);
        return 0;
    }
    defer_exec(2000, play_init_song_callback, NULL);
#endif // defined(AUDIO_ENABLE) && defined(MUSHROOM_SOUND)
}

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    const uint8_t mods       = get_mods();
    const uint8_t all_mods   = (mods | get_weak_mods());
    const uint8_t shift_mods = all_mods & MOD_MASK_SHIFT;

    if (record->event.pressed) {
        switch (keycode) {
                // case UPDIR:
                //   SEND_STRING_DELAY("../", TAP_CODE_DELAY);
                //   return false;

                // case STDCC:
                //   SEND_STRING_DELAY("std::", TAP_CODE_DELAY);
                //   return false;

                // case ARROW:  // Unicode arrows -> => <-> <=> through Shift and Alt.
                //   send_unicode_string(alt ? (shift_mods
                //                               ? "\xe2\x87\x94"     // <=>
                //                               : "\xe2\x86\x94")    // <->
                //                            : (shift_mods
                //                               ? "\xe2\x87\x92"     // =>
                //                               : "\xe2\x86\x92"));  // ->
                //   return false;

            case KC_RABK:
                if (shift_mods) { // Shift + > types a happy emoji.
                    static const char* emojis[] = {
                        "\xf0\x9f\xa5\xb3", // Party hat.
                        "\xf0\x9f\x91\x8d", // Thumbs up.
                        "\xe2\x9c\x8c",     // Victory hand.
                        "\xf0\x9f\xa4\xa9", // Star eyes.
                        "\xf0\x9f\x94\xa5", // Fire.
                        "\xf0\x9f\x8e\x89", // Party popper.
                        "\xf0\x9f\x91\xbe", // Purple alien.
                        "\xf0\x9f\x98\x81", // Grin.
                    };
                    const int NUM_EMOJIS = sizeof(emojis) / sizeof(*emojis);

                    // Pick an index between 0 and NUM_EMOJIS - 2.
                    uint8_t index = ((NUM_EMOJIS - 1) * myrand()) >> 8;
                    // Don't pick the same emoji twice in a row.
                    static uint8_t last_index = 0;
                    if (index >= last_index) {
                        ++index;
                    }
                    last_index = index;

                    // Produce the emoji.
                    send_unicode_string(emojis[index]);
                    return false;
                }
                return true;

                // Macros invoked through the MAGIC key.
                // case M_THE:
                //     MAGIC_STRING(/* */ "the", KC_N);
                //     break;
                // case M_ION:
                //     MAGIC_STRING(/*i*/ "on", KC_S);
                //     break;
                // case M_MENT:
                //     MAGIC_STRING(/*m*/ "ent", KC_S);
                //     break;
                // case M_QUEN:
                //     MAGIC_STRING(/*q*/ "uen", KC_C);
                //     break;
                // case M_TMENT:
                //     MAGIC_STRING(/*t*/ "ment", KC_S);
                //     break;
                // case M_UPDIR:
                //     MAGIC_STRING(/*.*/ "./", UPDIR);
                //     break;
                // case M_INCLUDE:
                //     SEND_STRING_DELAY(/*#*/ "include ", TAP_CODE_DELAY);
                //     break;
                // case M_EQEQ:
                //     SEND_STRING_DELAY(/*=*/"==", TAP_CODE_DELAY);
                //     break;
                // case M_NBSP:
                //     SEND_STRING_DELAY(/*&*/ "nbsp;", TAP_CODE_DELAY);
                //     break;
                //
                // case M_DOCSTR:
                //     SEND_STRING_DELAY(/*"*/ "\"\"\"\"\"" SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT), TAP_CODE_DELAY);
                //     break;
                // case M_MKGRVS:
                //     SEND_STRING_DELAY(/*`*/ "``\n\n```" SS_TAP(X_UP), TAP_CODE_DELAY);
                //     break;

#if RGB_MATRIX_ENABLE
            case RGBNEXT:
                if (shift_mods) {
                    rgb_matrix_step_reverse_noeeprom();
                } else {
                    rgb_matrix_step_noeeprom();
                }
                break;

            case RGBHUP:
                if (shift_mods) {
                    rgb_matrix_decrease_hue_noeeprom();
                } else {
                    rgb_matrix_increase_hue_noeeprom();
                }
                break;

            case RGBHRND:
                lighting_set_palette(myrand());
                break;
#endif // RGB_MATRIX_ENABLE
        }
    }

    return true;
}
