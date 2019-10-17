# Build Options
#   change to "no" to disable the options, or define them in the Makefile in
#   the appropriate keymap folder that will get included automatically
#
CONSOLE_ENABLE = no
TAP_DANCE_ENABLE = yes
NKRO_ENABLE = yes
BOOTMAGIC_ENABLE = lite      # Virtual DIP switch configuration(+1000)

ifeq ($(strip $(KEYBOARD)), crkbd/rev1)
RGB_MATRIX_ENABLE = WS2812
EXTRAFLAGS += -flto
BOOTLOADER = qmk-dfu
OLED_DRIVER_ENABLE = yes
BOOTMAGIC_ENABLE = no
endif

ifeq ($(strip $(KEYBOARD)), lazydesigners/dimple)
MOUSEKEY_ENABLE = no        # Mouse keys(+4700)
EXTRAKEY_ENABLE = yes        # Audio control and System control(+450)
BACKLIGHT_ENABLE = yes       # Enable keyboard backlight functionality on B7 by default
RGBLIGHT_ENABLE = yes        # Enable keyboard RGB underglow
# RGB_MATRIX_ENABLE = WS2812
endif


SRC += tominabox1.c
