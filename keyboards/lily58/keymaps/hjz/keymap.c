#include QMK_KEYBOARD_H

enum layer_number { _QWERTY = 0, _FUNC, _SHIFT, _TMUX, _SYSTM };

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

// Tap Dance declarations
enum {
    TD_LD,
    TD_RU,
    TD_PUHM,
    TD_PDED,
    TD_BKDEL,
};

// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Escape, twice for Caps Lock
    [TD_LD]   = ACTION_TAP_DANCE_DOUBLE(KC_LEFT, KC_DOWN),  // Left,  Down
    [TD_RU]   = ACTION_TAP_DANCE_DOUBLE(KC_RGHT, KC_UP),    // Right, UP
    [TD_PUHM] = ACTION_TAP_DANCE_DOUBLE(KC_PGUP, KC_HOME),  // Page Up, HOME
    [TD_PDED] = ACTION_TAP_DANCE_DOUBLE(KC_PGDN, KC_END),   // Page Down  , END
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | GESC |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  TAB |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  Del |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |CTL(T)|   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  | Enter|
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |  '   |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt |  INS | LGUI | /Space  /       \Space \  |_SHIFT| LT/UP| RT/UP|
 *                   `----------------------------'           '------''--------------------'
 */

 [_QWERTY] = LAYOUT( \
  // left hand                                                         // Right hand
  KC_GESC,         KC_1,  KC_2,  KC_3,  KC_4,  KC_5,                   KC_6,  KC_7,  KC_8,    KC_9,    KC_0,    KC_BSPC,
  KC_TAB,          KC_Q,  KC_W,  KC_E,  KC_R,  KC_T,                   KC_Y,  KC_U,  KC_I,    KC_O,    KC_P,    KC_DEL,
  LCTL_T(KC_TAB),  KC_A,  KC_S,  KC_D,  KC_F,  KC_G,                   KC_H,  KC_J,  KC_K,    KC_L,    KC_SCLN, KC_ENT,
  KC_LSFT,         KC_Z,  KC_X,  KC_C,  KC_V,  KC_B, _______,MO(_SYSTM),KC_N,  KC_M,  KC_COMM, KC_DOT,  KC_SLSH, KC_QUOT,
        KC_LALT, KC_INS, KC_LGUI, LT(_FUNC, KC_SPC),      LT(_SHIFT, KC_SPC), _______, TD(TD_LD), TD(TD_RU) \
),
/* FUNCTION
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  F1  |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |  UP  |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | CTL  | LEFT | DOWN | RGHT |      |      |-------.    ,-------| LEFT | DOWN |  UP  | RGHT |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      |      | /       /       \      \  |PU/HM | PD/ED|      |
 *                   `----------------------------'           '------''--------------------'
 */
[_FUNC] = LAYOUT( \
  // left hand                                                            // Right hand
  _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10, _______,
  _______, _______,   KC_UP, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
  KC_LCTL, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,                   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                    _______, _______, _______, _______,             MO(_TMUX), _______, TD(TD_PUHM), TD(TD_PDED)
),
/* SHIFT
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |   !  |   @  |   #  |   $  |   %  |                    |      |   ^  |   &  |   *  |   (  |   )  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |   `  |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |   -  |   =  |   [  |   ]  |  T-: |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |  T-Z |  T-X |  T-C |  T-V |      |-------|    |-------|  T-N |  T-M |  T-, |      |      |   \  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      |      | /       /       \      \  |PU/HM | PD/ED|      |
 *                   `----------------------------'           '------''--------------------'
 */

[_SHIFT] = LAYOUT( \
  _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                     KC_CIRC, KC_AMPR, KC_ASTR,  KC_LPRN, KC_RPRN, _______,
  _______, _______, _______, _______, _______, _______,                     _______, _______, _______,  _______, _______, _______,
  _______, _______, _______, _______, _______, _______,                     _______, KC_MINS,  KC_EQL,  KC_LBRC, KC_RBRC, TMUX_COLON,
  _______, TMUX_Z,  TMUX_X,  TMUX_C,  TMUX_V,  _______, _______, _______,    TMUX_N, TMUX_M,  TMUX_COMMA, _______, _______, KC_BSLS,
                             _______, _______, _______,MO(_TMUX), _______, _______, TD(TD_PUHM), TD(TD_PDED)
),
/* TMUX
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |  T-Q |      |      |      |      |                    |      |      |      | T-CO |  T-P |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |  T-A |  T-S |  T-D |      |      |-------.    ,-------|      |  T-- |  T-+ |  T-[ |  T-] |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |  T-Z |  T-X |  T-C |  T-V |      |-------|    |-------|  T-N |  T-M |  T-, |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      |      | /       /       \      \  |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
  [_TMUX] = LAYOUT( \
  _______, _______, _______, _______, _______, _______,                   _______, _______,    _______,    _______, _______, _______,
  _______, TMUX_Q,  _______, _______, _______, _______,                   _______, _______,    _______,    TMUX_CTRL_O, TMUX_P, _______,
  _______, TMUX_A,  TMUX_S,  TMUX_D,  _______, _______,                   _______,TMUX_MINUS,TMUX_PLUS,  TMUX_OPEN_SQ_B, TMUX_CLOSE_SQ_B, _______,
  _______, TMUX_Z,  TMUX_X,  TMUX_C,  TMUX_V,  _______, _______, _______,  TMUX_N, TMUX_M,     TMUX_COMMA, _______,     _______, _______,
                             _______, _______, _______, _______, _______, _______, _______, _______ \
  ),
/* SYSTEM
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      | BTN1 | BTN2 | BTN3 | BTN4 | BTN5 |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    +------+------+------+------+------+------|
 * |      |      | MS_U |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      | MS_L | MS_D | MS_R |MsRght|      |-------.    ,-------|      | Vol- | Vol+ |      |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      | MUTE |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      |      | /       /       \      \  |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
  [_SYSTM] = LAYOUT( \
  _______, KC_BTN1, KC_BTN2, KC_BTN3, KC_BTN4, KC_BTN5,                       _______, _______, _______, _______, _______, _______,
  _______, _______, KC_MS_U, _______, _______, _______,                       _______, _______, _______, _______, _______, _______,
  _______, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______,                       _______, KC_VOLD, KC_VOLU, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______,     _______, _______, KC_MUTE, _______, _______, _______, _______,
                             _______, _______, _______, _______, _______,  _______, _______, _______ \
  )
};
// clang-format on

// layer_state_t layer_state_set_user(layer_state_t state) { return update_tri_layer_state(state, _FUNC, _SHIFT, _TMUX); }

// SSD1306 OLED update loop, make sure to enable OLED_ENABLE=yes in rules.mk
#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (!is_keyboard_master()) return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
    return rotation;
}

// When you add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void        set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        // If you want to change the display of OLED, you need to change here
        oled_write_ln(read_layer_state(), false);
        // oled_write_ln(read_mode_icon(keymap_config.swap_lalt_lgui), false);
        // oled_write_ln(read_host_led_state(), false);
        // oled_write_ln(read_timelog(), false);
    } else {
    }
    return true;
}
#endif  // OLED_ENABLE

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
        case LT(_FUNC, KC_SPC):
        case LT(_SHIFT, KC_SPC):
            return TAPPING_TERM + 30;
        default:
            return TAPPING_TERM;
    }
}
