# MCU name
MCU = STM32F411

# Bootloader selection
BOOTLOADER = tinyuf2

KEYBOARD_SHARED_EP = yes
CONSOLE_ENABLE     = yes
MOUSE_SHARED_EP    = yes

EEPROM_DRIVER = spi
WS2812_DRIVER = pwm
SERIAL_DRIVER = usart
AUDIO_DRIVER  = pwm_hardware

DEBOUNCE_TYPE = asym_eager_defer_pk
