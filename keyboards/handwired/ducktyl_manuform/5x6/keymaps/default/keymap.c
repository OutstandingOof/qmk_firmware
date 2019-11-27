/* A standard layout for the Ducktyl Manuform 5x6 Keyboard */ 

#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#define _QWERTY 0
#define _DVORAK 1
#define _LOWER 2
#define _RAISE 3
#define _GAME 5

#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT_5x6(
     KC_ESC , KC_1  , KC_2  , KC_3  , KC_4  , KC_5  ,                         KC_6  , KC_7  , KC_8  , KC_9  , KC_0  ,KC_BSPC,
     KC_TAB , KC_Q  , KC_W  , KC_E  , KC_R  , KC_T  ,                         KC_Y  , KC_U  , KC_I  , KC_O  , KC_P  ,KC_MINS,
     KC_LSFT, KC_A  , KC_S  , KC_D  , KC_F  , KC_G  ,                         KC_H  , KC_J  , KC_K  , KC_L  ,KC_SCLN,KC_LSFT,
     KC_LCTL, KC_Z  , KC_X  , KC_C  , KC_V  , KC_B  ,                         KC_N  , KC_M  ,KC_COMM,KC_DOT ,KC_SLSH,KC_BSLASH,
                      KC_LBRC,KC_RBRC,                                                       KC_PLUS, KC_EQL,
                                      TG(_GAME),KC_SPC,                       KC_ENT, LOWER,
                                      KC_LGUI,KC_ESC,                        KC_BSPC,KC_LGUI,
                                      KC_BSPC, KC_GRV,                        KC_MPLY,KC_LALT
  ), 

  [_DVORAK] = LAYOUT_5x6(
     KC_ESC , KC_1  , KC_2  , KC_3  , KC_4  , KC_5  ,                         KC_6  , KC_7  , KC_8  , KC_9  , KC_0  ,KC_BSPC,
     KC_TAB , KC_Q  , KC_COMM, KC_DOT, KC_P , KC_Y  ,                         KC_F  , KC_G  , KC_C  , KC_R  , KC_L  ,KC_MINS,
     KC_LSFT, KC_A  , KC_O  , KC_E  , KC_U  , KC_I  ,                         KC_D  , KC_H  , KC_T  , KC_N  , KC_S  ,KC_LSFT,
     KC_LCTL, KC_Z  , KC_Q  , KC_J  , KC_K  , KC_X  ,                         KC_B  , KC_M  , KC_W  , KC_V  , KC_Z  ,KC_BSLASH,
                      KC_LBRC,KC_RBRC,                                                       KC_PLUS, KC_EQL,
                                      TG(_GAME),KC_SPC,                       KC_ENT, LOWER,
                                      KC_LGUI,KC_ESC,                        KC_BSPC,KC_LGUI,
                                      KC_BSPC, KC_GRV,                        KC_MPLY,KC_LALT
  ),

  [_LOWER] = LAYOUT_5x6(

     KC_TILD,KC_EXLM, KC_AT ,KC_HASH,KC_DLR ,KC_PERC,                        KC_CIRC,KC_AMPR,KC_ASTR,KC_LPRN,KC_RPRN,KC_DEL,
     _______,_______,_______,_______,_______,KC_LBRC,                        KC_RBRC, KC_P7 , KC_P8 , KC_P9 ,_______,KC_PLUS,
     _______,KC_HOME,KC_PGUP,KC_PGDN,KC_END ,KC_LPRN,                        KC_RPRN, KC_P4 , KC_P5 , KC_P6 ,KC_MINS,KC_PIPE,
     _______,_______,_______,_______,_______,_______,                        _______, KC_P1 , KC_P2 , KC_P3 ,KC_EQL ,KC_UNDS,
                                             _______,KC_PSCR,            _______, KC_P0,
                                             _______,_______,            _______,_______,
                                             _______,_______,            _______,_______,
                                             _______,_______,            _______,_______

  ),

  [_RAISE] = LAYOUT_5x6(
       KC_F12 , KC_F1 , KC_F2 , KC_F3 , KC_F4 , KC_F5 ,                        KC_F6  , KC_F7 , KC_F8 , KC_F9 ,KC_F10 ,KC_F11 ,
       _______,_______,_______,_______,_______,KC_LBRC,                        KC_RBRC,_______,KC_NLCK,KC_INS ,KC_SLCK,KC_MUTE,
       _______,KC_LEFT,KC_UP  ,KC_DOWN,KC_RGHT,KC_LPRN,                        KC_RPRN,KC_MPRV,KC_MPLY,KC_MNXT,_______,KC_VOLU,
       _______,_______,_______,_______,_______,_______,                        _______,_______,_______,_______,_______,KC_VOLD,
                                               _______,_______,            KC_EQL ,_______,
                                               _______,_______,            _______,_______,
                                               _______,_______,            _______,_______,
                                               _______,_______,            _______,_______
  ), 

  [_GAME] = LAYOUT_5x6(
     _______, KC_5  , KC_1  , KC_2  , KC_3  , KC_4  ,                         _______,_______,_______,_______,_______,_______,
     _______, KC_TAB, KC_Q  , KC_W  , KC_E  , KC_R  ,                         _______,_______,_______,_______,_______,_______,
     _______, KC_LSFT,KC_A  , KC_S  , KC_D  , KC_F  ,                         _______,_______,_______,_______,_______,_______,
     _______, KC_B  , KC_Z  , KC_X  , KC_C  , KC_V  ,                         _______,_______,_______,_______,_______,_______,
                     _______,_______,                                                         _______,_______,
                                      KC_LALT ,KC_SPC,                        _______,_______,
                                      _______,  KC_G ,                        _______,_______,
                                      _______, TG(_GAME),                     _______,_______
  ),
};

void encoder_update_user(uint8_t index, bool clockwise) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
}

