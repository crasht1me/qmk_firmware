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

enum planck_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  BACKLIT
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT_planck_grid( \
  KC_TAB,         KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,         \
  LCTL_T(KC_ESC), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,     KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, RCTL_T(KC_QUOT), \
  LSFT_T(KC_TAB), KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,     KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, RSFT_T(KC_ENT),  \
  _______,        KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_SPC,   KC_SPC,  RAISE,   KC_RSFT, KC_RCTL, KC_RALT, _______          \
),

[_LOWER] = LAYOUT_planck_grid( \
  KC_TILD,        KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,  KC_CIRC, KC_AMPR, KC_ASTR, KC_MINS, KC_PLUS, _______,         \
  KC_SPC,         _______, _______, _______, KC_PLUS, _______,  _______, KC_LBRC, KC_RBRC, KC_PLUS, _______, _______,         \
  _______,        _______, _______, _______, KC_MINS, _______,  KC_UNDS, KC_SPC,  KC_BSPC, _______, _______, _______,         \
  _______,        _______, _______, _______, _______, KC_ESC,   KC_ESC,  _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY          \
),

[_RAISE] = LAYOUT_planck_grid( \
  KC_GRV,         KC_1,    KC_2,    KC_3,    KC_4,    KC_5,     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,         \
  _______,        _______, _______, _______, _______, _______,  KC_PLUS, KC_LPRN, KC_RPRN, KC_EQL,  KC_COLN, _______,         \
  _______,        _______, _______, _______, _______, _______,  KC_MINS, KC_LCBR, KC_RCBR, KC_PIPE, KC_BSLS, _______,         \
  _______,        _______, _______, _______, _______, KC_ESC,   KC_ESC,  _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY          \
),

[_ADJUST] = LAYOUT_planck_grid( \
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
  switch (keycode) {
        case QWERTY:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_QWERTY);
          }
          return false;
          break;
        case BACKLIT:
          if (record->event.pressed) {
            register_code(KC_RSFT);
            #ifdef BACKLIGHT_ENABLE
              backlight_step();
            #endif
            PORTE &= ~(1<<6);
          } else {
            unregister_code(KC_RSFT);
            PORTE |= (1<<6);
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
