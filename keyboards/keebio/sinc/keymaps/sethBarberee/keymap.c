#include QMK_KEYBOARD_H
#include "sethBarberee.h"

#define LAYOUT_80_with_macro_wrapper(...) LAYOUT_80_with_macro(__VA_ARGS__)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_80_with_macro_wrapper(
    KC_MUTE,          KC_ECAP, _________________FUNC_LEFT_________________, _________________FUNC_RIGHT________________,  KC_F11,  KC_F12,  KC_DEL,  KC_MUTE,
    KC_F1,   KC_F2,   KC_GRV,  ________________NUMBER_LEFT________________, ________________NUMBER_RIGHT_______________,KC_MINS, KC_EQL,  _______,  KC_BSPC, KC_HOME,
    KC_F3,   KC_F4,   KC_TAB,  _________________QWERTY_L1_________________, _________________QWERTY_R1_________________,  KC_LBRC, KC_RBRC, KC_BSLS, KC_END,
    KC_F5,   KC_F6,   KC_LSFT, _________________QWERTY_L2_________________, _________________QWERTY_R2_________________,                   KC_ENT,  KC_PGUP,
    KC_F7,   KC_F8,   KC_LSFT, _________________QWERTY_L3_________________, _________________QWERTY_R3_________________,          KC_RSFT, KC_UP,   KC_PGDN,
    KC_F9,   KC_F10,  KC_LCTL, KC_LALT, KC_LGUI, KC_LOWR,  _______,  KC_SPC,          KC_RASE, KC_BSPC,  KC_RALT, KC_RCTL, KC_RGUI, KC_LEFT, KC_DOWN, KC_RGHT
  ),
  [_LOWER] = LAYOUT_80_with_macro_wrapper(
    _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    RGB_HUI, RGB_HUD, KC_GESC, _________________FUNC_LEFT_________________, _________________FUNC_RIGHT________________,  KC_F11,  KC_F12,  _______, _______, KC_MPRV,
    RGB_SAI, RGB_SAD, RGB_TOG, _______, _______, KC_UP,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT,
    RGB_VAI, RGB_VAD, _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, _______, _______, _______, _______, _______,          _______, KC_VOLU,
    RGB_MOD, RGB_RMOD, _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_VOLD,
    _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______, _______
  ),
  [_RAISE] = LAYOUT_80_with_macro_wrapper(
    _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    RESET,   KC_VRSN, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______,
    _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______, _______
  ),
  [_ADJUST] = LAYOUT_80_with_macro_wrapper(
    _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______,
    _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______, _______
  ),
};

void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_PGDN);
        } else {
            tap_code(KC_PGUP);
        }
    } else if (index == 1) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
}
