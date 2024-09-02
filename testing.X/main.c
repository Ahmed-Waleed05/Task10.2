#include "GPIO.h"
#include "TIMER.h"
#include "ADC.h"
#include "SPI.h"
#include "EXT_INTRE.h"
int calculate_RPM();

void main() {
    
    char rpm_string[RPM_BUFFER_SIZE];
    
    ADC_INIT();
    TIMER_INIT();
    SPI_init();
    EXT_INIT();
    
    
    while(1)
    {
       int value= adc_run(0);
       ti_run(value);
       int rpm = calculate_RPM(); 
        //SPI_send(rpm  & 0xFF);
        //SPI_send(rpm >> 8);  
       
       rpm_to_string(rpm, rpm_string); // Convert RPM to string
        SPI_send_string(rpm_string); // Send RPM string over SPI
       
        _delay_ms(500);
    }
}
int calculate_RPM() {
    static int last_count = 0;
    int rpm = ((count - last_count) * 60)/24;
    last_count = count;
    return rpm;
}
