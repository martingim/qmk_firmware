#include QMK_KEYBOARD_H
#if __has_include("keymap.h")
#    include "keymap.h"
#endif

// Define a type for as many tap dance states as you need
typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_TAP
} td_state_t;

typedef struct {
    bool is_press_action;
    td_state_t state;
} td_tap_t;

enum {
    GUI_LAYR, // Our custom tap dance key; add any other tap dance keys to this enum 
};

// Declare the functions to be used with your tap dance key(s)

// Function associated with all tap dances
td_state_t cur_dance(tap_dance_state_t *state);

// Functions associated with individual tap dances
void ql_finished(tap_dance_state_t *state, void *user_data);
void ql_reset(tap_dance_state_t *state, void *user_data);



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
      *     ┌───┬───┬───┬───┬───┐                   ┌───┬───┬───┬───┬───┐
      *     │ Q │ W │ E │ R │ T │                   │ Y │ U │ I │ O │ P │
      * ┌───┼───┼───┼───┼───┼───┤                   ├───┼───┼───┼───┼───┼───┐
      * │Esc│ A │ S │ D │ F │ G │                   │ H │ J │ K │ L │ ; │ ' │
      * ├───┼───┼───┼───┼───┼───┤                   ├───┼───┼───┼───┼───┼───┤
      * │Ctl│ Z │ X │ C │ V │ B │                   │ N │ M │ , │ . │ / │TO4│
      * └tab┴───┴───┴───┴───┴───┘                   └───┴───┴───┴───┴───┴───┘
      *                 ┌───┬───┐                   ┌───┬───┐
      *                 │   │GUI├───┐           ┌───┤Del│   │
      *                 └───┴───┤Shf├───┐   ┌───┤Spc├───┴───┘
      *                         └───┤Alt│   │Ent├───┘
      *                             └───┘   └───┘
      */
    //base layer
    [0] = LAYOUT(
                    KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,                               KC_Y,   KC_U,   KC_I,   KC_O,   KC_P, 
        KC_ESC,     KC_A,   KC_S,   KC_D,   KC_F,   KC_G,                               KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN, KC_QUOT, 
    LCTL_T(KC_TAB), KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_MUTE,        KC_MPLY,    KC_N,   KC_M,  KC_COMM, KC_DOT, KC_SLSH, KC_BSPC, 
                                    KC_LGUI, KC_NO, KC_LSFT, KC_LALT,        LT(2,KC_ENT), LT(3,KC_SPC), LT(1,KC_DEL), KC_BSPC),
    //number layer
    [1] = LAYOUT(
                    KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,                              KC_F6,  KC_F7,  KC_F8,  KC_F9,  KC_F10, 
        KC_ESC,     KC_1,   KC_2,   KC_3,   KC_4,   KC_5,                               KC_6,   KC_7,   KC_8,   KC_9,   KC_0, KC_QUOT, 
    LCTL_T(KC_TAB), KC_F11, KC_F12, LCA(KC_LEFT), LCA(KC_RGHT),KC_B,KC_MUTE, KC_MPLY,    KC_N,   KC_M,  KC_COMM, KC_DOT, KC_SLSH, KC_BSPC, 
                                    KC_LGUI, KC_NO, KC_LSFT, KC_LALT,        LT(2,KC_ENT), LT(3,KC_SPC), LT(1,KC_DEL), KC_BSPC),
};

#if defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {

};
#endif // defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)



// Determine the current tap dance state
td_state_t cur_dance(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (!state->pressed) return TD_SINGLE_TAP;
        else return TD_SINGLE_HOLD;
    } else if (state->count == 2) return TD_DOUBLE_TAP;
    else return TD_UNKNOWN;
}

// Initialize tap structure associated with example tap dance key
static td_tap_t ql_tap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

int _MY_LAYER = 5;
// Functions that control what our tap dance key does
void ql_finished(tap_dance_state_t *state, void *user_data) {
    ql_tap_state.state = cur_dance(state);
    switch (ql_tap_state.state) {
        case TD_SINGLE_TAP:
            layer_on(5);
            break;
        case TD_SINGLE_HOLD:
            tap_code(KC_LGUI);
            break;
        case TD_DOUBLE_TAP:
            break;
            // Check to see if the layer is already set
            if (layer_state_is(_MY_LAYER)) {
                // If already set, then switch it off
                layer_off(_MY_LAYER);
            } else {
                // If not already set, then switch the layer on
                layer_on(_MY_LAYER);
            }
            break;
        default:
            break;
    }
}

void ql_reset(tap_dance_state_t *state, void *user_data) {
    // If the key was held down and now is released then switch off the layer
    if (ql_tap_state.state == TD_SINGLE_HOLD) {
        
        //layer_off(_MY_LAYER);
    }
    ql_tap_state.state = TD_NONE;
}

// Associate our tap dance key with its functionality
tap_dance_action_t tap_dance_actions[] = {
    [GUI_LAYR] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, ql_finished, ql_reset)
};

// Set a long-ish tapping term for tap-dance keys
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case QK_TAP_DANCE ... QK_TAP_DANCE_MAX:
            return 275;
        default:
            return TAPPING_TERM;
    }
}