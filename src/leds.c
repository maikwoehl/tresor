#include "../inc/leds.h"

#include <avr/io.h>

void led_init()
{
    LEDDDR |= LEDRED | LEDYELLOW | LEDGREEN;
}

void led_set(uint8_t led_bits, uint8_t state)
{
    if (state)
    {
        LEDPORT |= led_bits;
    }
    else
    {
        LEDPORT &= ~led_bits;
    }
}