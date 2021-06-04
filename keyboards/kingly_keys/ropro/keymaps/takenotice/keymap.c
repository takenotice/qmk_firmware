/* Copyright 2019 Garret G. (TheRoyalSweatshirt)
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

enum layer_names {
    QRTY, // default layer
    COMK, // Colemak layer
    FUNC, // Functino layer
    SYMB, // symbols
    MDIA, // media keys
};

#define _FN_A LT(FUNC, KC_A)
#define _MD_SCN LT(MDIA, KC_SCLN)
#define _MD_O LT(MDIA, KC_O)
#define _SY_GRV LT(SYMB,KC_GRV)
#define _CTL_Z CTL_T(KC_Z)
#define _MD_MO MO(MDIA)
#define _MD_SPC LT(MDIA, KC_SPC)
#define _SY_MO MO(SYMB)
#define _META ALL_T(KC_NO)
#define _MEH MEH_T(KC_NO)
#define _CTL_SL CTL_T(KC_SLSH)
#define _WN_QOT GUI_T(KC_QUOT)
#define _RSH_EN RSFT_T(KC_ENT)
#define _TAP_SY TT(SYMB)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* QRTY
   *        ,-----------------------------------------------------------------------------------.
   *        | Esc  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |
   *        |------+------+------+------+------+-------------+------+------+------+------+------|
   *        | + =  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |   -  |
   *        |------+------+------+------+------+------+------+------+------+------+------+------|
   *  RotEn | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
   * ,------+------+------+------+------+------+------+------+------+------+------+------+------|
   * | QRTY | Caps |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
   * |------+------+------+------+------+------+-------------+------+------+------+------+------|
   * | COMK | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |SH/ENT|
   * |------+------+------+------+------+------+-------------+------+------+------+------+------|
   * | Meh  | Ctrl | Del  | GUI  | ALT  |_SYMB |    Space    |_MDIA | Left | Down |  Up  |Right |
   * `------------------------------------------------------------------------------------------'
   */
  	[QRTY] = LAYOUT(
              KC_ESC,   KC_F1,   KC_F2,   KC_F3,   KC_F4,    KC_F5,   KC_F6,   KC_F7,    KC_F8,   KC_F9,   KC_F10,  KC_F11,
              KC_EQL,   KC_1,    KC_2,    KC_3,    KC_4,     KC_5,    KC_6,    KC_7,     KC_8,    KC_9,    KC_0,    KC_MINUS,
    KC_MUTE,  KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,     KC_T,    KC_Y,    KC_U,     KC_I,    KC_O,    KC_P,    KC_BSPC,
    DF(QRTY), KC_CAPS,  KC_A,    KC_S,    KC_D,    KC_F,     KC_G,    KC_H,    KC_J,     KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    DF(COMK), KC_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,     KC_B,    KC_N,    KC_M,     KC_COMM, KC_DOT,  KC_SLSH, _RSH_EN,
    _MEH,     KC_LCTRL, KC_DEL,  KC_LGUI, KC_LALT, MO(FUNC), KC_SPC,  KC_SPC,  MO(FUNC), KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
  ),
    /* COMK - Colemak
   *        ,-----------------------------------------------------------------------------------.
   *        | Esc  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |
   *        |------+------+------+------+------+-------------+------+------+------+------+------|
   *        | + =  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |   -  |
   *        |------+------+------+------+------+------+------+------+------+------+------+------|
   *  RotEn | Del  |   Q  |   W  |   F  |   P  |   G  |   J  |   L  |   U  |   Y  |   :  | \  | |
   * ,------+------+------+------+------+------+------+------+------+------+------+------+------|
   * | QRTY | Bksp | FN/A |   R  |   S  |   T  |   D  |   H  |   N  |   E  |   I  |   O  |  "   |
   * |------+------+------+------+------+------+-------------+------+------+------+------+------|
   * | COMK | Shift|Ctrl/Z|   X  |   C  |   V  |   B  |   K  |   M  |   ,  |   .  |   /  |SH/ENT|
   * |------+------+------+------+------+------+-------------+------+------+------+------+------|
   * | Meh  |`/SYMB| Esc  |  FN  | Alt  | Tab  |    Space    |  FN  | Left | Down |  Up  |Right |
   * `------------------------------------------------------------------------------------------'
   */
  	[COMK] = LAYOUT(
              KC_ESC,  KC_F1,   KC_F2,    KC_F3,   KC_F4,   KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,
              KC_EQL,  KC_1,    KC_2,     KC_3,    KC_4,    KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINUS,
    KC_MUTE,  KC_DEL,  KC_Q,    KC_W,     KC_F,    KC_P,    KC_G,     KC_J,     KC_L,     KC_U,     KC_Y,     KC_SCLN,  KC_BSLS,
    DF(QRTY), KC_BSPC, _FN_A,   KC_R,     KC_S,    KC_T,    KC_D,     KC_H,     KC_N,     KC_E,     KC_I,     _MD_O,    _WN_QOT,
    DF(COMK), KC_LSFT, _CTL_Z,  KC_X,     KC_C,    KC_V,    KC_B,     KC_K,     KC_M,     KC_COMM,  KC_DOT,   _CTL_SL,  _RSH_EN,
    _MEH,     _SY_GRV, KC_ESC,  MO(FUNC), KC_LALT, KC_TAB,  KC_SPC,   KC_SPC,   MO(FUNC), KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT
  ),


  /* SYMB
   *        ,-----------------------------------------------------------------------------------.
   *        |      |  F11 |  F12 |  F13 |  F14 |  F15 |  F16 |  F17 |  F18 |  F19 |  F20 |  F21 |
   *        |------+------+------+------+------+-------------+------+------+------+------+------|
   *        |  `   |      |      |      |      |      |      |      |      |      |      |      |
   *        |------+------+------+------+------+------+------+------+------+------+------+------|
   *  RotEn |      |   !  |   @  |   {  |   }  |   |  |      | Home |  Up  |  End |PrScr |   \  |
   * ,------+------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |   #  |   $  |   (  |   )  |   `  |      | Left | Down |Right |      |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |   %  |   ^  |   [  |   ]  |   ~  |      |      |      |      |      |      |
   * |------+------+------+------+------+------+-------------+------+------+------+------+------|
   * |      |      |      |      |      |      |             |      |      |      |      |      |
   * `------------------------------------------------------------------------------------------'
   */
    [SYMB] = LAYOUT(
              _______,  KC_F11,   KC_F12,   KC_F13,   KC_F14,   KC_F15,   KC_F16,   KC_F17,   KC_F18,   KC_F19,   KC_F20,  KC_F21,
              KC_GRAVE, _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______, _______,
    _______,  _______,  KC_EXLM,  KC_AT,    KC_LCBR,  KC_RCBR,  KC_PIPE,  _______,  KC_HOME,  KC_UP,    KC_END,   KC_PSCR, KC_BSLS,
    _______,  _______,  KC_HASH,  KC_DLR,   KC_LPRN,  KC_RPRN,  KC_GRV,   _______,  KC_LEFT,  KC_DOWN,  KC_RIGHT, _______, _______,
    _______,  _______,  KC_PERC,  KC_CIRC,  KC_LBRC,  KC_RBRC,  KC_TILD,  _______,  _______,  _______,  _______,  _______, _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______, _______
  )
};

void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
}
