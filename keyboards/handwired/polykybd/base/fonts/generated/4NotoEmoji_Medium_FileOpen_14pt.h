// fontconvert -f~/repos/Noto_Emoji/static/NotoEmoji-Medium.ttf -s14 -r50 -v _FileOpen_ -n0x11000 0x1F4C2 0x1F4C2 
// Visualize your font via https://tchapi.github.io/Adafruit-GFX-Font-Customiser

const uint8_t NotoEmoji_Medium_FileOpen_14pt16bBitmaps[] PROGMEM = {
  0x07, 0xC0, 0x03, 0x00, 0x78, 0x81, 0xFE, 0x00, 0x81, 0xFF, 0x04, 0x02,
  0x03, 0x80, 0x08, 0x0C, 0x00, 0x00, 0x10, 0x10, 0x00, 0x00, 0x20, 0x20,
  0x00, 0x00, 0x47, 0xC0, 0x00, 0x03, 0xFB, 0x80, 0x01, 0xFC, 0x05, 0x00,
  0x06, 0x00, 0x1A, 0x00, 0x08, 0x00, 0x24, 0x00, 0x10, 0x00, 0x48, 0x01,
  0xE0, 0x01, 0x90, 0x3E, 0x00, 0x02, 0x20, 0x80, 0x00, 0x0C, 0x41, 0x00,
  0x00, 0x10, 0x84, 0x00, 0x00, 0x61, 0x08, 0x00, 0x00, 0x82, 0x20, 0x00,
  0x01, 0x04, 0x40, 0x00, 0x06, 0x09, 0x00, 0x00, 0x08, 0x12, 0x00, 0x01,
  0xF0, 0x28, 0x00, 0x3E, 0x00, 0x50, 0x07, 0xC0, 0x00, 0xC1, 0xF8, 0x00,
  0x01, 0xBF, 0x00, 0x00, 0x03, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00 };

const GFXglyph NotoEmoji_Medium_FileOpen_14pt16bGlyphs[] PROGMEM = {
// bmpOff,   w,   h,xAdv, xOff, yOff      range 0 (0x1f4c2 - 0x1f4c2)
  {     0,  31,  28,  35,    2,  -22 } }; // 0x1F4C2 u1F4C2  (#0)

const GFXfont NotoEmoji_Medium_FileOpen_14pt16b PROGMEM = {
  (uint8_t  *)NotoEmoji_Medium_FileOpen_14pt16bBitmaps,
  (GFXglyph *)NotoEmoji_Medium_FileOpen_14pt16bGlyphs,
  0xE4C2, // first
  0xE4C2, // last
  50   //height
 };

// Approx. 123 bytes
