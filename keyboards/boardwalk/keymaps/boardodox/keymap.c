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
    // QRTY, // default layer
    COMK, // Colemak layer
    GAME, // Game layer
    SYMB, // symbols
    MDIA, // media keys
    // ABRT, // abort layer
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
// #define _D_QRTY DF(QRTY)
// #define _D_COMK DF(COMK)
#define _TG_GAM TG(GAME)
// #define LOWER MO(_LO)
// #define RAISE TG(_UP)
// #define FN    MO(_FN)
// #define LCBRC S(KC_LBRC)
// #define RCBRC S(KC_RBRC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Keymap 0: Colemak Matrix
 *
 * ,-----------------------------------------------------------------------------------------------------.
 * |   =    |   1  |   2  |   3  |   4  |   5  | [ {  |  } ] |   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|------+------+------+------+------+------+--------|
 * | Delete |   Q  |   W  |   F  |   P  |   G  | SYMB | SYMB |   J  |   L  |   U  |   Y  |   ;  |   \    |
 * |--------+------+------+------+------+------|      |      |------+------+------+------+------+--------|
 * | BkSp   |A/MDIA|   R  |   S  |   T  |   D  |------|------|   M  |   N  |   E  |   I  |O/MDIA|' / GUI |
 * |--------+------+------+------+------+------| Hyper| Meh  |------+------+------+------+------+--------|
 * | LShift |Z/Ctrl|   X  |   C  |   V  |   B  |      |      |   K  |   H  |   ,  |   .  |//Ctrl| RShift |
 * |--------+------+------+------+------+-------------'-------------+------+------+------+------+--------|
 * |Grv/SYMB| ESC  | MDIA | Alt  | Tab  | Space/MEDIA |    Space    | Left | Down | Up   | Right| ~SYMB  |
 * `-----------------------------------------------------------------------------------------------------'
 */
[COMK] = LAYOUT_ortho_5x14(
// [BASE] = LAYOUT_full_ergo(
  KC_EQL,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_LBRC, KC_RBRC, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
  KC_DEL,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    _SY_MO,  _SY_MO,  KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSLS,
  KC_BSPC, _MD_A,   KC_R,    KC_S,    KC_T,    KC_D,    XXXXXXX, XXXXXXX, KC_H,    KC_N,    KC_E,    KC_I,    _MD_O,   _WN_QOT,
  KC_LSFT, _CTL_Z,  KC_X,    KC_C,    KC_V,    KC_B,    _META,   _MEH,    KC_K,    KC_M,    KC_COMM, KC_DOT,  _CTL_SL, _RSH_EN,
  _SY_GRV, KC_ESC,  _MD_MO,  KC_LALT, KC_TAB,  _MD_SPC, XXXXXXX, KC_SPC,  XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _TAP_SY
),


/* Keymap 1: Game layer
 *
 * ,-----------------------------------------------------------------------------------------------------.
 * |        |      |      |      |      |      |      |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  |      |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |      |------+------+------+------+------+--------|
 * | Caps   |   A  |   S  |   D  |   F  |   G  |------|------|      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |      |------+------+------+------+------+--------|
 * |        |   Z  |   X  |   C  |   V  |   B  |      |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------'-------------+------+------+------+------+--------|
 * | Ctrl   |      |      |      |      |    Space    |             |      |      |      |      |        |
 * `-----------------------------------------------------------------------------------------------------'
 */
[GAME] = LAYOUT_ortho_5x14(
// [BASE] = LAYOUT_full_ergo(
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    XXXXXXX, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_LCTL, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_SPC,  XXXXXXX, KC_TRNS, XXXXXXX, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
),

/* Keymap 2: Symbol Layer
 *
 * ,-----------------------------------------------------------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  | F13  | F14  |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |--------+------+------+------+------+------+------|------+------+------+------+------+------+--------|
 * |        |   !  |   @  |   {  |   }  |   |  |      |      |      |   7  |   8  |   9  |   *  |   F12  |
 * |--------+------+------+------+------+------|      |      |------+------+------+------+------+--------|
 * |        |   #  |   $  |   (  |   )  |   `  |------|------|      |   4  |   5  |   6  |   +  |        |
 * |--------+------+------+------+------+------|      |      |------+------+------+------+------+--------|
 * |        |   %  |   ^  |   [  |   ]  |   ~  |      |      |   &  |   1  |   2  |   3  |   \  |        |
 * |--------+------+------+------+------+------'------'------'------+------+------+------+------+--------|
 * |        |      |      |      |      |             |             |   0  |   0  |   .  |   =  |        |
 * `-----------------------------------------------------------------------------------------------------'
 */
[SYMB] = LAYOUT_ortho_5x14(
// [SYMB] = LAYOUT_full_ergo(
  KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F13,  KC_F14,  KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  KC_TRNS, KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR, KC_PIPE, KC_TRNS, KC_TRNS, KC_TRNS, KC_7,    KC_8,    KC_9,    KC_ASTR, KC_F12,
  KC_TRNS, KC_HASH, KC_DLR,  KC_LPRN, KC_RPRN, KC_GRV,  XXXXXXX, XXXXXXX, KC_TRNS, KC_4,    KC_5,    KC_6,    KC_PLUS, KC_TRNS,
  KC_TRNS, KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_TILD, KC_TRNS, KC_TRNS, KC_AMPR, KC_1,    KC_2,    KC_3,    KC_BSLS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, XXXXXXX, KC_TRNS, XXXXXXX, KC_0,    KC_0,    KC_DOT,  KC_EQL,  KC_TRNS
),
/* Keymap 3: Media and mouse keys
 *
 * ,-----------------------------------------------------------------------------------------------------.
 * |        | F21  | F22  | F13  | F14  | F15  |QWERTY|COLMAK| F16  | F17  | F18  | F19  | F20  |  GAME  |
 * |--------+------+------+------+------+-------------|------+------+------+------+------+------+--------|
 * |        |MsWhL |MsWhUp| MsUp |MsWhDn|MsWhR |      |      | PgUp | Home |      | End  |PrtSc |        |
 * |--------+------+------+------+------+------|      |      |------+------+------+------+------+--------|
 * | Caps   |      |MsLeft|MsDown|MsRght|      |------|------| Left | Down | Up   | Right|      |  Play  |
 * |--------+------+------+------+------+------|      |      |------+------+------+------+------+--------|
 * |        |      |MsBtn4| CALC |MsBtn5|      |      |      | PgDn | Mute | Prev | Next | Ins  |        |
 * |--------+------+------+------+------+-------------'-------------+------+------+------+------+--------|
 * | EPRM   | RESET|      | Lclk | Rclk |             |             |      |VolDn |VolUp |      |        |
 * `-----------------------------------------------------------------------------------------------------'
 */
[MDIA] = LAYOUT_ortho_5x14(
// [SYMB] = LAYOUT_full_ergo(
  KC_TRNS, KC_F21,  KC_F22,  KC_F13,  KC_F14,  KC_F15,  KC_TRNS, KC_TRNS, KC_F16,  KC_F17,  KC_F18,  KC_F19,  KC_F20,  _TG_GAM,
  KC_TRNS, KC_WH_L, KC_WH_U, KC_MS_U, KC_WH_D, KC_WH_R, KC_TRNS, KC_TRNS, KC_PGUP, KC_HOME, KC_TRNS, KC_END,  KC_PSCR, KC_TRNS,
  KC_CAPS, KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS, XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_TRNS, KC_MPLY,
  KC_TRNS, KC_TRNS, KC_BTN4, KC_CALC, KC_BTN5, KC_TRNS, KC_TRNS, KC_TRNS, KC_PGDN, KC_MUTE, KC_MPRV, KC_MNXT, KC_INS,  KC_TRNS,
  EEP_RST, RESET,   KC_TRNS, KC_BTN1, KC_BTN2, KC_TRNS, XXXXXXX, KC_TRNS, XXXXXXX, KC_TRNS, KC_VOLD, KC_VOLU, KC_TRNS, KC_TRNS
)
};







// /* Keymap 1: Colemak-DHm (Matrix DHm) layer -- Tarmak level 1
//  *
//  * ,-----------------------------------------------------------------------------------------------------.
//  * |        |      |      |      |      |      |      |      |      |      |      |      |      |        |
//  * |--------+------+------+------+------+-------------|------+------+------+------+------+------+--------|
//  * |        |      |      |   J  |      |      |      |      |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------|      |      |------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |------|------|   M  |   N  |   E  |      |      |        |
//  * |--------+------+------+------+------+------|      |      |------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |      |      |   K  |   H  |      |      |      |        |
//  * |--------+------+------+------+------+-------------'-------------+------+------+------+------+--------|
//  * |        |      |      |      |      |             |             |      |      |      |      |        |
//  * `-----------------------------------------------------------------------------------------------------'
//  */
// [COMK] = LAYOUT_ortho_5x14(
// // [COMK] = LAYOUT_full_ergo(
//   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
//   KC_TRNS, KC_TRNS, KC_TRNS, KC_J,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
//   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, XXXXXXX, XXXXXXX, KC_M,    KC_N,    KC_E,    KC_TRNS, KC_TRNS, KC_TRNS,
//   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_K,    KC_H,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
//   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, XXXXXXX, KC_TRNS, XXXXXXX, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
// ),
// /* Keymap 1: Colemak-DHm (Matrix DHm) layer
//  *
//  * ,--------------------------------------------------------------------------------------------------------.
//  * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
//  * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
//  * |      |      |      |   F  |   P  |   B  |      |      |      |   J  |   L  |   U  |   Y  |  ; : |      |
//  * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
//  * |      |      |   R  |   S  |   T  |      |      |      |      |   M  |   N  |   E  |   I  |   O  |      |
//  * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
//  * |      |      |      |      |   D  |   V  |      |      |      |   K  |   H  |      |      |      |      |
//  * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
//  * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
//  * `--------------------------------------------------------------------------------------------------------'
//  */
//   [COMK] = LAYOUT(
//     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
//     KC_TRNS, KC_TRNS, KC_TRNS, KC_F,    KC_P,    KC_B,    KC_TRNS, KC_TRNS, KC_TRNS, KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_TRNS,
//     KC_TRNS, _MD_A,   KC_R,    KC_S,    KC_T,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_M,    KC_N,    KC_E,    KC_I,    _MD_O,   KC_TRNS,
//     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_D,    KC_V,    KC_TRNS, KC_TRNS, KC_TRNS, KC_K,    KC_H,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
//     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
//   ),


// const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

//     /* Base Layer
//      * .-----------------------------------------------------------------------------------------------------------------------------.
//      * | GESC   | 1      | 2      | 3      | 4      | 5      | -      | =      | 6      | 7      | 8      | 9      | 0      | BACKSP |
//      * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
//      * | TAB    | Q      | W      | E      | R      | T      |        |        | Y      | U      | I      | O      | P      | '      |
//      * |--------+--------+--------+--------+--------+--------| PGUP   | HOME   |--------+--------+--------+--------+--------+--------|
//      * | CAP LK | A      | S      | D      | F      | G      |--------|--------| H      | J      | K      | L      | ;      | ENTER  |
//      * |--------+--------+--------+--------+--------+--------|        |        |--------+--------+-----------------+--------+--------|
//      * | LSHIFT | Z      | X      | C      | V      | B      | PGDN   | END    | N      | M      | ,      | .      | /      | RSHIFT |
//      * |--------+--------+--------+--------+--------+-----------------+-----------------+--------+-----------------+--------+--------|
//      * | LCTRL  | LGUI   | LOWER  | LALT   | FN     |      SPACE      |      SPACE      | LEFT   | DOWN   | UP     | RIGHT  | RCTRL  |
//      * '-----------------------------------------------------------------------------------------------------------------------------'
//      */
//     [_BASE] = LAYOUT_ortho_5x14( // Modified for 2u Ergo layout with 1.5u center keys, some keys omitted.
//         KC_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_MINS, KC_EQL,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
//         KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_PGUP, KC_HOME, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_QUOT,
//         KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    XXXXXXX, XXXXXXX, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,
//         KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_PGDN, KC_END,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
//         KC_LCTL, KC_LGUI, LOWER,   KC_LALT, FN,      KC_SPC,  XXXXXXX, KC_SPC,  XXXXXXX, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_RCTL
//     ),
//     /* Function Layer
//      * .-----------------------------------------------------------------------------------------------------------------------------.
//      * | `      |        |        |        |        |        | [      | ]      |        | [      | ]      | {      | }      | DEL    |
//      * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
//      * |        |        |        |        |        |        | VOL UP | TRK <  |        | PAUSEBR| INSERT | SCRLK  | PRT SC | \      |
//      * |--------+--------+--------+--------+--------+--------|        |        |--------+--------+--------+--------+--------+--------|
//      * |        |        |        |        | MYCMP  |        |--------|--------| LEFT   | DOWN   | UP     | RIGHT  |        |        |
//      * |--------+--------+--------+--------+--------+--------|        |        |--------+--------+-----------------+--------+--------|
//      * |        |        |        | CALC   |        |        | VOL DN | TRK >  |        | MUTE   |        |        |        |        |
//      * |--------+--------+--------+--------+--------+-----------------+-----------------+--------+-----------------+--------+--------|
//      * |        |        |        |        |        | PLAY/PAUSE      | RAISE           |        |        |        |        |        |
//      * '-----------------------------------------------------------------------------------------------------------------------------'
//      */
//     [_FN] = LAYOUT_ortho_5x14(
//         KC_GRV,  _______, _______, _______, _______, _______, KC_LBRC, KC_RBRC, _______,  KC_LBRC, KC_RBRC, KC_LCBR, KC_RCBR, KC_DEL,
//         _______, _______, _______, _______, _______, _______, KC_VOLU, KC_MPRV, _______, KC_PAUS, KC_INS,  KC_SLCK, KC_PSCR, KC_BSLS,
//         _______, _______, _______, _______, KC_MYCM, _______, XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,
//         _______, _______, _______, KC_CALC, _______, _______, KC_VOLD, KC_MNXT, _______, KC_MUTE, _______, _______, _______, _______,
//         _______, _______, _______, _______, _______, KC_MPLY, XXXXXXX, RAISE,   XXXXXXX, _______, _______, _______, _______, _______
//     ),
//     /* Upper Layer
//      * .-----------------------------------------------------------------------------------------------------------------------------.
//      * |        |        |        |        |        |        |        |        |        | NUMLOCK| /      | *      | -      |
//      * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
//      * |        |        |        | RESET  |        |        |        |        |        | 7      | 8      | 9      | +      |        |
//      * |--------+--------+--------+--------+--------+--------|        |        |--------+--------+--------+--------+--------+--------|
//      * |        |        |        |        |        |        |--------+--------|        | 4      | 5      | 6      | +      |        |
//      * |--------+--------+--------+--------+--------+--------|        |        |--------+--------+-----------------+--------+--------|
//      * |        |        |        |        |        |        |        |        |        | 1      | 2      | 3      | Enter  |        |
//      * |--------+--------+--------+--------+--------+-----------------+-----------------+--------+-----------------+--------+--------|
//      * |        |        |        |        | FN     |                 | RAISE           | 0      | 0      | .      | Enter  |        |
//      * '-----------------------------------------------------------------------------------------------------------------------------'
//      */
//     [_UP] = LAYOUT_ortho_5x14(
//         _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_NLCK, KC_PSLS, KC_PAST,  KC_PMNS, _______,
//         _______, _______, _______, RESET,   _______, _______, _______, _______, _______, KC_P7,   KC_P8,   KC_P9,    KC_PPLS, _______,
//         _______, _______, _______, _______, _______, _______, XXXXXXX, XXXXXXX, _______, KC_P4,   KC_P5,   KC_P6,    KC_PPLS, _______,
//         _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_P1,   KC_P2,   KC_P3,    KC_PENT, _______,
//         _______, _______, _______, _______, FN,      _______, XXXXXXX, RAISE,   XXXXXXX, KC_P0,   KC_P0,   KC_PDOT,  KC_PENT, _______
//     ),

//     /* Lower Layer
//      * .-----------------------------------------------------------------------------------------------------------------------------.
//      * |        | F1     | F2     | F3     | F4     | F5     |        |        | F6     | F7     | F8     | F9     | F10    |        |
//      * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
//      * |        | F11    | F22    | F13    | F14    | F15    |        |        | F16    | F17    | F18    | F19    | F20    | PIPE   |
//      * |--------+--------+--------+--------+--------+--------|        |        |--------+--------+--------+--------+--------+--------|
//      * |        | F21    | F22    | F23    | F24    |        |--------+--------|        |        | VAL-   | VAL+   |        |        |
//      * |--------+--------+--------+--------+--------+--------|        |        |--------+--------+--------+--------+--------+--------|
//      * |        |        |        |        |        |        |        |        |        |        | SAT-   | SAT+   |        |        |
//      * |--------+--------+--------+--------+--------+-----------------+-----------------+--------+--------+--------+--------+--------|
//      * |        |        |        |        |        |                 | RGB ON/OFF      | MODE-  | HUE-   | HUE+   | MODE+  |        |
//      * '-----------------------------------------------------------------------------------------------------------------------------'
//      */
//     [_LO] = LAYOUT_ortho_5x14(
//         _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______, _______, KC_F6,   KC_F7,    KC_F8,   KC_F9,    KC_F10,  _______,
//         _______, KC_F11,  KC_F12,  KC_F13,  KC_F14,  KC_F15,  _______, _______, KC_F16,  KC_F17,   KC_F18,  KC_F19,   KC_F20,  KC_PIPE,
//         _______, KC_F21,  KC_F22,  KC_F23,  KC_F24,  _______, XXXXXXX, XXXXXXX, _______, _______,  RGB_VAD, RGB_VAI,  _______, _______,
//         _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  RGB_SAD, RGB_SAI,  _______, _______,
//         _______, _______, _______, _______, _______, _______, XXXXXXX, RGB_TOG, XXXXXXX, RGB_RMOD, RGB_HUD, RGB_HUI,  RGB_MOD, _______
//     )


