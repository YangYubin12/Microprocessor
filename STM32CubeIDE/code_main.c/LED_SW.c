// 내장 버튼으로 LED를 제어할 수 있도록 프로그래밍 하시오.
#include "main.h"

int main(void) {
   RCC->APB2ENR |= (0x1<<2)|(0x1<<4);
   GPIOA->CRL &= ~(1<<22); // ~(0x1<<22);
   GPIOA->CRL |= (1<<20); // (0x1<<20); output select
   GPIOC->CRH &= ~(1<<22); // ~(0x1<<22);
   GPIOC->CRH |= (1<<23); // (0x1<<23); input select
   GPIOC->ODR |= (1<<13); // (0x1<<13);

   while(1) {
      if(GPIOC->IDR & 0x00002000){
         GPIOA->BSRR |= (0x1<<21); //0x00200000; //LED reset
      } else {
         GPIOA->BSRR |= (0x1<<5); //0x00000020; //LED set
      }
   }
}
