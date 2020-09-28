#include QMK_KEYBOARD_H


#define _QWERTY 0
#define _RAISE 1

enum custom_keycodes {
    QWERTY = SAFE_RANGE,
    RAISE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_QWERTY] = LAYOUT(
    //┌────────┬────────┬────────┬────────┬────────┬────────┐                            ┌────────┬────────┬────────┬────────┬────────┬────────┐
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,                                   KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_BSPC,
    //├────────┼────────┼────────┼────────┼────────┼────────┤                            ├────────┼────────┼────────┼────────┼────────┼────────┤
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,                                   KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_BSLS,
    //├────────┼────────┼────────┼────────┼────────┼────────┤                            ├────────┼────────┼────────┼────────┼────────┼────────┤
        KC_DEL,   KC_A,     KC_S,     KC_D,     KC_F,     KC_G,                                   KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,
    //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
        KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_ENT,             KC_SPC,   KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,
    //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                          KC_LCTL,  MO(_RAISE), KC_ENT,                    KC_SPC,   KC_LGUI,   KC_LALT
                                  //     └────────┴────────┴────────┘                  └────────┴────────┴────────┘
    ),
    [_RAISE] = LAYOUT(
    //┌────────┬────────┬────────┬────────┬────────┬────────┐                            ┌────────┬────────┬────────┬────────┬────────┬────────┐
        KC_F12,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,                                  KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,
    //├────────┼────────┼────────┼────────┼────────┼────────┤                            ├────────┼────────┼────────┼────────┼────────┼────────┤
        _______,  KC_HOME,  KC_UP,    KC_END,   KC_PGUP,  _______,                                _______,  KC_UNDS,  KC_PLUS,  _______,  _______,  _______,
    //├────────┼────────┼────────┼────────┼────────┼────────┤                            ├────────┼────────┼────────┼────────┼────────┼────────┤
        KC_ESC,   KC_LEFT,  KC_DOWN,  KC_RIGHT,  KC_PGDN,  KC_UNDS,                                _______, KC_MINS,  KC_EQL,   KC_LBRC,  KC_RBRC,  _______,
    //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
        _______,  RGB_TOG,  RGB_MOD,  RGB_HUI,  RGB_SAI,  _______,  _______,            _______,  _______,  KC_NUHS,  KC_NUBS,  KC_VOLD,  KC_VOLU,  _______,
    //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                           _______,  _______,  _______,                     _______,  _______,  _______
                                  //     └────────┴────────┴────────┘                  └────────┴────────┴────────┘
    ),
};
