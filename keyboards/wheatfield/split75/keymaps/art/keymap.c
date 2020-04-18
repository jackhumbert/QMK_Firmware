#include QMK_KEYBOARD_H
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <sendstring_workman_zxcvm.h>

enum layer_names {
	QWERTY, //TODO - MAKE BASE 1ST
  BASE,
  QWERTY_MOD,

  WORKMAN,
  MOD,
  MEDIA,
	COMBOS,
	STRINGS,
	LAYOUT_CHG,
	CONFIG,
	GIT,
	GIT_C,
	GIT_P,
	GIT_S
};

enum custom_keycodes {
  CTRL_CTV = SAFE_RANGE,
	SARCASM,

	TOG_OS,
	CTR_ALT,
  OS_HOME,
  OS_END,

  ADMINS,
  PRESCRIPTION,
  PHONE,
  FOURS,
  

	G_ADD,
	G_BRCH,
	G_C,
	G_BS_C,
	G_CHEC,	
	G_COMM,
	G_DIFF,
	G_FTCH,
	G_LOG,
	G_MERG,
	G_P,
	// G_BS_P,
	// G_PULL,
	// G_PUSH,
	G_RST,
	G_S,
	G_BS_S,
	G_STAT,
	G_STSH,
	G_SHOW,
};

bool led_update_user(led_t led_state) {
  writePin(CAPSLOCK_LED_PIN, led_state.caps_lock);
  return false;
}

void keyboard_pre_init_user(void) {
  writePinHigh(SCROLLLOCK_LED_PIN);
  wait_ms(50);
  writePinHigh(CAPSLOCK_LED_PIN);
  wait_ms(50);
  writePinHigh(NUMLOCK_LED_PIN);
  wait_ms(50);
  writePinLow(SCROLLLOCK_LED_PIN);
  wait_ms(50);
  writePinLow(CAPSLOCK_LED_PIN);
  wait_ms(50);
  writePinLow(NUMLOCK_LED_PIN);
	
	layer_state_set_user(layer_state);
}

layer_state_t layer_state_set_user(layer_state_t state) {
  writePinLow(NUMLOCK_LED_PIN);
  writePinLow(SCROLLLOCK_LED_PIN);
  switch (get_highest_layer(state)) {
  case BASE:
      writePinHigh(SCROLLLOCK_LED_PIN);
      break;
  }
  return state;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Base          ,-----------------------------------------.     ,-----------------------------------------------------.
  *                | ESC | F1  | F2  | F3  | F4  | F5  | F6  |     | F7  | F8  | F9  | F10 | F11 | F12 |Print| Ins | Home|
  * ,-----------.  |-----+-----+-----+-----+-----+-----+-----|     |-----+-----+-----+-----+-----+-----+-----------+-----|
  * |  8  |  9  |  |  ~  |  1  |  2  |  3  |  4  |  5  |  6  |     |  7  |  8  |  9  |  0  |  -  |  =  | Backspac  | Del |
  * |-----+-----|  |-----------------------------------------'  ,--------------------------------------------------+-----|
  * |  6  |  7  |  | Tab   |  Q  |  W  |  E  |  R  |  T  |     |  Y  |  U  |  I  |  O  |  P  |  [  |  ]  |    \    | End |
  * |-----+-----|  |---------------------------------------.    `--------------------------------------------------+-----|
  * |  4  |  5  |  | Caps    |  A  |  S  |  D  |  F  |  G  |     |  H  |  J  |  K  |  L  |  ;  |  '  |    Enter    | PgUp|
  * |-----+-----|  |-----------------------------------------.   `-------------------------------------------------+-----|
  * |  2  |  3  |  | Shift     |  Z  |  X  |  C  |  V  |  B  |     |  N  |  M  |  ,  |  .  |   /   |  Shift  | Up  | PgDn|
  * |-----+-----|  |-----------------------------------------'   ,-------------------------------------------+-----+-----|
  * |  0  |  1  |  | Ctrl  |  GUI |  Alt |   Space   |Space|     | Space         |  Alt  |QW_ON| Ctrl  | Left| Down|Right|
  * `-----------'  `---------------------------------------'     `-------------------------------------------------------'
  */
  [BASE] = LAYOUT(
//--------------------------------Left Hand-----------------------------------| |--------------------------------Right Hand------------------------------------------------
                KC_ESC,   KC_F1,   KC_F2,   KC_F3,  KC_F4,  KC_F5,  KC_F6,                KC_F7,  KC_F8,   KC_F9,  KC_F10,  KC_F11,   KC_F12,   KC_PSCR,  KC_INS,  KC_HOME,
KC_8,  KC_9,    KC_GRAVE, KC_1,    KC_2,    KC_3,   KC_4,   KC_5,   KC_6,                 KC_7,   KC_8,    KC_9,   KC_0,    KC_MINUS, KC_EQUAL, KC_BSPC,           KC_DEL,
KC_6,  KC_7,    KC_TAB,   KC_Q,    KC_W,    KC_E,   KC_R,   KC_T,                 KC_Y,   KC_U,   KC_I,    KC_O,   KC_P,    KC_LBRC,  KC_RBRC,  KC_BSLS,           KC_END,
KC_4,  KC_5,    KC_CAPS,  KC_A,    KC_S,    KC_D,   KC_F,   KC_G,                 KC_H,   KC_J,   KC_K,    KC_L,   KC_SCLN, KC_QUOT,  KC_ENTER,                    KC_PGUP,
KC_2,  KC_3,    KC_LSFT,  KC_Z,    KC_X,    KC_C,   KC_V,   KC_B,                 KC_N,   KC_M,   KC_COMM, KC_DOT, KC_SLSH,                     KC_RSFT,  KC_UP,   KC_PGDN,
KC_0,  KC_1,    KC_LCTL,  KC_LGUI, KC_LALT, KC_SPC, KC_SPC,                       KC_SPC,         KC_RALT, MO(QWERTY_MOD),  KC_RCTL,            KC_LEFT,  KC_DOWN, KC_RIGHT
  ),

  [QWERTY_MOD] = LAYOUT(
//--------------------------------Left Hand-----------------------------------------------| |--------------------------------Right Hand------------------------------------------------
                      _______,  _______,  _______,  _______,  _______,  _______,  _______,              _______,   _______,  _______,  _______,  _______,  _______,  _______,  _______, _______,
_______,  _______,    _______,  _______,  _______,  _______,  _______,  _______,  _______,              _______,   _______,  _______,  _______,  _______,  _______,  _______,           _______,
_______,  _______,    _______,  KC_MPRV,  KC_VOLU,  KC_MNXT,  _______,  _______,              _______,  _______,   _______,  _______,  _______,  _______,  _______,  _______,           _______,
_______,  _______,    _______,  _______,  KC_VOLD,  _______,  _______,  _______,              _______,  _______,   _______,  _______,  _______,  _______,  _______,                     _______,
_______,  _______,    _______,  _______,  KC_MUTE,  KC_MPLY,  _______,  _______,              _______,  _______,   _______,  _______,  _______,                      _______, _______,  _______,
_______,  _______,    TO(QWERTY),_______, _______,  _______,  _______,                        _______,             _______, _______,   _______,                      _______, _______,  _______
  ),

  /* QWERTY        ,-----------------------------------------.     ,-----------------------------------------------------.
  *                | ESC | F1  | F2  | F3  | F4  | F5  | F6  |     | F7  | F8  | F9  | F10 | F11 | F12 |Print| Ins | Home|
  * ,-----------.  |-----+-----+-----+-----+-----+-----+-----|     |-----+-----+-----+-----+-----+-----+-----------+-----|
  * |  8  |  9  |  |  ~  |  1  |  2  |  3  |  4  |  5  |  6  |     |  7  |  8  |  9  |  0  |  -  |  =  | Backspac  | Del |
  * |-----+-----|  |-----------------------------------------'  ,--------------------------------------------------+-----|
  * |  6  |  7  |  | Tab   |  Q  |  W  |  E  |  R  |  T  |     |  Y  |  U  |  I  |  O  |  P  |  [  |  ]  |    \    | End |
  * |-----+-----|  |---------------------------------------.    `--------------------------------------------------+-----|
  * |  4  |  5  |  | Caps    |  A  |  S  |  D  |  F  |  G  |     |  H  |  J  |  K  |  L  |  ;  |  '  |    Enter    | PgUp|
  * |-----+-----|  |-----------------------------------------.   `-------------------------------------------------+-----|
  * |  2  |  3  |  | Shift     |  Z  |  X  |  C  |  V  |  B  |     |  N  |  M  |  ,  |  .  |   /   |  Shift  | Up  | PgDn|
  * |-----+-----|  |-----------------------------------------'   ,-------------------------------------------+-----+-----|
  * |  0  |  1  |  | Ctrl  |  GUI |  Alt |Spac/MEDIA | BSPC|     |      MOD      |  Alt  | MOD | Ctrl  | Left| Down|Right|
  * `-----------'  `---------------------------------------'     `-------------------------------------------------------'
  */
  [QWERTY] = LAYOUT(
//--------------------------------Left Hand------------------------------------| |--------------------------------Right Hand------------------------------------------------
                KC_ESC,   KC_F1,   KC_F2,   KC_F3,  KC_F4,  KC_F5,  KC_F6,                KC_F7,  KC_F8,   KC_F9,  KC_F10,  KC_F11,   KC_F12,   LT(CONFIG, KC_PSCR),  KC_INS,  KC_HOME,
KC_8,  KC_9,    KC_GRAVE, KC_1,    KC_2,    KC_3,   KC_4,   KC_5,   KC_6,                 KC_7,   KC_8,    KC_9,   KC_0,    KC_MINUS, KC_EQUAL, KC_BSPC,           KC_DEL,
KC_6,  KC_7,    KC_TAB,   KC_Q,    KC_W,    KC_E,   KC_R,   KC_T,                 KC_Y,   KC_U,   KC_I,    KC_O,   KC_P,    KC_LBRC,  KC_RBRC,  KC_BSLS,           KC_END,
KC_4,  KC_5,    LT(STRINGS,KC_CAPS),  KC_A,    KC_S ,KC_D ,KC_F ,KC_G,   KC_H,   KC_J, KC_K, KC_L, KC_SCLN,KC_QUOT,KC_ENTER,         KC_PGUP,
KC_2,  KC_3,    KC_LSFT,  KC_Z,    KC_X,    KC_C,   KC_V,   KC_B,                 KC_N,   KC_M,   KC_COMM, KC_DOT, LT(GIT,KC_SLSH),                     KC_RSFT,  KC_UP,   KC_PGDN,
KC_0,  KC_1,    KC_LCTL,  KC_LGUI, KC_LALT, LT(MEDIA, KC_SPC),LT(COMBOS,KC_BSPC),            LT(MOD, KC_ENTER),        KC_RALT, MO(LAYOUT_CHG),KC_RCTL,                     KC_LEFT,  KC_DOWN, KC_RIGHT
  ),

  [WORKMAN] = LAYOUT(
//--------------------------------Left Hand-----------------------------------------------| |--------------------------------Right Hand------------------------------------------------
                      _______,  _______,  _______,  _______,  _______,  _______,  _______,              _______,   _______,  _______,  _______,  _______,  _______,  _______,  _______, _______,
_______,  _______,    _______,  _______,  _______,  _______,  _______,  _______,  _______,              _______,   _______,  _______,  _______,  _______,  _______,  _______,           _______,
_______,  _______,    _______,  KC_Q,     KC_D,		KC_R,     KC_W,     KC_B,              KC_J,   KC_F,		KC_U,   KC_P,   KC_SCLN,_______,_______,  _______,           _______,
_______,  _______,    _______,  KC_A,     KC_S,		KC_H,     KC_T,     KC_G,              KC_Y,   KC_N,		KC_E,   KC_O,   KC_I,  _______,  _______,           _______,
_______,  _______,    _______,  KC_Z,     KC_X,		KC_C,     KC_V,     KC_M,              KC_K,   KC_L,		KC_COMM,KC_DOT, _______,                      _______, _______,  _______,
_______,  _______,    _______, _______,_______,_______, _______,                        _______,             _______, TO(QWERTY),   _______,            _______, _______,  _______
  ),
  
  [MOD] = LAYOUT(
//--------------------------------Left Hand-----------------------------------------------| |--------------------------------Right Hand------------------------------------------------
                      _______,  _______,  _______,  _______,  _______,  _______,  _______,              _______,   _______,  _______,  _______,  _______,  _______,  _______,  _______, _______,
_______,  _______,    _______,  _______,  _______,  _______,  _______,  _______,  _______,              _______,   _______,  _______,  _______,  _______,  _______,  _______,           _______,
_______,  _______,    _______,  _______,  OS_HOME,  KC_UP,    OS_END,   KC_PGUP,              _______,  _______,_______, _______,_______,_______,_______,  _______,           _______,
_______,  _______,    _______,  _______,  KC_LEFT,  KC_DOWN,  KC_RIGHT, KC_PGDOWN,              _______,CTR_ALT,KC_LSFT,_______,_______,  _______,  _______,           _______,
_______,  _______,    _______,_______,_______,  _______,  KC_DEL,  _______,              _______,  _______,   _______,  _______,  _______,                      _______, _______,  _______,
_______,  _______,    _______, _______,_______,KC_DEL, _______,                        _______,             _______, _______,   _______,            _______, _______,  _______
  ),
  
  [MEDIA] = LAYOUT(
//--------------------------------Left Hand-----------------------------------------------| |--------------------------------Right Hand------------------------------------------------
                      _______,  _______,  _______,  _______,  _______,  _______,  _______,              _______,   _______,  _______,  _______,  _______,  _______,  _______,  _______, _______,
_______,  _______,    _______,  _______,  _______,  _______,  _______,  _______,  _______,              _______,   _______,  _______,  _______,  _______,  _______,  _______,           _______,
_______,  _______,    _______,  KC_MPRV,  KC_VOLU,  KC_MNXT,  _______,  _______,              _______,  _______,   _______,  _______,  _______,  _______,  _______,  _______,           _______,
_______,  _______,    _______,  _______,  KC_VOLD,  _______,  _______,  _______,              _______,  _______,   _______,  _______,  _______,  _______,  _______,                     _______,
_______,  _______,    _______,  _______,  KC_MUTE,  KC_MPLY,  _______,  _______,              _______,  _______,   _______,  _______,  _______,                      _______, _______,  _______,
_______,  _______,    _______,  _______,  _______,  _______,  _______,                        _______,             _______, _______,   _______,                      _______, _______,  _______
  ),
  
  [COMBOS] = LAYOUT(
//--------------------------------Left Hand-----------------------------------------------| |--------------------------------Right Hand------------------------------------------------
                      _______,  _______,  _______,  _______,  _______,  _______,  _______,              _______,   _______,  _______,  _______,  _______,  _______,  _______,  _______, _______,
_______,  _______,    _______,  _______,  _______,  _______,  _______,  _______,  _______,              _______,   _______,  _______,  _______,  _______,  _______,  _______,           _______,
_______,  _______,    _______,  _______,  _______,  _______,  _______,  _______,              _______,  _______,   _______,  _______,  _______,  _______,  _______,  _______,           _______,
_______,  _______,    _______,  _______,  SARCASM,  _______,  CTRL_CTV,  _______,              _______,  _______,   _______,  _______,  _______,  _______,  _______,                     _______,
_______,  _______,    _______,  _______,  _______,  _______,  _______,  _______,              _______,  _______,   _______,  _______,  _______,                      _______, _______,  _______,
_______,  _______,    _______,  _______,  _______,  _______,  _______,                        _______,             _______, _______,   _______,                      _______, _______,  _______
  ),
  
  [STRINGS] = LAYOUT(
//--------------------------------Left Hand-----------------------------------------------| |--------------------------------Right Hand------------------------------------------------
                      _______,  _______,  _______,  _______,  _______,  _______,  _______,              _______,   _______,  _______,  _______,  _______,  _______,  _______,  _______, _______,
_______,  _______,    _______,  PRESCRIPTION,  PHONE,  _______,  FOURS,  _______,  _______,              _______,   _______,  _______,  _______,  _______,  _______,  _______,           _______,
_______,  _______,    _______,  _______,  _______,  _______,  _______,  _______,              _______,  _______,   _______,  _______,  _______,  _______,  _______,  _______,           _______,
_______,  _______,    _______,  ADMINS,  _______,  _______,  _______,  _______,              _______,  _______,   _______,  _______,  _______,  _______,  _______,                     _______,
_______,  _______,    _______,  _______,  _______,  _______,  _______,  _______,              _______,  _______,   _______,  _______,  _______,                      _______, _______,  _______,
_______,  _______,    _______,  _______,  _______,  _______,  _______,                        _______,             _______, _______,   _______,                      _______, _______,  _______
  ),  
  
  [LAYOUT_CHG] = LAYOUT(
//--------------------------------Left Hand-----------------------------------------------| |--------------------------------Right Hand------------------------------------------------
                      _______,  _______,  _______,  _______,  _______,  _______,  _______,              _______,   _______,  _______,  _______,  _______,  _______,  _______,  _______, _______,
_______,  _______,    _______,  _______,  _______,  _______,  _______,  _______,  _______,              _______,   _______,  _______,  _______,  _______,  _______,  _______,           _______,
_______,  _______,    _______,  _______,  _______,  _______,  _______,  _______,              _______,  _______,   _______,  _______,  _______,  _______,  _______,  _______,           _______,
_______,  _______,    _______,  _______,  _______,  _______,  _______,  _______,              _______,  _______,   _______,  _______,  _______,  _______,  _______,                     _______,
_______,  _______,    TO(WORKMAN),  _______,  _______,  _______,  _______,  _______,              _______,  _______,   _______,  _______,  _______,                      _______, _______,  _______,
_______,  _______,    TO(BASE),  _______,  _______,  _______,  _______,                        _______,             _______, _______,   _______,                      _______, _______,  _______
  ),  
  
  [CONFIG] = LAYOUT(
//--------------------------------Left Hand-----------------------------------------------| |--------------------------------Right Hand------------------------------------------------
                      _______,  _______,  _______,  _______,  _______,  _______,  _______,              _______,   _______,  _______,  _______,  _______,  _______,  _______,  _______, _______,
RGB_VAI,  RGB_VAD,    RGB_MODE_PLAIN,  RGB_MODE_BREATHE,  RGB_MODE_RAINBOW,  RGB_MODE_SWIRL,  RGB_MODE_SNAKE,  RGB_MODE_KNIGHT,  RGB_MODE_XMAS,              RGB_MODE_GRADIENT,   RGB_MODE_RGBTEST,  XXXXXXX,  XXXXXXX,  _______,  _______,  _______,           _______,
RGB_SAI,  RGB_SAD,    _______,  _______,  _______,  _______,  _______,  _______,              _______,  _______,   _______,  TOG_OS,  _______,  _______,  _______,  _______,           _______,
RGB_HUI,  RGB_HUD,    _______,  _______,  _______,  _______,  _______,  _______,              _______,  _______,   _______,  _______,  _______,  _______,  _______,                     _______,
RGB_MOD,  RGB_RMOD,    _______,  _______,  _______,  _______,  _______,  _______,              _______,  _______,   _______,  _______,  _______,                      _______, _______,  _______,
RGB_TOG,  _______,    _______,  _______,  _______,  _______,  _______,                        _______,             _______, _______,   _______,                      _______, _______,  _______
  ),
  
  [GIT] = LAYOUT(
//--------------------------------Left Hand-----------------------------------------------| |--------------------------------Right Hand------------------------------------------------
                      _______,  _______,  _______,  _______,  _______,  _______,  _______,              _______,   _______,  _______,  _______,  _______,  _______,  _______,  _______, _______,
_______,  _______,    _______,  _______,  _______,  _______,  _______,  _______,  _______,              _______,   _______,  _______,  _______,  _______,  _______,  _______,           _______,
_______,  _______,    _______,  _______,  G_DIFF,  G_RST,  _______,  G_BRCH,              _______,  G_FTCH,   _______,  G_P,  _______,  _______,  _______,  _______,           _______,
_______,  _______,    _______,  G_ADD,  G_S,  _______,  _______,  _______,              _______,  _______,   _______,  _______,  _______,  _______,  _______,                     _______,
_______,  _______,    _______,  _______,  _______,  G_C,  _______,  G_MERG,              _______,  G_LOG,   _______,  _______,  _______,                      _______, _______,  _______,
_______,  _______,    _______,  _______,  _______,  _______,  _______,                        _______,             _______, _______,   _______,                      _______, _______,  _______
  ),
  
  [GIT_C] = LAYOUT(
//--------------------------------Left Hand-----------------------------------------------| |--------------------------------Right Hand------------------------------------------------
                      XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,              XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX,
XXXXXXX,  XXXXXXX,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,              XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  G_BS_C,           XXXXXXX,
XXXXXXX,  XXXXXXX,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,              XXXXXXX,  XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,           XXXXXXX,
XXXXXXX,  XXXXXXX,    XXXXXXX,  XXXXXXX,  XXXXXXX,  G_CHEC,  XXXXXXX,  XXXXXXX,              XXXXXXX,  XXXXXXX,   XXXXXXX,  G_COMM,  XXXXXXX,  XXXXXXX,  XXXXXXX,                     XXXXXXX,
XXXXXXX,  XXXXXXX,    _______,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,              XXXXXXX,  XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,                      _______, XXXXXXX,  XXXXXXX,
XXXXXXX,  XXXXXXX,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,                        XXXXXXX,             XXXXXXX, XXXXXXX,   XXXXXXX,                      XXXXXXX, XXXXXXX,  XXXXXXX
  ),   
  
  // [GIT_P] = LAYOUT(
// //--------------------------------Left Hand-----------------------------------------------| |--------------------------------Right Hand------------------------------------------------
                      // XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,              XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX,
// XXXXXXX,  XXXXXXX,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,              XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  G_BS_P,           XXXXXXX,
// XXXXXXX,  XXXXXXX,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,              XXXXXXX,  XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,           XXXXXXX,
// XXXXXXX,  XXXXXXX,    XXXXXXX,  XXXXXXX,  G_PUSH,  XXXXXXX,  XXXXXXX,  XXXXXXX,              XXXXXXX,  XXXXXXX,   XXXXXXX,  G_PULL,  XXXXXXX,  XXXXXXX,  XXXXXXX,                     XXXXXXX,
// XXXXXXX,  XXXXXXX,    _______,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,              XXXXXXX,  XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,                      _______, XXXXXXX,  XXXXXXX,
// XXXXXXX,  XXXXXXX,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,                        XXXXXXX,             XXXXXXX, XXXXXXX,   XXXXXXX,                      XXXXXXX, XXXXXXX,  XXXXXXX
  // ), 
  
  [GIT_S] = LAYOUT(
//--------------------------------Left Hand-----------------------------------------------| |--------------------------------Right Hand------------------------------------------------
                      XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,              XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX,
XXXXXXX,  XXXXXXX,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,              XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  G_BS_S,           XXXXXXX,
XXXXXXX,  XXXXXXX,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,              XXXXXXX,  XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,           XXXXXXX,
XXXXXXX,  XXXXXXX,    XXXXXXX,  XXXXXXX,  G_STSH,  G_SHOW,  G_STAT,  XXXXXXX,              XXXXXXX,  XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,                     XXXXXXX,
XXXXXXX,  XXXXXXX,    _______,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,              XXXXXXX,  XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,                      _______, XXXXXXX,  XXXXXXX,
XXXXXXX,  XXXXXXX,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,                        XXXXXXX,             XXXXXXX, XXXXXXX,   XXXXXXX,                      XXXXXXX, XXXXXXX,  XXXXXXX
  ),   
  
 /*                ,-----------------------------------------.     ,-----------------------------------------------------.
  *                |     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |
  * ,-----------.  |-----+-----+-----+-----+-----+-----+-----|     |-----+-----+-----+-----+-----+-----+-----------+-----|
  * |     |     |  |     |     |     |     |     |     |     |     |     |     |     |     |     |     |           |     |
  * |-----+-----|  |-----------------------------------------'  ,--------------------------------------------------+-----|
  * |     |     |  |       |     |     |     |     |     |     |     |     |     |     |     |     |     |         |     |
  * |-----+-----|  |---------------------------------------.    `--------------------------------------------------+-----|
  * |     |     |  |         |     |     |     |     |     |     |     |     |     |     |     |     |             |     |
  * |-----+-----|  |-----------------------------------------.   `-------------------------------------------------+-----|
  * |     |     |  |           |    |     |      |     |     |     |     |     |     |     |       |         |     |     |
  * |-----+-----|  |-----------------------------------------'   ,-------------------------------------------+-----+-----|
  * |     |     |  |       |      |      |           |     |     |               |       |     |       |     |     |     |
  * `-----------'  `---------------------------------------'     `-------------------------------------------------------'
  */
  // [] = LAYOUT(
// //--------------------------------Left Hand-----------------------------------------------| |--------------------------------Right Hand------------------------------------------------
                      // _______,  _______,  _______,  _______,  _______,  _______,  _______,              _______,   _______,  _______,  _______,  _______,  _______,  _______,  _______, _______,
// _______,  _______,    _______,  _______,  _______,  _______,  _______,  _______,  _______,              _______,   _______,  _______,  _______,  _______,  _______,  _______,           _______,
// _______,  _______,    _______,  _______,  _______,  _______,  _______,  _______,              _______,  _______,   _______,  _______,  _______,  _______,  _______,  _______,           _______,
// _______,  _______,    _______,  _______,  _______,  _______,  _______,  _______,              _______,  _______,   _______,  _______,  _______,  _______,  _______,                     _______,
// _______,  _______,    _______,  _______,  _______,  _______,  _______,  _______,              _______,  _______,   _______,  _______,  _______,                      _______, _______,  _______,
// _______,  _______,    _______,  _______,  _______,  _______,  _______,                        _______,             _______, _______,   _______,                      _______, _______,  _______
  // ),
};

static bool is_win = false;
static const char *key_up[2] = {SS_UP(X_LALT), SS_UP(X_LCTL)};
static const char *key_down[2] = {SS_DOWN(X_LALT), SS_DOWN(X_LCTL)};
static bool sarcasmOn = false;
static bool sarcasmKey = false;

void send_n_backspace(int times) {
  for (int i=0; i<times; i++) {
    SEND_STRING(SS_TAP(X_BSPC));  
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (sarcasmOn) {
    sarcasmKey = ! sarcasmKey;  
    if (sarcasmKey) {
      SEND_STRING(SS_TAP(X_CAPS));
    }
  }	

  switch (keycode) {
    case CTRL_CTV:
      if (record->event.pressed) {
        if ( get_mods() & MOD_MASK_SHIFT ) {
          clear_mods();
          SEND_STRING(SS_LCTL("ctv"));
        } else {
          SEND_STRING(SS_LCTL("ctv") SS_TAP(X_ENTER));
        }
      }
      break;
    case SARCASM:
      if (record->event.pressed) {
          sarcasmOn = !sarcasmOn;
      }
      break;
        
	case TOG_OS:
		if (record->event.pressed) {
			is_win = ! is_win;
		}
    break;
    case CTR_ALT:
      if (record->event.pressed) {
        send_string(key_down[is_win]);
      } else {
        send_string(key_up[is_win]);
      }
      break;
    case OS_HOME:
      if (is_win) {
        if (record->event.pressed) {
          SEND_STRING(SS_DOWN(X_HOME));
        } else {
          SEND_STRING(SS_UP(X_HOME));
        }
      } else {
        if (record->event.pressed) {
          SEND_STRING(SS_DOWN(X_LCTL) SS_TAP(X_LEFT) SS_UP(X_LCTRL));
        }
      }
      break;
    case OS_END:
      if (is_win) {
        if (record->event.pressed) {
          SEND_STRING(SS_DOWN(X_END));
        } else {
          SEND_STRING(SS_UP(X_END));
        }
      } else {
        if (record->event.pressed) {
          SEND_STRING(SS_DOWN(X_LCTL) SS_TAP(X_RIGHT) SS_UP(X_LCTRL));
        }
      }
      break;

    // case :
    //   if (record->event.pressed) {
    //     SEND_STRING("");
    //   }
    //   break;
    // case :
    //   if (record->event.pressed) {
    //     if ( get_mods() & MOD_MASK_SHIFT ) {
    //       clear_mods();
    //       SEND_STRING("");
    //     } else {
    //       SEND_STRING("");
    //     }
    //   }
    //   break;
    case ADMINS:
      if (record->event.pressed) {
        if ( get_mods() & MOD_MASK_SHIFT ) {
          clear_mods();
          SEND_STRING("/admin");
        } else {
          SEND_STRING("/admin/aurora/status");
        }
      }
      break;
    case PRESCRIPTION:
      if (record->event.pressed) {
        SEND_STRING("12122019");
      }
      break;
    case PHONE:
      if (record->event.pressed) {
        SEND_STRING("0123456789");
      }
      break;
    case FOURS:
      if (record->event.pressed) {
        SEND_STRING("4444333322221111");
      }
      break;
		  
	case G_ADD:
		if (record->event.pressed) {
			SEND_STRING("git add ");
		}
		break;
	case G_BRCH:
		if (record->event.pressed) {
			if ( get_mods() & MOD_MASK_SHIFT ) {
				clear_mods();
				SEND_STRING("master");
			} else {
				SEND_STRING("develop");
			}
		}
		break;
	case G_C:
		if (record->event.pressed) {
      SEND_STRING("git c[Heckout/Ommit]");
			layer_on(GIT_C);
		}
		break;
	case G_BS_C:
		if (!record->event.pressed) {
      send_n_backspace(20);
			layer_off(GIT_C);
		}
		break;
	case G_CHEC:
		if (!record->event.pressed) {
      bool shifted = get_mods() & MOD_MASK_SHIFT;
      clear_mods();
            
      send_n_backspace(15);
			SEND_STRING("heckout ");
      if (shifted) {
				SEND_STRING("-b ");
			}
      layer_off(GIT_C);
		}
		break;
	case G_COMM:
		if (!record->event.pressed) {
        bool shifted = get_mods() & MOD_MASK_SHIFT;
        clear_mods();
        
        send_n_backspace(15);
        SEND_STRING("ommit -");
			if (shifted) {
				SEND_STRING("a");
			}
      SEND_STRING("m \"\"" SS_TAP(X_LEFT));
			layer_off(GIT_C);
		}
		break;
	case G_DIFF:
		if (record->event.pressed) {
			SEND_STRING("git diff ");
		}
		break;	
	case G_FTCH:
		if (record->event.pressed) {
			SEND_STRING("git fetch ");
		}
		break;
	case G_LOG:
		if (record->event.pressed) {
			SEND_STRING("git log ");
		}
		break;
	case G_MERG:
		if (record->event.pressed) {
			SEND_STRING("git merge ");
		}
		break;
	case G_P:
		if (record->event.pressed) {
      if ( get_mods() & MOD_MASK_SHIFT ) {
				clear_mods();
				SEND_STRING("git push -u");
			} else {
				SEND_STRING("git pu");
			}
		}
		break;
	case G_RST:
		if (record->event.pressed) {
			SEND_STRING("git reset ");
		}
		break;
	case G_S:
		if (!record->event.pressed) {
			SEND_STRING("git s[How/taSh/taTus]");
			layer_on(GIT_S);			
		}
		break;
	case G_BS_S:
		if (!record->event.pressed) {
      send_n_backspace(21);
			layer_off(GIT_S);
		}
		break;
	case G_SHOW:
		if (!record->event.pressed) {
      send_n_backspace(16);
			SEND_STRING("how ");
			layer_off(GIT_S);
		}
		break;			
	case G_STSH:
		if (!record->event.pressed) {
      send_n_backspace(16);
			SEND_STRING("tash ");
			layer_off(GIT_S);
		}
		break;		
	case G_STAT:
		if (!record->event.pressed) {
      send_n_backspace(16);
			SEND_STRING("tatus ");
			layer_off(GIT_S);
		}
		break;
  }
  return true;
};