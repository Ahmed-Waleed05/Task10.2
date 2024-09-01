#include "EXT_INTR.h"
#include <avr/interrupt.h>
#include <avr/io.h>
#include "GPIO.h"
volatile uint16_t encoder_count = 0;

void ExternalInterrupts_init(void) { 
    
     DDRD &= ~(1 << PD2); // Clear PD2 for input
    DDRD &= ~(1 << PD3); // Clear PD3 for input

    // Enable pull-up resistors on PD2 and PD3
    PORTD |= (1 << PD2) | (1 << PD3);
    
    // Example: Configure PB1 as output for PWM
    DDRB |= (1 << PB1);
    
    
    
    EICRA |= (1 << ISC00) | (1 << ISC10) | (1 << ISC01) | (1 << ISC11);
    EIMSK |= (1 << INT0) | (1 << INT1);
    sei();
}

ISR(INT0_vect) {
    encoder_count++;
}

ISR(INT1_vect) {
    encoder_count--;
}
