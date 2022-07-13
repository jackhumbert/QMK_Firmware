// Copyright 2022 Andrew Kannan (@awkannan)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include "quantum.h"

#define ____ KC_NO

#define LAYOUT_all( \
	K000, K001, K002, K003, K004, K005, K006, K007, K008, K009, K010, K011, K012,       K014, K015, K016, K017, \
	K100, K101, K102, K103, K104, K105, K106, K107, K108, K109, K110, K111, K112, K113, K114, K115, K116, K117, \
	K200, K201, K202, K203, K204, K205, K206, K207, K208, K209, K210, K211, K212,       K214, K215, K216, K217, \
	K300, K301, K302, K303, K304, K305, K306, K307, K308, K309, K310, K311, K312,       K314,                   \
	K400, K401, K402, K403, K404, K405, K406, K407, K408, K409, K410, K411, K412,       K414,       K416,       \
	K500, K501, K502,                   K506,                         K511, K512,       K514, K515, K516, K517  \
) { \
	{ K000,  K001,  K002,  K003,  K004,  K005,  K006,  K007,  K008,  K009,  K010,  K011,  K012,  ____,  K014,  K015,  K016,  K017 }, \
	{ K100,  K101,  K102,  K103,  K104,  K105,  K106,  K107,  K108,  K109,  K110,  K111,  K112,  K113,  K114,  K115,  K116,  K117 }, \
	{ K200,  K201,  K202,  K203,  K204,  K205,  K206,  K207,  K208,  K209,  K210,  K211,  K212,  ____,  K214,  K215,  K216,  K217 }, \
	{ K300,  K301,  K302,  K303,  K304,  K305,  K306,  K307,  K308,  K309,  K310,  K311,  K312,  ____,  K314,  ____,  ____,  ____ }, \
	{ K400,  K401,  K402,  K403,  K404,  K405,  K406,  K407,  K408,  K409,  K410,  K411,  K412,  ____,  K414,  ____,  K416,  ____ }, \
	{ K500,  K501,  K502,  ____,  ____,  ____,  K506,  ____,  ____,  ____,  ____,  K511,  K512,  ____,  K514,  K515,  K516,  K517 }  \
}
