/*
Copyright 2012,2013 Jun Wako <wakojun@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include <stdint.h>
#include <stdbool.h>
#include "keyboard.h"
#include "keycode.h"
#include "action_code.h"
#include "action_macro.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Disable macro and function features when LTO is enabled, since they break */
#ifdef LTO_ENABLE
#    ifndef NO_ACTION_MACRO
#        define NO_ACTION_MACRO
#    endif
#    ifndef NO_ACTION_FUNCTION
#        define NO_ACTION_FUNCTION
#    endif
#endif

#ifndef TAP_CODE_DELAY
#    define TAP_CODE_DELAY 0
#endif
#ifndef TAP_HOLD_CAPS_DELAY
#    define TAP_HOLD_CAPS_DELAY 80
#endif

/* tapping count and state */
typedef struct {
    bool    interrupted : 1;
    bool    reserved2 : 1;
    bool    reserved1 : 1;
    bool    reserved0 : 1;
    uint8_t count : 4;
} tap_t;

/* Key event container for recording */
typedef struct {
    keyevent_t event;
#ifndef NO_ACTION_TAPPING
    tap_t tap;
#endif
#ifdef COMBO_ENABLE
    uint16_t keycode;
#endif
} keyrecord_t;

/* Execute action per keyevent */
void action_exec(keyevent_t event);

/* action for key */
action_t action_for_key(uint8_t layer, keypos_t key);
action_t action_for_keycode(uint16_t keycode);

/* macro */
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt);

/* user defined special function */
void action_function(keyrecord_t *record, uint8_t id, uint8_t opt);

/* keyboard-specific key event (pre)processing */
bool process_record_quantum(keyrecord_t *record);

/* Utilities for actions.  */
#if !defined(NO_ACTION_LAYER) && !defined(STRICT_LAYER_RELEASE)
extern bool disable_action_cache;
#endif

void process_record_nocache(keyrecord_t *record);
void process_record(keyrecord_t *record);
void process_record_handler(keyrecord_t *record);
void post_process_record_quantum(keyrecord_t *record);
void process_action(keyrecord_t *record, action_t action);
void register_code(uint8_t code);
void unregister_code(uint8_t code);
void tap_code(uint8_t code);
void tap_code_delay(uint8_t code, uint16_t delay);
void register_mods(uint8_t mods);
void unregister_mods(uint8_t mods);
void register_weak_mods(uint8_t mods);
void unregister_weak_mods(uint8_t mods);
// void set_mods(uint8_t mods);
void clear_keyboard(void);
void clear_keyboard_but_mods(void);
void clear_keyboard_but_mods_and_keys(void);
void layer_switch(uint8_t new_layer);
bool is_tap_key(keypos_t key);
bool is_tap_record(keyrecord_t *record);
bool is_tap_action(action_t action);

#ifndef NO_ACTION_TAPPING
void process_record_tap_hint(keyrecord_t *record);
#endif

/* debug */
void debug_event(keyevent_t event);
void debug_record(keyrecord_t record);
void debug_action(action_t action);

#ifdef __cplusplus
}
#endif
