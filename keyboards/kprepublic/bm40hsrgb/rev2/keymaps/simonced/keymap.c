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
  _FN,
  _MOTI,
  _SEL,
  _ADJUST
};

// CTRL and ESC on the same key
//#define CTR_ESC MT(MOD_LCTL, KC_ESC)
// CTRL and TAB on the same key
#define CTR_TAB MT(MOD_LCTL, KC_TAB)
// same for Enter
#define CTR_ENT MT(MOD_RCTL, KC_ENT)
// CTRL and SPC on the same key
// #define CTR_SPC MT(MOD_LCTL, KC_SPC)

// shift and backspace on the same key
// #define SFT_BSP MT(MOD_LSFT, KC_BSPC)

// shift and enter on the same key
// #define SFT_ENT MT(MOD_LSFT, KC_ENT)

// F or _MOTI
#define F_MOTI LT(_MOTI, KC_F)
// V or _SEL
#define V_SEL  LT(_SEL,  KC_V)
// eigo - lower
#define ROMA_LW LT(_LOWER, JP_MHEN)
// left - lower (to type numbers with left hand while holding layer on right hand?)
#define LEFT_LW LT(_LOWER, KC_LEFT)
// kana - upper
#define KANA_UP LT(_RAISE, JP_HENK)
// specific function keys
#define FN LT(_FN, KC_NO)
#define RGHT_FN LT(_FN, KC_RGHT)

// text selection (for _SE layer)
#define SEL_L S(KC_LEFT)
#define SEL_D S(KC_DOWN)
#define SEL_U S(KC_UP)
#define SEL_R S(KC_RIGHT)
#define SEL_H S(KC_HOME)
#define SEL_E S(KC_END)


// some key overrides
const key_override_t spc_del_override = ko_make_basic(MOD_MASK_SHIFT, KC_BSPC, KC_DEL);

// This globally defines all key overrides to be used
const key_override_t *key_overrides[] = {
	&spc_del_override
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


[_QWERTY] = LAYOUT_ortho_4x12_1x2uC(
    KC_ESC,   KC_Q,    KC_W,    KC_E,  KC_R,    KC_T,    KC_Y, KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    CTR_TAB,  KC_A,    KC_S,    KC_D,  F_MOTI,  KC_G,    KC_H, KC_J,    KC_K,    KC_L,    JP_SCLN, CTR_ENT,
    KC_LSFT,  KC_Z,    KC_X,    KC_C,  V_SEL,   KC_B,    KC_N, KC_M,    JP_COMM, JP_DOT,  JP_SLSH, KC_RSFT,
    KC_LCTL,  KC_LGUI, KC_LALT, FN,    ROMA_LW,     KC_SPC,    KANA_UP, LEFT_LW, KC_DOWN, KC_UP,   RGHT_FN
),

[_LOWER] = LAYOUT_ortho_4x12_1x2uC(
    _______, JP_1, JP_2,   JP_3,     _______, _______, _______, _______,     _______, JP_LABK, JP_RABK, JP_EQL,
    _______, JP_4, JP_5,   JP_6,     KC_VOLU, _______, _______, _______,     _______, _______, JP_MINS, JP_COLN,
    _______, JP_7, JP_8,   JP_9,     KC_VOLD, KC_MPLY, KC_MNXT, _______,     _______, _______, _______, JP_ASTR,
    _______, JP_0, JP_DOT,  _______, _______,      _______,     MO(_ADJUST), _______, _______, _______, _______
),

[_RAISE] = LAYOUT_ortho_4x12_1x2uC(
    JP_ZKHK, JP_EXLM, JP_DQUO, JP_HASH, JP_DLR,   JP_PERC, JP_AMPR, JP_QUOT, JP_LPRN, JP_RPRN, _______, _______,
    _______, JP_LCBR, JP_RCBR, JP_LBRC, JP_RBRC,  _______, _______, KC_INS,  KC_DEL,  _______, JP_UNDS, JP_PIPE,
    KC_CAPS, _______, _______, _______, _______,  _______, JP_CIRC, JP_AT,   JP_GRV,  JP_TILD, JP_BSLS, _______,
    _______, KC_PSCR, KC_INS,  KC_BRK,  MO(_ADJUST),    _______,    _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END
),

[_FN] = LAYOUT_ortho_4x12_1x2uC(
    KC_F11,  KC_F1,   KC_F2,   KC_F3,   KC_F4,         KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F12,
    _______, _______, _______, _______, _______,       _______, _______, _______,  _______, _______, _______, _______,
    _______, _______, _______, _______, _______,       _______, _______, _______,  _______, _______, _______, _______,
    _______, _______, _______, _______,        _______,         _______, _______, _______,  _______, _______, _______
),

[_MOTI] = LAYOUT_ortho_4x12_1x2uC(
    _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN,   KC_UP,  KC_RGHT, KC_PGUP, _______,
    _______, _______, _______, _______, _______, _______, _______, KC_HOME,  KC_END,  _______, KC_PGDN, _______,
    _______, _______, _______, _______, _______,     _______,      _______, _______,  _______, _______, _______
),

[_SEL] = LAYOUT_ortho_4x12_1x2uC(
    _______, _______, _______, _______, _______, _______, _______, _______,  _______,  _______, _______, _______,
    _______, _______, _______, _______, _______, _______, SEL_L,   SEL_D,    SEL_U,    SEL_R,   KC_NO,   _______,
    _______, _______, _______, _______, _______, _______, KC_NO,   SEL_H,    SEL_E,    KC_NO,   KC_NO,   _______,
    _______, _______, _______, _______, _______,      _______,      _______, _______,  _______, _______, _______
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
