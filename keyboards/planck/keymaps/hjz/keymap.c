/* Copyright 2015-2017 Jack Humbert
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

enum layers { _QWERTY, _NUMBER, _FUNC, _TMUX, _SYSTM };

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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* Qwerty
     * ,-----------------------------------------------------------------------------------.
     * | GESC |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |CTL(T)|   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |Enter |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |LShift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |  '   |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | CTL  | Alt  | INS  | GUI  |_FUNC |    Space    |_NUMBE| Left | Down |  Up  |Right |
     * `-----------------------------------------------------------------------------------'
     */
    [_QWERTY] = LAYOUT_planck_mit(                                                                           // Start
        QK_GESC, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC,                        // Row 1
        LCTL_T(KC_TAB), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_ENT,               // Row 2
        KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_QUOT,                // Row 3
        KC_LCTL, KC_LALT, KC_INS, KC_LGUI, MO(_FUNC), KC_SPC, MO(_NUMBER), KC_LEFT, KC_DOWN, KC_UP, KC_RGHT  // Row 4
        ),

    /* NUMBER
     * ,-----------------------------------------------------------------------------------.
     * |      |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Del  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |   -  |   =  |  [   |   ]  |  T-: |
     * |------+------+------+------+------+------|------+------+------+------+------+------|
     * |      | T-Z  |  T-X | T-C  | T-V  |      | T-N  | T-M  |  T-, |      |      |  \   |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |_TMUX |       _SYSTM|      | HOME | PGDN | PGUP |  END |
     * `-----------------------------------------------------------------------------------'
     */
    [_NUMBER] = LAYOUT_planck_mit(                                                                                     // Start
        KC_TRNS, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_DEL,                                   // Row1
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MINS, KC_EQL, KC_LBRC, KC_RBRC, TMUX_COLON,  // Row 2
        KC_TRNS, TMUX_Z, TMUX_X, TMUX_C, TMUX_V, KC_TRNS, TMUX_N, TMUX_M, TMUX_COMMA, KC_TRNS, KC_TRNS, KC_BSLS,       // Row 3
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, MO(_TMUX), MO(_SYSTM), KC_TRNS, KC_HOME, KC_PGDN, KC_PGUP, KC_END          // Row5
        ),

    /* Function
     * ,-----------------------------------------------------------------------------------.
     * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | CTL  |      |  UP  |      |      |      | LEFT | DOWN |  UP  | RGHT |      |      |
     * |------+------+------+------+------+------|------+------+------+------+------+------|
     * |      | LEFT | DOWN | RGHT |      |      |      |      |      |      |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |             |_TMUX | HOME | PGDN | PGUP |  END |
     * `-----------------------------------------------------------------------------------'
     */
    [_FUNC] = LAYOUT_planck_mit(                                                                                     // Start
        KC_TRNS, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_TRNS,                     // Row 1
        KC_LCTL, KC_TRNS, KC_UP, KC_TRNS, KC_TRNS, KC_TRNS, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_TRNS, KC_TRNS,      // Row 2
        KC_TRNS, KC_LEFT, KC_DOWN, KC_RGHT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  // Row 3
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, MO(_TMUX), KC_HOME, KC_PGDN, KC_PGUP, KC_END           // Row 4
        ),

    /* TMUX
     * ,-----------------------------------------------------------------------------------.
     * |      | T-Q  |      |      |      |      |      |      |      | T-CO |  T-P |      |
     * |------+------+------+------+------+-------------+------+------+------+------+------|
     * |      | T-A  |  T-S | T-D  |      |      |      | T--  |  T-+ | T-[  | T-]  |      |
     * |------+------+------+------+------+------|------+------+------+------+------+------|
     * |      | T-Z  |  T-X | T-C  | T-V  |      | T-N  | T-M  |  T-, |      |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |             |      |      |      |      |      |
     * `-----------------------------------------------------------------------------------'
     */
    [_TMUX] = LAYOUT_planck_mit(                                                                                                      // Start
        KC_TRNS, TMUX_Q, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, TMUX_CTRL_O, TMUX_P, KC_TRNS,                 // Row1
        KC_TRNS, TMUX_A, TMUX_S, TMUX_D, KC_TRNS, KC_TRNS, KC_TRNS, TMUX_MINUS, TMUX_PLUS, TMUX_OPEN_SQ_B, TMUX_CLOSE_SQ_B, KC_TRNS,  // Row2
        KC_TRNS, TMUX_Z, TMUX_X, TMUX_C, TMUX_V, KC_TRNS, TMUX_N, TMUX_M, TMUX_COMMA, KC_TRNS, KC_TRNS, KC_TRNS,                      // Row3
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS                             // Row4
        ),

    /* SYSTEM
     * ,-----------------------------------------------------------------------------------.
     * |      | BTN1 | MS_U | BTN2 | BTN3 |      |      |      |      |      |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      | MS_L | MS_D | MS_R |      |      |      |      |      |      |RGB_FW|RGB_TO|
     * |------+------+------+------+------+------|------+------+------+------+------+------|
     * |      |      |      |      |      |      |      | MUTE |      |      |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
     * `-----------------------------------------------------------------------------------'
     */
    [_SYSTM] = LAYOUT_planck_mit(                                                                                             // Start
        KC_TRNS, KC_BTN1, KC_MS_U, KC_BTN2, KC_BTN3, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,           // Row1
        KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RGB_MODE_FORWARD, RGB_TOG,  // Row2
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MUTE, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,           // Row3
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY                     // Row4
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

static volatile bool ctrl_hold;
static volatile bool gui_hold;

bool process_control_record(uint16_t keycode, keyrecord_t *record) {
    if (!record->event.pressed) {
        return true;
    }

    switch (keycode) {
        case LCTL_T(KC_TAB):
            ctrl_hold = true;
            break;
        case KC_GESC:
            if (ctrl_hold) {
                tap_code(KC_TAB);
                return false;
            }
            break;
    }
    return true;
}

bool process_gui_record(uint16_t keycode, keyrecord_t *record) {
    if (!record->event.pressed) {
        return true;
    }

    int map_key = KC_NO;

    switch (keycode) {
        case KC_LGUI:
            gui_hold = true;
            break;
        case KC_Q:
            map_key = KC_1;
            break;
        case KC_W:
            map_key = KC_2;
            break;
        case KC_E:
            map_key = KC_3;
            break;
        case KC_R:
            map_key = KC_4;
            break;
        case KC_T:
            map_key = KC_5;
            break;
        case KC_Y:
            map_key = KC_6;
            break;
        case KC_U:
            map_key = KC_7;
            break;
        case KC_I:
            map_key = KC_8;
            break;
        case KC_O:
            map_key = KC_9;
            break;
        case KC_P:
            map_key = KC_0;
            break;
    }
    if (gui_hold && (map_key != KC_NO)) {
        tap_code(map_key);
        return false;
    }
    return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if ((keycode >= TMUX_Q) && (keycode <= TMUX_PLUS)) {
        return process_tmux_record(keycode, record);
    } else if ((keycode == LCTL_T(KC_TAB)) || (keycode == KC_GESC)) {
        return process_control_record(keycode, record);
    } else if ((keycode == KC_LGUI) || gui_hold) {
        return process_gui_record(keycode, record);
    }
    return true;
}

void post_process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!record->event.pressed) {
        switch (keycode) {
            case LCTL_T(KC_TAB):
                ctrl_hold = false;
                break;
            case KC_LGUI:
                gui_hold = false;
                break;
        }
    }
}

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { /* First encoder */
        if (clockwise) {
            tap_code(KC_VOLD);
        } else {
            tap_code(KC_VOLU);
        }
    }
    return false;
}
