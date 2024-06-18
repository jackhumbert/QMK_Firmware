const uint16_t PROGMEM ly0_r0[] = { KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO };
const uint16_t PROGMEM ly0_r1[] = { KC_Q, KC_W, KC_E, KC_R, KC_T, KC_NO, KC_NO, KC_Y, KC_U, KC_I, KC_O, KC_P };
const uint16_t PROGMEM ly0_r2[] = { KC_A, KC_S, KC_D, KC_F, KC_G, KC_NO, KC_NO, KC_H, KC_J, KC_K, KC_L, KC_SCLN };
const uint16_t PROGMEM ly0_r3[] = { KC_Z, KC_X, KC_C, KC_V, KC_B, KC_NO, KC_NO, KC_N, KC_M, KC_COMM, KC_DOT, KC_BSPC };
const uint16_t PROGMEM ly0_r4[] = { KC_NO, KC_NO, KC_NO, MO(2), KC_SPC, KC_NO, KC_NO, KC_RSFT, MO(1), KC_NO, KC_NO, KC_NO };

const uint16_t PROGMEM ly1_r0[] = { KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO };
const uint16_t PROGMEM ly1_r1[] = { KC_DOT, KC_4, KC_5, KC_6, KC_NO, KC_NO, KC_NO, KC_NO, KC_PIPE, KC_MINS, KC_SLSH, KC_NO };
const uint16_t PROGMEM ly1_r2[] = { KC_1, KC_2, KC_3, KC_0, KC_NO, KC_NO, KC_NO, KC_DQUO, KC_UNDS, KC_EQL, MO(3), KC_TILD };
const uint16_t PROGMEM ly1_r3[] = { KC_7, KC_8, KC_9, KC_NO, KC_NO, KC_NO, KC_NO, KC_PLUS, KC_QUES, KC_EXLM, KC_DEL, KC_NO };
const uint16_t PROGMEM ly1_r4[] = { KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_NO };

const uint16_t PROGMEM ly2_r0[] = { KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO };
const uint16_t PROGMEM ly2_r1[] = { KC_NO, KC_BSLS, KC_PERC, KC_DLR, KC_NO, KC_NO, KC_NO, KC_CIRC, KC_LCBR, KC_RCBR, KC_NO, KC_ASTR };
const uint16_t PROGMEM ly2_r2[] = { KC_LPRN, KC_RPRN, KC_COLN, KC_NO, KC_NO, KC_NO, KC_NO, KC_QUOT, KC_LBRC, KC_RBRC, KC_SCLN, KC_NO };
const uint16_t PROGMEM ly2_r3[] = { KC_GRV, KC_AT, KC_AMPR, KC_NO, KC_NO, KC_NO, KC_NO, KC_HASH, KC_COMM, KC_DOT, KC_DEL, KC_NO };
const uint16_t PROGMEM ly2_r4[] = { KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_TRNS, KC_ESC, KC_NO, KC_NO, KC_NO };

const uint16_t PROGMEM ly3_r0[] = { KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO };
const uint16_t PROGMEM ly3_r1[] = { KC_NO, KC_F4, KC_F5, KC_F6, KC_F10, KC_NO, KC_NO, KC_HOME, KC_UP, KC_END, KC_NO, KC_NO };
const uint16_t PROGMEM ly3_r2[] = { KC_F1, KC_F2, KC_F3, KC_F11, KC_NO, KC_NO, KC_NO, KC_LEFT, KC_DOWN, KC_RGHT, KC_TRNS, KC_NO };
const uint16_t PROGMEM ly3_r3[] = { KC_F7, KC_F8, KC_F9, KC_F12, KC_NO, KC_NO, KC_NO, KC_PGUP, KC_NO, KC_PGDN, KC_NO, KC_NO };
const uint16_t PROGMEM ly3_r4[] = { KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_NO };

const uint16_t PROGMEM keymaps[][MATRIX_rS][MATRIX_COLS] = {
    [0] = LAYOUT_ortho_5x12(
        ly0_r0[0], ly0_r0[1], ly0_r0[2], ly0_r0[3], ly0_r0[4], ly0_r0[5],     ly0_r0[6], ly0_r0[7], ly0_r0[8], ly0_r0[9], ly0_r0[10], ly0_r0[11],
        ly0_r1[0], ly0_r1[1], ly0_r1[2], ly0_r1[3], ly0_r1[4], ly0_r1[5],     ly0_r1[6], ly0_r1[7], ly0_r1[8], ly0_r1[9], ly0_r1[10], ly0_r1[11],
        ly0_r2[0], ly0_r2[1], ly0_r2[2], ly0_r2[3], ly0_r2[4], ly0_r2[5],     ly0_r2[6], ly0_r2[7], ly0_r2[8], ly0_r2[9], ly0_r2[10], ly0_r2[11],
        ly0_r3[0], ly0_r3[1], ly0_r3[2], ly0_r3[3], ly0_r3[4], ly0_r3[5],     ly0_r3[6], ly0_r3[7], ly0_r3[8], ly0_r3[9], ly0_r3[10], ly0_r3[11],
        ly0_r4[0], ly0_r4[1], ly0_r4[2], ly0_r4[3], ly0_r4[4], ly0_r4[5],     ly0_r4[6], ly0_r4[7], ly0_r4[8], ly0_r4[9], ly0_r4[10], ly0_r4[11]
    ),
    [1] = LAYOUT_ortho_5x12(
        ly1_r0[0], ly1_r0[1], ly1_r0[2], ly1_r0[3], ly1_r0[4], ly1_r0[5],     ly1_r0[6], ly1_r0[7], ly1_r0[8], ly1_r0[9], ly1_r0[10], ly1_r0[11],
        ly1_r1[0], ly1_r1[1], ly1_r1[2], ly1_r1[3], ly1_r1[4], ly1_r1[5],     ly1_r1[6], ly1_r1[7], ly1_r1[8], ly1_r1[9], ly1_r1[10], ly1_r1[11],
        ly1_r2[0], ly1_r2[1], ly1_r2[2], ly1_r2[3], ly1_r2[4], ly1_r2[5],     ly1_r2[6], ly1_r2[7], ly1_r2[8], ly1_r2[9], ly1_r2[10], ly1_r2[11],
        ly1_r3[0], ly1_r3[1], ly1_r3[2], ly1_r3[3], ly1_r3[4], ly1_r3[5],     ly1_r3[6], ly1_r3[7], ly1_r3[8], ly1_r3[9], ly1_r3[10], ly1_r3[11],
        ly1_r4[0], ly1_r4[1], ly1_r4[2], ly1_r4[3], ly1_r4[4], ly1_r4[5],     ly1_r4[6], ly1_r4[7], ly1_r4[8], ly1_r4[9], ly1_r4[10], ly1_r4[11]
    ),
    [2] = LAYOUT_ortho_5x12(
        ly2_r0[0], ly2_r0[1], ly2_r0[2], ly2_r0[3], ly2_r0[4], ly2_r0[5],     ly2_r0[6], ly2_r0[7], ly2_r0[8], ly2_r0[9], ly2_r0[10], ly2_r0[11],
        ly2_r1[0], ly2_r1[1], ly2_r1[2], ly2_r1[3], ly2_r1[4], ly2_r1[5],     ly2_r1[6], ly2_r1[7], ly2_r1[8], ly2_r1[9], ly2_r1[10], ly2_r1[11],
        ly2_r2[0], ly2_r2[1], ly2_r2[2], ly2_r2[3], ly2_r2[4], ly2_r2[5],     ly2_r2[6], ly2_r2[7], ly2_r2[8], ly2_r2[9], ly2_r2[10], ly2_r2[11],
        ly2_r3[0], ly2_r3[1], ly2_r3[2], ly2_r3[3], ly2_r3[4], ly2_r3[5],     ly2_r3[6], ly2_r3[7], ly2_r3[8], ly2_r3[9], ly2_r3[10], ly2_r3[11],
        ly2_r4[0], ly2_r4[1], ly2_r4[2], ly2_r4[3], ly2_r4[4], ly2_r4[5],     ly2_r4[6], ly2_r4[7], ly2_r4[8], ly2_r4[9], ly2_r4[10], ly2_r4[11]
    ),
    [3] = LAYOUT_ortho_5x12(
        ly3_r0[0], ly3_r0[1], ly3_r0[2], ly3_r0[3], ly3_r0[4], ly3_r0[5],     ly3_r0[6], ly3_r0[7], ly3_r0[8], ly3_r0[9], ly3_r0[10], ly3_r0[11],
        ly3_r1[0], ly3_r1[1], ly3_r1[2], ly3_r1[3], ly3_r1[4], ly3_r1[5],     ly3_r1[6], ly3_r1[7], ly3_r1[8], ly3_r1[9], ly3_r1[10], ly3_r1[11],
        ly3_r2[0], ly3_r2[1], ly3_r2[2], ly3_r2[3], ly3_r2[4], ly3_r2[5],     ly3_r2[6], ly3_r2[7], ly3_r2[8], ly3_r2[9], ly3_r2[10], ly3_r2[11],
        ly3_r3[0], ly3_r3[1], ly3_r3[2], ly3_r3[3], ly3_r3[4], ly3_r3[5],     ly3_r3[6], ly3_r3[7], ly3_r3[8], ly3_r3[9], ly3_r3[10], ly3_r3[11],
        ly3_r4[0], ly3_r4[1], ly3_r4[2], ly3_r4[3], ly3_r4[4], ly3_r4[5],     ly3_r4[6], ly3_r4[7], ly3_r4[8], ly3_r4[9], ly3_r4[10], ly3_r4[11]
    )
};


