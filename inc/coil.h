#include <stdint.h>

#ifndef COIL_H_
#define COIL_H_

#define COILDDR     DDRD
#define COILPORT    PORTD
#define COIL        (1<<PD0)

void coil_init();
void coil_unlock();
void coil_lock();

#endif