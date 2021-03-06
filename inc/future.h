#define __DELAY_BACKWARD_COMPATIBLE__
#define F_CPU   1000000UL

#include <stdint.h>
#include <util/delay.h>

extern int main();
extern void setup (void);
extern void loop  (void);

#ifndef FUTURE_H_
#define FUTURE_H_

void delay (double ms);
void delay_us (double us);

#endif

