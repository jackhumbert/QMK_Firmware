#include QMK_KEYBOARD_H
#include "brandonschlack.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* LAYOUT
 * ┌───┐ ┌───┬───┬───┬───┬───┬───┬───┐         ┌───┬───┬───┬───┬───┬───┬───┬───┐
 * │Hom│ │Esc│! 1│@ 2│# 3│$ 4│% 5│^ 6│         │& 7│* 8│( 9│) 0│_ -│+ =│| \│~ `│
 * ├───┤ ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┘       ┌─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┤
 * │PgU│ │Tab  │ Q │ W │ E │ R │ T │         │ Y │ U │ I │ O │ P │{ [│} ]│ Bspc│
 * ├───┤ ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┐        └┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤
 * │PgD│ │HyCaps│ A │ S │ D │ F │ G │         │ H │ J │ K │ L │: ;│" '│   Enter│
 * └───┘ ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┐     ┌─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┤
 *       │LShift  │ Z │ X │ C │ V │ B │     │ B │ N │ M │< ,│> .│? /│↑ Shft│Fn │
 *       ├─────┬──┴──┬┴───┴┬──┴───┴┬──┴─┐   ├───┴───┴──┬┴───┴┬──┴───┴────┬─┴───┤
 *       │Opt  │     │Cmd  │Spc/Fn1│Ctrl│   │   Spc/Rai│  Cmd│           │  Opt│
 *       └─────┘     └─────┴───────┴────┘   └──────────┴─────┘           └─────┘
 */
[_BASE] = LAYOUT_all( \
    KC_HOME, KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSLS, KC_GRV,  \
    KC_PGUP, KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSPC, \
    KC_PGDN, HY_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,  \
             KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, TT(_FN1),\
             KC_LOPT,          KC_LCMD,     SPC_LWR,      KC_LCTL,          SPC_RAI,          KC_RCMD,                   KC_ROPT \
),
[_FN1] = LAYOUT_all( \
    KC_MUTE, QM_MAKE, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  MC_LHPD, MC_SLPD, \
    KC_VOLU, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI, _______, _______, _______, _______, _______, KC_PGUP, KC_HOME, KC_END,  KC_DELT, \
    KC_VOLD, RGB_TOG, RGB_HUD, RGB_SAD, RGB_VAD, RGB_SPD, _______, _______, _______, KC_MPRV, KC_MNXT, KC_PGDN, KC_UP,            KC_MPLY, \
             _______, RGB_LYR, RGB_THM, _______, _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, RGT_SFT, _______, \
             _______,          _______,     _______,      _______,          _______,          _______,                   _______ \

),
[_FN2] = LAYOUT_all( \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, \
             _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
             _______,          _______,     _______,      _______,          _______,          _______,                   _______ \

),
[_ADJUST] = LAYOUT_all( \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, \
             _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
             _______,          _______,     _______,      _______,          _______,          _______,                   _______ \

)
/*
[_BLANK] = LAYOUT( \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, \
             _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
             _______,          _______,     _______,      _______,          _______,          _______,                   _______ \

)
*/
};

layer_state_t layer_state_set_keymap(layer_state_t state) {
    state = update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
    return state;
}

#ifdef USE_LEDS_FOR_LAYERS
bool led_update_keymap(led_t led_state) {
    writePin(TOP_LED, LED_ON(IS_LAYER_ON(_FN1))); // Use for Layer 1
    writePin(MIDDLE_LED, LED_ON(IS_LAYER_ON(_FN2))); // Use for Layer 2
    writePin(BOTTOM_LED, LED_ON(led_state.caps_lock)); // Use for Caps Lock
    return false; // Override default set by KB
}
#endif
