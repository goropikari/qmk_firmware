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
#define _DVORAK 0
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

#define TAPPING_FORCE_HOLD
#define TAPPING_TERM 100

#define KC_KNRM  AG_NORM
#define KC_KSWP  AG_SWAP
#define KC_CTLTB CTL_T(KC_TAB)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_DVORAK] = LAYOUT( \
  //,-----------------------------------------------------.        ,-----------------------------------------------------.
       KC_ESC, KC_QUOT, KC_COMM,  KC_DOT,    KC_P,    KC_Y,            KC_F,    KC_G,    KC_C,    KC_R,    KC_L, KC_SLSH, \
  //|--------+--------+--------+--------+--------+--------|       |--------+--------+--------+--------+--------+--------|
     KC_CTLTB,    KC_A,    KC_O,    KC_E,    KC_U,    KC_I,            KC_D,    KC_H,    KC_T,    KC_N,    KC_S, KC_MINS, \
  //|--------+--------+--------+--------+--------+--------|       |--------+--------+--------+--------+--------+--------|
      KC_LSFT, KC_SCLN,    KC_Q,    KC_J,    KC_K,    KC_X,            KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,  KC_ENT, \
  //|--------+--------+--------+--------+--------+--------|       |--------+--------+--------+--------+--------+--------|
        LOWER,          KC_RGUI,   LOWER, KC_RALT, KC_BSPC,          KC_GRV,   RAISE,  KC_SPC,  KC_GRV,           KC_TAB  \
  //`--------/        \--------+--------+--------+--------'       `--------+--------+--------+--------/        \--------'
  ),

  [_LOWER] = LAYOUT( \
  //,-----------------------------------------------------.        ,-----------------------------------------------------.
        _____,   XXXXX,   XXXXX,   XXXXX,   XXXXX,   XXXXX,           XXXXX,   XXXXX,   KC_UP,   XXXXX, KC_LBRC, KC_RBRC, \
  //|--------+--------+--------+--------+--------+--------|       |--------+--------+--------+--------+--------+--------|
      KC_GRV,    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,         KC_HOME, KC_LEFT, KC_DOWN,KC_RIGHT, KC_BSPC,  KC_DEL, \
  //|--------+--------+--------+--------+--------+--------|       |--------+--------+--------+--------+--------+--------|
        _____,  KC_F11,  KC_F12,   XXXXX,   XXXXX,   XXXXX,          KC_END,   XXXXX,   XXXXX,   XXXXX,   XXXXX,   XXXXX, \
  //|--------+--------+--------+--------+--------+--------|       |--------+--------+--------+--------+--------+--------|
        LOWER,          KC_RGUI,   LOWER, KC_RALT, KC_BSPC,           RAISE,   RAISE,  KC_SPC,  KC_GRV,           KC_TAB  \
  //`--------/        \--------+--------+--------+--------'       `--------+--------+--------+--------/        \--------'
 ),

  [_RAISE] = LAYOUT( \
    //,-----------------------------------------------------.        ,-----------------------------------------------------.
         KC_ESC,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,            KC_6,    KC_7,    KC_8,    KC_9,    KC_0,   XXXXX, \
    //|--------+--------+--------+--------+--------+--------|       |--------+--------+--------+--------+--------+--------|
       KC_CTLTB,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,          KC_F11,  KC_F12,   XXXXX,   XXXXX,  KC_EQL, KC_BSLS, \
    //|--------+--------+--------+--------+--------+--------|       |--------+--------+--------+--------+--------+--------|
        _____,     KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,           XXXXX, KC_PLUS,   XXXXX,   XXXXX,   XXXXX,   XXXXX, \
    //|--------+--------+--------+--------+--------+--------|       |--------+--------+--------+--------+--------+--------|
        LOWER,            KC_RGUI,   LOWER, KC_RALT, KC_BSPC,           RAISE,   RAISE,  KC_SPC,  KC_GRV,           KC_TAB  \
    //`--------/        \--------+--------+--------+--------'       `--------+--------+--------+--------/        \--------'
  ),

  [_ADJUST] = LAYOUT( \
   //,-----------------------------------------------------.        ,-----------------------------------------------------.
      _____,    KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,         KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,   XXXXX, \
   //|--------+--------+--------+--------+--------+--------|       |--------+--------+--------+--------+--------+--------|
      KC_CTLTB,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,           KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10, KC_PIPE, \
   //|--------+--------+--------+--------+--------+--------|       |--------+--------+--------+--------+--------+--------|
         XXXXX,   XXXXX,   XXXXX,   XXXXX,   XXXXX,   XXXXX,           XXXXX,   XXXXX,   XXXXX,   XXXXX,   XXXXX,   XXXXX, \
   //|--------+--------+--------+--------+--------+--------|       |--------+--------+--------+--------+--------+--------|
         LOWER,          KC_RGUI,   LOWER, KC_RALT, KC_BSPC,           RAISE,   RAISE,  KC_SPC,  KC_GRV,           KC_TAB  \
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
                persistent_default_layer_set(1UL<<_DVORAK);
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
        case _DVORAK:
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
