/**
 * \mainpage Tresor application
 * \author Maik Wöhl
 * \date 13. July 2021
 */
#include <stdint.h>
#include <stddef.h>

#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/sleep.h>

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
    static uint16_t counter = 0; 
    static uint8_t is_active = 0;
    if (g_timer0)
    {
        g_timer0 = 0;
        // DO YOUR STUFF BELOW

        if ( (keyboard_get_key_code() & 0xFF) != 0)
        {
            is_active = 1;

            // TODO: Handle keycode

            // TODO: signal processing end    
        }

        if (counter >= 6)
        {
            counter = 0;

            if (!is_active)
            {
                // TODO: Disable Timer1 and set Timer0 to very slow interrupt rate
                sleep_mode(); 
                // TODO: Enable Timer1 and set Timer0 to default interrupt rate
            }
                
        }

        // DO YOUR STUFF ABOVE
        g_reset_btn_count++;
        counter++;
    }

    // TODO: Power-down mode with INT1 external interrupt?
}
