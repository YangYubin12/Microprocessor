// LED 4개를 연속하여 점멸하도록 프로그래밍 하시오.
#include "main.h"

void Delay_Timer(uint32_t time){
   for(; time > 0; time--){
   }
}
void set_led(uint8_t n){
   switch(n){
   case 1:
      GPIOA->BSRR |= 0x01<<12;
      Delay_Timer(500000);
      GPIOA->BSRR |= 0x01<<28;
      Delay_Timer(500000);
      break;
   case 2:
      GPIOA->BSRR |= 0x01<<11;
      Delay_Timer(500000);
      GPIOA->BSRR |= 0x01<<27;
      Delay_Timer(500000);
      break;
   case 3:
      GPIOB->BSRR |= 0x01<<12;
      Delay_Timer(500000);
      GPIOB->BSRR |= 0x01<<28;
      Delay_Timer(500000);
      break;
   case 4:
      GPIOB->BSRR |= 0x01<<11;
      Delay_Timer(500000);
      GPIOB->BSRR |= 0x01<<27;
      Delay_Timer(500000);
      break;
   }
}

int main(void) {
   RCC->APB2ENR |= (0x1<<2)|(0x1<<3);
   GPIOA->CRH &= ~0x44000;
   GPIOA->CRH |= 0x11000;
   GPIOC->CRH &= ~0x44000;
   GPIOC->CRH |= 0x11000;

   while(1) {
      for(uint8_t i=1;i<5;i++){
         set_led(i);
      }
   }
}
