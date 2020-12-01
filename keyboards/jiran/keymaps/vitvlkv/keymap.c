#include QMK_KEYBOARD_H

/*
qmk compile -kb jiran -km vitvlkv
qmk flash -kb jiran -km vitvlkv
*/

// Defines names for use in layer keycodes and the keymap
enum jiran_layers {
  _QWERTY,
  _LOWER
};

#define KC_BSCT  RCTL_T(KC_BSLS)
#define KC_QTSH  RSFT_T(KC_QUOT)
#define KC_SLSF  RSFT_T(KC_LSCR)
#define KC_NLCT  RCTL_T(KC_LNUM)
#define KC_ETAL  RALT_T(KC_ENT)

#define LOWER  MO(_LOWER)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT(
  //          ┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
               KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
  // ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┼────────┐
      KC_LGUI, KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,
  // └────────┼────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┼────────┘
               KC_LSFT, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QTSH,
  //          ├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
               KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                               KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_BSCT,
  //          └────────┴────────┴────────┴────────┼────────┼────────┤                          ├────────┼────────┼────────┴────────┴────────┴────────┘
                                          LOWER,   KC_SPC,  KC_LALT,                            KC_ETAL, LOWER,   KC_BSPC
                                  //     └────────┴────────┴────────┘                          └────────┴────────┴────────┘
  ),

  [_LOWER] = LAYOUT(
  //          ┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
               KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                              KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_EQL,
  // ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┼────────┐
      KC_F11,  KC_CAPS, _______, _______, _______, _______, RESET,                              RESET,   _______, KC_UP,   _______, KC_PSCR, _______, KC_F12,
  // └────────┼────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┼────────┘
               KC_LSFT, KC_APP , _______, KC_HOME, KC_END,  KC_DEL,                             KC_BSPC, KC_LEFT, KC_DOWN, KC_RGHT, KC_INS,  KC_SLSF,
  //          ├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
               KC_LCTL, _______, _______, KC_MUTE, KC_VOLD, KC_VOLU,                            KC_PGUP, KC_PGDN, KC_DOWN, _______, KC_PAUS, KC_NLCT,
  //          └────────┴────────┴────────┴────────┼────────┼────────┤                          ├────────┼────────┴────────┴────────┴────────┴────────┘
                                          _______, _______, _______,                            _______, _______, KC_DEL
                                    //   └────────┴────────┴────────┘                          └────────┴────────┴────────┘
  ),

};
