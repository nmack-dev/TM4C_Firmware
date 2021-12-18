#include "gpioF.h"
#include "sysTick.h"

#define CORRECT 308000
#define TOLERANCE 160

unsigned long Led;
long Errors;

void delayms(unsigned long ms);

// A basic function to delay a program based on millisecond input
void delayms(unsigned long ms)
{
	unsigned long count = (308 * ms);

	while (count > 0)
	{
		count--;
	}
}

// An example blinky program performing functional debugging with
int main(void)
{
    unsigned long Now;
    unsigned long Last;
    unsigned long Elapsed;

	PortF_Init();
	SysTick_Init();

	Errors = -1;				// Counts timing errors
	Last = NVIC_ST_CURRENT_R;

	while(1)
	{
		Led = GPIO_PORTF_DATA_R;
		Led = Led ^ 0x02;
		GPIO_PORTF_DATA_R = Led;

		Now = NVIC_ST_CURRENT_R;
		Elapsed = (Last - Now) & 0x00FFFFFF;	// Calculates time elapsed

		if ((Elapsed < (CORRECT - TOLERANCE)) || (Elapsed > (CORRECT + TOLERANCE)))
		{
			Errors++;
		}

		Last = Now;
		delayms(100);
	}
}
