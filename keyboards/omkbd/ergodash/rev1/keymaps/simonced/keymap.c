#include QMK_KEYBOARD_H
#include "keymap_japanese.h"

// definition of the layers
#define _QWERTY 0

// symbols layer
#define _SY 2

// windows/desktop layer
#define _WIN 3

// selection layer
#define _SE 4

// gaming layer (will be a toggle)
#define _GA 5

// motion layer (also contains the toggle to gamig layer)
#define _MO 6 // has to be higher be activable from different layers

// unused adjust layer
#define _ADJUST 8


/*======================================================================*/
/*define key combinaisions*/
/*======================================================================*/

// == LAYERS RELATED ==

// my custom switches to different layers
#define RSTQ TO(_QWERTY) // will force default layer

// motion layer switch
#define SW_ML LT(_MO, KC_F) // temporary (on F key)
#define SW_MLE LT(_MO, KC_ENT) // same on Enter

// symbols layer switch
// #define SW_SL LT(_SY, KC_ENT) // temporary (a bit painful for the whole day...)
#define SW_SLE LT(_SY, KC_E) // temporary (E on left hand)
#define SW_SLI LT(_SY, KC_I) // temporary (I on right hand)

// win layer switch
#define SW_WL LT(_WIN, KC_D)

// text selection switch
#define SW_SE LT(_SE, KC_V)

// gaming later switch
#define TG_GA TO(_GA) // toggle from mothion layer on G key (so it activates with F-G)

// == SHORTCUTS RELATED ==

// IME toggle
#define EISU LALT(KC_GRV)
#define LAYSW G(KC_SPC) // win + space to change keyboard layout in Windows

// ctrl and esc on the same key
#define CTR_ESC MT(MOD_LCTL, KC_ESC)
// shift and capslocks on the same key
#define SFT_CAP MT(MOD_LSFT, KC_CAPS)

// changing virtual desktop (only left and right)
#define DESK_R G(C(KC_RIGHT))
#define DESK_L G(C(KC_LEFT))

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


/*======================================================================*/
/*layouts*/
/*======================================================================*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /*
   * Qwerty
   * ,----------------------------------------------------------------------------------------------------------------------.
   * | `    |   1  |   2  |   3  |   4  |   5  |   -  |                    |   =  |   6  |   7  |   8  |   9  |   0  | HOME |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | Tab  |   Q  |   W  |   E  |   R  |   T  |   [  |                    |   ]  |   Y  |   U  |   I  |   O  |   P  | END  |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | Esc  |   A  |   S  |   D  |   F  |   G  |  Del |                    | Bksp |   H  |   J  |   K  |   L  |   ;  |  '   |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * | CAPS |   Z  |   X  |   C  |   V  |   B  | Alt  |                    | AltG |   N  |   M  |   ,  |   .  |   /  | PGUP |
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * | GUI  |  ALT |      | EISU |||||||| Shift| Ctrl | Space|||||||| Enter| Ctrl | Shift|||||||| QUERT|      |      | PGDN |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_QWERTY] = LAYOUT( \
    KC_GRV , KC_1,    KC_2,  KC_3,   KC_4,  KC_5,    KC_MINS,                         KC_EQL,  KC_6,   KC_7,  KC_8,     KC_9,    KC_0,    KC_HOME, \
    KC_TAB , KC_Q,    KC_W,  SW_SLE, KC_R,  KC_T,    JP_LBRC,                         KC_RBRC, KC_Y,   KC_U,  SW_SLI,   KC_O,    KC_P,    KC_END,  \
    CTR_ESC, KC_A,    KC_S,  SW_WL,  SW_ML, KC_G,    KC_DEL,                          KC_BSPC, KC_H,   KC_J,  KC_K,     KC_L,    KC_SCLN, KC_QUOT, \
    SFT_CAP, KC_Z,    KC_X,  KC_C,   SW_SE, KC_B,    KC_LALT,                         KC_ALGR, KC_N,   KC_M,  KC_COMM,  KC_DOT,  KC_SLSH, KC_PGUP, \
    KC_LGUI, KC_LALT, LAYSW, EISU,          KC_LSFT, KC_LCTL, KC_SPC,         KC_ENT, KC_RCTL, KC_RSFT,       RSTQ,     KC_NO,   KC_NO,   KC_PGDN  \
  ),

  /*
   * Motion layer
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F11 |                    |  F12 |  F6  |  F7  |  F8  |  F9  |  F10 |      |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |                    |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |                    | XXXX | LEFT | DOWN | RIGHT|  UP  |      |      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |                    |      |      |      |      |      |      |      |
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * |      |      |      |      ||||||||      |      |      ||||||||      |      |      ||||||||      |      |      |      |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_MO] = LAYOUT(
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F11,                            KC_F12,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10, _______, \
    _______, _______, _______, _______, _______, _______, _______,                          _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, TG_GA,   _______,                           KC_NO , KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT,_______, _______, \
    _______, _______, _______, _______, _______, _______, _______,                          _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______,          _______, _______,_______,          _______,_______, _______,          _______, _______, _______, _______  \
  ),

  /*
   * Symbols layer
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F11 |                    | F12  |  F6  |  F7  |  F8  |  F9  |  F10 |      |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * |      |   !  |   @  |   #  |   $  |   %  |   ~  |                    |   +  |   ^  |   &  |   *  |   _  |      |      |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * |      |   1  |   2  |   3  |   4  |   5  |   -  |                    |   =  |   {  |   }  |   (  |   )  |   |  |      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      |   6  |   7  |   8  |   9  |   0  |      |                    |      |   [   |  ]  |   <  |   >  |   \  |      |
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * |      |      |      |      ||||||||      |      |      ||||||||      |      |      ||||||||      |      |      |      |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_SY] = LAYOUT(
    _______, KC_F1,   KC_F2,   KC_F3,    KC_F4,   KC_F5,     KC_F11,                               KC_F12,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10, _______, \
    _______, JP_EXLM, JP_AT,   JP_HASH,  JP_DLR,  JP_PERC,   JP_TILD,                             JP_PLUS, JP_CIRC, JP_AMPR, JP_ASTR, JP_UNDS, _______, _______, \
    _______, KC_1,    KC_2,    KC_3,     KC_4,    KC_5,      JP_MINS,                              JP_EQL, JP_LCBR, JP_RCBR, JP_LPRN, JP_RPRN, JP_PIPE, _______, \
    _______, KC_6,    KC_7,    KC_8,     KC_9,    KC_0,      _______ ,                            _______, JP_LBRC, JP_RBRC, JP_LABK, JP_RABK, JP_BSLS, _______, \
    _______, _______, _______, _______,           _______,   _______ ,_______,           _______, _______, _______,          _______,  KC_INS, KC_PSCR, _______  \
  ),


  // Windowns / Desktop shortcuts (SW_WL) switch windows layer
  [_WIN] = LAYOUT(
    _______, _______, _______, _______, _______, _______, _______,                          _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______,                          _______,  WIN_RL,  WIN_RD,  WIN_RU,  WIN_RR, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______,                          _______,  WIN_ML,  WIN_MD,  WIN_MU,  WIN_MR, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______,                          _______, _______,  DESK_L,  DESK_R, _______, _______, _______, \
    _______, _______, _______, _______,          _______, _______,_______,          _______,_______, _______,          _______, _______, _______, _______  \
  ),

  // Selection layer (will help when selecting text)
  [_SE] = LAYOUT(
    _______, _______, _______, _______, _______, _______, _______,                          _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______,                          _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______,                          _______,   SEL_L,   SEL_D,   SEL_U,   SEL_R, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______,                          _______, _______,   SEL_H,   SEL_E, _______, _______, _______, \
    _______, _______, _______, _______,          _______, _______,_______,          _______,_______, _______,          _______, _______, _______, _______  \
  ),

  // Gaming layer
  // Same as querty but with the following differences
  //  - no windows key
  //  - arrow keys at the very right-bottom
  //  - all other layers are deactivated but Enter (motion layer) so I can still use F1~F12
  [_GA] = LAYOUT(
    KC_ESC , KC_1,    KC_2,  KC_3,  KC_4,  KC_5,    KC_MINS,                         KC_EQL,  KC_6,   KC_7,  KC_8,     KC_9,    KC_0,    RSTQ,    \
    KC_TAB , KC_Q,    KC_W,  KC_E,  KC_R,  KC_T,    KC_LBRC,                         KC_RBRC, KC_Y,   KC_U,  KC_I,     KC_O,    KC_P,    KC_NO,   \
    KC_LCTL, KC_A,    KC_S,  KC_D,  KC_F,  KC_G,    KC_DEL,                          KC_BSPC, KC_H,   KC_J,  KC_K,     KC_L,    KC_SCLN, KC_QUOT, \
    KC_LSFT, KC_Z,    KC_X,  KC_C,  KC_V,  KC_B,    KC_LALT,                         KC_ALGR, KC_N,   KC_M,  KC_COMM,  KC_DOT,  KC_UP,   KC_NO,   \
    KC_NO,   KC_LALT, KC_NO, KC_NO,        KC_LSFT, KC_LCTL, KC_SPC,         SW_MLE, KC_RCTL, KC_RSFT,       KC_NO,    KC_LEFT, KC_DOWN, KC_RIGHT \
  ),

  /* Adjust (not used)
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
    _______, QK_BOOT, RGB_TOG, RGB_MOD, RGB_HUD, RGB_HUI,_______,                       _______, RGB_SAD, RGB_SAI, RGB_VAD, RGB_VAI, _______, _______, \
    _______, _______, BL_TOGG, BL_BRTG, BL_UP , BL_DOWN ,_______,                       _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______,_______,                       _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______,          _______,_______,_______,       _______,_______, _______,          _______, _______, _______, _______  \
  )
};

#ifdef AUDIO_ENABLE
float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
#endif

// What does that do? Do I need it?
void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}
