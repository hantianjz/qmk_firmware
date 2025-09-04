/**
 * Copyright 2021 Charly Delay <charly@codesink.dev> (@0xcharly)
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

#include <string.h>

enum charybdis_keymap_layers {
    LAYER_BASE = 0,
    LAYER_FUNC,
    LAYER_SHIFT,
    LAYER_TMUX,
    LAYER_SYSTEM,
};

enum custom_keycodes {
    TMUX_Q = SAFE_RANGE,
    TMUX_A,
    TMUX_Z,
    TMUX_W,
    TMUX_S,
    TMUX_X,
    TMUX_D,
    TMUX_C,
    TMUX_V,
    TMUX_N,
    TMUX_M,
    TMUX_COMMA,
    TMUX_OPEN_SQ_B,
    TMUX_CLOSE_SQ_B,
    TMUX_CTRL_O,
    TMUX_P,
    TMUX_COLON,
    TMUX_MINUS,
    TMUX_PLUS,
};

#define PT_LSPC LT(LAYER_FUNC, KC_SPC)
#define PT_RSPC LT(LAYER_SHIFT, KC_SPC)
#define LTMUX MO(LAYER_TMUX)
#define LSYSM MO(LAYER_SYSTEM)

#ifndef POINTING_DEVICE_ENABLE
#    define DRGSCRL KC_NO
#    define DPI_MOD KC_NO
#    define S_D_MOD KC_NO
#    define SNIPING KC_NO
#endif // !POINTING_DEVICE_ENABLE

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [LAYER_BASE] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       QK_GESC,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,       KC_6,    KC_7,    KC_8,    KC_9,    KC_0, DRGSCRL,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
        KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_BTN1,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       KC_LCTL,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,       KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_ENT,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,       KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_QUOT,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                           LGUI_T(KC_SPC), PT_LSPC,  LSYSM,      KC_BSPC,   PT_RSPC,
                                           KC_LCTL, KC_LALT,     KC_BTN2
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),

  [LAYER_FUNC] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,      KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX, XXXXXXX, KC_UP,   XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       KC_LCTL, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, XXXXXXX,    KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                  XXXXXXX, XXXXXXX, XXXXXXX,    LTMUX,   LTMUX,
                                           XXXXXXX, XXXXXXX,    XXXXXXX
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),

  [LAYER_SHIFT] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       XXXXXXX, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,    KC_CIRC, KC_AMPR, KC_ASTR,  KC_LPRN, KC_RPRN, XXXXXXX,

  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, TMUX_COLON,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       KC_LSFT, TMUX_Z,  TMUX_X,  TMUX_C,  TMUX_V,  XXXXXXX,    TMUX_N,  TMUX_M,TMUX_COMMA, XXXXXXX, XXXXXXX, KC_BSLS,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                  LTMUX,   LTMUX,   XXXXXXX,    XXXXXXX, XXXXXXX,
                                           XXXXXXX, XXXXXXX,    XXXXXXX
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),

  [LAYER_TMUX] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       _______, TMUX_Q,  _______, _______, _______, _______,    _______, _______, _______,TMUX_CTRL_O,TMUX_P, _______,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       _______, TMUX_A,  TMUX_S,  TMUX_D,  _______, _______,   _______,TMUX_MINUS,TMUX_PLUS,TMUX_OPEN_SQ_B,TMUX_CLOSE_SQ_B,_______,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
      KC_LSFT,  TMUX_Z,  TMUX_X,  TMUX_C,  TMUX_V,  _______,    TMUX_N,  TMUX_M,  TMUX_COMMA, _______, _______, _______,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                  XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX,
                                           XXXXXXX, XXXXXXX,    XXXXXXX
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),

  [LAYER_SYSTEM] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       QK_BOOT,  EE_CLR, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT, EE_CLR,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, DPI_MOD, S_D_MOD,    S_D_MOD, DPI_MOD, XXXXXXX, XXXXXXX, KC_MPRV, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, DRGSCRL,    KC_MPLY, KC_VOLD, KC_VOLU, XXXXXXX, XXXXXXX, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX, XXXXXXX, XXXXXXX, SNIPING, KC_BTN2, KC_BTN1,    KC_MNXT, KC_MUTE, SNIPING, DRGSCRL, _______, XXXXXXX,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                  XXXXXXX, XXXXXXX, XXXXXXX,    KC_BTN1, DRGSCRL,
                                           XXXXXXX, XXXXXXX,    KC_BTN2
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),
};

void tmux_code(keyrecord_t *record, char *tmux_code) {
    if (record->event.pressed) {
        SEND_STRING(SS_LCTL("a") SS_DELAY(100));
        send_string(tmux_code);
    }
}

bool process_tmux_record(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case TMUX_Q:
            tmux_code(record, "q");
            break;
        case TMUX_A:
            tmux_code(record, "a");
            break;
        case TMUX_Z:
            tmux_code(record, "z");
            break;
        case TMUX_W:
            tmux_code(record, "w");
            break;
        case TMUX_S:
            tmux_code(record, "s");
            break;
        case TMUX_X:
            tmux_code(record, "x");
            break;
        case TMUX_D:
            tmux_code(record, "d");
            break;
        case TMUX_C:
            tmux_code(record, "c");
            break;
        case TMUX_V:
            tmux_code(record, "v");
            break;
        case TMUX_N:
            tmux_code(record, "n");
            break;
        case TMUX_M:
            tmux_code(record, "m");
            break;
        case TMUX_COMMA:
            tmux_code(record, ",");
            break;
        case TMUX_OPEN_SQ_B:
            tmux_code(record, "[");
            break;
        case TMUX_CLOSE_SQ_B:
            tmux_code(record, "]");
            break;
        case TMUX_CTRL_O:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("a") SS_DELAY(100) SS_LCTL("o"));
            }
            break;
        case TMUX_P:
            tmux_code(record, "p");
            break;
        case TMUX_COLON:
            tmux_code(record, ":");
            break;
        case TMUX_MINUS:
            tmux_code(record, "-");
            break;
        case TMUX_PLUS:
            tmux_code(record, "=");
            break;
    }
    return true;
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if ((keycode >= TMUX_Q) && (keycode <= TMUX_PLUS)) {
        return process_tmux_record(keycode, record);
    }
    return true;
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case PT_LSPC:
        case PT_RSPC:
            return TAPPING_TERM + 30;
        default:
            return TAPPING_TERM;
    }
}
