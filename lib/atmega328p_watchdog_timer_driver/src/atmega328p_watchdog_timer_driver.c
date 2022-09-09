#include "atmega328p_watchdog_timer_driver.h"

void WDT_On(WDT_Mode mode, WDT_Prescaler period)
{
    WDTCSR |= (1 << WDCE) | mode;
    WDTCSR = (1 << WDE) | period;
}

void WDT_Off(void)
{
    MCUSR &= ~(1 << WDRF);
    WDTCSR |= (1 << WDCE) | (1 << WDE);
    WDTCSR = 0x00;
}
