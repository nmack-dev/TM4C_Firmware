#define NVIC_ST_CTRL_R      (*((volatile unsigned long *)0xE000E010))
#define NVIC_ST_RELOAD_R    (*((volatile unsigned long *)0xE000E014))
#define NVIC_ST_CURRENT_R   (*((volatile unsigned long *)0xE000E018))

extern unsigned long Now;       // Time at call
extern unsigned long Last;      // Time at previous call
extern unsigned long Elapsed;   // Time between calls

void SysTick_Init(void);
void Action(void);
