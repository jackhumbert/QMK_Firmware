# MCU name
MCU = atmega32u2

# Bootloader selection
BOOTLOADER = atmel-dfu

# Build Options
#   change yes to no to disable
#
BOOTMAGIC_ENABLE  = yes # Virtual DIP switch configuration
MOUSEKEY_ENABLE   = yes # Mouse keys
EXTRAKEY_ENABLE   = yes # Audio control and System control
CONSOLE_ENABLE    = no  # Console for debug
COMMAND_ENABLE    = yes # Commands for debug and configuration
SLEEP_LED_ENABLE  = no  # Breathing sleep LED during USB suspend
NKRO_ENABLE       = yes # USB Nkey Rollover - if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
BACKLIGHT_ENABLE  = no  # Enable keyboard backlight functionality
AUDIO_ENABLE      = no  # Audio output on port C6
RGBLIGHT_ENABLE   = no  # Enable keyboard RGB underglow
UNICODE_ENABLE    = no  # Unicode
BLUETOOTH_ENABLE  = no  # Enable Bluetooth with the Adafruit EZ-Key HID
