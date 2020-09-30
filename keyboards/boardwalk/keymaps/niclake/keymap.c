/*
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H

// Layer shorthand
enum layer_names {
    _BASE,
    _QWERTY,
    _RAISE,
    _LOWER,
    _NUM,
    _ADJ,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

k    /* Base Layer (Colemak)
     * .-----------------------------------------------------------------------------------------------------------------------------.
     * | `      | 1      | 2      | 3      | 4      | 5      | -      | =      | 6      | 7      | 8      | 9      | 0      | BACKSP |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
     * | TAB    | Q      | W      | F      | P      | G      | [      | ]      | J      | L      | U      | Y      | ;      | \      |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
     * | _RAISE | A      | R      | S      | T      | D      | HOME   | PG UP  | H      | N      | E      | I      | O      | '      |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
     * | LSHIFT | Z      | X      | C      | V      | B      | END    | PG DN  | K      | M      | ,      | .      | /      | RSHIFT |
     * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+-----------------+--------+--------|
     * | LCTRL  | LALT   | LGUI   | ??     | TG_NUM |      ENTER      |      SPACE      | _LOWER | ????   | RGUI   | RALT   | RCTRL  |
     * '-----------------------------------------------------------------------------------------------------------------------------'
     */
    [_BASE] = LAYOUT_ortho_2x2u(
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_MINS, KC_EQL,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
        KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_LBRC, KC_RBRC, KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSLS,
        MO(_RAISE), KC_A, KC_R,    KC_S,    KC_T,    KC_D,    KC_HOME, KC_PGUP, KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_END,  KC_PGDN, KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
        KC_LCTL, KC_LALT, KC_LGUI, KC_??,   TT(_NUM),    KC_ENT,           KC_SPC,       KC_LEFT, KC_????, KC_RGUI, KC_RALT, KC_RCTL
    ),

    /* QWERTY
     * .-----------------------------------------------------------------------------------------------------------------------------.
     * | `      | 1      | 2      | 3      | 4      | 5      | -      | =      | 6      | 7      | 8      | 9      | 0      | BACKSP |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
     * | TAB    | Q      | W      | E      | R      | T      | [      | ]      | Y      | U      | I      | O      | P      | \      |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
     * | _RAISE | A      | S      | D      | F      | G      | HOME   | PG UP  | H      | J      | K      | L      | ;      | '      |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
     * | LSHIFT | Z      | X      | C      | V      | B      | END    | PG DN  | N      | M      | ,      | .      | /      | RSHIFT |
     * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+-----------------+--------+--------|
     * | LCTRL  | LALT   | LGUI   | ??     | TG_NUM |      ENTER      |      SPACE      | _LOWER | ????   | RGUI   | RALT   | RCTRL  |
     * '-----------------------------------------------------------------------------------------------------------------------------'
     */
    [_QWERTY] = LAYOUT_ortho_2x2u(
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_MINS, KC_EQL,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_LBRC, KC_RBRC, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
        MO(_RAISE), KC_A, KC_S,    KC_D,    KC_F,    KC_G,    KC_HOME, KC_PGUP, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_END,  KC_PGDN, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
        KC_LCTL, KC_LALT, KC_LGUI, KC_??,   TT(_NUM),    KC_ENT,           KC_SPC,       KC_LEFT, KC_????, KC_RGUI, KC_RALT, KC_RCTL
    ),

    /* RAISE
     * .-----------------------------------------------------------------------------------------------------------------------------.
     * | ESC    | F1     | F2     | F3     | F4     | F5     | F11    | F12    | F6     | F7     | F8     | F9     | F10    | DEL    |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
     * |        | Prev   | Play   | Next   |        |        |        |        |        | Pg Up  | Up     | Pg Dn  | PRT SC |        |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
     * | _raise |        | Mute   | Vol Dn | Vol Up |        |        |        |        | Left   | Down   | Right  |        |        |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
     * |        |        |        |        |        |        |        |        |        | Home   |        | End    |        | CapsLk |
     * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+-----------------+--------+--------|
     * |        |        |        |        | TG_NUM |                 |                 | _ADJ   |        |        |        |        |
     * '-----------------------------------------------------------------------------------------------------------------------------'
     */
    [_RAISE] = LAYOUT_ortho_2x2u(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,    KC_F5,   KC_F11,  KC_F12,  KC_F6,   KC_F7,    KC_F8,   KC_F9,   KC_F10,  KC_DEL,
        _______, KC_MPRV, KC_MPLY, KC_MNXT, _______,  _______, _______, _______, _______, KC_PGUP,  KC_UP,   KC_PGDN, KC_PSCR, _______,
        _______, _______, KC_MUTE, KC_VOLD, KC_VOLU,  _______, _______, _______, _______, KC_LEFT,  KC_DOWN, KC_RGHT, _______, _______,
        _______, _______, _______, _______, _______,  _______, _______, _______, _______, KC_HOME,  _______, KC_END,  _______, KC_CAPS,
        _______, _______, _______, _______, TT(_NUM),     _______,          _______,      MO(_ADJ), _______, _______, _______, _______
    ),

    /* LOWER - Currently unused and awaiting whatever I want to do
     * .-----------------------------------------------------------------------------------------------------------------------------.
     * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
     * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
     * | _ADJ   |        |        |        |        |        |        |        |        |        |        |        |        |        |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
     * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
     * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+-----------------+--------+--------|
     * |        |        |        |        |        |                 |                 | _lower |        |        |        |        |
     * '-----------------------------------------------------------------------------------------------------------------------------'
     */
    [_LOWER] = LAYOUT_ortho_2x2u(
        _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        MO(_ADJ), _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______,  _______, _______, _______, _______,     _______,          _______,      _______, _______, _______, _______, _______
    ),

    /* Num Pad (NUM)
     * .-----------------------------------------------------------------------------------------------------------------------------.
     * |        |        |        |        |        |        |        |        | Num Lk | KP /   | KP *   | KP -   | Scr Lk | Pause  |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
     * |        |        |        |        |        |        |        |        | KP 7   | KP 8   | KP 9   | KP +   |        |        |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
     * |        |        |        |        |        |        |        |        | KP 4   | KP 5   | KP 6   | KP +   |        |        |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
     * |        |        |        |        |        |        |        |        | KP 1   | KP 2   | KP 3   | KP Ent |        |        |
     * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+-----------------+--------+--------|
     * |        |        |        |        | _num   |                 | KP 0            | KP 0   | KP .   | KP Ent |        |        |
     * '-----------------------------------------------------------------------------------------------------------------------------'
     */
    [_NUM] = LAYOUT_ortho_2x2u(
        _______, _______, _______, _______, _______, _______, _______, _______, KC_NLCK, KC_PSLS, KC_PAST, KC_PMNS, KC_SLCK, KC_PAUS,
        _______, _______, _______, _______, _______, _______, _______, _______, KC_KP_7, KC_KP_8, KC_KP_9, KC_PPLS, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, KC_KP_4, KC_KP_5, KC_KP_6, KC_PPLS, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, KC_KP_1, KC_KP_2, KC_KP_3, KC_PENT, _______, _______,
        _______, _______, _______, _______, _______,     _______,          KC_KP_0,      KC_KP_0, KC_PDOT, KC_PENT, _______, _______
    ),

    /* ADJUST
     * .-----------------------------------------------------------------------------------------------------------------------------.
     * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
     * |        | RESET  |        |        |        |        |        |        |        |        |        |        |        |        |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
     * | _raise |        |        |        |        |        |        |        |        |        |        |        |        |        |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
     * |        | Colemak| QWERTY |        |        |        |        |        |        |        |        |        |        |        |
     * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+-----------------+--------+--------|
     * |        |        |        |        |        |                 |                 | _lower |        |        |        |        |
     * '-----------------------------------------------------------------------------------------------------------------------------'
     */
    [_ADJ] = LAYOUT_ortho_2x2u(
        _______, _______,   _______,     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, RESET,     _______,     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______,   _______,     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, DF(_BASE), DF(_QWERTY), _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______,   _______,     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    )

};
