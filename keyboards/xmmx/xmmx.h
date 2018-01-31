#ifndef XMMX
#define XMMX

#include "quantum.h"

// 80% keyboard: default - all keys
#define KEYMAP( \
	K000,       K001, K002, K003, K004, K005, K006, K007, K008, K009, K010, K011, K012, K014, K015, K016,       \
	K100, K101, K102, K103, K104, K105, K106, K107, K108, K109, K110, K111, K112, K113, K013, K114, K115, K116, \
	K200, K201, K202, K203, K204, K205, K206, K207, K208, K209, K210, K211, K212, K213, K214, K215, K216,       \
	K300, K301, K302, K303, K304, K305, K306, K307, K308, K309, K310, K311, K312, K313, K314, K315, K316,       \
	K400, K401, K402, K403, K404, K405, K406, K407, K408, K409, K410, K411, K412, K413, K414, K415, K416,       \
	K500, K501, K502,                         K507,             K510, K511, K512, K513, K514, K515, K516        \
) { \
	{ K000, K001, K002, K003, K004, K005, K006, K007, K008, K009, K010, K011, K012, K013, K014, K015, K016 }, \
	{ K100, K101, K102, K103, K104, K105, K106, K107, K108, K109, K110, K111, K112, K113, K114, K115, K116 }, \
	{ K200, K201, K202, K203, K204, K205, K206, K207, K208, K209, K210, K211, K212, K213, K214, K215, K216 }, \
	{ K300, K301, K302, K303, K304, K305, K306, K307, K308, K309, K310, K311, K312, K313, K314, K315, K316 }, \
	{ K400, K401, K402, K403, K404, K405, K406, K407, K408, K409, K410, K411, K412, K413, K414, K415, K416 }, \
	{ K500, K501, K502, KC_NO,KC_NO,KC_NO,KC_NO,K507, KC_NO,KC_NO,K510, K511, K512, K513, K514, K515, K516 }  \
}

// 80% keyboard: ANSI Winkey
#define KEYMAP_ANSI_WK( \
	K000,       K001, K002, K003, K004, K005, K006, K007, K008, K009, K010, K011, K012, K014, K015, K016, \
	K100, K101, K102, K103, K104, K105, K106, K107, K108, K109, K110, K111, K112, K113, K114, K115, K116, \
	K200, K201, K202, K203, K204, K205, K206, K207, K208, K209, K210, K211, K212, K213, K214, K215, K216, \
	K300, K301, K302, K303, K304, K305, K306, K307, K308, K309, K310, K311,       K313,                   \
	K400,       K402, K403, K404, K405, K406, K407, K408, K409, K410, K411, K412,             K415,       \
	K500, K501, K502,                         K507,             K510, K511, K512, K513, K514, K515, K516  \
) { \
	{ K000, K001, K002, K003, K004, K005, K006, K007, K008, K009, K010, K011, K012, KC_NO,K014, K015, K016 }, \
	{ K100, K101, K102, K103, K104, K105, K106, K107, K108, K109, K110, K111, K112, K113, K114, K115, K116 }, \
	{ K200, K201, K202, K203, K204, K205, K206, K207, K208, K209, K210, K211, K212, K213, K214, K215, K216 }, \
	{ K300, K301, K302, K303, K304, K305, K306, K307, K308, K309, K310, K311, KC_NO,K313, KC_NO,KC_NO,KC_NO}, \
	{ K400, KC_NO,K402, K403, K404, K405, K406, K407, K408, K409, K410, K411, K412, KC_NO,KC_NO,K415, KC_NO}, \
	{ K500, K501, K502, KC_NO,KC_NO,KC_NO,KC_NO,K507, KC_NO,KC_NO,K510, K511, K512, K513, K514, K515, K516 }  \
}

// 80% keyboard: ANSI Winkeyless
#define KEYMAP_ANSI_WKL( \
	K000,       K001, K002, K003, K004, K005, K006, K007, K008, K009, K010, K011, K012, K014, K015, K016, \
	K100, K101, K102, K103, K104, K105, K106, K107, K108, K109, K110, K111, K112, K113, K114, K115, K116, \
	K200, K201, K202, K203, K204, K205, K206, K207, K208, K209, K210, K211, K212, K213, K214, K215, K216, \
	K300, K301, K302, K303, K304, K305, K306, K307, K308, K309, K310, K311,       K313,                   \
	K400,       K402, K403, K404, K405, K406, K407, K408, K409, K410, K411, K412,             K415,       \
	K500,       K502,                         K507,                   K511,       K513, K514, K515, K516  \
) { \
	{ K000, K001, K002, K003, K004, K005, K006, K007, K008, K009, K010, K011, K012, KC_NO,K014, K015, K016 }, \
	{ K100, K101, K102, K103, K104, K105, K106, K107, K108, K109, K110, K111, K112, K113, K114, K115, K116 }, \
	{ K200, K201, K202, K203, K204, K205, K206, K207, K208, K209, K210, K211, K212, K213, K214, K215, K216 }, \
	{ K300, K301, K302, K303, K304, K305, K306, K307, K308, K309, K310, K311, KC_NO,K313, KC_NO,KC_NO,KC_NO}, \
	{ K400, KC_NO,K402, K403, K404, K405, K406, K407, K408, K409, K410, K411, K412, KC_NO,KC_NO,K415, KC_NO}, \
	{ K500, KC_NO,K502, KC_NO,KC_NO,KC_NO,KC_NO,K507, KC_NO,KC_NO,KC_NO,K511, KC_NO,K513, K514, K515, K516 }  \
}

// 80% keyboard: ISO Winkey
#define KEYMAP_ISO_WK( \
	K000,       K001, K002, K003, K004, K005, K006, K007, K008, K009, K010, K011, K012, K014, K015, K016, \
	K100, K101, K102, K103, K104, K105, K106, K107, K108, K109, K110, K111, K112, K113, K114, K115, K116, \
	K200, K201, K202, K203, K204, K205, K206, K207, K208, K209, K210, K211, K212,       K214, K215, K216, \
	K300, K301, K302, K303, K304, K305, K306, K307, K308, K309, K310, K311, K312, K313,                   \
	K400, K401, K402, K403, K404, K405, K406, K407, K408, K409, K410, K411, K412,             K415,       \
	K500, K501, K502,                         K507,             K510, K511, K512, K513, K514, K515, K516  \
) { \
	{ K000, K001, K002, K003, K004, K005, K006, K007, K008, K009, K010, K011, K012, KC_NO,K014, K015, K016 }, \
	{ K100, K101, K102, K103, K104, K105, K106, K107, K108, K109, K110, K111, K112, K113, K114, K115, K116 }, \
	{ K200, K201, K202, K203, K204, K205, K206, K207, K208, K209, K210, K211, K212, KC_NO,K214, K215, K216 }, \
	{ K300, K301, K302, K303, K304, K305, K306, K307, K308, K309, K310, K311, K312, K313, KC_NO,KC_NO,KC_NO}, \
	{ K400, K401, K402, K403, K404, K405, K406, K407, K408, K409, K410, K411, K412, KC_NO,KC_NO,K415, KC_NO}, \
	{ K500, K501, K502, KC_NO,KC_NO,KC_NO,KC_NO,K507, KC_NO,KC_NO,K510, K511, K512, K513, K514, K515, K516 }  \
}

// 80% keyboard: ISO Winkeyless
#define KEYMAP_ISO_WKL( \
	K000,       K001, K002, K003, K004, K005, K006, K007, K008, K009, K010, K011, K012, K014, K015, K016, \
	K100, K101, K102, K103, K104, K105, K106, K107, K108, K109, K110, K111, K112, K113, K114, K115, K116, \
	K200, K201, K202, K203, K204, K205, K206, K207, K208, K209, K210, K211, K212,       K214, K215, K216, \
	K300, K301, K302, K303, K304, K305, K306, K307, K308, K309, K310, K311, K312, K313,                   \
	K400, K401, K402, K403, K404, K405, K406, K407, K408, K409, K410, K411, K412,             K415,       \
	K500,       K502,                         K507,                   K511,       K513, K514, K515, K516  \
) { \
	{ K000, K001, K002, K003, K004, K005, K006, K007, K008, K009, K010, K011, K012, KC_NO,K014, K015, K016 }, \
	{ K100, K101, K102, K103, K104, K105, K106, K107, K108, K109, K110, K111, K112, K113, K114, K115, K116 }, \
	{ K200, K201, K202, K203, K204, K205, K206, K207, K208, K209, K210, K211, K212, KC_NO,K214, K215, K216 }, \
	{ K300, K301, K302, K303, K304, K305, K306, K307, K308, K309, K310, K311, K312, K313, KC_NO,KC_NO,KC_NO}, \
	{ K400, K401, K402, K403, K404, K405, K406, K407, K408, K409, K410, K411, K412, KC_NO,KC_NO,K415, KC_NO}, \
	{ K500, KC_NO,K502, KC_NO,KC_NO,KC_NO,KC_NO,K507, KC_NO,KC_NO,KC_NO,K511, KC_NO,K513, K514, K515, K516 }  \
}


// 70% keyboard: default - all keys
#define TOAD_KEYMAP( \
	K000,       K001, K002, K003, K004, K005, K006, K007, K008, K009, K010, K011, K012,        \
	K100, K101, K102, K103, K104, K105, K106, K107, K108, K109, K110, K111, K112, K113, K013,  \
	K200, K201, K202, K203, K204, K205, K206, K207, K208, K209, K210, K211, K212, K213,        \
	K300, K301, K302, K303, K304, K305, K306, K307, K308, K309, K310, K311, K312, K313,        \
	K400, K401, K402, K403, K404, K405, K406, K407, K408, K409, K410, K411, K412, K413,        \
	K500, K501, K502,                         K507,             K510, K511, K512, K513         \
) { \
	{ K000, K001, K002, K003, K004, K005, K006, K007, K008, K009, K010, K011, K012, K013 }, \
	{ K100, K101, K102, K103, K104, K105, K106, K107, K108, K109, K110, K111, K112, K113 }, \
	{ K200, K201, K202, K203, K204, K205, K206, K207, K208, K209, K210, K211, K212, K213 }, \
	{ K300, K301, K302, K303, K304, K305, K306, K307, K308, K309, K310, K311, K312, K313 }, \
	{ K400, K401, K402, K403, K404, K405, K406, K407, K408, K409, K410, K411, K412, K413 }, \
	{ K500, K501, K502, KC_NO,KC_NO,KC_NO,KC_NO,K507, KC_NO,KC_NO,K510, K511, K512, K513 }  \
}

// 70% keyboard: ANSI Winkey
#define TOAD_KEYMAP_ANSI_WK( \
	K000,       K001, K002, K003, K004, K005, K006, K007, K008, K009, K010, K011, K012,  \
	K100, K101, K102, K103, K104, K105, K106, K107, K108, K109, K110, K111, K112, K013,  \
	K200, K201, K202, K203, K204, K205, K206, K207, K208, K209, K210, K211, K212, K213,  \
	K300, K301, K302, K303, K304, K305, K306, K307, K308, K309, K310, K311,       K313,  \
	K400,       K402, K403, K404, K405, K406, K407, K408, K409, K410, K411, K412,        \
	K500, K501, K502,                         K507,             K510, K511, K512, K513   \
) { \
	{ K000, K001, K002, K003, K004, K005, K006, K007, K008, K009, K010, K011, K012, K013 }, \
	{ K100, K101, K102, K103, K104, K105, K106, K107, K108, K109, K110, K111, K112, KC_NO}, \
	{ K200, K201, K202, K203, K204, K205, K206, K207, K208, K209, K210, K211, K212, K213 }, \
	{ K300, K301, K302, K303, K304, K305, K306, K307, K308, K309, K310, K311, KC_NO,K313 }, \
	{ K400, KC_NO,K402, K403, K404, K405, K406, K407, K408, K409, K410, K411, K412, KC_NO}, \
	{ K500, K501, K502, KC_NO,KC_NO,KC_NO,KC_NO,K507, KC_NO,KC_NO,K510, K511, K512, K513 }  \
}

// 70% keyboard: ANSI Winkeyless
#define TOAD_KEYMAP_ANSI_WKL( \
	K000,       K001, K002, K003, K004, K005, K006, K007, K008, K009, K010, K011, K012,  \
	K100, K101, K102, K103, K104, K105, K106, K107, K108, K109, K110, K111, K112, K013,  \
	K200, K201, K202, K203, K204, K205, K206, K207, K208, K209, K210, K211, K212, K213,  \
	K300, K301, K302, K303, K304, K305, K306, K307, K308, K309, K310, K311,       K313,  \
	K400,       K402, K403, K404, K405, K406, K407, K408, K409, K410, K411, K412,        \
	K500,       K502,                         K507,                   K511,       K513   \
) { \
	{ K000, K001, K002, K003, K004, K005, K006, K007, K008, K009, K010, K011, K012, K013 }, \
	{ K100, K101, K102, K103, K104, K105, K106, K107, K108, K109, K110, K111, K112, KC_NO}, \
	{ K200, K201, K202, K203, K204, K205, K206, K207, K208, K209, K210, K211, K212, K213 }, \
	{ K300, K301, K302, K303, K304, K305, K306, K307, K308, K309, K310, K311, KC_NO,K313 }, \
	{ K400, KC_NO,K402, K403, K404, K405, K406, K407, K408, K409, K410, K411, K412, KC_NO}, \
	{ K500, KC_NO,K502, KC_NO,KC_NO,KC_NO,KC_NO,K507, KC_NO,KC_NO,KC_NO,K511, KC_NO,K513 }  \
}

// 70% keyboard: ISO Winkey
#define TOAD_KEYMAP_ISO_WK( \
	K000,       K001, K002, K003, K004, K005, K006, K007, K008, K009, K010, K011, K012,  \
	K100, K101, K102, K103, K104, K105, K106, K107, K108, K109, K110, K111, K112, K013,  \
	K200, K201, K202, K203, K204, K205, K206, K207, K208, K209, K210, K211, K212,        \
	K300, K301, K302, K303, K304, K305, K306, K307, K308, K309, K310, K311, K312, K313,  \
	K400, K401, K402, K403, K404, K405, K406, K407, K408, K409, K410, K411, K412,        \
	K500, K501, K502,                         K507,             K510, K511, K512, K513   \
) { \
	{ K000, K001, K002, K003, K004, K005, K006, K007, K008, K009, K010, K011, K012, K013 }, \
	{ K100, K101, K102, K103, K104, K105, K106, K107, K108, K109, K110, K111, K112, KC_NO}, \
	{ K200, K201, K202, K203, K204, K205, K206, K207, K208, K209, K210, K211, K212, KC_NO}, \
	{ K300, K301, K302, K303, K304, K305, K306, K307, K308, K309, K310, K311, K312, K313 }, \
	{ K400, K401, K402, K403, K404, K405, K406, K407, K408, K409, K410, K411, K412, KC_NO}, \
	{ K500, K501, K502, KC_NO,KC_NO,KC_NO,KC_NO,K507, KC_NO,KC_NO,K510, K511, K512, K513 }  \
}

// 70% keyboard: ISO Winkeyless
#define TOAD_KEYMAP_ISO_WKL( \
	K000,       K001, K002, K003, K004, K005, K006, K007, K008, K009, K010, K011, K012,  \
	K100, K101, K102, K103, K104, K105, K106, K107, K108, K109, K110, K111, K112, K013,  \
	K200, K201, K202, K203, K204, K205, K206, K207, K208, K209, K210, K211, K212,        \
	K300, K301, K302, K303, K304, K305, K306, K307, K308, K309, K310, K311, K312, K313,  \
	K400, K401, K402, K403, K404, K405, K406, K407, K408, K409, K410, K411, K412,        \
	K500,       K502,                         K507,                   K511,       K513   \
) { \
	{ K000, K001, K002, K003, K004, K005, K006, K007, K008, K009, K010, K011, K012, K013 }, \
	{ K100, K101, K102, K103, K104, K105, K106, K107, K108, K109, K110, K111, K112, KC_NO}, \
	{ K200, K201, K202, K203, K204, K205, K206, K207, K208, K209, K210, K211, K212, KC_NO}, \
	{ K300, K301, K302, K303, K304, K305, K306, K307, K308, K309, K310, K311, K312, K313 }, \
	{ K400, K401, K402, K403, K404, K405, K406, K407, K408, K409, K410, K411, K412, KC_NO}, \
	{ K500, KC_NO,K502, KC_NO,KC_NO,KC_NO,KC_NO,K507, KC_NO,KC_NO,KC_NO,K511, KC_NO,K513 }  \
}

#endif
