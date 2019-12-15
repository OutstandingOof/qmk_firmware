/* OutstandingOof's firmware built for a German layout, i3 and the dvorak layout*/

#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#define _QWERTY 1
#define _DVORAK 0
#define _LOWER 2
#define _RAISE 3
#define _MOUSE 4
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
                                      RAISE ,KC_SPC ,                         KC_ENT, LOWER,
                                      KC_LGUI,KC_ESC,                         KC_BSPC,KC_LGUI,
                                      KC_LALT,KC_GRV,                        KC_MPLY,KC_RALT
  ), 

  [_DVORAK] = LAYOUT_5x6(
     KC_GESC, KC_1  , KC_2  , KC_3  , KC_4  , KC_5  ,                         KC_6  , KC_7  , KC_8  , KC_9  , KC_0  ,KC_MINS,
     KC_TAB ,KC_SLSH, KC_COMM, KC_DOT, KC_P , KC_Z  ,                         KC_F  , KC_G  , KC_C  , KC_R  , KC_L  ,KC_BSLASH,
     KC_LSFT, KC_A  , KC_O  , KC_E  , KC_U  , KC_I  ,                         KC_D  , KC_H  , KC_T  , KC_N  , KC_S  ,KC_LSFT,
     KC_LCTL,KC_NUBS, KC_Q  , KC_J  , KC_K  , KC_X  ,                         KC_B  , KC_M  , KC_W  , KC_V  , KC_Y  ,KC_RCTL,
                     KC_INS ,KC_CAPS,                                                        KC_RBRC,KC_EQL ,
                                     RAISE  ,KC_SPC ,                        KC_ENT, LOWER,
                                     KC_LGUI,KC_ESC ,                        KC_BSPC,KC_LGUI,
                                     KC_LALT,KC_RALT,                        KC_MPLY,KC_DEL
  ),

  [_LOWER] = LAYOUT_5x6(

     KC_TILD,KC_EXLM, KC_AT ,KC_HASH,KC_DLR ,KC_PERC,                        KC_CIRC,KC_AMPR,KC_ASTR,KC_LPRN,KC_RPRN,KC_DEL,
     _______,_______,_______,_______,_______,KC_LBRC,                        KC_RBRC, KC_P7 , KC_P8 , KC_P9 ,_______,KC_PLUS,
     _______,KC_QUOT,KC_SCLN,KC_PGDN,KC_LBRC,KC_LPRN,                        KC_RPRN, KC_P4 , KC_P5 , KC_P6 ,KC_MINS,KC_PIPE,
     _______,_______,_______,_______,_______,_______,                        _______, KC_P1 , KC_P2 , KC_P3 ,KC_EQL ,KC_UNDS,
                                             _______,KC_PSCR,            _______, KC_P0,
                                             _______,_______,            _______,_______,
                                             _______,_______,            _______,_______,
                                             _______,_______,            _______,_______

  ),

  [_RAISE] = LAYOUT_5x6(
       KC_F12 , KC_F1 , KC_F2 , KC_F3 , KC_F4 , KC_F5 ,                        KC_F6  , KC_F7 , KC_F8 , KC_F9 ,KC_F10 ,KC_F11 ,
       _______,_______,_______,_______,_______,KC_LBRC,                        KC_RBRC,TO(_GAME),KC_NLCK,KC_INS ,KC_SLCK,KC_MUTE,
       _______,KC_LEFT,KC_UP  ,KC_DOWN,KC_RGHT,KC_LPRN,                        DF(_DVORAK),KC_MPRV,KC_MPLY,KC_MNXT,_______,KC_VOLU,
       _______,_______,DF(_QWERTY),_______,_______,_______,                    _______,TO(_MOUSE),_______,_______,_______,KC_VOLD,
                                               _______,_______,            KC_EQL ,_______,
                                               _______,_______,            _______,_______,
                                               _______,_______,            _______,_______,
                                               _______,_______,            _______,_______
  ), 

  [_GAME] = LAYOUT_5x6(
     _______, KC_5  , KC_1  , KC_2  , KC_3  , KC_4  ,                         _______,_______,_______,_______,_______,TG(_GAME),
     _______, KC_TAB, KC_Q  , KC_W  , KC_E  , KC_R  ,                         _______,_______,_______,_______,_______,_______,
     _______, KC_LSFT,KC_A  , KC_S  , KC_D  , KC_F  ,                           KC_H ,KC_MPRV,KC_MPLY,KC_MNXT,_______,_______,
     _______, KC_B  , KC_Z  , KC_X  , KC_C  , KC_V  ,                           KC_B ,_______,_______,_______,_______,_______,
                     _______,_______,                                                         _______,_______,
                                      KC_LALT ,KC_SPC,                        _______,_______,
                                      _______,  KC_G ,                        _______,_______,
                                      _______,_______,                     _______,_______
  ),

  [_MOUSE] = LAYOUT_5x6(
     _______,_______,_______,_______,_______,_______,                         _______,_______,_______,_______,_______,TG(_MOUSE),
     _______,_______,_______,KC_MS_U,_______,_______,                         _______,_______,_______,_______,_______,_______,
     _______,_______,KC_MS_L,KC_MS_D,KC_MS_R,_______,                         _______,KC_BTN1,KC_BTN2,_______,_______,_______,
     _______,_______,_______,_______,_______,_______,                         _______,_______,_______,_______,_______,_______,
                     _______,_______,                                                         _______,_______,
                                      _______,_______,                        _______,_______,
                                      _______,_______,                        _______,_______,
                                      _______,_______,                        _______,_______
  ),
};

void encoder_update_user(uint8_t index, bool clockwise) {
	switch (get_highest_layer(layer_state)) {
		case _MOUSE:
			if (clockwise) {
				tap_code(KC_WH_U);
				break;
			} else {
				tap_code(KC_WH_D);
				break;
			}
		default:
			if (clockwise) {
				tap_code(KC_VOLU);
			} else {
				tap_code(KC_VOLD);
			}
	}
}

#ifdef OLED_DRIVER_ENABLE
void oled_task_user(void) {
  // Host Keyboard Layer Status
  oled_write_P(PSTR("Layer: "), false);
  switch (get_highest_layer(layer_state)) {
    case _QWERTY:
      oled_write_P(PSTR("QWERTY\n"), false);
      break;
    case _RAISE:
      oled_write_P(PSTR("RAISE\n"), false);
      break;
    case _LOWER:
      oled_write_P(PSTR("LOWER\n"), false);
      break;
    case _GAME:
      oled_write_P(PSTR("GAME\n"), false);
      break;
	case _MOUSE:
      oled_write_P(PSTR("MOUSE\n"), false);
      break;
    case _DVORAK:
      oled_write_P(PSTR("DVORAK\n"), false);
      break;

    default:
      // Or use the write_ln shortcut over adding '\n' to the end of your string
      oled_write_ln_P(PSTR("Undefined"), false);
  }

  // Host Keyboard LED Status
  uint8_t led_usb_state = host_keyboard_leds();
  oled_write_P(led_usb_state & (1<<USB_LED_NUM_LOCK) ? PSTR("NUMLCK ") : PSTR("       "), false);
  oled_write_P(led_usb_state & (1<<USB_LED_CAPS_LOCK) ? PSTR("CAPLCK ") : PSTR("       "), false);
  oled_write_P(led_usb_state & (1<<USB_LED_SCROLL_LOCK) ? PSTR("SCRLCK ") : PSTR("       "), false);
}
#endif
