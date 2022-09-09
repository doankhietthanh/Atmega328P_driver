/*
 * atmega328p_gpio_driver.c
 *
 * Created: 8/12/2022 10:47:44 PM
 *  Author: doank
 */

#include "atmega328p_gpio_driver.h"

void GPIO_SetMode(GPIO_PortType GPIO_Port, uint8_t GPIO_Pin, GPIO_InitMode GPIO_Mode)
{
    if (GPIO_Port == GPIO_PORT_B)
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
    else if (GPIO_Port == GPIO_PORT_C)
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
    else if (GPIO_Port == GPIO_PORT_D)
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

uint8_t GPIO_ReadPort(GPIO_PortType GPIO_Port)
{
    uint8_t data = 0;

    if (GPIO_Port == GPIO_PORT_B)
    {
        data = PINB;
    }
    else if (GPIO_Port == GPIO_PORT_C)
    {
        data = PINC;
    }
    else if (GPIO_Port == GPIO_PORT_D)
    {
        data = PIND;
    }

    return data;
}

uint8_t GPIO_ReadPin(GPIO_PortType GPIO_Port, uint8_t GPIO_Pin)
{
    uint8_t pinValue = 0;

    if (GPIO_Port == GPIO_PORT_B)
    {
        pinValue = (PINB & _BV(GPIO_Pin));
    }
    else if (GPIO_Port == GPIO_PORT_C)
    {
        pinValue = (PINC & _BV(GPIO_Pin));
    }
    else if (GPIO_Port == GPIO_PORT_D)
    {
        pinValue = (PINC & _BV(GPIO_Pin));
    }

    return pinValue;
}

void GPIO_WritePin(GPIO_PortType GPIO_Port, uint8_t GPIO_Pin, GPIO_PinState Pin_State)
{
    if (GPIO_Port == GPIO_PORT_B)
    {
        if (Pin_State == GPIO_PIN_RESET)
        {
            PORTB &= ~(1 << GPIO_Pin);
        }
        else
        {
            PORTB |= (1 << GPIO_Pin);
        }
    }
    else if (GPIO_Port == GPIO_PORT_C)
    {
        if (Pin_State == GPIO_PIN_RESET)
        {
            PORTC &= ~(1 << GPIO_Pin);
        }
        else
        {
            PORTC |= (1 << GPIO_Pin);
        }
    }
    else if (GPIO_Port == GPIO_PORT_D)
    {
        if (Pin_State == GPIO_PIN_RESET)
        {
            PORTD &= ~(1 << GPIO_Pin);
        }
        else
        {
            PORTD |= (1 << GPIO_Pin);
        }
    }
}

void GPIO_TogglePin(GPIO_PortType GPIO_Port, uint8_t GPIO_Pin)
{
    if (GPIO_Port == GPIO_PORT_B)
    {
        PORTB ^= (1 << GPIO_Pin);
    }
    else if (GPIO_Port == GPIO_PORT_C)
    {
        PORTC ^= (1 << GPIO_Pin);
    }
    else if (GPIO_Port == GPIO_PORT_D)
    {
        PORTD ^= (1 << GPIO_Pin);
    }
}
