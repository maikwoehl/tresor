#include <stdint.h>

#ifndef RESET_BTN_H_
#define RESET_BTN_H_

#define BTNDDR  DDRB
#define BTNPORT PORTB
#define BTNPIN  PINB
#define BTN     (1<<PB1);

void reset_btn_init();
uint8_t reset_btn_read();

#endif