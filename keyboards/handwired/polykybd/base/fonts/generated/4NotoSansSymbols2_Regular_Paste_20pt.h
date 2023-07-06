// fontconvert -f~/repos/Noto_Sans_Symbols_2/NotoSansSymbols2-Regular.ttf -s20 -r50 -v _ClipPaste_ -n0x11000 0x1F5CA 0x1F5CA 
// Visualize your font via https://tchapi.github.io/Adafruit-GFX-Font-Customiser

const uint8_t NotoSansSymbols2_Regular_ClipPaste_20pt16bBitmaps[] PROGMEM = {
  0x00, 0xFF, 0xFF, 0xFF, 0x00, 0x80, 0x00, 0x01, 0x00, 0x80, 0x00, 0x01,
  0x00, 0x80, 0x00, 0x01, 0x0F, 0xFF, 0xFF, 0xF1, 0x08, 0x00, 0x00, 0x11,
  0x08, 0x00, 0x00, 0x11, 0x08, 0x00, 0x00, 0x11, 0xFF, 0xFF, 0xFF, 0x91,
  0x80, 0x00, 0x00, 0x91, 0x80, 0x00, 0x00, 0x91, 0x80, 0x00, 0x00, 0x91,
  0x80, 0x00, 0x00, 0x91, 0x83, 0xFE, 0x00, 0x91, 0x80, 0x00, 0x00, 0x91,
  0x80, 0x00, 0x00, 0x91, 0x80, 0x00, 0x00, 0x91, 0x83, 0xFF, 0x00, 0x91,
  0x80, 0x00, 0x00, 0x91, 0x80, 0x00, 0x00, 0x91, 0x80, 0x00, 0x00, 0x91,
  0x83, 0xFE, 0x00, 0x91, 0x80, 0x00, 0x00, 0x91, 0x80, 0x00, 0x00, 0x91,
  0x80, 0x00, 0x00, 0x9F, 0x80, 0x00, 0x00, 0x90, 0x83, 0xFF, 0x00, 0x90,
  0x80, 0x00, 0x00, 0x90, 0x80, 0x00, 0x00, 0xF0, 0x80, 0x00, 0x00, 0x80,
  0x80, 0x00, 0x00, 0x80, 0x80, 0x00, 0x00, 0x80, 0xFF, 0xFF, 0xFF, 0x80 };

const GFXglyph NotoSansSymbols2_Regular_ClipPaste_20pt16bGlyphs[] PROGMEM = {
// bmpOff,   w,   h,xAdv, xOff, yOff      range 0 (0x1f5ca - 0x1f5ca)
  {     0,  32,  33,  36,    2,  -29 } }; // 0x1F5CA u1F5CA  (#0)

const GFXfont NotoSansSymbols2_Regular_ClipPaste_20pt16b PROGMEM = {
  (uint8_t  *)NotoSansSymbols2_Regular_ClipPaste_20pt16bBitmaps,
  (GFXglyph *)NotoSansSymbols2_Regular_ClipPaste_20pt16bGlyphs,
  0xE5CA, // first
  0xE5CA, // last
  50   //height
 };

// Approx. 146 bytes
