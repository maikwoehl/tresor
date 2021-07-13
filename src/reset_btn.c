#include "../inc/reset_btn.h"

#include <avr/io.h>

void reset_btn_init()
{
    // Make input
    BTNDDR &= ~BTN;
    // Enable internal pull-up resistor
    BTNPORT |= BTN;
}

uint8_t reset_btn_read()
{
    // TODO: Debounce!
    return BTNPIN & BTN;
}