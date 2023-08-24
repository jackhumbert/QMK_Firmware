/*
 * (c) 2015 flabberast <s3+flabbergast@sdfeu.org>
 *
 * Based on the following work:
 *  - Guillaume Duc's raw hid example (MIT License)
 *    https://github.com/guiduc/usb-hid-chibios-example
 *  - PJRC Teensy examples (MIT License)
 *    https://www.pjrc.com/teensy/usb_keyboard.html
 *  - hasu's TMK keyboard code (GPL v2 and some code Modified BSD)
 *    https://github.com/tmk/tmk_keyboard/
 *  - ChibiOS demo code (Apache 2.0 License)
 *    http://www.chibios.org
 *
 * Since some GPL'd code is used, this work is licensed under
 * GPL v2 or later.
 */

#include <ch.h>
#include <hal.h>

#include "usb_main.h"

/* TMK includes */
#include "report.h"
#include "host.h"
#include "host_driver.h"
#include "keyboard.h"
#include "action.h"
#include "action_util.h"
#include "usb_device_state.h"
#include "mousekey.h"
#include "led.h"
#include "sendchar.h"
#include "debug.h"
#include "print.h"

#ifndef EARLY_INIT_PERFORM_BOOTLOADER_JUMP
// Change this to be TRUE once we've migrated keyboards to the new init system
// Remember to change docs/platformdev_chibios_earlyinit.md as well.
#    define EARLY_INIT_PERFORM_BOOTLOADER_JUMP FALSE
#endif

#ifdef SLEEP_LED_ENABLE
#    include "sleep_led.h"
#endif
#ifdef MIDI_ENABLE
#    include "qmk_midi.h"
#endif
#include "suspend.h"
#include "wait.h"

#define USB_GETSTATUS_REMOTE_WAKEUP_ENABLED (2U)

/* -------------------------
 *   TMK host driver defs
 * -------------------------
 */

/* declarations */
uint8_t keyboard_leds(void);
void    send_keyboard(report_keyboard_t *report);
void    send_mouse(report_mouse_t *report);
void    send_extra(report_extra_t *report);

/* host struct */
host_driver_t chibios_driver = {keyboard_leds, send_keyboard, send_mouse, send_extra};

#ifdef VIRTSER_ENABLE
void virtser_task(void);
#endif

#ifdef RAW_ENABLE
void raw_hid_task(void);
#endif

#ifdef CONSOLE_ENABLE
void console_task(void);
#endif
#ifdef MIDI_ENABLE
void midi_ep_task(void);
#endif

/* Early initialisation
 */
__attribute__((weak)) void early_hardware_init_pre(void) {
#if EARLY_INIT_PERFORM_BOOTLOADER_JUMP
    void enter_bootloader_mode_if_requested(void);
    enter_bootloader_mode_if_requested();
#endif // EARLY_INIT_PERFORM_BOOTLOADER_JUMP
}

__attribute__((weak)) void early_hardware_init_post(void) {}

__attribute__((weak)) void board_init(void) {}

// This overrides what's normally in ChibiOS board definitions
void __early_init(void) {
    early_hardware_init_pre();

    // This is the renamed equivalent of __early_init in the board.c file
    void __chibios_override___early_init(void);
    __chibios_override___early_init();

    early_hardware_init_post();
}

// This overrides what's normally in ChibiOS board definitions
void boardInit(void) {
    // This is the renamed equivalent of boardInit in the board.c file
    void __chibios_override_boardInit(void);
    __chibios_override_boardInit();

    board_init();
}

void protocol_setup(void) {
    usb_device_state_init();
}

static host_driver_t *driver = NULL;

void protocol_pre_init(void) {
    /* Init USB */
    usb_event_queue_init();
    init_usb_driver(&USB_DRIVER);

#ifdef MIDI_ENABLE
    setup_midi();
#endif

    /* Wait until USB is active */
    while (true) {
#if defined(WAIT_FOR_USB)
        if (USB_DRIVER.state == USB_ACTIVE) {
            driver = &chibios_driver;
            break;
        }
#else
        driver = &chibios_driver;
        break;
#endif
        wait_ms(50);
    }

    /* Do need to wait here!
     * Otherwise the next print might start a transfer on console EP
     * before the USB is completely ready, which sometimes causes
     * HardFaults.
     */
    wait_ms(50);

    print("USB configured.\n");
}

void protocol_post_init(void) {
    host_set_driver(driver);
}

void protocol_pre_task(void) {
    usb_event_queue_task();
#if !defined(NO_USB_STARTUP_CHECK)
    if (USB_DRIVER.state == USB_SUSPENDED) {
        dprintln("suspending keyboard");
        while (USB_DRIVER.state == USB_SUSPENDED) {
            suspend_power_down();
            if ((USB_DRIVER.status & USB_GETSTATUS_REMOTE_WAKEUP_ENABLED) && suspend_wakeup_condition()) {
                usbWakeupHost(&USB_DRIVER);
                restart_usb_driver(&USB_DRIVER);
#    if USB_SUSPEND_WAKEUP_DELAY > 0
                /* Some hubs, kvm switches, and monitors do weird things, with
                 * USB device state bouncing around wildly on wakeup, yielding
                 * race conditions that can corrupt the keyboard state.
                 *
                 * Pause for a while to let things settle... */
                wait_ms(USB_SUSPEND_WAKEUP_DELAY);
#    endif
            }
        }
        /* Woken up */
        // variables has been already cleared by the wakeup hook
        send_keyboard_report();
#    ifdef MOUSEKEY_ENABLE
        mousekey_send();
#    endif /* MOUSEKEY_ENABLE */
    }
#endif
}

void protocol_post_task(void) {
#ifdef CONSOLE_ENABLE
    console_task();
#endif
#ifdef MIDI_ENABLE
    midi_ep_task();
#endif
#ifdef VIRTSER_ENABLE
    virtser_task();
#endif
#ifdef RAW_ENABLE
    raw_hid_task();
#endif
}
