#ifndef ATMEGA328P_WATCHDOG_TIMER_DRIVER_H_
#define ATMEGA328P_WATCHDOG_TIMER_DRIVER_H_

#include <avr/io.h>

typedef enum
{
    WDT_Mode_Stop = 0,              // none
    WDT_Mode_Interrupt = _BV(WDIE), // interrupt
    WDT_Mode_SysRst = _BV(WDE),     // interrupt, then go system reset mode
} WDT_Mode;

typedef enum
{
    WDT_Period_16ms = 0,
    WDT_Period_32ms = _BV(WDP0),
    WDT_Period_64ms = _BV(WDP1),
    WDT_Period_125ms = _BV(WDP0) | _BV(WDP1),
    WDT_Period_250ms = _BV(WDP2),
    WDT_Period_500ms = _BV(WDP2) | _BV(WDP0),
    WDT_Period_1s = _BV(WDP2) | _BV(WDP1),
    WDT_Period_2s = _BV(WDP2) | _BV(WDP1) | _BV(WDP0),
    WDT_Period_4s = _BV(WDP3),
    WDT_Period_8s = _BV(WDP3) | _BV(WDP0),
} WDT_Prescaler;

void WDT_On(WDT_Mode mode, WDT_Prescaler period);

void WDT_Off(void);

#endif /* ATMEGA328P_WATCHDOG_TIMER_DRIVER_H_ */