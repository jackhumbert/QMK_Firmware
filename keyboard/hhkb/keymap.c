/*
Copyright 2011,2012,2013 Jun Wako <wakojun@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

/* 
 * Keymap for PFU HHKB Pro
 */
#include <stdint.h>
#include <stdbool.h>
#include <avr/pgmspace.h>
#include "host.h"
#include "keycode.h"
#include "print.h"
#include "debug.h"
#include "util.h"
#include "action.h"
#include "keymap.h"


// Convert physical keyboard layout to matrix array.
// This is a macro to define keymap easily in keyboard layout form.
#define KEYMAP( \
    K31, K30, K00, K10, K11, K20, K21, K40, K41, K60, K61, K70, K71, K50, K51, \
    K32, K01, K02, K13, K12, K23, K22, K42, K43, K62, K63, K73, K72, K52, \
    K33, K04, K03, K14, K15, K24, K25, K45, K44, K65, K64, K74, K53, \
    K34, K05, K06, K07, K16, K17, K26, K46, K66, K76, K75, K55, K54, \
         K35, K36,           K37,                K57, K56 \
) \
{ \
    { KC_##K00, KC_##K01, KC_##K02, KC_##K03, KC_##K04, KC_##K05, KC_##K06, KC_##K07 }, \
    { KC_##K10, KC_##K11, KC_##K12, KC_##K13, KC_##K14, KC_##K15, KC_##K16, KC_##K17 }, \
    { KC_##K20, KC_##K21, KC_##K22, KC_##K23, KC_##K24, KC_##K25, KC_##K26, KC_NO    }, \
    { KC_##K30, KC_##K31, KC_##K32, KC_##K33, KC_##K34, KC_##K35, KC_##K36, KC_##K37 }, \
    { KC_##K40, KC_##K41, KC_##K42, KC_##K43, KC_##K44, KC_##K45, KC_##K46, KC_NO    }, \
    { KC_##K50, KC_##K51, KC_##K52, KC_##K53, KC_##K54, KC_##K55, KC_##K56, KC_##K57 }, \
    { KC_##K60, KC_##K61, KC_##K62, KC_##K63, KC_##K64, KC_##K65, KC_##K66, KC_NO    }, \
    { KC_##K70, KC_##K71, KC_##K72, KC_##K73, KC_##K74, KC_##K75, KC_##K76, KC_NO    } \
}


static const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Layer 0: Default Layer
     * ,-----------------------------------------------------------.
     * |Esc|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|  \|  `|
     * |-----------------------------------------------------------|
     * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|Backs|
     * |-----------------------------------------------------------|
     * |Contro|  A|  S|  D|  F|  G|  H|  J|  K|  L|Fn3|  '|Return  |
     * |-----------------------------------------------------------|
     * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|Fn2|Shift |Fn1|
     * `-----------------------------------------------------------'
     *       |Gui|Alt  |Fn5                    |Alt  |Fn4|
     *       `-------------------------------------------'
     */
    KEYMAP(ESC, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   MINS,EQL, BSLS,GRV, \
           TAB, Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,   LBRC,RBRC,BSPC, \
           FN6, A,   S,   D,   F,   G,   H,   J,   K,   L,   FN3, QUOT,FN7, \
           FN8, Z,   X,   C,   V,   B,   N,   M,   COMM,DOT, FN2, FN12,FN10, \
                LGUI,LALT,          FN5,                RALT,FN4),

    /* Layer 1: HHKB mode (HHKB Fn)
     * ,-----------------------------------------------------------.
     * |Esc| F1| F2| F3| F4| F5| F6| F7| F8| F9|F10|F11|F12|Ins|Del|
     * |-----------------------------------------------------------|
     * |Caps |   |   |   |   |   |   |   |Psc|Slk|Pus|Up |   |Backs|
     * |-----------------------------------------------------------|
     * |Contro|VoD|VoU|Mut|   |   |  *|  /|Hom|PgU|Lef|Rig|Enter   |
     * |-----------------------------------------------------------|
     * |Shift   |   |   |   |   |   |  +|  -|End|PgD|Dow|Shift |Fn0|
     * `-----------------------------------------------------------'
     *      |Gui |Alt  |Space                  |Alt  |xxx|
     *      `--------------------------------------------'
     */ 
    KEYMAP(PWR, F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9,  F10, F11, F12, INS, DEL, \
           CAPS,NO,  NO,  NO,  NO,  NO,  NO,  NO,  PSCR,SLCK,BRK, UP,  NO,  BSPC, \
           LCTL,VOLD,VOLU,MUTE,NO,  NO,  PAST,PSLS,HOME,PGUP,LEFT,RGHT,ENT, \
           LSFT,NO,  NO,  NO,  NO,  NO,  PPLS,PMNS,END, PGDN,DOWN,RSFT,FN10, \
                LGUI,LALT,          SPC,                RALT,RGUI),

    /* Layer 2: Vi mode (Slash)
     * ,-----------------------------------------------------------.
     * |Esc| F1| F2| F3| F4| F5| F6| F7| F8| F9|F10|F11|F12|Ins|Del|
     * |-----------------------------------------------------------|
     * |Tab  |Hom|PgD|Up |PgU|End|Hom|PgD|PgUlEnd|   |   |   |Backs|
     * |-----------------------------------------------------------|
     * |Contro|   |Lef|Dow|Rig|   |Lef|Dow|Up |Rig|   |   |Return  |
     * |-----------------------------------------------------------|
     * |Shift   |   |   |   |   |   |Hom|PgD|PgUlEnd|Fn0|Shift |   |
     * `-----------------------------------------------------------'
     *       |Gui|Alt  |Space                  |Alt  |Gui|
     *       `-------------------------------------------'
     */
    KEYMAP(ESC, F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9,  F10, F11, F12, INS, DEL, \
           TAB, HOME,PGDN,UP,  PGUP,END, HOME,PGDN,PGUP,END, NO,  NO,  NO,  BSPC, \
           LCTL,NO,  LEFT,DOWN,RGHT,NO,  LEFT,DOWN,UP,  RGHT,NO,  NO,  ENT, \
           LSFT,NO,  NO,  NO,  NO,  NO,  HOME,PGDN,PGUP,END, FN0, RSFT,NO, \
                LGUI,LALT,          SPC,                RALT,RGUI),

    /* Layer 3: Mouse mode (Semicolon)
     * ,-----------------------------------------------------------.
     * |Esc| F1| F2| F3| F4| F5| F6| F7| F8| F9|F10|F11|F12|Ins|Del|
     * |-----------------------------------------------------------|
     * |Tab  |MwL|MwU|McU|MwD|MwR|MwL|MwD|MwU|MwR|   |   |   |Backs|
     * |-----------------------------------------------------------|
     * |Contro|   |McL|McD|McR|   |McL|McD|McU|McR|Fn0|   |Return  |
     * |-----------------------------------------------------------|
     * |Shift   |Mb4|Mb5|Mb1|Mb2|Mb3|Mb2|Mb1|Mb4|Mb5|   |Shift |   |
     * `-----------------------------------------------------------'
     *      |Gui |Alt  |Mb1                    |Alt  |Fn0|
     *      `--------------------------------------------'
     * Mc: Mouse Cursor / Mb: Mouse Button / Mw: Mouse Wheel 
     */
    KEYMAP(ESC, F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9,  F10, F11, F12, INS, DEL, \
           TAB, NO,  NO,  NO,  NO,  NO,  WH_L,WH_D,WH_U,WH_R,NO,  NO,  NO,  BSPC, \
           LCTL,NO,  ACL0,ACL1,ACL2,NO,  MS_L,MS_D,MS_U,MS_R,FN0, QUOT,ENT, \
           LSFT,NO,  NO,  NO,  NO,  BTN3,BTN2,BTN1,BTN4,BTN5,SLSH,RSFT,NO, \
                LGUI,LALT,          BTN1,               RALT,FN0),

    /* Layer 4: Matias half keyboard style (Space)
     * ,-----------------------------------------------------------.
     * |  -|  0|  9|  8|  7|  6|  5|  4|  3|  2|  1|   |   |   |Esc|
     * |-----------------------------------------------------------|
     * |Backs|  P|  O|  I|  U|  Y|  T|  R|  E|  W|  Q|   |   |Tab  |
     * |-----------------------------------------------------------|
     * |Contro|  ;|  L|  K|  J|  H|  G|  F|  D|  S|  A|Con|Control |
     * |-----------------------------------------------------------|
     * |Shift   |  /|  .|  ,|  M|  N|  B|  V|  C|  X|  Z|Shift |   |
     * `-----------------------------------------------------------'
     *      |Gui |Alt  |          Fn0          |Alt  |Gui|
     *      `--------------------------------------------'
     */
    KEYMAP(MINS,0,   9,   8,   7,   6,   5,   4,   3,   2,   1,   NO,  NO,  NO,  ESC, \
           BSPC,P,   O,   I,   U,   Y,   T,   R,   E,   W,   Q,   NO,  NO,  TAB, \
           LCTL,SCLN,L,   K,   J,   H,   G,   F,   D,   S,   A,   RCTL,RCTL, \
           LSFT,SLSH,DOT, COMM,M,   N,   B,   V,   C,   X,   Z,   RSFT,NO, \
                LGUI,LALT,          FN0,                RALT,RGUI),

    /* Layer5: another Mouse mode (Space) */
    KEYMAP(ESC, F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9,  F10, F11, F12, INS, DEL, \
           TAB, NO,  NO,  NO,  NO,  NO,  WH_L,WH_D,WH_U,WH_R,NO,  NO,  NO,  BSPC, \
           LCTL,NO,  ACL0,ACL1,ACL2,NO,  MS_L,MS_D,MS_U,MS_R,FN0, NO,  ENT, \
           LSFT,NO,  NO,  NO,  NO,  BTN3,BTN2,BTN1,BTN4,BTN5,NO,  RSFT,NO, \
                LGUI,LALT,          FN0,                RALT,RGUI),
};



/* id for user defined functions */
enum function_id {
    LSHIFT_LPAREN,
    RSHIFT_RPAREN,
};

/*
 * Fn action definition
 */
static const uint16_t PROGMEM fn_actions[] = {
    ACTION_LAYER_RETURN_DEFAULT,                    // FN0
    ACTION_LAYER_SET(1),                            // FN1
    ACTION_LAYER_SET_TAP_KEY(2, KC_SLASH),          // FN2
    ACTION_LAYER_SET_TAP_KEY(3, KC_SCLN),           // FN3
    ACTION_LAYER_SET(3),                            // FN4
    ACTION_LAYER_SET_TAP_KEY(5, KC_SPC),            // FN5
    ACTION_LMOD_TAP_KEY(KC_LCTL, KC_BSPC),          // FN6
    ACTION_RMOD_TAP_KEY(KC_RCTL, KC_ENT),           // FN7
    ACTION_LMOD_ONESHOT(KC_LSFT),                   // FN8    Oneshot Shift
    ACTION_LAYER_SET_ON_RELEASED_TAP_TOGGLE(1),     // FN9
    ACTION_LAYER_BIT_TAP_KEY(1, KC_GRV),            // FN10
    //ACTION_LAYER_BIT(1),                          // FN10
    //ACTION_LAYER_BIT_TAP_TOGGLE(1),               // FN10
    ACTION_FUNCTION_TAP(LSHIFT_LPAREN),             // FN11
    ACTION_FUNCTION_TAP(RSHIFT_RPAREN),             // FN12
};

/*
 * user defined action function
 */
void keymap_call_function(keyrecord_t *record, uint8_t id)
{
    keyevent_t event = record->event;
    uint8_t tap_count = record->tap_count;

    debug("action_call_function: ");
    if (event.pressed) debug("pressed"); else debug("released");
    debug(" id: "); debug_hex(id);
    debug(" tap_count: "); debug_dec(tap_count);
    debug("\n");

    switch (id) {
        case LSHIFT_LPAREN:
            // LShft + tap '('
            if (event.pressed) {
                if (tap_count == 0) {
                    add_mods(MOD_BIT(KC_LSHIFT));
                } else {
                    if (waiting_buffer_has_anykey_pressed()) {
                        // ad hoc: set 0 to cancel tap
                        record->tap_count = 0;
                        add_mods(MOD_BIT(KC_LSHIFT));
                    } else {
                        // NOTE to avoid conflicting command key bind(LShift+RShift)
                        //register_code(KC_LSHIFT);
                        //register_code(KC_9);
                        host_add_mods(MOD_BIT(KC_LSHIFT));
                        host_add_key(KC_9);
                        host_send_keyboard_report();
                    }
                }
            } else {
                if (tap_count == 0) {
                    del_mods(MOD_BIT(KC_LSHIFT));
                } else {
                    //unregister_code(KC_9);
                    //unregister_code(KC_LSHIFT);
                    host_del_mods(MOD_BIT(KC_LSHIFT));
                    host_del_key(KC_9);
                    host_send_keyboard_report();
                }
            }
            break;
        case RSHIFT_RPAREN:
            // RShift + tap ')'
            if (event.pressed) {
                if (tap_count == 0) {
                    add_mods(MOD_BIT(KC_RSHIFT));
                } else {
                    if (waiting_buffer_has_anykey_pressed()) {
                        // ad hoc: set 0 to cancel tap
                        record->tap_count = 0;
                        add_mods(MOD_BIT(KC_RSHIFT));
                    } else {
                        //register_code(KC_RSHIFT);
                        //register_code(KC_0);
                        host_add_mods(MOD_BIT(KC_RSHIFT));
                        host_add_key(KC_0);
                        host_send_keyboard_report();
                    }
                }
            } else {
                if (tap_count == 0) {
                    del_mods(MOD_BIT(KC_RSHIFT));
                } else {
                    //unregister_code(KC_0);
                    //unregister_code(KC_RSHIFT);
                    host_del_mods(MOD_BIT(KC_RSHIFT));
                    host_del_key(KC_0);
                    host_send_keyboard_report();
                }
            }
            break;
    }
}

/* convert keycode to action */
action_t keymap_get_action(uint8_t layer, uint8_t row, uint8_t col) {
    uint8_t key = (pgm_read_byte(&keymaps[(layer)][(row)][(col)]));
    action_t action;
    switch (key) {
        case KC_A ... KC_EXSEL:
            action.code = ACTION_KEY(key);
            break;
        case KC_LCTRL ... KC_LGUI:
            action.code = ACTION_LMOD(key);
            break;
        case KC_RCTRL ... KC_RGUI:
            action.code = ACTION_RMOD(key);
            break;
        case KC_SYSTEM_POWER ... KC_SYSTEM_WAKE:
            action.code = ACTION_USAGE_SYSTEM(KEYCODE2SYSTEM(key));
            break;
        case KC_AUDIO_MUTE ... KC_WWW_FAVORITES:
            action.code = ACTION_USAGE_CONSUMER(KEYCODE2CONSUMER(key));
            break;
        case KC_MS_UP ... KC_MS_ACCEL2:
            action.code = ACTION_MOUSEKEY(key);
            break;
        case KC_FN0 ... KC_FN31:
            if (FN_INDEX(key) < sizeof(fn_actions) / sizeof(fn_actions[0])) {
                action.code = pgm_read_word(&fn_actions[FN_INDEX(key)]);
            } else {
                action.code = ACTION_NO;
            }
            break;
        case KC_NO ... KC_UNDEFINED:
        default:
            action.code = ACTION_NO;
            break;
    }
    return action;
}
