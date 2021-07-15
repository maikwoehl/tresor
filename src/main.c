/**
 * \mainpage Tresor application
 * \author Maik Wöhl
 * \date 13. July 2021
 */
#include <stdint.h>
#include <stddef.h>

#include "../inc/future.h"
#include "../inc/coil.h"
#include "../inc/leds.h"
#include "../inc/reset_btn.h"
#include "../inc/batsens.h"
#include "../inc/buzzer.h"
#include "../inc/keyboard.h"

void setup(void) {
    coil_init();
    led_init();
    reset_btn_init();
    batsens_init();
}

void loop(void) {
}
