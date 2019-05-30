#ifndef RGBLIGHT_EFFECT_BREATHE_TABLE
#define RGBLIGHT_EFFECT_BREATHE_TABLE

const uint8_t rgblight_effect_breathe_table[] PROGMEM = {
  /* #define RGBLIGHT_EFFECT_BREATHE_CENTER   0.00 */
  /* #define RGBLIGHT_EFFECT_BREATHE_MAX      255 */

 #if RGBLIGHT_BREATHE_TABLE_SIZE == 256
  0x44,  0x45,  0x47,  0x48,  0x4a,  0x4b,  0x4c,  0x4e,
  0x4f,  0x51,  0x52,  0x54,  0x55,  0x57,  0x58,  0x5a,
  0x5c,  0x5d,  0x5f,  0x60,  0x62,  0x64,  0x65,  0x67,
  0x69,  0x6a,  0x6c,  0x6e,  0x70,  0x72,  0x73,  0x75,
  0x77,  0x79,  0x7b,  0x7c,  0x7e,  0x80,  0x82,  0x84,
  0x86,  0x88,  0x8a,  0x8b,  0x8d,  0x8f,  0x91,  0x93,
  0x95,  0x97,  0x99,  0x9b,  0x9d,  0x9f,  0xa1,  0xa3,
  0xa5,  0xa7,  0xa9,  0xaa,  0xac,  0xae,  0xb0,  0xb2,
  0xb4,  0xb6,  0xb8,  0xba,  0xbc,  0xbe,  0xbf,  0xc1,
  0xc3,  0xc5,  0xc7,  0xc9,  0xca,  0xcc,  0xce,  0xd0,
  0xd1,  0xd3,  0xd5,  0xd6,  0xd8,  0xda,  0xdb,  0xdd,
  0xde,  0xe0,  0xe1,  0xe3,  0xe4,  0xe5,  0xe7,  0xe8,
  0xe9,  0xeb,  0xec,  0xed,  0xee,  0xef,  0xf0,  0xf1,
  0xf2,  0xf3,  0xf4,  0xf5,  0xf6,  0xf7,  0xf8,  0xf8,
  0xf9,  0xfa,  0xfa,  0xfb,  0xfc,  0xfc,  0xfc,  0xfd,
  0xfd,  0xfe,  0xfe,  0xfe,  0xfe,  0xfe,  0xfe,  0xfe,
  0xfe,  0xfe,  0xfe,  0xfe,  0xfe,  0xfe,  0xfe,  0xfd,
  0xfd,  0xfc,  0xfc,  0xfc,  0xfb,  0xfa,  0xfa,  0xf9,
  0xf8,  0xf8,  0xf7,  0xf6,  0xf5,  0xf4,  0xf3,  0xf2,
  0xf1,  0xf0,  0xef,  0xee,  0xed,  0xec,  0xeb,  0xe9,
  0xe8,  0xe7,  0xe5,  0xe4,  0xe3,  0xe1,  0xe0,  0xde,
  0xdd,  0xdb,  0xda,  0xd8,  0xd6,  0xd5,  0xd3,  0xd1,
  0xd0,  0xce,  0xcc,  0xca,  0xc9,  0xc7,  0xc5,  0xc3,
  0xc1,  0xbf,  0xbe,  0xbc,  0xba,  0xb8,  0xb6,  0xb4,
  0xb2,  0xb0,  0xae,  0xac,  0xaa,  0xa9,  0xa7,  0xa5,
  0xa3,  0xa1,  0x9f,  0x9d,  0x9b,  0x99,  0x97,  0x95,
  0x93,  0x91,  0x8f,  0x8d,  0x8b,  0x8a,  0x88,  0x86,
  0x84,  0x82,  0x80,  0x7e,  0x7c,  0x7b,  0x79,  0x77,
  0x75,  0x73,  0x72,  0x70,  0x6e,  0x6c,  0x6a,  0x69,
  0x67,  0x65,  0x64,  0x62,  0x60,  0x5f,  0x5d,  0x5c,
  0x5a,  0x58,  0x57,  0x55,  0x54,  0x52,  0x51,  0x4f,
  0x4e,  0x4c,  0x4b,  0x4a,  0x48,  0x47,  0x45,  0x44
 #endif /* 256 bytes table */

 #if RGBLIGHT_BREATHE_TABLE_SIZE == 128
  0x44,  0x47,  0x4a,  0x4c,
  0x4f,  0x52,  0x55,  0x58,
  0x5c,  0x5f,  0x62,  0x65,
  0x69,  0x6c,  0x70,  0x73,
  0x77,  0x7b,  0x7e,  0x82,
  0x86,  0x8a,  0x8d,  0x91,
  0x95,  0x99,  0x9d,  0xa1,
  0xa5,  0xa9,  0xac,  0xb0,
  0xb4,  0xb8,  0xbc,  0xbf,
  0xc3,  0xc7,  0xca,  0xce,
  0xd1,  0xd5,  0xd8,  0xdb,
  0xde,  0xe1,  0xe4,  0xe7,
  0xe9,  0xec,  0xee,  0xf0,
  0xf2,  0xf4,  0xf6,  0xf8,
  0xf9,  0xfa,  0xfc,  0xfc,
  0xfd,  0xfe,  0xfe,  0xfe,
  0xfe,  0xfe,  0xfe,  0xfe,
  0xfd,  0xfc,  0xfb,  0xfa,
  0xf8,  0xf7,  0xf5,  0xf3,
  0xf1,  0xef,  0xed,  0xeb,
  0xe8,  0xe5,  0xe3,  0xe0,
  0xdd,  0xda,  0xd6,  0xd3,
  0xd0,  0xcc,  0xc9,  0xc5,
  0xc1,  0xbe,  0xba,  0xb6,
  0xb2,  0xae,  0xaa,  0xa7,
  0xa3,  0x9f,  0x9b,  0x97,
  0x93,  0x8f,  0x8b,  0x88,
  0x84,  0x80,  0x7c,  0x79,
  0x75,  0x72,  0x6e,  0x6a,
  0x67,  0x64,  0x60,  0x5d,
  0x5a,  0x57,  0x54,  0x51,
  0x4e,  0x4b,  0x48,  0x45
 #endif /* 128 bytes table */

 #if RGBLIGHT_BREATHE_TABLE_SIZE == 64
  0x44,  0x4a,
  0x4f,  0x55,
  0x5c,  0x62,
  0x69,  0x70,
  0x77,  0x7e,
  0x86,  0x8d,
  0x95,  0x9d,
  0xa5,  0xac,
  0xb4,  0xbc,
  0xc3,  0xca,
  0xd1,  0xd8,
  0xde,  0xe4,
  0xe9,  0xee,
  0xf2,  0xf6,
  0xf9,  0xfc,
  0xfd,  0xfe,
  0xfe,  0xfe,
  0xfd,  0xfb,
  0xf8,  0xf5,
  0xf1,  0xed,
  0xe8,  0xe3,
  0xdd,  0xd6,
  0xd0,  0xc9,
  0xc1,  0xba,
  0xb2,  0xaa,
  0xa3,  0x9b,
  0x93,  0x8b,
  0x84,  0x7c,
  0x75,  0x6e,
  0x67,  0x60,
  0x5a,  0x54,
  0x4e,  0x48
 #endif /* 64 bytes table */
};

static const int table_scale = 256/sizeof(rgblight_effect_breathe_table);

#endif /* RGBLIGHT_EFFECT_BREATHE_TABLE */
