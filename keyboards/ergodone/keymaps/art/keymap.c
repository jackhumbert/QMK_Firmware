#include <art.h>
#include <sendstring_workman_zxcvm.h>

bool is_win = true;

enum custom_keycodes {
  keyboardSpecificKeyCode = NEW_SAFE_RANGE //not used
};

void led_set_user(uint8_t usb_led) {
  if (usb_led & (1<<USB_LED_CAPS_LOCK)) {
    ergodox_right_led_2_on();
  } else {
    ergodox_right_led_2_off();
  }
}

layer_state_t layer_state_set_user(layer_state_t state) {
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_3_off();
  switch (get_highest_layer(state)) {
    case NAV:
    case CTRL_NAV:
    case SHIFT_NAV:
      ergodox_right_led_1_on();
      break;
    case FKEYS:
      ergodox_right_led_3_on();
      break;
  }
  return state;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Base qwerty layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |  ` ~   |   1  |   2  |   3  |   4  |   5  |  ESC |           | - _  |   6  |   7  |   8  |   9  |   0  |   ]    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  | ???  |           |  =   |   Y  |   U  |   I  |   O  |   P  |   [    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | Caps   |   A  |   S  |   D  |Ctrl/F|   G  |------|           |------|   H  |   J  |   K  |   L  |  ;   |   '    |
 * |--------+------+------+------+------+------| FKEYS|           | FKEYS|------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |  /   | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |LCtrl |  \   | Win  |Alt   | NAV  |                                       | Home | End  |Workmn|Macro1| RCtrl|
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,---------------.
 *                                        | Del  |  Ins |       | Left |  Right |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | PgUp |       |SFT_NV|        |      |
 *                                 | Space|Backsp|------|       |------|  NAV   |Enter |
 *                                 |      |ace   | PgDn |       |CTR_NV|        |      |
 *                                 `--------------------'       `----------------------'
 */
[QWERTY] = LAYOUT_ergodox(
  // ------------------------------------------left hand------------------------------------------
  KC_GRAVE,         KC_1,         KC_2,       KC_3,       KC_4,              KC_5,      KC_ESCAPE,
  KC_TAB,           KC_Q,         KC_W,       KC_E,       KC_R,              KC_T,      XXXXXXX,
  KC_CAPS,          KC_A,         KC_S,       KC_D,       KC_F,              KC_G,
  KC_LSFT,          KC_Z,         KC_X,       KC_C,       KC_V,              KC_B,      TT(FKEYS),
  KC_LCTRL,         KC_BSLASH,    KC_LWIN,    KC_LALT,    LT(NAV, KC_RIGHT),

                                           KC_DEL,    KC_INS,
                                                      KC_PGUP,
                                  KC_SPC,  KC_BSPC,   KC_PGDOWN,

  // ------------------------------------------right hand------------------------------------------
  KC_MINS,          KC_6,         KC_7,       KC_8,       KC_9,              KC_0,      KC_RBRC,
  KC_EQL,           KC_Y,         KC_U,       KC_I,       KC_O,              KC_P,      KC_LBRC,
                    KC_H,         KC_J,       KC_K,       KC_L,              KC_SCLN,   KC_QUOT,
  TT(FKEYS),        KC_N,         KC_M,       KC_COMM,    KC_DOT,            KC_SLSH,   KC_RSFT,
                                  KC_HOME,    KC_END,     DF(WORKMAN),       XXXXXXX,   KC_RCTRL,

    KC_LEFT,                KC_RIGHT,
    LT(SHIFT_NAV, KC_UP),
    LT(CTRL_NAV, KC_DOWN),  LT(NAV, KC_ESCAPE),   KC_ENT
),
 /* Workman
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   ~    |   1  |   2  |   3  |   4  |   5  |  ESC |           | - _  |   6  |   7  |   8  |   9  |   0  |   ]    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   D  |   R  |   W  |   B  |  /?  |           |  =   |   J  |   F  |   U  |   P  |   ;  |   [    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | Caps   |   A  |   S  |   H  |   T  |   G  |------|           |------|   Y  |   N  |   E  |   O  |  I   |   '    |
 * |--------+------+------+------+------+------| FKEYS|           | FKEYS|------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   M  |      |           |      |   K  |   L  |   ,  |   .  |  /   | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | Ctrl |  \   | Win  | Alt  |      |                                       |      |      |QWERTY| ?????| RCtrl|
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,---------------.
 *                                        | Del  |  Ins |       | Left |  Right |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | PgUp |       |   Up |        |      |
 *                                 | Space|Backsp|------|       |------|        |Enter |
 *                                 |      |ace   | PgDn |       | Down |        |      |
 *                                 `--------------------'       `----------------------'
 */
[WORKMAN] = LAYOUT_ergodox(  
  // ------------------------------------------left hand------------------------------------------
  _______,          _______,      _______,    _______,    _______,           _______,   _______,
  _______,          KC_Q,         KC_D,       KC_R,       KC_W,              KC_B,      _______,
  _______,          KC_A,         KC_S,       KC_H,       KC_T,              KC_G,
  _______,          KC_Z,         KC_X,       KC_C,       KC_V,              KC_M,      _______,
  _______,          _______,      _______,    _______,    _______,

                                            _______,   _______,
                                                       _______,
                                  _______,  _______,   _______,

  // ------------------------------------------right hand------------------------------------------
  _______,          _______,      _______,    _______,    _______,           _______,   _______,
  _______,          KC_J,         KC_F,       KC_U,       KC_P,              KC_SCLN,   _______,
                    KC_Y,         KC_N,       KC_E,       KC_O,              KC_I,      _______,
  _______,          KC_K,         KC_L,       KC_COMM,    KC_DOT,            KC_SLSH,   _______,
                                  _______,    _______,    DF(QWERTY),        _______,   _______,

    _______,  _______,
    _______,
    _______,  _______, _______
),
/* FKeys
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |         |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |      |      |      |      |      |      |           |      |      |      |      |      |      |   F12  |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |      |      |      |      |      |------|           |------|      |      |      |      |      |  PrtSc |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |      |      |      |      |      |      |           |      |      |      |      |      |      | PrtSc |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |       |      |      |      |      |                                       |      |      |      |      |PausBk|
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[FKEYS] = LAYOUT_ergodox(
       // ------------------------------------------left hand------------------------------------------
       _______,KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  _______,
       _______,_______,_______,  _______,_______,_______,_______,
       _______,_______,_______, _______,_______,_______,
       _______,_______,_______,_______,_______,_______,_______,
          _______,_______,_______,_______,_______,
                                       _______,_______,
                                               _______,
                               _______,_______,_______,
       // ------------------------------------------right hand------------------------------------------
       _______, KC_F6,   KC_F7,  KC_F8,   KC_F9,   KC_F10,  KC_F11,
       _______, _______,   _______,   _______,    _______,    _______, KC_F12,
                _______, _______,   _______,    _______,    _______, KC_PSCREEN,
       _______, _______, _______,   _______,    _______,    _______, KC_PSCREEN,
                         _______,_______,  _______,    _______,  KC_PAUSE,
       _______, _______,
       _______,
       _______, _______, _______
),
/* Navigation
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |         |altF1 |altF2 |altF3 |altF4 |altF5 |      |           |      |altF6 |altF7 |altF8 |altF9 |altF10|altF11  |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         | TESTT| Home |  Up  | End  | PgUp |      |           |      |      |  LMB |MousUp|  MMB |  RMB |altF12  |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |      | Left | Down | Right| PgDn |------|           |------| Vol+ |MousLt|MousDn|MousRt|Cntext|        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |      |      |      |  Alt |      |      |           |      | Vol- |VolMut|      |      |      |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |       |MosAc1|MosAc2|MosAc3|      |                                       |      |      | PWR  |      |      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,--------------.
 *                                        |      |      |       |       |      |
 *                                 ,------|------|------|       |-------+------+------.
 *                                 |      |      |M_stop|       |       |      |      |
 *                                 |      | Del  |------|       |-------|      |      |
 *                                 |      |      |M1Start|      |       |      |      |
 *                                 `--------------------'       `---------------------'
 */
[NAV] = LAYOUT_ergodox(
       // ------------------------------------------left hand------------------------------------------
       _______,LALT(KC_F1),  LALT(KC_F2),  LALT(KC_F3),  LALT(KC_F4),  LALT(KC_F5),  _______,
       _______,_______,  KC_HOME,  KC_UP,KC_END,KC_PGUP,_______,
       _______,_______,KC_LEFT, KC_DOWN,KC_RIGHT,KC_PGDOWN,
       _______,_______,  _______,_______,KC_LALT,_______,_______,
          _______,KC_MS_ACCEL0,  KC_MS_ACCEL1,KC_MS_ACCEL2,_______,
                                       _______,_______,
                                               DM_RSTP,
                               _______,KC_DEL,DM_REC1,
       // ------------------------------------------right hand------------------------------------------
       _______, LALT(KC_F6),   LALT(KC_F7),  LALT(KC_F8),   LALT(KC_F9),   LALT(KC_F10),  LALT(KC_F11),
       _______, _______,   KC_MS_BTN1,   KC_MS_UP,    KC_MS_BTN3,    KC_MS_BTN2, LALT(KC_F12),
        KC_AUDIO_VOL_UP,   KC_MS_LEFT,   KC_MS_DOWN,    KC_MS_RIGHT,    KC_APPLICATION, _______,
       _______, KC_AUDIO_VOL_DOWN, KC_AUDIO_MUTE,   _______,    _______,    _______, _______,
                         _______,_______,  KC_SYSTEM_POWER,    _______,  _______,
       _______, _______,
       _______,
       _______, _______, _______
),
/* Navigation with Ctrl
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |         |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |      | Home |  Up  | End  | PgUp |      |           |      |      |      |      |      |      |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |      | Left | Down | Right| PgDn |------|           |------|      |      |      |      |      |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |      |   X  |  C   |  V   |      |      |           |      |      |      |      |      |      |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |       |      |      |      |      |                                       | Home | End  |      |      |      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,--------------.
 *                                        |  Del |      |       | Left  | Right|
 *                                 ,------|------|------|       |-------+------+------.
 *                                 |      |      |      |       | Shift |      |      |
 *                                 |      | BSpce|------|       |-------|      |      |
 *                                 |      |      |  Del |       |       |      |      |
 *                                 `--------------------'       `---------------------'
 */
[CTRL_NAV] = LAYOUT_ergodox(
       // ------------------------------------------left hand------------------------------------------
       _______,_______,  _______,  _______,  _______,  _______,  _______,
       _______,_______,  LCTL(KC_HOME),  LCTL(KC_UP),LCTL(KC_END),LCTL(KC_PGUP),_______,
       _______,_______,LCTL(KC_LEFT), LCTL(KC_DOWN),LCTL(KC_RIGHT),LCTL(KC_PGDOWN),
       _______,_______,  LCTL(KC_X),LCTL(KC_C),LCTL(KC_V),_______,_______,
          _______,_______,  _______,_______,_______,
                                       LCTL(KC_DEL),_______,
                                               _______,
                               _______,LCTL(KC_BSPC),LCTL(KC_DEL),
       // ------------------------------------------right hand------------------------------------------
       _______, _______,   _______,  _______,   _______,   _______,  _______,
       _______, _______,   _______,   _______,    _______,    _______, _______,
                _______,   _______,   _______,    _______,    _______, _______,
       _______, _______, _______,   _______,    _______,    _______, _______,
                         LCTL(KC_HOME),LCTL(KC_END),  _______,    _______,  _______,
       LCTL(KC_LEFT), LCTL(KC_RIGHT),
       KC_LSFT,
       _______, _______, _______
),
/* Navigation with Shift
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |         |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |      | Home |  Up  | End  | PgUp |      |           |      |      |      |      |      |      |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |      | Left | Down | Right| PgDn |------|           |------|      |      |      |      |      |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |      |  X   |  C   |  V   |      |      |           |      |      |      |      |      |      |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |       |      |      |      |      |                                       | Home | End  |      |      |      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,--------------.
 *                                        |      |      |       | Left  | Right|
 *                                 ,------|------|------|       |-------+------+------.
 *                                 |      |      |      |       |       |      |      |
 *                                 |      |      |------|       |-------|      |      |
 *                                 |      |      |      |       | Ctrl  |      |      |
 *                                 `--------------------'       `---------------------'
 */
[SHIFT_NAV] = LAYOUT_ergodox(
       // ------------------------------------------left hand------------------------------------------
       _______,_______,  _______,  _______,  _______,  _______,  _______,
       _______,_______,  LSFT(KC_HOME),  LSFT(KC_UP),LSFT(KC_END),LSFT(KC_PGUP),_______,
       _______,_______,LSFT(KC_LEFT), LSFT(KC_DOWN),LSFT(KC_RIGHT),LSFT(KC_PGDOWN),
       _______,_______,  LCTL(KC_X),LCTL(KC_C),LCTL(KC_V),_______,_______,
          _______,_______,  _______,_______,_______,
                                       _______,_______,
                                               _______,
                               _______,_______,_______,
       // ------------------------------------------right hand------------------------------------------
       _______, _______,   _______,  _______,   _______,   _______,  _______,
       _______, _______,   _______,   _______,    _______,    _______, _______,
                _______,   _______,   _______,    _______,    _______, _______,
       _______, _______, _______,   _______,    _______,    _______, _______,
                         LSFT(KC_HOME),LSFT(KC_END),  _______,    _______,  _______,
       LSFT(KC_LEFT), LSFT(KC_RIGHT),
       _______,
       KC_LCTRL, _______, _______
),

/* Numpad
 *
 *           ,--------------------------------------------------.
 *           |      |      |      |      |      |   /  |        |
 *           |------+------+------+------+------+------+--------|
 *           |      |      |   7  |   8  |   9  |   *  |        |
 *           |      |------+------+------+------+------+--------|
 *           |------|      |   4  |   5  |   6  |   -  |  Enter |
 *           |      |------+------+------+------+------+--------|
 *           |      |      |   1  |   2  |   3  |   +  |  Enter |
 *           `-------------+------+------+------+------+--------'
 *                         |      |   0  |   .  | Calc | Calc   |
 *                         `----------------------------------'
 */

// [] = LAYOUT_ergodox(  
//   // ------------------------------------------left hand------------------------------------------
//   _______,          _______,          _______,          _______,          _______,          _______,          _______,
//   _______,          _______,          _______,          _______,          _______,          _______,          _______,
//   _______,          _______,          _______,          _______,          _______,          _______,
//   _______,          _______,          _______,          _______,          _______,          _______,          _______,
//   _______,          _______,          _______,          _______,          _______,

//                                             _______,   _______,
//                                                        _______,
//                                   _______,  _______,   _______,

//   // ------------------------------------------right hand------------------------------------------
//   _______,          _______,      _______,    _______,    _______,           _______,   _______,
//   _______,          _______,         _______,       _______,       _______,              _______,   _______,
//                     _______,         _______,       _______,       _______,              _______,      _______,
//   _______,          _______,         _______,       _______,    _______,            _______,   _______,
//                                   _______,    _______,    _______,        _______,   _______,

//     _______,  _______,
//     _______,
//     _______,  _______, _______
// ),

};

bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {

  }
  return true;
}