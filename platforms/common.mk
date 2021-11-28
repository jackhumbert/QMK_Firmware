PLATFORM_COMMON_DIR = $(PLATFORM_PATH)/$(PLATFORM_KEY)

TMK_COMMON_SRC +=	\
	$(PLATFORM_COMMON_DIR)/platform.c \
	$(PLATFORM_COMMON_DIR)/suspend.c \
	$(PLATFORM_COMMON_DIR)/timer.c \
	$(PLATFORM_COMMON_DIR)/bootloader.c \

# Search Path
VPATH += $(PLATFORM_PATH)
VPATH += $(PLATFORM_PATH)/$(PLATFORM_KEY)
VPATH += $(PLATFORM_PATH)/$(PLATFORM_KEY)/$(DRIVER_DIR)
