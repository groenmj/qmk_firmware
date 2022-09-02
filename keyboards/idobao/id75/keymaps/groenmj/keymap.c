/* Copyright 2018 Milton Griffin
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

// Keyboard Layers
#define _QW 0
#define _LOWER 1
#define _RAISE 2

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * | '      | 1      | 2      | 3      | 4      | 5      | NUM LK | P*     | =      | 6      | 7      | 8      | 9      | 0      | -      |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
 * | TAB    | Q      | W      | E      | R      | T      | P7     | P8     | P9     | Y      | U      | I      | O      | P      | \      |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | ESC    | A      | S      | D      | F      | G      | P4     | P5     | P6     | H      | J      | K      | L      | ;      | '      |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | LGUI   | Z      | X      | C      | V      | B      | P1     | P2     | P3     | N      | M      | ,      | .      | /      | RCTRL  |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | PrvWin | PSCR   | LALT   | LOWER  | SHIFT  | SPACE  | P0     | P.     | PENTER | BKSPC  | ENTER  | RAISE  | RALT   | INS    | NxtWin |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */

 [_QW] = LAYOUT_ortho_5x15( /* QWERTY */
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_NLCK, KC_PAST, KC_EQL,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINUS,\
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_P7,   KC_P8,   KC_P9,   KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS, \
    LCTL_T(KC_ESC),KC_A,KC_S,  KC_D,    KC_F,    KC_G,    KC_P4,   KC_P5,   KC_P6,   KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
    KC_LGUI, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_P1,   KC_P2,   KC_P3,   KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_RCTL, \
    C(A(S(KC_TAB))), KC_PSCR, KC_LALT, MO(_LOWER), KC_LSFT, KC_SPC,  KC_P0,   KC_PDOT, KC_PENT, KC_BSPC, KC_SFTENT,MO(_RAISE),KC_RALT, KC_INS, C(A(KC_TAB)) \
 ),

/* LOWER
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * | RESET  | M Ac1  | M Ac2  | M Ac3  |        |        | P+     | P-     | P/     | Top    |        |        | Bottom | Pause  | PScr   |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        | VOL+   |MWh Lt  | M Up   |MWh Rt  |MWh Up  |        |        |        | HOME   | PG DWN | PG UP  | END    | INSERT | F12    |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        | VOL-   | M Lt   | M Dw   | M Rt   |MWh Dw  |        |        |        | LEFT   | DOWN   | UP     | RIGHT  |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        | MUTE   |        |        |        |        |        |        |        | Wd Lft | M Bt1  | M Bt2  | Wd Rgt |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |        |        |        |        | DELETE |        |        |        | DELETE |        |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */
 
 [_LOWER] = LAYOUT_ortho_5x15( /* LOWER */
    RESET,   KC_ACL0, KC_ACL1, KC_ACL2, _______, _______, KC_PPLS, KC_PMNS, KC_PSLS, LCTL(KC_HOME), XXXXXXX, XXXXXXX, LCTL(KC_END), KC_PAUSE, KC_PSCR,  \
    _______, KC_VOLU, KC_WH_L, KC_MS_U, KC_WH_R, KC_WH_U, _______, _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_INS,  KC_F12,  \
    _______, KC_VOLD, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______, \
    _______, KC_MUTE, _______, _______, _______, _______, _______, _______, _______, C(KC_LEFT),KC_BTN1, KC_BTN2, C(KC_RGHT), _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_DEL,  _______, _______, _______, KC_DEL,  _______  \
 ),

/* RAISE
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * | RESET  | F1     | F2     | F3     | F4     | F5     | P+     | P-     | P/     | F6     | F7     | F8     | F9     | F10    | =      |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | CAPS   | F11    | F12    | F13	   | F14    | F15    |        | RGB HD | RGB HI | F16    | F17    | F18    | F19    | F20    |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        | !      | @      | #      | $      | %      |        | RGB SD | RGB SI | ^      | &      | *      | (      | )      | `      |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        | <      | {      | [      | (      |        | RGB VD | RGB VI | )      | ]      | }      | >      |  APP   |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | DskLft |        |        |        | LSHFT  |        | RGB TG | RGB RMD| RGB MD | DELETE |        |        |        | DELETE | DskRgt |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */
 
 [_RAISE] = LAYOUT_ortho_5x15( /* RAISE */
    RESET,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_PPLS, KC_PMNS, KC_PSLS, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_EQL,  \
    KC_CAPS, KC_F11,  KC_F12,  KC_F13,  KC_F14,  KC_F15,  _______, RGB_HUD, RGB_HUI, KC_F16,  KC_F17,  KC_F18,  KC_F19,  KC_F20,  _______,  \
    _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, _______, RGB_SAD, RGB_SAI, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_GRAVE, \
    _______, _______, KC_LABK, KC_LCBR, KC_LBRC, KC_LPRN, _______, RGB_VAD, RGB_VAI, KC_RPRN, KC_RBRC, KC_RCBR, KC_RABK, KC_APP,  _______, \
    G(C(KC_LEFT)), _______, _______, _______, LSFT_T(KC_CAPS), _______, RGB_TOG, RGB_RMOD,RGB_MOD, KC_DEL, _______, _______, _______, KC_DEL, G(C(KC_RIGHT))  \
 ),
};
