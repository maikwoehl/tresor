#include <stdint.h>

#ifndef LEDS_H
#define LEDS_H_

#define LEDDDR      DDRC
#define LEDPORT     PORTC
#define LEDRED      (1<<PC1)
#define LEDYELLOW   (1<<PC2)
#define LEDGREEN    (1<<PC3)

void led_init();
void led_set(uint8_t led_bits, uint8_t state);

#endif