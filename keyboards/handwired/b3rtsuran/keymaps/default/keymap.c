/* Derivate of elmo's firmware >>kb-elmo<mail@elmo.space>
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

// defining layer_names
enum layer {
    BASE,
    NAV,
    MEDIA,
    NUMPAD,
    SYMBOLS,
    FUNCTIONS
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* b3rtsuran
   *  ┌────┬────┬────┬────┬────┐┌────┐┌────┬────┬────┬────┬────┐
   *  │ Q  │ "b3rtsuran.h"W  │ E  │ R  │ T  ││    ││ Y  │ U  │ I  │ O  │ P  │
   *  ├────┼────┼────┼────┼────┤├────┤├────┼────┼────┼────┼────┤
   *  │ A  │ S  │ D  │ F  │ G  ││    ││ H  │L(2J│ K  │ L  │ ;  │
   *  ├────┼────┼────┼────┼────┤├────┤├────┼────┼────┼────┼────┤
   *  │ Z  │ X  │ C  │ V  │ B  ││    ││ N  │ M  │ ,  │ .  │ /  │
   *  └────┴────┴────┴────┴────┘└────┘└────┴────┴────┴────┴────┘
   *  ┌────┬────┬─────┐┌──────┐ ┌────┐ ┌──────┐┌─────┬────┬────┐
   *  │ctrl│MO1 │ GUI ││LT1Spc│ │MCR │ │ Bksp ││Ralt │Mo1 │ctrl│
   *  └────┴────┴─────┘└──────┘ └────┘ └──────┘└─────┴────┴────┘
   */

    // TODO: Encoder - ? KC_MPLY

   [BASE] = LAYOUT(
        KC_Q,        KC_W,        KC_E,        KC_R,        KC_T,               KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,
        LGUI_T(KC_A), LALT_T(KC_S), LCTL_T(KC_D), LSFT_T(KC_F), KC_G,           KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,
        KC_Z,        KC_X,        KC_C,        KC_V,        KC_B,               KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,
        KC_LCTL, LT(MEDIA,KC_ESC), KC_LGUI, KC_NO, LT(NUMPAD,KC_BSPC),   KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,
        //
        KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,                                          KC_Y,        KC_U,        KC_I,        KC_O,        KC_P,
        KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,                                          KC_H,        LSFT_T(KC_J), LCTL_T(KC_K), LALT_T(KC_L), LGUI_T(KC_SCLN),
        KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,                                          KC_N,        KC_M,        KC_COMMA,    KC_DOT,        KC_SLASH,
        KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,                                          LT(BASE,KC_SPC),     KC_NO,  LT(SYMBOLS,KC_ENT), LT(FUNCTIONS,KC_DEL), KC_LALT
    ),


    // [BASE] = LAYOUT_split_3x6_3(
    //     KC_NO, KC_Q, KC_W, KC_E, KC_R, KC_T,                                    /* ------- */    KC_Y, KC_U, KC_I, KC_O, KC_P, KC_NO,
    //     KC_NO, LGUI_T(KC_A), LALT_T(KC_S), LCTL_T(KC_D), LSFT_T(KC_F), KC_G,    /* ------- */    KC_H, LSFT_T(KC_J), LCTL_T(KC_K), LALT_T(KC_L), LGUI_T(KC_SCLN), KC_NO,
    //     KC_NO, KC_Z, RALT_T(KC_X), KC_C, KC_V, KC_B,                            /* ------- */    KC_N, KC_M, KC_COMM, RALT_T(KC_DOT), KC_SLSH, KC_NO,
    //     LT(MEDIA,KC_ESC), LT(NUMPAD,KC_BSPC), LT(NAV,KC_TAB),                   /* ------- */    LT(SYMBOLS,KC_ENT), LT(0,KC_SPC), LT(FUNCTIONS,KC_DEL)
    // ),

   [NAV] = LAYOUT(
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,          KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,
        KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_NO,          KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,
        KC_NO, KC_RALT, KC_NO, KC_NO, KC_NO,                KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                               KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,
        //
        KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,                                          KC_AGIN, KC_UNDO, KC_CUT, KC_COPY, KC_PSTE,
        KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,                                          KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_CAPS,
        KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,                                          KC_HOME, KC_PGDN, KC_PGUP, KC_END, KC_INS,
        KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,                                          KC_SPC, KC_NO, KC_ENT, KC_DEL, KC_LALT
    ),


    // [NAV] = LAYOUT_split_3x6_3(
    //     KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,               /* ------- */     KC_AGIN, KC_UNDO, KC_CUT, KC_COPY, KC_PSTE, KC_NO,
    //     KC_NO, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_NO,       /* ------- */     KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_CAPS, KC_NO,
    //     KC_NO, KC_NO, KC_RALT, KC_NO, KC_NO, KC_NO,             /* ------- */     KC_HOME, KC_PGDN, KC_PGUP, KC_END, KC_INS, KC_NO,
    //     KC_NO, KC_NO, KC_NO,                                    /* ------- */     KC_ENT, KC_SPC, KC_DEL
    // ),

   [MEDIA] = LAYOUT(
        KC_NO, QK_BOOT, KC_NO, KC_NO, KC_NO,          KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,
        KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_NO,          KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,
        KC_NO, KC_RALT, KC_NO, KC_NO, KC_NO,                KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                               KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,
        //
        KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,                                          RGB_TOG, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI,
        KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,                                          KC_NO, KC_MPRV, KC_MSTP, KC_MNXT, KC_NO,
        KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,                                          KC_NO, KC_MUTE, KC_VOLD, KC_VOLU, KC_NO,
        KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,                                          KC_SPC, KC_NO, KC_MSTP, KC_MPLY, KC_MUTE
    ),


    // [MEDIA] = LAYOUT_split_3x6_3(
    //     KC_NO, QK_BOOT, KC_NO, KC_NO, KC_NO, KC_NO,         /* ------- */     RGB_TOG, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, KC_NO,
    //     KC_NO, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_NO,   /* ------- */     KC_NO, KC_MPRV, KC_MSTP, KC_MNXT, KC_NO, KC_NO,
    //     KC_NO, KC_NO, KC_RALT, KC_NO, KC_NO, KC_NO,         /* ------- */     KC_NO, KC_MUTE, KC_VOLD, KC_VOLU, KC_NO, KC_NO,
    //     KC_NO, KC_NO, KC_NO,                                /* ------- */     KC_MSTP, KC_MPLY, KC_MUTE
    // ),

   [NUMPAD] = LAYOUT(
        KC_1, KC_2, KC_3, KC_4, KC_5,         KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,
        KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_NO,          KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,
        KC_NO, KC_RALT, KC_NO, KC_NO, KC_NO,                KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                               KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,
        //
        KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,                                          KC_6, KC_7, KC_8, KC_9, KC_MINS,
        KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,                                          KC_PAST, LSFT_T(KC_4), KC_5, KC_6, KC_EQL,
        KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,                                          KC_SLSH, KC_1, KC_2, KC_3, KC_ENT,
        KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,                                          KC_0, KC_NO, KC_DOT, KC_NO, KC_NO
    ),


    // [NUMPAD] = LAYOUT_split_3x6_3(
    //     KC_NO, KC_1, KC_2, KC_3, KC_4, KC_5,           /* ------- */          KC_6, KC_7, KC_8, KC_9, KC_MINS, KC_NO,
    //     KC_NO, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_NO,   /* ------- */     KC_PAST, LSFT_T(KC_4), KC_5, KC_6, KC_EQL, KC_NO,
    //     KC_NO, KC_NO, KC_RALT, KC_NO, KC_NO, KC_NO,         /* ------- */     KC_SLSH, KC_1, KC_2, KC_3, KC_ENT, KC_NO,
    //     KC_NO, KC_NO, KC_NO,                                /* ------- */     KC_TAB, KC_0, KC_DOT
    // ),

   [SYMBOLS] = LAYOUT(
        KC_LBRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RBRC,   KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,
        KC_QUOT, KC_DLR, KC_PERC, KC_CIRC, KC_PLUS,            KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,
        KC_GRV, KC_EXLM, KC_AT, KC_HASH, KC_BSLS,              KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,
        KC_LPRN, KC_RPRN, KC_UNDS, KC_NO, KC_BSPC,                                KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,
        //
        KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,                                          KC_NO, KC_NO, KC_NO, KC_NO, QK_BOOT,
        KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,                                          KC_NO, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,
        KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,                                          KC_NO, KC_NO, KC_NO, KC_RALT, KC_NO,
        KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,                                          KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
    ),


    // [SYMBOLS] = LAYOUT_split_3x6_3(
    //     KC_NO, KC_LBRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RBRC,    /* ------- */     KC_NO, KC_NO, KC_NO, KC_NO, QK_BOOT, KC_NO,
    //     KC_NO, KC_QUOT, KC_DLR, KC_PERC, KC_CIRC, KC_PLUS,     /* ------- */     KC_NO, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, KC_NO,
    //     KC_NO, KC_GRV, KC_EXLM, KC_AT, KC_HASH, KC_BSLS,      /* ------- */     KC_NO, KC_NO, KC_NO, KC_RALT, KC_NO, KC_NO,
    //     KC_LPRN, KC_RPRN, KC_UNDS,                             /* ------- */     KC_NO, KC_NO, KC_NO
    // ),

   [FUNCTIONS] = LAYOUT(
        KC_PAUS, KC_F7, KC_F8, KC_F9, KC_F10,    KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,
        KC_SCRL, KC_F4, KC_F5, KC_F6, KC_F11,            KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,
        KC_PSCR, KC_F1, KC_F2, KC_F3, KC_F12,            KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,
        KC_APP, KC_SPC, KC_TAB, KC_NO,KC_BSPC,                                KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,
        //
        KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,                                          KC_NO, KC_NO, KC_NO, KC_NO, QK_BOOT,
        KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,                                          KC_NO, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,
        KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,                                          KC_NO, KC_NO, KC_NO, KC_RALT, KC_NO,
        KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,                                          KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
    ),


    // [FUNCTIONS] = LAYOUT_split_3x6_3(
    //     KC_NO, KC_PAUS, KC_F7, KC_F8, KC_F9, KC_F10,    /* ------- */     KC_NO, KC_NO, KC_NO, KC_NO, QK_BOOT, KC_NO,
    //     KC_NO, KC_SCRL, KC_F4, KC_F5, KC_F6, KC_F11,    /* ------- */     KC_NO, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, KC_NO,
    //     KC_NO, KC_PSCR, KC_F1, KC_F2, KC_F3, KC_F12,    /* ------- */     KC_NO, KC_NO, KC_NO, KC_RALT, KC_NO, KC_NO,
    //     KC_APP, KC_SPC, KC_TAB,                         /* ------- */     KC_NO, KC_NO, KC_NO
    // )
/* b3rtsuran
   *  ┌────┬────┬────┬────┬────┐┌────┐┌────┬────┬────┬────┬────┐
   *  │ 0  │ 1  │ 2  │ 3  │ 4  ││    ││ 5  │ 6  │ 7  │ 8  │ 9  │
   *  ├────┼────┼────┼────┼────┤├────┤├────┼────┼────┼────┼────┤
   *  │ESC │ [  │ ]  │ \  │ '  ││    ││LEFT│DOWN│ UP │RGHT│    │
   *  ├────┼────┼────┼────┼────┤├────┤├────┼────┼────┼────┼────┤
   *  │SHFT│    │ `  │ -  │ =  ││    ││ `  │    │ @  │ '  │ /  │
   *  └────┴────┴────┴────┴────┘└────┘└────┴────┴────┴────┴────┘
   *  ┌────┬────┬─────┐┌──────┐ ┌────┐ ┌──────┐┌─────┬────┬────┐
   *  │lalt│    │     ││      │ │    │ │ del  ││     │    │    │
   *  └────┴────┴─────┘└──────┘ └────┘ └──────┘└─────┴────┴────┘
  */
   //[_FL] = LAYOUT(

   //     KC_1,        KC_2,        KC_3,        KC_4,       KC_5,                         KC_6,        KC_7,      KC_8,        KC_9,        KC_0,
   //     KC_ESC,      KC_LBRC,     KC_RBRC,     KC_BSLS,    KC_QUOT,                      KC_LEFT,     KC_DOWN,   KC_UP,       KC_RIGHT,    KC_NO,
   //     KC_LSFT,     KC_NO,       KC_QUOT,     KC_MINS,    KC_EQL,                       KC_QUOT,     KC_NO,     LSFT(KC_2),  KC_GRV,      KC_SLASH,
   //     KC_LALT,     KC_NO,       KC_NO,       KC_NO,      KC_NO,                        KC_DEL,      KC_NO,     KC_NO,       KC_NO,       KC_NO

   // ),
 /*b3rtsuran
   *  ┌────┬────┬────┬────┬────┐┌────┐┌────┬────┬────┬────┬────┐
   *  │ F1 │ F2 │ F3 │ F4 │    ││    ││    │    │    │    │    │
   *  ├────┼────┼────┼────┼────┤├────┤├────┼────┼────┼────┼────┤
   *  │ F5 │ F6 │ F7 │ F8 │    ││    ││    │    │    │    │    │
   *  ├────┼────┼────┼────┼────┤├────┤├────┼────┼────┼────┼────┤
   *  │ F9 │F10 │F11 │F12 │    ││    ││    │    │    │    │    │
   *  └────┴────┴────┴────┴────┘└────┘└────┴────┴────┴────┴────┘
   *  ┌────┬────┬─────┐┌──────┐ ┌────┐ ┌──────┐┌─────┬────┬────┐
   *  │VOLU│VOLD│MUTE ││BRIGHT│ │    │ │      ││     │    │    │
   *  └────┴────┴─────┘└──────┘ └────┘ └──────┘└─────┴────┴────┘
   */
   //[_FFL] = LAYOUT(

   //     KC_F1,        KC_F2,        KC_F3,        KC_F4,        KC_NO,                    KC_NO,        KC_NO,        KC_NO,        KC_NO,        KC_NO,
   //     KC_F5,        KC_F6,        KC_F7,        KC_F8,        KC_NO,                    KC_NO,        KC_NO,        KC_NO,        KC_NO,        KC_NO,
   //     KC_F9,        KC_F10,       KC_F11,       KC_F12,       KC_NO,                    KC_NO,        KC_NO,        KC_NO,        KC_NO,        KC_NO,
   //     KC_NO,        KC_NO,        KC_NO,        KC_NO,        KC_NO,                    KC_NO,        KC_NO,        KC_NO,        KC_NO,        KC_NO

   // )
};
