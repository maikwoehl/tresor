#include <stdint.h>

#ifndef BATSENS_H_
#define BATSENS_H_

#define BATSENSDDR  DDRB
#define BATSENSPORT PORTB
#define BATSENSPIN  PINB
#define BATSENS     (1<<PB1);

void batsens_init();
uint8_t batsens_read();

#endif