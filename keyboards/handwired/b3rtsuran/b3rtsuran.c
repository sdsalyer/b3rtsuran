#include <i2c_master.h>
#include "quantum.h"

// for debug:
#include "print.h"

#define I2C_ADDR        (0x36<<1)
#define SS_SWITCH       24
#define SS_NEOPIX       6
#define SS_VERSION      0x02

i2c_status_t i2c_status = I2C_STATUS_ERROR;
bool is_i2c_init = false;
bool is_debug_enabled = false;



void enable_debug(void) {
    debug_enable   = true;
    debug_matrix   = true;
    debug_keyboard = true;
    debug_mouse    = true;
}

void enable_i2c(void) {
    if ( ! is_i2c_init) {
        print("\n***** INITIALIZING I2C *****\n");
        i2c_init();
        is_i2c_init = true;
    }
    else {
        print("\n***** i2c already initalized.... *****\n");
    }
}

/*
    keyboard_pre_init_* - Happens before most anything is started. Good for hardware setup that you want running very early.
*/
void keyboard_pre_init_kb(void) {
    // if debug turned on in config
    enable_debug();
    // end if

    print("\n***** PRE-INIT KB *****\n");

    //i2c_init();
    keyboard_pre_init_user();

    print("\n***** END PRE-INIT KB *****\n");
}

/*
    matrix_init_* - Happens midway through the firmware's startup process. Hardware is initialized, but features may not be yet.
*/
void matrix_init_kb(void) {
    enable_debug();
    print("\n***** INIT KB *****\n");

    //i2c_init();
    matrix_init_user();

    print("\n***** END INIT KB *****\n");
}

/*
    keyboard_post_init_* - Happens at the end of the firmware's startup process. This is where you'd want to put "customization" code, for the most part.
*/
void keyboard_post_init_kb(void) {
    enable_debug();
    print("\n***** POST-INIT KB *****\n");

    //i2c_init();
    keyboard_post_init_user();

    enable_i2c();

    print("\n***** END POST-INIT KB *****\n");


    // try to get version
    uint8_t data[3];
    data[0] = 0;
    data[1] = 0;
    data[2] = 0;
    i2c_status = i2c_receive(I2C_ADDR, (uint8_t *)data, 4, 30);
    if (i2c_status != I2C_STATUS_SUCCESS) {

        print("\n *Error* unable to get i2c version \n");
    }
    else {
        print("\n *YEAH* something might have worked? \n");
    }
}
// void matrix_scan_kb(void) {
//     print("\n***** scan KB *****\n");
//     // put your keyboard start-up code here
//     // runs once when the firmware starts up
//     i2c_init();
//     matrix_scan_user();
//
//     print("\n***** scan KB END *****\n");
// }

/*
    The default I2C address is 0x36.
    SCL - level shifted so you can use 3-5V logic, there's a 10K pullup
    SDA - level shifted so you can use 3-5V logic, there's a 10K pullup
    Onboard NeoPixel LED - connected to seesaw pin 6.
    Rotary encoder - button on the encoder is connected to seesaw pin 24.
*/
void i2c_init(void) {
}



