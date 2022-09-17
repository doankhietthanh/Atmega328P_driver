// LED sao băng
#include "main.h"
#define LED0 &PORTB, PINB0
#define LED1 &PORTB, PINB1
#define LED2 &PORTB, PINB2
#define LED3 &PORTB, PINB3
#define LED4 &PORTB, PINB4
#define LED5 &PORTB, PINB5
#define LED6 &PORTB, PINB6
#define LED7 &PORTB, PINB7

#define LED_ON 1
#define LED_OFF 0

static void GPIO_Init(void);
static void TIMER1_Init(void);

int brightnessMax = 30;
int count = 0;
unsigned char data_LED[8] = {1, 3, 6, 9, 13, 17, 25, 30};
unsigned char LED[8];

ISR(TIMER1_OVF_vect)
{
    if (LED[0] > count)
        GPIO_WritePin(LED0, LED_ON);
    else
        GPIO_WritePin(LED0, LED_OFF);

    if (LED[1] > count)
        GPIO_WritePin(LED1, LED_ON);
    else
        GPIO_WritePin(LED1, LED_OFF);

    if (LED[2] > count)
        GPIO_WritePin(LED2, LED_ON);
    else
        GPIO_WritePin(LED2, LED_OFF);

    if (LED[3] > count)
        GPIO_WritePin(LED3, LED_ON);
    else
        GPIO_WritePin(LED3, LED_OFF);

    if (LED[4] > count)
        GPIO_WritePin(LED4, LED_ON);
    else
        GPIO_WritePin(LED4, LED_OFF);

    if (LED[5] > count)
        GPIO_WritePin(LED5, LED_ON);
    else
        GPIO_WritePin(LED5, LED_OFF);

    if (LED[6] > count)
        GPIO_WritePin(LED6, LED_ON);
    else
        GPIO_WritePin(LED6, LED_OFF);

    if (LED[7] > count)
        GPIO_WritePin(LED7, LED_ON);
    else
        GPIO_WritePin(LED7, LED_OFF);

    count++;
    if (count > brightnessMax)
        count = 0;

    TCNT1 = 53036;
}

int main()
{
    GPIO_Init();
    TIMER1_Init();

    while (1)
    {
        for (int k = 7; k > -12; k--) //-12 la khoang cach giua cac tia sao bang, cang lon khoang cach cang xa
        {
            for (int i = 7; i > 0; i--)
                LED[i] = LED[i - 1]; // dich array LED sang phai >> 1 lan
            if (k >= 0)
                LED[0] = data_LED[k]; // lay do sang trong data_LED ghi vao LED[0]
            else
                LED[0] = 0; // tat led 0
            _delay_ms(100);
        }
    }

    return 0;
}

static void GPIO_Init(void)
{
    DDRB = 0xFF;
}

static void TIMER1_Init(void)
{
    cli();

    TCCR1A = 0;
    TCCR1B = 0;
    TIMSK1 = 0;
    TCCR1B |= (1 << CS11); // prescale = 8
    TCNT1 = 53036;
    TIMSK1 = (1 << TOIE1); // Overflow interrupt enable

    sei();
}
