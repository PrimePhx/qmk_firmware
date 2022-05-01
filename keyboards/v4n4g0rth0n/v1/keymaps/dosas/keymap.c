#include "V4N4G0RTH0N.h"


enum layers{
  _COLEMAK,
  _NAV,
  _SYM,
  _NUM,
  _GAME
};

#define SftT LSFT_T(KC_T)
#define CtlS LCTL_T(KC_S)
#define AltR LALT_T(KC_R)
#define GuiA LGUI_T(KC_A)
#define SftN RSFT_T(KC_N)
#define CtlE RCTL_T(KC_E)
#define AltI RALT_T(KC_I)
#define GuiO RGUI_T(KC_O)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_COLEMAK] = LAYOUT(
      KC_MPRV, KC_MPLY, KC_MNXT, KC_VOLD, KC_MUTE, KC_VOLU,
      KC_ESC,  KC_Q,  KC_W, KC_F, KC_P, KC_B,      KC_J, KC_L, KC_U,    KC_Y,   KC_SCLN, KC_BSPC,
      KC_TAB,  GuiA,  AltR, CtlS, SftT, KC_G,      KC_M, SftN, CtlE,    AltI,   GuiO, KC_QUOT,
      KC_LSPO, KC_Z,  KC_X, KC_C, KC_D, KC_V,      KC_K, KC_H, KC_COMM, KC_DOT, KC_SLSH, KC_ENT,
      KC_LCTL,KC_LGUI,KC_LALT,LT(_NAV,KC_SPC),     LT(_SYM,KC_BSPC),  LT(_NUM,KC_RALT), KC_DEL, KC_HYPR 
  ),
  [_NAV] = LAYOUT(
    KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6,
     KC_TRNS, KC_TRNS, LGUI(KC_LEFT), LGUI(KC_UP), LGUI(KC_DOWN), LGUI(KC_RGHT),      LCTL(KC_LEFT), LCTL(KC_DOWN), LCTL(KC_UP), LCTL(KC_RGHT), KC_NO, CG_TOGG,
     KC_TRNS, KC_LGUI,   KC_LALT, KC_LCTL, KC_LSFT, KC_TRNS,                          KC_LEFT,  KC_DOWN, KC_UP, KC_RGHT, KC_CAPS, KC_NO,
     KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                          KC_HOME,  KC_PGDN, KC_PGUP, KC_END, KC_INS, KC_TRNS,
     RESET, KC_TRNS, KC_TRNS,                     KC_TRNS,                            KC_DEL,          KC_TRNS, KC_TRNS, KC_TRNS
  ),
  [_SYM] = LAYOUT(
    KC_MPRV, KC_MPLY, KC_MNXT, KC_VOLD, KC_MUTE, KC_VOLU,
    KC_TRNS, KC_LCBR,  KC_AMPR,    KC_ASTR,   KC_LPRN,   KC_RCBR,     KC_NO,          KC_UNDS,      KC_EXLM,        KC_NO, KC_PERC, KC_TRNS,
    KC_TRNS, KC_COLN,  KC_DLR,     KC_PERC,   KC_CIRC,   KC_EQL,     KC_HASH,S(A(C(KC_TAB))), C(A(KC_TAB)),      KC_PIPE, KC_SCLN, KC_TRNS,
    XXXXXXX, KC_TILD,  KC_EXLM,    KC_AT,     KC_HASH,   KC_BSLS,    G(C(KC_D)), G(KC_TAB),C(G(KC_LEFT)),C(G(KC_RGHT)), KC_BSLS, KC_TRNS,
    KC_TRNS,KC_LPRN, KC_RPRN,     KC_MINS,                               KC_TRNS,                    KC_MRWD, KC_MPLY, KC_MFFD
  ),
  [_NUM] = LAYOUT(
    KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6,
    KC_TRNS, KC_LBRC,  KC_7,     KC_8,    KC_9,    KC_MINS,       KC_LBRC, KC_F7, KC_F8, KC_F9, KC_RBRC, KC_TRNS,
    XXXXXXX, KC_PAST,  KC_4,     KC_5,    KC_6,    KC_PPLS,       KC_TRNS, KC_F4, KC_F5, KC_F6, KC_TRNS, KC_TRNS,
    XXXXXXX, KC_PSLS,  KC_1,     KC_2,    KC_3,    KC_DOT,       KC_TRNS, KC_F1, KC_F2, KC_F3,  KC_F11,  KC_F12,
    RESET, KC_TRNS, KC_DOT,      KC_0,                        KC_F10,       KC_F11,  KC_F12, TG(_GAME)
  ),
  [_GAME] = LAYOUT(
    KC_1, KC_2, KC_3, KC_4, KC_5, KC_6,
    KC_ESC,  KC_Q,  KC_W, KC_E, KC_R, KC_T,      KC_Y, KC_U, KC_I,    KC_O,   KC_P, KC_BSPC,
    KC_CAPS,  KC_A,  KC_S, KC_D, KC_F, KC_G,      KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, LT(_NUM,KC_QUOT),
    KC_LSFT, KC_Z,  KC_X, KC_C, KC_V, KC_B,      KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_ENT,
    KC_LCTL, KC_LALT, KC_LCTL,  KC_SPC,      KC_BSPC,         KC_TRNS, KC_TRNS, TG(_GAME)
  )
};

void keyboard_post_init_user(void) {
    setPinOutput(B4);
    writePinHigh(B4);

    setPinOutput(D7);
    setPinOutput(D6);
};

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
        case _NAV:
            writePinHigh(D7);
            break;
        case _SYM:
            writePinHigh(D6);
            break;
        case _NUM:
            writePinHigh(D7);
            writePinHigh(D6);
            break;
        case _GAME:
            writePinLow(B4);
            writePinLow(D7);
            writePinLow(D6);
            break;
        default:
            writePinHigh(B4);
            writePinLow(D7);
            writePinLow(D6);
    }
    return state;
}

