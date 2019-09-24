#include QMK_KEYBOARD_H

enum tofu68_layers {
    _QWERTY,
    _FNM
};

#define FNM MO(_FNM)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_QWERTY] = LAYOUT_65_ansi(
		KC_GESC, KC_1,     KC_2,     KC_3,   KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     KC_MINS,  KC_EQL,  KC_BSPC, KC_GRV,  \
		KC_TAB,  KC_Q,     KC_W,     KC_E,   KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     KC_LBRC,  KC_RBRC, KC_BSLS, KC_DEL, \
		KC_GRV,  KC_A,     KC_S,     KC_D,   KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,  KC_QUOT,           KC_ENT,  KC_PGUP, \
		KC_LSPO, KC_Z,     KC_X,     KC_C,   KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_RSFT,           KC_UP,   KC_PGDN,  \
		KC_LCTL, KC_LALT,  KC_LCMD,                   KC_SPC,                             FNM,     KC_RALT,  KC_RCTL,  KC_LEFT, KC_DOWN, KC_RGHT  \
	),
	[_FNM]    = LAYOUT_65_ansi(
		_______, KC_F1,    KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,   _______,  _______, KC_MUTE, KC_VOLU, \
		_______, RGB_TOG,  RGB_MOD, RGB_HUI ,RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, _______, _______,  _______,  _______,   RESET, KC_VOLD, \
		_______, _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,           AG_TOGG, _______, \
		_______, _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______,  KC_BTN1,           KC_MS_U, _______, \
		_______, _______,  _______,                   _______,                            _______, _______,  _______,  KC_MS_L, KC_MS_D, KC_MS_R  \
	)
};
