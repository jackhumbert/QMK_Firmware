#pragma once

#include "quantum.h"

enum custom_keycodes {
	CTRL_C_UP = SAFE_RANGE,
	L1_EXPL,
	CMD_SRH
};

enum tap_dances {
	SSHT = 0,
	LBRC,
	SCLN,
	QUOT,
	END_HOME
};

bool process_record_user(uint16_t keycode, keyrecord_t *record);

void dance_SSHT_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_SSHT_reset(qk_tap_dance_state_t *state, void *user_data);
void dance_LBRC_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_LBRC_reset(qk_tap_dance_state_t *state, void *user_data);
void dance_SCLN_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_SCLN_reset(qk_tap_dance_state_t *state, void *user_data);
void dance_QUOT_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_QUOT_reset(qk_tap_dance_state_t *state, void *user_data);
