#include "gpioA.h"

void PortA_Init(void)
{
    volatile unsigned long delay;

    SYSCTL_RCGC2_R |= 0x01;             // Activate Port A clock
    delay = SYSCTL_RCGC2_R;

    GPIO_PORTA_PCTL_R &= ~0x00000F00;    // Regular GPIO initialization
    GPIO_PORTA_AMSEL_R &= ~0x0C;        // Disable analog
    GPIO_PORTA_DIR_R |= 0x0C;           // Set direction to output
    GPIO_PORTA_AFSEL_R &= ~0x0C;         // Regular port function
    GPIO_PORTA_DEN_R |= 0x0C;           // Enable digital
}
