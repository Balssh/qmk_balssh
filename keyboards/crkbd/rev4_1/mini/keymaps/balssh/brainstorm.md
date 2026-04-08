# What I like currently

- graphite layout (might fool around with graphyre)
- homerow mods when they work
- the sym layer, especially brackets
- a bit of the nav and mouse layer

# What I dislike currently

- homerow mods when they don't work
- : is VERY annoying to hit
- num layer as a numpad still feels off
- many duplicated symbols (eg ', /)
- med and fun layer almost unused
- would like to try magic and/or repeat keys
- no game layer

# Possible improvements:

1. Using combos for syms
    `(lb)  [(dl) \](dw)  !(wz) \(rem)          ^ $ %
    *(nr)  ((rt)  )(ts)  @(gs) =(rem)           '(rem) "(rem) 
    /(rem) <(xm)  >(mc)  #(vc) &          ;(rem) ,(rem) .(rem) :(rem)
                                -(rem)
    in theory i could get ; and : from some tap dancing , and . (or maybe some combos related to them)
              / could be replace with a tap hold for \ 
```c
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
    [CT_CLN] = ACTION_TAP_DANCE_TAP_HOLD(KC_COLN, KC_SCLN),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    tap_dance_action_t *action;
    tap_dance_state_t* state;

    switch (keycode) {
        case TD(CT_CLN):
            action = tap_dance_get(QK_TAP_DANCE_GET_INDEX(keycode));
            state = tap_dance_get_state(QK_TAP_DANCE_GET_INDEX(keycode));
            if (!record->event.pressed && state != NULL && state->count && !state->finished) {
                tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
                tap_code16(tap_hold->tap);
            }
    }
    return true;
}```
        after this i could fit ^$% into the left side with combos
2. Add magic key -> kinda fits to trying graphyre
3. homerow mods should be ameliorated by urob's timeless config
4. NUM and MOUSE layers should be moved to smart layers
5. GAME layer can be copied from wellum's conf
6. med and fun layer can probably be compacted into 1 (i don't even use fun layer that much)
7. could try orbital mouse setup
8. could use the extra keys for like vol control
