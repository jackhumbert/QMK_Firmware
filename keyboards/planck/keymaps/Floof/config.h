#pragma once
#include <stdlib.h>
#include <stdio.h>

#define CAKE_SSLJ B__NOTE(_D6), M__NOTE(_C6, 36), M__NOTE(_D6, 36), M__NOTE(_C6, 36), M__NOTE(_D6, 36), W__NOTE(_REST), M__NOTE(_C6, 36), M__NOTE(_D6, 36), M__NOTE(_C6, 36), M__NOTE(_A5, 36), B__NOTE(_F5), B__NOTE(_G5), B__NOTE(_A5),
int fuckboi = rand() % 2 + 1;

#ifdef AUDIO_ENABLE
    #define STARTUP_SONG SONG(CAKE_SSLJ)
    #define DEFAULT_LAYER_SONGS { SONG(QWERTY_SOUND) }
#endif

/*
 * MIDI options
 */

/* Prevent use of disabled MIDI features in the keymap */
//#define MIDI_ENABLE_STRICT 1

/* enable basic MIDI features:
   - MIDI notes can be sent when in Music mode is on
*/

#define MIDI_BASIC

/* enable advanced MIDI features:
   - MIDI notes can be added to the keymap
   - Octave shift and transpose
   - Virtual sustain, portamento, and modulation wheel
   - etc.
*/
//#define MIDI_ADVANCED

/* override number of MIDI tone keycodes (each octave adds 12 keycodes and allocates 12 bytes) */
//#define MIDI_TONE_KEYCODE_OCTAVES 2

// Most tactile encoders have detents every 6 stages
#define ENCODER_RESOLUTION 6
