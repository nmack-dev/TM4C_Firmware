#include "sysTick.h"

void SysTick_Init(void)
{
    NVIC_ST_CTRL_R = 0;             // disable SysTick during setup
    NVIC_ST_CTRL_R = 0x00000005;    // enable SysTick with core clock
}

void SysTick_Wait(uint32_t delay)
{
    NVIC_ST_RELOAD_R = delay - 1;               // number of counts to wait
    NVIC_ST_CURRENT_R  = 0;                        // resets current value
    while ((NVIC_ST_CTRL_R  & 0x00010000) == 0) {} // wait for count flag
}

void SysTick_Wait10ms(uint32_t delay)
{
    uint32_t i;
    for (i = 0; i < delay; i++)
    {
        SysTick_Wait(800000);   // wait 10ms
    }
}
