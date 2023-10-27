/* Copyright 2023 @Marek128b */

#include "quantum.h"

bool rgb_matrix_indicators_kb(void) {
    if (!rgb_matrix_indicators_user()) {
        return false;
    }
    if (host_keyboard_led_state().caps_lock) 
	{
        rgb_matrix_set_color(0, RGB_RED);
    }
	
	if (host_keyboard_led_state().num_lock) 
	{
        rgb_matrix_set_color(1, RGB_RED);
    }

	if (host_keyboard_led_state().scroll_lock) 
	{
        rgb_matrix_set_color(2, RGB_RED);
    }
	
	if (get_highest_layer(layer_state) == 1) 
	{
        rgb_matrix_set_color(3, RGB_CYAN);
    } 
	else if (get_highest_layer(layer_state) == 2) 
	{
        rgb_matrix_set_color(3, RGB_MAGENTA);
    } 
	else if (get_highest_layer(layer_state) == 3) 
	{
        rgb_matrix_set_color(3, RGB_YELLOW);
    } 
    return true;
}
