#include <avr/io.h>
#include <avr/interrupt.h>
#define F_CPU 1000000UL // 1MHz
#include <util/delay.h>
#include <atmega328p_gpio_driver.h>

volatile uint8_t portbhistory = 0xFF;
ISR(PCINT2_vect)
{
  uint8_t changedbits;
  changedbits = PIND ^ portbhistory;
  portbhistory = PIND;

  if (changedbits & _BV(5))
  {
    GPIO_WritePin(GPIO_PORT_B, GPIO_PIN_4, GPIO_PIN_SET);
  }
  if (changedbits & _BV(6))
  {
    GPIO_WritePin(GPIO_PORT_B, GPIO_PIN_4, GPIO_PIN_RESET);
  }
}

static void GPIO_Init(void);

int main(void)
{
  GPIO_Init();

  // Config Interrupt on INT1 and INT0 pins
  PCICR |= (1 << PCIE2);                     // Pin Change Interrupt Enable 2
  sei();                                     // Enable interrupts by setting the global interrupt mask
  PCMSK2 |= (1 << PCINT22) | (1 << PCINT21); // Pin Change Enable Mask 21 & 22

  while (1)
  {
    GPIO_TogglePin(GPIO_PORT_B, GPIO_PIN_5);
    _delay_ms(1000);
  }
  return 0;
}

static void GPIO_Init(void)
{
  GPIO_SetMode(GPIO_PORT_D, GPIO_PIN_5, GPIO_MODE_INPUT);
  GPIO_SetMode(GPIO_PORT_D, GPIO_PIN_6, GPIO_MODE_INPUT);

  GPIO_SetMode(GPIO_PORT_B, GPIO_PIN_4, GPIO_MODE_OUTPUT);
  GPIO_SetMode(GPIO_PORT_B, GPIO_PIN_5, GPIO_MODE_OUTPUT);
}
