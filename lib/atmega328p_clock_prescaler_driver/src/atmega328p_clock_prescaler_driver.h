/*
 * atmega328p_clock_prescaler_driver.h
 *
 * Created: 8/25/2022 3:24:38 PM
 *  Author: doank
 */

#ifndef ATMEGA328P_CLOCK_PRESCALER_DRIVER_H_
#define ATMEGA328P_CLOCK_PRESCALER_DRIVER_H_

#include <avr/io.h>

#define PRESCALER_1 0
#define PRESCALER_2 1
#define PRESCALER_4 2
#define PRESCALER_8 3
#define PRESCALER_16 4
#define PRESCALER_32 5
#define PRESCALER_64 6
#define PRESCALER_128 7
#define PRESCALER_256 8

void CLK_PreScalerConfig(uint8_t PRESCALER_x);

#endif /* ATMEGA328P_CLOCK_PRESCALER_DRIVER_H_ */