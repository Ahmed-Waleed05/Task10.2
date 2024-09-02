#include <xc.h>
#include <stdio.h>
#include "SPI.h"
void SPI_init() {
    DDRB |= (1 << PB3) | (1 << PB5) | (1 << PB2);
    SPCR |= (1 << SPE) | (1 << MSTR) | (1 << SPR0);
}

void SPI_send(int data) {
    SPDR = data;
    while (!(SPSR & (1 << SPIF))); 
}
void SPI_send_string(const char* str) {
    while (*str) {
        SPI_send((int)*str); // Transmit each character
        str++;
    }
}
void rpm_to_string(int rpm, char* buffer) {
    snprintf(buffer, RPM_BUFFER_SIZE, "RPM: %u", rpm);
}