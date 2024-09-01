#include <xc.h>
#include "SPI.h"
void SPI_init() {
    DDRB |= (1 << PB3) | (1 << PB5);
    DDRB &= ~(1 << PB4);
    SPCR |= (1 << SPE) | (1 << MSTR) | (1 << SPR0);
}

void SPI_send(int data) {
    SPDR = data;
    while (!(SPSR & (1 << SPIF))); 
}
