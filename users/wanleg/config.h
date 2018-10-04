#ifndef USERSPACE_CONFIG_H
#define USERSPACE_CONFIG_H

//TAPPING_TERM
#if (defined(TAP_DANCE_ENABLE) && defined(KEYBOARD_gherkin))
//tapping term short (<100): lingering taps may not register, but modifiers register easier
//tapping term long (>200): lingering taps register easily, modifiers don't register as easily (e.g. shift doesn't want to engage.)
#define TAPPING_TERM 180
#else
#define TAPPING_TERM 110
#endif

//Mousekey Settings
#ifdef MOUSEKEY_ENABLE
#define MOUSEKEY_INTERVAL 16
#define MOUSEKEY_DELAY 0
#define MOUSEKEY_TIME_TO_MAX 60
#define MOUSEKEY_MAX_SPEED 7
#define MOUSEKEY_WHEEL_DELAY 0
#endif

// Disable action_get_macro and fn_actions, since we don't use these
// and it saves on space in the firmware.
#ifndef NO_DEBUG
#define NO_DEBUG
#endif // !NO_DEBUG
#if !defined(NO_PRINT) && !defined(CONSOLE_ENABLE)
#define NO_PRINT
#endif // !NO_PRINT
#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION
#define NO_ACTION_ONESHOT

// Disable mod tap interrrupt
#ifndef IGNORE_MOD_TAP_INTERRUPT 
#define IGNORE_MOD_TAP_INTERRUPT 
#endif // !mod tap interrrupt

#endif // !USERSPACE_CONFIG_H
