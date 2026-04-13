#include <stdint.h>
#include "color.h"
#include "keymap_introspection.h"
#include "custom_shift_keys.h"
#include "keycodes.h"
#include "keymap_us.h"
#include "lumino.h"
#include "orbital_mouse.h"
#include "process_combo.h"
#include "smart_layers.h"
#include "swapper.h"

#include QMK_KEYBOARD_H

const custom_shift_key_t custom_shift_keys[] = {
    {KC_LPRN, KC_LT}, // Shift ( is <
    {KC_RPRN, KC_GT}, // Shift ) is >
};

enum {
    DOT_CLN,
    COMM_SCLN,
    SLSH_BSLSH,
    NAV_LEFT_TD,
    NAV_RIGHT_TD,
    NAV_UP_TD,
    NAV_DOWN_TD,
    NAV_BSPC_TD,
    NAV_DEL_TD,
    SMART_NUM_TD,
};

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
    NUMWORD,
    SMARTMOUSE,
    SW_WIN,
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

    NAV_LEFT  = TD(NAV_LEFT_TD),
    NAV_RIGHT = TD(NAV_RIGHT_TD),
    NAV_UP    = TD(NAV_UP_TD),
    NAV_DOWN  = TD(NAV_DOWN_TD),
    NAV_BSPC  = TD(NAV_BSPC_TD),
    NAV_DEL   = TD(NAV_DEL_TD),
};

const smart_layer_t smart_layers[] = {
    {NUMWORD, _NUM},
    {SMARTMOUSE, _MOUS},
};

// clang-format off
const smart_layer_break_t smart_layer_breaks[] = {
SMART_LAYER_ALLOW(_NUM,
        KC_1, KC_2, KC_3, KC_4, KC_5,
        KC_6, KC_7, KC_8, KC_9, KC_0,
        KC_PERC, KC_COMM, KC_DOT, KC_SLSH,
        KC_MINS, KC_ASTR, KC_PLUS, KC_COLN,
        KC_EQL, KC_UNDS, KC_BSPC, KC_X,
        MAGIC, KC_ENT
    ),
SMART_LAYER_ALLOW(_MOUS,
        OM_L, OM_D, OM_U, OM_R,
        MS_WHLD, MS_WHLU,
        MS_BTN2, MS_BTN1, MS_BTN3
    ),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_split_3x5_3_ex2(
        KC_B,   KC_L,    KC_D,    KC_W,    KC_Z,   __,     __,  KC_J,   KC_F,   KC_O,       KC_U,   KC_QUOT,
        HRM_N,  HRM_R,   HRM_T,   HRM_S,   KC_G,   __,     __,  KC_Y,   HRM_H,  HRM_A,      HRM_E,  HRM_I,
        KC_Q,   KC_X,    KC_M,    KC_C,    KC_V,                KC_K,   KC_P,   TD(COMM_SCLN),    TD(DOT_CLN), TD(SLSH_BSLSH),
                         LT_FUN,  LT_NAV,  LT_MOUS,             KC_ENT, KC_BSPC, KC_DEL
    ),
    [_NUM] = LAYOUT_split_3x5_3_ex2(
        __, KC_PLUS, KC_ASTR, __, __, __,   __, __, __, KC_SLSH, KC_MINS, __,
        KC_6, KC_4, KC_0, KC_2, __, __,     __, __, KC_3, KC_1, KC_5, KC_7,
        __, __, __, KC_8, __,                   __, KC_9, __, __, __,
                       __,  __,  KC_SPC,            ___, ___, ___
    ),

    [_NAV] = LAYOUT_split_3x5_3_ex2(
        __, LSFT(KC_TAB), SW_WIN, __, __, __,                     __, __,  C(KC_H), C(KC_K), C(KC_J), C(KC_L),
        OSM(MOD_LGUI), OSM(MOD_LALT), OSM(MOD_LCTL), OSM(MOD_LSFT), __, __,  __, __, NAV_LEFT, NAV_DOWN, NAV_UP, NAV_RIGHT,
        __, __, __, __, __,                                              __, KC_HOME, KC_PGDN, KC_PGUP, KC_END,
                __, __,  __,                                         KC_ENT, NAV_BSPC, NAV_DEL
    ),

    [_MOUS] = LAYOUT_split_3x5_3_ex2(
        __, __, __, __, __, __,         __, __, __, __, __, __,
        __, __, __, __, __, __,         __, __, OM_L, OM_D, OM_U, OM_R,
        __, __, __, __, __,                 __, __, MS_WHLD, MS_WHLU, __,
                __, __,  __,       MS_BTN2, MS_BTN1, MS_BTN3
    ),

    [_FUN] = LAYOUT_split_3x5_3_ex2(
        KC_F12, KC_F7, KC_F8, KC_F9, KC_PSCR, __,       __, LUMINO, KC_MPLY, KC_MPRV, KC_MNXT, __,
        LGUI_T(KC_F11), LALT_T(KC_F4), LCTL_T(KC_F5), LSFT_T(KC_F6), KC_WBAK, __,       __, RGBHRND, KC_MUTE, KC_VOLD, KC_VOLU, __,
        KC_F10, KC_F1, KC_F2, KC_F3, KC_WFWD,               RGBNEXT, RGBHUP, KC_BRID, KC_BRIU, __,
                       __, __, __,                    __, __, QK_LLCK
    ),
};
// clang-format on

///////////////////////////////////////////////////////////////////////////////
// Combos (https://docs.qmk.fm/features/combo)
///////////////////////////////////////////////////////////////////////////////

// Left hand
const uint16_t combo_esc[] PROGMEM    = {KC_L, KC_D, COMBO_END};
const uint16_t combo_mouse[] PROGMEM  = {KC_D, KC_W, COMBO_END};
const uint16_t combo_hash[] PROGMEM   = {KC_D, HRM_T, COMBO_END};
const uint16_t combo_at[] PROGMEM     = {KC_L, HRM_R, COMBO_END};
const uint16_t combo_dlr[] PROGMEM    = {KC_W, HRM_S, COMBO_END};
const uint16_t combo_perc[] PROGMEM   = {KC_Z, KC_G, COMBO_END};
const uint16_t combo_tab[] PROGMEM    = {HRM_T, HRM_R, COMBO_END};
const uint16_t combo_leader[] PROGMEM = {HRM_T, HRM_S, COMBO_END};
const uint16_t combo_exlm[] PROGMEM   = {HRM_T, KC_M, COMBO_END};
const uint16_t combo_grv[] PROGMEM    = {HRM_R, KC_X, COMBO_END};
const uint16_t combo_eq[] PROGMEM     = {HRM_S, KC_C, COMBO_END};
const uint16_t combo_tild[] PROGMEM   = {KC_G, KC_V, COMBO_END};
const uint16_t combo_paste[] PROGMEM  = {KC_X, KC_M, COMBO_END};
const uint16_t combo_copy[] PROGMEM   = {KC_M, KC_C, COMBO_END};

// Right hand
const uint16_t combo_bspc[] PROGMEM = {KC_F, KC_O, COMBO_END};
const uint16_t combo_del[] PROGMEM  = {KC_O, KC_U, COMBO_END};
const uint16_t combo_astr[] PROGMEM = {KC_O, HRM_A, COMBO_END};
const uint16_t combo_circ[] PROGMEM = {KC_J, KC_Y, COMBO_END};
const uint16_t combo_plus[] PROGMEM = {KC_F, HRM_H, COMBO_END};
const uint16_t combo_ampr[] PROGMEM = {KC_U, HRM_E, COMBO_END};
const uint16_t combo_lprn[] PROGMEM = {HRM_H, HRM_A, COMBO_END};
const uint16_t combo_rprn[] PROGMEM = {HRM_A, HRM_E, COMBO_END};
const uint16_t combo_quot[] PROGMEM = {HRM_A, TD(COMM_SCLN), COMBO_END};
const uint16_t combo_unds[] PROGMEM = {KC_Y, KC_K, COMBO_END};
const uint16_t combo_mins[] PROGMEM = {HRM_H, KC_P, COMBO_END};
const uint16_t combo_pipe[] PROGMEM = {HRM_E, HRM_I, COMBO_END};
const uint16_t combo_lbrc[] PROGMEM = {KC_P, TD(COMM_SCLN), COMBO_END};
const uint16_t combo_rbrc[] PROGMEM = {TD(COMM_SCLN), TD(DOT_CLN), COMBO_END};

const uint16_t combo_numword[] PROGMEM = {KC_Q, TD(SLSH_BSLSH), COMBO_END};

// clang-format off
combo_t key_combos[] = {
    // Left hand
    COMBO(combo_esc,    LT_NAV),
    COMBO(combo_mouse,  SMARTMOUSE),
    COMBO(combo_hash,   KC_HASH),
    COMBO(combo_at,     KC_AT),
    COMBO(combo_dlr,    KC_DLR),
    COMBO(combo_perc,   KC_PERC),
    COMBO(combo_tab,    LT_FUN),
    COMBO(combo_leader, QK_LEAD),
    COMBO(combo_exlm,   KC_EXLM),
    COMBO(combo_grv,    KC_GRV),
    COMBO(combo_eq,     KC_EQL),
    COMBO(combo_tild,   KC_TILD),
    COMBO(combo_paste,  KC_PASTE),
    COMBO(combo_copy,   KC_COPY),
    // Right hand
    COMBO(combo_bspc,   KC_BSPC),
    COMBO(combo_del,    KC_DEL),
    COMBO(combo_astr,   KC_ASTR),
    COMBO(combo_circ,   KC_CIRC),
    COMBO(combo_plus,   KC_PLUS),
    COMBO(combo_ampr,   KC_AMPR),
    COMBO(combo_lprn,   KC_LPRN),
    COMBO(combo_rprn,   KC_RPRN),
    COMBO(combo_quot,   KC_QUOT),
    COMBO(combo_unds,   KC_UNDS),
    COMBO(combo_mins,   KC_MINS),
    COMBO(combo_pipe,   KC_PIPE),
    COMBO(combo_lbrc,   KC_LBRC),
    COMBO(combo_rbrc,   KC_RBRC),
    // Misc
    COMBO(combo_numword, TD(SMART_NUM_TD)),
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

static bool smart_num_held    = false;
static bool oneshot_num       = false;
static bool oneshot_num_used  = false;

void smart_num_finished(tap_dance_state_t *state, void *user_data) {
    if (state->count == 2) {
        // Double-tap → one-shot num layer
        oneshot_num      = true;
        oneshot_num_used = false;
        layer_on(_NUM);
    } else {
        // Tap → numword (smart layer toggle)
        enable_smart_layer(0);
    }
}

void smart_num_reset(tap_dance_state_t *state, void *user_data) {
    smart_num_held = false;
}

// clang-format off
tap_dance_action_t tap_dance_actions[] = {
    [DOT_CLN] = ACTION_TAP_DANCE_TAP_HOLD(KC_DOT, KC_COLN),
    [COMM_SCLN] = ACTION_TAP_DANCE_TAP_HOLD(KC_COMMA, KC_SCLN),
    [SLSH_BSLSH] = ACTION_TAP_DANCE_TAP_HOLD(KC_SLSH, KC_BSLS),
    [NAV_LEFT_TD] = ACTION_TAP_DANCE_TAP_HOLD(KC_LEFT, KC_HOME),
    [NAV_RIGHT_TD] = ACTION_TAP_DANCE_TAP_HOLD(KC_RIGHT, KC_END),
    [NAV_UP_TD] = ACTION_TAP_DANCE_TAP_HOLD(KC_UP, C(KC_HOME)),
    [NAV_DOWN_TD] = ACTION_TAP_DANCE_TAP_HOLD(KC_DOWN, C(KC_END)),
    [NAV_BSPC_TD] = ACTION_TAP_DANCE_TAP_HOLD(KC_BSPC, C(KC_BSPC)),
    [NAV_DEL_TD] = ACTION_TAP_DANCE_TAP_HOLD(KC_DEL, C(KC_DEL)),
    [SMART_NUM_TD] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, smart_num_finished, smart_num_reset),
};
// clang-format on

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

#if RGB_MATRIX_ENABLE
void smart_layer_set_user(uint8_t layer, bool active) {
    if (active) {
        rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
        if (layer == _NUM) {
            // Cyan for number word mode
            rgb_matrix_sethsv_noeeprom(HSV_CYAN);
        } else if (layer == _MOUS) {
            // Magenta for smart mouse mode
            rgb_matrix_sethsv_noeeprom(HSV_MAGENTA);
        }
    } else {
        lighting_preset(RGB_MATRIX_CUSTOM_PALETTEFX_FLOW + (myrand() % 4), myrand());
    }
}
#endif

static bool sw_win_active = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    update_swapper(&sw_win_active, KC_LALT, KC_TAB, SW_WIN, LSFT(KC_TAB), keycode, record);
    if (sw_win_active && keycode == SW_WIN) return false;

    // Manual one-shot for _NUM: turn off after next non-modifier key press+release
    if (oneshot_num && keycode != TD(SMART_NUM_TD)) {
        bool is_mod = (keycode >= KC_LCTL && keycode <= KC_RGUI);
        if (!is_mod) {
            if (record->event.pressed) {
                oneshot_num_used = true;
            } else if (oneshot_num_used) {
                layer_off(_NUM);
                oneshot_num      = false;
                oneshot_num_used = false;
            }
        }
    }
    const uint8_t mods       = get_mods();
    const uint8_t all_mods   = (mods | get_weak_mods());
    const uint8_t shift_mods = all_mods & MOD_MASK_SHIFT;

    // Handle tap-dance tap-on-release OUTSIDE the pressed guard
    switch (keycode) {
        case TD(DOT_CLN):
        case TD(COMM_SCLN):
        case TD(SLSH_BSLSH):
        case TD(NAV_LEFT_TD):
        case TD(NAV_RIGHT_TD):
        case TD(NAV_UP_TD):
        case TD(NAV_DOWN_TD):
        case TD(NAV_BSPC_TD):
        case TD(NAV_DEL_TD): {
            tap_dance_action_t *action = tap_dance_get(QK_TAP_DANCE_GET_INDEX(keycode));
            tap_dance_state_t  *state  = tap_dance_get_state(QK_TAP_DANCE_GET_INDEX(keycode));
            if (!record->event.pressed && state != NULL && state->count && !state->finished) {
                tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
                tap_code16(tap_hold->tap);
            }
            break;
        }
    }

    if (record->event.pressed) {
        switch (keycode) {
            // case NUMWORD:
            //     process_num_word_activation(record);
            //     return false;
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
