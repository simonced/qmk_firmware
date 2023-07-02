#include QMK_KEYBOARD_H
#include "keymap_japanese.h"

// definition of the layers
enum {
    LAYER_BASE = 0,
    LAYER_SYMB,
    LAYER_NUM,
    LAYER_GAME
};

/*======================================================================*/
/*define key combinaisions*/
/*======================================================================*/

// == LAYERS RELATED ==

#define LAY0 TO(LAYER_BASE) // Go [TO] base layer
#define LAY1 MO(LAYER_SYMB) // [MO]memtary layer (non assigned keys are "transparent")
#define LAY2 TG(LAYER_NUM)  // [T]o[G]gle layer on/off (non assigned keys are "transparent")
#define LAY3 TO(LAYER_GAME) // Go [TO] layer (all keys replaced)
#define F_FUN LT(LAYER_SYMB, KC_F)

// == SHORTCUTS RELATED ==

// IME toggle
#define EISU LALT(KC_GRV)

// ctrl and esc on the same key
#define CTR_ESC MT(MOD_LCTL, KC_ESC)
// shift and capslocks on the same key
#define SFT_CAP MT(MOD_LSFT, KC_CAPS)

// changing virtual desktop (only left and right)
#define DESK_R G(C(KC_RIGHT))
#define DESK_L G(C(KC_LEFT))

/*
// moving windows in screen(s) (4 directions)
#define WIN_MR G(S(KC_RIGHT))
#define WIN_ML G(S(KC_LEFT))
#define WIN_MU G(S(KC_UP))
#define WIN_MD G(S(KC_DOWN))

// resizing windows
#define WIN_RR G(KC_RIGHT)
#define WIN_RL G(KC_LEFT)
#define WIN_RU G(KC_UP)
#define WIN_RD G(KC_DOWN)

// text selection (for _SE layer)
#define SEL_L S(KC_LEFT)
#define SEL_D S(KC_DOWN)
#define SEL_U S(KC_UP)
#define SEL_R S(KC_RIGHT)
#define SEL_H S(KC_HOME)
#define SEL_E S(KC_END)
*/


/*======================================================================*/
/*layouts*/
/*======================================================================*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /*
   * QWERTY (JIS) by default
   * ,------------------------------------------------.                    ,------------------------------------------------.
   * | 英数 |   1  |   2  |   3  |   4  |   5  |   -  |                    |   ^  |   6  |   7  |   8  |   9  |   0  | BSPC |
   * |------+------+------+------+------+------+------|                    |------+------+------+------+------+------+------|
   * | Tab  |   Q  |   W  |   E  |   R  |   T  |   [  |                    |   ]  |   Y  |   U  |   I  |   O  |   P  |  @   |
   * |------+------+------+------+------+------+------|                    |------+------+------+------+------+------+------|
   * | Esc  |   A  |   S  |   D  |   F  |   G  | DEL  |                    | BSPC |   H  |   J  |   K  |   L  |   ;  |  :   |
   * |------+------+------+------+------+------+------|                    |------+------+------+------+------+------+------|
   * | CAPS |   Z  |   X  |   C  |   V  |   B  | Alt  |                    | AltG |   N  |   M  |   ,  |   .  |   /  |  \   |
   * |-------------+------+------+------+------+------+------.      ,------+------+------+------+------+------+-------------|
   * | GUI  |  ALT |      |      |      | Shift| Ctrl | Space|      | Enter| Ctrl | Shift|      |      |      |      |      |
   * `---------------------------'      `--------------------'      `--------------------'      `---------------------------'
   */
  [LAYER_BASE] = LAYOUT( \
    EISU ,   JP_1,   JP_2, JP_3, JP_4,  JP_5,    JP_MINS,                         JP_CIRC, JP_6, JP_7, JP_8,    JP_9,    JP_0,    KC_BSPC, \
    KC_TAB , KC_Q,   KC_W, KC_E, KC_R,  KC_T,    JP_LBRC,                         JP_RBRC, KC_Y, KC_U, KC_I,    KC_O,    KC_P,    JP_AT,   \
    CTR_ESC, KC_A,   KC_S, KC_D, F_FUN, KC_G,    KC_DEL,                          KC_BSPC, KC_H, KC_J, KC_K,    KC_L,    JP_SCLN, JP_COLN, \
    SFT_CAP, KC_Z,   KC_X, KC_C, KC_V,  KC_B,    KC_LALT,                         KC_ALGR, KC_N, KC_M, JP_COMM, JP_DOT,  JP_SLSH, JP_BSLS, \
    KC_LGUI, KC_LALT, LAY3, LAY2,      KC_LSFT,  KC_LCTL, KC_SPC,         KC_ENT, KC_RCTL, KC_RSFT,    KC_MNXT, KC_MPLY, KC_VOLD, KC_VOLU  \
  ),

  /*
   * Motion +Symbols layer
   * ,------------------------------------------------.                    ,------------------------------------------------.
   * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F11 |                    |  F12 |  F6  |  F7  |  F8  |  F9  |  F10 | home |
   * |------+------+------+------+------+------+------|                    |------+------+------+------+------+------+------|
   * |      |  !   |  "   |  #   |  $   |  %   |      |                    |      |  &   |  '   |  (   |  )   |  |   | end  |
   * |------+------+------+------+------+------+------|                    |------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |                    |      | LEFT | DOWN |  UP  | RGHT |      |      |
   * |------+------+------+------+------+------+------+------,      ,------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |      |      |      |      |      |  {   |  }   |  [   |  ]   | pgup |
   * |-------------+------+------+------+------+------|      |      |      |------+------+------+------+------+-------------|
   * |      |      |      |      |      |      |      |      |      |      |      |      |      | pscr |  ins |      | pgdn |
   * `---------------------------'      `--------------------'      `--------------------'      `---------------------------'
   */
  [LAYER_SYMB] = LAYOUT(
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,  KC_F5,    KC_F11,                           KC_F12,  KC_F6,   KC_F7,   KC_F8,   KC_F9,    KC_F10,  KC_HOME, \
    _______, JP_EXLM, JP_DQUO, JP_HASH, JP_DLR, JP_PERC,  _______,                          _______, JP_AMPR, JP_QUOT, JP_LPRN, JP_RPRN,  JP_PIPE, KC_END,  \
    _______, _______, _______, _______, _______, _______, _______,                          _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______,                          _______, _______, JP_LCBR, JP_RCBR, JP_LBRC,  JP_RBRC, KC_PGUP, \
    _______, _______, _______, _______,          _______, _______,_______,          _______,_______, _______,          KC_PSCR, KC_INS,   _______, KC_PGDN  \
  ),

  /*
   * Numbers
   * ,------------------------------------------------.                    ,------------------------------------------------.
   * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F11 |                    |      |      |      |  /   |  *   |  -   |      |
   * |------+------+------+------+------+------+------|                    |------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |                    |      |      |  7   |  8   |  9   |  +   |      |
   * |------+------+------+------+------+------+------|                    |------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |                    |      |      |  4   |  5   |  6   |  +   |      |
   * |------+------+------+------+------+------+------+------,      ,------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |      |      |      |      |      |  1   |  2   |  3   | ent  |      |
   * |-------------+------+------+------+------+------|      |      |      |------+------+------+------+------+-------------|
   * |      |      |      |      |      |      |      |      |      |      |      |      |      |  0   |  .   | ent  |      |
   * `---------------------------'      `--------------------'      `--------------------'      `---------------------------'
   */
  [LAYER_NUM] = LAYOUT(
    _______, _______, _______, _______, _______, _______, _______,                          _______, _______, KC_NUM, KC_PSLS, KC_PAST, KC_PMNS, _______, \
    _______, _______, _______, _______, _______, _______, _______,                          _______, _______, KC_P7,    KC_P8,   KC_P9, KC_PPLS, _______, \
    _______, _______, _______, _______, _______, _______, _______,                          _______, _______, KC_P4,    KC_P5,   KC_P6, KC_PPLS, _______, \
    _______, _______, _______, _______, _______, _______, _______,                          _______, _______, KC_P1,    KC_P2,   KC_P3, KC_PENT, _______, \
    _______, _______, _______, LAY0,             _______, _______,_______,          _______,_______, _______,           KC_P0, KC_PDOT, KC_PENT, _______  \
  ),


  /* Gaming layer TODO comment with keys
   * Same as querty but with the following differences
   *  - no windows key
   *  - arrow keys at the very right-bottom
   *  - all other layers are deactivated but Enter (motion layer) so I can still use F1~F12
   * ,------------------------------------------------.                    ,------------------------------------------------.
   * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F11 |                    |  F12 |  F6  |  F7  |  F8  |  F9  |  F10 |      |
   * |------+------+------+------+------+------+------|                    |------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |                    |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+------|                    |------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |                    |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+------+------,      ,------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |  UP  |      |
   * |-------------+------+------+------+------+------|      |      |      |------+------+------+------+------+-------------|
   * |      |      |      |  L0  |      |      |      |      |      |      |      |      |      |      |  LFT |  DWN | RGHT |
   * `---------------------------'      `--------------------'      `--------------------'      `---------------------------'
   */
  [LAYER_GAME] = LAYOUT(
    KC_ESC , KC_1,  KC_2,  KC_3, KC_4,  KC_5,    JP_MINS,                         JP_CIRC, KC_6,  KC_7,  KC_8,    KC_9,    KC_0,    KC_BSPC, \
    KC_TAB , KC_Q,  KC_W,  KC_E, KC_R,  KC_T,    JP_LBRC,                         JP_RBRC, KC_Y,  KC_U,  KC_I,    KC_O,    KC_P,    JP_AT,   \
    KC_LCTL, KC_A,  KC_S,  KC_D, KC_F,  KC_G,    KC_DEL,                          KC_BSPC, KC_H,  KC_J,  KC_K,    KC_L,    JP_SCLN, JP_COLN, \
    KC_LSFT, KC_Z,  KC_X,  KC_C, KC_V,  KC_B,    KC_LALT,                         KC_ALGR, KC_N,  KC_M,  JP_COMM, JP_DOT,  KC_UP,   JP_SLSH, \
    KC_NO, KC_LALT, LAY0, KC_NO,       KC_LSFT, KC_LCTL, KC_SPC,         KC_ENT, KC_RCTL, KC_NO,        KC_NO,   KC_LEFT, KC_DOWN, KC_RIGHT \
  ),
};


/*
// What does that do? Do I need it?
#ifdef AUDIO_ENABLE
float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
#endif

// What does that do? Do I need it?
void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}
*/
