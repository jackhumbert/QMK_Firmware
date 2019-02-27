// this is the style you want to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,

#include QMK_KEYBOARD_H
#include "keymap_jis2us.h"
#include "action_pseudo_lut.h"
#include "keymap_jp.h"
#ifdef OLED_ENABLE
  #include "ssd1306.h"
#endif

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum comet46_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _PSEUDO_US,
  _PSEUDO_US_LOWER,
  _PSEUDO_US_RAISE,
  _ADJUST
};

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  PSEUDO_US,
  JIS2US,
};

// JIS keycodes
#define KC_JZHT JP_ZHTG  // hankaku/zenkaku|kanzi
#define KC_JCIR JP_CIRC  // ^, ~
#define KC_JAT  JP_AT    // @, `
#define KC_JLBR JP_LBRC  // [, {
#define KC_JCOL JP_COLN  // :, *
#define KC_JRBR JP_RBRC  // ], }
#define KC_JBSL JP_BSLS  // \, _
#define KC_JMHE JP_MHEN  // muhenkan
#define KC_JHEN JP_HENK  // henkan
#define KC_JKAN JP_KANA  // katakana/hiragana|ro-mazi
#define KC_JMKA JP_MKANA //kana on MacOSX
#define KC_JMEI JP_MEISU //eisu on MacOSX
#define KC_JAMP JP_AMPR  // &
#define KC_JQUO JP_QUOT  // '
#define KC_JLPR JP_LPRN  // (
#define KC_JRPR JP_RPRN  // )
#define KC_JEQL JP_EQL   // =
#define KC_JTIL JP_TILD  // ~
#define KC_JPIP JP_PIPE  // |
#define KC_JGRV JP_GRV   // `
#define KC_JLCB JP_LCBR  // {
#define KC_JPLU JP_PLUS  // +
#define KC_JAST JP_ASTR  // *
#define KC_JRCB JP_RCBR  // }
#define KC_JUND JP_UNDS  // _

// Layer related keycodes
#define KC_LWR  MO(_LOWER)
#define KC_RSE  MO(_RAISE)
#define KC_P_LW MO(_PSEUDO_US_LOWER)
#define KC_P_RS MO(_PSEUDO_US_RAISE)
#define KC_QWRT QWERTY
#define KC_P_US PSEUDO_US
#define KC_J2US JIS2US

// Special keycodes
#define KC_SPCT CTL_T(KC_SPC)
#define KC_ENSF SFT_T(KC_ENT)
#define KC_CAEC MT(MOD_LCTL | MOD_LALT, KC_ESC)
#define KC_CSTB C_S_T(KC_TAB)
#define KC_IMON ALT_T(KC_F13)
#define KC_IMOF GUI_T(KC_F14)
#define KC_CAD LCA(KC_DEL)
#define KC_RST RESET

// Fillers to make layering more clear
#define KC_ KC_TRNS
#define KC_XXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT_kc(
  //,----+----+----+----+----+----+               +----+----+----+----+----+----.
     CAEC, Q  , W  , E  , R  , T  ,                 Y  , U  , I  , O  , P  ,DEL ,
  //|----+----+----+----+----+----+----+     +----+----+----+----+----+----+----|
     CSTB, A  , S  , D  , F  , G  ,LPRN,      RPRN, H  , J  , K  , L  ,SCLN,BSPC,
  //|----+----+----+----+----+----+----|     |----+----+----+----+----+----+----|
     LSFT, Z  , X  , C  , V  , B  ,LBRC,      RBRC, N  , M  ,COMM,DOT ,SLSH,QUOT,
  //|----+----+----+----+----+----+----|     |----+----+----+----+----+----+----|
                         IMOF,LWR ,SPCT,      ENSF,RSE ,IMON
  //                    +----+----+---/       \---+----+----+
  ),

  [_LOWER] = LAYOUT_kc(
  //,----+----+----+----+----+----+               +----+----+----+----+----+----.
         ,EXLM, AT ,HASH,DLR ,PERC,                CIRC,AMPR,ASTR,LPRN,RPRN,    ,
  //|----+----+----+----+----+----+----+     +----+----+----+----+----+----+----|
         , F1 , F2 , F3 , F4 , F5 , F6 ,      GRV ,BSLS,MINS,EQL ,LBRC,RBRC,    ,
  //|----+----+----+----+----+----+----|     |----+----+----+----+----+----+----|
         , F7 , F8 , F9 , F10, F11, F12,      TILD,PIPE,UNDS,PLUS,LCBR,RCBR,    ,
  //|----+----+----+----+----+----+----|     |----+----+----+----+----+----+----|
                             ,    ,    ,          ,    ,
  //                    +----+----+---/       \---+----+----+
  ),

  [_RAISE] = LAYOUT_kc(
  //,----+----+----+----+----+----+               +----+----+----+----+----+----.
         , 1  , 2  , 3  , 4  , 5  ,                 6  , 7  , 8  , 9  , 0  ,    ,
  //|----+----+----+----+----+----+----+     +----+----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,    ,      XXXX,LEFT,DOWN, UP ,RGHT,END ,    ,
  //|----+----+----+----+----+----+----|     |----+----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,    ,      HOME,XXXX,PGDN,PGUP,XXXX,XXXX,    ,
  //|----+----+----+----+----+----+----|     |----+----+----+----+----+----+----|
                             ,    ,    ,          ,    ,
  //                    +----+----+---/       \---+----+----+
  ),

  [_PSEUDO_US] = LAYOUT_kc(
  //,----+----+----+----+----+----+               +----+----+----+----+----+----.
     CAEC, Q  , W  , E  , R  , T  ,                 Y  , U  , I  , O  , P  ,DEL ,
  //|----+----+----+----+----+----+----+     +----+----+----+----+----+----+----|
     CSTB, A  , S  , D  , F  , G  ,JLPR,      JRPR, H  , J  , K  , L  ,J2US,BSPC,
  //|----+----+----+----+----+----+----|     |----+----+----+----+----+----+----|
     LSFT, Z  , X  , C  , V  , B  ,J2US,      J2US, N  , M  ,COMM,DOT ,SLSH,J2US,
  //|----+----+----+----+----+----+----|     |----+----+----+----+----+----+----|
                         IMOF,P_LW,SPCT,      ENSF,P_RS,IMON
  //                    +----+----+---/       \---+----+----+
  ),


  [_PSEUDO_US_LOWER] = LAYOUT_kc(
  //,----+----+----+----+----+----+               +----+----+----+----+----+----.
         ,EXLM,JAT ,HASH,DLR ,PERC,                JCIR,JAMP,JAST,JLPR,JRPR,    ,
  //|----+----+----+----+----+----+----+     +----+----+----+----+----+----+----|
         , F1 , F2 , F3 , F4 , F5 , F6 ,      JGRV,JBSL,MINS,JEQL,JLBR,JRBR,    ,
  //|----+----+----+----+----+----+----|     |----+----+----+----+----+----+----|
         , F7 , F8 , F9 , F10, F11, F12,      JTIL,JPIP,JUND,JPLU,JLCB,JRCB,    ,
  //|----+----+----+----+----+----+----|     |----+----+----+----+----+----+----|
                             ,    ,    ,          ,    ,
  //                    +----+----+---/       \---+----+----+
  ),

  [_PSEUDO_US_RAISE] = LAYOUT_kc(
  //,----+----+----+----+----+----+               +----+----+----+----+----+----.
         , 1  , 2  , 3  , 4  , 5  ,                 6  , 7  , 8  , 9  , 0  ,    ,
  //|----+----+----+----+----+----+----+     +----+----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,JZHT,      XXXX,LEFT,DOWN, UP ,RGHT,END ,    ,
  //|----+----+----+----+----+----+----|     |----+----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,    ,      HOME,XXXX,PGDN,PGUP,XXXX,XXXX,    ,
  //|----+----+----+----+----+----+----|     |----+----+----+----+----+----+----|
                             ,    ,    ,          ,    ,
  //                    +----+----+---/       \---+----+----+
  ),

  [_ADJUST] = LAYOUT_kc(
  //,----+----+----+----+----+----+               +----+----+----+----+----+----.
         ,    ,    ,    ,    ,    ,                    ,    ,    ,    ,    ,    ,
  //|----+----+----+----+----+----+----+     +----+----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,CAD ,      QWRT,    ,    ,    ,    ,    ,    ,
  //|----+----+----+----+----+----+----|     |----+----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,RST ,      P_US,    ,    ,    ,    ,    ,    ,
  //|----+----+----+----+----+----+----|     |----+----+----+----+----+----+----|
                             ,    ,    ,          ,    ,
  //                    +----+----+---/       \---+----+----+
  )

};

uint32_t layer_state_set_user(uint32_t state) {
  switch (biton32(state)) {
    case _PSEUDO_US_LOWER:
    case _PSEUDO_US_RAISE:
      return update_tri_layer_state(state, _PSEUDO_US_RAISE, _PSEUDO_US_LOWER, _ADJUST);
      break;
    default:
      return update_tri_layer_state(state, _RAISE, _LOWER, _ADJUST);
      break;
  }
}

//SSD1306 OLED update loop
#ifdef OLED_ENABLE

// You need to add source files to SRC in rules.mk when using OLED display functions
void set_keylog(uint16_t keycode);
const char *read_keylog(void);
const char *read_modifier_state(void);
const char *read_host_led_state(void);

void matrix_init_user(void) {
  oled_init(false);   // turns on the display
}

void matrix_scan_user(void) {
  oled_task();  // this is what updates the display continuously
}

void render_status() {
  // Layer state
  char layer_str[22];
  oled_write("Layer: ", false);
  uint8_t layer = biton32(layer_state);
  uint8_t default_layer = biton32(eeconfig_read_default_layer());
    switch (layer) {
      case _QWERTY:
        switch (default_layer) {
          case _QWERTY:
            snprintf(layer_str, sizeof(layer_str), "Qwerty");
            break;
          case _PSEUDO_US:
            snprintf(layer_str, sizeof(layer_str), "Psuedo_US");
            break;
          default:
            snprintf(layer_str, sizeof(layer_str), "Undef-%d", default_layer);
            break;
        }
        break;
      case _RAISE:
        snprintf(layer_str, sizeof(layer_str), "Raise");
        break;
      case _LOWER:
        snprintf(layer_str, sizeof(layer_str), "Lower");
        break;
      case _PSEUDO_US_RAISE:
        snprintf(layer_str, sizeof(layer_str), "P_US_Raise");
        break;
      case _PSEUDO_US_LOWER:
        snprintf(layer_str, sizeof(layer_str), "P_US_Lower");
        break;
      case _ADJUST:
        snprintf(layer_str, sizeof(layer_str), "Adjust");
        break;
      default:
        snprintf(layer_str, sizeof(layer_str), "Undef-%d", layer);
    }
  oled_write_ln(layer_str, false);
  // Last entered keycode
  oled_write_ln(read_keylog(), false);
  // Modifier state
  oled_write_ln(read_modifier_state(), false);
  // Host Keyboard LED Status
  oled_write(read_host_led_state(), false);
}

void oled_task_user(void) {
  render_status();
}

#endif//OLED_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  #ifdef OLED_ENABLE
    if (record->event.pressed) {
      set_keylog(keycode);
    }
  #endif
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      break;
    case PSEUDO_US:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_PSEUDO_US);
      }
      break;
    case JIS2US:
      action_pseudo_lut(record, _QWERTY, keymap_jis2us);
      break;
  }
  return true;
}
