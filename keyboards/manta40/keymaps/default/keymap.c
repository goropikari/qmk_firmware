/* Copyright 2019 kamonanban
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

// Defines the keycodes used by our macros in process_record_user
#define _QWERTY 0
#define _LOWER 3
#define _RAISE 4
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
  RGBRST
};

#define _____ KC_TRNS
#define XXXXX KC_NO
#define KC_KANJI KC_GRV

#define KC_LOWER LOWER
#define KC_RAISE RAISE

#define KC_RST   RESET

// #define KC_LRST  RGBRST
// #define KC_LTOG  RGB_TOG
// #define KC_LHUI  RGB_HUI
// #define KC_LHUD  RGB_HUD
// #define KC_LSAI  RGB_SAI
// #define KC_LSAD  RGB_SAD
// #define KC_LVAI  RGB_VAI
// #define KC_LVAD  RGB_VAD
// #define KC_LSMOD RGB_SMOD

#define KC_KNRM  AG_NORM
#define KC_KSWP  AG_SWAP
#define KC_GUAP  LALT_T(KC_APP)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT( \
  //,-----------------------------------------------------.        ,-----------------------------------------------------.
       KC_ESC,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,            KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_AT, \
  //|--------+--------+--------+--------+--------+--------|       |--------+--------+--------+--------+--------+--------|
       KC_TAB,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,            KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT, \
  //|--------+--------+--------+--------+--------+--------|       |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,            KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_MINS, \
  //|--------+--------+--------+--------+--------+--------|       |--------+--------+--------+--------+--------+--------|
        LOWER,          KC_LGUI, KC_LCTRL, KC_ENT, KC_BSPC,          KC_DEL,  KC_SPC, KC_MHEN,  KC_RALT,           RAISE \
  //`--------/        \--------+--------+--------+--------'       `--------+--------+--------+--------/        \--------'
  ),

  [_LOWER] = LAYOUT( \
  //,-----------------------------------------------------.        ,-----------------------------------------------------.
        _____,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,           XXXXX,  KC_EQL, KC_BSLS,   XXXXX,   XXXXX,  XXXXX, \
  //|--------+--------+--------+--------+--------+--------|       |--------+--------+--------+--------+--------+--------|
      KC_GRV,    KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,           XXXXX, KC_LBRC, KC_RBRC,   XXXXX,   XXXXX,  XXXXX, \
  //|--------+--------+--------+--------+--------+--------|       |--------+--------+--------+--------+--------+--------|
        _____,  KC_F11,  KC_F12,   XXXXX,   XXXXX,   XXXXX,           XXXXX,   XXXXX,   XXXXX,   XXXXX,   XXXXX,  XXXXX, \
  //|--------+--------+--------+--------+--------+--------|       |--------+--------+--------+--------+--------+--------|
        LOWER,            XXXXX,   XXXXX,   XXXXX,   XXXXX,           XXXXX,   XXXXX,   XXXXX,   XXXXX,           RAISE \
  //`--------/        \--------+--------+--------+--------'       `--------+--------+--------+--------/        \--------'
 ),

  [_RAISE] = LAYOUT( \
    //,-----------------------------------------------------.        ,-----------------------------------------------------.
        KC_ESC,     KC_7,    KC_8,    KC_9, KC_PMNS,   XXXXX,           XXXXX,   XXXXX,   XXXXX,   XXXXX,  XXXXX,  XXXXX, \
    //|--------+--------+--------+--------+--------+--------|       |--------+--------+--------+--------+--------+--------|
        KC_GRV,     KC_4,    KC_5,    KC_6, KC_PPLS,   XXXXX,           XXXXX,   XXXXX,   XXXXX,   XXXXX,  XXXXX,  XXXXX, \
    //|--------+--------+--------+--------+--------+--------|       |--------+--------+--------+--------+--------+--------|
        _____,      KC_1,    KC_2,    KC_3,  KC_ENT,   XXXXX,           XXXXX,   XXXXX,   XXXXX,   XXXXX,  XXXXX,  XXXXX, \
    //|--------+--------+--------+--------+--------+--------|       |--------+--------+--------+--------+--------+--------|
        LOWER,               KC_0,   _____,   _____,   _____,           _____,   _____,   _____,   _____,           RAISE \
    //`--------/        \--------+--------+--------+--------'       `--------+--------+--------+--------/        \--------'
  ),

  [_ADJUST] = LAYOUT( \
   //,-----------------------------------------------------.        ,-----------------------------------------------------.
      _____,  KC_RST,  RGB_HUI,  RGB_SAI,  RGB_VAI, RGB_M_P,           XXXXX,   XXXXX,   XXXXX,   XXXXX,   XXXXX,   XXXXX, \
   //|--------+--------+--------+--------+--------+--------|       |--------+--------+--------+--------+--------+--------|
      _____,  RGB_TOG,  RGB_HUD,  RGB_SAD, RGB_VAD, RGB_M_B,           XXXXX,   XXXXX,   XXXXX,   XXXXX,   XXXXX,   XXXXX, \
   //|--------+--------+--------+--------+--------+--------|       |--------+--------+--------+--------+--------+--------|
      _____,     RGBRST,   XXXXX,   XXXXX,   XXXXX, RGB_M_K,           XXXXX,   XXXXX,   XXXXX,   XXXXX,   XXXXX,   XXXXX, \
   //|--------+--------+--------+--------+--------+--------|       |--------+--------+--------+--------+--------+--------|
         LOWER,            XXXXX,   XXXXX,   XXXXX,   XXXXX,           XXXXX,   XXXXX,   XXXXX,   XXXXX,           RAISE \
   //`--------/        \--------+--------+--------+--------'       `--------+--------+--------+--------/        \--------'
  )
};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

static inline void update_tri_layer_RGB(uint8_t layer1, uint8_t layer2, uint8_t layer3) {
  if (IS_LAYER_ON(layer1) && IS_LAYER_ON(layer2)) {
    layer_on(layer3);
  } else {
    layer_off(layer3);
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
  if (record->event.pressed) {
    persistent_default_layer_set(1UL<<_QWERTY);
  }
  return false;
  break;
case LOWER:
  if (record->event.pressed) {
    layer_on(_LOWER);
    update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
  } else {
    layer_off(_LOWER);
    update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
  }
  return false;
  break;
case RAISE:
  if (record->event.pressed) {
    layer_on(_RAISE);
    update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
  } else {
    layer_off(_RAISE);
    update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
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
    case RGBRST:
      #ifdef RGBLIGHT_ENABLE
        if (record->event.pressed){
            eeconfig_update_rgblight_default();
            rgblight_enable();
        }
        #endif
      break;
  }
  return true;
}

#ifdef OLED_DRIVER_ENABLE

void oled_task_user(void) {
  // Host Keyboard Layer Status
  oled_write_P(PSTR("Layer: "), false);
  switch (biton32(layer_state)) {
    case _QWERTY:
      oled_write_P(PSTR("Default\n"), false);
      break;
    case _LOWER:
      oled_write_P(PSTR("LOWER\n"), false);
      break;
    case _RAISE:
      oled_write_P(PSTR("RAISE\n"), false);
      break;
    case _ADJUST:
      oled_write_P(PSTR("ADJ\n"), false);
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

void led_set_user(uint8_t usb_led) {

}
