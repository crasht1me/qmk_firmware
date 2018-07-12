/* Copyright 2015-2017 Jack Humbert
 * Copyright 2018      Roman Volosatovs
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
/*#include <print.h>*/

enum preonic_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST,
  _EXTRA
};

enum preonic_keycodes {
  QWERTY = SAFE_RANGE
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define EXTRA MO(_EXTRA)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT_preonic_grid( \
      KC_GRV,         KC_1,    KC_2,    KC_3,    KC_4,    KC_5,     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,         \
      KC_TAB,         KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,         \
      KC_ESC,         KC_A,    KC_S,    KC_D,    KC_F,    KC_G,     KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, RCTL_T(KC_QUOT), \
      KC_LSFT,        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,     KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,          \
      _______,        KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_SPC,   KC_SPC,  RAISE,   KC_RSFT, KC_RCTL, KC_RALT, _______          \
      ),

  [_LOWER] = LAYOUT_preonic_grid( \
      KC_GRV,         KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,  KC_CIRC, KC_AMPR, KC_ASTR, KC_UNDS, _______, _______,         \
      KC_GRV,         KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,  KC_CIRC, KC_AMPR, KC_ASTR, KC_UNDS, _______, _______,         \
      _______,        _______, KC_BSPC, KC_ENT,  KC_SPC,  KC_ESC,   KC_LT,   KC_LBRC, KC_RBRC, KC_GT,   _______, RCTL_T(KC_GRV),  \
      _______,        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,    _______, KC_PIPE, KC_BSLS, _______, _______, _______,         \
      _______,        _______, _______, _______, _______, KC_ESC,   KC_ESC,  _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY          \
      ),

  [_RAISE] = LAYOUT_preonic_grid( \
      KC_TILD,        KC_1,    KC_2,    KC_3,    KC_4,    KC_5,     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,         \
      KC_TILD,        KC_1,    KC_2,    KC_3,    KC_4,    KC_5,     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,         \
      _______,        _______, KC_BSPC, KC_ENT,  KC_SPC,  KC_ESC,   KC_PLUS, KC_LPRN, KC_RPRN, KC_EQL,  KC_COLN, RCTL_T(KC_GRV),  \
      _______,        KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_MINS, KC_LCBR, KC_RCBR, _______, _______, _______,         \
      _______,        _______, _______, _______, _______, KC_ESC,   KC_ESC,  _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY          \
      ),

  [_ADJUST] = LAYOUT_preonic_grid( \
      KC_F1,          KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,    KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,          \
      KC_F1,          KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,    KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,          \
      _______,        _______, _______, _______, _______, _______,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,         \
      _______,        _______, _______, _______, _______, _______,  _______, KC_PGDN, KC_PGUP, KC_PSCR, _______, _______,         \
      EXTRA,          _______, _______, _______, _______, KC_ESC,   KC_ESC,  _______, _______, _______, _______, EXTRA            \
      ),

  [_EXTRA] = LAYOUT_preonic_grid( \
      _______,        RESET,   DEBUG,   RGB_TOG, RGB_MOD, RGB_HUI,  RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, KC_DEL,          \
      _______,        RESET,   DEBUG,   RGB_TOG, RGB_MOD, RGB_HUI,  RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, KC_DEL,          \
      _______,        MU_MOD,  AU_ON,   AU_OFF,  TERM_ON, TERM_OFF, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,         \
      _______,        MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,    MI_OFF,  KC_PGDN, KC_PGUP, KC_PSCR, _______, _______,         \
      _______,        _______, _______, _______, _______, KC_ESC,   KC_ESC,  _______, _______, _______, _______, _______          \
      )
};

uint32_t layer_state_set_user(uint32_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  /*xprintf("process_record_user %d, %p\n", keycode, record);*/
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
  }
  return true;
};

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case RAISE:
    case LOWER:
      return false;
    default:
      return true;
  }
}
