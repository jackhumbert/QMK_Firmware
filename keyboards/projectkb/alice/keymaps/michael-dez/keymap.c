#include QMK_KEYBOARD_H

/* THIS FILE WAS GENERATED!
 *
 * This file was generated by qmk json2c. You may or may not want to
 * edit it directly.
 */
enum custom_keycodes {
    NEW_L = SAFE_RANGE,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    //duplicate vim 'o' function
    case NEW_L:
        if (record->event.pressed) {
            SEND_STRING(SS_TAP(X_END) SS_TAP(X_ENTER));
        }
        break;
    }
    return true;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT_alice_split_bs(KC_GRV, KC_GESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC, KC_BSPC, KC_NO, KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS, MO(2), KC_LCTL, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT, KC_LSPO, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_LEAD, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSPC, KC_DEL, KC_CAPS, KC_LGUI, KC_BSPC, TT(1), KC_SPC, KC_RALT, KC_RCTL),
	[1] = LAYOUT_alice_split_bs(KC_NO, KC_TRNS, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_NO, KC_NO, KC_PGUP, KC_TRNS, KC_NO, LCTL(KC_RGHT), KC_NO, KC_NO, KC_NO, KC_COPY, KC_UNDO, TO(0), NEW_L, KC_PSTE, KC_NO, KC_NO, KC_TRNS, KC_PGDN, KC_TRNS, KC_NO, KC_NO, KC_CUT, KC_NO, KC_NO, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_NO, KC_NO, KC_TRNS, MO(3), KC_NO, KC_NO, KC_NO, TO(5), LCTL(KC_LEFT), KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_FIND, KC_TRNS, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO),
	[2] = LAYOUT_alice_split_bs(KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_ASTR, KC_NO, KC_NO, KC_MINS, KC_PLUS, KC_NO, RESET, KC_NO, KC_TAB, KC_NO, KC_NO, RGB_TOG, RGB_MOD, RGB_RMOD, KC_P7, KC_P8, KC_P9, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_NO, KC_NO, RGB_VAI, RGB_VAD, RGB_SPI, RGB_SPD, KC_P4, KC_P5, KC_P6, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, RGB_SAI, RGB_SAD, RGB_HUI, RGB_HUD, KC_NO, KC_P1, KC_P2, KC_P3, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_NO, KC_P0, KC_ENT, KC_NO),
	[3] = LAYOUT_alice_split_bs(KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_END, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_HOME, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO),
	[4] = LAYOUT_alice_split_bs(KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, LSFT(KC_END), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, LSFT(KC_HOME), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, RCS(KC_RGHT), KC_NO, KC_NO, KC_NO, KC_COPY, KC_NO, TO(0), KC_NO, KC_PSTE, KC_NO, KC_NO, KC_NO, KC_NO, TO(1), KC_NO, KC_NO, KC_CUT, KC_NO, KC_NO, LSFT(KC_LEFT), LSFT(KC_DOWN), LSFT(KC_UP), LSFT(KC_RGHT), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, RCS(KC_LEFT), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO)
};
