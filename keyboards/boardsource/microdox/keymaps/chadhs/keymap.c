/*
Custom keymap created by: Chad Stovern <hello@chadstovern.com>
*/

#include QMK_KEYBOARD_H
#include "g/keymap_combo.h" // enables combos.def support
#include "bit-c_led.h" // enables micro-controller led confirguration

enum layers {
    _COLEMAK_DH,
    _NUM_NAV,
    _FUNCTION,
    _GAMING,
    _GAMING_2,
};

/* thumb mods */
#define NUM_BSPC LT(_NUM_NAV,KC_BSPC)
#define FUN_SPC LT(_FUNCTION,KC_SPC)
#define G2_SPC LT(_GAMING_2,KC_SPC)
#define CMD_TAB CMD_T(KC_TAB)

/* misc mods */
#define GAMING TG(_GAMING)

/* home row mods */
#define HOME_A SFT_T(KC_A)
#define HOME_R CTL_T(KC_R)
#define HOME_S OPT_T(KC_S)
#define HOME_T CMD_T(KC_T)
#define HOME_BT SFT_T(KC_GRV)
#define HOME_N CMD_T(KC_N)
#define HOME_E OPT_T(KC_E)
#define HOME_I CTL_T(KC_I)
#define HOME_O SFT_T(KC_O)
#define HOME_DWN CMD_T(KC_DOWN)
#define HOME_UP OPT_T(KC_UP)
#define HOME_RGT CTL_T(KC_RGHT)
#define HOME_J CMD_T(KC_J)
#define HOME_K OPT_T(KC_K)
#define HOME_L CTL_T(KC_L)
#define HOME_QT SFT_T(KC_QUOT)

/* layer definitions */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_COLEMAK_DH] = LAYOUT_split_3x5_3(
/*
 ,------.------.------.------.------.            ,------.------.------.------.------.
 | Q    | W    | F    | P    | B    |            | J    | L    | U    | Y    | ; :  |
 |      |      |      |      |      |            |      |      |      |      |      |
 |------+------+------+------+------|            |------+------+------+------+------|
 | A    | R    | S    | T    | G    |            | M    | N    | E    | I    | O    |
 | SFT  | CTL  | OPT  | CMD  |      |            |      | CMD  | OPT  | CTL  | SFT  |
 |------+------+------+------+------|            |------+------+------+------+------|
 | Z    | X    | C    | D    | V    |            | K    | H    | , <  | . >  | / ?  |
 |      |      |      |      |      |            |      |      |      |      |      |
 `------'------'------'------'------'            `------'------'------'------'------'
                         .------.------.      .------.------.
                         | TAB  | BSPC |      | SPC  | ENT  |
                         | CMD  | LNUM |      | LFUN |      |
                         '------'------'      '------'------'
*/
  KC_Q,   KC_W,   KC_F,    KC_P,     KC_B,         KC_J,    KC_L,   KC_U,    KC_Y,   KC_SCLN,
  HOME_A, HOME_R, HOME_S,  HOME_T,   KC_G,         KC_M,    HOME_N, HOME_E,  HOME_I, HOME_O,
  KC_Z,   KC_X,   KC_C,    KC_D,     KC_V,         KC_K,    KC_H,   KC_COMM, KC_DOT, KC_SLSH,
                  XXXXXXX, CMD_TAB,  NUM_BSPC,     FUN_SPC, KC_ENT, XXXXXXX
),

[_NUM_NAV] = LAYOUT_split_3x5_3(
/*
 ,------.------.------.------.------.            ,------.------.------.------.------.
 | 1 !  | 2 @  | 3 #  | 4 $  | 5 %  |            | 6 ^  | 7 &  | 8 *  | 9 (  | 0 )  |
 |      |      |      |      |      |            |      |      |      |      |      |
 |------+------+------+------+------|            |------+------+------+------+------|
 | ` ~  |      |      |      |      |            | H    | J    | K    | L    | ' "  |
 | SFT  | CTL  | OPT  | CMD  |      |            |      | CMD  | OPT  | CTL  | SFT  |
 |------+------+------+------+------|            |------+------+------+------+------|
 |      |      |      |      |      |            | - _  | = +  | [ {  | ] }  | \ |  |
 |      |      |      |      |      |            |      |      |      |      |      |
 `------'------'------'------'------'            `------'------'------'------'------'
                         .------.------.      .------.------.
                         | ESC  | ↓↓↓  |      | ↓↓↓  | ↓↓↓  |
                         |      |      |      |      |      |
                         '------'------'      '------'------'
*/
  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,         KC_6,    KC_7,     KC_8,    KC_9,     KC_0,
  HOME_BT, KC_LCTL, KC_LOPT, KC_LCMD, XXXXXXX,      KC_H,    HOME_J,   HOME_K,  HOME_L,   HOME_QT,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      KC_MINS, KC_EQL,   KC_LBRC, KC_RBRC,  KC_BSLS,
                    XXXXXXX, KC_ESC,  KC_TRNS,      KC_TRNS, KC_TRNS,  XXXXXXX
),

[_FUNCTION] = LAYOUT_split_3x5_3(
/*
 ,------.------.------.------.------.            ,------.------.------.------.------.
 | F1   | F2   | F3   | F4   | F5   |            | F6   | F7   | F8   | F9   | F10  |
 |      |      |      |      |      |            |      |      |      |      |      |
 |------+------+------+------+------|            |------+------+------+------+------|
 |      |      |      |      |      |            | ←    | ↓    | ↑    | →    |      |
 | SFT  | CTL  | OPT  | CMD  |      |            |      | CMD  | OPT  | CTL  | SFT  |
 |------+------+------+------+------|            |------+------+------+------+------|
 | RGB  | RGB  | RGB  | RGB- | RGB+ |            | F11  | F12  |      |      | GAME |
 | TGGL | RMOD | MOD  |      |      |            |      |      |      |      |      |
 `------'------'------'------'------'            `------'------'------'------'------'
                         .------.------.      .------.------.
                         | ESC  | DEL  |      | ↓↓↓  | ↓↓↓  |
                         |      |      |      |      |      |
                         '------'------'      '------'------'
*/
  KC_F1,   KC_F2,    KC_F3,   KC_F4,   KC_F5,        KC_F6,   KC_F7,    KC_F8,   KC_F9,    KC_F10,
  KC_LSFT, KC_LCTL,  KC_LGUI, KC_LCMD, XXXXXXX,      KC_LEFT, HOME_DWN, HOME_UP, HOME_RGT, KC_LSFT,
  RGB_TOG, RGB_RMOD, RGB_MOD, RGB_VAD, RGB_VAI,      KC_F11,  KC_F12,   XXXXXXX, XXXXXXX,  GAMING,
                     XXXXXXX, KC_ESC,  KC_DEL,       KC_TRNS, KC_TRNS,  XXXXXXX
),

[_GAMING] = LAYOUT_split_3x5_3(
/*
 ,------.------.------.------.------.            ,------.------.------.------.------.
 | TAB  | Q    | W    | E    | R    |            | Y    | U    | I    | O    | P    |
 |      |      |      |      |      |            |      |      |      |      |      |
 |------+------+------+------+------|            |------+------+------+------+------|
 | ESC  | A    | S    | D    | F    |            | H    | J    | K    | L    | ; :  |
 |      |      |      |      |      |            |      |      |      |      |      |
 |------+------+------+------+------|            |------+------+------+------+------|
 |      | Z    | X    | C    | V    |            | N    | M    | , <  | . >  | GAME |
 | SFT  |      |      |      |      |            |      |      |      |      |      |
 `------'------'------'------'------'            `------'------'------'------'------'
                         .------.------.      .------.------.
                         |      | SPC  |      | SPC  |      |
                         | CMD  |      |      | G2   | CTL  |
                         '------'------'      '------'------'
*/
  KC_TAB,  KC_Q, KC_W,    KC_E,    KC_R,        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
  KC_ESC,  KC_A, KC_S,    KC_D,    KC_F,        KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,
  KC_LSFT, KC_Z, KC_X,    KC_C,    KC_V,        KC_N,    KC_M,    KC_COMM, KC_DOT,  GAMING,
                 XXXXXXX, KC_LCTL, KC_SPC,      G2_SPC,  KC_LOPT, XXXXXXX
),

[_GAMING_2] = LAYOUT_split_3x5_3(
/*
 ,------.------.------.------.------.            ,------.------.------.------.------.
 | ↓↓↓  |      |      |      | T    |            |      | F7   | F8   | F9   | F10  |
 |      |      |      |      |      |            |      |      |      |      |      |
 |------+------+------+------+------|            |------+------+------+------+------|
 | ↓↓↓  |      |      |      | G    |            |      | \ |  | [ {  | ] }  |      |
 |      |      |      |      |      |            |      |      |      |      |      |
 |------+------+------+------+------|            |------+------+------+------+------|
 | ↓↓↓  |      |      |      | B    |            | F11  | F12  |      |      | ↓↓↓  |
 |      |      |      |      |      |            |      |      |      |      |      |
 `------'------'------'------'------'            `------'------'------'------'------'
                         .------.------.      .------.------.
                         | ↓↓↓  | ↓↓↓  |      | ↓↓↓  | ↓↓↓  |
                         |      |      |      |      |      |
                         '------'------'      '------'------'
*/
  KC_TRNS, XXXXXXX,  XXXXXXX, XXXXXXX, KC_T,         XXXXXXX, KC_F7,   KC_F8,   KC_F9,   KC_F10,
  KC_TRNS, XXXXXXX,  XXXXXXX, XXXXXXX, KC_G,         XXXXXXX, KC_BSLS, KC_LBRC, KC_RBRC, XXXXXXX,
  KC_TRNS, XXXXXXX,  XXXXXXX, XXXXXXX, KC_B,         KC_F11,  KC_F12,  XXXXXXX, XXXXXXX, KC_TRNS,
                     XXXXXXX, KC_TRNS, KC_TRNS,      KC_TRNS, KC_TRNS, XXXXXXX
),
};


/* per key configuration */

// https://precondition.github.io/home-row-mods#finding-the-sweet-spot
bool get_ignore_mod_tap_interrupt(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case CMD_TAB: // make CMD SPC faster
        return false;
    default:
        return true;
    }
}

// https://precondition.github.io/home-row-mods#finding-the-sweet-spot
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    /* adjust home row key timing to prevent letter rolls triggering modifiers */
    case HOME_A:
    case HOME_R:
    case HOME_S:
    case HOME_T:
    case HOME_N:
    case HOME_E:
    case HOME_I:
    case HOME_O:
        return TAPPING_TERM + 50;
    default:
        return TAPPING_TERM;
    }
}

// https://beta.docs.qmk.fm/using-qmk/software-features/tap_hold
bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case NUM_BSPC:
        case FUN_SPC:
        case HOME_J:
        case HOME_K:
        case HOME_L:
        case KC_H:
        case HOME_DWN:
        case HOME_UP:
        case HOME_RGT:
        case KC_LEFT:
            return false;
        default:
            return true;
    }
}


/* custom lighting configuration */
// microcontroller leds
void led_set_kb(uint8_t usb_led) {
    if (usb_led & (1<<USB_LED_CAPS_LOCK))
        set_bit_c_LED(LED_DIM);
    else
        set_bit_c_LED(LED_OFF);
}

// underglow leds
const rgblight_segment_t PROGMEM rgb_capslock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 12, HSV_RED}
);

const rgblight_segment_t PROGMEM rgb_colemakdh_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 12, HSV_WHITE}
);

const rgblight_segment_t PROGMEM rgb_gaming_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 12, HSV_BLUE}
);

const rgblight_segment_t PROGMEM rgb_gaming2_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 12, HSV_PURPLE}
);

// Now define the array of layers. Later layers take precedence
const rgblight_segment_t* const PROGMEM rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    rgb_capslock_layer,
    rgb_colemakdh_layer, // Overrides caps lock layer
    rgb_gaming_layer,    // Overrides other layers
    rgb_gaming2_layer    // Overrides other layers
);

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = rgb_layers;
}

bool led_update_user(led_t led_state) {
    rgblight_set_layer_state(0, led_state.caps_lock);
    return true;
}

layer_state_t default_layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(1, layer_state_cmp(state, _COLEMAK_DH));
    return state;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(2, layer_state_cmp(state, _GAMING));
    rgblight_set_layer_state(3, layer_state_cmp(state, _GAMING_2));
    return state;
}
