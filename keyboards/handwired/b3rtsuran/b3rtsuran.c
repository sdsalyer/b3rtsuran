#include <i2c_master.h>
#include "quantum.h"

// for debug:
#include "print.h"

void i2c_init(void) {
    print("i2c_init");
}


void keyboard_post_init_kb(void) {
    debug_enable   = true;
    debug_matrix   = true;
    debug_keyboard = true;
    debug_mouse    = true;
    keyboard_post_init_user();
}
