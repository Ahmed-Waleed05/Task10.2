#ifndef SPI_H
#define SPI_H
#define RPM_BUFFER_SIZE 10
#include <avr/io.h>
void SPI_init(void);
void SPI_send(int data);
#endif
