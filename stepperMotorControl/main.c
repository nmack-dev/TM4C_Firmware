#include <stdint.h>
#include "gpioA.h"
#include "sysTick.h"
#include "pll.h"

// FSM State
struct State
{
	uint8_t out;
	uint16_t wait;		// 10ms unit
	uint8_t next;
	uint8_t previous;
};

volatile int8_t cState;
typedef const struct State State_t;

// Stepper Motor Finite State Machine
State_t FSM[4] =
{
	{0x50, 200, 1, 3},
	{0x60, 200, 2, 0},
	{0xA0, 200, 3, 1},
	{0x90, 200, 0, 2},
};

int main(void)
{
	PLL_Init();
	SysTick_Init();
	PortA_Init();
	cState = 0;

	while(1)
	{
		GPIO_PORTA_DATA_R = FSM[cState].out;
		SysTick_Wait10ms(FSM[cState].wait);
		cState = FSM[cState].next;
	}
}
