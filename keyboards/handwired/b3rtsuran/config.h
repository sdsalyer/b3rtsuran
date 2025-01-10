// Copyright 22 ScatteredDrifter / fabiansta

#pragma once

#include "config_common.h"

/* --- USB Device properties --- */
//#define VENDOR_ID 0xFAB0
//#define PRODUCT_ID 0xFAB1
//#define DEVICE_VER 0x0001
//#define MANUFACTURER b3rts
//#define PRODUCT b3rtsuran

/* --- Matrix definition --- */
#define MATRIX_ROWS 8
#define MATRIX_COLS 10

/* --- Matrix assignment --- */
//        "cols": [
//            // Left
//            "GP29", "GP28", "GP27", "GP0", "GP26",
//            // Right
//            "GP5", "GP4", "GP3", "GP1", "GP2"
//        ],
//        "rows": [
//            // Left
//            "GP18", "GP20", "GP19", "GP10",
//            // Right
//            "GP6", "GP7", "GP8", "GP9",
//        ]

#define MATRIX_COL_PINS \
    { GP29, GP28, GP27, GP0, GP26, \
      GP5,  GP4,  GP3,  GP1, GP2 }
#define MATRIX_ROW_PINS \
    { GP18, GP20, GP19, GP10, \
      GP6,  GP7,  GP8,  GP9 }
/* --- Encoder assignment --- */
//#define ENCODER_RESOLUTION 4
//#define ENCODERS_PAD_A {GP22, GP4}
//#define ENCODERS_PAD_B {GP23, GP5}

/*#define ENCODER_DIRECTION_FLIP*/

/* --- additional settings --- */
//#define DEBUG_MATRIX_SCAN_RATE
//#define LAYER_STATE_16BIT
// reducing chattering, set to 0 if not necessary
//#define DEBOUNCE 5
#define DIODE_DIRECTION COL2ROW


//#define QMK_WAITING_TEST_BUSY_PIN GP8
//#define QMK_WAITING_TEST_YIELD_PIN GP9

/* --- RP2040 specific settings */
//#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
//#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_LED GP25
//#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 500U

//#define RGB_DI_PIN GP12
