#include <avr/io.h>
#include "TIMER.h"
void TIMER_INIT() {
    TCCR0A |= (1<<COM0A1) | (1<<WGM01) |(1<<WGM00);
    TCCR0B |= (1<<CS00) | (1<<CS01);
}
void ti_run(int duty_cycle){OCR0A =duty_cycle; }
