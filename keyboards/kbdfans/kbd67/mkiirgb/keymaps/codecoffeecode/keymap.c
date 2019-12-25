#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Base layer
   * ,--------------------------------------------------------------------------------------------------.
   * |Esc ~|  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  -  |  =  |  Backspace  | Home |
   * |-------------------------------------------------------------------------------------------+------+
   * | Tab    |  Q  |  W  |  E  |  R  |  T  |  Y  |  U  |  I  |  O  |  P  |  [  |  ]  |    \     | End  |
   * |-------------------------------------------------------------------------------------------+------+
   * | CtrlCaps |  A  |  S  |  D  |  F  |  G  |  H  |  J  |  K  |  L  |  ;  |  '  |     Enter    | PgUp |
   * |-------------------------------------------------------------------------------------------+------+
   * | Shift      |  Z  |  X  |  C  |  V  |  B  |  N  |  M  |  ,  |  .  |  /  |   MO(2)    | Up  | PgDn |
   * +-------------------------------------------------------------------------┬---┬-------------+------+
   * | LCtrl | LGUI | LAlt |               Space                 | Btn2 | MO(1)|   | Left  |Down | Right|
   * `-------------------------------------------------------------------------┘   └-------------+------´
   */
    [0] = LAYOUT_65_ansi_blocker( /* Base */
        KC_GESC,       KC_1,     KC_2,     KC_3,  KC_4,  KC_5,  KC_6,    KC_7,  KC_8,    KC_9,     KC_0,     KC_MINS,  KC_EQL,  KC_BSPC,   KC_HOME,\
        KC_TAB,        KC_Q,     KC_W,     KC_E,  KC_R,  KC_T,  KC_Y,    KC_U,  KC_I,    KC_O,     KC_P,     KC_LBRC,  KC_RBRC, KC_BSLASH, KC_END, \
        CTL_T(KC_CAPS),KC_A,     KC_S,     KC_D,  KC_F,  KC_G,  KC_H,    KC_J,  KC_K,    KC_L,     KC_SCLN,  KC_QUOT,           KC_ENT,    KC_PGUP,\
        KC_LSFT,       KC_Z,     KC_X,     KC_C,  KC_V,  KC_B,  KC_N,    KC_M,  KC_COMM, KC_DOT,   KC_SLSH,  MO(2),             KC_UP,     KC_PGDN,\
        KC_LCTL,       KC_LGUI,  KC_LALT,                KC_SPC,                KC_BTN2,           MO(1),    KC_LEFT,           KC_DOWN,   KC_RIGHT
    ),

    [1] = LAYOUT_65_ansi_blocker( /* MO(1) - Fn */
        KC_GRV,        KC_F1,    KC_F2,   KC_F3,  KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,  KC_F12,  KC_DEL,   KC_HOME,\
        _______,       RGB_TOG,  RGB_MOD, RGB_HUI,RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, _______, KC_PSCR,  KC_SLCK, KC_PAUS, RESET,    KC_PGUP,\
        CTL_T(KC_CAPS),RGB_SPI,  RGB_SPD, _______,_______, _______, _______, _______, _______, _______, _______,  _______,          EEP_RST,  KC_PGDN,\
        KC_LSFT,       _______,  _______, _______,_______, _______, _______, _______, _______, _______, _______,  _______,          KC_VOLU,  KC_MUTE,\
        _______,       _______,  _______,                  _______,                   _______,          _______,  KC_MPRV,          KC_VOLD,  KC_MNXT
    ),

    [2] = LAYOUT_65_ansi_blocker( /* MO(2) - RShift */
        KC_GESC,       _______,  _______, _______,_______, _______, _______, _______, _______, _______, _______,  _______,  _______, _______, _______,\
        LCTL(KC_L),    _______,  _______, _______,_______, _______, _______, _______, _______, _______, _______,  _______,  _______, _______, _______,\
        _______,       _______,  _______, _______,_______, _______, _______, _______, _______, _______, _______,  _______,           _______, _______,\
        _______,       _______,  _______, _______,_______, _______, _______, _______, _______, _______, _______,  _______,           _______, _______,\
        _______,       _______,  _______,                  _______,                   _______,          _______,  _______,           _______, _______
    )
};

void matrix_init_user(void)
{
  //user initialization
}

void matrix_scan_user(void)
{
  //user matrix
}

bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
	  return true;
}
