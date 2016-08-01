#ifndef KEYBOARDS_ERGODOX_INFINITY_INFINITY_H_
#define KEYBOARDS_ERGODOX_INFINITY_INFINITY_H_

#include "quantum.h"

void ergodox_board_led_on(void);
void ergodox_right_led_1_on(void);
void ergodox_right_led_2_on(void);
void ergodox_right_led_3_on(void);
void ergodox_right_led_on(uint8_t led);

void ergodox_board_led_off(void);
void ergodox_right_led_1_off(void);
void ergodox_right_led_2_off(void);
void ergodox_right_led_3_off(void);
void ergodox_right_led_off(uint8_t led);

inline void ergodox_led_all_on(void)
{
    ergodox_board_led_on();
    ergodox_right_led_1_on();
    ergodox_right_led_2_on();
    ergodox_right_led_3_on();
}

inline void ergodox_led_all_off(void)
{
    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
}

inline void ergodox_right_led_1_set(uint8_t n){
	if (n) {
		ergodox_right_led_1_on();
	} else {
		ergodox_right_led_1_off();
	}
}

inline void ergodox_right_led_2_set(uint8_t n){
	if (n) {
		ergodox_right_led_2_on();
	} else {
		ergodox_right_led_2_off();
	}
}

inline void ergodox_right_led_3_set(uint8_t n){
	if (n) {
		ergodox_right_led_3_on();
	} else {
		ergodox_right_led_3_off();
	}
}

inline void ergodox_right_led_set(uint8_t led, uint8_t n){
	if (n) {
		ergodox_right_led_on(led);
	} else {
		ergodox_right_led_off(led);
	}
}

inline void ergodox_led_all_set(uint8_t n) {
    ergodox_right_led_1_set(n);
    ergodox_right_led_2_set(n);
    ergodox_right_led_3_set(n);
}

#define KEYMAP( \
    A80, A70, A60, A50, A40, A30, A20,  \
    A81, A71, A61, A51, A41, A31, A21,  \
    A82, A72, A62, A52, A42, A32,       \
    A83, A73, A63, A53, A43, A33, A23,  \
    A84, A74, A64, A54, A44,            \
                                  A13, A03, \
                                       A04, \
                             A34, A24, A14, \
         B20, B30, B40, B50, B60, B70, B80, \
         B21, B31, B41, B51, B61, B71, B81, \
              B32, B42, B52, B62, B72, B82, \
         B23, B33, B43, B53, B63, B73, B83, \
                   B44, B54, B64, B74, B84, \
    B03, B13,     \
    B04,          \
    B14, B24, B34 \
) { \
    { KC_NO, KC_NO, KC_NO, A03,   A04 }, \
    { KC_NO, KC_NO, KC_NO, A13,   A14 }, \
    { A20,   A21,   KC_NO, A23,   A24 }, \
    { A30,   A31,   A32,   A33,   A34 }, \
    { A40,   A41,   A42,   A43,   A44 }, \
    { A50,   A51,   A52,   A53,   A54 }, \
    { A60,   A61,   A62,   A63,   A64 }, \
    { A70,   A71,   A72,   A73,   A74 }, \
    { A80,   A81,   A82,   A83,   A84 }, \
    { KC_NO, KC_NO, KC_NO, B03,   B04 }, \
    { KC_NO, KC_NO, KC_NO, B13,   B14 }, \
    { B20,   B21,   KC_NO, B23,   B24 }, \
    { B30,   B31,   B32,   B33,   B34 }, \
    { B40,   B41,   B42,   B43,   B44 }, \
    { B50,   B51,   B52,   B53,   B54 }, \
    { B60,   B61,   B62,   B63,   B64 }, \
    { B70,   B71,   B72,   B73,   B74 }, \
    { B80,   B81,   B82,   B83,   B84 }  \
}

#endif /* KEYBOARDS_ERGODOX_INFINITY_INFINITY_H_ */
