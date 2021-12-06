
//main.c
//Toggles the Red LED of TM4C Launchpad when SW1(PF4) is pushed and held
//PF4 is negative logic,i.e 0 is on and non-zero is off
#include"gpio.h"

unsigned long Led;

void Delay(void) { unsigned long volatile time;
  time = 800000;
  while(time) {
		time--;
  }
}

int main(void) {
  PortF_Init();
  while(1){
   
    Led = 0x02;                 // reverse value of LED
    GPIO_PORTF_DATA_R = Led;    // write value to PORTF DATA register,toggle led
    Delay();

    Led = 0x04;                 // reverse value of LED
    GPIO_PORTF_DATA_R = Led;    // write value to PORTF DATA register,toggle led
    Delay();

    Led = 0x08;                 // reverse value of LED
    GPIO_PORTF_DATA_R = Led;    // write value to PORTF DATA register,toggle led
    Delay();
  }
}

