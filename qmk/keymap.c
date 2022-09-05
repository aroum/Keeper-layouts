#include QMK_KEYBOARD_H

enum custom_keycodes {
    LNG_SW = SAFE_RANGE,
    SCRCUT,
    NUMDOT,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case LNG_SW:
        if (record->event.pressed) {
            // when keycode LNG_SW is pressed
            SEND_STRING(SS_LCTL(SS_TAP(X_LSFT)));
        } else {
            // when keycode LNG_SW is released
        }
        break;

    case SCRCUT:
        if (record->event.pressed) {
            // when keycode SCRCUT is pressed
            SEND_STRING(SS_LGUI(SS_LSFT(SS_TAP(X_S))));
        } else {
            // when keycode SCRCUT is released
        }
        break;
               
    case NUMDOT:
        if (record->event.pressed) {
            // when keycode SCRCUT is pressed
             SEND_STRING(SS_LALT(SS_TAP(X_KP_4) SS_TAP(X_KP_6)));

            // when keycode SCRCUT is released
        }
        break;
        }
    return true;
};


// Main
#define KC_LG_S LGUI_T(KC_S)
#define KC_LC_F LCTL_T(KC_F)
#define KC_LA_D  LALT_T(KC_D)

#define KC_LG_L LGUI_T(KC_L)
#define KC_LC_J LCTL_T(KC_J)
#define KC_LA_K LALT_T(KC_K)

#define KC_LS_SPC LSFT_T(KC_SPC)
#define KC_L1_ENT LT(1, KC_ENT)

#define KC_L3_ESC LT(3, KC_ESC)
#define KC_L2_BSP LT(2, KC_BSPC)

// LNav
#define KC_L4_ENT LT(4, KC_ENT)
// Sym
#define KC_L4_ESC LT(4, KC_ESC)
// Adjust


// Combos
const uint16_t PROGMEM test_combo1[]  = {KC_T, KC_G, COMBO_END};
const uint16_t PROGMEM test_combo2[]  = {KC_Y, KC_H, COMBO_END};
const uint16_t PROGMEM test_combo3[]  = {KC_G, KC_B, COMBO_END};
const uint16_t PROGMEM test_combo4[]  = {KC_H, KC_N, COMBO_END};
const uint16_t PROGMEM test_combo5[]  = {KC_A, KC_Z, COMBO_END};
const uint16_t PROGMEM test_combo6[]  = {KC_SCLN, KC_SLSH, COMBO_END};
const uint16_t PROGMEM test_combo7[]  = {KC_Q, KC_A, COMBO_END};
const uint16_t PROGMEM test_combo8[]  = {KC_P, KC_SCLN, COMBO_END};
const uint16_t PROGMEM test_combo9[]  = {KC_PSLS, KC_0, COMBO_END};
const uint16_t PROGMEM test_combo10[] = {KC_PERC, KC_RPRN, COMBO_END};
const uint16_t PROGMEM test_combo11[] = {KC_RPRN, KC_F7, COMBO_END};
combo_t key_combos[COMBO_COUNT] = {
    COMBO(test_combo1, KC_TAB),
    COMBO(test_combo2, KC_DEL),
    COMBO(test_combo3, KC_BSLS),
    COMBO(test_combo4, KC_MINUS),
    COMBO(test_combo5, KC_GRV),
    COMBO(test_combo6, KC_QUOT),
    COMBO(test_combo7, KC_RBRC),
    COMBO(test_combo8, KC_LBRC),
    COMBO(test_combo9, KC_EQL),
    COMBO(test_combo10, KC_F1),
    COMBO(test_combo11, KC_F2)
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[0] = LAYOUT( // Main
//┌──────────┬──────────┬──────────┬──────────┬──────────┐                                   ┌──────────┬──────────┬──────────┬──────────┬──────────┐ 
     KC_Q    ,   KC_W   ,   KC_E   ,   KC_R   ,   KC_T   ,                                       KC_Y   ,   KC_U   ,   KC_I   ,   KC_O   , KC_P     , 
//├──────────┼──────────┼──────────┼──────────┼──────────┤                                   ├──────────┼──────────┼──────────┼──────────┼──────────┤ 
     KC_A    ,  KC_LG_S ,  KC_LA_D ,  KC_LC_F ,   KC_G   ,                                       KC_H   ,  KC_LC_J ,  KC_LA_K ,  KC_LG_L , KC_SCLN  , 
//├──────────┼──────────┼──────────┼──────────┼──────────┤                                   ├──────────┼──────────┼──────────┼──────────┼──────────┤ 
     KC_Z    ,   KC_X   ,   KC_C   ,   KC_V   ,   KC_B   ,                                       KC_N   ,   KC_M   ,  KC_COMM ,   KC_DOT , KC_SLSH  , 
//└──────────┴──────────┴──────────┴──────────┼──────────┼──────────┐             ┌──────────┼──────────┼──────────┴──────────┴──────────┴──────────┘  
                                               KC_LS_SPC , KC_L1_ENT,              KC_L3_ESC ,KC_L2_BSP   
                                           // └──────────┴──────────┘             └──────────┴──────────┘
),

[1] = LAYOUT( // LSym
//┌──────────┬──────────┬──────────┬──────────┬──────────┐                                   ┌──────────┬──────────┬──────────┬──────────┬──────────┐ 
    KC_PAST  ,   KC_7   ,   KC_8   ,   KC_9   , KC_PPLS  ,                                      KC_EXLM ,   KC_AT  ,  KC_HASH ,  KC_DLR  , KC_PERC  ,
//├──────────┼──────────┼──────────┼──────────┼──────────┤                                   ├──────────┼──────────┼──────────┼──────────┼──────────┤ 
    KC_PSLS  ,   KC_4   ,   KC_5   ,   KC_6   , KC_PMNS  ,                                      KC_CIRC ,  KC_AMPR ,  KC_ASTR , KC_LPRN  , KC_RPRN  ,
//├──────────┼──────────┼──────────┼──────────┼──────────┤                                   ├──────────┼──────────┼──────────┼──────────┼──────────┤ 
     KC_0    ,   KC_1   ,   KC_2   ,   KC_3   ,  NUMDOT  ,                                      LNG_SW  , KC_F4    , KC_F5    ,  KC_F6   , KC_F7    ,
//└──────────┴──────────┴──────────┴──────────┼──────────┼──────────┐             ┌──────────┼──────────┼──────────┴──────────┴──────────┴──────────┘  
                                                KC_LS_SPC,  _______ ,               KC_L4_ESC , KC_BSPC 
                                           // └──────────┴──────────┘             └──────────┴──────────┘
),

[2] = LAYOUT( // Nav
//┌──────────┬──────────┬──────────┬──────────┬──────────┐                                   ┌──────────┬──────────┬──────────┬──────────┬──────────┐ 
      KC_NO  ,  KC_NO   ,  KC_NO   ,  KC_NO   ,  KC_NO   ,                                     KC_WH_U  ,  KC_HOME ,  KC_MPLY ,  KC_PGUP , KC_VOLU  , 
//├──────────┼──────────┼──────────┼──────────┼──────────┤                                   ├──────────┼──────────┼──────────┼──────────┼──────────┤ 
   LCTL(KC_A),LCTL(KC_S),  KC_NO   ,LCTL(KC_F),  KC_NO   ,                                     KC_LEFT  ,  KC_DOWN ,  KC_UP   ,  KC_RGHT , KC_VOLD  ,  
//├──────────┼──────────┼──────────┼──────────┼──────────┤                                   ├──────────┼──────────┼──────────┼──────────┼──────────┤ 
   LCTL(KC_Z),LCTL(KC_X),LCTL(KC_C),LCTL(KC_V),  KC_NO   ,                                     KC_WH_D  ,  KC_END  ,  SCRCUT  ,  KC_PGDN , KC_MUTE  , 
//└──────────┴──────────┴──────────┴──────────┼──────────┼──────────┐             ┌──────────┼──────────┼──────────┴──────────┴──────────┴──────────┘  
                                                KC_LS_SPC,  KC_ENT  ,                KC_ESC  , _______  
                                           // └──────────┴──────────┘             └──────────┴──────────┘
),

[3] = LAYOUT( // RSym
//┌──────────┬──────────┬──────────┬──────────┬──────────┐                                   ┌──────────┬──────────┬──────────┬──────────┬──────────┐ 
    KC_PAST  ,   KC_7   ,   KC_8   ,   KC_9   , KC_PPLS  ,                                      KC_EXLM ,   KC_AT  ,  KC_HASH ,  KC_DLR  , KC_PERC  ,
//├──────────┼──────────┼──────────┼──────────┼──────────┤                                   ├──────────┼──────────┼──────────┼──────────┼──────────┤ 
    KC_PSLS  ,   KC_4   ,   KC_5   ,   KC_6   , KC_PMNS  ,                                      KC_CIRC ,  KC_AMPR ,  KC_ASTR , KC_LPRN  , KC_RPRN  ,
//├──────────┼──────────┼──────────┼──────────┼──────────┤                                   ├──────────┼──────────┼──────────┼──────────┼──────────┤ 
     KC_0    ,   KC_1   ,   KC_2   ,   KC_3   ,  NUMDOT  ,                                      LNG_SW  , KC_F4    , KC_F5    ,  KC_F6   , KC_F7    , 
//└──────────┴──────────┴──────────┴──────────┼──────────┼──────────┐             ┌──────────┼──────────┼──────────┴──────────┴──────────┴──────────┘  
                                                KC_LS_SPC, KC_L4_ENT,                _______ , KC_BSPC 
                                           // └──────────┴──────────┘             └──────────┴──────────┘
),

[4] = LAYOUT( // Adjust
//┌──────────┬──────────┬──────────┬──────────┬──────────┐                                   ┌──────────┬──────────┬──────────┬──────────┬──────────┐ 
    KC_NUM   ,   KC_P7  ,   KC_P8  ,   KC_P9  , KC_INS   ,                                      KC_F8   ,  KC_F9   ,  KC_F10  ,  KC_F11  , KC_F12   , 
//├──────────┼──────────┼──────────┼──────────┼──────────┤                                   ├──────────┼──────────┼──────────┼──────────┼──────────┤ 
    KC_PENT  ,   KC_P4  ,   KC_P5  ,   KC_P6  , KC_PMNS  ,                                      KC_PSCR ,  KC_MENU ,  KC_CAPS ,  KC_NO   ,  KC_NO   , 
//├──────────┼──────────┼──────────┼──────────┼──────────┤                                   ├──────────┼──────────┼──────────┼──────────┼──────────┤ 
    KC_P0    ,   KC_P1  ,   KC_P2  ,   KC_P3  , KC_PAUS  ,                                      KC_SCRL ,  KC_NO   ,  KC_NO   ,  RESET   ,  KC_NO   , 
//└──────────┴──────────┴──────────┴──────────┼──────────┼──────────┐             ┌──────────┼──────────┼──────────┴──────────┴──────────┴──────────┘  
                                                KC_LS_SPC,  _______ ,               _______  , KC_BSPC    
                                           // └──────────┴──────────┘             └──────────┴──────────┘
)
};