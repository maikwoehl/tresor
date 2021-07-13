#include <stdint.h>

#ifndef BUZZER_H_
#define BUZZER_H_

#define BUZZDDR     DDRD
#define BUZZPORT    PORTD
#define BUZZPIN     PIND

void buzzer_init();
void buzzer_start();
void buzzer_stop();

#endif