#ifndef EXT_INTERRUPTS_H
#define EXT_INTERRUPTS_H
#include <avr/io.h>
#include <avr/interrupt.h>
 
void ExternalInterrupts_init(void);
ISR(INT0_vect);
ISR(INT1_vect);

#endif 
