#include QMK_KEYBOARD_H
#include "keymap_japanese.h"

// definition of the layers
enum {
  LAYER_BASE = 0,
  LAYER_GAME,
  LAYER_SYMB,
  LAYER_SEL,
  LAYER_NUM,
  LAYER_SYMB2
};

/*======================================================================*/
/*define key combinaisions*/
/*======================================================================*/

// == LAYERS RELATED ==
// TO fully change layer
// TG toggle a layer "on top"
// MO momentary toggle (as long as key pressed)
// LT momentary toggle (like MO, but usable as specified key press)

#define TO_L0 TO(LAYER_BASE)
// #define TG_SY TG(LAYER_SYMB)
#define MO_NU MO(LAYER_NUM) // [MO]mentary layer Numbers + Music controls
#define TO_GM TO(LAYER_GAME)

// active some layers from home row
#define F_FUN LT(LAYER_SYMB, KC_F) // F aslo as symbol layer temporary switch
#define J_FUN LT(LAYER_SYMB, KC_J) // J aslo as symbol layer temporary switch
#define V_SEL LT(LAYER_SEL, KC_V) // text selection switch

// activate some layers from gaming layer
#define F_KEYS MO(LAYER_SYMB2)

// == SHORTCUTS RELATED ==

// IME toggle
#define EISU LALT(KC_GRV)

// ctrl and esc on the same key
#define CTR_ESC MT(MOD_LCTL, KC_ESC)
// shift and capslocks on the same key
#define SFT_CAP MT(MOD_LSFT, KC_CAPS)

// changing virtual desktop (only left and right)
#define DESK_R LGUI(C(KC_RIGHT))
#define DESK_L LGUI(C(KC_LEFT))

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
*/

// text selection (for _SE layer)
#define SEL_L S(KC_LEFT)
#define SEL_D S(KC_DOWN)
#define SEL_U S(KC_UP)
#define SEL_R S(KC_RIGHT)
#define SEL_H S(KC_HOME)
#define SEL_E S(KC_END)


/*======================================================================*/
// Tap Dance declarations
/*======================================================================*/
enum {
   // reset a toggle layer by double tapping the otherwise innert windows key
  TD_RST_NUM,
  TD_RST_GAME,
};

void dance_rst_number(tap_dance_state_t *state, void *user_data) {
  if (state->count >= 2) {
    layer_off(LAYER_NUM);
    layer_on(LAYER_BASE);
    reset_tap_dance(state);
  }
}
void dance_rst_game(tap_dance_state_t *state, void *user_data) {
  if (state->count >= 2) {
    layer_off(LAYER_GAME);
    layer_on(LAYER_BASE);
    reset_tap_dance(state);
  }
}
// I guess I could add user data to note have 2 functions...
// will check on that later.

// Tap Dance definitions
tap_dance_action_t tap_dance_actions[] = {
  // only activate the function when tapped twice
  [TD_RST_NUM] = ACTION_TAP_DANCE_FN(dance_rst_number),
  [TD_RST_GAME] = ACTION_TAP_DANCE_FN(dance_rst_game),
};

#define RST_N TD(TD_RST_NUM) // assigned but unused, since num layer is only momentary
// #define RST_G TD(TD_RST_GAME)

/*======================================================================*/
/*layouts*/
/*======================================================================*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /*
   * LAYER0: QWERTY (JIS) by default
   * ,------------------------------------------------.                    ,------------------------------------------------.
   * | 英数 |   1  |   2  |   3  |   4  |   5  |   -  |                    |   ^  |   6  |   7  |   8  |   9  |   0  | BSPC |
   * |------+------+------+------+------+------+------|                    |------+------+------+------+------+------+------|
   * | Tab  |   Q  |   W  |   E  |   R  |   T  |   [  |                    |   ]  |   Y  |   U  |   I  |   O  |   P  |  @   |
   * |------+------+------+------+------+------+------|                    |------+------+------+------+------+------+------|
   * | Esc  |   A  |   S  |   D  |   F  |   G  | DEL  |                    | BSPC |   H  |   J  |   K  |   L  |   ;  |  :   |
   * |------+------+------+------+------+------+------|                    |------+------+------+------+------+------+------|
   * | CAPS |   Z  |   X  |   C  |   V  |   B  | Alt  |                    | AltG |   N  |   M  |   ,  |   .  |   /  |  \   |
   * |-------------+------+------+------+------+------+------.      ,------+------+------+------+------+------+-------------|
   * | GUI  |  ALT |  L3  |  L2  |      | Shift| Ctrl | Space|      | Enter| Ctrl | Shift|      |   <  |   v  |   ^  |  >   |
   * `---------------------------'      `--------------------'      `--------------------'      `---------------------------'
   */
  [LAYER_BASE] = LAYOUT( \
    EISU ,   JP_1,   JP_2, JP_3, JP_4,  JP_5,    JP_MINS,                         JP_CIRC, JP_6, JP_7,  JP_8,    JP_9,    JP_0,    KC_BSPC, \
    KC_TAB , KC_Q,   KC_W, KC_E, KC_R,  KC_T,    JP_LBRC,                         JP_RBRC, KC_Y, KC_U,  KC_I,    KC_O,    KC_P,    JP_AT,   \
    CTR_ESC, KC_A,   KC_S, KC_D, F_FUN, KC_G,    KC_DEL,                          KC_BSPC, KC_H, J_FUN, KC_K,    KC_L,    JP_SCLN, JP_COLN, \
    SFT_CAP, KC_Z,   KC_X, KC_C, V_SEL, KC_B,    KC_LALT,                         KC_ALGR, KC_N, KC_M,  JP_COMM, JP_DOT,  JP_SLSH, JP_BSLS, \
    KC_LGUI, KC_LALT, TO_GM, MO_NU,      KC_LSFT,  KC_LCTL, KC_SPC,         KC_ENT, KC_RCTL, KC_RSFT,     KC_LEFT, KC_DOWN,   KC_UP, KC_RIGHT \
  ),

  /*
   * LAYER1: Motion +Symbols layer (overlay, so un-modified keys are from the base layer)
   * ,------------------------------------------------.                    ,------------------------------------------------.
   * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F11 |                    |  F12 |  F6  |  F7  |  F8  |  F9  |  F10 | home |
   * |------+------+------+------+------+------+------|                    |------+------+------+------+------+------+------|
   * |      |  !   |  "   |  #   |  $   |  %   |      |                    |      |  &   |  '   |  (   |  )   |  |   | end  |
   * |------+------+------+------+------+------+------|                    |------+------+------+------+------+------+------|
   * |      |      | DESL | DESR |      |      |      |                    |      | LEFT | DOWN |  UP  | RGHT |  _   |   -  |
   * |------+------+------+------+------+------+------+------.      ,------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |      |      |      |      |  =   |  {   |  }   |  [   |  ]   | pgup |
   * |-------------+------+------+------+------+------|      |      |      |------+------+------+------+------+-------------|
   * |      |      |      |      |      |      |      |      |      |      |      |      |      | pscr |  brk | ins  | pgdn |
   * `---------------------------'      `--------------------'      `--------------------'      `---------------------------'
   */
  [LAYER_SYMB] = LAYOUT( \
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,  KC_F5,    KC_F11,                           KC_F12,  KC_F6,   KC_F7,   KC_F8,   KC_F9,    KC_F10,  KC_HOME, \
    _______, JP_EXLM, JP_DQUO, JP_HASH, JP_DLR, JP_PERC,  KC_NO,                            KC_NO,   JP_AMPR, JP_QUOT, JP_LPRN, JP_RPRN,  JP_PIPE, KC_END,  \
    _______, _______, DESK_L,  DESK_R,  _______, _______, KC_NO,                            KC_NO,   KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, JP_UNDS, JP_MINS, \
    _______, _______, _______, _______, _______, _______, _______,                          _______,  JP_EQL, JP_LCBR, JP_RCBR, JP_LBRC,  JP_RBRC, KC_PGUP, \
    _______, _______, _______, _______,          _______, _______,_______,          _______,_______, _______,          KC_PSCR, KC_BRK,    KC_INS, KC_PGDN  \
  ),

  // Selection layer (will help when selecting text)
  [LAYER_SEL] = LAYOUT( \
    _______, _______, _______, _______, _______, _______, _______,                          _______, _______, _______, _______, _______, _______, SEL_H,   \
    _______, _______, _______, _______, _______, _______, _______,                          _______, _______, _______, _______, _______, _______, SEL_E,   \
    _______, _______, _______, _______, _______, _______, _______,                          _______,   SEL_L,   SEL_D,   SEL_U,   SEL_R, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______,                          _______, _______,   SEL_H,   SEL_E, _______, _______, _______, \
    _______, _______, _______, _______,          _______, _______,_______,          _______,_______, _______,          _______, _______, _______, _______  \
  ),

  /* Gaming layer TODO comment with keys
   * Same as querty but with the following differences
   *  - no windows key
   *  - arrow keys at the very right-bottom
   *  - all other layers are deactivated but Enter (motion layer) so I can still use F1~F12
   * ,------------------------------------------------.                    ,------------------------------------------------.
   * |      |      |      |      |      |      |      |                    |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+------|                    |------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |                    |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+------|                    |------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |                    |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+------+------,      ,------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |  UP  |      |
   * |-------------+------+------+------+------+------|      |      |      |------+------+------+------+------+-------------|
   * |       |      |      |      |     |      |      |      |      |      |      |      |      |  FUN |  LFT |  DWN | RGHT |
   * `---------------------------'      `--------------------'      `--------------------'      `---------------------------'
   */
  [LAYER_GAME] = LAYOUT( \
    KC_ESC , KC_1,  KC_2,  KC_3, KC_4,  KC_5,    JP_MINS,                         JP_CIRC, KC_6,  KC_7,  KC_8,    KC_9,    KC_0,    KC_BSPC, \
    KC_TAB , KC_Q,  KC_W,  KC_E, KC_R,  KC_T,    JP_LBRC,                         JP_RBRC, KC_Y,  KC_U,  KC_I,    KC_O,    KC_P,    JP_AT,   \
    KC_LCTL, KC_A,  KC_S,  KC_D, KC_F,  KC_G,    KC_DEL,                          KC_BSPC, KC_H,  KC_J,  KC_K,    KC_L,    JP_SCLN, JP_COLN, \
    KC_LSFT, KC_Z,  KC_X,  KC_C, KC_V,  KC_B,    KC_LALT,                         KC_ALGR, KC_N,  KC_M,  JP_COMM, JP_DOT,  KC_UP,   JP_SLSH, \
    KC_NO, KC_LALT, KC_NO, _______,     KC_LSFT, KC_LCTL, KC_SPC,         KC_ENT, KC_RCTL, KC_RSFT,      F_KEYS,  KC_LEFT, KC_DOWN, KC_RIGHT \
  ),

  /*
   * LAYER2: Numbers + Media
   * ,------------------------------------------------.                    ,------------------------------------------------.
   * |      |      |      |      |      |      |      |                    |      |      | NmLk |  /   |  *   |  -   |      |
   * |------+------+------+------+------+------+------|                    |------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |                    |      |      |  7   |  8   |  9   |  +   |      |
   * |------+------+------+------+------+------+------|                    |------+------+------+------+------+------+------|
   * |      |      |      |      |      | Vol+ |      |                    |      |      |  4   |  5   |  6   |  +   |      |
   * |------+------+------+------+------+------+------+------,      ,------+------+------+------+------+------+------+------|
   * |      |      | Prev | Play | Next | Vol- |      |      |      |      |      |      |  1   |  2   |  3   | ent  |      |
   * |-------------+------+------+------+------+------|      |      |      |------+------+------+------+------+-------------|
   * |      |      |      |      |      |      |      |      |      |      |      |      |      |  0   |  .   | ent  |      |
   * `---------------------------'      `--------------------'      `--------------------'      `---------------------------'
   */
  [LAYER_NUM] = LAYOUT( \
    _______, _______, _______, _______, _______, _______, _______,                          _______, _______, KC_NUM, KC_PSLS, KC_PAST, KC_PMNS, _______, \
    _______, _______, _______, _______, _______, _______, _______,                          _______, _______, KC_P7,    KC_P8,   KC_P9, KC_PPLS, _______, \
    _______, _______, _______, _______, _______, KC_VOLU, _______,                          _______, _______, KC_P4,    KC_P5,   KC_P6, KC_PPLS, _______, \
    _______, _______, KC_MPRV, KC_MPLY, KC_MNXT, KC_VOLD, _______,                          _______, _______, KC_P1,    KC_P2,   KC_P3, KC_PENT, _______, \
    _______, _______, _______, _______,          _______, _______,_______,          _______,_______, _______,           KC_P0, KC_PDOT, KC_PENT, _______  \
  ),

  /*
   * Symbols layer for gaming
   * ,------------------------------------------------.                    ,------------------------------------------------.
   * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F11 |                    |  F12 |  F6  |  F7  |  F8  |  F9  |  F10 | home |
   * |------+------+------+------+------+------+------|                    |------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |                    |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+------|                    |------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |                    |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+------+------.      ,------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
   * |-------------+------+------+------+------+------|      |      |      |------+------+------+------+------+-------------|
   * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
   * `---------------------------'      `--------------------'      `--------------------'      `---------------------------'
   */
  [LAYER_SYMB2] = LAYOUT( \
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,  KC_F5,    KC_F11,                           KC_F12,  KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______, \
    _______, _______, _______, _______, _______, _______, _______,                          _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______,                          _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______,                          _______, _______, _______, _______, _______, _______, _______, \
    TO_L0,   _______, _______, _______,          _______, _______,_______,          _______,_______, _______,          _______, _______, _______, _______  \
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
