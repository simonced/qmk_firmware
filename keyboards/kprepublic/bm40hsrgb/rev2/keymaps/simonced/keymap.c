/* Copyright 2020 tominabox1
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
#include "keymap_japanese.h"

enum layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST
};

// ctrl and esc on the same key
#define CTR_ESC MT(MOD_LCTL, KC_ESC)
// shift and backspace on the same key
#define SFT_BSP MT(MOD_LSFT, KC_BSPC)

// eigo - lower
#define ROMA_LW LT(_LOWER, JP_MHEN)
// kana - upper
#define KANA_UP LT(_RAISE, JP_HENK)

// text selection (for _SE layer)
#define SEL_L S(KC_LEFT)
#define SEL_D S(KC_DOWN)
#define SEL_U S(KC_UP)
#define SEL_R S(KC_RIGHT)
#define SEL_H S(KC_HOME)
#define SEL_E S(KC_END)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


[_QWERTY] = LAYOUT_ortho_4x12_1x2uC(
    KC_TAB,   KC_Q,    KC_W,    KC_E,  KC_R,    KC_T,    KC_Y, KC_U,    KC_I,    KC_O,    KC_P,    JP_AT,
    CTR_ESC,  KC_A,    KC_S,    KC_D,  KC_F,    KC_G,    KC_H, KC_J,    KC_K,    KC_L,    JP_SCLN, KC_ENT,
    KC_LSFT,  KC_Z,    KC_X,    KC_C,  KC_V,    KC_B,    KC_N, KC_M,    JP_COMM, JP_DOT,  JP_COLN, SFT_BSP,
    KC_LCTL,  KC_LGUI, KC_LALT, KC_NO, ROMA_LW,     KC_SPC,    KANA_UP, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),


[_LOWER] = LAYOUT_ortho_4x12_1x2uC(
    _______, JP_1, JP_2,    JP_3,    _______, _______, JP_CIRC, JP_PIPE,     JP_TILD, JP_LABK, JP_RABK, JP_EQL,
    _______, JP_4, JP_5,    JP_6,    _______, _______, KC_LEFT, KC_DOWN,     KC_UP,   KC_RGHT, JP_MINS, _______,
    _______, JP_7, JP_8,    JP_9,    KC_MNXT, _______, _______, _______,     JP_SLSH, JP_BSLS, JP_QUES, ,
    _______, JP_0, KC_VOLD, KC_VOLU, _______,      KC_MPLY,     MO(_ADJUST), _______, _______, _______, _______
),


[_RAISE] = LAYOUT_ortho_4x12_1x2uC(
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,       KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
    _______, JP_EXLM, JP_DQUO, JP_HASH, JP_DLR,      JP_PERC, JP_AMPR, JP_QUOT, JP_LPRN, JP_RPRN, JP_UNDS, KC_F12,
    KC_CAPS, _______, _______, _______, _______,     _______, _______, JP_LCBR, JP_RCBR, JP_LBRC, JP_RBRC, KC_DEL,
    _______, KC_PSCR, KC_INS,  KC_BRK,  MO(_ADJUST),      _______,     _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END
),

/* Adjust (Lower + Raise)
 *                      v------------------------RGB CONTROL--------------------v
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|Debug | RGB  |RGBMOD| HUE+ | HUE- | SAT+ | SAT- |BRGTH+|BRGTH-|  Del |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_ortho_4x12_1x2uC(
    _______, QK_BOOT, DB_TOGG, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD,  RGB_VAI, RGB_VAD, KC_DEL ,
    _______, _______, _______, _______, _______, _______, _______, _______,  _______,  _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______,  _______,  _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______
)

};

