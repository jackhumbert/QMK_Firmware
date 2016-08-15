#include "process_unicode.h"

static uint8_t input_mode;

uint16_t hex_to_keycode(uint8_t hex)
{
  if (hex == 0x0) {
    return KC_0;
  } else if (hex < 0xA) {
    return KC_1 + (hex - 0x1);
  } else {
    return KC_A + (hex - 0xA);
  }
}

void set_unicode_input_mode(uint8_t os_target)
{
  input_mode = os_target;
}

void unicode_input_start (void) {
  switch(input_mode) {
  case UC_OSX:
    register_code(KC_LALT);
    break;
  case UC_LNX:
    register_code(KC_LCTL);
    register_code(KC_LSFT);
    register_code(KC_U);
    unregister_code(KC_U);
    unregister_code(KC_LSFT);
    unregister_code(KC_LCTL);
    break;
  case UC_WIN:
    register_code(KC_LALT);
    register_code(KC_PPLS);
    unregister_code(KC_PPLS);
    break;
  }
}

void unicode_input_finish (void) {
  switch(input_mode) {
  case UC_OSX:
  case UC_WIN:
    unregister_code(KC_LALT);
    break;
  case UC_LNX:
    register_code(KC_SPC);
    unregister_code(KC_SPC);
    break;
  }
}

void register_hex(uint16_t hex) {
  for(int i = 3; i >= 0; i--) {
    uint8_t digit = ((hex >> (i*4)) & 0xF);
    register_code(hex_to_keycode(digit));
    unregister_code(hex_to_keycode(digit));
  }
}

bool process_unicode(uint16_t keycode, keyrecord_t *record) {
  if (keycode > QK_UNICODE && record->event.pressed) {
    uint16_t unicode = keycode & 0x7FFF;
    unicode_input_start();
    register_hex(unicode);
    unicode_input_finish();
  }
  return true;
}

#ifdef UCIS_ENABLE
void qk_ucis_start(void) {
  qk_ucis_state.count = 0;
  qk_ucis_state.in_progress = true;

  qk_ucis_start_user();
}

__attribute__((weak))
void qk_ucis_start_user(void) {
  unicode_input_start();
  register_hex(0x2328);
  unicode_input_finish();
}

static bool is_uni_seq(char *seq) {
  uint8_t i;

  for (i = 0; seq[i]; i++) {
    uint16_t code;
    if (('1' <= seq[i]) && (seq[i] <= '0'))
      code = seq[i] - '1' + KC_1;
    else
      code = seq[i] - 'a' + KC_A;

    if (i > qk_ucis_state.count || qk_ucis_state.codes[i] != code)
      return false;
  }

  return (qk_ucis_state.codes[i] == KC_ENT ||
          qk_ucis_state.codes[i] == KC_SPC);
}

__attribute__((weak))
void qk_ucis_symbol_fallback (void) {
  for (uint8_t i = 0; i < qk_ucis_state.count - 1; i++) {
    uint8_t code = qk_ucis_state.codes[i];
    register_code(code);
    unregister_code(code);
  }
}

void register_ucis(const char *hex) {
  for(int i = 0; hex[i]; i++) {
    uint8_t kc = 0;
    char c = hex[i];

    switch (c) {
    case '0':
      kc = KC_0;
      break;
    case '1' ... '9':
      kc = c - '1' + KC_1;
      break;
    case 'a' ... 'f':
      kc = c - 'a' + KC_A;
      break;
    case 'A' ... 'F':
      kc = c - 'A' + KC_A;
      break;
    }

    if (kc) {
      register_code (kc);
      unregister_code (kc);
    }
  }
}

bool process_ucis (uint16_t keycode, keyrecord_t *record) {
  uint8_t i;

  if (!qk_ucis_state.in_progress)
    return true;

  if (qk_ucis_state.count >= UCIS_MAX_SYMBOL_LENGTH &&
      !(keycode == KC_BSPC || keycode == KC_ESC || keycode == KC_SPC || keycode == KC_ENT)) {
    return false;
  }

  if (!record->event.pressed)
    return true;

  qk_ucis_state.codes[qk_ucis_state.count] = keycode;
  qk_ucis_state.count++;

  if (keycode == KC_BSPC) {
    if (qk_ucis_state.count >= 2) {
      qk_ucis_state.count -= 2;
      return true;
    } else {
      qk_ucis_state.count--;
      return false;
    }
  }

  if (keycode == KC_ENT || keycode == KC_SPC || keycode == KC_ESC) {
    bool symbol_found = false;

    for (i = qk_ucis_state.count; i > 0; i--) {
      register_code (KC_BSPC);
      unregister_code (KC_BSPC);
    }

    if (keycode == KC_ESC) {
      qk_ucis_state.in_progress = false;
      return false;
    }

    unicode_input_start();
    for (i = 0; ucis_symbol_table[i].symbol; i++) {
      if (is_uni_seq (ucis_symbol_table[i].symbol)) {
        symbol_found = true;
        register_ucis(ucis_symbol_table[i].code + 2);
        break;
      }
    }
    if (!symbol_found) {
      qk_ucis_symbol_fallback();
    }
    unicode_input_finish();

    qk_ucis_state.in_progress = false;
    return false;
  }
  return true;
}
#endif
