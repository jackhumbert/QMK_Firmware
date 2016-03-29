BLUEFRUIT_DIR = protocol/bluefruit
PJRC_DIR = protocol/pjrc

SRC +=	$(BLUEFRUIT_DIR)/main.c \
	$(BLUEFRUIT_DIR)/bluefruit.c \
	serial_uart.c \
	$(PJRC_DIR)/pjrc.c \
	$(PJRC_DIR)/usb_keyboard.c \
	$(PJRC_DIR)/usb_debug.c \
	$(PJRC_DIR)/usb.c

# Option modules
ifeq ($(strip $(MOUSEKEY_ENABLE)), yes)
    SRC += $(PJRC_DIR)/usb_mouse.c
else ifeq ($(strip $(PS2_MOUSE_ENABLE)), yes)
    SRC += $(PJRC_DIR)/usb_mouse.c
endif

ifeq ($(strip $(EXTRAKEY_ENABLE)), yes)
    SRC += $(PJRC_DIR)/usb_extra.c
endif

# Search Path
VPATH += $(TMK_DIR)/$(BLUEFRUIT_DIR)
#VPATH += $(TMK_DIR)/$(BLUEFRUIT_DIR)/usb_debug_only
VPATH += $(TMK_DIR)/$(PJRC_DIR)

OPT_DEFS += -DPROTOCOL_BLUEFRUIT
OPT_DEFS += -DPROTOCOL_PJRC
