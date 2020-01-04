#pragma once

#include "quantum.h"

#define LAYOUT_tkl( \
    K80,      K90, K81, K91, K82, K92, K83, K93, K84, K94, K85, K95, K86,    K96, K88, K98, \
    K00, K10, K01, K11, K02, K12, K03, K13, K04, K14, K05, K15, K06, K16,    K08, K18, K48, \
    K20, K30, K21, K31, K22, K32, K23, K33, K24, K34, K25, K35, K26, K36,    K28, K38, K58, \
    K40, K41, K51, K42, K52, K43, K53, K44, K54, K45, K55, K46, K17, K56,                   \
    K70, K97, K61, K71, K62, K72, K63, K73, K64, K74, K65, K75, K66, K76,         K68,      \
    K60, K50, K87,                K07,                K27, K37, K47, K57,    K67, K77, K78  \
) \
{ \
    { K00, K01, K02, K03, K04, K05, K06, K07, K08 }, \
    { K10, K11, K12, K13, K14, K15, K16, K17, K18 }, \
    { K20, K21, K22, K23, K24, K25, K26, K27, K28 }, \
    { K30, K31, K32, K33, K34, K35, K36, K37, K38 }, \
    { K40, K41, K42, K43, K44, K45, K46, K47, K48 }, \
    { K50, K51, K52, K53, K54, K55, K56, K57, K58 }, \
    { K60, K61, K62, K63, K64, K65, K66, K67, K68 }, \
    { K70, K71, K72, K73, K74, K75, K76, K77, K78 }, \
    { K80, K81, K82, K83, K84, K85, K86, K87, K88 }, \
    { K90, K91, K92, K93, K94, K95, K96, K97, K98 } \
}

#define LAYOUT_60( \
    K80, K10, K01, K11, K02, K12, K03, K13, K04, K14, K05, K15, K06, K16, \
    K20, K30, K21, K31, K22, K32, K23, K33, K24, K34, K25, K35, K26, K36, \
    K40, K41, K51, K42, K52, K43, K53, K44, K54, K45, K55, K46, K17, K56, \
    K70, K97, K61, K71, K62, K72, K63, K73, K64, K74, K65, K75, K66, K76, \
    K60, K50, K87,                K07,                K27, K37, K47, K57  \
) { \
    { KC_NO, K01,   K02,   K03,   K04,   K05,   K06,   K07,   KC_NO }, \
    { K10,   K11,   K12,   K13,   K14,   K15,   K16,   K17,   KC_NO }, \
    { K20,   K21,   K22,   K23,   K24,   K25,   K26,   K27,   KC_NO }, \
    { K30,   K31,   K32,   K33,   K34,   K35,   K36,   K37,   KC_NO }, \
    { K40,   K41,   K42,   K43,   K44,   K45,   K46,   K47,   KC_NO }, \
    { K50,   K51,   K52,   K53,   K54,   K55,   K56,   K57,   KC_NO }, \
    { K60,   K61,   K62,   K63,   K64,   K65,   K66,   KC_NO, KC_NO }, \
    { K70,   K71,   K72,   K73,   K74,   K75,   K76,   KC_NO, KC_NO }, \
    { K80,   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, K87,   KC_NO }, \
    { KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, K97,   KC_NO } \
}
