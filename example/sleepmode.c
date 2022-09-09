#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/sleep.h>
#define F_CPU 1000000UL // 1MHz
#include <util/delay.h>
#include <atmega328p_gpio_driver.h>
#include <atmega328p_clock_prescaler_driver.h>

int8_t intCounter, adcsra, mcucr1, mcucr2;

static void GPIO_Init(void);
void goToSleep(void);

ISR(INT0_vect)
{
    EIMSK &= ~(1 << INT0);
}

int main(void)
{
    GPIO_Init();
    EICRA |= (1 << ISC01) | (1 << ISC00);
    while (1)
    {
        EIMSK |= (1 << INT0);
        for (int8_t i = 0; i < 3; i++)
        {
            GPIO_WritePin(GPIO_PORT_B, GPIO_PIN_5, 0);
            delay(1000);
            GPIO_WritePin(GPIO_PORT_B, GPIO_PIN_5, 1);
            delay(1000);
        }
        goToSleep();
    }
    return 0;
}

static void GPIO_Init(void)
{
    GPIO_SetMode(GPIO_PORT_B, GPIO_PIN_5, GPIO_MODE_OUTPUT);
    GPIO_SetMode(GPIO_PORT_D, GPIO_PIN_2, GPIO_MODE_INPUT);
    GPIO_WritePin(GPIO_PORT_B, GPIO_PIN_5, 1);
    GPIO_WritePin(GPIO_PORT_D, GPIO_PIN_2, 1);
}

void goToSleep(void)
{
    sleep_enable();
    set_sleep_mode(SLEEP_MODE_PWR_DOWN);
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
