#include <avr/io.h>
#include <avr/interrupt.h>
#define F_CPU 1000000UL // 1MHz
#include <util/delay.h>
#include "atmega328p_gpio_driver.h"

ISR(INT0_vect)
{
  GPIO_WritePin(GPIO_PORT_B, GPIO_PIN_4, GPIO_PIN_SET);
}

ISR(INT1_vect)
{
  GPIO_WritePin(GPIO_PORT_B, GPIO_PIN_4, GPIO_PIN_RESET);
}

static void GPIO_Init(void);
static void ISR_Init(void);

int main(void)
{
  GPIO_Init();
  ISR_Init();

  while (1)
  {
    GPIO_TogglePin(GPIO_PORT_B, GPIO_PIN_5);
    _delay_ms(1000);
  }
  return 0;
}

static void GPIO_Init(void)
{
  GPIO_SetMode(GPIO_PORT_D, GPIO_PIN_2, GPIO_MODE_INPUT);
  GPIO_SetMode(GPIO_PORT_D, GPIO_PIN_3, GPIO_MODE_INPUT);
  GPIO_WritePin(GPIO_PORT_D, GPIO_PIN_2, GPIO_PIN_SET);
  GPIO_WritePin(GPIO_PORT_D, GPIO_PIN_3, GPIO_PIN_SET);

  GPIO_SetMode(GPIO_PORT_B, GPIO_PIN_4, GPIO_MODE_OUTPUT);
  GPIO_SetMode(GPIO_PORT_B, GPIO_PIN_5, GPIO_MODE_OUTPUT);
}

static void ISR_Init(void)
{
  // Config Interrupt on INT1 and INT0 pins
  EICRA |= (1 << ISC11) | (1 << ISC01) | (1 << ISC10) | (1 << ISC00); // Mode: rising edge
  sei();                                                              // Enable interrupts by setting the global interrupt mask
  EIMSK |= (1 << INT0) | (1 << INT1);                                 // Enable External Interrupt Request 1 & 0
}
