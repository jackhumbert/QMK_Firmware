# MCU name
MCU = atmega32u4

# Bootloader selection
#   Teensy       halfkay
#   Pro Micro    caterina
#   Atmel DFU    atmel-dfu
#   LUFA DFU     lufa-dfu
#   QMK DFU      qmk-dfu
#   ATmega32A    bootloadHID
#   ATmega328P   USBasp
BOOTLOADER = atmel-dfu

# Build Options
#   change yes to no to disable
#
BOOTMAGIC_ENABLE  = no      # Virtual DIP switch configuration
MOUSEKEY_ENABLE   = no      # Mouse keys
EXTRAKEY_ENABLE   = yes     # Audio control and System control
CONSOLE_ENABLE    = no      # Console for debug
COMMAND_ENABLE    = no      # Commands for debug and configuration
# Do not enable SLEEP_LED_ENABLE. it uses the same timer as BACKLIGHT_ENABLE
SLEEP_LED_ENABLE  = no      # Breathing sleep LED during USB suspend
BACKLIGHT_ENABLE  = yes     # Enable keyboard backlight functionality
RGBLIGHT_ENABLE   = no      # Enable keyboard RGB underglow
MIDI_ENABLE       = no      # MIDI support
BLUETOOTH_ENABLE  = no      # Enable Bluetooth with the Adafruit EZ-Key HID
AUDIO_ENABLE      = no      # Audio output (needs a pin configured in config.h, see docs/feature_audio.md)
FAUXCLICKY_ENABLE = no      # Use buzzer to emulate clicky switches
HD44780_ENABLE    = no      # Enable support for HD44780 based LCDs
UNICODE_ENABLE    = no      # Unicode

LAYOUTS = ortho_5x4 ortho_6x4 numpad_5x4 numpad_6x4
