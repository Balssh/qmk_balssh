#include "keycodes.h"
#include "keymap_us.h"
#include "lumino.h"
#include "orbital_mouse.h"
#include "process_combo.h"
#include "keymap_introspection.h"

#include QMK_KEYBOARD_H

enum { DOT_CLN, COMM_SCLN };

enum layers {
    _BASE,
    _MED,
    _NAV,
    _MOUS,
    _SYM,
    _NUM,
    _FUN,
};
enum custom_keycodes {
    ARROW = SAFE_RANGE,
    SRCHSEL,
    RGBNEXT,
    RGBHUP,
    RGBHRND,
};

enum keycode_aliases {
    // The "magic" key is the Alternate Repeat Key.
    MAGIC = QK_AREP,

    HRM_N = LGUI_T(KC_N),
    HRM_R = LALT_T(KC_R),
    HRM_T = LCTL_T(KC_T),
    HRM_S = LSFT_T(KC_S),

    __  = KC_NO,
    ___ = KC_TRNS,

    HRM_H = RSFT_T(KC_H),
    HRM_A = RCTL_T(KC_A),
    HRM_E = RALT_T(KC_E),
    HRM_I = LGUI_T(KC_I),

    LT_FUN  = LT(_FUN, KC_TAB),
    LT_NAV  = LT(_NAV, KC_ESC),
    LT_MOUS = LT(_MOUS, KC_SPC),
    LT_SYM  = LT(_SYM, KC_ENT),
    NUMWORD = LT(_NUM, KC_BSPC),
    // LT_FUN  = LT(_FUN, KC_DEL),
};

// Defining the layers
// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_split_3x5_3_ex2(
        KC_B,   KC_L,    KC_D,    KC_W,    KC_Z,   __,     __,  KC_J,   KC_F,   KC_O,       KC_U,   KC_QUOT,
        HRM_N,  HRM_R,   HRM_T,   HRM_S,   KC_G,   __,     __,  KC_Y,   HRM_H,  HRM_A,      HRM_E,  HRM_I,
        KC_Q,   KC_X,    KC_M,    KC_C,    KC_V,                KC_K,   KC_P,   TD(COMM_SCLN),    TD(DOT_CLN), KC_SLSH,
                         LT_FUN,  LT_NAV,  LT_MOUS,             KC_ENT, KC_BSPC, KC_DEL
    ),

    [_NUM] = LAYOUT_split_3x5_3_ex2(
        __, KC_PLUS, KC_ASTR, __, __, __,   __, __, __, KC_SLSH, KC_MINS, __,
        KC_6, KC_4, KC_0, KC_2, __, __,     __, __, KC_3, KC_1, KC_5, KC_7,
        __, __, __, KC_8, __,                   __, KC_9, __, __, __,
                       __,  __,  KC_SPC,            ___, ___, ___
    ),

    [_NAV] = LAYOUT_split_3x5_3_ex2(
        __, __, __, __, __, __,         __, __,  C(KC_H), C(KC_K), C(KC_J), C(KC_L),
        __, __, __, __, __, __,         __, __, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT,
        __, __, __, __, __,                 __, KC_HOME, KC_PGDN, KC_PGUP, KC_END,
                __, __,  KC_SPC,        KC_ENT, KC_BSPC, KC_DEL
    ),

    [_MOUS] = LAYOUT_split_3x5_3_ex2(
        __, __, __, __, __, __,         __, __, __, __, __, __,
        __, __, __, __, __, __,         __, __, OM_L, OM_D, OM_U, OM_R,
        __, __, __, __, __,                 __, __, MS_WHLD, MS_WHLU, __,
                __, __,  KC_SPC,       MS_BTN2, MS_BTN1, MS_BTN3
    ),

    [_FUN] = LAYOUT_split_3x5_3_ex2(
        KC_F12, KC_F7, KC_F8, KC_F9, KC_PSCR, __,       __, LUMINO, KC_MPLY, KC_MPRV, KC_MNXT, __,
        KC_F11, KC_F4, KC_F5, KC_F6, KC_WBAK, __,       __, RGBHRND, KC_MUTE, KC_VOLD, KC_VOLU, __,
        KC_F10, KC_F1, KC_F2, KC_F3, KC_WFWD,               RGBNEXT, RGBHUP, KC_BRID, KC_BRIU, __,
                       __, __, __,                    __, __, QK_LLCK
    ),
};
// clang-format on

static bool _num_word_enabled = false;
bool        num_word_enabled(void) {
    return _num_word_enabled;
}
void enable_num_word(void) {
    if (!_num_word_enabled) {
        _num_word_enabled = true;
    }
    layer_on(_NUM);
}
void disable_num_word(void) {
    _num_word_enabled = false;
    layer_off(_NUM);
}
void process_num_word_activation(const keyrecord_t *record) {
    if (!record->event.pressed) {
        return;
    }

    if (num_word_enabled()) {
        _num_word_enabled = false;
    } else {
        enable_num_word();
    }
}

bool process_num_word(uint16_t keycode, const keyrecord_t *record) {
    if (!_num_word_enabled) return true;

    switch (keycode) {
        case QK_MOD_TAP ... QK_MOD_TAP_MAX:
        case QK_LAYER_TAP ... QK_LAYER_TAP_MAX:
        case QK_TAP_DANCE ... QK_TAP_DANCE_MAX:
            if (record->tap.count == 0) return true;
            keycode = keycode & 0xFF;
    }
    switch (keycode) {
        case KC_1 ... KC_0:
        case KC_PERC:
        case KC_COMM:
        case KC_DOT:
        case KC_SLSH:
        case KC_MINS:
        case KC_ASTR:
        case KC_PLUS:
        case KC_COLN:
        case KC_EQL:
        case KC_UNDS:
        case KC_BSPC:
        case KC_X:
        case MAGIC:
        case KC_ENT:
            break;
        case KC_SPC:
            tap_code(KC_SPC);
            disable_num_word();
        default:
            if (record->event.pressed) {
                disable_num_word();
            }
    }
    return true;
}

///////////////////////////////////////////////////////////////////////////////
// Combos (https://docs.qmk.fm/features/combo)
///////////////////////////////////////////////////////////////////////////////
// [SYM] = LAYOUT_split_3x5_3_ex2(
//     KC_GRV, KC_LBRC, KC_RBRC, KC_EXLM, KC_BSLS, __,     __, __, KC_CIRC, KC_DLR, KC_PERC, __,
//     KC_ASTR, KC_LPRN, KC_RPRN, KC_AT, KC_EQL,   __,     __, __, KC_LSFT, KC_QUOT, KC_DQT, __,
//     KC_SLASH, KC_LT, KC_GT, KC_HASH, KC_AMPR,               __, KC_SCLN, KC_COMM, KC_DOT, KC_COLN,
//                      QK_LLCK, KC_MINS,  KC_SPC,             __, __, __
//     ),

const uint16_t combo_grv[] PROGMEM  = {KC_B, KC_L, COMBO_END};
const uint16_t combo_lbrc[] PROGMEM = {KC_L, KC_D, COMBO_END};
const uint16_t combo_rbrc[] PROGMEM = {KC_D, KC_W, COMBO_END};
const uint16_t combo_excl[] PROGMEM = {KC_W, KC_Z, COMBO_END};

const uint16_t combo_astr[] PROGMEM = {HRM_N, HRM_R, COMBO_END};
const uint16_t combo_lprn[] PROGMEM = {HRM_R, HRM_T, COMBO_END};
const uint16_t combo_rprn[] PROGMEM = {HRM_T, HRM_S, COMBO_END};
const uint16_t combo_at[] PROGMEM   = {HRM_S, KC_G, COMBO_END};

const uint16_t combo_perc[] PROGMEM = {KC_Q, KC_X, COMBO_END};
const uint16_t combo_lt[] PROGMEM   = {KC_X, KC_M, COMBO_END};
const uint16_t combo_gt[] PROGMEM   = {KC_M, KC_C, COMBO_END};
const uint16_t combo_hash[] PROGMEM = {KC_C, KC_V, COMBO_END};

const uint16_t combo_circ[] PROGMEM = {KC_W, HRM_S, COMBO_END};
const uint16_t combo_dlr[] PROGMEM  = {HRM_S, KC_C, COMBO_END};

const uint16_t combo_mins[] PROGMEM = {KC_Z, KC_G, COMBO_END};
const uint16_t combo_eq[] PROGMEM   = {KC_G, KC_V, COMBO_END};

const uint16_t combo_quot[] PROGMEM = {KC_L, KC_W, COMBO_END};

const uint16_t combo_numword[] PROGMEM = {KC_BSPC, KC_DEL, COMBO_END};

// clang-format off
combo_t key_combos[] = {
    COMBO(combo_grv, KC_GRV),
    COMBO(combo_lbrc, KC_LBRC),
    COMBO(combo_rbrc, KC_RBRC),
    COMBO(combo_excl, KC_EXLM),
    COMBO(combo_astr, KC_ASTR),
    COMBO(combo_lprn, KC_LPRN),
    COMBO(combo_rprn, KC_RPRN),
    COMBO(combo_at, KC_AT),
    COMBO(combo_perc, KC_PERC),
    COMBO(combo_lt, KC_LT),
    COMBO(combo_gt, KC_GT),
    COMBO(combo_hash, KC_HASH),
    COMBO(combo_circ, KC_CIRC),
    COMBO(combo_dlr, KC_DLR),
    COMBO(combo_mins, KC_MINS),
    COMBO(combo_eq, KC_EQL),
    COMBO(combo_quot, KC_QUOT),
    COMBO(combo_numword, NUMWORD)
};
// clang-format on

#ifdef CHORDAL_HOLD
// Handedness for Chordal Hold.
// clang-format off
const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM =
    LAYOUT_split_3x5_3_ex2(
        'L', 'L', 'L', 'L', 'L', 'L',       'R','R', 'R', 'R', 'R', 'R',
        'L', 'L', 'L', 'L', 'L', 'L',       'R','R', 'R', 'R', 'R', 'R',
        'L', 'L', 'L', 'L', 'L',                'R', 'R', 'R', 'R', 'R',
                  'L', 'L', 'L',                'R', 'R', 'R'
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

typedef struct {
    uint16_t tap;
    uint16_t hold;
    uint16_t held;
} tap_dance_tap_hold_t;

void tap_dance_tap_hold_finished(tap_dance_state_t *state, void *user_data) {
    tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)user_data;

    if (state->pressed) {
        if (state->count == 1
#ifndef PERMISSIVE_HOLD
            && !state->interrupted
#endif
        ) {
            register_code16(tap_hold->hold);
            tap_hold->held = tap_hold->hold;
        } else {
            register_code16(tap_hold->tap);
            tap_hold->held = tap_hold->tap;
        }
    }
}

void tap_dance_tap_hold_reset(tap_dance_state_t *state, void *user_data) {
    tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)user_data;

    if (tap_hold->held) {
        unregister_code16(tap_hold->held);
        tap_hold->held = 0;
    }
}

#define ACTION_TAP_DANCE_TAP_HOLD(tap, hold)                                        \
    {                                                                               \
        .fn        = {NULL, tap_dance_tap_hold_finished, tap_dance_tap_hold_reset}, \
        .user_data = (void *)&((tap_dance_tap_hold_t){tap, hold, 0}),               \
    }

tap_dance_action_t tap_dance_actions[] = {
    [DOT_CLN]   = ACTION_TAP_DANCE_TAP_HOLD(KC_DOT, KC_COLN),
    [COMM_SCLN] = ACTION_TAP_DANCE_TAP_HOLD(KC_COMMA, KC_SCLN),
};

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
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_num_word(keycode, record)) {
        return false;
    }

    const uint8_t       mods       = get_mods();
    const uint8_t       all_mods   = (mods | get_weak_mods());
    const uint8_t       shift_mods = all_mods & MOD_MASK_SHIFT;
    tap_dance_action_t *action;
    tap_dance_state_t  *state;

    if (record->event.pressed) {
        switch (keycode) {
            case NUMWORD:
                process_num_word_activation(record);
                return false;
            case TD(DOT_CLN):
            case TD(COMM_SCLN):
                action = tap_dance_get(QK_TAP_DANCE_GET_INDEX(keycode));
                state  = tap_dance_get_state(QK_TAP_DANCE_GET_INDEX(keycode));
                if (!record->event.pressed && state != NULL && state->count && !state->finished) {
                    tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
                    tap_code16(tap_hold->tap);
                }
                break;
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
