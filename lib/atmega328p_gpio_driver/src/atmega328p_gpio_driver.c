/*
 * atmega328p_gpio_driver.c
 *
 * Created: 8/12/2022 10:47:44 PM
 *  Author: doank
 */

#include "atmega328p_gpio_driver.h"

void GPIO_SetMode(volatile uint8_t *GPIO_Port, uint8_t GPIO_Pin, GPIO_InitMode GPIO_Mode)
{
    if (*GPIO_Port == GPIO_PORT_B)
    {
        if (GPIO_Mode == GPIO_MODE_INPUT)
        {
            DDRB &= ~(1 << GPIO_Pin);
        }
        else if (GPIO_Mode == GPIO_MODE_OUTPUT)
        {
            DDRB |= (1 << GPIO_Pin);
        }
    }
    else if (*GPIO_Port == GPIO_PORT_C)
    {
        if (GPIO_Mode == GPIO_MODE_INPUT)
        {
            DDRC &= ~(1 << GPIO_Pin);
        }
        else if (GPIO_Mode == GPIO_MODE_OUTPUT)
        {
            DDRC |= (1 << GPIO_Pin);
        }
    }
    else if (*GPIO_Port == GPIO_PORT_D)
    {
        if (GPIO_Mode == GPIO_MODE_INPUT)
        {
            DDRD &= ~(1 << GPIO_Pin);
        }
        else if (GPIO_Mode == GPIO_MODE_OUTPUT)
        {
            DDRD |= (1 << GPIO_Pin);
        }
    }
}

uint8_t GPIO_ReadPort(volatile uint8_t *GPIO_Port)
{
    uint8_t data = 0;

    if (*GPIO_Port == GPIO_PORT_B)
    {
        data = PINB;
    }
    else if (*GPIO_Port == GPIO_PORT_C)
    {
        data = PINC;
    }
    else if (*GPIO_Port == GPIO_PORT_D)
    {
        data = PIND;
    }

    return data;
}

uint8_t GPIO_ReadPin(volatile uint8_t *GPIO_Port, uint8_t GPIO_Pin)
{
    uint8_t pinValue = 0;

    if (*GPIO_Port == GPIO_PORT_B)
    {
        pinValue = (PINB & _BV(GPIO_Pin));
    }
    else if (*GPIO_Port == GPIO_PORT_C)
    {
        pinValue = (PINC & _BV(GPIO_Pin));
    }
    else if (*GPIO_Port == GPIO_PORT_D)
    {
    }

    return pinValue;
}

void GPIO_WritePin(volatile uint8_t *GPIO_Port, uint8_t GPIO_Pin, GPIO_PinState Pin_State)
{
    if (Pin_State == GPIO_PIN_RESET)
    {
        *GPIO_Port &= ~(1 << GPIO_Pin);
    }
    else
    {
        *GPIO_Port |= (1 << GPIO_Pin);
    }
}

void GPIO_TogglePin(volatile uint8_t *GPIO_Port, uint8_t GPIO_Pin)
{
    *GPIO_Port ^= (1 << GPIO_Pin);
}
