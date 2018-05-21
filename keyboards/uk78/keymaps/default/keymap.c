#include QMK_KEYBOARD_H

// Helpful defines
#define _______ KC_TRNS

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _BL 0
#define _FL1 1
#define _FL2 2

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* _BL: Base Layer(Default) - For ISO enter use ANSI \
    * ,-------------------------------------------------------------------------------.
    * |Esc | 1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =| /|BSpc| Del|  P/|  P*|  P-|
    * |-------------------------------------------------------------------------------|
    * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|  \  |  P7|  P8|  P9|  P=|
    * |-------------------------------------------------------------------------------|
    * |CAPS   |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '| #| Ent|  P4|  P5|  P6|  P+|
    * |-------------------------------------------------------------------------------|
    * |Shift| \|  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift | Up|  P1|  P2|  P3|SLck|
    * |-------------------------------------------------------------------------------|
    * |Ctrl|Win |Alt |        Space        |Alt|Ctrl|Mo(1)|Lef|Dow| Rig|  P0|  P.|PEnt|
    * `-------------------------------------------------------------------------------'
    */
    [_BL] = LAYOUT(
        KC_ESC,  KC_1,    KC_2,    KC_3,   KC_4,    KC_5,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,   KC_BSLS, KC_BSPC, KC_DEL,  KC_PSLS, KC_PAST, KC_PMNS,
        KC_TAB,  KC_Q,    KC_W,    KC_E,   KC_R,    KC_T,  KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,           KC_BSLS, KC_P7,   KC_P8,   KC_P9,   KC_PEQL,
        KC_CAPS, KC_A,    KC_S,    KC_D,   KC_F,    KC_G,  KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_NUHS,           KC_ENT,  KC_P4,   KC_P5,   KC_P6,   KC_PPLS,
        KC_LSFT, KC_NUBS, KC_Z,    KC_X,   KC_C,    KC_V,  KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,  KC_RSFT, KC_UP,   KC_P1,   KC_P2,   KC_P3,   KC_SLCK,
        KC_LCTL, KC_LGUI, KC_LALT,                         KC_SPC,                             KC_RALT, KC_RCTL, MO(_FL1), KC_LEFT, KC_DOWN, KC_RGHT, KC_P0,   KC_PDOT, KC_PENT),
    /* _FL1: Function Layer 1 - For ISO enter use ANSI \
    * ,-------------------------------------------------------------------------------.
    * |  `|F1| F2| F3| F4| F5| F6| F7| F8| F9|F10|F11|F12|PScr|Ins|NLck|    |    |    |
    * |-------------------------------------------------------------------------------|
    * |     |   |   |   |RST|   |   |   |   |   |   |   |   |     |    |    |    |    |
    * |-------------------------------------------------------------------------------|
    * |       |   |   |   |   |   |Hu+|Va+|Sa+|   |   |   |  |    |    |    |    |    |
    * |-------------------------------------------------------------------------------|
    * |     |   |   |   |   |RGB|Hu-|Va-|Sa-|Bl-|Bl+|   |Mute|Vol+|    |    |    |    |
    * |-------------------------------------------------------------------------------|
    * |    |    |    |      BL_Toggle       |   |   |   |    |Vol-|    |    |    |    |
    * `-------------------------------------------------------------------------------'
    */
    [_FL1] = LAYOUT(
        KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_PSCR, KC_INS,  KC_NLCK, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RESET,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RGB_HUI, RGB_SAI, RGB_VAI, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RGB_TOG, RGB_HUD, RGB_SAD, RGB_VAD, BL_DEC,  BL_INC,  KC_TRNS, KC_MUTE, KC_MUTE, KC_VOLU, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS,                            BL_TOGG,                            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_VOLD, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
    /* _FL2: Function Layer 2 - For ISO enter use ANSI \
    * ,-------------------------------------------------------------------------------.
    * |   |  |   |   |   |   |   |   |   |   |   |   |   |    |   |    |    |    |    |
    * |-------------------------------------------------------------------------------|
    * |     |   |   |   |   |   |   |   |   |   |   |   |   |     |    |    |    |    |
    * |-------------------------------------------------------------------------------|
    * |       |   |   |   |   |   |   |   |   |   |   |   |  |    |    |    |    |    |
    * |-------------------------------------------------------------------------------|
    * |     |   |   |   |   |   |   |   |   |   |   |   |    |    |    |    |    |    |
    * |-------------------------------------------------------------------------------|
    * |    |    |    |                      |   |   |   |    |    |    |    |    |    |
    * `-------------------------------------------------------------------------------'
    */
    [_FL2] = LAYOUT(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS,                            KC_TRNS,                            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),


};


void matrix_init_user(void) {
}

void matrix_scan_user(void) {
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    return true;
}

void led_set_user(uint8_t usb_led) {

    if (usb_led & (1 << USB_LED_NUM_LOCK)) {

    }
    else {

    }

    if (usb_led & (1 << USB_LED_CAPS_LOCK)) {
        DDRA |= (1 << 3); PORTA |= (1 << 3);
    }
    else {
        DDRA &= ~(1 << 3); PORTA &= ~(1 << 3);
    }

    if (usb_led & (1 << USB_LED_SCROLL_LOCK)) {

    }
    else {

    }

    if (usb_led & (1 << USB_LED_COMPOSE)) {

    }
    else {

    }

    if (usb_led & (1 << USB_LED_KANA)) {

    }
    else {

    }
}