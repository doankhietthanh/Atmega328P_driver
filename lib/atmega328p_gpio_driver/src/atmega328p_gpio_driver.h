/*
 * atmega328p_gpio_driver.h
 *
 * Created: 8/12/2022 10:48:34 PM
 *  Author: doank
 */

#ifndef ATMEGA328P_GPIO_DRIVER_H_
#define ATMEGA328P_GPIO_DRIVER_H_

#include <avr/io.h>

typedef enum
{
    GPIO_MODE_INPUT = 0,
    GPIO_MODE_OUTPUT = 1,
} GPIO_InitMode;

// typedef enum
// {
//     GPIO_PORT_B = PORTB,
//     GPIO_PORT_C = PORTC,
//     GPIO_PORT_D = PORTD
// } GPIO_PortType;

#define GPIO_PORT_B PORTB
#define GPIO_PORT_C PORTC
#define GPIO_PORT_D PORTD

typedef enum
{
    GPIO_PIN_RESET = 0,
    GPIO_PIN_SET = 1,
} GPIO_PinState;

#define GPIO_PIN_0 0
#define GPIO_PIN_1 1
#define GPIO_PIN_2 2
#define GPIO_PIN_3 3
#define GPIO_PIN_4 4
#define GPIO_PIN_5 5
#define GPIO_PIN_6 6
#define GPIO_PIN_7 7

void GPIO_SetMode(volatile uint8_t *GPIO_Port, uint8_t GPIO_Pin, GPIO_InitMode GPIO_Mode);
uint8_t GPIO_ReadPort(volatile uint8_t *GPIO_Port);
uint8_t GPIO_ReadPin(volatile uint8_t *GPIO_Port, uint8_t GPIO_Pin);
void GPIO_WritePin(volatile uint8_t *GPIO_Port, uint8_t GPIO_Pin, GPIO_PinState Pin_State);
void GPIO_TogglePin(volatile uint8_t *GPIO_Port, uint8_t GPIO_Pin);

#endif /* ATMEGA328P_GPIO_DRIVER_H_ */