#pragma once

// Override SpaceCadet Settings
#undef LSPO_KEY
#undef RSPC_KEY
#define KC_LSPO_KEYS SC_KEY(KC_LSFT, KC_LSFT, KC_8) // Nordic Left SpaceCadet
#define KC_RSPC_KEYS SC_KEY(KC_RSFT, KC_RSFT, KC_9) // Nordic Right SpaceCadet

// Audio
#ifdef AUDIO_ENABLE
    #define STARTUP_SONG SONG(COIN_SOUND)

    #define DEFAULT_LAYER_SONGS { SONG(QWERTY_SOUND), \
                                  SONG(COLEMAK_SOUND), \
                                  SONG(DVORAK_SOUND) \
                                }
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

// Most tactile encoders have detents every 4 stages
#define ENCODER_RESOLUTION 4
