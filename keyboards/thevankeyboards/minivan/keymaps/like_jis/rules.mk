# Build Options
#   change to "no" to disable the options, or define them in the Makefile in
#   the appropriate keymap folder that will get included automatically
#
BOOTMAGIC_ENABLE = no       # Virtual DIP switch configuration(+1000)
MOUSEKEY_ENABLE = yes       # Mouse keys(+4700)
EXTRAKEY_ENABLE = no       # Audio control and System control(+450)
CONSOLE_ENABLE = no         # Console for debug(+400)
COMMAND_ENABLE = no        # Commands for debug and configuration
NKRO_ENABLE = yes           # Nkey Rollover - if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
MIDI_ENABLE = no            # MIDI controls
AUDIO_ENABLE = no           # Audio output (needs a pin configured in config.h, see docs/feature_audio.md)
UNICODE_ENABLE = no         # Unicode
BLUETOOTH_ENABLE = no       # Enable Bluetooth with the Adafruit EZ-Key HID
RGBLIGHT_ENABLE = yes        # Enable WS2812 RGB underlight.
SLEEP_LED_ENABLE = no       # Breathing sleep LED during USB suspend
TAP_DANCE_ENABLE = yes

LED_ANIMATIONS = yes        # LED animations

ifeq ($(strip $(LED_ANIMATIONS)), yes)
    # OPT_DEFS += -DRGBLIGHT_ANIMATIONS
    OPT_DEFS += -DLED_ANIMATIONS
endif
