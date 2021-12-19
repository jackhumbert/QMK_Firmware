#include "winx.h"

#include "chrisgve.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[0] = LAYOUT_tsangan(
		KC_GESC, KC_1,    KC_2,    KC_3,        KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSLS, KC_DEL,  KC_PGUP,  KC_NLCK, KC_PSLS, KC_PAST, KC_PMNS,
		KC_TAB,  KC_Q,    KC_W,    KC_E,        KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSPC,          KC_PGDN,  KC_P7,   KC_P8,   KC_P9,   KC_PPLS,
		CPS_CTL, KC_A,    KC_S,    LT(1, KC_D), KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,           MO(3),    KC_P4,   KC_P5,   KC_P6,   KC_PPLS,
		KC_LSFT, KC_Z,    KC_X,    KC_C,        KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, R_SHIFT,          KC_UP,                      KC_P1,   KC_P2,   KC_P3,   KC_PENT,
		KC_LCTL, KC_LALT, KC_LGUI,                       KC_SPC,                    KC_RGUI,                   KC_LEFT, KC_DOWN, KC_RGHT,                    KC_P0,            KC_PDOT
    ),

	[1] = LAYOUT_tsangan(
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,  _______, _______, _______, _______,
		_______, _______, M_F_WRD, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,           _______,  _______, _______, _______, _______,
		_______, A_SHIFT, S_SHIFT, _______, MO(2),   _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,          _______,           _______,  _______, _______, _______, _______,
		_______, _______, _______, _______, _______, M_B_WRD, KC_HOME, KC_END,  _______, _______, _______, _______,          _______,                     _______, _______, _______, _______,
		_______, _______, _______,                   _______,                            _______,                   _______, _______, _______,            _______,          _______ 
    ),

	[2] = LAYOUT_tsangan(
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,  _______, _______, _______, _______,
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,           _______,  _______, _______, _______, _______,
		_______, _______, _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______, _______,          _______,           _______,  _______, _______, _______, _______,
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,                     _______, _______, _______, _______,
		_______, _______, _______,                   _______,                            _______,                   _______, _______, _______,            _______,          _______ 
    ),

	[3] = LAYOUT_tsangan(
		KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______,  _______,  _______, _______, _______, _______,
		RESET,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,           _______,  _______, _______, _______, _______,
		_______, _______, _______, _______, _______, _______, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, _______, _______,          _______,           _______,  _______, _______, _______, _______,
		_______, _______, _______, _______, _______, _______, _______, KC_MUTE, _______, _______, _______, _______,          KC_VOLU,                     _______, _______, _______, _______,
		_______, _______, _______,                   KC_MPLY,                            _______,                   KC_MPRV, KC_VOLD, KC_MNXT,            _______,          _______ 
    ),

};

