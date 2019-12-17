#include QMK_KEYBOARD_H

#ifdef BOARD_GENERIC_STM32_F103
#include "8x18_arm.h"
#endif

#include "virtser.h"

#include <print.h>
#define _QWR 0
#define _CDH 1
#define _SYM 2
#define _MOV 3
#define _TRAN 5


#define LAYOUT_local LAYOUT_mobile_XUW

enum layer_keycodes {
    QWR,
    CDH,
    SYM,
    MOV,
    NUM,
    TRAN
};


// Shorter spacing
#define XXXX  KC_NO
#define ____  KC_TRNS

// Custom macros

/* Fn Keys */
#define TT_SYM MO(_SYM)
#define TT_MOV KC_FN2
#define TT_NUM MO(_NUM)
#define SSFT ACTION_MODS_ONESHOT(MOD_LSFT)
#define SSYM LT(_SYM, KC_SPC)
#define MVTAB LT(_MOV,KC_TAB)
#define BKSYM LT(_SYM, KC_BSPC)
#define MV2 LT(MOV, KC_2)
#define MV3 LT(MOV, KC_3)
#define MV4 LT(MOV, KC_4)
#define MV8 LT(MOV, KC_8)
#define MV9 LT(MOV, KC_9)
#define MV0 LT(MOV, KC_0)

enum macro_keycodes {
    DHPASTE=1,
    VIBRK,
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*  QWERTY
*
* |ESC | F1 | F2 | F3 | F4 | F5 | F6 | f7 | F8 | F9 | F10| F11| F12|Vol-|Vol+|_CDH|
*  -------------------------------------------------------------------------------'
* | ESC |  1 |  2 |  3 |  4 |  5 |  6 |  7 |  8 |  9 |  0 |  - |  = |Bakspace| Del|
* ---------------------------------------------------------------------------
* | tab  |  q |  w |  e |  r |  t |  y |  u |  i |  o |  p |  [ |  ] |  \    |    |
*  -------------------------------------------------------------------------------'
* |Bak/Mov|  a |  s |  d |  f |  g |  h |  j |  k |  l |  ; |  ' | enter     |PgUp|
* --------------------------------------------------------------------------------
* |Lsft    |  z |  x |  c |  v |  b |  n |  m |  , |  . |  / |      Rsft| Up| PgDn|
* ---------------------------------------------------------------------------------
* |Lctl   |Lgui  |Lalt |       Space/Sym      | GUI |  Sym |  Rctl |Left|Down|Rght|
* ---------------------------------------------------------------------------------
*/

[_QWR] = LAYOUT_local( \
KC_ESC,   KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8,   KC_F9, KC_F10,    KC_F11,   KC_F12, KC_VOLD, KC_VOLU, TG(CDH),\
KC_GRAVE, KC_1, MV2,  MV3 ,  MV4, KC_5, KC_6, KC_7, MV8,    MV9,    MV0,    KC_MINUS, KC_EQL, KC_BSPC, KC_DEL,\
KC_TAB,   KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I,   KC_O, KC_P,    KC_LBRC,  KC_RBRC,KC_BSLS,\
BKSYM,    KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K,   KC_L, KC_SCLN, KC_QUOT,  KC_ENT, KC_PGUP,\
KC_LSFT,  KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM,KC_DOT,KC_SLSH,KC_RSFT,  KC_UP,  KC_PGDN,\
KC_LCTL,  KC_LGUI, KC_LALT, KC_SPC, KC_RGUI, TT_SYM,  KC_CAPS, KC_LEFT, KC_DOWN, KC_RIGHT
),


[_CDH] = LAYOUT_local(\
____,    ____, ____, ____, ____, ____, ____, ____, ____,   ____,   ____,    ____,     ____,   ____,    ____,    ____,  \
KC_GRAVE, KC_1, KC_2, KC_3 ,KC_4, KC_5, KC_6, KC_7, KC_8,   KC_9, KC_0,    KC_MINUS, KC_EQL, KC_BSPC, KC_DEL,\
____,    KC_Q, KC_W, KC_F, KC_P, KC_B, KC_J, KC_L, KC_U,   KC_Y,   KC_SCLN, ____,    ____,    ____,\
MVTAB,   KC_A, KC_R, KC_S, KC_T, KC_G, KC_M, KC_N, KC_E,   KC_I,   KC_O,    KC_QUOT, KC_ENT,  KC_2,\
KC_LSFT, KC_Z, KC_X, KC_C, M(DHPASTE), KC_V, KC_K, KC_H, KC_COMM,  KC_DOT,  KC_SLSH, KC_RSFT, ____,   KC_1,\
____,     ____, ____ , KC_FN1, ____, ____, ____, ____, ____,   ____
),

/*  SYM
*
* |ESC | F1 | F2 | F3 | F4 | F5 | F6 | f7 | F8 | F9 | F10| F11| F12|Vol-|Vol+|_CDH|
*  -------------------------------------------------------------------------------'
* | ESC |  1 |  2 |  3 |  4 |  5 |  6 |  7 |  8 |  9 |  0 |  - |  = |Bakspace|Del |
*  --------------------------------------------------------------------------
* | ESC: | ^  |  { |  } |  @ |  % |    |   [ | ( | )  | _  |  [ |  ] |  \    |    |
*  -------------------------------------------------------------------------------'
* |Bak/Mov|  ! |  # |  0 | =  |  { |   } | -  | 1 |  + |  ] |  ` | enter     |PgUp|
* --------------------------------------------------------------------------------
* |Lsft    |  ; | ~ |  : | ~  | "|"|  $ | *   |    |  .  |  / |      Rsft| Up| PgDn|
* ---------------------------------------------------------------------------------
* |Lctl   |Lgui  |Lalt |       Space/Sym      | GUI |  Sym |  Rctl |Left|Down|Rght|
* ---------------------------------------------------------------------------------
*/

[_SYM] = LAYOUT_local(\
____,     ____, ____, ____, ____, ____, ____, ____, ____,   ____, ____,    ____,     ____,   ____,    ____,     ____,  \
____,     ____, ____, ____, ____, ____, ____, ____, ____,   ____, ____,    ____,     ____,   ____,    ____,   \
____,  KC_CIRC, KC_LCBR,  KC_RCBR, KC_AT,  KC_PERC,         ____, KC_LBRC,KC_LPRN,KC_RPRN,  KC_UNDS,  ____,   ____,   ____,\
____,  KC_EXLM, KC_HASH,  KC_0,   KC_EQL,  KC_LCBR,      KC_RCBR, KC_MINS,KC_1,   KC_PLUS,  KC_RBRC,  KC_GRV,   ____,  ____,\
____,  KC_SCLN, KC_TILDE, KC_COLN,KC_TILDE,KC_PIPE,       KC_DLR, KC_ASTR, ____,  KC_DOT ,  KC_SLSH,  ____, ____, ____,\
____,     ____, ____, ____, ____, ____, ____, ____, ____,   ____
),
/* MOVE simple version

* |ESC | MAC| Win|RdLn| VI |    |    |    |    |    |    |    |    |    |    |    |
*  -------------------------------------------------------------------------------'
* |     |    |  2 |  3 |  4 |  5 |  6 |  7 |  8 |  9 |  0 |  - |  = |Bakspace| Del|
* ---------------------------------------------------------------------------
* | tab  |    |    |Find|    |pTab |DSOL|DelW| Up |DelW|DEOL|  [ |  ] |  \    |    |
*  -------------------------------------------------------------------------------'
* |Bak/Mov|    |    |    |    |nTab |GSOL| <- | Dwn | -> | EOL |  ' | enter   |PgUp|
* --------------------------------------------------------------------------------
* |Lsft    |Undo| Cut|Copy|Pste|    |    |    |    |    |  / |      Rsft| Up| PgDn|
* ---------------------------------------------------------------------------------
* |Lctl   |Lgui  |Lalt |       Space/Sym      | GUI |  Sym |  Rctl |Left|Down|Rght|
* ---------------------------------------------------------------------------------
*/

[_MOV] = LAYOUT_local(\
____,     ____, ____, ____, ____, ____, ____, ____, ____,   ____, ____,    ____,     ____,   ____,    ____,     ____,  \
____,     ____, ____, ____, ____, ____,      ____, ____, ____, ____, ____,    ____, ____,   ____, ____,   \
____,     ____, ____, ____, ____, ____,      ____, ____, KC_UP, ____, ____,    ____, ____,   ____, \
____,     ____, ____, ____, ____, ____,      ____,  KC_LEFT, KC_DOWN, KC_RIGHT,  ____,    ____, ____,   ____, \
____,     ____, ____, ____, ____, ____,      ____, ____, ____, ____, ____,    ____, ____,   ____, \
____,     ____, ____, ____, ____, ____,      ____, ____, ____, ____
)

/* MOVE babble version version

* |ESC | MAC| Win|RdLn| VI |    |    |    |    |    |    |    |    |    |    |    |
*  -------------------------------------------------------------------------------'
* |     |    |  2 |  3 |  4 |  5 |  6 |  7 |  8 |  9 |  0 |  - |  = |Bakspace| Del|
* ---------------------------------------------------------------------------
* | tab  |    |    |Find|    |pTab |DSOL|DelW| Up |DelW|DEOL|  [ |  ] |  \    |    |
*  -------------------------------------------------------------------------------'
* |Bak/Mov|    |    |    |    |nTab |GSOL| <- | Dwn | -> | EOL |  ' | enter   |PgUp|
* --------------------------------------------------------------------------------
* |Lsft    |Undo| Cut|Copy|Pste|    |    |    |    |    |  / |      Rsft| Up| PgDn|
* ---------------------------------------------------------------------------------
* |Lctl   |Lgui  |Lalt |       Space/Sym      | GUI |  Sym |  Rctl |Left|Down|Rght|
* ---------------------------------------------------------------------------------
*/
/*

[_MOV] = LAYOUT_local(\
  ____,    B_MAC,B_WIN,B_READ, B_VI, ____, ____, ____, ____,   ____, ____,    ____,     ____,   ____,    ____,     ____,  \
  ____,      ____, B_PAPP, B_NAPP, ____, ____,      ____, ____, ____,   ____, ____,    ____,     ____,   ____,    ____,   \
  ____,     B_UNDO, ____, B_BFND, ____, B_PTAB,     B_DSOL, B_DLW, B_UP,   B_DRW, B_DEOL,  ____,  ____,   ____, \
  ____,     B_SELA, B_BRLD, ____, ____, B_NXTB,     B_GSOL, B_L1C, B_DOWN, B_R1C,B_GEOL,   ____, ____, ____,\
  ____,     B_UNDO,B_CUT, B_COPY, B_PAST, B_PAST,    ____, ____, ____, ____, ____,       ____,  ____,   ____, \
  ____,     ____, ____, ____, ____, ____, ____, ____, ____,   ____
),


[_TRAN] = LAYOUT_local(\
  ____,     ____, ____, ____, ____, ____, ____, ____, ____,   ____, ____,    ____,     ____,   ____,    ____,     ____,  \
  ____,     ____, ____, ____, ____, ____,      ____, ____, ____, ____, ____,    ____, ____,   ____, ____,   \
  ____,     ____, ____, ____, ____, ____,      ____, ____, ____, ____, ____,    ____, ____,   ____, \
  ____,     ____, ____, ____, ____, ____,      ____, ____, ____, ____, ____,    ____, ____,   ____, \
  ____,     ____, ____, ____, ____, ____,      ____, ____, ____, ____, ____,    ____, ____,   ____, \
  ____,     ____, ____, ____, ____, ____,      ____, ____, ____, ____
)
*/
};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_KEY(_SYM,KC_SPACE),
    [2] = ACTION_LAYER_TAP_KEY(_MOV,KC_BSPC)
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case QWR:
            if (record->event.pressed) {
                layer_off(_CDH);
            }
        return false;
        break;

        case CDH:
        if (record->event.pressed) {
            layer_on(_CDH);
        }
        return false;
        break;

        case SYM:
        if (record->event.pressed) {
            layer_on(_SYM);
        } else {
          layer_off(_SYM);
        }

        return false;
        break;
    }
    return true;

}

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
/* Any clever remapping with modifiers should happen here e.g. shift bablkey does opposite*/
#ifdef USE_BABLPASTE
    if( id >= BABL_START_NUM && id < (BABL_START_NUM + BABL_NUM_MACROS ) ) {
   		if (record->event.pressed)  { // is there a case where this isn't desired?
            babblePaste ( record,  id );
            return MACRO_NONE;
        }
    }
#endif


  // MACRODOWN only works in this function
    switch(id) {
        case 0:
            if (record->event.pressed) {
                register_code(KC_RSFT);
            } else {
                unregister_code(KC_RSFT);
            }
            break;

 /* Colemak mod-dh moves the D key to the qwerty V position
   This hack makes apple-V_position do what I mean */
        case DHPASTE:
            if(keyboard_report->mods & MOD_BIT(KC_LGUI) ) {
                if (record->event.pressed) {
                    clear_keyboard_but_mods();
                    register_code(KC_V);
                } else {
                    unregister_code(KC_V);
                }
            } else {
                if (record->event.pressed) {
                    register_code(KC_D);
                } else {
                    unregister_code(KC_D);
                }
            }
            break;

        case VIBRK: // vi esc:
            if (record->event.pressed) {
                return MACRO( T(ESC),D(LSFT),T(SCLN),U(LSFT), END );
            }
            break;

        default:
            return MACRO_NONE;
    }
return MACRO_NONE;
};


void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour
  // debug_enable=true;
  //debug_matrix=true;
  //debug_keyboard=true;
  //debug_mouse=true;
}


void matrix_init_user(void) {
    #ifdef RGB_MATRIX_ENABLE
    #ifdef RGB_DI_PIN
        rgblight_setrgb(RGB_GREEN);
    #endif
    #endif //RGB_matrix  
}


void matrix_scan_user(void) {
}


void led_set_user(uint8_t usb_led) {
}



// Runs whenever there is a layer state change.
layer_state_t layer_state_set_user(layer_state_t state) {
    uint8_t layer = get_highest_layer(state);
    switch (layer) {
        case 0:
            #ifdef RGBLIGHT_COLOR_LAYER_0
                rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
            #else
                #ifdef RGBLIGHT_ENABLE
                    rgblight_init();
                #endif
            #endif
            break;

        case 1:
            #ifdef RGBLIGHT_COLOR_LAYER_1
                rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
            #endif
            break;

        case 2:
            #ifdef RGBLIGHT_COLOR_LAYER_2
                rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
            #endif
            break;

        case 3:
            #ifdef RGBLIGHT_COLOR_LAYER_3
                rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
            #endif
            break;

        case 4:
            #ifdef RGBLIGHT_COLOR_LAYER_4
                rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
            #endif
            break;

        case 5:
            #ifdef RGBLIGHT_COLOR_LAYER_5
                rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
            #endif
            break;

        default:
          break;
      }
    #ifdef VIRTSER_ENABLE
      //virtser_send(layer + 48); // ascii 0 is 48
    #endif
  return state;
};

// custom tapping term lengths. 
uint16_t get_tapping_term(uint16_t keycode) {
    switch (keycode) {
        case LT(_MOV, KC_TAB):
            return TAPPING_TERM ;
            break;
        default:
        return TAPPING_TERM;
    }
}



#ifdef VIRTSER_ENABLE
/* listen on serial for commands. Either a set of lower case letters mapped to colors, 
/  or upper case letters that change RGB mode. 
/  special command C takes 3 numbers as arguments, terminated with a newline or comma or excess digits.
Command C takes 3-5octets of RGB settings. Numbers can be terminated with a comma or period. 
3 octets = set all LED, 4th argument specfies specfic LED, 4+5 specify start and stop LEDs.
*/ 

uint8_t ser_rgbByte[18] ; //ascii string 
uint8_t ser_cmd_started =0 ; // are we in process
uint8_t ser_got_RGBbytes =0 ; // how many bytes we've recived. 
uint8_t rgb_r[6]; // R, g, b, P1, p2
uint8_t bs=0; // how many bytes into our rgbBytestring.

void virtser_recv(uint8_t serIn) { 
#ifdef RGBLIGHT_ENABLE 
    if ((serIn == 10 ) || (serIn ==  13) || ser_got_RGBbytes >=5) { //reached newline or max digits

        if (ser_cmd_started) {
            ser_cmd_started =0 ; // end loop at newline
            virtser_send('|');

            if (ser_got_RGBbytes==3) {
                rgblight_setrgb( rgb_r[0], rgb_r[1], rgb_r[2]);
            }

            if (ser_got_RGBbytes ==4) {
                if (( rgb_r[3] >=0)  && (rgb_r[3] <= RGBLED_NUM) ) { // is pos1 plausible
                    rgblight_setrgb_at ( rgb_r[0], rgb_r[1], rgb_r[2], rgb_r[3]);
                } else {
                        rgblight_setrgb( rgb_r[0], rgb_r[1], rgb_r[2]);
                }
            }

            if (ser_got_RGBbytes == 5) { // are start and end positions plausible? 
                if ( (rgb_r[4] >0)  && (rgb_r[4] <= RGBLED_NUM) && (rgb_r[4] > rgb_r[3]) && 
                 (rgb_r[3] >=0)  && (rgb_r[3] <= (RGBLED_NUM -1))  ) {
                    rgblight_setrgb_range(rgb_r[0], rgb_r[1], rgb_r[2], rgb_r[3], rgb_r[4]);
               } else {
                   rgblight_setrgb( rgb_r[0], rgb_r[1], rgb_r[2]);
               }
            }
        } else { // newline outside of command loop, or something that can be ignored. 
          //virtser_send('.');
        }
    } 

    if (1 == ser_cmd_started) { // collecting bytes. 
        if  (   // it is time to compute a byte
          ( ( (serIn == ',') || (serIn == '.') ) && (bs > 0) ) || // signal done with the byte. 
            (bs ==2 )){ //or we know this is last.
        
            if ( (serIn <= '9') && (serIn >='0') ) { //3rd asci digit 
                ser_rgbByte[bs] = serIn;
                bs++;
            //  virtser_send(serIn);
            }

            if (bs>3) {
                rgb_r[ser_got_RGBbytes]=255;
                ser_got_RGBbytes ++;
            }
            if (bs==3) {
              rgb_r[ser_got_RGBbytes] = (ser_rgbByte[0] -'0')*100 + (ser_rgbByte[1] -'0')*10 + (ser_rgbByte[2] -'0' );
              ser_got_RGBbytes ++;
            }
            if (bs ==2 ) {
               rgb_r[ser_got_RGBbytes] = (ser_rgbByte[0] -'0')*10 +  (ser_rgbByte[1] -'0' );
               ser_got_RGBbytes ++;
            }
            if (bs ==1) {
               rgb_r[ser_got_RGBbytes] = (ser_rgbByte[0] -'0');
               ser_got_RGBbytes ++;
            }  // {else wipe & start over}

          bs=0;
    //  virtser_send(ser_got_RGBbytes+'0');

        } else { // haven't got enough for our byte / no terminal marker
            if ( (serIn <= '9') && (serIn >='0') ) { //ascii only 
                ser_rgbByte[bs] = serIn;
                bs++;
            //    virtser_send(serIn);
            }
        }
    } else { //not in command loop - next is command w/o arguments, or start of one. 
        switch (serIn) {
            case 'C': // color switch
                ser_cmd_started=1;
                ser_got_RGBbytes = bs =0;
                virtser_send('/');
                break;
        
            case 'r': //red
                rgblight_setrgb(RGB_RED);
                break;
         
            case 'g': 
                rgblight_setrgb(RGB_GREEN);
                break;
   
            case 'b':  // color switch
                rgblight_setrgb(RGB_BLUE);
                break;

            case 'w':  // color switch
                rgblight_setrgb(RGB_WHITE);
                break;

            case 'o':  // color black/off
                rgblight_setrgb(0,0,0);
                break;
               
            case 'T':  // toggle
                rgblight_toggle();
                break;
            
            case 'P': // pulse led
                rgblight_mode_noeeprom(RGBLIGHT_MODE_BREATHING);
                break; 
            case 'S':  // Static
                rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT);
                break;
           
            case 'U':  // Rainbow
                rgblight_mode_noeeprom(RGBLIGHT_MODE_RAINBOW_MOOD);
                break;
                   
            default: 
           //     virtser_send(serIn);
                break;

        }
    }

}
#endif // RGBLIGHT_ENABLE
#endif // VirtSerial
