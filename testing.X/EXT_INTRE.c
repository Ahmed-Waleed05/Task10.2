#include "EXT_INTRE.h"
int count=0;
void EXT_INIT() {
    DDRD &= ~(1 << PD2); 
    DDRD &= ~(1 << PD3); 
    PORTD |= (1 << PD2) | (1 << PD3);
    EICRA |= (1 << ISC00) | (1 << ISC10) | (1 << ISC01) | (1 << ISC11);
    EIMSK |= (1 << INT0) | (1 << INT1);
    sei();
}
ISR(INT0_vect) {
    count++;
}

ISR(INT1_vect) {
    count--;
}