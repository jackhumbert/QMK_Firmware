#include <art.h>
#include <sendstring_workman_zxcvm.h>

bool is_win = false;

enum custom_keycodes {
  keyboardSpecificKeyCode = NEW_SAFE_RANGE //not used
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
    case MEDIA:
    case LAYOUT_CHG:
      writePinHigh(SCROLLLOCK_LED_PIN);
    case BASE:
      writePinHigh(NUMLOCK_LED_PIN);
      break;
  }
  return state;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

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
  * |  0  |  1  |  | Ctrl  |  GUI |  Alt |Spac/MEDIA | BSPC|     |      NAV      |  Alt  | NAV | Ctrl  | Left| Down|Right|
  * `-----------'  `---------------------------------------'     `-------------------------------------------------------'
  */
  [QWERTY] = LAYOUT(
//--------------------------------Left Hand------------------------------------| |--------------------------------Right Hand------------------------------------------------
                 KC_ESC,   KC_F1,   KC_F2,   KC_F3,  KC_F4,  KC_F5,  KC_F6,                KC_F7,  KC_F8,   KC_F9,  KC_F10,  KC_F11,   KC_F12,   LT(CONFIG, KC_PSCR),  KC_INS,  KC_HOME,
KC_VOLD,KC_VOLU, KC_GRAVE, KC_1,    KC_2,    KC_3,   KC_4,   KC_5,   KC_6,                 KC_7,   KC_8,    KC_9,   KC_0,    KC_MINUS, KC_EQUAL, KC_BSPC,          KC_DEL,
KC_MPRV,KC_MNXT, KC_TAB,   KC_Q,    KC_W,    KC_E,   KC_R,   KC_T,                 KC_Y,   KC_U,   KC_I,    KC_O,   KC_P,    KC_LBRC,  KC_RBRC,  KC_BSLS,           KC_END,
KC_HOME,KC_END,  KC_CAPS,  KC_A,    KC_S,    KC_D,   KC_F,   KC_G,   KC_H,   KC_J, KC_K, KC_L, KC_SCLN,KC_QUOT,KC_ENTER,         KC_PGUP,
DYN_MACRO_PLAY1,MO(STRINGS),KC_LSFT,KC_Z,KC_X,KC_C,  KC_V,   KC_B,                 KC_N,   KC_M,   KC_COMM, KC_DOT, LT(GIT,KC_SLSH),                     KC_RSFT,  KC_UP,   KC_PGDN,
DYN_REC_STOP,DYN_REC_START1,KC_LCTL, KC_LGUI, KC_LALT, LT(MEDIA, KC_SPC),LT(COMBOS,KC_BSPC),            LT(NAV, KC_ENTER),        KC_RALT, MO(LAYOUT_CHG),KC_RCTL,                     KC_LEFT,  KC_DOWN, KC_RIGHT
  ),

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
                KC_ESC,   KC_F1,   KC_F2,   KC_F3,  KC_F4,  KC_F5,  KC_F6,                KC_F7,  KC_F8,   KC_F9,  KC_F10,  KC_F11,   KC_F12,   LT(CONFIG, KC_PSCR),  KC_INS,  KC_HOME,
KC_8,  KC_9,    KC_GRAVE, KC_1,    KC_2,    KC_3,   KC_4,   KC_5,   KC_6,                 KC_7,   KC_8,    KC_9,   KC_0,    KC_MINUS, KC_EQUAL, KC_BSPC,           KC_DEL,
KC_6,  KC_7,    KC_TAB,   KC_Q,    KC_W,    KC_E,   KC_R,   KC_T,                 KC_Y,   KC_U,   KC_I,    KC_O,   KC_P,    KC_LBRC,  KC_RBRC,  KC_BSLS,           KC_END,
KC_4,  KC_5,    KC_CAPS,  KC_A,    KC_S,    KC_D,   KC_F,   KC_G,                 KC_H,   KC_J,   KC_K,    KC_L,   KC_SCLN, KC_QUOT,  KC_ENTER,                    KC_PGUP,
KC_2,  KC_3,    KC_LSFT,  KC_Z,    KC_X,    KC_C,   KC_V,   KC_B,                 KC_N,   KC_M,   KC_COMM, KC_DOT, KC_SLSH,                     KC_RSFT,  KC_UP,   KC_PGDN,
KC_0,  KC_1,    OS_CTRL,  OS_WIN,  KC_LALT, KC_SPC, KC_SPC,                       KC_SPC,         KC_RALT, MO(QWERTY_MOD),  KC_RCTL,            KC_LEFT,  KC_DOWN, KC_RIGHT
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
  
  [NAV] = LAYOUT(
//--------------------------------Left Hand-----------------------------------------------| |--------------------------------Right Hand------------------------------------------------
                      _______,  _______,  _______,  _______,  _______,  _______,  _______,              _______,   _______,  _______,  _______,  _______,  _______,  _______,  _______, _______,
_______,  _______,    _______,  _______,  _______,  _______,  _______,  _______,  _______,              _______,   _______,  _______,  _______,  _______,  _______,  _______,           _______,
_______,  _______,    _______,  _______,  KC_HOME,  KC_UP,    KC_END,   KC_PGUP,              _______,  _______,_______, _______,_______,_______,_______,  _______,           _______,
_______,  _______,    _______,  _______,  KC_LEFT,  KC_DOWN,  KC_RIGHT, KC_PGDOWN,              _______,CTR_ALT,KC_LSFT,_______,_______,  _______,  _______,           _______,
_______,  _______,    _______,_______,_______,  _______,  _______,  _______,              _______,  _______,   _______,  _______,  _______,                      _______, _______,  _______,
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
_______,  _______,    _______,  _______,  _______,  _______,  _______,  _______,              _______,  CTRL_LCTV,   _______,  _______,  _______,                      _______, _______,  _______,
_______,  _______,    _______,  _______,  _______,  _______,  _______,                        _______,             _______, _______,   _______,                      _______, _______,  _______
  ),
  
  [STRINGS] = LAYOUT(
//--------------------------------Left Hand-----------------------------------------------| |--------------------------------Right Hand------------------------------------------------
                      _______,  _______,  _______,  _______,  _______,  _______,  _______,              _______,   _______,  _______,  _______,  _______,  _______,  _______,  _______, _______,
_______,  _______,    TILD_BLOCK,  PRESCRIPTION,  _______,  _______,  FOURS,  _______,  _______,              _______,   _______,  _______,  _______,  _______,  _______,  _______,           _______,
_______,  _______,    _______,  _______,  _______,  _______,  _______,  _______,              _______,  _______,   _______,  _______,  _______,  _______,  _______,  _______,           _______,
_______,  _______,    _______,  ADMINS,  _______,  _______,  _______,  _______,              _______,  _______,   _______,  _______,  _______,  _______,  _______,                     _______,
_______,  _______,    _______,  _______,  _______,  _______,  _______,  _______,              _______,  _______,   _______,  _______,  _______,                      _______, _______,  _______,
_______,  _______,    _______,  _______,  _______,  _______,  _______,                        _______,             _______, _______,   _______,                      _______, _______,  _______
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
  
  [LAYOUT_CHG] = LAYOUT(
//--------------------------------Left Hand-----------------------------------------------| |--------------------------------Right Hand------------------------------------------------
                      _______,  _______,  _______,  _______,  _______,  _______,  _______,              _______,   _______,  _______,  _______,  _______,  _______,  _______,  _______, _______,
KC_8,  KC_9,    _______,  _______,  _______,  _______,  _______,  _______,  _______,              _______,   _______,  _______,  _______,  _______,  _______,  _______,           _______,
KC_6,  KC_7,    _______,  _______,  CTL_ALT(KC_HOME),  CTL_ALT(KC_UP),    CTL_ALT(KC_END),   CTL_ALT(KC_PGUP),              _______,  _______,_______, _______,_______,_______,_______,  _______,           _______,
KC_4,  KC_5,    _______,  _______,  CTL_ALT(KC_LEFT),  CTL_ALT(KC_DOWN),  CTL_ALT(KC_RIGHT), CTL_ALT(KC_PGDOWN),              _______,_______,_______,_______,_______,  _______,  _______,           _______,
KC_2,  KC_3,    TO(WORKMAN),  _______,  _______,  _______,  _______,  _______,              _______,  _______,   _______,  _______,  _______,                      _______, _______,  _______,
KC_0,  KC_1,    TO(BASE),  _______,  _______,  _______,  CTL_ALT(KC_BSPC),                        KC_LSFT,             _______, _______,   _______,                      _______, _______,  _______
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
_______,  _______,    _______,  _______,  G_DIFF,   G_RST,    _______,  G_BRCH,               _______,   G_FTCH,   _______,  G_P,      _______,  _______,  _______,  _______,           _______,
_______,  _______,    _______,  G_ADD,    G_S,      _______,  _______,  _______,              _______,  _______,   _______,  _______,  _______,  _______,  _______,                     _______,
_______,  _______,    _______,  _______,  _______,  G_C,      _______,  G_MERG,               _______,   G_LOG,    _______,  _______,  _______,                      _______, _______,  _______,
_______,  _______,    _______,  _______,  _______,  _______,  _______,                        _______,             _______, _______,   _______,                      _______, _______,  _______
  ),
  
  [GIT_C] = LAYOUT(
//--------------------------------Left Hand-----------------------------------------------| |--------------------------------Right Hand------------------------------------------------
                      XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,              XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX,
XXXXXXX,  XXXXXXX,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,              XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  _______,           XXXXXXX,
XXXXXXX,  XXXXXXX,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,              XXXXXXX,  XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,           XXXXXXX,
XXXXXXX,  XXXXXXX,    XXXXXXX,  XXXXXXX,  XXXXXXX,  G_CHEC,   XXXXXXX,  XXXXXXX,              XXXXXXX,  XXXXXXX,   XXXXXXX,  G_COMM,   XXXXXXX,  XXXXXXX,  XXXXXXX,                     XXXXXXX,
XXXXXXX,  XXXXXXX,    _______,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,              XXXXXXX,  XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,                      _______, XXXXXXX,  XXXXXXX,
XXXXXXX,  XXXXXXX,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_BSPC,                        XXXXXXX,             XXXXXXX,  XXXXXXX,  XXXXXXX,                      XXXXXXX, XXXXXXX,  XXXXXXX
  ),
  
  [GIT_S] = LAYOUT(
//--------------------------------Left Hand-----------------------------------------------| |--------------------------------Right Hand------------------------------------------------
                      XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,              XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX,
XXXXXXX,  XXXXXXX,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,              XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  _______,           XXXXXXX,
XXXXXXX,  XXXXXXX,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,              XXXXXXX,  XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,           XXXXXXX,
XXXXXXX,  XXXXXXX,    XXXXXXX,  XXXXXXX,  G_STSH,   G_SHOW,   G_STAT,   XXXXXXX,              XXXXXXX,  XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,                     XXXXXXX,
XXXXXXX,  XXXXXXX,    _______,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,              XXXXXXX,  XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,                      _______, XXXXXXX,  XXXXXXX,
XXXXXXX,  XXXXXXX,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_BSPC,                        XXXXXXX,             XXXXXXX, XXXXXXX,   XXXXXXX,                      XXXXXXX, XXXXXXX,  XXXXXXX
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

bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {

  }
  return true;
}