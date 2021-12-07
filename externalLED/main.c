#include <stdint.h>
#include "gpioA.h"

void delay(uint32_t halfsecs);

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

int main(void)
{
    PortA_Init();

	while(1)
	{
	    GPIO_PORTA_DATA_R |= 0x04;
	    GPIO_PORTA_DATA_R |= 0x08;
	    delay(1);
	    GPIO_PORTA_DATA_R &= ~0x04;
	    delay(1);
	    GPIO_PORTA_DATA_R &= ~0x08;
	    delay(1);

	}
}
