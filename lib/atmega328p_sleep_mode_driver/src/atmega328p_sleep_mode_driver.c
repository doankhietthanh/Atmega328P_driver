#include "atmega328p_sleep_mode_driver.h"

void SLEEP_Init(uint8_t mode)
{
    sleep_enable();
    set_sleep_mode(mode);
    // EIMSK |= _BV(INT0); // enable INT0
    adcsra = ADCSRA; // save the ADC Control and Status Register A
    ADCSRA = 0;      // disable ADC
    cli();
    mcucr1 = MCUCR | _BV(BODS) | _BV(BODSE); // turn off the brown-out detector
    mcucr2 = mcucr1 & ~_BV(BODSE);
    MCUCR = mcucr1;
    MCUCR = mcucr2;
    sei();           // ensure interrupts enabled so we can wake up again
    sleep_cpu();     // go to sleep
    sleep_disable(); // wake up here
    ADCSRA = adcsra; // restore ADCSRA
}