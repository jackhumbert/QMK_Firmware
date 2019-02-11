SRC += konstantin.c
ifneq (,$(filter yes,$(RGBLIGHT_ENABLE) $(RGB_MATRIX_ENABLE)))  # if either is yes
  SRC += rgb.c
endif
ifeq ($(strip $(TAP_DANCE_ENABLE)), yes)
  SRC += tap_dance.c
endif

EXTRAFLAGS += -flto
