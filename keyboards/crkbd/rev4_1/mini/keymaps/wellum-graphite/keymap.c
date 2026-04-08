/*
 * Wellum-inspired keymap for CrKBD graphite layout
 * Based on braindefender/wellum but adapted for 6-column CrKBD
 * No home row mods - uses one-shot modifiers instead
 */

#include "keycodes.h"
#include "keymap_us.h"
#include QMK_KEYBOARD_H
#include "oneshot.h"
#include "swapper.h"

#define ___ KC_NO
#define __ KC_TRNS
#define RESET QK_BOOT

#define LA_SYM MO(_SYM)
#define LA_ALT MO(_ALT)
#define LA_NAV MO(_NAV)
#define LA_CMD MO(_CMD)
#define LA_MOUS MO(_MOUS)
#define LA_MED MO(_MED)
#define LA_NUM MO(_NUM)
#define LA_FUN MO(_FUN)
#define LA_GFN MO(_GFN)

#define LT_MED LT(_MED, KC_TAB)
#define LT_NAV LT(_NAV, KC_ESC)
#define LT_MOUS LT(_MOUS, KC_SPC)
#define LT_SYM LT(_SYM, KC_ENT)
#define LT_NUM LT(_NUM, KC_BSPC)
#define LT_FUN LT(_FUN, KC_DEL)

#define SPACE_L C(G(KC_LEFT))
#define SPACE_R C(G(KC_RGHT))
#define TAB_L C(S(KC_TAB))
#define TAB_R C(KC_TAB)

enum layers {
    _DEF,
    _BASE,
    _GAM,
    _GFN,
    _MED,
    _MOUS,
    _FUN,
    _NAV,
    _SYM,
    _NUM,
    _CMD,
};

enum keycodes {
    OS_SHFT = SAFE_RANGE,
    OS_CTRL,
    OS_ALT,
    OS_CMD,

    SW_WIN,
    SW_TAB,

    RGBNEXT,
    RGBHUP,
    RGBHRND,
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_split_3x5_3_ex2(
        KC_B,   KC_L,   KC_D,     KC_W,     KC_Z,      __,   __,   KC_J,     KC_F,     KC_O,      KC_U,     KC_QUOT,
        KC_N,   KC_R,   KC_T,     KC_S,     KC_G,      __,   __,   KC_Y,     KC_H,     KC_A,      KC_E,     KC_I,
        KC_Q,   KC_X,   KC_M,     KC_C,     KC_V,                  KC_K,     KC_P,     KC_COMM,   KC_DOT,   KC_SLSH,
                        LT_MED,   LT_NAV,   LT_MOUS,               LT_SYM,   LT_NUM,   LT_FUN
    ),

    [_GAM] = LAYOUT_split_3x5_3_ex2(
        KC_TAB,     KC_Q,       KC_W,       KC_E,       KC_R,       __, __,     ___,        ___,        KC_UP,      ___,        KC_TAB,
        KC_LSFT,    KC_A,       KC_S,       KC_D,       KC_F,       __, __,     ___,        KC_LEFT,    KC_DOWN,    KC_RGHT,    KC_RSFT,
        KC_LCTL,    KC_Z,       KC_X,       KC_C,       KC_V,                   ___,        ___,        ___,        ___,        KC_RCTL,
                                KC_LALT,    KC_SPC,     LA_GFN,                 DF(_DEF),   KC_SPC,     KC_PSCR
    ),

    [_GFN] = LAYOUT_split_3x5_3_ex2(
        KC_5,       KC_1,       KC_2,       KC_3,       KC_4,       __, __,     KC_NUM,     ___,        ___,        ___,        ___,
        KC_0,       KC_6,       KC_7,       KC_8,       KC_9,       __, __,     ___,        ___,        ___,        ___,        ___,
        KC_G,       KC_J,       KC_I,       KC_M,       KC_T,                   ___,        ___,        ___,        QK_RBT,     QK_BOOT,
                                KC_ESC,     KC_ENT,     _______,                _______,    _______,    _______
    ),

    [_SYM] = LAYOUT_split_3x5_3_ex2(
        KC_GRV,     KC_LBRC,    KC_RBRC,    KC_EXLM,    KC_BSLS,    __, __,     _______,    KC_DLR,     KC_PERC,    KC_COLN,    _______,
        KC_ASTR,    KC_LPRN,    KC_RPRN,    KC_AT,      KC_EQL,     __, __,     KC_PLUS,    OS_SHFT,    OS_CTRL,    OS_ALT,     OS_CMD,
        KC_CIRC,    KC_LT,      KC_GT,      KC_HASH,    KC_AMPR,                KC_MINS,    KC_RBRC,    KC_COMMA,   _______,    _______,
                                _______,    _______,    _______,                _______,    _______,    _______
    ),


    [_NAV] = LAYOUT_split_3x5_3_ex2(
        SW_TAB,     SW_WIN,     TAB_L,      TAB_R,      KC_ESC,     __, __,     KC_ESC,     _______,    _______,    _______,    _______,
        OS_CMD,     OS_ALT,     OS_CTRL,    OS_SHFT,    KC_ENT,     __, __,     KC_ENT,     KC_LEFT,    KC_DOWN,    KC_UP,      KC_RGHT,
        SPACE_L,    SPACE_R,    DF(_GAM),   KC_PSCR,    KC_TAB,                 KC_TAB,     KC_HOME,    KC_PGDN,    KC_PGUP,    KC_END,
                                LA_CMD,     _______,    _______,                _______,    _______,    _______
    ),

    [_NUM] = LAYOUT_split_3x5_3_ex2(
        KC_P1,      KC_P2,      KC_P3,      KC_P4,      KC_P5,      __, __,     KC_P6,      KC_P7,      KC_P8,      KC_P9,      KC_P0,
        OS_CMD,     OS_ALT,     OS_CTRL,    OS_SHFT,    KC_F11,     __, __,     KC_F12,     OS_SHFT,    OS_CTRL,    OS_ALT,     OS_CMD,
        KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,                  KC_F6,      KC_F7,      KC_F8,      KC_F9,      KC_F10,
                                _______,    _______,    _______,                _______,    _______,    _______
    ),

    [_CMD] = LAYOUT_split_3x5_3_ex2(
        MEH(KC_Q),  MEH(KC_W),  MEH(KC_E),  MEH(KC_R),  MEH(KC_T),  __, __,  MEH(KC_Y),  KC_VOLD,    KC_MUTE,       KC_VOLU,     MEH(KC_P),
        MEH(KC_A),  MEH(KC_S),  MEH(KC_D),  MEH(KC_F),  MEH(KC_G),  __, __,  MEH(KC_H),  KC_MPRV,    KC_MPLY,       KC_MNXT,     MEH(KC_SCLN),
        MEH(KC_Z),  MEH(KC_X),  MEH(KC_C),  MEH(KC_V),  MEH(KC_B),          MEH(KC_N),  MEH(KC_M),  MEH(KC_COMM),  MEH(KC_DOT), MEH(KC_SLSH),
                                _______,    _______,    _______,             KC_LGUI,    _______,    _______
    )
    // [_MED] = LAYOUT_split_3x6_3_ex2(
    //     //,-----------------------------------------------------.                    ,-----------------------------------------------------.
    //             __, __, __, __, __, __, __,                                                 __, LUMINO, KC_MPLY, KC_MPRV, KC_MNXT, __, __,
    //     //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+-----|
    //             __, __, __, __, __, __, __,                                                 __, RGBHRND, KC_MUTE, KC_VOLD, KC_VOLU, __, __,
    //     //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+-----|
    //             __, __, __, __, __, __,                                                         RGBNEXT, RGBHUP, KC_BRID, KC_BRIU, __, __,
    //     //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
    //                                             KC_LGUI, __, KC_SPC,            KC_ENT, __, QK_LLCK),
    //
    // [_NAV] = LAYOUT_split_3x6_3_ex2(
    //     //,-----------------------------------------------------.                    ,-----------------------------------------------------.
    //             __, SW_TAB, SW_WIN, TAB_L, TAB_R, KC_ESC, __,                                __, KC_ESC, KC_HOME, KC_END, KC_BSPC, KC_DEL, __,
    //     //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+-----|
    //             __, OS_GUI, OS_ALT, OS_CTRL, OS_SHFT, KC_ENT, __,                            __, KC_ENT, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, __,
    //     //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+-----|
    //             __, SPACE_L, SPACE_R, __, KC_PSCR, KC_TAB,                                      KC_TAB, KC_PGUP, KC_PGDN, KC_QUOT, XXXXXXX, __,
    //     //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
    //                                             KC_LGUI, __, KC_SPC,            KC_ENT, KC_BSPC, KC_DEL),
    //
    // [_MOUS] = LAYOUT_split_3x6_3_ex2(
    //     //,-----------------------------------------------------.                    ,-----------------------------------------------------.
    //             __, __, __, __, __, __, __, __,                                             __, __, __, __, __, __,
    //     //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+-----|
    //             __, __, __, __, __, __, __, __,                                             __, MS_LEFT, MS_DOWN, MS_UP, MS_RGHT, __,
    //     //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+-----|
    //             __, __, __, __, __, __, __,                                                     MS_WHLL, MS_WHLD, MS_WHLU, MS_WHLR, __,
    //     //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
    //                                             QK_LLCK, __, KC_SPC,            MS_BTN2, MS_BTN1, MS_BTN3),
    //
    // [_SYM] = LAYOUT_split_3x6_3_ex2(
    //     //,-----------------------------------------------------.                    ,-----------------------------------------------------.
    //             __, KC_GRV, KC_LBRC, KC_RBRC, KC_EXLM, KC_BSLS, __, __, __, KC_CIRC, KC_DLR, KC_PERC, __, __,
    //     //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+-----|
    //             __, KC_ASTR, KC_LPRN, KC_RPRN, KC_AT, KC_EQL, __, __, __, KC_LSFT, KC_QUOT, KC_DQT, __, __,
    //     //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+-----|
    //             __, KC_SLASH, KC_LT, KC_GT, KC_HASH, KC_AMPR, __, KC_SCLN, KC_COMM, KC_DOT, KC_COLN, __,
    //     //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
    //                                             QK_LLCK, KC_MINS, KC_SPC, __, __, __),
    //
    // [_NUM] = LAYOUT_split_3x6_3_ex2(
    //     //,-----------------------------------------------------.                    ,-----------------------------------------------------.
    //             __, KC_PERC, KC_7, KC_8, KC_9, KC_PPLS, __, __, __, KC_DOWN, KC_UP, __, __, __,
    //     //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+-----|
    //             __, KC_ASTR, KC_4, KC_5, KC_6, KC_PEQL, __, __, __, KC_LSFT, KC_RCTL, KC_RALT, KC_RGUI, __,
    //     //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+-----|
    //             __, KC_SLSH, KC_1, KC_2, KC_3, KC_PMNS, __, __, __, __, __, __,
    //     //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
    //                                             QK_LLCK, KC_0, KC_SPC, __, __, __),
    //
    // [_FUN] = LAYOUT_split_3x6_3_ex2(
    //     //,-----------------------------------------------------.                    ,-----------------------------------------------------.
    //             __, KC_F12, KC_F7, KC_F8, KC_F9, KC_PSCR, __, __, __, __, __, __, __, __,
    //     //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+-----|
    //             __, KC_F11, KC_F4, KC_F5, KC_F6, __, __, __, __, __, __, __, __, __,
    //     //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+-----|
    //             __, KC_F10, KC_F1, KC_F2, KC_F3, __, __, __, __, __, __, __,
    //     //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
    //                                              __, KC_0, KC_SPC, KC_ENT, __, QK_LLCK),
};

// clang-format on

bool is_oneshot_cancel_key(uint16_t keycode) {
    switch (keycode) {
        case LA_SYM:
        case LA_NAV:
            return true;
        default:
            return false;
    }
}

bool is_oneshot_ignored_key(uint16_t keycode) {
    switch (keycode) {
        case LA_SYM:
        case LA_NAV:
        case KC_LSFT:
        case OS_SHFT:
        case OS_CTRL:
        case OS_ALT:
        case OS_CMD:
            return true;
        default:
            return false;
    }
}

bool sw_win_active = false;
bool sw_tab_active = false;

oneshot_state os_shft_state = os_up_unqueued;
oneshot_state os_ctrl_state = os_up_unqueued;
oneshot_state os_alt_state  = os_up_unqueued;
oneshot_state os_gui_state  = os_up_unqueued;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    update_swapper(&sw_win_active, KC_LALT, KC_TAB, SW_WIN, OS_SHFT, keycode, record);
    update_swapper(&sw_tab_active, KC_LCTL, KC_TAB, SW_TAB, OS_SHFT, keycode, record);

    update_oneshot(&os_shft_state, KC_LSFT, OS_SHFT, keycode, record);
    update_oneshot(&os_ctrl_state, KC_LCTL, OS_CTRL, keycode, record);
    update_oneshot(&os_alt_state, KC_LALT, OS_ALT, keycode, record);
    update_oneshot(&os_gui_state, KC_LGUI, OS_CMD, keycode, record);

    return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _SYM, _NAV, _NUM);
}

void keyboard_post_init_user(void) {
#ifdef RGB_MATRIX_ENABLE
    rgb_matrix_enable_noeeprom();
#endif
}
