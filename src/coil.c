#include "../inc/coil.h"

#include <avr/io.h>

void coil_init()
{
    COILDDR |= COIL;
}

void coil_unlock()
{
    COILPORT |= COIL;
}

void coil_lock()
{
    COILPORT &= ~COIL;

}