# Make some noise
ifeq ($(strip $(AUDIO_ENABLE)), yes)
    SRC += muse.c
endif


