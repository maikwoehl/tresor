#include "../inc/future.h"

/** 
 * Entry point with automated call of setup() and loop(). 
 */
int main()
{
    setup();
    
    while (1) 
        loop();
}

/**
 * Masking the use of the delay function.
 * 
 * TODO: Maybe make use of timer functions
 * 
 * \param ms wait time in milliseconds
 */
void delay(double ms) 
{
    _delay_ms(ms);
}
/**
 * Masking the use of the delay function.
 * 
 * TODO: Maybe make use of timer functions
 * 
 * \param us wait time in microseconds
 */
void delay_us(double us) 
{
    _delay_us(us);
}
