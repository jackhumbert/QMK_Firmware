#include QMK_KEYBOARD_H

#define _L0 0
#define _L1 1

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base Layer
     * ┌──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────────────┬──────┐
     * │ GEsc │   1  │   2  │   3  │   4  │   5  │   6  │   7  │   8  │   9  │   0  │   -  │   =  │   Backspace  │ Home │
     * ├──────┴───┬──┴───┬──┴───┬──┴───┬──┴───┬──┴───┬──┴───┬──┴───┬──┴───┬──┴───┬──┴───┬──┴───┬──┴───┬──────────┼──────┤
     * │    Tab   │   Q  │   W  │   E  │   R  │   T  │   Y  │   U  │   I  │   O  │   P  │   [  │   ]  │     \    │ PgUp │
     * ├──────────┴─┬────┴─┬────┴─┬────┴─┬────┴─┬────┴─┬────┴─┬────┴─┬────┴─┬────┴─┬────┴─┬────┴─┬────┴──────────┼──────┤
     * │  Backspace │   A  │   S  │   D  │   F  │   G  │   H  │   J  │   K  │  L   │   ;  │   '  │     Enter     │ PgDn │
     * ├────────────┴───┬──┴───┬──┴───┬──┴───┬──┴───┬──┴───┬──┴───┬──┴───┬──┴───┬──┴───┬──┴───┬──┴────────┬──────┼──────┤
     * │      LSft      │   Z  │   X  │   C  │   V  │   B  │   N  │   M  │   ,  │   .  │   /  │    RSft   │  Up  │  End │
     * ├────────┬───────┴┬─────┴──┬───┴──────┴──────┴──────┴──────┴──────┴────┬─┴──────┼──────┴─┬──┬──────┼──────┼──────┤
     * │  LCtl  │  LAlt  │  LGUI  │                   Space                   │  RGUI  │ MO(1)  │  │ Left │ Down │ Rght │
     * └────────┴────────┴────────┴───────────────────────────────────────────┴────────┴────────┘  └──────┴──────┴──────┘
     */
    [_L0] = LAYOUT_65_ansi_blocker(
        KC_GESC, KC_1,    KC_2,    KC_3, KC_4, KC_5,   KC_6, KC_7, KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,   KC_HOME,
        KC_TAB,  KC_Q,    KC_W,    KC_E, KC_R, KC_T,   KC_Y, KC_U, KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLASH, KC_PGUP,
        KC_BSPC, KC_A,    KC_S,    KC_D, KC_F, KC_G,   KC_H, KC_J, KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,    KC_PGDN,
        KC_LSFT, KC_Z,    KC_X,    KC_C, KC_V, KC_B,   KC_N, KC_M, KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,          KC_UP,     KC_END,
        KC_LCTL, KC_LALT, KC_LGUI,             KC_SPC,                      KC_RGUI, MO(_L1),          KC_LEFT, KC_DOWN,   KC_RIGHT),


    [_L1] = LAYOUT_65_ansi_blocker(
        KC_GESC, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,  KC_HOME,
        KC_TRNS, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, KC_TRNS, KC_PSCR, KC_SLCK, KC_PAUS, QK_BOOT, KC_PGUP,
        KC_CAPS, RGB_SPI, RGB_SPD, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          EEP_RST, KC_PGDN,
        KC_LSFT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_VOLU, KC_MUTE,
        KC_TRNS, KC_TRNS, KC_TRNS,                   KC_TRNS,                            KC_TRNS, KC_TRNS,          KC_MPRV, KC_VOLD, KC_MNXT),
 };
