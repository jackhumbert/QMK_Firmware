import { _ as _export_sfc, c as createElementBlock, o as openBlock, a8 as createStaticVNode } from "./chunks/framework.DyMmIvSC.js";
const __pageData = JSON.parse('{"title":"Encoders","description":"","frontmatter":{},"headers":[],"relativePath":"features/encoders.md","filePath":"features/encoders.md"}');
const _sfc_main = { name: "features/encoders.md" };
const _hoisted_1 = /* @__PURE__ */ createStaticVNode('<h1 id="encoders" tabindex="-1">Encoders <a class="header-anchor" href="#encoders" aria-label="Permalink to &quot;Encoders&quot;">​</a></h1><p>Basic (EC11 compatible) encoders are supported by adding this to your <code>rules.mk</code>:</p><div class="language-make vp-adaptive-theme"><button title="Copy Code" class="copy"></button><span class="lang">make</span><pre class="shiki shiki-themes github-light github-dark vp-code"><code><span class="line"><span style="--shiki-light:#24292E;--shiki-dark:#E1E4E8;">ENCODER_ENABLE = yes</span></span></code></pre></div><p>and this to your <code>config.h</code>:</p><div class="language-c vp-adaptive-theme"><button title="Copy Code" class="copy"></button><span class="lang">c</span><pre class="shiki shiki-themes github-light github-dark vp-code"><code><span class="line"><span style="--shiki-light:#D73A49;--shiki-dark:#F97583;">#define</span><span style="--shiki-light:#6F42C1;--shiki-dark:#B392F0;"> ENCODER_A_PINS</span><span style="--shiki-light:#24292E;--shiki-dark:#E1E4E8;"> { B12 }</span></span>\n<span class="line"><span style="--shiki-light:#D73A49;--shiki-dark:#F97583;">#define</span><span style="--shiki-light:#6F42C1;--shiki-dark:#B392F0;"> ENCODER_B_PINS</span><span style="--shiki-light:#24292E;--shiki-dark:#E1E4E8;"> { B13 }</span></span></code></pre></div><p>Each PAD_A/B variable defines an array so multiple encoders can be defined, e.g.:</p><div class="language-c vp-adaptive-theme"><button title="Copy Code" class="copy"></button><span class="lang">c</span><pre class="shiki shiki-themes github-light github-dark vp-code"><code><span class="line"><span style="--shiki-light:#D73A49;--shiki-dark:#F97583;">#define</span><span style="--shiki-light:#6F42C1;--shiki-dark:#B392F0;"> ENCODER_A_PINS</span><span style="--shiki-light:#24292E;--shiki-dark:#E1E4E8;"> { encoder1a, encoder2a }</span></span>\n<span class="line"><span style="--shiki-light:#D73A49;--shiki-dark:#F97583;">#define</span><span style="--shiki-light:#6F42C1;--shiki-dark:#B392F0;"> ENCODER_B_PINS</span><span style="--shiki-light:#24292E;--shiki-dark:#E1E4E8;"> { encoder1b, encoder2b }</span></span></code></pre></div><p>If your encoder&#39;s clockwise directions are incorrect, you can swap the A &amp; B pad definitions. They can also be flipped with a define:</p><div class="language-c vp-adaptive-theme"><button title="Copy Code" class="copy"></button><span class="lang">c</span><pre class="shiki shiki-themes github-light github-dark vp-code"><code><span class="line"><span style="--shiki-light:#D73A49;--shiki-dark:#F97583;">#define</span><span style="--shiki-light:#6F42C1;--shiki-dark:#B392F0;"> ENCODER_DIRECTION_FLIP</span></span></code></pre></div><p>Additionally, the resolution, which defines how many pulses the encoder registers between each detent, can be defined with:</p><div class="language-c vp-adaptive-theme"><button title="Copy Code" class="copy"></button><span class="lang">c</span><pre class="shiki shiki-themes github-light github-dark vp-code"><code><span class="line"><span style="--shiki-light:#D73A49;--shiki-dark:#F97583;">#define</span><span style="--shiki-light:#6F42C1;--shiki-dark:#B392F0;"> ENCODER_RESOLUTION</span><span style="--shiki-light:#005CC5;--shiki-dark:#79B8FF;"> 4</span></span></code></pre></div><p>It can also be defined per-encoder, by instead defining:</p><div class="language-c vp-adaptive-theme"><button title="Copy Code" class="copy"></button><span class="lang">c</span><pre class="shiki shiki-themes github-light github-dark vp-code"><code><span class="line"><span style="--shiki-light:#D73A49;--shiki-dark:#F97583;">#define</span><span style="--shiki-light:#6F42C1;--shiki-dark:#B392F0;"> ENCODER_RESOLUTIONS</span><span style="--shiki-light:#24292E;--shiki-dark:#E1E4E8;"> { </span><span style="--shiki-light:#005CC5;--shiki-dark:#79B8FF;">4</span><span style="--shiki-light:#24292E;--shiki-dark:#E1E4E8;">, </span><span style="--shiki-light:#005CC5;--shiki-dark:#79B8FF;">2</span><span style="--shiki-light:#24292E;--shiki-dark:#E1E4E8;"> }</span></span></code></pre></div><p>For 4× encoders you also can assign default position if encoder skips pulses when it changes direction. For example, if your encoder send high level on both pins by default, define this:</p><div class="language-c vp-adaptive-theme"><button title="Copy Code" class="copy"></button><span class="lang">c</span><pre class="shiki shiki-themes github-light github-dark vp-code"><code><span class="line"><span style="--shiki-light:#D73A49;--shiki-dark:#F97583;">#define</span><span style="--shiki-light:#6F42C1;--shiki-dark:#B392F0;"> ENCODER_DEFAULT_POS</span><span style="--shiki-light:#D73A49;--shiki-dark:#F97583;"> 0x</span><span style="--shiki-light:#005CC5;--shiki-dark:#79B8FF;">3</span></span></code></pre></div><h2 id="split-keyboards" tabindex="-1">Split Keyboards <a class="header-anchor" href="#split-keyboards" aria-label="Permalink to &quot;Split Keyboards&quot;">​</a></h2><p>If you are using different pinouts for the encoders on each half of a split keyboard, you can define the pinout (and optionally, resolutions) for the right half like this:</p><div class="language-c vp-adaptive-theme"><button title="Copy Code" class="copy"></button><span class="lang">c</span><pre class="shiki shiki-themes github-light github-dark vp-code"><code><span class="line"><span style="--shiki-light:#D73A49;--shiki-dark:#F97583;">#define</span><span style="--shiki-light:#6F42C1;--shiki-dark:#B392F0;"> ENCODER_A_PINS_RIGHT</span><span style="--shiki-light:#24292E;--shiki-dark:#E1E4E8;"> { encoder1a, encoder2a }</span></span>\n<span class="line"><span style="--shiki-light:#D73A49;--shiki-dark:#F97583;">#define</span><span style="--shiki-light:#6F42C1;--shiki-dark:#B392F0;"> ENCODER_B_PINS_RIGHT</span><span style="--shiki-light:#24292E;--shiki-dark:#E1E4E8;"> { encoder1b, encoder2b }</span></span>\n<span class="line"><span style="--shiki-light:#D73A49;--shiki-dark:#F97583;">#define</span><span style="--shiki-light:#6F42C1;--shiki-dark:#B392F0;"> ENCODER_RESOLUTIONS_RIGHT</span><span style="--shiki-light:#24292E;--shiki-dark:#E1E4E8;"> { </span><span style="--shiki-light:#005CC5;--shiki-dark:#79B8FF;">2</span><span style="--shiki-light:#24292E;--shiki-dark:#E1E4E8;">, </span><span style="--shiki-light:#005CC5;--shiki-dark:#79B8FF;">4</span><span style="--shiki-light:#24292E;--shiki-dark:#E1E4E8;"> }</span></span></code></pre></div><p>If the <code>_RIGHT</code> definitions aren&#39;t specified in your <code>config.h</code>, then the non-<code>_RIGHT</code> versions will be applied to both sides of the split.</p><p>Additionally, if one side does not have an encoder, you can specify <code>{}</code> for the pins/resolution -- for example, a split keyboard with only a right-side encoder:</p><div class="language-c vp-adaptive-theme"><button title="Copy Code" class="copy"></button><span class="lang">c</span><pre class="shiki shiki-themes github-light github-dark vp-code"><code><span class="line"><span style="--shiki-light:#D73A49;--shiki-dark:#F97583;">#define</span><span style="--shiki-light:#6F42C1;--shiki-dark:#B392F0;"> ENCODER_A_PINS</span><span style="--shiki-light:#24292E;--shiki-dark:#E1E4E8;"> { }</span></span>\n<span class="line"><span style="--shiki-light:#D73A49;--shiki-dark:#F97583;">#define</span><span style="--shiki-light:#6F42C1;--shiki-dark:#B392F0;"> ENCODER_B_PINS</span><span style="--shiki-light:#24292E;--shiki-dark:#E1E4E8;"> { }</span></span>\n<span class="line"><span style="--shiki-light:#D73A49;--shiki-dark:#F97583;">#define</span><span style="--shiki-light:#6F42C1;--shiki-dark:#B392F0;"> ENCODER_RESOLUTIONS</span><span style="--shiki-light:#24292E;--shiki-dark:#E1E4E8;"> { }</span></span>\n<span class="line"><span style="--shiki-light:#D73A49;--shiki-dark:#F97583;">#define</span><span style="--shiki-light:#6F42C1;--shiki-dark:#B392F0;"> ENCODER_A_PINS_RIGHT</span><span style="--shiki-light:#24292E;--shiki-dark:#E1E4E8;"> { B12 }</span></span>\n<span class="line"><span style="--shiki-light:#D73A49;--shiki-dark:#F97583;">#define</span><span style="--shiki-light:#6F42C1;--shiki-dark:#B392F0;"> ENCODER_B_PINS_RIGHT</span><span style="--shiki-light:#24292E;--shiki-dark:#E1E4E8;"> { B13 }</span></span>\n<span class="line"><span style="--shiki-light:#D73A49;--shiki-dark:#F97583;">#define</span><span style="--shiki-light:#6F42C1;--shiki-dark:#B392F0;"> ENCODER_RESOLUTIONS_RIGHT</span><span style="--shiki-light:#24292E;--shiki-dark:#E1E4E8;"> { </span><span style="--shiki-light:#005CC5;--shiki-dark:#79B8FF;">4</span><span style="--shiki-light:#24292E;--shiki-dark:#E1E4E8;"> }</span></span></code></pre></div><div class="warning custom-block"><p class="custom-block-title">WARNING</p><p>Keep in mind that whenver you change the encoder resolution, you will need to reflash the half that has the encoder affected by the change.</p></div><h2 id="encoder-map" tabindex="-1">Encoder map <a class="header-anchor" href="#encoder-map" aria-label="Permalink to &quot;Encoder map {#encoder-map}&quot;">​</a></h2><p>Encoder mapping may be added to your <code>keymap.c</code>, which replicates the normal keyswitch layer handling functionality, but with encoders. Add this to your keymap&#39;s <code>rules.mk</code>:</p><div class="language-make vp-adaptive-theme"><button title="Copy Code" class="copy"></button><span class="lang">make</span><pre class="shiki shiki-themes github-light github-dark vp-code"><code><span class="line"><span style="--shiki-light:#24292E;--shiki-dark:#E1E4E8;">ENCODER_MAP_ENABLE = yes</span></span></code></pre></div><p>Your <code>keymap.c</code> will then need an encoder mapping defined (for four layers and two encoders):</p><div class="language-c vp-adaptive-theme"><button title="Copy Code" class="copy"></button><span class="lang">c</span><pre class="shiki shiki-themes github-light github-dark vp-code"><code><span class="line"><span style="--shiki-light:#D73A49;--shiki-dark:#F97583;">#if</span><span style="--shiki-light:#D73A49;--shiki-dark:#F97583;"> defined</span><span style="--shiki-light:#24292E;--shiki-dark:#E1E4E8;">(</span><span style="--shiki-light:#6F42C1;--shiki-dark:#B392F0;">ENCODER_MAP_ENABLE</span><span style="--shiki-light:#24292E;--shiki-dark:#E1E4E8;">)</span></span>\n<span class="line"><span style="--shiki-light:#D73A49;--shiki-dark:#F97583;">const</span><span style="--shiki-light:#D73A49;--shiki-dark:#F97583;"> uint16_t</span><span style="--shiki-light:#24292E;--shiki-dark:#E1E4E8;"> PROGMEM encoder_map</span><span style="--shiki-light:#D73A49;--shiki-dark:#F97583;">[]</span><span style="--shiki-light:#24292E;--shiki-dark:#E1E4E8;">[NUM_ENCODERS][NUM_DIRECTIONS] </span><span style="--shiki-light:#D73A49;--shiki-dark:#F97583;">=</span><span style="--shiki-light:#24292E;--shiki-dark:#E1E4E8;"> {</span></span>\n<span class="line"><span style="--shiki-light:#24292E;--shiki-dark:#E1E4E8;">    [</span><span style="--shiki-light:#005CC5;--shiki-dark:#79B8FF;">0</span><span style="--shiki-light:#24292E;--shiki-dark:#E1E4E8;">] </span><span style="--shiki-light:#D73A49;--shiki-dark:#F97583;">=</span><span style="--shiki-light:#24292E;--shiki-dark:#E1E4E8;"> { </span><span style="--shiki-light:#6F42C1;--shiki-dark:#B392F0;">ENCODER_CCW_CW</span><span style="--shiki-light:#24292E;--shiki-dark:#E1E4E8;">(MS_WHLU, MS_WHLD),  </span><span style="--shiki-light:#6F42C1;--shiki-dark:#B392F0;">ENCODER_CCW_CW</span><span style="--shiki-light:#24292E;--shiki-dark:#E1E4E8;">(KC_VOLD, KC_VOLU)  },</span></span>\n<span class="line"><span style="--shiki-light:#24292E;--shiki-dark:#E1E4E8;">    [</span><span style="--shiki-light:#005CC5;--shiki-dark:#79B8FF;">1</span><span style="--shiki-light:#24292E;--shiki-dark:#E1E4E8;">] </span><span style="--shiki-light:#D73A49;--shiki-dark:#F97583;">=</span><span style="--shiki-light:#24292E;--shiki-dark:#E1E4E8;"> { </span><span style="--shiki-light:#6F42C1;--shiki-dark:#B392F0;">ENCODER_CCW_CW</span><span style="--shiki-light:#24292E;--shiki-dark:#E1E4E8;">(UG_HUED, UG_HUEU),  </span><span style="--shiki-light:#6F42C1;--shiki-dark:#B392F0;">ENCODER_CCW_CW</span><span style="--shiki-light:#24292E;--shiki-dark:#E1E4E8;">(UG_SATD, UG_SATU)  },</span></span>\n<span class="line"><span style="--shiki-light:#24292E;--shiki-dark:#E1E4E8;">    [</span><span style="--shiki-light:#005CC5;--shiki-dark:#79B8FF;">2</span><span style="--shiki-light:#24292E;--shiki-dark:#E1E4E8;">] </span><span style="--shiki-light:#D73A49;--shiki-dark:#F97583;">=</span><span style="--shiki-light:#24292E;--shiki-dark:#E1E4E8;"> { </span><span style="--shiki-light:#6F42C1;--shiki-dark:#B392F0;">ENCODER_CCW_CW</span><span style="--shiki-light:#24292E;--shiki-dark:#E1E4E8;">(UG_VALD, UG_VALU),  </span><span style="--shiki-light:#6F42C1;--shiki-dark:#B392F0;">ENCODER_CCW_CW</span><span style="--shiki-light:#24292E;--shiki-dark:#E1E4E8;">(UG_SPDD, UG_SPDU)  },</span></span>\n<span class="line"><span style="--shiki-light:#24292E;--shiki-dark:#E1E4E8;">    [</span><span style="--shiki-light:#005CC5;--shiki-dark:#79B8FF;">3</span><span style="--shiki-light:#24292E;--shiki-dark:#E1E4E8;">] </span><span style="--shiki-light:#D73A49;--shiki-dark:#F97583;">=</span><span style="--shiki-light:#24292E;--shiki-dark:#E1E4E8;"> { </span><span style="--shiki-light:#6F42C1;--shiki-dark:#B392F0;">ENCODER_CCW_CW</span><span style="--shiki-light:#24292E;--shiki-dark:#E1E4E8;">(UG_PREV, UG_NEXT),  </span><span style="--shiki-light:#6F42C1;--shiki-dark:#B392F0;">ENCODER_CCW_CW</span><span style="--shiki-light:#24292E;--shiki-dark:#E1E4E8;">(KC_RIGHT, KC_LEFT) },</span></span>\n<span class="line"><span style="--shiki-light:#24292E;--shiki-dark:#E1E4E8;">};</span></span>\n<span class="line"><span style="--shiki-light:#D73A49;--shiki-dark:#F97583;">#endif</span></span></code></pre></div><div class="tip custom-block"><p class="custom-block-title">TIP</p><p>This should only be enabled at the keymap level.</p></div><p>Using encoder mapping pumps events through the normal QMK keycode processing pipeline, resulting in a <em>keydown/keyup</em> combination pushed through <code>process_record_xxxxx()</code>. To configure the amount of time between the encoder &quot;keyup&quot; and &quot;keydown&quot;, you can add the following to your <code>config.h</code>:</p><div class="language-c vp-adaptive-theme"><button title="Copy Code" class="copy"></button><span class="lang">c</span><pre class="shiki shiki-themes github-light github-dark vp-code"><code><span class="line"><span style="--shiki-light:#D73A49;--shiki-dark:#F97583;">#define</span><span style="--shiki-light:#6F42C1;--shiki-dark:#B392F0;"> ENCODER_MAP_KEY_DELAY</span><span style="--shiki-light:#005CC5;--shiki-dark:#79B8FF;"> 10</span></span></code></pre></div><div class="tip custom-block"><p class="custom-block-title">TIP</p><p>By default, the encoder map delay matches the value of <code>TAP_CODE_DELAY</code>.</p></div><h2 id="callbacks" tabindex="-1">Callbacks <a class="header-anchor" href="#callbacks" aria-label="Permalink to &quot;Callbacks&quot;">​</a></h2><div class="tip custom-block"><p class="custom-block-title">TIP</p><p><a href="https://github.com/qmk/qmk_firmware/blob/master/quantum/encoder.c#L79-" target="_blank" rel="noreferrer"><strong>Default Behaviour</strong></a>: all encoders installed will function as volume up (<code>KC_VOLU</code>) on clockwise rotation and volume down (<code>KC_VOLD</code>) on counter-clockwise rotation. If you do not wish to override this, no further configuration is necessary.</p></div><p>If you would like the alter the default behaviour, and are not using <code>ENCODER_MAP_ENABLE = yes</code>, the callback functions can be inserted into your <code>&lt;keyboard&gt;.c</code>:</p><div class="language-c vp-adaptive-theme"><button title="Copy Code" class="copy"></button><span class="lang">c</span><pre class="shiki shiki-themes github-light github-dark vp-code"><code><span class="line"><span style="--shiki-light:#D73A49;--shiki-dark:#F97583;">bool</span><span style="--shiki-light:#6F42C1;--shiki-dark:#B392F0;"> encoder_update_kb</span><span style="--shiki-light:#24292E;--shiki-dark:#E1E4E8;">(</span><span style="--shiki-light:#D73A49;--shiki-dark:#F97583;">uint8_t</span><span style="--shiki-light:#E36209;--shiki-dark:#FFAB70;"> index</span><span style="--shiki-light:#24292E;--shiki-dark:#E1E4E8;">, </span><span style="--shiki-light:#D73A49;--shiki-dark:#F97583;">bool</span><span style="--shiki-light:#E36209;--shiki-dark:#FFAB70;"> clockwise</span><span style="--shiki-light:#24292E;--shiki-dark:#E1E4E8;">) {</span></span>\n<span class="line"><span style="--shiki-light:#D73A49;--shiki-dark:#F97583;">    if</span><span style="--shiki-light:#24292E;--shiki-dark:#E1E4E8;"> (</span><span style="--shiki-light:#D73A49;--shiki-dark:#F97583;">!</span><span style="--shiki-light:#6F42C1;--shiki-dark:#B392F0;">encoder_update_user</span><span style="--shiki-light:#24292E;--shiki-dark:#E1E4E8;">(index, clockwise)) {</span></span>\n<span class="line"><span style="--shiki-light:#D73A49;--shiki-dark:#F97583;">      return</span><span style="--shiki-light:#005CC5;--shiki-dark:#79B8FF;"> false</span><span style="--shiki-light:#24292E;--shiki-dark:#E1E4E8;">;</span><span style="--shiki-light:#6A737D;--shiki-dark:#6A737D;"> /* Don&#39;t process further events if user function exists and returns false */</span></span>\n<span class="line"><span style="--shiki-light:#24292E;--shiki-dark:#E1E4E8;">    }</span></span>\n<span class="line"><span style="--shiki-light:#D73A49;--shiki-dark:#F97583;">    if</span><span style="--shiki-light:#24292E;--shiki-dark:#E1E4E8;"> (index </span><span style="--shiki-light:#D73A49;--shiki-dark:#F97583;">==</span><span style="--shiki-light:#005CC5;--shiki-dark:#79B8FF;"> 0</span><span style="--shiki-light:#24292E;--shiki-dark:#E1E4E8;">) {</span><span style="--shiki-light:#6A737D;--shiki-dark:#6A737D;"> /* First encoder */</span></span>\n<span class="line"><span style="--shiki-light:#D73A49;--shiki-dark:#F97583;">        if</span><span style="--shiki-light:#24292E;--shiki-dark:#E1E4E8;"> (clockwise) {</span></span>\n<span class="line"><span style="--shiki-light:#6F42C1;--shiki-dark:#B392F0;">            tap_code</span><span style="--shiki-light:#24292E;--shiki-dark:#E1E4E8;">(KC_PGDN);</span></span>\n<span class="line"><span style="--shiki-light:#24292E;--shiki-dark:#E1E4E8;">        } </span><span style="--shiki-light:#D73A49;--shiki-dark:#F97583;">else</span><span style="--shiki-light:#24292E;--shiki-dark:#E1E4E8;"> {</span></span>\n<span class="line"><span style="--shiki-light:#6F42C1;--shiki-dark:#B392F0;">            tap_code</span><span style="--shiki-light:#24292E;--shiki-dark:#E1E4E8;">(KC_PGUP);</span></span>\n<span class="line"><span style="--shiki-light:#24292E;--shiki-dark:#E1E4E8;">        }</span></span>\n<span class="line"><span style="--shiki-light:#24292E;--shiki-dark:#E1E4E8;">    } </span><span style="--shiki-light:#D73A49;--shiki-dark:#F97583;">else</span><span style="--shiki-light:#D73A49;--shiki-dark:#F97583;"> if</span><span style="--shiki-light:#24292E;--shiki-dark:#E1E4E8;"> (index </span><span style="--shiki-light:#D73A49;--shiki-dark:#F97583;">==</span><span style="--shiki-light:#005CC5;--shiki-dark:#79B8FF;"> 1</span><span style="--shiki-light:#24292E;--shiki-dark:#E1E4E8;">) {</span><span style="--shiki-light:#6A737D;--shiki-dark:#6A737D;"> /* Second encoder */</span></span>\n<span class="line"><span style="--shiki-light:#D73A49;--shiki-dark:#F97583;">        if</span><span style="--shiki-light:#24292E;--shiki-dark:#E1E4E8;"> (clockwise) {</span></span>\n<span class="line"><span style="--shiki-light:#6F42C1;--shiki-dark:#B392F0;">            rgb_matrix_increase_hue</span><span style="--shiki-light:#24292E;--shiki-dark:#E1E4E8;">();</span></span>\n<span class="line"><span style="--shiki-light:#24292E;--shiki-dark:#E1E4E8;">        } </span><span style="--shiki-light:#D73A49;--shiki-dark:#F97583;">else</span><span style="--shiki-light:#24292E;--shiki-dark:#E1E4E8;"> {</span></span>\n<span class="line"><span style="--shiki-light:#6F42C1;--shiki-dark:#B392F0;">            rgb_matrix_decrease_hue</span><span style="--shiki-light:#24292E;--shiki-dark:#E1E4E8;">();</span></span>\n<span class="line"><span style="--shiki-light:#24292E;--shiki-dark:#E1E4E8;">        }</span></span>\n<span class="line"><span style="--shiki-light:#24292E;--shiki-dark:#E1E4E8;">    }</span></span>\n<span class="line"><span style="--shiki-light:#D73A49;--shiki-dark:#F97583;">    return</span><span style="--shiki-light:#005CC5;--shiki-dark:#79B8FF;"> true</span><span style="--shiki-light:#24292E;--shiki-dark:#E1E4E8;">;</span></span>\n<span class="line"><span style="--shiki-light:#24292E;--shiki-dark:#E1E4E8;">}</span></span></code></pre></div><p>or <code>keymap.c</code>:</p><div class="language-c vp-adaptive-theme"><button title="Copy Code" class="copy"></button><span class="lang">c</span><pre class="shiki shiki-themes github-light github-dark vp-code"><code><span class="line"><span style="--shiki-light:#D73A49;--shiki-dark:#F97583;">bool</span><span style="--shiki-light:#6F42C1;--shiki-dark:#B392F0;"> encoder_update_user</span><span style="--shiki-light:#24292E;--shiki-dark:#E1E4E8;">(</span><span style="--shiki-light:#D73A49;--shiki-dark:#F97583;">uint8_t</span><span style="--shiki-light:#E36209;--shiki-dark:#FFAB70;"> index</span><span style="--shiki-light:#24292E;--shiki-dark:#E1E4E8;">, </span><span style="--shiki-light:#D73A49;--shiki-dark:#F97583;">bool</span><span style="--shiki-light:#E36209;--shiki-dark:#FFAB70;"> clockwise</span><span style="--shiki-light:#24292E;--shiki-dark:#E1E4E8;">) {</span></span>\n<span class="line"><span style="--shiki-light:#D73A49;--shiki-dark:#F97583;">    if</span><span style="--shiki-light:#24292E;--shiki-dark:#E1E4E8;"> (index </span><span style="--shiki-light:#D73A49;--shiki-dark:#F97583;">==</span><span style="--shiki-light:#005CC5;--shiki-dark:#79B8FF;"> 0</span><span style="--shiki-light:#24292E;--shiki-dark:#E1E4E8;">) {</span><span style="--shiki-light:#6A737D;--shiki-dark:#6A737D;"> /* First encoder */</span></span>\n<span class="line"><span style="--shiki-light:#D73A49;--shiki-dark:#F97583;">        if</span><span style="--shiki-light:#24292E;--shiki-dark:#E1E4E8;"> (clockwise) {</span></span>\n<span class="line"><span style="--shiki-light:#6F42C1;--shiki-dark:#B392F0;">            tap_code</span><span style="--shiki-light:#24292E;--shiki-dark:#E1E4E8;">(KC_PGDN);</span></span>\n<span class="line"><span style="--shiki-light:#24292E;--shiki-dark:#E1E4E8;">        } </span><span style="--shiki-light:#D73A49;--shiki-dark:#F97583;">else</span><span style="--shiki-light:#24292E;--shiki-dark:#E1E4E8;"> {</span></span>\n<span class="line"><span style="--shiki-light:#6F42C1;--shiki-dark:#B392F0;">            tap_code</span><span style="--shiki-light:#24292E;--shiki-dark:#E1E4E8;">(KC_PGUP);</span></span>\n<span class="line"><span style="--shiki-light:#24292E;--shiki-dark:#E1E4E8;">        }</span></span>\n<span class="line"><span style="--shiki-light:#24292E;--shiki-dark:#E1E4E8;">    } </span><span style="--shiki-light:#D73A49;--shiki-dark:#F97583;">else</span><span style="--shiki-light:#D73A49;--shiki-dark:#F97583;"> if</span><span style="--shiki-light:#24292E;--shiki-dark:#E1E4E8;"> (index </span><span style="--shiki-light:#D73A49;--shiki-dark:#F97583;">==</span><span style="--shiki-light:#005CC5;--shiki-dark:#79B8FF;"> 1</span><span style="--shiki-light:#24292E;--shiki-dark:#E1E4E8;">) {</span><span style="--shiki-light:#6A737D;--shiki-dark:#6A737D;"> /* Second encoder */</span></span>\n<span class="line"><span style="--shiki-light:#D73A49;--shiki-dark:#F97583;">        if</span><span style="--shiki-light:#24292E;--shiki-dark:#E1E4E8;"> (clockwise) {</span></span>\n<span class="line"><span style="--shiki-light:#6F42C1;--shiki-dark:#B392F0;">            rgb_matrix_increase_hue</span><span style="--shiki-light:#24292E;--shiki-dark:#E1E4E8;">();</span></span>\n<span class="line"><span style="--shiki-light:#24292E;--shiki-dark:#E1E4E8;">        } </span><span style="--shiki-light:#D73A49;--shiki-dark:#F97583;">else</span><span style="--shiki-light:#24292E;--shiki-dark:#E1E4E8;"> {</span></span>\n<span class="line"><span style="--shiki-light:#6F42C1;--shiki-dark:#B392F0;">            rgb_matrix_decrease_hue</span><span style="--shiki-light:#24292E;--shiki-dark:#E1E4E8;">();</span></span>\n<span class="line"><span style="--shiki-light:#24292E;--shiki-dark:#E1E4E8;">        }</span></span>\n<span class="line"><span style="--shiki-light:#24292E;--shiki-dark:#E1E4E8;">    }</span></span>\n<span class="line"><span style="--shiki-light:#D73A49;--shiki-dark:#F97583;">    return</span><span style="--shiki-light:#005CC5;--shiki-dark:#79B8FF;"> false</span><span style="--shiki-light:#24292E;--shiki-dark:#E1E4E8;">;</span></span>\n<span class="line"><span style="--shiki-light:#24292E;--shiki-dark:#E1E4E8;">}</span></span></code></pre></div><div class="warning custom-block"><p class="custom-block-title">WARNING</p><p>If you return <code>true</code> in the keymap level <code>_user</code> function, it will allow the keyboard/core level encoder code to run on top of your own. Returning <code>false</code> will override the keyboard level function, if setup correctly. This is generally the safest option to avoid confusion.</p></div><h2 id="hardware" tabindex="-1">Hardware <a class="header-anchor" href="#hardware" aria-label="Permalink to &quot;Hardware&quot;">​</a></h2><p>The A an B lines of the encoders should be wired directly to the MCU, and the C/common lines should be wired to ground.</p><h2 id="multiple-encoders" tabindex="-1">Multiple Encoders <a class="header-anchor" href="#multiple-encoders" aria-label="Permalink to &quot;Multiple Encoders&quot;">​</a></h2><p>Multiple encoders may share pins so long as each encoder has a distinct pair of pins when the following conditions are met:</p><ul><li>using detent encoders</li><li>pads must be high at the detent stability point which is called &#39;default position&#39; in QMK</li><li>no more than two encoders sharing a pin can be turned at the same time</li></ul><p>For example you can support two encoders using only 3 pins like this</p><div class="language- vp-adaptive-theme"><button title="Copy Code" class="copy"></button><span class="lang"></span><pre class="shiki shiki-themes github-light github-dark vp-code"><code><span class="line"><span>#define ENCODER_A_PINS { B1, B1 }</span></span>\n<span class="line"><span>#define ENCODER_B_PINS { B2, B3 }</span></span></code></pre></div><p>You could even support three encoders using only three pins (one per encoder) however in this configuration, rotating two encoders which share pins simultaneously will often generate incorrect output. For example:</p><div class="language- vp-adaptive-theme"><button title="Copy Code" class="copy"></button><span class="lang"></span><pre class="shiki shiki-themes github-light github-dark vp-code"><code><span class="line"><span>#define ENCODER_A_PINS { B1, B1, B2 }</span></span>\n<span class="line"><span>#define ENCODER_B_PINS { B2, B3, B3 }</span></span></code></pre></div><p>Here rotating Encoder 0 <code>B1 B2</code> and Encoder 1 <code>B1 B3</code> could be interpreted as rotating Encoder 2 <code>B2 B3</code> or <code>B3 B2</code> depending on the timing. This may still be a useful configuration depending on your use case</p>', 48);
const _hoisted_49 = [
  _hoisted_1
];
function _sfc_render(_ctx, _cache, $props, $setup, $data, $options) {
  return openBlock(), createElementBlock("div", null, _hoisted_49);
}
const encoders = /* @__PURE__ */ _export_sfc(_sfc_main, [["render", _sfc_render]]);
export {
  __pageData,
  encoders as default
};
