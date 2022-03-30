/*
 Copyright 2022 Álvaro "Gondolindrim" Volpato <alvaro.volpato@usp.br>

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

#include "delta.h"

void board_init(void) {
    setPinInput(B9);
    setPinInput(B10);
}

led_config_t g_led_config = { {
//	{ 0        , 1          , 2          , 3          , 4          , 5          , 6          , 7          , 8          , 9          , 10         , 11         , 12         , NO_LED     , 13         , 14         , 15        },
//	{ 16       , 17         , 18         , 19         , 20         , 21         , 22         , 23         , 24         , 25         , 26         , 27         , 28         , 29         , 30         , 31         , 32        },
//	{ 33       , 34         , 35         , 36         , 37         , 38         , 39         , 40         , 41         , 42         , 43         , 44         , 45         , 46         , 47         , 48         , 49        },
//	{ 50       , 51         , 52         , 53         , 54         , 55         , 56         , 57         , 58         , 59         , 60         , 61         , 62         , NO_LED     , NO_LED     , NO_LED     , NO_LED    },
//	{ 63       , NO_LED     , 64         , 65         , 66         , 67         , 68         , 69         , 70         , 71         , 72         , 73         , 74         , NO_LED     , NO_LED     , 75         , NO_LED    },
//	{ 76       , 77         , 78         , NO_LED     , NO_LED     , NO_LED     , 79         , NO_LED     , NO_LED     , 80         , 81         , 82         , 83         , NO_LED     , 84         , 85         , 86        }
//
	{ 15       , 14         , 13         , 12         , 11         , 10         , 9          , 8          , 7          , 6          , 5          , 4          , 3          , NO_LED     , 2          , 1          , 0         },
	{ 16       , 17         , 18         , 19         , 20         , 21         , 22         , 23         , 24         , 25         , 26         , 27         , 28         , 29         , 30         , 31         , 32        },
	{ 49       , 48         , 47         , 46         , 45         , 44         , 43         , 42         , 41         , 40         , 39         , 38         , 37         , 36         , 35         , 34         , 3         },
	{ 50       , 51         , 52         , 53         , 54         , 55         , 56         , 57         , 58         , 59         , 60         , 61         , 62         , NO_LED     , NO_LED     , NO_LED     , NO_LED    },
	{ 75       , NO_LED     , 74         , 73         , 72         , 71         , 70         , 69         , 68         , 67         , 66         , 65         , 64         , NO_LED     , NO_LED     , 63         , NO_LED    },
	{ 76       , 77         , 78         , NO_LED     , NO_LED     , NO_LED     , 79         , NO_LED     , NO_LED     , 80         , 81         , 82         , 83         , NO_LED     , 84         , 85         , 86        }
},{
	{ 224,   0}, { 210,   0}, { 196,   0}, { 182,   0}, { 168,   0}, { 154,   0}, { 140,   0}, { 126,   0}, { 112,   0}, {  98,   0}, {  84,   0}, {  70,   0}, {  56,   0},              {  28,   0}, {  14,   0}, {   0,   0},
	{   0,  45}, {  14,  45}, {  28,  45}, {  42,  45}, {  56,  45}, {  70,  45}, {  84,  45}, {  98,  45}, { 112,  45}, { 126,  45}, { 140,  45}, { 154,  45}, { 168,  45}, { 182,  45}, { 196,  45}, { 210,  45}, { 224,  45},
	{ 220,  90}, { 203,  90}, { 189,  90}, { 175,  90}, { 161,  90}, { 147,  90}, { 133,  90}, { 119,  90}, { 105,  90}, {  91,  90}, {  77,  90}, {  63,  90}, {  48,  90}, {  35,  90}, {  28,  90}, {  14,  90}, {   0,  90},
	{   3, 135}, {  35, 135}, {  49, 135}, {  63, 135}, {  77, 135}, {  91, 135}, { 105, 135}, { 119, 135}, { 133, 135}, { 147, 135}, { 161, 135}, { 175, 135}, { 189, 135},
	{ 224, 180},              { 196, 180}, { 182, 180}, { 168, 180}, { 154, 180}, { 140, 180}, { 126, 180}, { 112, 180}, {  98, 180}, {  84, 180}, {  70, 180}, {  56, 180},                           {  14, 180},
	{   0, 225}, {  14, 225}, {  28, 225},                                        {  84, 225},                           { 126, 225}, { 140, 225}, { 154, 225}, { 168, 225},              { 196,  45}, { 210,  45}, { 224,  90}
}, {
	1          , 4          , 4          , 4          , 4          , 4          , 4          , 4          , 4          , 4          , 4          , 4          , 4          ,              4          , 4          , 4          ,
	4          , 4          , 4          , 4          , 4          , 4          , 4          , 4          , 4          , 4          , 4          , 4          , 4          , 4          , 4          , 4          , 4          , 
	4          , 4          , 4          , 4          , 4          , 4          , 4          , 4          , 4          , 4          , 4          , 4          , 4          , 4          , 4          , 4          , 4          ,
	4          , 4          , 4          , 4          , 4          , 4          , 4          , 4          , 4          , 4          , 4          , 4          , 1          ,
	1                       , 4          , 4          , 4          , 4          , 4          , 4          , 4          , 4          , 4          , 4          , 1                                    , 1          ,
	1          , 1          , 1          ,                                        4          ,                           1          , 1          , 1          , 1                       , 1          , 1          , 1          
} };
