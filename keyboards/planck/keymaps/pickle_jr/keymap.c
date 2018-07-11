#include "planck.h" 

//TODO
//Add CTRL+ALT+DELETE
//ADD CTRL+V
//ADD CTRL+C
//ADD CTRL+F
//ADD CTRL+A
//ADD CTRL+T
//ADD Print Screen
//Update mouse speeds

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _SPECIAL 3
#define _CALC 4
#define _NAV 5
#define _ADJUST 6

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

#define LPSFT SFT_T(KC_RPRN)
#define LCCTL CTL_T(KC_LCBR)
#define RCCTL MT(MOD_RCTL,KC_RCBR)
#define RPSFT MT(MOD_RSFT,KC_LPRN)

#define SCOLNAV LT(_NAV,KC_SCLN)
#define TABCALC LT(_CALC, KC_TAB)
#define QUOCALC LT(_CALC, KC_QUOT)
#define LBRACK LT(_SPECIAL,KC_LBRC)
#define RBRACK LT(_SPECIAL,KC_RBRC)

#define LOCK RGUI(KC_L)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,--------------------------------------------------------------------------------------------------.
 * | Tab/CALC |   Q      |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P      |  "/CALC |
 * |----------+----------+------+------+------+-------------+------+------+------+----------+---------|
 * | Esc      |   A      |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;/Nav  | Enter   |
 * |----------+----------+------+------+------+------|------+------+------+------+----------+---------|
 * |   (/SFT  |   Z      |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /      |  )/SFT  |
 * |----------+----------+------+------+------+------+------+------+------+------+----------+---------|
 * |   [      |   {/CTRL |   <  | GUI  | Bksp |Lower |Raise |  SPC | ALT |   >   |  }/CTRL  |  ]      |
 * `--------------------------------------------------------------------------------------------------'
 */
[_QWERTY] = {
  {TABCALC, KC_Q,  KC_W,    KC_E,    KC_R,    KC_T,   KC_Y,   KC_U,    KC_I,     KC_O,    KC_P,    QUOCALC},
  {KC_ESC,  KC_A,  KC_S,    KC_D,    KC_F,    KC_G,   KC_H,   KC_J,    KC_K,     KC_L,    SCOLNAV, KC_ENT },
  {KC_LSPO, KC_Z,  KC_X,    KC_C,    KC_V,    KC_B,   KC_N,   KC_M,    KC_COMM,  KC_DOT,  KC_SLSH, KC_RSPC},
  {LBRACK , LCCTL, KC_LABK, KC_LGUI, KC_BSPC, LOWER,  RAISE,  KC_SPC,  KC_RALT,  KC_RABK, RCCTL,   RBRACK }
},

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   F7 |   F8 |   F9 |  F10 |  F11 | F12  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |  1   |  2   |  3   |  4   |  5   |  6   |  7   |  8   |  9   |  0   | CAPS |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      | DEL  |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = {
  {KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,    KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12 },
  {KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,     KC_7,    KC_8,    KC_9,    KC_0,    KC_CAPS, _______},
  {_______, _______, _______, _______, _______,  _______, _______, _______, _______, _______, _______, _______},
  {_______, _______, _______, _______, KC_DEL, KC_TRNS,   _______, _______, _______, _______, _______, _______}
},

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |   !  |   @  |   #  |   $  |   %  |   ^  |  &   |  *   |  _   |  =   |  +   |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |  ~   |   `  | CTRL |      |  |   |      |  -   |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = {
  {_______, _______, _______, _______, _______,  _______, _______, _______, _______, _______, _______, _______},
  {KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,  KC_CIRC, KC_AMPR, KC_ASTR, KC_UNDS, KC_EQL,  KC_PLUS, _______},
  {_______, _______, KC_TILD, KC_GRV,  KC_LCTRL, _______, KC_PIPE, _______, KC_MINS, KC_COLN, _______, _______},
  {_______, _______, _______, _______, _______,  _______, KC_TRNS, _______, _______, _______, _______, _______}
},

/* Special
 * ,-----------------------------------------------------------------------------------.
 * |      |  M2  | MUP  |  M1  | WUP  |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |MLEFT |MDOWN |MRIGHT|WDOWN |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |WLEFT |  M3  |WRIGHT|      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | PREV | PLAY | NEXT |      |      | LOCK |      | MUTE | VOL- | VOL+ |      |
 * `-----------------------------------------------------------------------------------'
 */
[_SPECIAL] = {
  {_______,  KC_BTN2,  KC_MS_U, KC_BTN1, KC_WH_U, _______, _______, _______, _______, _______, _______, _______},
  {_______,  KC_MS_L,  KC_MS_D, KC_MS_R, KC_WH_D, _______, _______, _______, _______, _______, _______, _______},
  {_______,  KC_WH_L,  KC_BTN3, KC_WH_R, _______, _______, _______, _______, _______, _______, _______, _______},
  {KC_TRNS,  KC_MPRV,  KC_MPLY, KC_MNXT, _______, _______, LOCK,    _______, KC_MUTE, KC_VOLD, KC_VOLU, KC_TRNS}
},

/* Calc
 * ,-----------------------------------------------------------------------------------.
 * |      |   F7 |  F8  |  F9  |      |      |  *   |   7  |  8   |  9   |  /   |  \   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |   F4 |  F5  |  F6  |      |      |  +   |   4  |  5   |  6   |  -   |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |   F1 |  F2  |  F3  |      |      |      |   1  |  2   |  3   |  =   |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |  F11 |  F12 |      | DEL  | Bksp |  0   |      |      |      | RET  |
 * `-----------------------------------------------------------------------------------'
 */
[_CALC] = {
  {KC_TRNS,  KC_F7,   KC_F8,   KC_F9,   _______, _______, KC_ASTR, KC_7, KC_8,    KC_9,    KC_BSLS, KC_TRNS },
  {_______,  KC_F4,   KC_F5,   KC_F6,   _______, _______, KC_PLUS, KC_4, KC_5,    KC_6,    KC_MINS, _______ },
  {_______,  KC_F1,   KC_F2,   KC_F3,   _______, _______, _______, KC_1, KC_2,    KC_3,    KC_EQL,  _______ },
  {_______,  _______, KC_F11,  KC_F12,  _______, KC_DEL,  KC_BSPC, KC_0, _______, _______, KC_ENT,  _______ }
},

/* Nav
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      | HOME | PGUP | PGDN | END  | LEFT | DOWN |  UP  |RIGHT |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |SUPER |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_NAV] = {
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______},
  {_______, _______, KC_HOME, KC_PGUP, KC_PGDN, KC_END,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_TRNS, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______},
  {_______, _______, _______, _______, KC_LGUI, _______, _______, _______, _______, _______, _______,  _______}
},

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|      |      |      |      |      |      |      |      |      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |Aud on|Audoff|AGnorm|AGswap|Qwerty|Colemk|Dvorak|Plover|      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = {
  {_______, RESET,   _______, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD,  RGB_VAI, RGB_VAD, KC_DEL },
  {_______, _______, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, _______, _______,  _______, _______, _______},
  {_______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  TERM_ON, TERM_OFF, _______, _______, _______},
  {_______, _______, _______, _______, _______, KC_TRNS, KC_TRNS, _______, _______,  _______, _______, _______}
}


};

#ifdef AUDIO_ENABLE
  float plover_song[][2]     = SONG(PLOVER_SOUND);
  float plover_gb_song[][2]  = SONG(PLOVER_GOODBYE_SOUND);
#endif

uint32_t layer_state_set_user(uint32_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case RAISE:
    case LOWER:
      return false;
    default:
      return true;
  }
}
