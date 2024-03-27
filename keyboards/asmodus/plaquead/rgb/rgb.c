/*
Copyright 2024 Asmodus

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

#include "quantum.h"

#ifdef RGB_MATRIX_ENABLE
led_config_t g_led_config = { {
//  { 0        , 1          , 2          , 3          , 4          , 5          , 6          , 7          , 8          , 9          , 10         , 11         , 12         , NO_LED     , 13         , 14         , 15        },
//  { 16       , 17         , 18         , 19         , 20         , 21         , 22         , 23         , 24         , 25         , 26         , 27         , 28         , 29         , 30         , 31         , 32        },
//  { 33       , 34         , 35         , 36         , 37         , 38         , 39         , 40         , 41         , 42         , 43         , 44         , 45         , 46         , 47         , 48         , 49        },
//  { 50       , 51         , 52         , 53         , 54         , 55         , 56         , 57         , 58         , 59         , 60         , 61         , 62         , NO_LED     , NO_LED     , NO_LED     , NO_LED    },
//  { 63       , NO_LED     , 64         , 65         , 66         , 67         , 68         , 69         , 70         , 71         , 72         , 73         , 74         , NO_LED     , NO_LED     , 75         , NO_LED    },
//  { 76       , 77         , 78         , NO_LED     , NO_LED     , NO_LED     , 79         , NO_LED     , NO_LED     , 80         , 81         , 82         , 83         , NO_LED     , 84         , 85         , 86        }
//
    { 17       , 16         , 15         , 14         , 13         , 12         , 10         , 9          , 8          , 7          , 6          , 5          , 4          , 3          , 2          , 1          , 0         },
    { 18       , 19         , 20         , 21         , 22         , 23         , 24         , 25         , 26         , 27         , 28         , 29         , 30         , 33         , 34         , 35         , 36        },
    { 53       , 52         , 51         , 50         , 49         , 48         , 47         , 46         , 45         , 44         , 43         , 42         , 41         , 40         , 39         , 38         , 37        },
    { 54       , 55         , 56         , 57         , 58         , 59         , 60         , 61         , 62         , 63         , 64         , 65         , 31         , 66         , NO_LED     , NO_LED     , NO_LED    },
    { 82       , 80         , 79         , 78         , 77         , 76         , 75         , 74         , 73         , 72         , 71         , 70         , 69         , 67         , NO_LED     , 93         , NO_LED    },
    { 83       , 84         , 85         , NO_LED     , NO_LED     , NO_LED     , 86         , NO_LED     , NO_LED     , NO_LED     , 88         , 89         , 90         , 91         , 92         , 94         , 95        }
},{
// "Fine-tuned" complex configuration
{224,0  }, {211,0  }, {198,0  }, {182,0  }, {166,0  }, {153,0  }, {148,0  }, {140,0  }, {127,0  }, {110,0  }, { 97,0  }, { 84,0  }, { 71,0  }, { 55,0  },            { 42,0  }, { 29,0  }, { 16,0  }, {  0,0  }, 
{  0,15 }, { 13,15 }, { 26,15 }, { 39,15 }, { 52,15 }, { 65,15 }, { 78,15 }, { 91,15 }, {104,15 }, {117,15 }, {130,15 }, {143,15 }, {156,15 }, {175,15 }, {169,15 }, {182,15 }, {198,15 }, {211,15 }, {224,15 },
{224,27 }, {211,27 }, {198,27 }, {179,27 }, {162,27 }, {149,27 }, {136,27 }, {123,27 }, {110,27 }, { 97,27 }, { 84,27 }, { 71,27 }, { 58,27 }, { 45,27 },                       { 32,27 }, { 19,27 }, {  3,27 }, 
{  5,40 }, { 23,40 }, { 36,40 }, { 49,40 }, { 62,40 }, { 75,40 }, { 88,40 }, {101,40 }, {114,40 }, {127,40 }, {140,40 }, {153,40 }, {174,40 }, 
{182,52 }, {170,52 }, {164,52 }, {146,52 }, {133,52 }, {120,52 }, {107,52 }, { 94,52 }, { 81,52 }, { 68,52 }, { 55,52 }, { 42,52 }, { 29,52 }, { 16,52 }, {  8,52 }, {  2,52 }, 
{  5,64 }, { 21,64 }, { 37,64 },                                  { 83,64 }, { 91,64 },                       {131,64 }, {151,64 }, {167,64 }, {183,64 },            {198,64 }, {211,52 }, {211,64 }, {224,64 }, 

{224,57 }, {224,45 }, {224,32 }, {224,20 }, 
{224,5  }, {209,5  }, {194,5  }, {179,5  }, {164,5  }, {149,5  }, {134,5  }, {119,5  }, {104,5  }, {89,5  }, { 74,5  }, { 59,5  }, { 44,5  }, { 29,5  }, { 14,5  }, 
{  0,5  }, {  0,20 }, {  0,32 }, {  0,45 }, 
{  0,57 }, { 14,57 }, { 29,57 }, { 44,57 }, { 59,57 }, { 74,57 }, { 89,57 }, {104,57 }, {119,57 }, {134,57 }, {149,57 }, {164,57 }, {179,57 }, {194,57 }, {209,57 },



// "Stock" simple configuration
//  { 224,   0}, { 210,   0}, { 196,   0}, { 182,   0}, { 168,   0}, { 154,   0}, { 140,   0}, { 126,   0}, { 112,   0}, {  98,   0}, {  84,   0}, {  70,   0}, {  56,   0},              {  28,   0}, {  14,   0}, {   0,   0},
//  {   0,  45}, {  14,  45}, {  28,  45}, {  42,  45}, {  56,  45}, {  70,  45}, {  84,  45}, {  98,  45}, { 112,  45}, { 126,  45}, { 140,  45}, { 154,  45}, { 168,  45}, { 182,  45}, { 196,  45}, { 210,  45}, { 224,  45},
//  { 224,  90}, { 210,  90}, { 196,  90}, { 182,  90}, { 168,  90}, { 154,  90}, { 140,  90}, { 126,  90}, { 112,  90}, {  98,  90}, {  84,  90}, {  70,  90}, {  56,  90}, {  42,  90}, {  28,  90}, {  14,  90}, {   0,  90},
//  {   0, 135}, {  14, 135}, {  28, 135}, {  42, 135}, {  56, 135}, {  70, 135}, {  84, 135}, {  98, 135}, { 112, 135}, { 126, 135}, { 140, 135}, { 154, 135}, { 168, 135},
//  { 224, 180},              { 196, 180}, { 182, 180}, { 168, 180}, { 154, 180}, { 140, 180}, { 126, 180}, { 112, 180}, {  98, 180}, {  84, 180}, {  70, 180}, {  56, 180},                           {  14, 180},
//  {   0, 225}, {  14, 225}, {  28, 225},                                        {  84, 225},                           { 126, 225}, { 140, 225}, { 154, 225}, { 168, 225},              { 196,  45}, { 210,  45}, { 224,  90}
}, {
    4          , 4          , 4          , 4          , 4          , 4          , 4          , 4          , 4          , 4          , 4          , 4          , 4          , 4          , 4          , 4          , 4          , 4          ,
    4          , 4          , 4          , 4          , 4          , 4          , 4          , 4          , 4          , 4          , 4          , 4          , 4          , 1          , 1          , 1          , 4          , 4          , 4          ,
    4          , 4          , 4          , 4          , 4          , 4          , 4          , 4          , 4          , 4          , 4          , 4          , 4          , 4          , 4          , 4          , 4          ,
    1          , 4          , 4          , 4          , 4          , 4          , 4          , 4          , 4          , 4          , 4          , 4          , 1          ,
    4          , 1          , 1          , 4          , 4          , 4          , 4          , 4          , 4          , 4          , 4          , 4          , 4          , 1          , 1          , 4          ,
    1          , 1          , 1          ,                                        4          , 4                       , 1          , 1          , 1          , 1          , 1          , 1          , 1          , 1          ,


    2          , 2          , 2          , 2          , 2          , 2          , 2          , 2          , 2          , 2          , 2          , 2          , 2          , 2          , 2          , 2          , 2          , 2          , 2           ,
    2          , 2          , 2          , 2          , 2          , 2          , 2          , 2          , 2          , 2          , 2          , 2          , 2          , 2          , 2          , 2          , 2          , 2          , 2                 

} };
#endif

#if defined(RGB_MATRIX_ENABLE) && defined(CAPS_LOCK_LED_INDEX) && defined(SCROLL_LOCK_LED_INDEX)

#if !defined(CAPS_LOCK_MAX_BRIGHTNESS)
    #define CAPS_LOCK_MAX_BRIGHTNESS RGB_MATRIX_MAXIMUM_BRIGHTNESS
#endif

#if !defined(CAPS_LOCK_VAL_STEP)
    #define CAPS_LOCK_VAL_STEP RGB_MATRIX_VAL_STEP
#endif

#if !defined(SCROLL_LOCK_MAX_BRIGHTNESS)
    #define SCROLL_LOCK_MAX_BRIGHTNESS RGB_MATRIX_MAXIMUM_BRIGHTNESS
#endif

#if !defined(SCROLL_LOCK_VAL_STEP)
    #define SCROLL_LOCK_VAL_STEP RGB_MATRIX_VAL_STEP
#endif


bool rgb_matrix_indicators_user(void) {
    if (host_keyboard_led_state().caps_lock) {
        uint8_t b = rgb_matrix_get_val();
        if (b < CAPS_LOCK_VAL_STEP) {
            b = CAPS_LOCK_VAL_STEP;
        } else if (b < (CAPS_LOCK_MAX_BRIGHTNESS - CAPS_LOCK_VAL_STEP)) {
            b += CAPS_LOCK_VAL_STEP;  // one step more than current brightness
        } else {
            b = CAPS_LOCK_MAX_BRIGHTNESS;
        }
        rgb_matrix_set_color(CAPS_LOCK_LED_INDEX, b, b, b);  // white, with the adjusted brightness
    }
        if (host_keyboard_led_state().scroll_lock) {
        uint8_t b = rgb_matrix_get_val();
        if (b < SCROLL_LOCK_VAL_STEP) {
            b = SCROLL_LOCK_VAL_STEP;
        } else if (b < (SCROLL_LOCK_MAX_BRIGHTNESS - SCROLL_LOCK_VAL_STEP)) {
            b += SCROLL_LOCK_VAL_STEP;  // one step more than current brightness
        } else {
            b = SCROLL_LOCK_MAX_BRIGHTNESS;
        }
        rgb_matrix_set_color(SCROLL_LOCK_LED_INDEX, b, b, b);  // white, with the adjusted brightness
    }
    return false;
}

#endif
