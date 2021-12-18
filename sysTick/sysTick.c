#include "sysTick.h"

void SysTick_Init(void)
{
    NVIC_ST_CTRL_R = 0;             // Disable SysTick during setup
    NVIC_ST_RELOAD_R = 0x00FFFFFF;  // Max reload value
    NVIC_ST_CURRENT_R = 0;          // Any write to current value clears it
    NVIC_ST_CTRL_R = 0x00000005;    // Enable SysTick with core clock
}

void Action(void)
{
    Now = NVIC_ST_CURRENT_R;
    Elapsed = (Last - Now) & 0x00FFFFFF;
    Last = Now;
}
