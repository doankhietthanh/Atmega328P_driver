#ifndef ATMEGA328P_SLEEP_MODE_DRIVER_H_
#define ATMEGA328P_SLEEP_MODE_DRIVER_H_

#include <avr/io.h>
#include <avr/sleep.h>
#include <avr/interrupt.h>

int8_t intCounter, adcsra, mcucr1, mcucr2;

// Mode: SLEEP_MODE_IDLE (0x00 << 1)
// Mode: SLEEP_MODE_ADC (0x01 << 1)
// Mode: SLEEP_MODE_PWR_DOWN (0x02 << 1)
// Mode: SLEEP_MODE_PWR_SAVE (0x03 << 1)
// Mode: SLEEP_MODE_STANDBY (0x06 << 1)
// Mode: SLEEP_MODE_EXT_STANDBY (0x07 << 1)

void SLEEP_Init(uint8_t mode);

#endif /* ATMEGA328P_SLEEP_MODE_DRIVER_H_ */