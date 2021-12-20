#include <stdint.h>

#define NVIC_ST_CTRL_R      (*((volatile uint32_t *)0xE000E010))
#define NVIC_ST_RELOAD_R    (*((volatile uint32_t *)0xE000E014))
#define NVIC_ST_CURRENT_R   (*((volatile uint32_t *)0xE000E018))

void SysTick_Init();
void SysTick_Wait(uint32_t delay);
void SysTick_Wait10ms(uint32_t delay);
