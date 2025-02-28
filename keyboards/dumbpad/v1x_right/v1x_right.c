/* Copyright 2019 Chip
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
#include "v1x_right.h"

void keyboard_pre_init_kb(void) {
  // Set the layer LED IO as outputs
  setPinOutput(LAYER_INDICATOR_LED_0);
  setPinOutput(LAYER_INDICATOR_LED_1);
  setPinOutput(LED_NUM_LOCK_PIN);
  
  keyboard_pre_init_user();
}

void shutdown_user() {
  // Shutdown the layer LEDs
  writePinLow(LAYER_INDICATOR_LED_0);
  writePinLow(LAYER_INDICATOR_LED_1);
}

layer_state_t layer_state_set_kb(layer_state_t state) {
  // Layer LEDs act as binary indication of current layer
  uint8_t layer = biton32(state);
  writePin(LAYER_INDICATOR_LED_0, layer & 0b1);
  writePin(LAYER_INDICATOR_LED_1, (layer >> 1) & 0b1);
  return layer_state_set_user(state);
}

bool led_update_kb(led_t led_state) {
    bool res = led_update_user(led_state);
    if(res) {
        // writePin sets the pin high for 1 and low for 0.
        // In this example the pins are inverted, setting
        // it low/0 turns it on, and high/1 turns the LED off.
        // This behavior depends on whether the LED is between the pin
        // and VCC or the pin and GND.
        writePin(LED_NUM_LOCK_PIN, !led_state.num_lock);
     }
    return res;
}

// Optional override functions below.
// You can leave any or all of these undefined.
// These are only required if you want to perform custom actions.

void matrix_init_kb(void) {
  // put your keyboard start-up code here
  // runs once when the firmware starts up
  for (int i = 0; i < 2; i++) {
    writePin(LAYER_INDICATOR_LED_0, true);
    writePin(LAYER_INDICATOR_LED_1, false);
    wait_ms(100);
    writePin(LAYER_INDICATOR_LED_0, true);
    writePin(LAYER_INDICATOR_LED_1, true);
    wait_ms(100);
    writePin(LAYER_INDICATOR_LED_0, false);
    writePin(LAYER_INDICATOR_LED_1, true);
    wait_ms(100);
    writePin(LAYER_INDICATOR_LED_0, false);
    writePin(LAYER_INDICATOR_LED_1, false);
    wait_ms(100);
  }

  matrix_init_user();
}

void matrix_scan_kb(void) {
  // put your looping keyboard code here
  // runs every cycle (a lot)

  matrix_scan_user();
}

bool process_record_kb(uint16_t keycode, keyrecord_t *record) {
  // put your per-action keyboard code here
  // runs for every action, just before processing by the firmware

  return process_record_user(keycode, record);
}

void led_set_kb(uint8_t usb_led) {
  // put your keyboard LED indicator (ex: Caps Lock LED) toggling code here

  led_set_user(usb_led);
}
