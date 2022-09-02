#include QMK_KEYBOARD_H

#ifdef PROTOCOL_LUFA
  #include "lufa.h"
  #include "split_util.h"
#endif
#ifdef SSD1306OLED
  #include "ssd1306.h"
#endif

extern uint8_t is_master;


enum custom_keycodes {
  // Layer Macros
  QWERTY = SAFE_RANGE,
  DVORAK,
  COLEMAK,
  BEAKL,
  // Custom Macros
};

enum layer_number {
  _QWERTY = 0,
  _DVORAK,
  _COLEMAK,
  _BEAKL,
  _NUMPAD,
  _LOWER,
  _RAISE,
  _ADJUST,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  \   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LCTRL |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|PrvWin |    |NxtWin |------+------+------+------+------+------|
 * | LGUI |   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RCTRL |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LALT |Lower |LShift| /Space  /       \BSpace\  |RShift|Raise | RALT |
 *                   |      |      |      |/       /         \      \ |Enter |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

 [_QWERTY] = LAYOUT( \
  KC_GRV,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, \
  KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS, \
  LCTL_T(KC_ESC), KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                     KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
  KC_LGUI,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, C(A(S(KC_TAB))),   C(A(KC_TAB)),  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RCTRL, \
                        KC_LALT, MO(_LOWER), KC_LSFT, KC_SPC, KC_BSPC, KC_SFTENT, MO(_RAISE), KC_RALT \
),
/* DVORAK
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  \   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   '  |   ,  |   .  |   P  |   Y  |                    |   F  |   G  |   C  |   R  |   L  |  /   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LCTRL |   A  |   O  |   E  |   U  |   I  |-------.    ,-------|   D  |   H  |   T  |   N  |   S  |  -   |
 * |------+------+------+------+------+------|PrvWin |    |NxtWin |------+------+------+------+------+------|
 * | LGUI |   ;  |   Q  |   J  |   K  |   X  |-------|    |-------|   B  |   M  |   W  |   V  |   Z  |RCTRL |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LALT |Lower |LShift| /Space  /       \BSpace\  |RShift|Raise | RALT |
 *                   |      |      |      |/       /         \      \ |Enter |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
 [_DVORAK] = LAYOUT( \
  KC_GRV,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSLS, \
  KC_TAB,   KC_QUOT,KC_COMM, KC_DOT,  KC_P,    KC_Y,                     KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_SLSH, \
  LCTL_T(KC_ESC), KC_A,   KC_O,    KC_E,    KC_U,    KC_I,                     KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_MINS, \
  KC_LGUI,  KC_SCLN,KC_Q,    KC_J,    KC_K,    KC_X , C(A(S(KC_TAB))),   C(A(KC_TAB)), KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_RCTRL, \
                        KC_LALT, MO(_LOWER), KC_LSFT, KC_SPC, KC_BSPC, KC_SFTENT, MO(_RAISE), KC_RALT \
),

/* COLEMAK
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   F  |   P  |   G  |                    |   J  |   L  |   U  |   Y  |   ;  |  \   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LCTRL |   A  |   R  |   S  |   T  |   D  |-------.    ,-------|   H  |   N  |   E  |   I  |   O  |  '   |
 * |------+------+------+------+------+------|PrvWin |    |NxtWin |------+------+------+------+------+------|
 * | LGUI |   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   K  |   M  |   ,  |   .  |   /  |RCTRL |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LALT |Lower |LShift| /Space  /       \BSpace\  |RShift|Raise | RALT |
 *                   |      |      |      |/       /         \      \ |Enter |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
 [_COLEMAK] = LAYOUT( \
  KC_GRV,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, \
  KC_TAB,   KC_Q,   KC_W,    KC_F,    KC_P,    KC_G,                     KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSLS, \
  LCTL_T(KC_ESC), KC_A,   KC_R,    KC_S,    KC_T,    KC_D,                     KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT, \
  KC_LGUI,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, C(A(S(KC_TAB))),   C(A(KC_TAB)),    KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RCTRL, \
                        KC_LALT, MO(_LOWER), KC_LSFT, KC_SPC, KC_BSPC, KC_SFTENT, MO(_RAISE), KC_RALT \
),

/* BEAKL
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  `   |   4  |   0  |   1  |   2  |   3  |                    |   7  |   6  |   5  |   9  |   8  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   H  |   O  |   U  |   X  |                    |   G  |   C  |   R  |   F  |   Z  |  \   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LCTRL |   Y  |   I  |   E  |   A  |   .  |-------.    ,-------|   D  |   S  |   T  |   N  |   B  |  ;   |
 * |------+------+------+------+------+------|PrvWin |    |NxtWin |------+------+------+------+------+------|
 * | LGUI |   J  |   /  |   ,  |   K  |   '  |-------|    |-------|   W  |   M  |   L  |   P  |   V  |RCTRL |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LALT |Lower |LShift| /Space  /       \BSpace\  |RShift|Raise | RALT |
 *                   |      |      |      |/       /         \      \ |Enter |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

 [_BEAKL] = LAYOUT( \
  KC_GRV,   KC_4,   KC_0,    KC_1,    KC_2,    KC_3,                     KC_7,    KC_6,    KC_5,    KC_9,    KC_8,    KC_MINS, \
  KC_TAB,   KC_Q,   KC_H,    KC_O,    KC_U,    KC_X,                     KC_G,    KC_C,    KC_R,    KC_F,    KC_Z,    KC_BSLS, \
  LCTL_T(KC_ESC), KC_Y,   KC_I,    KC_E,    KC_A,    KC_DOT,             KC_D,    KC_S,    KC_T,    KC_N,    KC_B,    KC_SCLN, \
  KC_LGUI,  KC_J,   KC_SLSH, KC_COMM, KC_K,  KC_QUOT, C(A(S(KC_TAB))),   C(A(KC_TAB)), KC_W,    KC_M,   KC_L,    KC_P,    KC_V,    KC_RCTRL, \
                        KC_LALT, MO(_LOWER), KC_LSFT, KC_SPC, KC_BSPC, KC_SFTENT, MO(_RAISE), KC_RALT \
),
 
/* NUMPAD
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | NmPad|   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   -  |   /  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    | NmLck|   4  |   5  |   6  |   +  |   *  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------| Tab  |   1  |   2  |   3  | NmEnt| NmEnt|
 * |------+------+------+------+------+------|PrvWin |    |NxtWin |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |   0  |   0  |   .  | NmEnt|      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LALT |Lower |LShift| /Space  /       \BSpace\  |RShift|Raise | RALT |
 *                   |      |      |      |/       /         \      \ |Enter |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

[_NUMPAD] = LAYOUT( \
  TG(_NUMPAD),KC_1, KC_2,    KC_3,    KC_4,    KC_5,                        KC_6,    KC_P7  , KC_P8  , KC_P9  , KC_PMNS, KC_PSLS, \
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     KC_NLCK, KC_P4  , KC_P5  , KC_P6  , KC_PPLS, KC_PAST, \
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     KC_TAB,  KC_P1  , KC_P2  , KC_P3  , KC_PENT, KC_PENT, \
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  _______, _______,  XXXXXXX, KC_P0  , KC_P0  , KC_PDOT, KC_PENT, _______, \
                             _______, _______, _______,  _______, _______,  _______, _______, _______ \
),

 
/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | NmPad| M Ac1| M Ac2| M Ac3|      |      |                    | Top  |      |      |Bottom| Pause| PScr |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      | Vol+ |MWh Lt| M Up |MWh Rt|MWh Up|                    | Home | PgDn | PgUp | End  | Ins  | Del  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      | Vol- | M Lt | M Dw | M Rt |MWh Dw|-------.    ,-------| Left | Down |  Up  |Right |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |BOOTLD| Mute |      |      |      |      |-------|    |-------|Wd Lft| M Bt1| M Bt2|Wd Rgt|      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LALT |Lower |LShift| /Space  /       \Delete\  |RShift|Raise | RALT |
 *                   |      |      |      |/       /         \      \ |Enter |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_LOWER] = LAYOUT( \
  TG(_NUMPAD), KC_ACL0, KC_ACL1, KC_ACL2, XXXXXXX, XXXXXXX,                 LCTL(KC_HOME), XXXXXXX, XXXXXXX,LCTL(KC_END),   KC_PAUSE, KC_PSCR, \
  _______, KC_VOLU, KC_WH_L, KC_MS_U, KC_WH_R, KC_WH_U,                     KC_HOME,       KC_PGDOWN,KC_PGUP, KC_END,        KC_INS, KC_DELETE, \
  _______, KC_VOLD, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D,                     KC_LEFT,       KC_DOWN, KC_UP,  KC_RIGHT,       XXXXXXX, XXXXXXX, \
  QK_BOOT, KC_MUTE, XXXXXXX, _______, _______, XXXXXXX,  XXXXXXX, XXXXXXX,  LCTL(KC_LEFT), KC_BTN1, KC_BTN2,LCTL(KC_RIGHT), XXXXXXX, _______,  \
                             _______, _______, LSFT_T(KC_CAPS),  XXXXXXX, KC_DELETE,  RSFT_T(KC_CAPS), _______, _______ \
),

/* RAISE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | NmPad|  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  |   =  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      | F11  | F12  | F13  | F14  | F15  |                    | F16  | F17  | F18  | F19  | F20  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | CAPS |   !  |   @  |   #  |   $  |   %  |-------.    ,-------|   ^  |   &  |   *  |   (  |   )  |   ~  |
 * |------+------+------+------+------+------|DskLeft|    |DskRght|------+------+------+------+------+------|
 * |      |      |   <  |   {  |   [  |   (  |-------|    |-------|   )  |   ]  |   }  |   >  | APP  |BOOTLD|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LALT |Lower |LShift| /Space  /       \Delete\  |RShift|Raise | RALT |
 *                   |      |      |      |/       /         \      \ |Enter |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_RAISE] = LAYOUT( \
  TG(_NUMPAD),KC_F1,KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_EQUAL, \
  _______, KC_F11,  KC_F12,  KC_F13,  KC_F14,  KC_F15,                    KC_F16,  KC_F17,  KC_F18,  KC_F19,  KC_F20,  _______, \
  KC_CAPS, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                   KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_GRAVE, \
  _______, XXXXXXX, KC_LABK, KC_LCBR, KC_LBRC, KC_LPRN, G(C(KC_LEFT)),  G(C(KC_RIGHT)), KC_RPRN, KC_RBRC, KC_RCBR, KC_RABK, KC_APP, QK_BOOT, \
                             _______, _______, LSFT_T(KC_CAPS),  XXXXXXX, KC_DELETE,  RSFT_T(KC_CAPS), _______, _______ \
),

/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |Qwerty|
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |Dvorak|
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |      |      |      |      |Colemk|
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |Beakl |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LALT |Lower |LShift| /Space  /       \BSpace\  |RShift|Raise | RALT |
 *                   |      |      |      |/       /         \      \ |Enter |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
  [_ADJUST] = LAYOUT( \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QWERTY, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, DVORAK, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, COLEMAK, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, BEAKL,\
                             _______, _______, _______, _______, _______,  _______, _______, _______ \
  )
};

// Enable _ADJUST layer upon triggering _LOWER and _RAISE layers
layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

//SSD1306 OLED update loop, make sure to enable OLED_ENABLE=yes in rules.mk
#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master())
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  return rotation;
}

// When you add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

bool oled_task_user(void) {
  if (is_keyboard_master()) {
    // If you want to change the display of OLED, you need to change here
    oled_write_ln(read_layer_state(), false);
    oled_write_ln(read_keylog(), false);
    oled_write_ln(read_keylogs(), false);
    //oled_write_ln(read_mode_icon(keymap_config.swap_lalt_lgui), false);
    //oled_write_ln(read_host_led_state(), false);
    //oled_write_ln(read_timelog(), false);
  } else {
    oled_write(read_logo(), false);
  }
    return false;
}
#endif // OLED_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
#ifdef OLED_ENABLE
    set_keylog(keycode, record);
#endif
    // set_timelog();
  }
  switch (keycode) {
    // BEGIN: Layer macros
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      break;
    case DVORAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_DVORAK);
      }
      break;
    case COLEMAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_COLEMAK);
      }
      break;
    case BEAKL:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_BEAKL);
      }
      break;
    // END: Layer macros
  }

  return true;
}
