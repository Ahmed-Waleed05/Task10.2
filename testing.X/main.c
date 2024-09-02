#include "GPIO.h"
#include "TIMER.h"
#include "ADC.h"
#include "SPI.h"
#include "EXT_INTRE.h"
int calculate_RPM();

void main() {
    
    ADC_INIT();
    TIMER_INIT();
    SPI_init();
    EXT_INIT();
    
    
    while(1)
    {
       int value= adc_run();
       
       ti_run(value);
       int rpm = calculate_RPM(); 
        SPI_send(rpm  & 0xFF);
        SPI_send(rpm >> 8);
       
        _delay_ms(500);
    }
}
int calculate_RPM() {
    static int last_count = 0;
    int rpm = ((count - last_count) * 120)/24;
    last_count = count;
    return rpm;
}
