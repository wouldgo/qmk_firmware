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
/*enum custom_keycodes {
    QMKBEST = SAFE_RANGE,
    QMKURL
};*/

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
    switch (keycode) {
        /*case KC_KP_0:
            if (record->event.pressed) {
                oled_write_ln_P(PSTR("Pressing 0"), false);
            } else {
                oled_write_ln_P(PSTR("Released 0"), false);
            }
            return false; // Skip all further processing of this key*/
        default:
            return true; // Process all other keycodes normally
    }
}

void matrix_init_user(void) {}

void matrix_scan_user(void) {}

void led_set_user(uint8_t usb_led) {}

static void current_layer(void) {
    switch (get_highest_layer(layer_state)) {
        case _BASE:
            oled_write_ln_P(PSTR("             Numpad"), false);
            break;
        default:
            oled_write_ln_P(PSTR("                N/A"), false);
    }
}

static void is_numlock_active(led_t* host_keyboard_led_state) {
    static const char PROGMEM num_lock_icon[] = {
        0x9d, 0x9e, 0
    };

    oled_write_P(num_lock_icon, host_keyboard_led_state->num_lock);
}

void oled_task_user(void) {
    led_t led_usb_state = host_keyboard_led_state();

    is_numlock_active(&led_usb_state);
    current_layer();
}
