#include "keymap.h"


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  | BSPC |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LShift|   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |RSFT/"|
 * |------+------+------+------+------+------| CAPSL |    | MUTE  |------+------+------+------+------+------|
 * |LCTRL |   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RCTRL |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE | RAlt | RGUI |
 *                   |      |      | -ESC |/       /         \      \ | -BSPC|      |      |
 *                   `----------------------------'           '------''--------------------'
 */

 [_QWERTY] = LAYOUT( \
  _______,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______, \
  KC_TAB,    KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, \
  KC_LSFT,   KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                     KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, CUSTOM_SHIFT_QUOT, \
  KC_LCTRL,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_CAPS,  KC_MUTE,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RCTRL, \
                             KC_LALT, KC_LGUI, LT(_RAISE, KC_ESC),KC_SPC,  KC_ENT, LT(_LOWER, KC_BSPC),  KC_RALT, KC_RGUI \
),
/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |                    |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |  %   |   /  |   \  |   |  |  &   |                    |  ^   |  +   |  -   |  *   |  /   |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |   `  |  =   |   [  |   {  |   (  |  ?   |-------.    ,-------|  <-  | DOWN |  UP  |  ->  |  `   |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |  _   |   ]  |   }  |   )  |  !   |-------|    |-------|  ~   |  #   |  $   |  @   |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      |      | /       /       \      \  |      |      |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_LOWER] = LAYOUT( \
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                     KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12, \
  _______, KC_PERC, KC_SLSH, KC_BSLS, KC_PIPE, KC_AMPR,                   KC_CIRC, KC_PLUS, KC_MINS, KC_ASTR, KC_SLSH, _______, \
  _______, KC_EQL,  KC_LBRC, KC_LCBR, KC_LPRN, KC_QUES,                   KC_LEFT, KC_DOWN, KC_UP,  KC_RIGHT, KC_GRV,  _______, \
  _______, KC_UNDS, KC_RBRC, KC_RCBR, KC_RPRN, KC_EXLM, _______, _______, KC_TILD, KC_HASH, KC_DLR,  KC_AT,   _______, _______, \
                             _______, _______, _______, _______, _______,  _______, _______, _______\
),
/* RAISE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |   `  |      |  7   |  8   |  9   |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |  4   |  5   |  6   |      |-------.    ,-------|      |      |      |      |      |      |
 * |------+------+------+------+------+------|       |    |RGB_TOG|------+------+------+------+------+------|
 * |      |      |  1   |  2   |  3   |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |  0   |      | /       /       \      \  |      |      |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

[_RAISE] = LAYOUT( \
  _______, _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, _______, \
  _______, _______, KC_7,    KC_8,    KC_9,    _______,                     _______, ALGR(KC_Y), _______, ALGR(KC_P), _______, _______, \
  _______, ALGR(KC_Q), KC_4,    KC_5,    KC_6,    _______,                  _______, _______, _______, _______, _______, _______, \
  _______, _______, KC_1,    KC_2,    KC_3,    _______,  _______, RGB_TOG,  _______, _______, _______, _______, _______, _______, \
                             KC_0,    _______, _______,  _______, _______,  _______, _______, _______ \
),
/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |RGB ON| HUE+ | SAT+ | VAL+ |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      | MODE | HUE- | SAT- | VAL- |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
  [_ADJUST] = LAYOUT( \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX, TOG_DK,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX,\
                             _______, _______, _______, _______, _______,  _______, _______, _______ \
  )
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}