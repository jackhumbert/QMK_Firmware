#include QMK_KEYBOARD_H

#define K64_VERSION "2"

enum custom_keycodes {
    VER_STR = SAFE_RANGE,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case VER_STR:
            if (record->event.pressed) {
                SEND_STRING("# olkb plank rev6 - komidore64 v"K64_VERSION);
            }
            break;
    }
    return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_planck_1x2uC(
            KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
            KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
            KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
            KC_ESC,  KC_CAPS, KC_LGUI, KC_LALT, MO(1),   KC_SPC,           MO(2),   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
    ),
    [1] = LAYOUT_planck_1x2uC(
            KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL,
            _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,
            _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  XXXXXXX, XXXXXXX, KC_HOME, KC_END, KC_TRNS,
            _______, _______, _______, _______, _______, _______,          MO(3),   KC_RALT, KC_RGUI, KC_APP,  KC_RCTL
    ),
    [2] = LAYOUT_planck_1x2uC(
            KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
            _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
            _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  XXXXXXX, XXXXXXX, KC_PGUP, KC_PGDN, KC_TRNS,
            _______, _______, _______, _______, MO(3),   _______,          _______, KC_RALT, KC_RGUI, KC_APP,  KC_RCTL
    ),
    [3] = LAYOUT_planck_1x2uC(
            XXXXXXX, RESET,   DEBUG,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MPLY, XXXXXXX,
            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, XXXXXXX, XXXXXXX,
            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MUTE, XXXXXXX, XXXXXXX, XXXXXXX, VER_STR,
            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    )
};
