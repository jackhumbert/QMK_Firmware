ifeq ($(strip $(AUDIO_ENABLE)), yes)
    SRC += muse.c
endif

AUDIO_ENABLE     = yes
BACKLIGHT_ENABLE = no
BLUETOOTH_ENABLE = no 
BOOTMAGIC_ENABLE = no       # Enable Bootmagic Lite
COMBO_ENABLE     = no
COMMAND_ENABLE   = no
CONSOLE_ENABLE   = no
EXTRAKEY_ENABLE  = yes
LEADER_ENABLE    = yes
MIDI_ENABLE      = no
MOUSEKEY_ENABLE  = yes 
NKRO_ENABLE      = yes # nkey rollover
RGBLIGHT_ENABLE  = no
SLEEP_LED_ENABLE = no
STENO_ENABLE     = yes
TAP_DANCE_ENABLE = yes
UNICODE_ENABLE   = yes
