#include QMK_KEYBOARD_H

enum custom_keycodes {
    SWITCH_LANG = SAFE_RANGE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    LAYOUT(
        LT(7, KC_Q), KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC,
        KC_A, KC_S, LT(6, KC_D), KC_F, KC_G, KC_H, KC_J, LT(6, KC_K), KC_L, KC_ENT,
        LSFT_T(KC_Z), LGUI_T(KC_X), KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, LCTL_T(KC_DOT),
        KC_LGUI, LALT_T(KC_LANG2), LT(1, KC_SPC), LT(1, KC_LANG1), KC_BSPC
    ),
    
    LAYOUT(
        KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_TRNS,
        LCTL_T(KC_EQL), KC_LBRC, KC_SLSH, KC_MINS, KC_RO, KC_SCLN, KC_QUOT, KC_RBRC, KC_NUHS, KC_JYEN,
        LSFT_T(KC_PLUS), KC_LCBR, KC_QUES, KC_UNDS, LSFT(KC_RO), KC_COLN, KC_DQUO, KC_RCBR, LSFT(KC_NUHS),
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),
    
    LAYOUT(
        KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, LGUI(KC_JYEN), KC_TRNS,
        KC_PLUS, KC_LCBR, KC_QUES, KC_UNDS, LSFT(KC_RO), KC_COLN, KC_DQUO, KC_RCBR, LSFT(KC_NUHS), LSFT(KC_JYEN),
        KC_LSFT, KC_LGUI, KC_LALT, KC_LANG2, KC_LSFT, KC_SPC, KC_LANG1, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),
    
    LAYOUT(
        LT(7, KC_Q), KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_TRNS,
        KC_A, KC_S, LT(6, KC_D), KC_F, KC_G, KC_H, KC_J, LT(6, KC_K), KC_L, KC_ENT,
        LSFT_T(KC_Z), LGUI_T(KC_X), KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, LCTL_T(KC_DOT),
        KC_LGUI, LALT_T(KC_LANG2), LT(4, KC_SPC), LT(4, KC_LANG1), KC_BSPC
    ),
        
    LAYOUT(
        KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_TRNS,
        KC_CIRC, KC_AT, KC_SLSH, KC_MINS, KC_UNDS, KC_SCLN, KC_COLN, KC_LBRC, KC_RBRC, KC_JYEN,
        LT(5, KC_TILD), KC_GRV, KC_QUES, KC_EQL, KC_UNDS, KC_PLUS, KC_ASTR, KC_LCBR, KC_RCBR,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),
    
    LAYOUT(
        KC_EXLM, KC_DQUO, KC_HASH, KC_DLR, KC_PERC, KC_AMPR, KC_QUOT, KC_LPRN, KC_RPRN, KC_BSLS, KC_TRNS,
        KC_TILD, KC_GRV, KC_QUES, KC_EQL, KC_UNDS, KC_PLUS, KC_ASTR, KC_LCBR, KC_RCBR, KC_PIPE,
        KC_LSFT, KC_LGUI, KC_LALT, KC_LANG2, KC_LSFT, KC_SPC, KC_LANG1, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),
    
    LAYOUT(
        KC_ESC, KC_TAB, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_UP, KC_NO, KC_NO, KC_TRNS,
        KC_LCTL, KC_TRNS, KC_QUES, KC_EXLM, KC_NO, KC_NO, KC_LEFT, KC_DOWN, KC_RGHT, KC_NO,
        KC_LSFT, KC_LGUI, KC_LALT, KC_LANG2, KC_TRNS, KC_NO, KC_LANG1, KC_NO, KC_NO,
        KC_TRNS, KC_TRNS, SWITCH_LANG, KC_TRNS, KC_TRNS
    ), 
    
    LAYOUT(
        KC_NO, KC_TAB, KC_NO, KC_NO, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_TRNS,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12,
        KC_LSFT, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, MO(8),
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),
    
    LAYOUT(
        RGB_TOG, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, KC_NO, KC_NO, KC_NO, DF(0), DF(3), KC_TRNS,
        RGB_M_P, RGB_M_B, RGB_M_R, RGB_M_SW, RGB_M_SN, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        RGB_M_K, RGB_M_X, RGB_M_G, KC_NO, KC_NO, QK_BOOT, KC_NO, KC_NO, KC_NO,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    )
};

bool is_lang1 = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case SWITCH_LANG:
            if (record->event.pressed) {

                if (is_lang1) {
                    register_code(KC_LANG1);
                    is_lang1 = false;
                }
                else {
                    register_code(KC_LANG2);
                    is_lang1 = true;
                }
            }
            break;
        case KC_LANG1:
            if (record->event.pressed) {
                is_lang1 = false;
            }
            break;

        case KC_LANG2:
            if (record->event.pressed) {
                is_lang1 = true;
            }
            break;
    }
    return true;
}
