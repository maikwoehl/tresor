#include <stdint.h>

#ifndef KEYBOARD_H_
#define KEYBOARD_H_

#define F_DDR   DDRD
#define S_DDR   DDRB
#define F_PORT  PORTD
#define S_PORT  PORTB
#define F_PIN   PIND
#define S_PIN   PINB

#define R0      (1<<PD4)
#define R1      (1<<PB6)
#define R2      (1<<PD5)
#define R3      (1<<PD7)

#define C0      (1<<PD3)
#define C1      (1<<PB7)
#define C2      (1<<PD6)

void keyboard_init();
void keyboard_set_row(uint8_t row);
uint16_t keyboard_get_key_code();

#endif