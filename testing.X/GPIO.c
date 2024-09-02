#include <xc.h>
#include <avr/io.h>
#include "GPIO.h"
void SET_PIN(char *ddr, int n, int dir) {
  if(dir) *ddr |= (1 << n);
  else *ddr &= ~(1 << n);
}

void PIN_WRITE(char *port, int n, int val) {
  if(val) *port |= (1 << n);
  else *port &= ~(1 << n);
}

int PIN_READ(char *pin, int n) {
  return (*pin & (1 << n)) != 0;
}