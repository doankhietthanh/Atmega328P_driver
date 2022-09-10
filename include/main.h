#include <avr/io.h>
#define F_CPU 1000000UL // 1MHz
#include <util/delay.h>
#include <avr/interrupt.h>

#include <atmega328p_gpio_driver.h>
#include <atmega328p_clock_prescaler_driver.h>
#include <atmega328p_watchdog_timer_driver.h>
#include <atmega328p_sleep_mode_driver.h>