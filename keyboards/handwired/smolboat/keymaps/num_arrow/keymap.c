/* Copyright 2019 takenotice
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

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
  QMKBEST = SAFE_RANGE,
  QMKURL
};

#define _BASE 0
#define _LOWER 1
#define _UPPER 3

#define LOWER MO(_LOWER)
#define RAISE MO(_UPPER)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* BASE
   * ,--------------------------------------------------------------------------------------------------------.
   * | ESC  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |   -  |   =	|   /  |   *  |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * | TAB  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | BKSP |   7	|   8  |   9  |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * |   `  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  ENT |   4  |   5  |   9  |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * | SHFT |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |  UP  |   '  |   1  |   2  |   3  |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * | CTRL | GUI  | ALT  |LOWER |SPACE |SPACE |SPACE |RAISE |   /  | LEFT | DOWN |RIGHT |   0	|   .  |  ENT |
   * `--------------------------------------------------------------------------------------------------------'
   */
  	[_BASE] = LAYOUT(
    KC_ESC,    KC_1,    KC_2,     KC_3,   KC_4,    KC_5,    KC_6,    KC_7,   KC_8,     KC_9,     KC_0,     KC_MINUS,  KC_EQL,  KC_PSLS,  KC_PAST,
	KC_TAB,    KC_Q,    KC_W,     KC_E,   KC_R,    KC_T,    KC_Y,    KC_U,   KC_I,     KC_O,     KC_P,     KC_BSPC,   KC_P7,   KC_P8,    KC_P9,  
    KC_GRV,    KC_A,    KC_S,     KC_D,   KC_F,    KC_G,    KC_H,    KC_J,   KC_K,     KC_L,     KC_SCLN,  KC_ENT,    KC_P4,   KC_P5,    KC_P6,
    KC_LSHIFT, KC_Z,    KC_X,     KC_C,   KC_V,    KC_B,    KC_N,    KC_M,   KC_COMM,  KC_DOT,   KC_UP,    KC_QUOT,   KC_P1,   KC_P2,    KC_P3,
    KC_LCTL,   KC_LGUI, KC_LALT,  LOWER,  KC_SPC,  KC_SPC,  KC_SPC,  RAISE,  KC_SLSH,  KC_LEFT,  KC_DOWN,  KC_RIGHT,  KC_P0,   KC_PDOT,  KC_PENT
  ),
  /* UPPER
   * ,--------------------------------------------------------------------------------------------------------.
   * |   `  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12	|  F13 |  F14 |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |      |      |      |      |  DEL |  <<	|  >>  | VOL+ |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * | CAPS |      |      |      |      |      |      |      |      |      |      |      | STOP | PLAY | VOL- |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |      |      |      |      |      |   	|      | MUTE |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |      |      |      |      |      |   	|      |      |
   * `--------------------------------------------------------------------------------------------------------'
   */
  	[_UPPER] = LAYOUT(
     KC_GRV,     KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,     KC_F9,   KC_F10,   KC_F11,   KC_F12,   KC_F13,   KC_F14,
	_______,   _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,   KC_DEL,  KC_MPRV,  KC_MNXT,  KC_VOLU,  
    KC_CAPS,   _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,  KC_MSTP,  KC_MPLY,  KC_VOLD,
    _______,   _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,  KC_MUTE,
    _______,   _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,  _______
  ),
  /* LOWER
   * ,--------------------------------------------------------------------------------------------------------.
   * |      |      |      |      |      |      |      |      |      |      |      |NUMLCK|PRTSC	|SCRLK |PAUSE |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |RESET |      |      |      |      |      |      |      |  INS	| HOME | PGUP |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |      |      |      |      |      |  DEL |  END | PGDN |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |      |      |      |      |      |   	|      |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |ALTGR |      |      |      |      |      |   \  |      |      |      |   	|      |      |
   * `--------------------------------------------------------------------------------------------------------'
   */
  	[_LOWER] = LAYOUT(
    _______,   _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,  KC_NLCK,  KC_PSCR,  KC_SLCK,  KC_PAUS,
	_______,   _______,  _______,  _______,    RESET,  _______,  _______,  _______,  _______,   _______,  _______,  _______,   KC_INS,  KC_HOME,  KC_PGUP,  
    _______,   _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,   KC_DEL,   KC_END,  KC_PGDN,
    _______,   _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,  _______,
    _______,   _______,  KC_ALGR,  _______,  _______,  _______,  _______,  _______,  KC_BSLS,   _______,  _______,  _______,  _______,  _______,  _______
  )
  
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QMKBEST:
      if (record->event.pressed) {
        // when keycode QMKBEST is pressed
        SEND_STRING("QMK is the best thing ever!");
      } else {
        // when keycode QMKBEST is released
      }
      break;
    case QMKURL:
      if (record->event.pressed) {
        // when keycode QMKURL is pressed
        SEND_STRING("https://qmk.fm/" SS_TAP(X_ENTER));
      } else {
        // when keycode QMKURL is released
      }
      break;
  }
  return true;
}

void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

void led_set_user(uint8_t usb_led) {

}
