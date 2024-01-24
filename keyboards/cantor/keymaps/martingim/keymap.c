// Copyright 2022 Diego Palacios (@diepala)
// SPDX-License-Identifier: GPL-2.0

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
     /*
      * ┌───┬───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┬───┐
      * │Esc│ Q │ W │ E │ R │ T │       │ Y │ U │ I │ O │ P │Bsp│
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │Tab│ A │ S │ D │ F │ G │       │ H │ J │ K │ L │ ; │ ' │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │Ctl│ Z │ X │ C │ V │ B │       │ N │ M │ , │ . │ / │TO4│
      * └───┴───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┴───┘
      *               ┌───┐                   ┌───┐
      *               │Alt├───┐           ┌───┤Del│
      *               └───┤Shf├───┐   ┌───┤Spc├───┘
      *                   └───┤TO1│   │Ent├───┘
      *                       └───┘   └───┘
      */
    [0] = LAYOUT_split_3x6_3( KC_ESC, KC_Q, KC_W, KC_E, KC_R, KC_T,                   KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC, 
                              KC_TAB, KC_A, KC_S, KC_D, KC_F, KC_G,                   KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, 
                              KC_LCTL, KC_Z, KC_X, KC_C, KC_V, KC_B,                  KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, TO(4), 
                                                    KC_LALT, KC_LSFT, TO(1),   LT(2,KC_ENT), LT(3,KC_SPC), LT(1,KC_DEL)),

	  [1] = LAYOUT_split_3x6_3( KC_ESC, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,              KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_BSPC, 
                              KC_NO, KC_1, KC_2, KC_3, KC_4, KC_5,                    KC_6, KC_7, KC_8, KC_9, KC_0, KC_EQL, 
                              KC_LSFT, KC_F11, KC_F12, LCA(KC_LEFT), LCA(KC_RGHT), KC_NO,       KC_PPLS, KC_PAST, KC_COMM, KC_DOT, KC_PSLS, KC_PMNS, 
                                                    TO(0), KC_LSFT, TO(0),     LT(2,KC_ENT), LT(3,KC_SPC), KC_DEL),
	  
    [2] = LAYOUT_split_3x6_3(KC_NO, KC_NO, KC_EXLM, KC_DQUO, KC_DLR, KC_PERC, KC_SLSH, KC_TILD, KC_NO, KC_NO, KC_NO, KC_BSPC, KC_NO, KC_NO, KC_LCBR, KC_LBRC, KC_LPRN, KC_MINS, KC_COMM, KC_RPRN, KC_RBRC, KC_RCBR, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_UNDS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, TO(0), KC_NO, KC_TRNS, KC_NO, KC_NO, KC_NO),
	  
    [3] = LAYOUT_split_3x6_3(LALT(KC_TAB), KC_NO, KC_NO, KC_UP, KC_NO, KC_NO, KC_NO, KC_NO, KC_VOLU, KC_VOLD, KC_MUTE, KC_BSPC, KC_NO, KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_END, KC_HOME, KC_LEFT, KC_UP, KC_DOWN, KC_RGHT, KC_END, KC_NO, LCTL(KC_Y), LCTL(KC_X), LCTL(KC_C), LCTL(KC_V), LCTL(KC_Z), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, TO(0), KC_LSFT, KC_NO, KC_ENT, KC_SPC, KC_NO),
	  
    [4] = LAYOUT_split_3x6_3( KC_ESC, KC_Q, KC_W, KC_E, KC_R, KC_T,                    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_BSPC, 
                              KC_TAB, KC_A, KC_S, KC_D, KC_F, KC_G,                    KC_NO, KC_NO, TO(0), TO(0), KC_UP, TO(0), 
                              KC_LCTL, KC_Z, KC_X, KC_C, KC_V, KC_B,                   KC_NO, KC_NO, TO(0), KC_LEFT, KC_DOWN, KC_RGHT, 
                                                  TO(0), KC_LSFT, KC_SPC,         KC_ENT, KC_SPC, TO(0))
};

