import { _ as _export_sfc, c as createElementBlock, o as openBlock, a8 as createStaticVNode } from "./chunks/framework.DyMmIvSC.js";
const __pageData = JSON.parse('{"title":"SNLED27351 Driver","description":"","frontmatter":{},"headers":[],"relativePath":"drivers/snled27351.md","filePath":"drivers/snled27351.md"}');
const _sfc_main = { name: "drivers/snled27351.md" };
const _hoisted_1 = /* @__PURE__ */ createStaticVNode('<h1 id="snled27351-driver" tabindex="-1">SNLED27351 Driver <a class="header-anchor" href="#snled27351-driver" aria-label="Permalink to &quot;SNLED27351 Driver {#snled27351-driver}&quot;">​</a></h1><p>I²C 16x12 LED matrix driver by Sonix. Supports a maximum of four drivers, each controlling up to 192 single-color LEDs, or 64 RGB LEDs.</p><p>A slightly modified version of this IC is also known as &quot;CKLED2001&quot;.</p><p><a href="https://www.sonix.com.tw/files/1/D235860C0C037C28E050007F01001CBE" target="_blank" rel="noreferrer">SNLED27351 Datasheet</a></p><h2 id="usage" tabindex="-1">Usage <a class="header-anchor" href="#usage" aria-label="Permalink to &quot;Usage {#usage}&quot;">​</a></h2><p>The SNLED27351 driver code is automatically included if you are using the <a href="./../features/led_matrix">LED Matrix</a> or <a href="./../features/rgb_matrix">RGB Matrix</a> feature with the <code>snled27351</code> driver set, and you would use those APIs instead.</p><p>However, if you need to use the driver standalone, add this to your <code>rules.mk</code>:</p><div class="language-make vp-adaptive-theme"><button title="Copy Code" class="copy"></button><span class="lang">make</span><pre class="shiki shiki-themes github-light github-dark vp-code"><code><span class="line"><span style="--shiki-light:#24292E;--shiki-dark:#E1E4E8;">COMMON_VPATH += </span><span style="--shiki-light:#032F62;--shiki-dark:#9ECBFF;">$(</span><span style="--shiki-light:#24292E;--shiki-dark:#E1E4E8;">DRIVER_PATH</span><span style="--shiki-light:#032F62;--shiki-dark:#9ECBFF;">)</span><span style="--shiki-light:#24292E;--shiki-dark:#E1E4E8;">/led</span></span>\n<span class="line"><span style="--shiki-light:#24292E;--shiki-dark:#E1E4E8;">SRC += snled27351-mono.c </span><span style="--shiki-light:#6A737D;--shiki-dark:#6A737D;"># For single-color</span></span>\n<span class="line"><span style="--shiki-light:#24292E;--shiki-dark:#E1E4E8;">SRC += snled27351.c </span><span style="--shiki-light:#6A737D;--shiki-dark:#6A737D;"># For RGB</span></span>\n<span class="line"><span style="--shiki-light:#24292E;--shiki-dark:#E1E4E8;">I2C_DRIVER_REQUIRED = yes</span></span></code></pre></div><h2 id="basic-configuration" tabindex="-1">Basic Configuration <a class="header-anchor" href="#basic-configuration" aria-label="Permalink to &quot;Basic Configuration {#basic-configuration}&quot;">​</a></h2><p>Add the following to your <code>config.h</code>:</p><table><thead><tr><th>Define</th><th>Default</th><th>Description</th></tr></thead><tbody><tr><td><code>SNLED27351_SDB_PIN</code></td><td><em>Not defined</em></td><td>The GPIO pin connected to the drivers&#39; shutdown pins</td></tr><tr><td><code>SNLED27351_I2C_TIMEOUT</code></td><td><code>100</code></td><td>The I²C timeout in milliseconds</td></tr><tr><td><code>SNLED27351_I2C_PERSISTENCE</code></td><td><code>0</code></td><td>The number of times to retry I²C transmissions</td></tr><tr><td><code>SNLED27351_I2C_ADDRESS_1</code></td><td><em>Not defined</em></td><td>The I²C address of driver 0</td></tr><tr><td><code>SNLED27351_I2C_ADDRESS_2</code></td><td><em>Not defined</em></td><td>The I²C address of driver 1</td></tr><tr><td><code>SNLED27351_I2C_ADDRESS_3</code></td><td><em>Not defined</em></td><td>The I²C address of driver 2</td></tr><tr><td><code>SNLED27351_I2C_ADDRESS_4</code></td><td><em>Not defined</em></td><td>The I²C address of driver 3</td></tr></tbody></table><h3 id="i2c-addressing" tabindex="-1">I²C Addressing <a class="header-anchor" href="#i2c-addressing" aria-label="Permalink to &quot;I²C Addressing {#i2c-addressing}&quot;">​</a></h3><p>The SNLED27351 has four possible 7-bit I²C addresses, depending on how the <code>ADDR</code> pin is connected.</p><p>To configure this, set the <code>SNLED27351_I2C_ADDRESS_n</code> defines to one of the following in your <code>config.h</code>, where <em>n</em> denotes the driver index:</p><table><thead><tr><th>Define</th><th>Value</th></tr></thead><tbody><tr><td><code>SNLED27351_I2C_ADDRESS_GND</code></td><td><code>0x74</code></td></tr><tr><td><code>SNLED27351_I2C_ADDRESS_SCL</code></td><td><code>0x75</code></td></tr><tr><td><code>SNLED27351_I2C_ADDRESS_SDA</code></td><td><code>0x76</code></td></tr><tr><td><code>SNLED27351_I2C_ADDRESS_VDDIO</code></td><td><code>0x77</code></td></tr></tbody></table><h2 id="arm-configuration" tabindex="-1">ARM/ChibiOS Configuration <a class="header-anchor" href="#arm-configuration" aria-label="Permalink to &quot;ARM/ChibiOS Configuration {#arm-configuration}&quot;">​</a></h2><p>Depending on the ChibiOS board configuration, you may need to <a href="./i2c#arm-configuration">enable and configure I²C</a> at the keyboard level.</p><h2 id="led-mapping" tabindex="-1">LED Mapping <a class="header-anchor" href="#led-mapping" aria-label="Permalink to &quot;LED Mapping {#led-mapping}&quot;">​</a></h2><p>In order to use this driver, each output must be mapped to an LED index, by adding the following to your <code>&lt;keyboardname&gt;.c</code>:</p><div class="language-c vp-adaptive-theme"><button title="Copy Code" class="copy"></button><span class="lang">c</span><pre class="shiki shiki-themes github-light github-dark vp-code"><code><span class="line"><span style="--shiki-light:#D73A49;--shiki-dark:#F97583;">const</span><span style="--shiki-light:#005CC5;--shiki-dark:#79B8FF;"> snled27351_led_t</span><span style="--shiki-light:#24292E;--shiki-dark:#E1E4E8;"> PROGMEM </span><span style="--shiki-light:#E36209;--shiki-dark:#FFAB70;">g_snled27351_leds</span><span style="--shiki-light:#24292E;--shiki-dark:#E1E4E8;">[SNLED27351_LED_COUNT] </span><span style="--shiki-light:#D73A49;--shiki-dark:#F97583;">=</span><span style="--shiki-light:#24292E;--shiki-dark:#E1E4E8;"> {</span></span>\n<span class="line"><span style="--shiki-light:#6A737D;--shiki-dark:#6A737D;">/* Driver</span></span>\n<span class="line"><span style="--shiki-light:#6A737D;--shiki-dark:#6A737D;"> *   |  R         G         B */</span></span>\n<span class="line"><span style="--shiki-light:#24292E;--shiki-dark:#E1E4E8;">    {</span><span style="--shiki-light:#005CC5;--shiki-dark:#79B8FF;">0</span><span style="--shiki-light:#24292E;--shiki-dark:#E1E4E8;">, CB1_CA1,  CB1_CA2,  CB1_CA3},</span></span>\n<span class="line"><span style="--shiki-light:#6A737D;--shiki-dark:#6A737D;">    // etc...</span></span>\n<span class="line"><span style="--shiki-light:#24292E;--shiki-dark:#E1E4E8;">};</span></span></code></pre></div><p>In this example, the red, green and blue channels for the first LED index on driver 0 all have their cathodes connected to the <code>CB1</code> pin, and their anodes on the <code>CA1</code>, <code>CA2</code> and <code>CA3</code> pins respectively.</p><p>For the single-color driver, the principle is the same, but there is only one channel:</p><div class="language-c vp-adaptive-theme"><button title="Copy Code" class="copy"></button><span class="lang">c</span><pre class="shiki shiki-themes github-light github-dark vp-code"><code><span class="line"><span style="--shiki-light:#D73A49;--shiki-dark:#F97583;">const</span><span style="--shiki-light:#005CC5;--shiki-dark:#79B8FF;"> snled27351_led_t</span><span style="--shiki-light:#24292E;--shiki-dark:#E1E4E8;"> PROGMEM </span><span style="--shiki-light:#E36209;--shiki-dark:#FFAB70;">g_snled27351_leds</span><span style="--shiki-light:#24292E;--shiki-dark:#E1E4E8;">[SNLED27351_LED_COUNT] </span><span style="--shiki-light:#D73A49;--shiki-dark:#F97583;">=</span><span style="--shiki-light:#24292E;--shiki-dark:#E1E4E8;"> {</span></span>\n<span class="line"><span style="--shiki-light:#6A737D;--shiki-dark:#6A737D;">/* Driver</span></span>\n<span class="line"><span style="--shiki-light:#6A737D;--shiki-dark:#6A737D;"> *   |  V */</span></span>\n<span class="line"><span style="--shiki-light:#24292E;--shiki-dark:#E1E4E8;">    {</span><span style="--shiki-light:#005CC5;--shiki-dark:#79B8FF;">0</span><span style="--shiki-light:#24292E;--shiki-dark:#E1E4E8;">, CB1_CA1},</span></span>\n<span class="line"><span style="--shiki-light:#6A737D;--shiki-dark:#6A737D;">    // etc...</span></span>\n<span class="line"><span style="--shiki-light:#24292E;--shiki-dark:#E1E4E8;">};</span></span></code></pre></div><p>These values correspond to the register indices as shown in the datasheet on page 13.</p><h2 id="api" tabindex="-1">API <a class="header-anchor" href="#api" aria-label="Permalink to &quot;API {#api}&quot;">​</a></h2><h3 id="api-snled27351-led-t" tabindex="-1"><code>struct snled27351_led_t</code> <a class="header-anchor" href="#api-snled27351-led-t" aria-label="Permalink to &quot;`struct snled27351_led_t` {#api-snled27351-led-t}&quot;">​</a></h3><p>Contains the PWM register addresses for a single RGB LED.</p><h4 id="api-snled27351-led-t-members" tabindex="-1">Members <a class="header-anchor" href="#api-snled27351-led-t-members" aria-label="Permalink to &quot;Members {#api-snled27351-led-t-members}&quot;">​</a></h4><ul><li><code>uint8_t driver</code><br> The driver index of the LED, from 0 to 3.</li><li><code>uint8_t r</code><br> The output PWM register address for the LED&#39;s red channel (RGB driver only).</li><li><code>uint8_t g</code><br> The output PWM register address for the LED&#39;s green channel (RGB driver only).</li><li><code>uint8_t b</code><br> The output PWM register address for the LED&#39;s blue channel (RGB driver only).</li><li><code>uint8_t v</code><br> The output PWM register address for the LED (single-color driver only).</li></ul><hr><h3 id="api-snled27351-init" tabindex="-1"><code>void snled27351_init(uint8_t index)</code> <a class="header-anchor" href="#api-snled27351-init" aria-label="Permalink to &quot;`void snled27351_init(uint8_t index)` {#api-snled27351-init}&quot;">​</a></h3><p>Initialize the LED driver. This function should be called first.</p><h4 id="api-snled27351-init-arguments" tabindex="-1">Arguments <a class="header-anchor" href="#api-snled27351-init-arguments" aria-label="Permalink to &quot;Arguments {#api-snled27351-init-arguments}&quot;">​</a></h4><ul><li><code>uint8_t index</code><br> The driver index.</li></ul><hr><h3 id="api-snled27351-write-register" tabindex="-1"><code>void snled27351_write_register(uint8_t index, uint8_t reg, uint8_t data)</code> <a class="header-anchor" href="#api-snled27351-write-register" aria-label="Permalink to &quot;`void snled27351_write_register(uint8_t index, uint8_t reg, uint8_t data)` {#api-snled27351-write-register}&quot;">​</a></h3><p>Set the value of the given register.</p><h4 id="api-snled27351-write-register-arguments" tabindex="-1">Arguments <a class="header-anchor" href="#api-snled27351-write-register-arguments" aria-label="Permalink to &quot;Arguments {#api-snled27351-write-register-arguments}&quot;">​</a></h4><ul><li><code>uint8_t index</code><br> The driver index.</li><li><code>uint8_t reg</code><br> The register address.</li><li><code>uint8_t data</code><br> The value to set.</li></ul><hr><h3 id="api-snled27351-select-page" tabindex="-1"><code>void snled27351_select_page(uint8_t index, uint8_t page)</code> <a class="header-anchor" href="#api-snled27351-select-page" aria-label="Permalink to &quot;`void snled27351_select_page(uint8_t index, uint8_t page)` {#api-snled27351-select-page}&quot;">​</a></h3><p>Change the current page for configuring the LED driver.</p><h4 id="api-snled27351-select-page-arguments" tabindex="-1">Arguments <a class="header-anchor" href="#api-snled27351-select-page-arguments" aria-label="Permalink to &quot;Arguments {#api-snled27351-select-page-arguments}&quot;">​</a></h4><ul><li><code>uint8_t index</code><br> The driver index.</li><li><code>uint8_t page</code><br> The page number to select.</li></ul><hr><h3 id="api-snled27351-set-color" tabindex="-1"><code>void snled27351_set_color(int index, uint8_t red, uint8_t green, uint8_t blue)</code> <a class="header-anchor" href="#api-snled27351-set-color" aria-label="Permalink to &quot;`void snled27351_set_color(int index, uint8_t red, uint8_t green, uint8_t blue)` {#api-snled27351-set-color}&quot;">​</a></h3><p>Set the color of a single LED (RGB driver only). This function does not immediately update the LEDs; call <code>snled27351_update_pwm_buffers()</code> after you are finished.</p><h4 id="api-snled27351-set-color-arguments" tabindex="-1">Arguments <a class="header-anchor" href="#api-snled27351-set-color-arguments" aria-label="Permalink to &quot;Arguments {#api-snled27351-set-color-arguments}&quot;">​</a></h4><ul><li><code>int index</code><br> The LED index (ie. the index into the <code>g_snled27351_leds</code> array).</li><li><code>uint8_t red</code><br> The red value to set.</li><li><code>uint8_t green</code><br> The green value to set.</li><li><code>uint8_t blue</code><br> The blue value to set.</li></ul><hr><h3 id="api-snled27351-set-color-all" tabindex="-1"><code>void snled27351_set_color_all(uint8_t red, uint8_t green, uint8_t blue)</code> <a class="header-anchor" href="#api-snled27351-set-color-all" aria-label="Permalink to &quot;`void snled27351_set_color_all(uint8_t red, uint8_t green, uint8_t blue)` {#api-snled27351-set-color-all}&quot;">​</a></h3><p>Set the color of all LEDs (RGB driver only).</p><h4 id="api-snled27351-set-color-all-arguments" tabindex="-1">Arguments <a class="header-anchor" href="#api-snled27351-set-color-all-arguments" aria-label="Permalink to &quot;Arguments {#api-snled27351-set-color-all-arguments}&quot;">​</a></h4><ul><li><code>uint8_t red</code><br> The red value to set.</li><li><code>uint8_t green</code><br> The green value to set.</li><li><code>uint8_t blue</code><br> The blue value to set.</li></ul><hr><h3 id="api-snled27351-set-value" tabindex="-1"><code>void snled27351_set_value(int index, uint8_t value)</code> <a class="header-anchor" href="#api-snled27351-set-value" aria-label="Permalink to &quot;`void snled27351_set_value(int index, uint8_t value)` {#api-snled27351-set-value}&quot;">​</a></h3><p>Set the brightness of a single LED (single-color driver only). This function does not immediately update the LEDs; call <code>snled27351_update_pwm_buffers()</code> after you are finished.</p><h4 id="api-snled27351-set-value-arguments" tabindex="-1">Arguments <a class="header-anchor" href="#api-snled27351-set-value-arguments" aria-label="Permalink to &quot;Arguments {#api-snled27351-set-value-arguments}&quot;">​</a></h4><ul><li><code>int index</code><br> The LED index (ie. the index into the <code>g_snled27351_leds</code> array).</li><li><code>uint8_t value</code><br> The brightness value to set.</li></ul><hr><h3 id="api-snled27351-set-value-all" tabindex="-1"><code>void snled27351_set_value_all(uint8_t value)</code> <a class="header-anchor" href="#api-snled27351-set-value-all" aria-label="Permalink to &quot;`void snled27351_set_value_all(uint8_t value)` {#api-snled27351-set-value-all}&quot;">​</a></h3><p>Set the brightness of all LEDs (single-color driver only).</p><h4 id="api-snled27351-set-value-all-arguments" tabindex="-1">Arguments <a class="header-anchor" href="#api-snled27351-set-value-all-arguments" aria-label="Permalink to &quot;Arguments {#api-snled27351-set-value-all-arguments}&quot;">​</a></h4><ul><li><code>uint8_t value</code><br> The brightness value to set.</li></ul><hr><h3 id="api-snled27351-set-led-control-register-rgb" tabindex="-1"><code>void snled27351_set_led_control_register(uint8_t index, bool red, bool green, bool blue)</code> <a class="header-anchor" href="#api-snled27351-set-led-control-register-rgb" aria-label="Permalink to &quot;`void snled27351_set_led_control_register(uint8_t index, bool red, bool green, bool blue)` {#api-snled27351-set-led-control-register-rgb}&quot;">​</a></h3><p>Configure the LED control registers for a single LED (RGB driver only). This function does not immediately update the LEDs; call <code>snled27351_update_led_control_registers()</code> after you are finished.</p><h4 id="api-snled27351-set-led-control-register-rgb-arguments" tabindex="-1">Arguments <a class="header-anchor" href="#api-snled27351-set-led-control-register-rgb-arguments" aria-label="Permalink to &quot;Arguments {#api-snled27351-set-led-control-register-rgb-arguments}&quot;">​</a></h4><ul><li><code>uint8_t index</code><br> The LED index (ie. the index into the <code>g_snled27351_leds</code> array).</li><li><code>bool red</code><br> Enable or disable the red channel.</li><li><code>bool green</code><br> Enable or disable the green channel.</li><li><code>bool blue</code><br> Enable or disable the blue channel.</li></ul><hr><h3 id="api-snled27351-set-led-control-register-mono" tabindex="-1"><code>void snled27351_set_led_control_register(uint8_t index, bool value)</code> <a class="header-anchor" href="#api-snled27351-set-led-control-register-mono" aria-label="Permalink to &quot;`void snled27351_set_led_control_register(uint8_t index, bool value)` {#api-snled27351-set-led-control-register-mono}&quot;">​</a></h3><p>Configure the LED control registers for a single LED (single-color driver only). This function does not immediately update the LEDs; call <code>snled27351_update_led_control_registers()</code> after you are finished.</p><h4 id="api-snled27351-set-led-control-register-mono-arguments" tabindex="-1">Arguments <a class="header-anchor" href="#api-snled27351-set-led-control-register-mono-arguments" aria-label="Permalink to &quot;Arguments {#api-snled27351-set-led-control-register-mono-arguments}&quot;">​</a></h4><ul><li><code>uint8_t index</code><br> The LED index (ie. the index into the <code>g_snled27351_leds</code> array).</li><li><code>bool value</code><br> Enable or disable the LED.</li></ul><hr><h3 id="api-snled27351-update-pwm-buffers" tabindex="-1"><code>void snled27351_update_pwm_buffers(uint8_t index)</code> <a class="header-anchor" href="#api-snled27351-update-pwm-buffers" aria-label="Permalink to &quot;`void snled27351_update_pwm_buffers(uint8_t index)` {#api-snled27351-update-pwm-buffers}&quot;">​</a></h3><p>Flush the PWM values to the LED driver.</p><h4 id="api-snled27351-update-pwm-buffers-arguments" tabindex="-1">Arguments <a class="header-anchor" href="#api-snled27351-update-pwm-buffers-arguments" aria-label="Permalink to &quot;Arguments {#api-snled27351-update-pwm-buffers-arguments}&quot;">​</a></h4><ul><li><code>uint8_t index</code><br> The driver index.</li></ul><hr><h3 id="api-snled27351-update-led-control-registers" tabindex="-1"><code>void snled27351_update_led_control_registers(uint8_t index)</code> <a class="header-anchor" href="#api-snled27351-update-led-control-registers" aria-label="Permalink to &quot;`void snled27351_update_led_control_registers(uint8_t index)` {#api-snled27351-update-led-control-registers}&quot;">​</a></h3><p>Flush the LED control register values to the LED driver.</p><h4 id="api-snled27351-update-led-control-registers-arguments" tabindex="-1">Arguments <a class="header-anchor" href="#api-snled27351-update-led-control-registers-arguments" aria-label="Permalink to &quot;Arguments {#api-snled27351-update-led-control-registers-arguments}&quot;">​</a></h4><ul><li><code>uint8_t index</code><br> The driver index.</li></ul>', 84);
const _hoisted_85 = [
  _hoisted_1
];
function _sfc_render(_ctx, _cache, $props, $setup, $data, $options) {
  return openBlock(), createElementBlock("div", null, _hoisted_85);
}
const snled27351 = /* @__PURE__ */ _export_sfc(_sfc_main, [["render", _sfc_render]]);
export {
  __pageData,
  snled27351 as default
};
