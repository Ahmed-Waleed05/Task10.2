#include <avr/io.h>
#include "ADC.h"
void ADC_INIT() {
    ADMUX |= (1<<REFS0) | (1<<MUX1) | (1<<MUX0);
    ADCSRA = (1 << ADEN) | (1 << ADPS1) | (1 << ADPS2);
}
int adc_run(int channel )
{
    ADMUX = (ADMUX & 0xF0) | (channel & 0x0F);
    ADCSRA |= (1 << ADSC);
     while (ADCSRA & (1 << ADSC));
     return ADC;
}