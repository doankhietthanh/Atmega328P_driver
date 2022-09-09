/*
 * atmega328p_clock_prescaler_driver.c
 *
 * Created: 8/25/2022 3:24:45 PM
 *  Author: doank
 */

#include "atmega328p_clock_prescaler_driver.h"

void CLK_PreScalerConfig(uint8_t PRESCALER_x)
{
    CLKPR = _BV(CLKPCE);
    CLKPR = PRESCALER_x;
}