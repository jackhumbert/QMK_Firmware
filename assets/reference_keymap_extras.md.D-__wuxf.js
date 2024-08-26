import { _ as _export_sfc, c as createElementBlock, o as openBlock, a8 as createStaticVNode } from "./chunks/framework.DyMmIvSC.js";
const __pageData = JSON.parse('{"title":"Language-specific Keycodes","description":"","frontmatter":{},"headers":[],"relativePath":"reference_keymap_extras.md","filePath":"reference_keymap_extras.md"}');
const _sfc_main = { name: "reference_keymap_extras.md" };
const _hoisted_1 = /* @__PURE__ */ createStaticVNode('<h1 id="language-specific-keycodes" tabindex="-1">Language-specific Keycodes <a class="header-anchor" href="#language-specific-keycodes" aria-label="Permalink to &quot;Language-specific Keycodes&quot;">​</a></h1><p>Keyboards are able to support a wide range of languages. However, this support is not actually achieved within the keyboard itself - instead, it sends numerical codes, which the operating system maps to the appropriate characters depending on the user&#39;s configured keyboard layout. By default (and per the HID spec), this is the US ANSI layout. For example, when a Swedish person presses the key with the <code>å</code> character printed on it, the keyboard is <em>actually</em> sending the keycode for <code>[</code>.</p><p>Obviously, this can get confusing, so QMK provides language-specific keycode aliases for many keyboard layouts. These won&#39;t do much on their own - you still have to set the matching keyboard layout in your OS settings. Think of them more as keycap labels for your keymap.</p><p>Simply <code>#include</code> one of the keycode headers below at the top of your <code>keymap.c</code>, and assign the keycodes defined in the header in place of the <code>KC_</code> prefixed ones.</p><h2 id="sendstring-support" tabindex="-1">Sendstring Support <a class="header-anchor" href="#sendstring-support" aria-label="Permalink to &quot;Sendstring Support&quot;">​</a></h2><p>By default, <code>SEND_STRING()</code> assumes a US ANSI keyboard layout is set. If you are using a different layout, you can include one of the Sendstring LUT headers below in your <code>keymap.c</code> to override the lookup tables used for mapping ASCII characters to keycodes. You do not need to include the corresponding <code>keymap_*.h</code> header, as it is implicit when including the Sendstring header.</p><p>An important thing to note here is that <code>SEND_STRING()</code> only operates on <a href="https://en.wikipedia.org/wiki/ASCII#Character_set" target="_blank" rel="noreferrer">ASCII text</a>. This means that you cannot pass it a string containing Unicode characters - this unfortunately includes accented characters that may be present in your desired layout.<br> Many layouts make certain characters, such as Grave or Tilde, available only as <a href="https://en.wikipedia.org/wiki/Dead_key" target="_blank" rel="noreferrer">dead keys</a>, so you must add a space immediately after it in the string you want to send, to prevent it from potentially combining with the next character.<br> Certain other layouts have no Sendstring header as they do not use a Latin-derived alphabet (for example Greek and Russian), and thus there is no way to input most of the ASCII character set.</p><h2 id="header-files" tabindex="-1">Header Files <a class="header-anchor" href="#header-files" aria-label="Permalink to &quot;Header Files&quot;">​</a></h2><p>These headers are located in <a href="https://github.com/qmk/qmk_firmware/tree/master/quantum/keymap_extras" target="_blank" rel="noreferrer"><code>quantum/keymap_extras/</code></a>.</p><table><thead><tr><th>Layout</th><th>Keycodes Header</th><th>Sendstring LUT Header</th></tr></thead><tbody><tr><td>Canadian Multilingual (CSA)</td><td><code>keymap_canadian_multilingual.h</code></td><td><code>sendstring_canadian_multilingual.h</code></td></tr><tr><td>Croatian</td><td><code>keymap_croatian.h</code></td><td><code>sendstring_croatian.h</code></td></tr><tr><td>Czech</td><td><code>keymap_czech.h</code></td><td><code>sendstring_czech.h</code></td></tr><tr><td>Czech (macOS, ANSI)</td><td><code>keymap_czech_mac_ansi.h</code></td><td><code>sendstring_czech_mac_ansi.h</code></td></tr><tr><td>Czech (macOS, ISO)</td><td><code>keymap_czech_mac_iso.h</code></td><td><code>sendstring_czech_mac_iso.h</code></td></tr><tr><td>Danish</td><td><code>keymap_danish.h</code></td><td><code>sendstring_danish.h</code></td></tr><tr><td>Dutch (Belgium)</td><td><code>keymap_belgian.h</code></td><td><code>sendstring_belgian.h</code></td></tr><tr><td>English (Ireland)</td><td><code>keymap_irish.h</code></td><td></td></tr><tr><td>English (UK)</td><td><code>keymap_uk.h</code></td><td><code>sendstring_uk.h</code></td></tr><tr><td>English (US Extended)</td><td><code>keymap_us_extended.h</code></td><td></td></tr><tr><td>English (US International)</td><td><code>keymap_us_international.h</code></td><td><code>sendstring_us_international.h</code></td></tr><tr><td>English (US International, Linux)</td><td><code>keymap_us_international_linux.h</code></td><td></td></tr><tr><td>Estonian</td><td><code>keymap_estonian.h</code></td><td><code>sendstring_estonian.h</code></td></tr><tr><td>Farsi</td><td><code>keymap_farsi.h</code></td><td></td></tr><tr><td>Finnish</td><td><code>keymap_finnish.h</code></td><td><code>sendstring_finnish.h</code></td></tr><tr><td>French</td><td><code>keymap_french.h</code></td><td><code>sendstring_french.h</code></td></tr><tr><td>French (AFNOR)</td><td><code>keymap_french_afnor.h</code></td><td><code>sendstring_french_afnor.h</code></td></tr><tr><td>French (BÉPO)</td><td><code>keymap_bepo.h</code></td><td><code>sendstring_bepo.h</code></td></tr><tr><td>French (Belgium)</td><td><code>keymap_belgian.h</code></td><td><code>sendstring_belgian.h</code></td></tr><tr><td>French (Canada)</td><td><code>keymap_canadian_french.h</code></td><td><code>sendstring_canadian_french.h</code></td></tr><tr><td>French (Switzerland)</td><td><code>keymap_swiss_fr.h</code></td><td><code>sendstring_swiss_fr.h</code></td></tr><tr><td>French (macOS, ISO)</td><td><code>keymap_french_mac_iso.h</code></td><td><code>sendstring_french_mac_iso.h</code></td></tr><tr><td>German</td><td><code>keymap_german.h</code></td><td><code>sendstring_german.h</code></td></tr><tr><td>German (Switzerland)</td><td><code>keymap_swiss_de.h</code></td><td><code>sendstring_swiss_de.h</code></td></tr><tr><td>German (macOS)</td><td><code>keymap_german_mac_iso.h</code></td><td><code>sendstring_german_mac_iso.h</code></td></tr><tr><td>German (Neo2)</td><td><code>keymap_neo2.h</code></td><td></td></tr><tr><td>Greek</td><td><code>keymap_greek.h</code></td><td></td></tr><tr><td>Hebrew</td><td><code>keymap_hebrew.h</code></td><td></td></tr><tr><td>Hungarian</td><td><code>keymap_hungarian.h</code></td><td><code>sendstring_hungarian.h</code></td></tr><tr><td>Icelandic</td><td><code>keymap_icelandic.h</code></td><td><code>sendstring_icelandic.h</code></td></tr><tr><td>Italian</td><td><code>keymap_italian.h</code></td><td><code>sendstring_italian.h</code></td></tr><tr><td>Italian (macOS, ANSI)</td><td><code>keymap_italian_mac_ansi.h</code></td><td><code>sendstring_italian_mac_ansi.h</code></td></tr><tr><td>Italian (macOS, ISO)</td><td><code>keymap_italian_mac_iso.h</code></td><td><code>sendstring_italian_mac_iso.h</code></td></tr><tr><td>Japanese</td><td><code>keymap_japanese.h</code></td><td><code>sendstring_japanese.h</code></td></tr><tr><td>Korean</td><td><code>keymap_korean.h</code></td><td></td></tr><tr><td>Latvian</td><td><code>keymap_latvian.h</code></td><td><code>sendstring_latvian.h</code></td></tr><tr><td>Lithuanian (ĄŽERTY)</td><td><code>keymap_lithuanian_azerty.h</code></td><td><code>sendstring_lithuanian_azerty.h</code></td></tr><tr><td>Lithuanian (QWERTY)</td><td><code>keymap_lithuanian_qwerty.h</code></td><td><code>sendstring_lithuanian_qwerty.h</code></td></tr><tr><td>Norwegian</td><td><code>keymap_norwegian.h</code></td><td><code>sendstring_norwegian.h</code></td></tr><tr><td>Polish</td><td><code>keymap_polish.h</code></td><td></td></tr><tr><td>Portuguese</td><td><code>keymap_portuguese.h</code></td><td><code>sendstring_portuguese.h</code></td></tr><tr><td>Portuguese (macOS, ISO)</td><td><code>keymap_portuguese_mac_iso.h</code></td><td><code>sendstring_portuguese_mac_iso.h</code></td></tr><tr><td>Portuguese (Brazil)</td><td><code>keymap_brazilian_abnt2.h</code></td><td><code>sendstring_brazilian_abnt2.h</code></td></tr><tr><td>Romanian</td><td><code>keymap_romanian.h</code></td><td><code>sendstring_romanian.h</code></td></tr><tr><td>Russian</td><td><code>keymap_russian.h</code></td><td></td></tr><tr><td>Serbian</td><td><code>keymap_serbian.h</code></td><td></td></tr><tr><td>Serbian (Latin)</td><td><code>keymap_serbian_latin.h</code></td><td><code>sendstring_serbian_latin.h</code></td></tr><tr><td>Slovak</td><td><code>keymap_slovak.h</code></td><td><code>sendstring_slovak.h</code></td></tr><tr><td>Slovenian</td><td><code>keymap_slovenian.h</code></td><td><code>sendstring_slovenian.h</code></td></tr><tr><td>Spanish</td><td><code>keymap_spanish.h</code></td><td><code>sendstring_spanish.h</code></td></tr><tr><td>Spanish (Dvorak)</td><td><code>keymap_spanish_dvorak.h</code></td><td><code>sendstring_spanish_dvorak.h</code></td></tr><tr><td>Spanish (Latin America)</td><td><code>keymap_spanish_latin_america.h</code></td><td><code>sendstring_spanish_latin_america.h</code></td></tr><tr><td>Swedish</td><td><code>keymap_swedish.h</code></td><td><code>sendstring_swedish.h</code></td></tr><tr><td>Swedish (macOS, ANSI)</td><td><code>keymap_swedish_mac_ansi.h</code></td><td></td></tr><tr><td>Swedish (macOS, ISO)</td><td><code>keymap_swedish_mac_iso.h</code></td><td></td></tr><tr><td>Swedish Pro (macOS, ANSI)</td><td><code>keymap_swedish_pro_mac_ansi.h</code></td><td></td></tr><tr><td>Swedish Pro (macOS, ISO)</td><td><code>keymap_swedish_pro_mac_iso.h</code></td><td></td></tr><tr><td>Turkish (F)</td><td><code>keymap_turkish_f.h</code></td><td><code>sendstring_turkish_f.h</code></td></tr><tr><td>Turkish (Q)</td><td><code>keymap_turkish_q.h</code></td><td><code>sendstring_turkish_q.h</code></td></tr><tr><td>Ukrainian</td><td><code>keymap_ukrainian.h</code></td><td></td></tr></tbody></table><p>There are also a few which are not quite language-specific, but useful if you are not using a QWERTY layout:</p><table><thead><tr><th>Layout</th><th>Keycodes Header</th><th>Sendstring LUT Header</th></tr></thead><tbody><tr><td>Colemak</td><td><code>keymap_colemak.h</code></td><td><code>sendstring_colemak.h</code></td></tr><tr><td>Dvorak</td><td><code>keymap_dvorak.h</code></td><td><code>sendstring_dvorak.h</code></td></tr><tr><td>Dvorak (French)</td><td><code>keymap_dvorak_fr.h</code></td><td><code>sendstring_dvorak_fr.h</code></td></tr><tr><td>Dvorak (Programmer)</td><td><code>keymap_dvorak_programmer.h</code></td><td><code>sendstring_dvorak_programmer.h</code></td></tr><tr><td>Norman</td><td><code>keymap_norman.h</code></td><td><code>sendstring_norman.h</code></td></tr><tr><td>Plover</td><td><code>keymap_plover.h</code></td><td></td></tr><tr><td>Plover (Dvorak)</td><td><code>keymap_plover_dvorak.h</code></td><td></td></tr><tr><td>Workman</td><td><code>keymap_workman.h</code></td><td><code>sendstring_workman.h</code></td></tr><tr><td>Workman (ZXCVM)</td><td><code>keymap_workman_zxcvm.h</code></td><td><code>sendstring_workman_zxcvm.h</code></td></tr></tbody></table>', 12);
const _hoisted_13 = [
  _hoisted_1
];
function _sfc_render(_ctx, _cache, $props, $setup, $data, $options) {
  return openBlock(), createElementBlock("div", null, _hoisted_13);
}
const reference_keymap_extras = /* @__PURE__ */ _export_sfc(_sfc_main, [["render", _sfc_render]]);
export {
  __pageData,
  reference_keymap_extras as default
};
