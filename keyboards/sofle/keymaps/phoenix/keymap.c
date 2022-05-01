#include QMK_KEYBOARD_H

enum sofle_layers {
    /* _M_XYZ = Mac Os, _W_XYZ = Win/Linux */
    _COLEMAK,
    _NAV,
    _MEDIA,
    _NUM,
    _SYM,
    _GAME
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * COLEMAK
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ESC  |   Q  |   W  |   F  |   P  |   G  |                    |   J  |   L  |   U  |   Y  |   ;  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | TAB  |   A  |   R  |   S  |   T  |   D  |-------.    ,-------|   H  |   N  |   E  |   I  |   O  |  '   |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   K  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

[_COLEMAK] = LAYOUT(
  KC_GESC,         KC_1,         KC_2,         KC_3,         KC_4,     KC_5,                      KC_6,           KC_7,         KC_8,         KC_9,         KC_0,  TG(_GAME),
  KC_TAB,          KC_Q,         KC_W,         KC_F,         KC_P,     KC_B,                      KC_J,           KC_L,         KC_U,         KC_Y,         KC_SCLN,  KC_BSPC,
  KC_CAPS,  LGUI_T(KC_A), LALT_T(KC_R), LCTL_T(KC_S), LSFT_T(KC_T),    KC_G,                      KC_M,    RSFT_T(KC_N), RCTL_T(KC_E), RALT_T(KC_I), RGUI_T(KC_O),    KC_QUOT,
  KC_LSPO,         KC_Z,         KC_X,         KC_C,         KC_D,     KC_V, KC_MPLY,     KC_F13, KC_K,           KC_H,         KC_COMM,      KC_DOT,       KC_SLSH,  KC_HYPR,
                   KC_LGUI, KC_LALT, LT(_MEDIA, KC_ESC), LT(_NAV, KC_SPC), KC_TAB,        LT(_SYM, KC_ENT),LT(_NUM, KC_BSPC), KC_DEL, KC_RALT, KC_RGUI
),
/* NAV
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   !  |   @  |   #  |   $  |   %  |-------.    ,-------|   ^  |   &  |   *  |   (  |   )  |   |  |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * | Shift|  =   |  -   |  +   |   {  |   }  |-------|    |-------|   [  |   ]  |   ;  |   :  |   \  | Shift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_NAV] = LAYOUT(
  _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                                         KC_F6,    KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,
  _______,   LGUI(KC_LEFT), LGUI(KC_UP), LGUI(KC_DOWN), LGUI(KC_RGHT),_______,      LCTL(KC_LEFT), LCTL(KC_DOWN), LCTL(KC_UP), LCTL(KC_RGHT), KC_NO, KC_F12,
  _______, KC_LGUI,   KC_LALT, KC_LCTL, KC_LSFT, _______,                                       KC_LEFT,  KC_DOWN, KC_UP, KC_RGHT, KC_CAPS, KC_NO,
  _______,  _______,  _______, _______, _______, _______, _______,                     _______, KC_HOME,  KC_PGDN, KC_PGUP, KC_END, KC_INS, _______,
                      _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______
),
/* MEDIA
 * ,----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Esc  | Ins  | Pscr | Menu |      |      |                    |      | PWrd |  Up  | NWrd | DLine| Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  | LAt  | LCtl |LShift|      | Caps |-------.    ,-------|      | Left | Down | Rigth|  Del | Bspc |
 * |------+------+------+------+------+------|  MUTE  |    |       |------+------+------+------+------+------|
 * |Shift | Undo |  Cut | Copy | Paste|      |-------|    |-------|      | LStr |      | LEnd |      | Shift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_MEDIA] = LAYOUT(
  KC_NO,  KC_NO,   KC_NO,     KC_NO,    KC_NO,    KC_NO,                         KC_NO,   KC_NO,    KC_NO,    KC_NO,    KC_NO,  RESET,
  KC_NO,  KC_NO,   KC_NO,     KC_NO,    KC_NO,    KC_NO,                         KC_NO,   KC_NO,    KC_NO,    KC_NO,    KC_NO,  KC_NO,
  KC_NO,  KC_LGUI, KC_LALT,   KC_LCTL,  KC_LSFT,  KC_NO,                         KC_MPRV, KC_VOLD,  KC_VOLU,  KC_MNXT,  KC_NO,  KC_NO,
  KC_NO,  KC_NO,   KC_NO,     KC_NO,    KC_NO,    KC_NO,   _______,     _______, KC_NO,   KC_NO,    KC_NO,    KC_NO,    KC_NO,  _______,
                       _______, _______, _______, _______, _______,     KC_MSTP, KC_MPLY, KC_MUTE, _______, _______
),
/* NUM
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | RESET|      |QWERTY|COLEMAK|      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |MACWIN|      |      |      |-------.    ,-------|      | VOLDO| MUTE | VOLUP|      |      |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      | PREV | PLAY | NEXT |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
  [_NUM] = LAYOUT(
  _______, _______,  _______,  _______, _______, _______,                       _______, _______,  _______,  _______, _______, _______,
  _______, KC_LBRC,  KC_7,     KC_8,    KC_9,    KC_RBRC,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX,
  XXXXXXX, KC_PAST,  KC_4,     KC_5,    KC_6,    KC_PPLS,                       XXXXXXX, KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI,   XXXXXXX,
  XXXXXXX, KC_PSLS,  KC_1,     KC_2,    KC_3,    KC_BSLS, _______,     _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   _______,
                     _______, _______,  KC_DOT,  KC_0,    KC_MINS,     _______, _______, _______, _______, _______
  ),
/* SYM
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | RESET|      |QWERTY|COLEMAK|      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |MACWIN|      |      |      |-------.    ,-------|      | VOLDO| MUTE | VOLUP|      |      |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      | PREV | PLAY | NEXT |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
  [_SYM] = LAYOUT(
  _______, _______,  _______,    _______,   _______,   _______,                          _______, _______,  _______,  _______, _______, _______,
  _______, KC_LCBR,  KC_AMPR,    KC_ASTR,   KC_LPRN,   KC_RCBR,                          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX,
  XXXXXXX, KC_COLN,  KC_DLR,     KC_PERC,   KC_CIRC,   KC_EQL,                           XXXXXXX, KC_RSFT, KC_RCTL, KC_RALT,  KC_RGUI,  XXXXXXX,
  XXXXXXX, KC_TILD,  KC_EXLM,    KC_AT,     KC_HASH,   KC_BSLS, _______,        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,  _______,
                     _______, _______,      KC_LPRN,  KC_RPRN,  KC_UNDS,        _______, _______, _______, _______, _______
  ),
/*
 * GAME
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ESC  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

[_GAME] = LAYOUT(
  KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                          KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  _______,
  KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                          KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  KC_BSPC,
  KC_CAPS,  KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                          KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN,  KC_QUOT,
  KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,   _______,      _______, KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_HYPR,
                    KC_LGUI, KC_LALT, KC_LALT,  KC_SPC, KC_LCTL,      KC_ENT,  KC_BSPC, KC_RCTRL, KC_RALT, KC_RGUI
  )
};

#ifdef ENCODER_ENABLE

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    } else if (index == 1) {
        if (clockwise) {
            tap_code(KC_PGDOWN);
        } else {
            tap_code(KC_PGUP);
        }
    }
    return true;
}

#endif
