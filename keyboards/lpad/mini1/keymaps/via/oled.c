/* Copyright 2021 bululau
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

static const char oled_a [] PROGMEM = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf8, 0xf8, 0xfc, 0xf8, 0xf8,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf8, 0xf8, 0xfc, 0xf8, 0xf0, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff,
	0x00, 0x00, 0x00, 0x00, 0xfc, 0xfe, 0xfe, 0xfe, 0xfc, 0xf8, 0x7c, 0x3c, 0x3e, 0x3e, 0x3e, 0x7e,
	0xfe, 0xfc, 0xfc, 0xf8, 0xf0, 0xc0, 0x00, 0x00, 0x00, 0xf0, 0xf8, 0xfc, 0xfc, 0x7e, 0x3e, 0x1e,
	0x1e, 0x1e, 0x1e, 0x3e, 0xfe, 0xfc, 0xfc, 0xf8, 0xf0, 0x80, 0x00, 0x00, 0x80, 0xe0, 0xf8, 0xfc,
	0xfc, 0xfe, 0xfe, 0x3e, 0x3e, 0x3e, 0x3e, 0x3c, 0xfc, 0xf8, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff,
	0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe1, 0x80, 0x00, 0x00, 0x00, 0x80, 0x80,
	0xe0, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0xe0, 0xf8, 0xfd, 0xfd, 0xfe, 0xfe, 0x1e, 0x1e,
	0x0e, 0x0f, 0x0f, 0x8f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x3f, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x80, 0xc0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0xf8, 0xfc, 0xfc, 0xf8, 0x1c, 0x1c, 0xfc, 0xfc, 0xf8, 0x1c, 0x1c,
	0xfc, 0xfc, 0xf8, 0x00, 0x00, 0xff, 0xff, 0xf9, 0x00, 0xf8, 0xfc, 0xfc, 0x38, 0x1c, 0x1c, 0xfc,
	0xfc, 0xf8, 0x00, 0xf9, 0xff, 0xff, 0xf9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f,
	0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0x07, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f,
	0x0f, 0x0f, 0x07, 0x03, 0x01, 0x00, 0x00, 0x00, 0x01, 0x03, 0x07, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f,
	0x0f, 0x0f, 0x0f, 0x07, 0x03, 0x07, 0x0f, 0x0f, 0x0f, 0x0f, 0x00, 0x00, 0x00, 0x01, 0x03, 0x07,
	0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x07, 0x03, 0x0f, 0x0f, 0x0f, 0x0f, 0x07, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x0f, 0x0f, 0x0f, 0x00, 0x00, 0x0f, 0x0f, 0x0f, 0x00, 0x00,
	0x0f, 0x0f, 0x0f, 0x00, 0x00, 0x0f, 0x0f, 0x0f, 0x00, 0x0f, 0x0f, 0x0f, 0x00, 0x00, 0x00, 0x0f,
	0x0f, 0x0f, 0x00, 0x07, 0x0f, 0x0f, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

// 'setting128x32', 128x32px
static const char oled_b [] PROGMEM = {
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf9, 0x64, 0x8d,
	0xa3, 0x67, 0xee, 0xdc, 0x91, 0x87, 0x8d, 0x33, 0x67, 0xef, 0xcf, 0xdf, 0xc6, 0xd5, 0xd3, 0x52,
	0x13, 0x13, 0x33, 0x33, 0x67, 0x67, 0x4f, 0xc6, 0xc7, 0xed, 0xef, 0xef, 0xfb, 0xfb, 0xff, 0xf7,
	0xf3, 0x73, 0x33, 0x93, 0xc7, 0xe1, 0x79, 0x74, 0xb6, 0xdc, 0xf0, 0xfe, 0x3c, 0x81, 0xf7, 0xff,
	0xff, 0xff, 0xff, 0xfe, 0xf1, 0x0f, 0x7f, 0xfe, 0xc0, 0x03, 0xef, 0x9f, 0x3f, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf1, 0x80, 0x3f,
	0x7f, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x47, 0x7e, 0xb8, 0xc9, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe,
	0xfe, 0xfe, 0xf8, 0xf0, 0xf0, 0xc8, 0xe6, 0xfe, 0xfc, 0xed, 0xfb, 0xfb, 0xff, 0xff, 0xff, 0xff,
	0x01, 0x7c, 0xff, 0xff, 0x8f, 0xec, 0xee, 0x81, 0x81, 0x01, 0x81, 0xc4, 0x7f, 0xff, 0xff, 0xff,
	0xff, 0xf7, 0x1f, 0xff, 0xff, 0xff, 0xfc, 0xf1, 0xef, 0xfe, 0xe7, 0x3f, 0xfe, 0xfc, 0xf3, 0xcf,
	0x1f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xfe, 0xff, 0xff, 0x7f, 0x18, 0xce, 0xf4, 0xfd, 0xff, 0x7b, 0x73, 0x8f, 0x9f, 0x1f, 0x9f,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x7f, 0xbf, 0xdf, 0xef, 0xef,
	0xf6, 0xf8, 0xfb, 0xf7, 0xe7, 0xff, 0xbf, 0xff, 0x7f, 0x7f, 0x01, 0x8f, 0x39, 0x07, 0x7f, 0xff,
	0xff, 0xff, 0xff, 0xf1, 0x8f, 0x7f, 0xff, 0xff, 0xfb, 0xf7, 0xef, 0xd8, 0xa3, 0x8f, 0x7f, 0xff,
	0xff, 0xfc, 0xe3, 0x1f, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0x7f, 0x7f, 0x7f, 0xbf, 0xbf, 0xdf, 0xdf, 0xef, 0xef, 0xf7, 0xf7, 0xe7, 0xd7,
	0xf7, 0x37, 0x3f, 0x99, 0xda, 0xfb, 0xdb, 0x4d, 0xbf, 0xc6, 0xe2, 0xe9, 0xed, 0xee, 0xef, 0xef,
	0x6f, 0xc6, 0x60, 0xbd, 0xdd, 0xcd, 0xc1, 0xe9, 0xef, 0xf6, 0xe0, 0xdc, 0x1c, 0x09, 0x09, 0x01,
	0x03, 0x03, 0x01, 0x99, 0x09, 0x09, 0x1c, 0x7c, 0x7e, 0x7e, 0x7f, 0x3f, 0xbf, 0x9f, 0x18, 0xc1,
	0xe3, 0xe7, 0xcf, 0x9f, 0x3f, 0xfc, 0x61, 0x8f, 0x3f, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc,
	0xf9, 0xf3, 0xe7, 0xdf, 0xb8, 0x07, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff
};

// 'function128x32', 128x32px
static const char oled_c [] PROGMEM = {
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0x3f, 0x0f, 0xc3, 0xf0, 0x7c, 0x07, 0xe0, 0x00, 0x0f, 0xff, 0xff, 0x7f, 0x3f,
	0x00, 0x01, 0x03, 0x1f, 0x01, 0x04, 0x0f, 0x00, 0x00, 0xc7, 0x8f, 0xbf, 0xbf, 0x7f, 0xe0, 0xff,
	0xff, 0x80, 0x1f, 0xfd, 0x02, 0x3e, 0x31, 0x2f, 0x1f, 0x0f, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xfc,
	0x80, 0x07, 0xff, 0xff, 0xff, 0xff, 0xc1, 0x3f, 0xff, 0xff, 0x80, 0x07, 0x38, 0x0f, 0xff, 0xfe,
	0x07, 0x3f, 0xfe, 0xf9, 0xe3, 0x00, 0x03, 0x5f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0x01, 0x00, 0xfe, 0x7f, 0x07, 0xe0, 0xfe, 0xff, 0xfe, 0xf8, 0xf8, 0x83, 0x0f, 0x00,
	0x00, 0xfe, 0xfe, 0xa0, 0x20, 0x20, 0x81, 0xf1, 0x7d, 0x3d, 0x9d, 0xdb, 0xff, 0xfb, 0xfb, 0x1f,
	0x0b, 0xf9, 0xfc, 0xfc, 0xe5, 0x00, 0x00, 0x44, 0x04, 0x00, 0xc8, 0x81, 0x03, 0x73, 0x67, 0x07,
	0xef, 0x4c, 0x41, 0x9f, 0xff, 0xff, 0xff, 0xf8, 0x03, 0xff, 0xff, 0x00, 0x00, 0xfc, 0xff, 0x3f,
	0xe0, 0x80, 0x1f, 0xff, 0xff, 0xff, 0x0e, 0x00, 0xe7, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xfc, 0xf0, 0x03, 0xc0, 0xff, 0x0f, 0xf9, 0xfe, 0xff, 0xff, 0x03, 0xc9, 0x7f, 0x00,
	0x1c, 0x7e, 0xfd, 0xfd, 0xfd, 0xf9, 0xfd, 0xfc, 0xfe, 0xfb, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc,
	0xf9, 0xf3, 0xf7, 0xe7, 0xef, 0xed, 0xe9, 0xe9, 0xea, 0xeb, 0xe1, 0x38, 0xc7, 0xf0, 0xfc, 0x70,
	0x03, 0xc3, 0xe0, 0xff, 0xff, 0xff, 0xff, 0x1f, 0xfe, 0x21, 0x13, 0xc0, 0x7e, 0x1f, 0xe3, 0xf8,
	0xff, 0x3f, 0x00, 0xff, 0xff, 0xff, 0xff, 0x00, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xfc, 0xe0, 0xc7, 0x80, 0x8f, 0x3f, 0x7f, 0xff, 0xfe, 0xf0, 0xe0, 0xcc,
	0x9f, 0xbc, 0x59, 0x13, 0xc7, 0xcf, 0x9f, 0x3f, 0x7f, 0xff, 0xff, 0xff, 0xf7, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0x7f, 0x7f, 0x3f, 0x1f, 0xbf, 0xdf, 0x03, 0xcc, 0x87, 0x03, 0xf9, 0x1c, 0x87,
	0xf1, 0xff, 0xff, 0xff, 0xff, 0x3f, 0xc7, 0x7c, 0x07, 0xb0, 0x9e, 0xce, 0x62, 0x3b, 0x1f, 0x41,
	0x20, 0x9a, 0xcf, 0xc7, 0xe3, 0x79, 0x0c, 0xc0, 0xfc, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff
};

static const char oled_d [] PROGMEM = {
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x0f, 0xc3, 0xf8, 0xfe, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x3f, 0x9f, 0x9f, 0x9f, 0x9f, 0x9f, 0x1f, 0x07,
	0x8f, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x00, 0x87, 0xcf, 0x0f,
	0x0f, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xfc, 0xe0, 0x81, 0x33, 0xf3,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xef, 0xe7, 0x67, 0x03, 0xc3, 0xf9, 0xfc, 0xfe, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xbf, 0x1f, 0x1f, 0x1f, 0x0f, 0x01, 0xf0, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0x7f, 0x3f, 0x0f, 0x6f, 0x7f, 0x7f, 0x3f, 0x7f, 0x7f, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0xf8, 0xf3, 0x07, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x0f, 0xc0, 0xfc, 0x03, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0x1f, 0x1f, 0x7f, 0x0f, 0xcf, 0xe7, 0xf3, 0xfb, 0xfb, 0x7b, 0x33, 0x30, 0x26,
	0x0f, 0x1e, 0xfc, 0xf9, 0xc7, 0x0f, 0x1f, 0x7f, 0x7f, 0xbf, 0xcf, 0x01, 0x60, 0xfb, 0xf9, 0xfd,
	0xfc, 0x1c, 0x0c, 0x09, 0x01, 0x01, 0x51, 0xf1, 0x07, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7e, 0x01,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x03, 0xf0, 0xff, 0xff, 0xff, 0xff, 0xff, 0x1f, 0xc3, 0xe3,
	0x07, 0x03, 0x33, 0x31, 0x70, 0xf0, 0xf2, 0xf3, 0xe7, 0xc0, 0x06, 0x9f, 0x7f, 0xff, 0xff, 0x7f,
	0x1f, 0x8f, 0xe7, 0xf1, 0x3c, 0x1e, 0x48, 0x60, 0x67, 0xe7, 0xe7, 0xef, 0xee, 0xcc, 0x9d, 0x1f,
	0xff, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x0f, 0xfc, 0x01, 0x0f, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0xfc, 0xfc, 0x40, 0xff, 0xf8, 0xe1, 0x8f, 0x3f,
	0xff, 0xff, 0xff, 0xfe, 0xe0, 0x1c, 0x78, 0xf7, 0xef, 0xdf, 0xdf, 0xdf, 0xde, 0xdc, 0xcc, 0xec,
	0xf0, 0xf0, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xfe, 0xff, 0xff, 0xff, 0xfe, 0xfc, 0xfb, 0xf7, 0xf7,
	0xef, 0xff, 0xf6, 0xf6, 0xf3, 0x99, 0xc6, 0xc1, 0x8c, 0x07, 0x43, 0x63, 0xe3, 0x01, 0x1c, 0xfe,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0xf0, 0x07, 0xc7, 0x07, 0x0f, 0x0f, 0x18, 0x07, 0x1c,
	0x30, 0xe4, 0xcc, 0xdc, 0xde, 0xdf, 0xdf, 0xcf, 0xe7, 0xf3, 0xfc, 0xff, 0xff, 0xfc, 0xfc, 0xfc,
	0xfe, 0xff, 0xff, 0xff, 0xe0, 0xc0, 0x90, 0xb0, 0xb8, 0x3f, 0x3f, 0xbf, 0xbf, 0xdf, 0xcf, 0xf0,
	0x38, 0x80, 0xff, 0xff, 0xff, 0xff, 0xff, 0x3f, 0x83, 0xe8, 0xff, 0x03, 0xc0, 0xf1, 0xf9, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xf1, 0xc1, 0xf3, 0xe3, 0xff, 0xff, 0xf0, 0xc3, 0x9f, 0x3f, 0x7f, 0xfe,
	0xbc, 0x38, 0x78, 0xf9, 0xf1, 0xf9, 0xf0, 0xe1, 0xc1, 0x93, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xfe, 0xfc, 0xfc, 0xfd, 0xfc, 0xfc, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0x7f, 0x7f, 0x7f, 0x3f, 0x1f, 0x1f, 0x0f, 0x03, 0x00, 0x90, 0x91, 0x83, 0xe0, 0xfc, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x9f, 0x09, 0x09, 0x20, 0x0e, 0x1f, 0x3f,
	0x7f, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf9, 0xfb, 0xfb, 0xfb,
	0xf9, 0xfb, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x07, 0x87, 0xc1, 0xe4,
	0xe6, 0xe7, 0xe3, 0xe3, 0x73, 0x79, 0xfc, 0xfe, 0xff, 0x3f, 0x8f, 0xe0, 0x7f, 0x7f, 0xef, 0xff
};

// 'function128x32', 128x32px
static const char oled_e [] PROGMEM = {
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x3f,
	0xff, 0xff, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x7f, 0x7f, 0x7f, 0x0f,
	0x07, 0x84, 0xc0, 0xf0, 0x38, 0xc4, 0xf2, 0xfa, 0xf8, 0xff, 0x7f, 0x0f, 0xe3, 0xfc, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0x07, 0x1f, 0xff, 0xff, 0xff, 0xf9, 0xf1, 0x62, 0x0e, 0xfc, 0xf8, 0xf8,
	0xf0, 0xf3, 0x27, 0x0f, 0x1f, 0x1f, 0x3f, 0x7f, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xd8,
	0xff, 0xff, 0xd8, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0xc0, 0x00, 0x00, 0x80, 0x00, 0xe0,
	0xfc, 0xff, 0xff, 0x3f, 0x10, 0x17, 0xf7, 0x07, 0x03, 0x03, 0x00, 0x08, 0x83, 0x83, 0x3f, 0x7f,
	0xff, 0x3f, 0x03, 0x90, 0x18, 0x1e, 0x18, 0x13, 0x01, 0x01, 0x00, 0x00, 0x00, 0x63, 0xff, 0xff,
	0xff, 0xff, 0x00, 0x00, 0x00, 0xc0, 0xe0, 0xf0, 0xfc, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x1e, 0x07, 0x00, 0x0f,
	0x1f, 0x7f, 0xff, 0x80, 0x0c, 0x7e, 0xf0, 0xc0, 0xc0, 0xce, 0xc0, 0xc0, 0xff, 0xff, 0xff, 0xfe,
	0xfc, 0xfc, 0xfc, 0xf0, 0xc0, 0xc0, 0xc7, 0xc6, 0x40, 0x00, 0x1f, 0x43, 0xf0, 0x7f, 0x3f, 0x9f,
	0x87, 0x03, 0x00, 0xc0, 0xc0, 0x01, 0x03, 0xe7, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xfe, 0xfe, 0xfc, 0xff,
	0x00, 0x00, 0xfc, 0xfc, 0xf8, 0xf0, 0xc7, 0x07, 0x07, 0x0f, 0x0f, 0x0f, 0x0f, 0x09, 0x0a, 0x0a,
	0x0a, 0x09, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x47, 0x06, 0x00, 0x00, 0x30, 0xf0, 0xfc, 0xfe, 0xff,
	0xff, 0x00, 0xf7, 0x00, 0xc3, 0x8f, 0x3f, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff
};

// 'function128x32', 128x32px
static const char oled_f [] PROGMEM = {
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x3f, 0x8f, 0xe7,
	0xf3, 0xf9, 0xfd, 0xfc, 0xfe, 0xfe, 0xfd, 0xfd, 0xf9, 0xfb, 0xfb, 0xf3, 0xf3, 0xf3, 0xf3, 0xf3,
	0xf7, 0xf7, 0xf7, 0xf7, 0xf7, 0xf7, 0xef, 0xcf, 0xcf, 0xdf, 0x9f, 0x1f, 0x5f, 0xdf, 0xbf, 0xbf,
	0x7f, 0x7f, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xbf, 0xbf, 0xbf, 0x3f, 0x3f, 0x4f, 0xe7, 0xf1, 0xfc, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xfb, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe7, 0xef, 0xef, 0x07,
	0xf3, 0x03, 0xcf, 0xdf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xfe, 0xfe, 0xfe,
	0xfe, 0xfc, 0xfc, 0xfc, 0xf8, 0x01, 0x1b, 0xf7, 0xef, 0xdf, 0xbf, 0x7f, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0x7f, 0x3f, 0x9f, 0xcf, 0xe7, 0xf3, 0xf0, 0xf7, 0xf7, 0xf7, 0xf7, 0xf7, 0xf7, 0xf7,
	0xf7, 0x77, 0x37, 0xb3, 0x13, 0x03, 0xb1, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0,
	0x1f, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xbf, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xb0, 0x06, 0xb7, 0x37, 0x7f, 0xff, 0xfe, 0xfd, 0xf3, 0x87, 0x37,
	0xf7, 0xf7, 0xf7, 0xf7, 0xf7, 0xf7, 0xf7, 0xf7, 0xf7, 0xf7, 0xf7, 0xf7, 0xf7, 0xf7, 0xf7, 0xf7,
	0xf7, 0xf7, 0xf7, 0xf7, 0xf7, 0xf7, 0xf7, 0xf7, 0xf7, 0xf7, 0xf7, 0xf7, 0xf7, 0xf7, 0xf7, 0xf7,
	0xf7, 0xf7, 0xf7, 0xf7, 0xf7, 0xf7, 0xf7, 0xf7, 0xf7, 0xf7, 0xf7, 0xf7, 0xf7, 0xf7, 0xf7, 0xf3,
	0xf1, 0xf4, 0xf6, 0xf7, 0xf7, 0xf7, 0xf7, 0xf7, 0xf7, 0xf7, 0xf7, 0xf7, 0xf7, 0xf7, 0xf7, 0xf7,
	0xf7, 0xf7, 0xf7, 0xf5, 0xf0, 0xf3, 0xf7, 0xf7, 0xf7, 0xf7, 0xf7, 0xf7, 0xf7, 0xf7, 0xf7, 0xf7,
	0xf7, 0xf7, 0xf7, 0xf7, 0xf7, 0xf7, 0xf7, 0xf7, 0xf7, 0xf7, 0xf7, 0xf7, 0xf7, 0xf7, 0xf7, 0xf7,
	0xf6, 0xf6, 0xf7, 0xf7, 0xf7, 0xf7, 0xf7, 0xf7, 0xf7, 0xf7, 0xf7, 0xf7, 0xf7, 0xf7, 0xf7, 0xf7,
	0xf7, 0xf7, 0xf7, 0xf7, 0xf7, 0xf1, 0xf2, 0xf3, 0xf3, 0xf3, 0xf3, 0xf3, 0xf3, 0xf7, 0xf7, 0xf0,
	0xf1, 0xf7, 0xf7, 0xf7, 0xf7, 0xf7, 0xf7, 0xf7, 0xf7, 0xf7, 0xf7, 0xf7, 0xf7, 0xf7, 0xf7, 0xf7,
	0xf7, 0xf7, 0xf7, 0xf7, 0xf7, 0xf7, 0xf7, 0xf7, 0xf7, 0xf7, 0xf7, 0xf7, 0xf7, 0xf7, 0xf7, 0xf7
};

// 'function128x32', 128x32px
static const char oled_g [] PROGMEM = {
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x1f, 0x87, 0xf8, 0xff, 0xff, 0xff, 0xff, 0xff,
	0x0f, 0xff, 0x03, 0xf0, 0xff, 0xff, 0xff, 0xff, 0x1f, 0xc7, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0x3f, 0x81, 0x8f, 0x6f, 0xe7, 0xf3, 0x18, 0xf8, 0xe3, 0x8f, 0x3f, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xfc, 0xf9, 0xfb, 0xfb, 0xf7, 0xff, 0xff, 0xff, 0xff, 0x9f,
	0x3c, 0xf0, 0x87, 0x3d, 0xf9, 0xf3, 0xcf, 0x9f, 0x3d, 0x63, 0x4f, 0xdf, 0x7f, 0xff, 0x1f, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x87, 0x1f, 0xfc, 0xe0, 0x00, 0x7f,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x1f, 0x01, 0xf8, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x00,
	0x8f, 0xf1, 0xfe, 0xff, 0x7f, 0x3f, 0x9f, 0x1f, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0x5f, 0x00, 0xff, 0xff, 0xfc, 0xf9, 0xff, 0xc0, 0x7f, 0xff, 0xff, 0xfe, 0x58, 0x73, 0x47, 0xcc,
	0x99, 0x3b, 0xf7, 0xe7, 0xef, 0xcf, 0xdf, 0x9f, 0xbf, 0x3f, 0x7f, 0xff, 0xff, 0xff, 0xfb, 0xc3,
	0x8e, 0xfe, 0xcd, 0x85, 0x81, 0x87, 0x83, 0x83, 0x83, 0x86, 0x86, 0x87, 0x87, 0xc0, 0xc0, 0x07,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x00, 0x07, 0x0f, 0x10,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0x0f, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0xfe,
	0xff, 0xff, 0x81, 0x80, 0xc2, 0xe7, 0xf7, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0x12, 0x00, 0xcf, 0xc7, 0xc3, 0xc3, 0xe3, 0xe1, 0xe0, 0xf0, 0xf0, 0xf0, 0xf8, 0xf8, 0xf8, 0xfd,
	0xff, 0xff, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xfe, 0xfe,
	0xfe, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0xff, 0x7f, 0x7f, 0x18, 0x00,
	0x7f, 0x1f, 0xc7, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0xfe,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0x7f, 0x00, 0xf8, 0x08, 0x99, 0xff, 0xff, 0x87, 0xff, 0x01, 0x40, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xe7, 0xcf, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0x00, 0x00, 0xff, 0xf3, 0xf9, 0xff, 0xf1, 0xf9, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0x87, 0x03, 0x7b, 0xfb, 0xfb, 0xfb, 0xfb, 0xf3, 0x37, 0x87, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xfe, 0xff, 0xfe, 0xff, 0xf0, 0xf8,
	0xfe, 0x00, 0xff, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff
};

// 'function128x32', 128x32px
static const char oled_h [] PROGMEM = {
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x03, 0x80, 0xff, 0xff, 0xff, 0xff, 0xc3,
	0x00, 0x00, 0xfc, 0xff, 0x00, 0x00, 0xff, 0x03, 0xf1, 0x7e, 0x5a, 0x66, 0x18, 0x00, 0x86, 0xcb,
	0xcc, 0xc3, 0xc9, 0xcd, 0xc7, 0xc3, 0xc1, 0xe4, 0xe3, 0xe5, 0xc6, 0x81, 0xc8, 0x86, 0x01, 0x83,
	0x89, 0x2c, 0x1f, 0x0f, 0x03, 0x30, 0x1e, 0x03, 0x70, 0x9f, 0xe0, 0xfe, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x3f, 0x00, 0x00, 0xe1, 0xff, 0xff, 0x1f, 0xff, 0xfc,
	0x00, 0x00, 0xff, 0xff, 0x00, 0xe2, 0xcc, 0x88, 0x39, 0x01, 0x84, 0x3e, 0x7e, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xfc, 0xf9, 0xf3, 0xf3, 0xf3, 0xf9, 0xff, 0xff, 0xff, 0xdf, 0x9f, 0xb7,
	0x37, 0x1f, 0x9e, 0xcc, 0xc0, 0xe0, 0xf0, 0xf8, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0x8e, 0x30, 0x40, 0x1f, 0xff, 0xff, 0xf8, 0xc7,
	0x1e, 0x60, 0x87, 0x1f, 0x00, 0xdf, 0xef, 0xf3, 0xf9, 0xfe, 0xff, 0xff, 0xfc, 0xf9, 0xf3, 0xe7,
	0xcf, 0x9f, 0x3f, 0x7f, 0x7f, 0xff, 0xff, 0x5f, 0x4f, 0x7f, 0x7f, 0x3f, 0xbf, 0x1f, 0xcf, 0x73,
	0x19, 0xc4, 0xff, 0xff, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0x3f, 0x1f, 0x8f, 0xe7, 0xe3, 0xe1, 0xe0, 0xe0, 0x60, 0xc1, 0xc1, 0x81,
	0x03, 0x02, 0x01, 0x07, 0x0c, 0x30, 0xe1, 0x83, 0x07, 0x0f, 0x0f, 0x3f, 0xff, 0xff, 0xff, 0xff,
	0xc7, 0x81, 0x84, 0x0a, 0x12, 0x02, 0x0e, 0x7e, 0xfe, 0xc7, 0x07, 0x21, 0x98, 0xe6, 0xf3, 0xfc,
	0xff, 0xff, 0xff, 0xff, 0xfe, 0xfc, 0xf9, 0xfb, 0xf7, 0xf7, 0xff, 0x3f, 0x7f, 0x7b, 0x7b, 0x73,
	0x27, 0x8f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff
};

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
 return OLED_ROTATION_180;
}
void oled_task_user(void) {
    switch (get_highest_layer(layer_state)) {
        case 0:
			oled_write_raw_P(oled_a,1024);
            break;
        case 1:
			oled_write_raw_P(oled_b,1024);
            break;
        case 2:
			oled_write_raw_P(oled_c,1024);
            break;
        case 3:
			oled_write_raw_P(oled_d,1024);
            break;
        case 4:
			oled_write_raw_P(oled_e,1024);
            break;
        case 5:
			oled_write_raw_P(oled_f,1024);
            break;
        case 6:
			oled_write_raw_P(oled_g,1024);
            break;
        case 7:
			oled_write_raw_P(oled_h,1024);
            break;
    }
}
#endif

