#include "../inc/reset_btn.h"

#include <avr/io.h>

volatile uint8_t g_debounce_cycles;

void reset_btn_init(uint8_t debounce_cycles)
{
    g_debounce_cycles = debounce_cycles;
    // Make input
    BTNDDR &= ~BTN;
    // Enable internal pull-up resistor
    BTNPORT |= BTN;
}

uint8_t reset_btn_read()
{
    if (g_reset_btn_count == 0) 
    {
        g_reset_btn_count = g_debounce_cycles;
        return 1;
    }
    
    return 0;
}