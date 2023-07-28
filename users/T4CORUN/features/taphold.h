#pragma once
#include "t4corun.h"

void double_tap(uint16_t keycode);
void double_tap_space(uint16_t keycode);
void double_parens_left(uint16_t left, uint16_t right);
void triple_tap(uint16_t keycode);
bool process_tap_hold_key(keyrecord_t* record, uint16_t keycode);