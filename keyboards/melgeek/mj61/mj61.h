#pragma once

#include "quantum.h"

#define XXX KC_NO

#define LAYOUT_60_ansi( \
    K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, K0B, K0C, K0D, \
    K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B, K1C, K1D, \
    K20, K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, K2B, K2C,      \
    K30,      K32, K33, K34, K35, K36, K37, K38, K39, K3A, K3B, K3C,      \
    K40, K41,      K43,      K45,                K49, K4A, K4B,      K4D  \
) { \
    { K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, K0B, K0C, K0D }, \
    { K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B, K1C, K1D }, \
    { K20, K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, K2B, K2C, XXX }, \
    { K30, XXX, K32, K33, K34, K35, K36, K37, K38, K39, K3A, K3B, K3C, XXX }, \
    { K40, K41, XXX, K43, XXX, K45, XXX, XXX, XXX, K49, K4A, K4B, XXX, K4D }  \
}
