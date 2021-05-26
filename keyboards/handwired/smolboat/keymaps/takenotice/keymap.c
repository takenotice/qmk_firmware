/*
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

// Layer shorthand
enum layer_names {
    QRTY, // default layer
    TMK1, // Tarmak 1 layer
    TMK2, // Tarmak 2 layer
    TMK3, // Tarmak 3 layer
    TMK4, // Tarmak 4 layer
    CLMK, // Colemak layer
    GAME, // Game layer
    SYMB, // symbols
    MDIA, // media keys
};

#define _MD_A LT(MDIA, KC_A)
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
#define _D_QRTY DF(QRTY)
#define _D_TMK1 DF(TMK1)
#define _D_TMK2 DF(TMK2)
#define _D_TMK3 DF(TMK3)
#define _D_TMK4 DF(TMK4)
#define _D_CLMK DF(CLMK)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Keymap 0: Basic QWERTY layer
 *
 * ,--------------------------------------------------------------------------------------------------------.
 * |   =  |   1  |   2  |   3  |   4  |   5  | [ {  |      |  } ] |   6  |   7  |   8  |   9  |   0  |   -  |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * | Del  |   Q  |   W  |   E  |   R  |   T  | SYMB |      | SYMB |   Y  |   U  |   I  |   O  |   P  |  \   |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * | BkSp |A/MDIA|   S  |   D  |   F  |   G  | SYMB |      | SYMB |   H  |   J  |   K  |   L  |;/MDIA|'/GUI |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shft |Z/Ctrl|   X  |   C  |   V  |   B  |Super |      | Meh  |   N  |   M  |   ,  |   .  |//Ctrl|Shf/En|
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |`/SYMB| Esc  | MDIA | Alt  | Tab  |Sp/MDA|Sp/MDA|      |Space |Space | Left | Down | Up   | Right|~SYMB |
 * `--------------------------------------------------------------------------------------------------------'
 */
  [QRTY] = LAYOUT(
    KC_EQL,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_LBRC,  KC_NO,   KC_RBRC, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
    KC_DEL,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    _SY_MO,   KC_NO,   _SY_MO,  KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
    KC_BSPC, _MD_A,   KC_S,    KC_D,    KC_F,    KC_G,    _SY_MO,   KC_NO,   _SY_MO,  KC_H,    KC_J,    KC_K,    KC_L,    _MD_SCN, _WN_QOT,
    KC_LSFT, _CTL_Z,  KC_X,    KC_C,    KC_V,    KC_B,    _META,    KC_NO,   _MEH,    KC_N,    KC_M,    KC_COMM, KC_DOT,  _CTL_SL, _RSH_EN,
    _SY_GRV, KC_ESC,  _MD_MO,  KC_LALT, KC_TAB,  _MD_SPC, _MD_SPC,  KC_NO,   KC_SPC,  KC_SPC,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _TAP_SY
  ),
/* Keymap 1: Colemak-DHm (Matrix DHm) layer -- Tarmak level 1
 *
 * ,--------------------------------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |   J  |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |   M  |   N  |   E  |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |   K  |   H  |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
 * `--------------------------------------------------------------------------------------------------------'
 */
  [TMK1] = LAYOUT(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_J,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_M,    KC_N,    KC_E,    KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_K,    KC_H,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  ),
  /* Keymap 2: Colemak-DHm (Matrix DHm) layer -- Tarmak level 2
 *
 * ,--------------------------------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |   F  |      |  B   |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |  T   |      |      |      |      |   M  |   N  |   E  |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |  J   |  V   |      |      |      |   K  |   H  |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
 * `--------------------------------------------------------------------------------------------------------'
 */
  [TMK2] = LAYOUT(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_F,    KC_TRNS, KC_B,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_T,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_M,    KC_N,    KC_E,    KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_J,    KC_V,    KC_TRNS, KC_TRNS, KC_TRNS, KC_K,    KC_H,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  ),
  /* Keymap 3: Colemak-DHm (Matrix DHm) layer -- Tarmak level 3
 *
 * ,--------------------------------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |  F   |  J   |  B   |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |  R   |  S   |  T   |      |      |      |      |   M  |   N  |   E  |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |  D   |  V   |      |      |      |   K  |   H  |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
 * `--------------------------------------------------------------------------------------------------------'
 */
  [TMK3] = LAYOUT(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_F,    KC_J,    KC_B,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_R,    KC_S,    KC_T,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_M,    KC_N,    KC_E,    KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_D,    KC_V,    KC_TRNS, KC_TRNS, KC_TRNS, KC_K,    KC_H,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  ),
  /* Keymap 4: Colemak-DHm (Matrix DHm) layer -- Tarmak level 4
 *
 * ,--------------------------------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |  F   |  P   |  B   |      |      |      |   J  |      |      |   Y  |  ; : |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |  R   |  S   |  T   |      |      |      |      |   M  |   N  |   E  |      |   O  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |  D   |  V   |      |      |      |   K  |   H  |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
 * `--------------------------------------------------------------------------------------------------------'
 */
  [TMK4] = LAYOUT(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_F,    KC_P,    KC_B,    KC_TRNS, KC_TRNS, KC_TRNS, KC_J,    KC_TRNS, KC_TRNS, KC_Y,    KC_SCLN, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_R,    KC_S,    KC_T,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_M,    KC_N,    KC_E,    KC_TRNS, _MD_O,   KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_D,    KC_V,    KC_TRNS, KC_TRNS, KC_TRNS, KC_K,    KC_H,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  ),
  /* Keymap 5: Colemak-DHm (Matrix DHm) layer
 *
 * ,--------------------------------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |  F   |  P   |  B   |      |      |      |   J  |   L  |   U  |   Y  |  ; : |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |  R   |  S   |  T   |      |      |      |      |   M  |   N  |   E  |   I  |   O  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |  D   |  V   |      |      |      |   K  |   H  |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
 * `--------------------------------------------------------------------------------------------------------'
 */
  [CLMK] = LAYOUT(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_F,    KC_P,    KC_B,    KC_TRNS, KC_TRNS, KC_TRNS, KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_R,    KC_S,    KC_T,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_M,    KC_N,    KC_E,    KC_I,    _MD_O,   KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_D,    KC_V,    KC_TRNS, KC_TRNS, KC_TRNS, KC_K,    KC_H,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  ),
  /* Keymap 6: Symbol Layer
 *
 * ,--------------------------------------------------------------------------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F21 |  F22 |  F23 |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   !  |   @  |   {  |   }  |   |  |      |  F24 |      |      |   7  |   8  |   9  |   *  |  F12 |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   #  |   $  |   (  |   )  |   `  |      |      |      |      |   4  |   5  |   6  |   +  |   -  |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   %  |   ^  |   [  |   ]  |   ~  |      |      |      |   &  |   1  |   2  |   3  |   \  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |   0  |   0  |   .  |   =  |      |
 * `--------------------------------------------------------------------------------------------------------'
 */
  [SYMB] = LAYOUT(
    KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F21,  KC_F23,  KC_F14,  KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
    KC_TRNS, KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR, KC_PIPE, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_7,    KC_8,    KC_9,    KC_ASTR, KC_F12,
    KC_TRNS, KC_HASH, KC_DLR,  KC_LPRN, KC_RPRN, KC_GRV,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_4,    KC_5,    KC_6,    KC_PLUS, KC_MINS,
    KC_TRNS, KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_TILD, KC_TRNS, KC_TRNS, KC_TRNS, KC_AMPR, KC_1,    KC_2,    KC_3,    KC_BSLS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_0,    KC_0,    KC_DOT,  KC_EQL,  KC_TRNS
  ),
/* Keymap 7: Media and mouse keys
 *
 * ,--------------------------------------------------------------------------------------------------------.
 * |  Esc | F11  | F12  | F13  | F14  | F15  |QWERTY|TARMK1|TARMK1| F16  | F17  | F18  | F19  | F20  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |MsWhL |MsWhUp| MsUp |MsWhDn|MsWhR |      |TARMK2|      | PgUp | Home |      | End  |PrtSc |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * | CAPS |      |MsLeft|MsDown|MsRght|      |      |TARMK3|      | Left | Down | Up   | Right|      | Play |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |MsBtn4| Calc |MsBtn5|      |      |TARMK4|      | PgDn | Mute | Prev | Next | Ins  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * | EPRM | RESET|      | Lclk | Rclk |      |      |      |      |      |      |VolDn |VolUp |      |      |
 * `--------------------------------------------------------------------------------------------------------'
 */
  [MDIA] = LAYOUT(
    KC_ESC,  KC_F11,  KC_F12,  KC_F13,  KC_F14,  KC_F15,  _D_QRTY, _D_TMK1, _D_CLMK, KC_F16,  KC_F17,  KC_F18,  KC_F19,   KC_F20,  KC_TRNS,
    KC_TRNS, KC_WH_L, KC_WH_U, KC_MS_U, KC_WH_D, KC_WH_R, KC_TRNS, _D_TMK2, KC_TRNS, KC_PGUP, KC_HOME, KC_TRNS, KC_END,   KC_PSCR, KC_TRNS,
    KC_CAPS, KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS, KC_TRNS, _D_TMK3, KC_TRNS, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, KC_TRNS, KC_MPLY,
    KC_TRNS, KC_TRNS, KC_BTN4, KC_CALC, KC_BTN5, KC_TRNS, KC_TRNS, _D_TMK4, KC_TRNS, KC_PGDN, KC_MUTE, KC_MPRV, KC_MNXT,  KC_INS,  KC_TRNS,
    EEP_RST, RESET,   KC_TRNS, KC_BTN1, KC_BTN2, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_VOLD, KC_VOLU,  KC_TRNS, KC_TRNS
  )
};


