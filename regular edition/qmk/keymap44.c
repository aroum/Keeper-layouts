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
        } else {
            // when keycode SCRCUT is released
        }
        break;
        }
    return true;
};


#define KC_LS_SPC LSFT_T(KC_SPC)
#define KC_L1_ENT LT(1, KC_ENT)

#define KC_L2_ESC LT(1, KC_ESC)
#define KC_L3_BSP LT(1, KC_BSPC)

#define KC_L3_TAB LT(3, KC_TAB)
#define KC_L3_DEL LT(3, KC_DEL)

#define KC_L4_ENT LT(4, KC_ENT)
#define KC_L4_ESC LT(4, KC_ESC)

#define KC_OGUI  OSM(MOD_LGUI)
#define KC_OALT  OSM(MOD_LALT)
#define KC_OCTL  OSM(MOD_LCTL)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[0] = LAYOUT( // Main
//┌──────────┬──────────┬──────────┬──────────┬──────────┬──────────┬──────────┐                                   ┌──────────┬──────────┬──────────┬──────────┬──────────┬──────────┬──────────┐
    KC_NO    ,  KC_NO   ,   KC_Q   ,   KC_W   ,   KC_E   ,   KC_R   ,   KC_T   ,                                       KC_Y   ,   KC_U   ,   KC_I   ,   KC_O   ,   KC_P   ,   KC_NO  ,   KC_NO  ,
//└──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤                                   ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┘ 
                KC_NO   ,   KC_A   ,   KC_S   ,   KC_D   ,   KC_F   ,   KC_G   ,                                       KC_H   ,   KC_J   ,   KC_K   ,   KC_L   ,  KC_SCLN ,   KC_NO  ,
           //├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤                                   ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤ 
                KC_NO   ,   KC_Z   ,   KC_X   ,   KC_C   ,   KC_V   ,   KC_B   ,                                       KC_N   ,   KC_M   ,  KC_COMM ,   KC_DOT,   KC_SLSH ,   KC_NO  ,
           //└──────────┴──────────┴──────────┴──────────┼──────────┼──────────┼──────────┐             ┌──────────┼──────────┼──────────┼──────────┴──────────┴──────────┴──────────┘       
                                                            KC_NO  ,KC_LS_SPC , KC_L1_ENT,              KC_L2_ESC ,KC_L3_BSP ,   KC_NO  
                                                    // └──────────┴──────────┴──────────┘             └──────────┴──────────┴──────────┘
),

[1] = LAYOUT( // LNav
//┌──────────┬──────────┬──────────┬──────────┬──────────┬──────────┬──────────┐                                   ┌──────────┬──────────┬──────────┬──────────┬──────────┬──────────┬──────────┐
     KC_NO   ,   KC_NO  ,  KC_VOLU ,  KC_PGUP ,  KC_MPLY , KC_HOME  ,  KC_WH_U ,                                      KC_F1   ,  KC_DEL  ,  KC_TAB  ,  KC_PGUP ,  LNG_SW  ,   KC_NO  ,   KC_NO  ,
//└──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤                                   ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┘
               KC_NO    ,  KC_VOLD ,  KC_LEFT ,   KC_UP  , KC_DOWN  ,  KC_RGHT ,                                      KC_F2   ,  KC_OCTL , KC_OALT  ,  KC_OGUI ,  KC_MENU ,   KC_NO  ,
           //├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤                                   ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤  
               KC_NO    ,  KC_MUTE ,  KC_PGDN ,  SCRCUT  ,  KC_END  ,  KC_WH_D ,                                      KC_F3   ,   KC_F4  ,   KC_F5  ,   KC_F6 ,   KC_F7   ,   KC_NO  ,
           //└──────────┴──────────┴──────────┴──────────┼──────────┼──────────┼──────────┐             ┌──────────┼──────────┼──────────┼──────────┴──────────┴──────────┴──────────┘  
                                                             KC_NO  , KC_LS_SPC, _______  ,              KC_L4_ENT , KC_BSPC  ,   KC_NO  
                                                      // └──────────┴──────────┴──────────┘             └──────────┴──────────┴──────────┘
            ),

[2] = LAYOUT( // RNav
//┌──────────┬──────────┬──────────┬──────────┬──────────┬──────────┬──────────┐                                   ┌──────────┬──────────┬──────────┬──────────┬──────────┬──────────┬──────────┐
     KC_NO   ,   KC_NO  ,  KC_CAPS ,  KC_BSLS ,  KC_TAB  , KC_DEL   ,  KC_F1   ,                                     KC_WH_U  ,  KC_HOME ,  KC_MPLY ,  KC_PGUP ,  KC_VOLU ,   KC_NO  ,   KC_NO  ,
//└──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤                                   ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┘
               KC_NO    ,  KC_MENU ,  KC_OGUI ,  KC_OALT , KC_OCTL  ,  KC_F2   ,                                     KC_LEFT  ,  KC_DOWN ,  KC_UP   ,  KC_RGHT ,  KC_VOLD ,   KC_NO  ,
           //├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤                                   ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤  
               KC_NO    ,  KC_F7   ,   KC_F6  ,   KC_F5  ,   KC_F4  ,  KC_F3   ,                                     KC_WH_D  ,  KC_END  ,  SCRCUT  ,  KC_PGDN ,  KC_MUTE ,   KC_NO  ,
           //└──────────┴──────────┴──────────┴──────────┼──────────┼──────────┼──────────┐             ┌──────────┼──────────┼──────────┼──────────┴──────────┴──────────┴──────────┘  
                                                             KC_NO  , KC_LS_SPC,KC_L4_ENT ,                _______ , KC_BSPC  ,   KC_NO  
                                                      // └──────────┴──────────┴──────────┘             └──────────┴──────────┴──────────┘
),

[3] = LAYOUT( // Sym
//┌──────────┬──────────┬──────────┬──────────┬──────────┬──────────┬──────────┐                                   ┌──────────┬──────────┬──────────┬──────────┬──────────┬──────────┬──────────┐
     KC_NO   ,  KC_NO   ,  KC_PAST ,   KC_7   ,   KC_8   ,   KC_9   , KC_PPLS  ,                                      KC_EXLM ,   KC_AT  ,  KC_HASH ,  KC_DLR  ,  KC_PERC ,   KC_NO  ,   KC_NO  ,
//└──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤                                   ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┘
                KC_NO   ,  KC_PSLS ,   KC_4   ,   KC_5   ,   KC_6   , KC_PMNS  ,                                      KC_CIRC ,  KC_AMPR ,  KC_ASTR , KC_LPRN  ,  KC_RPRN ,   KC_NO  ,
           //├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤                                   ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤ 
                KC_NO   ,   KC_0   ,   KC_1   ,   KC_2   ,   KC_3   , NUMDOT   ,                                      KC_EQL  ,  KC_QUOT ,  KC_GRV  , KC_LBRC  ,  KC_RBRC ,   KC_NO  ,
           //└──────────┴──────────┴──────────┴──────────┼──────────┼──────────┼──────────┐             ┌──────────┼──────────┼──────────┼──────────┴──────────┴──────────┴──────────┘       
                                                             KC_NO  , KC_LS_SPC, _______  ,               _______  , KC_BSPC  ,   KC_NO  
                                                      // └──────────┴──────────┴──────────┘             └──────────┴──────────┴──────────┘
),

[4] = LAYOUT( // Adjust
//┌──────────┬──────────┬──────────┬──────────┬──────────┬──────────┬──────────┐                                   ┌──────────┬──────────┬──────────┬──────────┬──────────┬──────────┬──────────┐
     KC_NO   ,  KC_NO   ,  KC_NUM  ,   KC_P7  ,   KC_P8  ,   KC_P9  , KC_INS   ,                                      KC_F8   ,  KC_F9   ,  KC_F10  ,  KC_F11  ,  KC_F12  ,   KC_NO ,    KC_NO  ,
//└──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤                                   ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┘
                KC_NO   ,  KC_PENT ,   KC_P4  ,   KC_P5  ,   KC_P6  , KC_PMNS  ,                                      KC_PSCR ,  KC_OCTL , KC_OALT  , KC_OGUI ,   RESET   ,   KC_NO  ,
           //├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤                                   ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤  
                KC_NO   ,   KC_P0  ,   KC_P1  ,   KC_P2  ,   KC_P3  , KC_PAUS  ,                                      KC_SCRL ,  KC_NO   ,  KC_NO   ,  KC_NO   ,  KC_NO   ,   KC_NO  ,
           //└──────────┴──────────┴──────────┴──────────┼──────────┼──────────┼──────────┐             ┌──────────┼──────────┼──────────┼──────────┴──────────┴──────────┴──────────┘  
                                                             KC_NO  , KC_LS_SPC, _______  ,               _______  , KC_BSPC  ,   KC_NO  
                                                      // └──────────┴──────────┴──────────┘             └──────────┴──────────┴──────────┘
)
};

#ifdef RGBLIGHT_ENABLE
 const rgblight_segment_t PROGMEM capslock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
        {0, 2, HSV_PURPLE});
    const rgblight_segment_t PROGMEM numlock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
        {6, 1, HSV_ORANGE});
    const rgblight_segment_t PROGMEM ctrl_layer[] = RGBLIGHT_LAYER_SEGMENTS(
        {3, 1, HSV_RED});
    const rgblight_segment_t PROGMEM alt_layer[] = RGBLIGHT_LAYER_SEGMENTS(
        {4, 1, HSV_GREEN});
    const rgblight_segment_t PROGMEM gui_layer[] = RGBLIGHT_LAYER_SEGMENTS(
        {5, 1, HSV_CYAN});

    // Now define the array of layers. Later layers take precedence
    const rgblight_segment_t *const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
        capslock_layer,
        numlock_layer,
        ctrl_layer,
        alt_layer,
        gui_layer);

    void keyboard_post_init_user(void)
    {
        // Enable the LED layers
        rgblight_layers = my_rgb_layers;
    };

    bool led_update_user(led_t led_state)
    {
        rgblight_set_layer_state(0, led_state.caps_lock);
        rgblight_set_layer_state(1, !led_state.num_lock);
        return true;
    }

    void oneshot_mods_changed_user(uint8_t mods)
    {
        if (mods & MOD_MASK_CTRL)
        {
            rgblight_set_layer_state(2, true);
        }
        if (mods & MOD_MASK_ALT)
        {
            rgblight_set_layer_state(3, true);
        }
        if (mods & MOD_MASK_GUI)
        {
            rgblight_set_layer_state(4, true);
        }
        if (!mods)
        {
            rgblight_set_layer_state(2, false);
            rgblight_set_layer_state(3, false);
            rgblight_set_layer_state(4, false);
        }
    }
#endif