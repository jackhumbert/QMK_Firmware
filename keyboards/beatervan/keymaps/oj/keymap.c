#include QMK_KEYBOARD_H


// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

#define _QW 0
#define _DV 1
#define _CM 2
#define _L1 3
#define _L2 4
#define _L3 5

// Curly braces have their own keys. These are defined to make them not mess up
// the grid in layer 2.
#define L_CURBR LSFT(KC_LBRC)
#define R_CURBR LSFT(KC_RBRC)

enum custom_keycodes {
  DVORAK = SAFE_RANGE,
  QWERTY,
  COLEMAK
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QW] = LAYOUT( /* Qwerty */
    KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_DEL,
    KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_QUOT, KC_ENTER,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, MO(_L2),
    KC_TAB,  MO(_L1), KC_LGUI,                   KC_SPC,  KC_BSPC,                   KC_LALT, KC_RALT, TG(_L3)
  ),
  [_DV] = LAYOUT( /* Dvorak */
    KC_ESC,  KC_SLSH, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_QUOT,
    KC_LCTL, KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_ENTER,
    KC_LSFT, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    MO(_L2),
    KC_TAB,  MO(_L1), KC_LGUI,                   KC_SPC,  KC_BSPC,                   KC_LALT, KC_RALT, TG(_L3)
  ),
  [_CM] = LAYOUT( /* Colemak */
    KC_ESC,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_QUOT,
    KC_LCTL, KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_ENTER,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, MO(_L2),
    KC_TAB,  MO(_L1), KC_LGUI,                   KC_SPC,  KC_BSPC,                   KC_LALT, KC_RALT, TG(_L3)
  ),
  [_L1] = LAYOUT( /* NUM */
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
    _______, _______, _______, _______, _______, _______, KC_LEFT, KC_UP,   KC_DOWN, KC_RGHT, KC_SCLN, KC_BSLS,
    _______, _______, _______, KC_PSCR, _______, _______, _______, _______, KC_LBRC, KC_RBRC, KC_MINS, KC_EQL,
    _______, _______, _______,                   _______, _______,                   _______, _______, _______
  ),
  [_L2] = LAYOUT( /* F Keys */
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,      KC_F10,     KC_F11,
    _______, KC_MPRV, KC_MPLY, KC_MNXT, _______, _______, _______, _______, _______, _______,    _______, KC_ENTER,
    _______, QWERTY,  DVORAK,  COLEMAK, _______, _______, _______, _______, _______, _______,    _______,    _______,
    _______, _______, _______,                   _______, _______,                   _______,    _______,    _______
  ),
  [_L3] = LAYOUT( /* Gaming */
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   _______,
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    _______, _______, KC_F5,   KC_F6,   KC_F7,   KC_F8,   _______,
    KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    _______, MO(_L2), KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______,
    KC_LSFT, KC_Z,    KC_B,                      KC_SPC,  KC_BSPC,                   _______, _______, TG(_L3)
  )
};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
      switch(keycode) {
        case DVORAK:
          if (record->event.pressed) {
            persistent_default_layer_set(1UL<<_DV);
          }
          return false;
        case QWERTY:
          if (record->event.pressed) {
            persistent_default_layer_set(1UL<<_QW);
          }
          return false;
        case COLEMAK:
          if (record->event.pressed) {
            persistent_default_layer_set(1UL<<_CM);
          }
          return false;
        default:
          return true;
      }
    return true;
};
