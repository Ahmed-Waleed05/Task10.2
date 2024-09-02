#ifndef EXT_INTRE_H
#define	EXT_INTRE_H
#include <xc.h>  
#include <avr/interrupt.h>
#include <avr/io.h>
#include <util/delay.h>
#define F_CPU 20000000
void EXT_INIT();
ISR(INT0_vect);
ISR(INT1_vect);
extern int count;
#endif
