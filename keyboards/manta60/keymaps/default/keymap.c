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
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 3

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
  RGBRST
};

#define KC______ KC_TRNS
#define KC_XXXXX KC_NO
#define KC_KANJI KC_GRV

#define KC_LOWER LOWER
#define KC_RAISE RAISE

#define KC_RST   RESET

#define KC_LRST  RGBRST
#define KC_LTOG  RGB_TOG
#define KC_LHUI  RGB_HUI
#define KC_LHUD  RGB_HUD
#define KC_LSAI  RGB_SAI
#define KC_LSAD  RGB_SAD
#define KC_LVAI  RGB_VAI
#define KC_LVAD  RGB_VAD

#define KC_KNRM  AG_NORM
#define KC_KSWP  AG_SWAP
#define KC_GUAP  LALT_T(KC_APP)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_kc( \
  //,------------------------------------------------.                            ,------------------------------------------------.
        ESC,     1,     2,     3,     4,     5,   EQL,                               MINS,     6,     7,     8,     9,     0,  BSLS,\
  //|------+------+------+------+------+------+------|                            |------+------+------+------+------+------+------|
        GRV,     Q,     W,     E,     R,     T,  LBRC,                               RBRC,     Y,     U,     I,     O,     P,    AT,\
  //|------+------+------+------+------+------+------|                            |------+------+------+------+------+------+------|
        TAB,     A,     S,     D,     F,     G,  COMM,                                DOT,     H,     J,     K,     L,    UP,  SCOLON,\
  //|------+------+------+------+------+------+------|                            |------+------+------+------+------+------+------|
       LSFT,     Z,     X,     C,     V,  SLSH,                                                B,     N,     M,  LEFT,  DOWN,  RGHT,\
  //|------+------+------+------+------+------+-----------------|     |------ ------------------+------+------+------+------+------|
      LOWER, XXXXX,                LALT, LCTRL,  ENT,  BSPC,   LGUI,      ENT,  DEL,  SPC, HENK,  MHEN,               XXXXX, RAISE \
  //`------+--------/            \-----+------+------+------+------'  `----+------+------+------+-----/              \------+------'
  ),

  [_LOWER] = LAYOUT_kc( \
  //,------------------------------------------------.                            ,------------------------------------------------.
      _____,    F1,    F2,    F3,    F4,    F5, XXXXX,                              XXXXX, XXXXX,  MINS,   EQL,  JYEN,  LBRC,  RBRC,\
  //|------+------+------+------+------+------+------|                            |------+------+------+------+------+------+------|
      _____,    F6,    F7,    F8,    F9,   F10, XXXXX,                              XXXXX, XXXXX, XXXXX, XXXXX,  SCLN,  QUOT,  BSLS,\
  //|------+------+------+------+------+------+------|                            |------+------+------+------+------+------+------|
      _____,   F11,   F12, XXXXX, KANJI,   ENT, XXXXX,                              XXXXX, XXXXX, XXXXX,  COMM,   DOT,  SLSH,    RO,\
  //|------+------+------+------+------+------+------|                            |------+------+------+------+------+------+------|
      _____, LTOG, XXXXX, XXXXX, XXXXX, XXXXX,                                            XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,\
  //|------+------+------+------+------+------+------|                            |------+------+------+------+------+------+------|
      LOWER, XXXXX,              _____, _____, _____, _____, _____,   _____, _____, _____, _____, _____,               XXXXX, RAISE \
  //`------+--------/            \-----+------+------+------+------'  `----+------+------+------+-----/              \------+------'
 ),

  [_RAISE] = LAYOUT_kc( \
  //,------------------------------------------------.                            ,------------------------------------------------.
      _____, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,                              XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,\
  //|------+------+------+------+------+------+------|                            |------+------+------+------+------+------+------|
      _____, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,                              XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,\
  //|------+------+------+------+------+------+------|                            |------+------+------+------+------+------+------|
      _____, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,                              XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,\
  //|------+------+------+------+------+------+------|                            |------+------+------+------+------+------+------|
      _____, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,                                            XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,\
  //|------+------+------+------+------+------+------|                            |------+------+------+------+------+------+------|
      LOWER, XXXXX,               _____, _____, _____, _____, _____,  _____, _____, _____, _____, _____,               XXXXX, RAISE \
  //`------+--------/            \-----+------+------+------+------'  `----+------+------+------+-----/              \------+------'
  ),

  [_ADJUST] = LAYOUT_kc( \
  //,------------------------------------------------.                            ,------------------------------------------------.
      _____,   RST,  LRST,  KNRM,  KSWP, XXXXX, XXXXX,                              XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,\
  //|------+------+------+------+------+------+------|                            |------+------+------+------+------+------+------|
      _____,  LTOG,  LHUI,  LSAI,  LVAI, XXXXX, XXXXX,                              XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,\
  //|------+------+------+------+------+------+------|                            |------+------+------+------+------+------+------|
      _____, XXXXX,  LHUD,  LSAD,  LVAD, XXXXX, XXXXX,                              XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,\
  //|------+------+------+------+------+------+------|                            |------+------+------+------+------+------+------|
      _____, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,                                            XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,\
  //|------+------+------+------+------+------+------|                            |------+------+------+------+------+------+------|
      LOWER, XXXXX,               _____, _____, _____, _____, _____,  _____, _____, _____, _____, _____,               XXXXX, RAISE \
  //`------+--------/            \-----+------+------+------+------'  `----+------+------+------+-----/              \------+------'
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
void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

void led_set_user(uint8_t usb_led) {

}
