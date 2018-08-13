#include QMK_KEYBOARD_H
#include "bootloader.h"
#ifdef ENCODER_ENABLE
#include "common/knob_v2.h"
#endif
#ifdef PROTOCOL_LUFA
#include "lufa.h"
#include "split_util.h"
#endif
#ifdef SSD1306OLED
  #include "common/ssd1306.h"
#endif

extern keymap_config_t keymap_config;

#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

extern uint8_t is_master;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layer_number {
    _QWERTY = 0,
    _COLEMAK,
    _FN,
    _ADJ
};

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  FN,
  ADJ,
  BACKLIT,
  RGBRST
};

enum macro_keycodes {
  KC_SAMPLEMACRO,
};


// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

#define FN_ESC  LT(_FN, KC_ESC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Qwerty
   * ,------------------------------------------------.  ,------------------------------------------------.
   * |   `  |   1  |   2  |   3  |   4  |   5  |      |  |      |   6  |   7  |   8  |   9  |   0  | Del  |
   * |------+------+------+------+------+------|------|  |------|------+------+------+------+------+------|
   * | Tab  |   Q  |   W  |   E  |   R  |   T  |      |  |      |   Y  |   U  |   I  |   O  |   P  | Bksp |
   * |------+------+------+------+------+------|------|  |------|------+------+------+------+------+------|
   * | Ctrl |   A  |   S  |   D  |   F  |   G  |      |  |      |   H  |   J  |   K  |   L  |   ;  |  '   |
   * |------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
   * | Shift|   Z  |   X  |   C  |   V  |   B  |   [  |  |   ]  |   N  |   M  |   ,  |   .  |   /  |Enter |
   * |------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
   * |ADJ| Esc  | Alt  | GUI  | EISU |Lower |Space |  |Space |FN | KANA | Left | Down |  Up  |Right |
   * `------+------+------+------+------+------+------|  |------+------+------+------+------+------+------'
   *                                    |Lower |Space |  |Space |FN |
   *                                    `-------------'  `-------------'
   */
  [_QWERTY] = LAYOUT( \
      KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,   RGB_VAI,  KC_EQL,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, \
      KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,   RGB_VAD,  RGB_MOD, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS, \
      FN_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,   RGB_MOD,  RGBRST,  KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
      KC_LSPO, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,   KC_LBRC,  KC_RBRC, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSPC, \
      KC_LCTL, KC_LGUI, KC_LGUI, KC_LALT, FN,      KC_SPC, RGB_MOD,  FN,      FN,      KC_MINS, KC_EQL,  KC_DOWN, KC_PGUP, KC_PGDN, \
                                                   KC_SPC, KC_BSPC,  KC_ENT,  KC_SPC\
      ),

  /* Colemak
   * ,------------------------------------------------.  ,------------------------------------------------.
   * |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------|------|  |------|------+------+------+------+------+------|
   * |      |   Q  |   W  |   F  |   P  |   G  |      |  |      |   J  |   L  |   U  |   Y  |   ;  |      |
   * |------+------+------+------+------+------|------|  |------|------+------+------+------+------+------|
   * |      |   A  |   R  |   S  |   T  |   D  |      |  |      |   H  |   N  |   E  |   I  |   O  |      |
   * |------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
   * |      |   Z  |   X  |   C  |   V  |   B  |   [  |  |   ]  |   K  |   M  |      |      |      |      |
   * |------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
   *                                    |      |      |  |      |      |
   *                                    `-------------'  `--------=----'
   */
  [_COLEMAK] = LAYOUT( \
      KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,   RGB_VAI,  KC_EQL,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, \
      KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,   RGB_VAD,  RGB_MOD, KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSLS, \
      FN_ESC,  KC_A,    KC_R,    KC_S,    KC_T,    KC_D,   RGB_MOD,  RGBRST,  KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT, \
      KC_LSPO, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,   KC_LBRC,  KC_RBRC, KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSPC, \
      KC_LCTL, KC_LGUI, KC_LGUI, KC_LALT, FN,      KC_SPC, RGB_MOD,  FN,      FN,      KC_MINS, KC_EQL,  KC_DOWN, KC_PGUP, KC_PGDN, \
                                                   KC_SPC, KC_BSPC,  KC_ENT,  KC_SPC \
      ),


  /* FN
   * ,------------------------------------------------.  ,------------------------------------------------.
   * |   ~  |   !  |   @  |   #  |   $  |   %  |      |  |      |   ^  |   &  |   *  |   (  |   )  |      |
   * |------+------+------+------+------+------|------|  |------|------+------+------+------+------+------|
   * |   ~  |   !  |   @  |   #  |   $  |   %  |      |  |      |   ^  |   &  |   *  |   (  |   )  |      |
   * |------+------+------+------+------+------|------|  |------|------+------+------+------+------+------|
   * | Ctrl |   A  |   O  |   E  |   U  |   I  |      |  |      |   D  |   H  |   T  |   N  |   S  |  /   |
   * |------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
   * | Shift|   ;  |   Q  |   J  |   K  |   X  |   [  |  |   ]  |   B  |   M  |   W  |   V  |   Z  |Enter |
   * |------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
   * |ADJ| Esc  | Alt  | GUI  | EISU |Lower |Space |  |Space |FN | KANA | Left | Down |  Up  |Right |
   * |------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
   *                                    |Lower |Space |  |Space |FN |
   *                                    `-------------'  `------------'
   */
  [_FN] = LAYOUT( \
      KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   _______, KC_PSCR, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12, \
      _______, RGB_SAI, RGB_VAI, RGB_SAD, RESET,   KC_LBRC, _______, _______, KC_RBRC, KC_7,    KC_UP,   KC_9,    KC_0,    KC_HOME, \
      ADJ,     RGB_HUD, RGB_VAD, RGB_HUI, _______, _______, _______, _______, KC_F6,   KC_LEFT, KC_DOWN, KC_RGHT, KC_RBRC, KC_END, \
      _______, _______, _______, _______, _______, _______, _______, _______, KC_F12,  _______, _______, KC_PGDN, KC_PGUP, _______, \
      _______, _______, _______, _______, ADJ,     _______, _______, ADJ,     ADJ,     KC_MPLY, KC_MNXT, KC_MUTE, KC_VOLD, KC_VOLU, \
                                                   _______,  KC_DEL, _______, _______ \
      ),

  /* ADJ
   * ,------------------------------------------------.  ,------------------------------------------------.
   * |   ~  |   !  |   @  |   #  |   $  |   %  |      |  |      |   ^  |   &  |   *  |   (  |   )  |      |
   * |------+------+------+------+------+------|------|  |------|------+------+------+------+------+------|
   * |   ~  |   !  |   @  |   #  |   $  |   %  |      |  |      |   ^  |   &  |   *  |   (  |   )  |      |
   * |------+------+------+------+------+------|------|  |------|------+------+------+------+------+------|
   * | Ctrl |   A  |   O  |   E  |   U  |   I  |      |  |      |   D  |   H  |   T  |   N  |   S  |  /   |
   * |------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
   * | Shift|   ;  |   Q  |   J  |   K  |   X  |   [  |  |   ]  |   B  |   M  |   W  |   V  |   Z  |Enter |
   * |------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
   * |ADJ| Esc  | Alt  | GUI  | EISU |Lower |Space |  |Space |FN | KANA | Left | Down |  Up  |Right |
   * |------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
   *                                    |Lower |Space |  |Space |FN |
   *                                    `-------------'  `------------'
   */

  [_ADJ] =  LAYOUT( \
      KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   _______, _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12, \
      _______, RESET,   RGBRST,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_DEL, \
      _______, _______, _______, _______, _______, _______, _______, _______, _______, QWERTY,  COLEMAK, _______, _______, _______, \
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, \
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RGB_SMOD,RGB_HUD, RGB_SAD, RGB_VAD, \
                                                   _______, _______, _______, _______ \
      )
};


// define variables for reactive RGB
bool TOG_STATUS = false;
int RGB_current_mode;

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  //uint8_t shifted = get_mods() & (MOD_BIT(KC_LSHIFT) | MOD_BIT(KC_RSHIFT));

  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
    case COLEMAK:
      if(record->event.pressed) {
        persistent_default_layer_set(1UL<<_COLEMAK);
      }
      return false;
      break;
    case FN:
      if (record->event.pressed) {
        layer_on(_FN);
      } else {
        layer_off(_FN);
      }
      return false;
      break;
    case ADJ:
        if (record->event.pressed) {
          layer_on(_ADJ);
        } else {
          layer_off(_ADJ);
        }
        return false;
        break;
      //led operations - RGB mode change now updates the RGB_current_mode to allow the right RGB mode to be set after reactive keys are released
    case RGBRST:
      #ifdef RGBLIGHT_ENABLE
        if (record->event.pressed) {
          eeconfig_update_rgblight_default();
          rgblight_enable();
          RGB_current_mode = rgblight_config.mode;
        }
      #endif
      break;
  }
  return true;
}

void matrix_init_user(void) {
    #ifdef ENCODER_ENABLE
        knob_init();  //FOR ENCODER
    #endif
    #ifdef RGBLIGHT_ENABLE
      RGB_current_mode = rgblight_config.mode;
    #endif
    //SSD1306 OLED init, make sure to add #define SSD1306OLED in config.h
    #ifdef SSD1306OLED
        iota_gfx_init(!has_usb());   // turns on the display
    #endif
}


//SSD1306 OLED update loop, make sure to add #define SSD1306OLED in config.h
#ifdef SSD1306OLED

// hook point for 'led_test' keymap
//   'default' keymap's led_test_init() is empty function, do nothing
//   'led_test' keymap's led_test_init() force rgblight_mode_noeeprom(35);
__attribute__ ((weak))
void led_test_init(void) {}

void matrix_scan_user(void) {
  #ifdef ENCODER_ENABLE
    knob_report_t knob_report = knob_report_read();
    knob_report_reset();
    if (knob_report.phase) { // I check for phase to avoid handling the rotation twice (on 90 and 270 degrees).
      while (knob_report.dir > 0) {
        register_code(KC_VOLU);
        unregister_code(KC_VOLU);
        knob_report.dir--;
      }
      while (knob_report.dir < 0) {
        register_code(KC_VOLD);
        unregister_code(KC_VOLD);
        knob_report.dir++;
      }
    }
  #endif
     led_test_init();
     iota_gfx_task();  // this is what updates the display continuously
}

void matrix_update(struct CharacterMatrix *dest,
                          const struct CharacterMatrix *source) {
  if (memcmp(dest->display, source->display, sizeof(dest->display))) {
    memcpy(dest->display, source->display, sizeof(dest->display));
    dest->dirty = true;
  }
}

//assign the right code to your layers for OLED display
#define L_BASE 0
#define L_FN (1<<_FN)
#define L_ADJ (1<<_ADJ)
#define L_ADJ_TRI (L_ADJ|L_FN)

static void render_logo(struct CharacterMatrix *matrix) {

  static char logo[]={
    0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
    0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
    0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,
    0};
  matrix_write(matrix, logo);
  //matrix_write_P(&matrix, PSTR(" Split keyboard kit"));
}



void render_status(struct CharacterMatrix *matrix) {

  // Render to mode icon
  static char logo[][2][3]={{{0x95,0x96,0},{0xb5,0xb6,0}},{{0x97,0x98,0},{0xb7,0xb8,0}}};
  if(keymap_config.swap_lalt_lgui==false){
    matrix_write(matrix, logo[0][0]);
    matrix_write_P(matrix, PSTR("\n"));
    matrix_write(matrix, logo[0][1]);
  }else{
    matrix_write(matrix, logo[1][0]);
    matrix_write_P(matrix, PSTR("\n"));
    matrix_write(matrix, logo[1][1]);
  }

  // Define layers here, Have not worked out how to have text displayed for each layer. Copy down the number you see and add a case for it below
  char buf[40];
  snprintf(buf,sizeof(buf), "Undef-%ld", layer_state);
  matrix_write_P(matrix, PSTR("\nLayer: "));
    switch (layer_state) {
        case L_BASE:
           matrix_write_P(matrix, PSTR("Default"));
           break;
        case L_FN:
           matrix_write_P(matrix, PSTR("FN"));
           break;
        case L_ADJ:
        case L_ADJ_TRI:
           matrix_write_P(matrix, PSTR("ADJ"));
           break;
        default:
           matrix_write(matrix, buf);
    }

  // Host Keyboard LED Status
  char led[40];
    snprintf(led, sizeof(led), "\n%s  %s  %s",
            (host_keyboard_leds() & (1<<USB_LED_NUM_LOCK)) ? "NUMLOCK" : "       ",
            (host_keyboard_leds() & (1<<USB_LED_CAPS_LOCK)) ? "CAPS" : "    ",
            (host_keyboard_leds() & (1<<USB_LED_SCROLL_LOCK)) ? "SCLK" : "    ");
  matrix_write(matrix, led);
}


void iota_gfx_task_user(void) {
  struct CharacterMatrix matrix;

#if DEBUG_TO_SCREEN
  if (debug_enable) {
    return;
  }
#endif

  matrix_clear(&matrix);
  if(is_master){
    render_status(&matrix);
  }else{
    render_logo(&matrix);
  }
  matrix_update(&display, &matrix);
}

#endif
