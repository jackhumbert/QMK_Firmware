LTO_ENABLE = yes

MOUSEKEY_ENABLE = yes
EXTRAKEY_ENABLE = yes
NKRO_ENABLE = yes
RGBLIGHT_ENABLE = yes

BOOTMAGIC_ENABLE = no       # Enable Bootmagic Lite
COMMAND_ENABLE = no
AUDIO_ENABLE = no
ENCODER_ENABLE = no
DIP_SWITCH_ENABLE = no

ifeq ($(strip $(AUDIO_ENABLE)), yes)
    SRC += muse.c
endif