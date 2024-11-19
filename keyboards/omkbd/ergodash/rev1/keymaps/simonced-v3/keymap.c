#include QMK_KEYBOARD_H
#include "keymap_japanese.h"

// definition of the layers
enum layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _MOTI,
  _SEL
};

/*======================================================================*/
/*define key combinaisions*/
/*======================================================================*/

// == LAYERS RELATED ==
// TO fully change layer
// TG toggle a layer "on top"
// MO momentary toggle (as long as key pressed)
// LT momentary toggle (like MO, but usable as specified key press)

// ctrl and esc on the same key
#define CTR_ESC MT(MOD_LCTL, KC_ESC)
// same with enter
#define CTR_ENT MT(MOD_RCTL, KC_ENT)
// ctrl and space on the same key
// #define CTRL_SPC MT(MOD_RCTL, KC_SPC)

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
// kana - upper
#define KANA_UP LT(_RAISE, JP_HENK)

// text selection (for _SE layer)
#define SEL_L S(KC_LEFT)
#define SEL_D S(KC_DOWN)
#define SEL_U S(KC_UP)
#define SEL_R S(KC_RIGHT)
#define SEL_H S(KC_HOME)
#define SEL_E S(KC_END)


// some key overrides
const key_override_t spc_del_override = ko_make_basic(MOD_MASK_SHIFT, KC_SPC, KC_DEL);

// This globally defines all key overrides to be used
const key_override_t *key_overrides[] = {
	&spc_del_override
};


/*======================================================================*/
/*layouts*/
/*======================================================================*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT(
    JP_ZKHK,  JP_1,   JP_2,    JP_3,  JP_4,    JP_5,  JP_CIRC,                         JP_AT,    JP_6,  JP_7,  JP_8,    JP_9,    JP_0,    JP_MINS,
    KC_TAB,   KC_Q,   KC_W,    KC_E,  KC_R,    KC_T,  JP_YEN,                          JP_LBRC,  KC_Y,  KC_U,  KC_I,    KC_O,    KC_P,    KC_BSPC,
    CTR_ESC,  KC_A,   KC_S,    KC_D,  F_MOTI,  KC_G,  JP_BSLS,                         JP_RBRC,  KC_H,  KC_J,  KC_K,    KC_L,    JP_SCLN, CTR_ENT,
    KC_LSFT,  KC_Z,   KC_X,    KC_C,  V_SEL,   KC_B,  KC_F11,                          KC_F12,   KC_N,  KC_M,  JP_COMM, JP_DOT,  JP_SLSH, KC_LSFT,
    KC_LCTL, KC_LGUI, KC_LALT, KC_NO,    ROMA_LW, KC_SPC, KC_SPC,                   KC_SPC, KC_SPC, KANA_UP,     KC_LEFT, KC_DOWN, KC_UP, KC_RGHT
  ),

  [_LOWER] = LAYOUT(
    KC_NO,   KC_F1, KC_F2,  KC_F3,   KC_F4,   KC_F5,   KC_NO,                          KC_NO,   KC_F6,   KC_F7,   KC_F8,   KC_F9,    KC_F10, KC_NO,
    _______, JP_1,  JP_2,   JP_3,    _______, _______, _______,                        _______, _______, _______, _______, JP_LABK, JP_RABK, JP_EQL,
    _______, JP_4,  JP_5,   JP_6,    KC_VOLU, _______, _______,                        _______, _______, _______, _______, _______, JP_MINS, JP_COLN,
    _______, JP_7,  JP_8,   JP_9,    KC_VOLD, KC_MPLY, KC_MNXT,                        _______, _______, _______, _______, _______, _______, JP_ASTR,
    _______, JP_0,  JP_DOT, _______,      _______, _______, _______,              _______, _______, _______,      _______, _______, _______, _______
  ),

  [_RAISE] = LAYOUT(
    KC_NO,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,    KC_NO,                               KC_NO,   KC_F6,   KC_F7,   KC_F8,    KC_F9,   KC_F10,  KC_NO,
    KC_F11,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______,                              _______, KC_F6,   KC_F7,   KC_F8,    KC_F9,   KC_F10,  KC_F12,
    JP_ZKHK, JP_EXLM, JP_DQUO, JP_HASH, JP_DLR, JP_PERC,  _______,                             _______, JP_AMPR,  JP_QUOT, JP_LPRN,  JP_RPRN, JP_UNDS, JP_BSLS,
    KC_CAPS, JP_LCBR, JP_RCBR, JP_LBRC, JP_RBRC, _______, _______,                             _______, JP_CIRC,  JP_AT,   JP_GRV,   JP_PIPE, JP_TILD, KC_DEL,
    _______, KC_PSCR, KC_INS,  KC_BRK,      _______, _______, _______,                    _______, _______, _______,       KC_HOME,  KC_PGDN, KC_PGUP, KC_END
  ),

  [_MOTI] = LAYOUT(
    _______, _______, _______, _______, _______, _______,  _______,                          _______, _______,  _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,  _______,                          _______, _______,  _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,  _______,                          _______, KC_LEFT, KC_DOWN,  KC_UP,   KC_RGHT, KC_PGUP, _______,
    _______, _______, _______, _______, _______, _______,  _______,                          _______, _______, KC_HOME,  KC_END,  _______, KC_PGDN, _______,
    _______, _______, _______, _______,     _______, _______, _______,                    _______, _______, _______,     _______, _______, _______, _______
  ),

  [_SEL] = LAYOUT(
    _______, _______, _______, _______, _______, _______,  _______,                          _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,  _______,                          _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,  _______,                          _______, SEL_L,   SEL_D,   SEL_U,   SEL_R,   KC_NO,   _______,
    _______, _______, _______, _______, _______, _______,  _______,                          _______, KC_NO,   SEL_H,   SEL_E,   KC_NO,   KC_NO,   _______,
    _______, _______, _______, _______,     _______, _______, _______,                 _______, _______, _______,       _______, _______, _______, _______
  )

};
