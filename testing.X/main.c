#include <xc.h>
#include <util/delay.h>
#include "GPIO.h"
#include "TIMER.h"
#include "ADC.h"
#include "SPI.h"

void main() {
    ADC_INIT();
    TIMER_INIT();
    SPI_init();
    while(1)
    {
       int value= adc_run(0);
       ti_run(value);
       int rpm = calculate_RPM(); 
        SPI_send(rpm & 0xFF);
        SPI_send(rpm >> 8);  

        _delay_ms(100);
    }
}
int calculate_RPM() {
    static int last_count = 0;
    int rpm = (PLACEHOLDER - last_count) * 60;
    last_count = PLACEHOLDER;
    return rpm;
}
