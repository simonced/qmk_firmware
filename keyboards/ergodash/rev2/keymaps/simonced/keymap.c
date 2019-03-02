#include QMK_KEYBOARD_H
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

// definition of the layers
#define _QWERTY 0
#define _Q 0

// motion layer
#define _LOWER 1
#define _MO 1 // alias

// symbols layer
#define _RAISE 2
#define _SY 2 // alias

#define _ADJUST 16

// unused
/*
enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
};
*/

/*======================================================================*/
/*define key combinaisions*/
/*======================================================================*/

// IME toggle
#define EISU LALT(KC_GRV)

// my custom switches to different layers

// motion layer
#define MY_EL LT(_MO, KC_ENT) // temporary
#define T_MO TG(_MO) // toggle

// symbols layer
#define MY_SL LT(_SY, KC_SPC) // temporary
#define T_SY TG(_SY) // toggle

// ctrl and esc on the same key
#define CTR_ESC MT(MOD_LCTL, KC_ESC)
// shift and capslocks on the same key
#define SFT_CAP MT(MOD_LSFT, KC_CAPS)


/*======================================================================*/
/*layouts*/
/*======================================================================*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Qwerty TODO update that map once I am done with my changes.
   * This is a good layout. I don't plan to change it that much.
   * ,----------------------------------------------------------------------------------------------------------------------.
   * | `    |   1  |   2  |   3  |   4  |   5  |   -  |                    |     |   6  |   7  |   8  |   9  |   0  |Pscree|
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | Tab  |   Q  |   W  |   E  |   R  |   T  |   [  |                    |   ]  |   Y  |   U  |   I  |   O  |   P  |  \   |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | Esc  |   A  |   S  |   D  |   F  |   G  |  Del |                    | Bksp |   H  |   J  |   K  |   L  |   ;  |  :   |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * | XXXXX|   Z  |   X  |   C  |   V  |   B  | Alt  |                    | Alt  |   N  |   M  |   ,  |   .  |   /  | Shift|
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * | GUI  |      |      | EISU |||||||| Shift| Ctrl | Space|||||||| Enter| Ctrl | Shift||||||||      |      | RAISE| PRSCR|
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_QWERTY] = LAYOUT( \
    KC_GRV , KC_1,    KC_2,   KC_3,   KC_4,   KC_5,    KC_MINS,                         KC_EQL,  KC_6,   KC_7,  KC_8,      KC_9,    KC_0,    KC_HOME, \
    KC_TAB , KC_Q,    KC_W,   KC_E,   KC_R,   KC_T,    KC_LBRC,                         KC_RBRC, KC_Y,   KC_U,  KC_I,      KC_O,    KC_P,    KC_PGUP, \
    CTR_ESC, KC_A,    KC_S,   KC_D,   KC_F,   KC_G,    KC_DEL,                          KC_BSPC, KC_H,   KC_J,  KC_K,      KC_L,    KC_SCLN, KC_PGDN, \
    SFT_CAP, KC_Z,    KC_X,   KC_C,   KC_V,   KC_B,    KC_LALT,                         KC_ALGR, KC_N,   KC_M,  KC_COMM,   KC_DOT,  KC_SLSH, KC_END,  \
    KC_LGUI, KC_LALT, T_SY,   EISU,           KC_LSFT, KC_LCTL, MY_SL,           MY_EL, KC_RCTL, KC_RSFT,       KC_NO,     T_MO,    KC_QUOT, KC_NO    \
  ),

  /* Lower
   * Motion layer
   * TODO update the layout and reformat the list bellow
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |  F11 |  F1  |  F2  |  F3  |  F4  |  F5  |   {  |                    |   }  |  F6  |  F7  |  F8  |  F9  |  F10 |  F12 |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * |  ~   |   !  |   @  |   #  |   $  |   %  |   _  |                    |   +  |   ^  |   &  |   *  |   (  |   )  |  |   |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | Tab  |   1  |   2  |   3  |   4  |   5  |  Del |                    | Bksp |   H  |   J  |   K  |   L  |   :  |  "   |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * | Shift|   6  |   7  |   8  |   9  |   0  | Space|                    | Enter|   N  |   M  |   <  |   >  |   ?  | Shift|
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * | Ctrl |  GUI |  ALt | EISU |||||||| Lower| Space|      ||||||||      | Enter| Raise|||||||| Home |PageDn|PageUp|  End |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_LOWER] = LAYOUT(
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F11,                            KC_F12,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10, _______, \
    _______, _______, _______, KC_MS_U, _______, _______, _______,                          _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______,                          _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT,_______, _______, \
    _______, _______, KC_ACL0, KC_ACL1, KC_ACL2, _______, _______,                          _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______,          _______, _______,_______,          _______,_______, _______,          _______,    T_MO, _______, KC_PSCR  \
  ),

  /* Raise TODO complete that layer
   * this layer will be for symbols and keypad
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |  F11 |  F1  |  F2  |  F3  |  F4  |  F5  |   {  |                    |   }  |  F6  |  F7  |  F8  |  F9  |  F10 |  F12 |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * |  ~   |   !  |   @  |   #  |   $  |   %  |   _  |                    |   +  |   ^  |   &  |   *  |   (  |   )  |  |   |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | Tab  |   1  |   2  |   3  |   4  |   5  |  Del |                    | Bksp |   H  |   J  |   K  |   L  |   :  |  "   |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * | Shift|   6  |   7  |   8  |   9  |   0  | Space|                    | Enter|   N  |   M  |   <  |   >  |   ?  | Shift|
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * | Ctrl |  GUI |  ALt | EISU |||||||| Lower| Space|      ||||||||      | Enter| Raise|||||||| Home |PageDn|PageUp|  End |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_RAISE] = LAYOUT(
    _______, KC_F1,   KC_F2, KC_F3,    KC_F4,   KC_F5,     KC_F11,                               KC_F12,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10, _______, \
    _______, KC_EXLM, KC_AT, KC_HASH,  KC_DLR,  KC_PERC,   KC_UNDS,                             KC_PLUS, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______, \
    _______, KC_1,    KC_2,  KC_3,     KC_4,    KC_5,      _______ ,                            _______, _______, _______, _______, _______, KC_PIPE, _______, \
    _______, KC_6,    KC_7,  KC_8,     KC_9,    KC_0,      _______ ,                            _______, _______, _______, _______, _______, KC_NUBS, _______, \
    _______, _______, T_SY,  _______,           _______,   _______ ,_______,           _______, _______, _______,          _______, _______, _______, _______ \
  ),

  /* Adjust
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |      |      |      |      |      |      |      |                    |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      | Reset|RGB ON|  MODE|  HUE-|  HUE+|      |                    |      |  SAT-|  SAT+|  VAL-|  VAL+|      |      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |                    |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |                    |      |      |      |      |      |      |      |
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * |      |      |      |      ||||||||      |      |      ||||||||      |      |      ||||||||      |      |      |      |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_ADJUST] = LAYOUT(
    _______, _______, _______, _______, _______, _______,_______,                       _______, _______, _______, _______, _______, _______, _______, \
    _______, RESET  , RGB_TOG, RGB_MOD, RGB_HUD, RGB_HUI,_______,                       _______, RGB_SAD, RGB_SAI, RGB_VAD, RGB_VAI, _______, _______, \
    _______, _______, BL_TOGG, BL_BRTG, BL_INC , BL_DEC ,_______,                       _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______,_______,                       _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______,          _______,_______,_______,       _______,_______, _______,          _______, _______, _______, _______  \
  )
};

#ifdef AUDIO_ENABLE
float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
#endif

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}


// that function seems to deal with swapping layers
// it simply makes like layers are activated in order
// let's not use that, at least for now.
/*
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
         print("mode just switched to qwerty and this is a huge string\n");
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
  }
  return true;
}
*/

