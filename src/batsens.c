#include "../inc/batsens.h"

#include <avr/io.h>

void batsens_init()
{
    // Make input
    BATSENSDDR &= ~BATSENS;
    // TODO: Enable ADC
}

uint8_t batsens_read()
{
    // TODO: Read ADC
}