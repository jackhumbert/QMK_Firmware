#include QMK_KEYBOARD_H

/*
NQN is not-quite-neo
A layout based on neo2
*/

#include "action_layer.h"
#include "version.h"

#include "nqn-keys-on-quertz-de-latin1.h"
#include "nqn-basic-layout.h"

// Since our quirky block definitions are basically a list of comma separated 
// arguments, we need a wrapper in order for these definitions to be 
// expanded before being used as arguments to the LAYOUT_xxx macro.
#define LAYOUT_ergodox_wrapper(...) LAYOUT_ergodox(__VA_ARGS__)

#ifdef LEADER_TIMEOUT
#undef LEADER_TIMEOUT
#endif
#define LEADER_TIMEOUT 300

#define TAP_ONCE(code)  \
  register_code (code); \
  unregister_code (code)


// Automatic number generation of important keywords
enum my_keycodes{
    // Layer numbers follow the neo2 terminology, i.e. base layer = layer 1
    L01 = 0,
    /* L02, SHIFT is not (yet) implemented as a fully customizable layer */
    L03,
    L04,
    L05,
    /* L06, UNSPECIFIED not (yet) needed */
    LFN
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* L01 -> default: BASE LAYER
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | TAB    |   1  |   2  |   3  |   4  |   5  |      |           |      |   6  |   7  |   8  |   9  |   0  | BACKSP |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | ESC    |                                  | LEADR|           | LEADR|                                  | ENTER  |
 * |--------+                                  |      |           |      |                                  +--------|
 * | L03    |             L01_LEFT             |------|           |------|             L01_RIGHT            | L03    |
 * |--------+                                  | LFN  |           | LFN  |                                  +--------|
 * | SHIFT  |                                  |      |           |      |                                  | SHIFT  |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | CTRL | GUI  | ALT  | L05  | L04  |                                       | L04  | L05  | ALTGR| LFN  | CTRL |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | HOME | END  |       | LEFT | RIGHT|
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      | PGUP |       | UP   |      |      |
 *                                 | SPACE| SHIFT|------|       |------| SHIFT| SPACE|
 *                                 |      |      | PGDN |       | DOWN |      |      |
 *                                 `--------------------'       `--------------------'
 */
[L01] = LAYOUT_ergodox_wrapper(
  KC_TAB,  KC_1,   KC_2,    KC_3,    KC_4,    KC_5,    XXXXXXX,
  KC_ESC,                 L01_LEFT_01,                 KC_LEAD,
  MO(L03),                L01_LEFT_02,
  KC_LSHIFT,              L01_LEFT_03,                 MO(LFN),
  KC_LCTRL,KC_LGUI,KC_LALT, MO(L05), MO(L04),
                                              XXXXXXX, XXXXXXX,
                                                       KC_PGUP,
                                     KC_SPACE,KC_LSHIFT,KC_PGDN,
  //--
  XXXXXXX,  KC_6,   KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPACE,
  KC_LEAD,                L01_RIGHT_01,                 KC_ENTER,
                          L01_RIGHT_02,                 MO(L03),
  MO(LFN),                L01_RIGHT_03,                 KC_RSHIFT,
                    MO(L04), MO(L05), KC_RALT, MO(LFN), KC_RCTRL,
  KC_LEFT, KC_RIGHT,
  KC_UP,
  KC_DOWN, KC_RSHIFT, KC_SPACE
),


/*
L02 -> MO(L02): SHIFT (as a layer not used, not defined, not reachable)
 */


/* L03 -> MO(L03): PROGRAMMING
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |                                  |      |           |      |                                  |        |
 * |--------+                                  |      |           |      |                                  +--------|
 * |        |             L03_LEFT             |------|           |------|             L03_RIGHT            |        |
 * |--------+                                  |      |           |      |                                  +--------|
 * |        |                                  |      |           |      |                                  |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[L03] = LAYOUT_ergodox_wrapper(
  _______, _______, _______, _______, _______, _______, _______,
  _______,                 L03_LEFT_01,                 _______,
  _______,                 L03_LEFT_02,
  _______,                 L03_LEFT_03,                 _______,
  _______, _______, _______, _______, _______,
                                               _______, _______,
                                                        _______,
                                      _______, _______, _______,
  //--
  _______, _______, _______, _______, _______, _______, _______,
  _______,                 L03_RIGHT_01,                _______,
                           L03_RIGHT_02,                _______,
  _______,                 L03_RIGHT_03,                _______,
                    _______, _______, _______, _______, _______,
  _______, _______,
  _______,
  _______, _______, _______
),

/* L04 -> MO(L04): NAVIGATION AND NUMBERS
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |                                  |      |           |      |                                  |        |
 * |--------+                                  |      |           |      |                                  +--------|
 * |        |             L04_LEFT             |------|           |------|             L04_RIGHT            |        |
 * |--------+                                  |      |           |      |                                  +--------|
 * |        |                                  |      |           |      |                                  |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 | 0    |      |------|       |------|      | 0    |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[L04] = LAYOUT_ergodox_wrapper(
  _______, _______, _______, _______, _______, _______, _______,
  _______,                 L04_LEFT_01,                 _______,
  _______,                 L04_LEFT_02,
  _______,                 L04_LEFT_03,                 _______,
  _______, _______, _______, _______, _______,
                                               _______, _______,
                                                        _______,
                                      KC_0,    _______, _______,
  //--
  _______, _______, _______, _______, _______, _______, _______,
  _______,                 L04_RIGHT_01,                _______,
                           L04_RIGHT_02,                _______,
  _______,                 L04_RIGHT_03,                _______,
                    _______, _______, _______, _______, _______,
  _______, _______,
  _______,
  _______, _______, KC_0
),


/* L05 -> MO(L05): ALTERNATE
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |                                  |      |           |      |                                  |        |
 * |--------+                                  |      |           |      |                                  +--------|
 * |        |             L05_LEFT             |------|           |------|             L05_RIGHT            |        |
 * |--------+                                  |      |           |      |                                  +--------|
 * |        |                                  |      |           |      |                                  |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[L05] = LAYOUT_ergodox_wrapper(
  _______, _______, _______, _______, _______, _______, _______,
  _______,                 L05_LEFT_01,                 _______,
  _______,                 L05_LEFT_02,
  _______,                 L05_LEFT_03,                 _______,
  _______, _______, _______, _______, _______,
                                               _______, _______,
                                                        _______,
                                      _______, _______, _______,
  //--
  _______, _______, _______, _______, _______, _______, _______,
  _______,                 L05_RIGHT_01,                _______,
                           L05_RIGHT_02,                _______,
  _______,                 L05_RIGHT_03,                _______,
                    _______, _______, _______, _______, _______,
  _______, _______,
  _______,
  _______, _______, _______
),


/*
L06 -> <TBD>: UNSPECIFIED
*/


/* LFN -> MO(FN): FUNCTION
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | QK_BOOT  |      |      |      |      |      |      |           |      |      |      |      |      |      | QK_BOOT  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |                                  |      |           |      |                                  | BACKSPC|
 * |--------+                                  |      |           |      |                                  +--------|
 * |        |             L06_LEFT             |------|           |------|             L06_RIGHT            | INSERT |
 * |--------+                                  |      |           |      |                                  +--------|
 * |        |                                  |      |           |      |                                  | DELETE |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       | VOL+ | VOL- | MUTE |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[LFN] = LAYOUT_ergodox_wrapper(
  QK_BOOT, _______, _______, _______, _______, _______, _______,
  _______,                 L06_LEFT_01,                 _______,
  _______,                 L06_LEFT_02,
  _______,                 L06_LEFT_03,                 _______,
  _______, _______, _______, _______, _______,
                                               _______, _______,
                                                        _______,
                                      _______, _______, _______,
  //--
  _______, _______, _______, _______, _______, _______, QK_BOOT,
  _______,                 L06_RIGHT_01,                KC_BSPACE,
                           L06_RIGHT_02,                KC_INSERT,
  _______,                 L06_RIGHT_03,                KC_DELETE,
                    KC_VOLU, KC_VOLD, KC_MUTE, _______, _______,
  _______, _______,
  _______,
  _______, _______, _______
)

};

void leader_end_user(void) {
  if (leader_sequence_one_key(KC_1)) {
    // ¯\_(ツ)_/¯
    unicode_input_start(); register_hex(0xaf); unicode_input_finish();
    register_code (KC_RALT); TAP_ONCE (KC_MINS); unregister_code (KC_RALT);
    register_code (KC_RSFT); TAP_ONCE (KC_8); unregister_code (KC_RSFT);
    unicode_input_start (); register_hex(0x30c4); unicode_input_finish();
    register_code (KC_RSFT); TAP_ONCE (KC_9); TAP_ONCE(KC_7); unregister_code (KC_RSFT);
    unicode_input_start (); register_hex(0xaf); unicode_input_finish();
  }

  if (leader_sequence_one_key(KC_2)) {
    // 凸(ツ)凸
    unicode_input_start(); register_hex(0x51F8); unicode_input_finish();
    register_code (KC_RSFT); TAP_ONCE (KC_8); unregister_code (KC_RSFT);
    unicode_input_start (); register_hex(0x30c4); unicode_input_finish();
    register_code (KC_RSFT); TAP_ONCE (KC_9); unregister_code (KC_RSFT);
    unicode_input_start (); register_hex(0x51F8); unicode_input_finish();
  }
}


// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
  set_unicode_input_mode(UC_LNX);
};
