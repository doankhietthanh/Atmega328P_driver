#include <avr/io.h>
#include <avr/interrupt.h>
#define F_CPU 1000000UL // 1MHz
#include <util/delay.h>
#include <atmega328p_gpio_driver.h>
#include <atmega328p_clock_prescaler_driver.h>
#include <atmega328p_watchdog_timer_driver.h>

ISR(INT0_vect)
{
    if (GPIO_ReadPin(GPIO_PORT_D, GPIO_PIN_2) == 0)
    {
        while (GPIO_ReadPin(GPIO_PORT_D, GPIO_PIN_2) == 0)
        {
        }
    }
}

static void GPIO_Init(void);
static void ISR_Init(void);

int main(void)
{
    GPIO_Init();
    ISR_Init();
    while (1)
    {
        WDT_On(WDT_Mode_SysRst, WDT_Period_2s);
        GPIO_TogglePin(GPIO_PORT_B, GPIO_PIN_5);
        _delay_us(200000);
        WDT_Off();
    }
    return 0;
}

static void GPIO_Init(void)
{
    GPIO_SetMode(GPIO_PORT_D, GPIO_PIN_2, GPIO_MODE_INPUT);
    GPIO_SetMode(GPIO_PORT_B, GPIO_PIN_5, GPIO_MODE_OUTPUT);
    GPIO_WritePin(GPIO_PORT_D, GPIO_PIN_2, 1);
}

static void ISR_Init(void)
{
    EICRA |= (1 << ISC01); // Mode: falling edge
    sei();                 // Enable interrupts by setting the global interrupt mask
    EIMSK |= (1 << INT0);
}
