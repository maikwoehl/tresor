/**
 * \mainpage Tresor application
 * \author Maik Wöhl
 * \date 13. July 2021
 */
#include <stdint.h>
#include <stddef.h>

#include <avr/io.h>
#include <avr/interrupt.h>

#include "../inc/future.h"
#include "../inc/coil.h"
#include "../inc/leds.h"
#include "../inc/batsens.h"
#include "../inc/buzzer.h"
#include "../inc/keyboard.h"
#include "../inc/reset_btn.h"

#define TIMER_PERIOD    (F_CPU) / (256 * (1/0.025))

volatile uint8_t g_timer0 = 0;

ISR(TIMER0_OVF_vect)
{
    g_timer0 = 1;
}

void setup(void) {
    char cSREG;
    cli();
    cSREG = SREG;
    // Set global timer flag to 0
    g_timer0 = 0;
    // Set Prescaler to 256
    TCCR0 |= (1<<CS02);
    // Set timer frequency
    TCNT0 = (uint8_t) TIMER_PERIOD;
    // Enable timer interrupt
    TIMSK |= (1<<TOIE0);

    coil_init();
    led_init();
    reset_btn_init(2);
    batsens_init();
    buzzer_init();
    keyboard_init();

    SREG = cSREG;
    sei();
}

void loop(void) {
    if (g_timer0)
    {
        g_timer0 = 0;
        g_reset_btn_count++;
        // DO YOUR STUFF BELOW

        
    }
}
