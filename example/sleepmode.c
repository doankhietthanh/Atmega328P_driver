#include <avr/io.h>
#define F_CPU 1000000UL // 1MHz
#include <util/delay.h>
#include <avr/interrupt.h>
#include <avr/sleep.h>
#include <atmega328p_gpio_driver.h>
#include <atmega328p_sleep_mode_driver.h>

static void GPIO_Init(void);

ISR(INT0_vect)
{
    EIMSK &= ~_BV(INT0); // one interrupt to wake up only
}

int main()
{
    GPIO_Init();
    EICRA = 0x00; // interrupt mode low level
    while (1)
    {
        EIMSK |= _BV(INT0); // enable INT0

        for (int8_t i = 0; i < 3; i++)
        {
            GPIO_WritePin(&GPIO_PORT_B, GPIO_PIN_5, 0);
            _delay_ms(1000);
            GPIO_WritePin(&GPIO_PORT_B, GPIO_PIN_5, 1);
            _delay_ms(1000);
        }
        GPIO_WritePin(&GPIO_PORT_B, GPIO_PIN_5, 0);
        SLEEP_Init(SLEEP_MODE_PWR_DOWN);
        GPIO_WritePin(&GPIO_PORT_B, GPIO_PIN_5, 1);
    }

    return 0;
}

static void GPIO_Init(void)
{
    GPIO_SetMode(&GPIO_PORT_D, GPIO_PIN_2, GPIO_MODE_INPUT);
    GPIO_WritePin(&GPIO_PORT_D, GPIO_PIN_2, GPIO_PIN_SET);
    GPIO_SetMode(&GPIO_PORT_B, GPIO_PIN_5, GPIO_MODE_OUTPUT);
}
