# Build Options
#   change to "no" to disable the options, or define them in the Makefile in
#   the appropriate keymap folder that will get included automatically
#
BOOTMAGIC_ENABLE = no       # Virtual DIP switch configuration
MOUSEKEY_ENABLE = yes       # Mouse keys
EXTRAKEY_ENABLE = yes       # Audio control and System control
CONSOLE_ENABLE = no         # Console for debug
COMMAND_ENABLE = no         # Commands for debug and configuration
NKRO_ENABLE = no            # Nkey Rollover - if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
MIDI_ENABLE = no            # MIDI controls
AUDIO_ENABLE = no           # Audio output on port C6
UNICODE_ENABLE = yes        # Unicode
BLUETOOTH_ENABLE = no       # Enable Bluetooth with the Adafruit EZ-Key HID
RGBLIGHT_ENABLE = no        # Enable WS2812 RGB underlight. 
SWAP_HANDS_ENABLE = no      # Enable one-hand typing
OLED_DRIVER_ENABLE= yes     # OLED display
ENCODER_ENABLE = yes        # Encoder enable
TAP_DANCE_ENABLE = yes      # Tap Dance
LEADER_ENABLE = yes         # Leader support
LTO_ENABLE = yes
DYNAMIC_MACRO_ENABLE = yes  # Dynamic Macros
WPM_ENABLE = yes           # Enable WPM calc and transport

# Do not enable SLEEP_LED_ENABLE. it uses the same timer as BACKLIGHT_ENABLE
SLEEP_LED_ENABLE = no    # Breathing sleep LED during USB suspend

# If you want to change the display of OLED, you need to change here
SRC +=  ./lib/layer_state_reader.c \
        # ./lib/logo_reader.c \
        # ./lib/mode_icon_reader.c \
        # ./lib/keylogger.c \
        # ./lib/rgb_state_reader.c \
        # ./lib/timelogger.c \
        # ./lib/host_led_state_reader.c \
