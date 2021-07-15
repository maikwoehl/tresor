#include <stdint.h>
#include "future.h"

#ifndef BUZZER_H_
#define BUZZER_H_

#define BUZZDDR     DDRB
#define BUZZ        (1<<PB1)

#define PRESCALER       1

// Formula: f = f_clk / (2 * PRESCALER * TOP)
#define FREQUENCY(freq)     (F_CPU / (2 * PRESCALER * freq))

void buzzer_init();
void buzzer_start();
void buzzer_stop();

#endif