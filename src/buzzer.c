#include "../inc/buzzer.h"

#include <avr/io.h>

void buzzer_init()
{
    // Set buzzer pin to output
    BUZZDDR |= BUZZ;
    // Reset control registers
    TCCR1A &= ~0b11111111;
    TCCR1B &= ~0b11011111;
    // Set OC1A to be set on upcounting and to be not set on downcounting
    TCCR1A |= (1<<COM1A0) | (1<<COM1A1);
    // Set PWM Phase and Frequency Correct with OCR1A as source
    TCCR1A |= (1<<WGM10);
    TCCR1B |= (1<<WGM12);
    // Set Prescaler to 1
    TCCR1B |= (1<<CS10);
}

void buzzer_start(uint16_t freq)
{
    uint16_t tone = (uint16_t) FREQUENCY(freq);
    // Set high and low byte of OCR1A register
    OCR1AL = tone & 0xFF;
    OCR1AH = (tone & 0xFF00) >> 8;
    // Enable timer interrupt
    TIMSK |= (1<<OCIE1A);
}

void buzzer_stop()
{
    TIMSK &= (1<<OCIE1A);
}