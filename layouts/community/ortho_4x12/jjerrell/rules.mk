ifeq ($(strip $(AUDIO_ENABLE)), yes)
    SRC += muse.c
endif

BOOTMAGIC_ENABLE = yes      # Enable Bootmagic Lite
MOUSEKEY_ENABLE = no
EXTRAKEY_ENABLE = yes
TAP_DANCE_ENABLE = no
SPACE_CADET_ENABLE = no
NKRO_ENABLE = no
