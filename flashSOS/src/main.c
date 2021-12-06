#include <stdint.h>
#include"gpio.h"

unsigned long SW1;
unsigned long SW2;

void delay(uint32_t halfsecs);
void FlashSOS(uint8_t color);

void delay(uint32_t halfsecs)
{
    volatile uint32_t count;
    
    while(halfsecs > 0)
    {
        count = 1538460;
        
        while (count > 0)
        {
            count--;
        }

        halfsecs--;
    }
}

void FlashSOS(uint8_t color)
{
    // S
    GPIO_PORTF_DATA_R |= color;     delay(1);
    GPIO_PORTF_DATA_R &= ~color;    delay(1);
    GPIO_PORTF_DATA_R |= color;     delay(1);
    GPIO_PORTF_DATA_R &= ~color;    delay(1);        
    GPIO_PORTF_DATA_R |= color;     delay(1);
    GPIO_PORTF_DATA_R &= ~color;    delay(1);

    // O
    GPIO_PORTF_DATA_R |= color;     delay(4);
    GPIO_PORTF_DATA_R &= ~color;    delay(4);
    GPIO_PORTF_DATA_R |= color;     delay(4);
    GPIO_PORTF_DATA_R &= ~color;    delay(4);        
    GPIO_PORTF_DATA_R |= color;     delay(4);
    GPIO_PORTF_DATA_R &= ~color;    delay(4);

    // S
    GPIO_PORTF_DATA_R |= color;     delay(1);
    GPIO_PORTF_DATA_R &= ~color;    delay(1);
    GPIO_PORTF_DATA_R |= color;     delay(1);
    GPIO_PORTF_DATA_R &= ~color;    delay(1);        
    GPIO_PORTF_DATA_R |= color;     delay(1);
    GPIO_PORTF_DATA_R &= ~color;    delay(1);
}

int main(void)
{
   PortF_Init();

   while (1)
   {
       FlashSOS(0x04);
   }
}
