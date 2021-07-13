#include <stdint.h>

#ifndef BATSENS_H_
#define BATSENS_H_

#define BATSENSDDR  DDRB
#define BATSENSPORT PORTB
#define BATSENSPIN  PINB
#define BATSENS     (1<<PB1);

void reset_batsens_init();
uint8_t reset_batsens_read();

#endif