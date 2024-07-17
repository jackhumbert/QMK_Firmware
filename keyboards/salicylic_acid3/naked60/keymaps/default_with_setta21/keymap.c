#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

extern uint8_t is_master;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layer_number {
  _QWERTY = 0,
  _FLOCK,
  _LOWER,
  _RAISE,
  _ADJUST,
};

enum custom_keycodes {
  RGB_RST = SAFE_RANGE,
  SEND_SUM,
  SEND_AVE,
  SEND_CIF,
  SEND_MAX,
  SEND_MIN
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_with_setta21(
  //,-----------------------------------------------------|                 |-----------------------------------------------------.      |-----------------------------------------------|
       KC_ESC,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_BSPC,LT(_LOWER, KC_P0),KC_P1, KC_P4,  KC_P7,KC_NUM,  KC_ESC,
  //|--------+--------+--------+--------+--------+--------|                 |--------+--------+--------+--------+--------+--------|      |-------+-------+-------+-------+-------+-------|
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_BSLS,                 KC_P2,  KC_P5,  KC_P8,KC_PSLS,  KC_F2,
  //|--------+--------+--------+--------+--------+--------|                 |--------+--------+--------+--------+--------+--------|      |-------+-------+-------+-------+-------+-------|
      KC_LSFT,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,LT(_RAISE, KC_PDOT),KC_P3,KC_P6, KC_P9,KC_PAST, KC_EQL,
  //|--------+--------+--------+--------+--------+--------|                 |--------+--------+--------+--------+--------+--------|      |---------------+---------------+-------+-------|
     KC_LCTL,     KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                      KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_ENT,               KC_PENT,        KC_PPLS,KC_PMNS, KC_DEL,
  //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|      |-----------------------------------------------|
           MO(_ADJUST),KC_LCTL,  KC_LALT, KC_LGUI,MO(_LOWER), KC_SPC, KC_SPC,MO(_RAISE),KC_LEFT,KC_DOWN,   KC_UP,KC_RIGHT
          //`------------------------------------------------------------------------------------------------------------'
  ),

  [_FLOCK] = LAYOUT_with_setta21(
  //,-----------------------------------------------------|                 |-----------------------------------------------------.      |-----------------------------------------------|
   TG(_FLOCK),   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                     KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11, _______,       _______,_______,_______,_______,_______,_______,
  //|--------+--------+--------+--------+--------+--------|                 |--------+--------+--------+--------+--------+--------|      |-------+-------+-------+-------+-------+-------|
      _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,               _______,_______,_______,_______,_______,
  //|--------+--------+--------+--------+--------+--------|                 |--------+--------+--------+--------+--------+--------|      |-------+-------+-------+-------+-------+-------|
      _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,       _______,_______,_______,_______,_______,_______,
  //|--------+--------+--------+--------+--------+--------|                 |--------+--------+--------+--------+--------+--------|      |---------------+---------------+-------+-------|
      _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,               _______,        _______,_______,_______,
  //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|      |-----------------------------------------------|
               _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
          //`------------------------------------------------------------------------------------------------------------'
  ),

  [_LOWER] = LAYOUT_with_setta21(
  //,-----------------------------------------------------|                 |-----------------------------------------------------.      |-----------------------------------------------|
       KC_ESC,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                     KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,    MO(_LOWER),XXXXXXX,KC_LEFT,XXXXXXX,XXXXXXX, KC_ESC,
  //|--------+--------+--------+--------+--------+--------|                 |--------+--------+--------+--------+--------+--------|      |-------+-------+-------+-------+-------+-------|
      KC_TILD, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                   KC_CIRC, KC_AMPR,  KC_ASTR,KC_LPRN, KC_RPRN,  KC_DEL,               KC_DOWN,KC_DOWN,  KC_UP,KC_PSLS,  KC_F2,
  //|--------+--------+--------+--------+--------+--------|                 |--------+--------+--------+--------+--------+--------|      |-------+-------+-------+-------+-------+-------|
      _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_F6, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,    MO(_RAISE),XXXXXXX,KC_RIGHT,XXXXXXX,KC_PAST,KC_EQL,
  //|--------+--------+--------+--------+--------+--------|                 |--------+--------+--------+--------+--------+--------|      |---------------+---------------+-------+-------|
      _______,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,                    KC_F12,S(KC_NUHS),S(KC_NUBS),_______,_______,_______,              KC_PENT,        KC_PPLS,KC_PMNS, KC_DEL,
  //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|      |-----------------------------------------------|
               _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
          //`------------------------------------------------------------------------------------------------------------'
  ),

  [_RAISE] = LAYOUT_with_setta21(
  //,-----------------------------------------------------|                 |-----------------------------------------------------.      |------------------------------------------------|
      _______,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                     KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,       _______, KC_F11,  KC_F4,  KC_F7,SEND_MIN, KC_ESC,
  //|--------+--------+--------+--------+--------+--------|                 |--------+--------+--------+--------+--------+--------|      |-------+-------+-------+-------+--------+-------|
      KC_TILD,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_DEL,                KC_F12,  KC_F5,  KC_F8,SEND_MAX,  KC_F2,
  //|--------+--------+--------+--------+--------+--------|                 |--------+--------+--------+--------+--------+--------|      |-------+-------+-------+-------+--------+-------|
       KC_DEL,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_F6, KC_MINS,  KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS,       _______,  KC_F3,  KC_F6,  KC_F9,SEND_CIF, KC_EQL,
  //|--------+--------+--------+--------+--------+--------|                 |--------+--------+--------+--------+--------+--------|      |---------------+---------------+--------+-------|
      _______,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,                    KC_F12, KC_NUHS, KC_NUBS, _______, _______, _______,               KC_RPRN,       SEND_SUM,SEND_AVE, KC_DEL,
  //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|      |------------------------------------------------|
               _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ 
          //`------------------------------------------------------------------------------------------------------------'
  ),

  [_ADJUST] = LAYOUT_with_setta21( /* Base */
  //,-----------------------------------------------------|                 |-----------------------------------------------------.      |-----------------------------------------------|
   TG(_FLOCK),   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                     KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,       _______,RGB_VAD,RGB_HUD,RGB_SAD,XXXXXXX,_______,
  //|--------+--------+--------+--------+--------+--------|                 |--------+--------+--------+--------+--------+--------|      |-------+-------+-------+-------+-------+-------|
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, KC_BTN1, KC_MS_U, KC_BTN2, XXXXXXX,LALT(KC_PSCR),          RGB_VAI,RGB_HUI,RGB_SAI,XXXXXXX,_______,
  //|--------+--------+--------+--------+--------+--------|                 |--------+--------+--------+--------+--------+--------|      |-------+-------+-------+-------+-------+-------|
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_R, XXXXXXX, KC_PSCR,       _______,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,_______,
  //|--------+--------+--------+--------+--------+--------|                 |--------+--------+--------+--------+--------+--------|      |---------------+---------------+-------+-------|
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,LCA(KC_DEL),            RGB_MOD,        RGB_TOG,_______,_______,
  //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|      |-----------------------------------------------|
               _______, _______, _______, _______, _______, QK_BOOT, QK_BOOT, _______, _______, _______, _______, _______
          //`------------------------------------------------------------------------------------------------------------'
  )
};

int RGB_current_mode;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  bool result = false;
  switch (keycode) {
    case SEND_SUM:
      if (record->event.pressed) {
        SEND_STRING("=SUM(");
      }
      break;
    case SEND_AVE:
      if (record->event.pressed) {
        SEND_STRING("=AVERAGE(");
      }
      break;
    case SEND_CIF:
      if (record->event.pressed) {
        SEND_STRING("=COUNTIF(");
      }
      break;
    case SEND_MAX:
      if (record->event.pressed) {
        SEND_STRING("=MAX(");
      }
      break;
    case SEND_MIN:
      if (record->event.pressed) {
        SEND_STRING("=MIN(");
      }
      break;
    #ifdef RGBLIGHT_ENABLE
      case RGB_MOD:
          if (record->event.pressed) {
            rgblight_mode(RGB_current_mode);
            rgblight_step();
            RGB_current_mode = rgblight_config.mode;
          }
        break;
      case RGB_RST:
          if (record->event.pressed) {
            eeconfig_update_rgblight_default();
            rgblight_enable();
            RGB_current_mode = rgblight_config.mode;
          }
        break;
    #endif
    default:
      result = true;
      break;
  }

  return result;
}
