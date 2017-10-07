#include "nyquist.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

#define _QWERTY 0
#define _GAME 1
#define _LOWER 2
#define _VIM 3


enum custom_macros {
    DLEFT,
    DRIGHT,
};

enum planck_keycodes {
  DYNAMIC_MACRO_RANGE,
};

#include "dynamic_macro.h"

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | 0(') |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  | Ö(0) | Ü(-) |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |  Z(Y)|   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |LTVIMF|   G  |   H  |   J  |   K  |   L  |  É(;)| Á(") |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |Í/Shft| Y(Z) |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |  -(/)| Shift|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |  GUI |  Alt |LOWER |  Spc |  Spc | Bksp | Ent  |  Alt |  DM  | GAME | Del  |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = KEYMAP( \
  KC_GRV,                KC_1,      KC_2,    KC_3,        KC_4,           KC_5,    KC_6,    KC_7,    KC_8,    KC_9,            KC_0,          KC_MINUS, \
  KC_TAB,                KC_Q,      KC_W,    KC_E,        KC_R,           KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,            KC_P,          KC_BSPC, \
  KC_ESC,                KC_A,      KC_S,    KC_D,        LT(_VIM, KC_F), KC_G,    KC_H,    KC_J,    KC_K,    KC_L,            KC_SCLN,       KC_QUOT, \
  MT(MOD_LSFT, KC_NUBS), KC_Z,      KC_X,    KC_C,        KC_V,           KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,          KC_SLSH,       OSM(MOD_RSFT), \
  KC_LCTL,               KC_LGUI,   KC_LALT, TT(_LOWER),  KC_SPC,         KC_SPC, KC_BSPC,  KC_ENT,  KC_RALT, DYN_MACRO_PLAY1, TG(_GAME),     KC_DEL \
),

/* Gaming mode
 * All one-shot mods are disabled on this layer
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |QWERTY|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |Lower |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |   F  |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      | Left | Down |  Up  | Right|
 * `-----------------------------------------------------------------------------------'
 */
[_GAME] =  KEYMAP( \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, TO(_QWERTY),    \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, OSL(_LOWER),    \
  _______, _______, _______, _______, KC_F,    _______, _______, _______, _______, _______, _______, _______,    \
  KC_LSFT, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,    \
  _______, _______, _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT \
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |  Up  |      |  Del |  Ins |      |      |   7  |   8  |   9  |   /  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      | Left | Down | Right| Home |  End |      |      |   4  |   5  |   6  |   *  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|      |      |      | PGUP | PGDN |      |      |   1  |   2  |   3  |   -  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |   0  |   .  |   =  |   +  |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = KEYMAP( \
  KC_F1,     KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,    KC_F8,   KC_F9,   KC_F10,    KC_F11,       KC_F12, \
  _______,   _______, KC_UP,   _______, KC_DEL , KC_INS , _______,  _______, KC_7,    KC_8,      KC_9,         KC_KP_SLASH, \
  _______,   KC_LEFT, KC_DOWN, KC_RGHT, KC_HOME, KC_END , _______,  _______, KC_4,    KC_5,      KC_6,         KC_KP_ASTERISK, \
  KC_LSFT,   _______, _______, _______, KC_PGUP, KC_PGDN, _______,  _______, KC_1,    KC_2,      KC_3,         KC_KP_MINUS, \
  _______,   _______, _______, _______, _______, _______, _______,  _______, KC_GRV,  KC_KP_DOT, KC_KP_EQUAL,  KC_KP_PLUS \
),


/* Vim Movement (Hold down F)
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |DM_stp|      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |DM_REC|      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | DLeft|DRight| LCTRL|      |      | Left | Down |  Up  | Right|      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      | LShft|      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_VIM] =  KEYMAP( \
  RGB_MOD, RGB_TOG,  _______,   _______, DYN_REC_STOP,   _______, _______, _______, _______, _______, KC_LBRC, KC_NUHS, \
  _______, _______,  _______,   _______, DYN_REC_START1, _______, _______, KC_RBRC, KC_NUBS, KC_EQL , _______, _______, \
  _______, M(DLEFT), M(DRIGHT), KC_LCTL, _______,        _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______, \
  _______, _______,  _______,   _______, _______,        _______, _______, _______, _______, _______, _______, _______, \
  _______, _______,  _______,   _______, KC_LSFT,        _______, _______, _______, _______, _______, _______, _______ \
)


};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
    switch(id) {
        case DLEFT:
            if (record->event.pressed) { // Windows move desktop left
                return MACRO(D(LCTL), D(LGUI), T(LEFT), U(LGUI), U(LCTL), END);
            }
            break;
        case DRIGHT:
            if (record->event.pressed) { // Windows move desktop right
                return MACRO(D(LCTL), D(LGUI), T(RIGHT), U(LGUI), U(LCTL), END);
            }
            break;
    }
    return MACRO_NONE;
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    uint16_t macro_kc = (keycode == MO(_VIM) ? DYN_REC_STOP : keycode);
    if (!process_record_dynamic_macro(macro_kc, record)) {
        return false;
    }
    return true;
}
