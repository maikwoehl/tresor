#include "../inc/keyboard.h"
#include "../inc/keycodes.h"

#include <avr/io.h>

void keyboard_init()
{
    // Set columns as inputs
    F_DDR &= ~(C0 | C2);
    S_DDR &= ~C1;

    // Enable pull-up resistor on inputs
    F_PORT |= C0 | C2;
    S_PORT |= C1;
}

void keyboard_set_row(uint8_t row)
{
    // Make all outputs high impedance
    F_DDR &= ~(R0 | R2 | R3);
    S_DDR &= ~R1;

    // Enable all pull-up-resistors
    F_PORT |= R0 | R2 | 3;
    S_PORT |= R1;

    if (row != R1)
    {
        // Set pull-up resistor off and prepare for grounding
        F_PORT &= ~row;
        // Set mode to output and short to ground
        F_DDR |= row;
    }
    else
    {
        // Set pull-up resistor off and prepare for grounding
        S_PORT &= ~row;
        // Set mode to output and short to ground
        S_DDR |= row;
    }
}

uint16_t keyboard_get_key_code()
{
    uint8_t col = 0;
    uint8_t row = F_DDR & (R0 | R2 | R3);
    
    if (!row) // Check if no of R0, R2 or R3 is active
        row = S_DDR & R1;
    
    // Get pressed col (low-active)
    col = (F_PIN & (C0 | C2)) | (S_PIN & C1);

    // Negate columns to isolate bit
    col = ~col;

    // Find bit with mask where it was 0 before and now 1
    col &= C0 | C1 | C2;

    return (col<<8) | row;
}