//LED 4개 연속 점등
//#include "main.h"
//void Delay_Timer(uint32_t time) {
//   for(; time>0; time--) {
//   }
//}
//
//void set_led(uint32_t n){
//   switch(n) {
//   case 1:
//      GPIOA->BSRR |= (0x1<<12);
//      break;
//   case 2:
//      GPIOA->BSRR |= (0x1<<11);
//      break;
//   case 3:
//      GPIOB->BSRR |= (0x1<<12);
//      break;
//   case 4:
//      GPIOB->BSRR |= (0x1<<11);
//      break;
//   }
//}
//
//void reset_led(uint8_t n) {
//   GPIOA->BSRR |= (0x1<<27) | (0x1<<28);
//   GPIOB->BSRR |= (0x1<<27) | (0x1<<28);
//}
//
//int main(void) {
//   RCC->APB2ENR |= (0x1<<2)|(0x1<<3);
//
//   GPIOA->CRH &= ~(0x44000);
//   GPIOA->CRH |= (0x11000);
//   GPIOB->CRH &= ~(0x44000);
//   GPIOB->CRH |= (0x11000);
//   while(1) {
//      for(uint8_t i=1; i<5; i++) {
//         set_led(i);
//         Delay_Timer(50000);
//         reset_led(i);
//         Delay_Timer(50000);
//      }
//   }
//}

// 버튼을 누른 횟수에 따라 해당 LED가 ON/OFF 하도록 프로그래밍.
// 버튼을 1번 누르면 PA12의 LED가 ON/OFF.
// 4번 누르면 PB11의 LED가 ON/OFF.
// 5번 누르면 PB12의 LED가 ON/OFF.
// 단, LED가 ON되고 일정시간 이후 자동 OFF/
// 출력핀: PA12, PA11, PB12, PB11
// 입력핀: PC8
// 풀업
#include "main.h"
void delay_out(uint32_t a){
   for(;a>0;a--){

   }
}
void set_led(uint8_t n){
   switch(n){
      case 1:
         GPIOA->BSRR |= (0x1<<12);
         break;
      case 2:
         GPIOA->BSRR |= (0x1<<11);
         break;
      case 3:
         GPIOB->BSRR |= (0x1<<12);
         break;
      case 4:
         GPIOB->BSRR |= (0x1<<11);
         break;
   }
}
void reset_led(){
   GPIOA->BSRR |= (0x1<<28)|(0x1<<27);
   GPIOB->BSRR |= (0x1<<28)|(0x1<<27);
}
int main(){
   uint32_t cnt=1;
   RCC->APB2ENR |=(0x1<<4)|(0x1<<2)|(0x1<<3);
   GPIOC->CRH &=~(0x1<<2);
   GPIOC->CRH |=(0x1<<3);
   GPIOC->ODR |= (0x1<<8);
   GPIOA->CRH &= ~((0x1<<14)|(0x1<<18));
   GPIOA->CRH |= (0x1<<12)|(0x1<<16);
   GPIOB->CRH &= ~((0x1<<14)|(0x1<<18));
   GPIOB->CRH |= (0x1<<12)|(0x1<<16);
   while(1){
      if(!(GPIOC->IDR & 0x00000100)){
         if(cnt==5){
            cnt=1;
         }
         reset_led();
         set_led(cnt);
         cnt++;
         delay_out(100000);
         reset_led();
         delay_out(100000);
      }
      return 0;
   }
//   선생님 방법
//   while(1){
//      if(GPIOC->IDR & (0x1<<8)){
//         reset_led();
//   } else{
//      set_led(i);
//      Daley_Timer(200000);
//      reset_led();
//      Delay_Timer(200000);
//      i++;
//      if(i == 5){
//         i = 1;
//      }
//   }
   }
