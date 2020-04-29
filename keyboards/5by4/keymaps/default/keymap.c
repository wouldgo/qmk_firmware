/* Copyright 2020 wouldgo
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
#include QMK_KEYBOARD_H

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE
};

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
    QMKBEST = SAFE_RANGE,
    QMKURL
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
        /*
    * |---------------------------------------|
    * | NumLock |    /    |    *    |   BSpc  |
    * |---------------------------------------|
    * |    7    |    8    |    9    |    -    |
    * |---------------------------------------|
    * |    4    |    5    |    6    |    +    |
    * |---------------------------------------|
    * |    1    |    2    |    3    |         |
    * |---------------------------------------|
    * |    0    |         |    .    |   Ent   |
    * |---------------------------------------|
    */
    [_BASE] = LAYOUT(
        KC_NUMLOCK, KC_KP_SLASH, KC_KP_ASTERISK, KC_BSPACE,
        KC_KP_7,    KC_KP_8,     KC_KP_9,        KC_KP_MINUS,
        KC_KP_4,    KC_KP_5,     KC_KP_6,        KC_KP_PLUS,
        KC_KP_1,    KC_KP_2,     KC_KP_3,
        KC_KP_0,                 KC_KP_DOT,      KC_KP_ENTER
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

    return true;
}

void matrix_init_user(void) {}

void matrix_scan_user(void) {}

void led_set_user(uint8_t usb_led) {}

#ifdef OLED_DRIVER_ENABLE

static void render_logo(void) {
  static const char PROGMEM qmk_logo[] = {
    0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
    0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
    0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0};

  oled_write_P(qmk_logo, false);
}

void oled_task_user(void) {
  oled_write_P(PSTR("NUMLOCK\n"), host_keyboard_led_state().num_lock);

  render_logo();
}
#endif
