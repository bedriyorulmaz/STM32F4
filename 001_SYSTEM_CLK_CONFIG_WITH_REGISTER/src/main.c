/*
******************************************************************************
File:     main.c
Info:     Generated by Atollic TrueSTUDIO(R) 9.3.0   2020-10-18

The MIT License (MIT)
Copyright (c) 2019 STMicroelectronics

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

******************************************************************************
*/

/* Includes */
#include "stm32f4xx.h"
#include "stm32f4_discovery.h"

void CLK_Config()
{
	RCC->CR |= 0x00030000;//hseon ve hseonrdy enable
	while(!(RCC->CR & 0x00020000));//hseon ready flag
	RCC->CR |= 0x00080000;//css enable
	RCC->PLLCFGR |= 0x00400000;//pll e hse se�tik
	RCC->PLLCFGR |= 0x00000004;//PLL M =4
	RCC->PLLCFGR |= 0x00005A00;//PLL N=168
	RCC->PLLCFGR |= 0x00000000;//PLL P=2
	RCC->CFGR |= 	0x00000000;//AHB Prescaler =1
	RCC->CFGR |= 	0x00080000;//ApB2 Prescaler =2
	RCC->CFGR |= 	0x00001400;//ApB1 Prescaler =4
	RCC->CIR |= 	0x00080000;//hserdy fLAG CLEAR
	RCC->CIR |= 	0x00800000;//css fLAG CLEAR
	RCC->AHB1RSTR |=0x00000008;//GPIOD PORT RESET

	GPIOD->MODER = 0x55000000;
	GPIOD->OTYPER= 0x00000000;
	GPIOD->OSPEEDR=0xFF000000;
	GPIOD->PUPDR=  0x00000000;
}
void delay(uint32_t time){
	while(time--);
}
int main(void)
{
	CLK_Config();
  while (1)
  {GPIOD->ODR = 0x0000F000;
  delay(16800000);
  GPIOD->ODR = 0x00000000;
  delay(16800000);

  }
}


/*
 * Callback used by stm32f4_discovery_audio_codec.c.
 * Refer to stm32f4_discovery_audio_codec.h for more info.
 */
void EVAL_AUDIO_TransferComplete_CallBack(uint32_t pBuffer, uint32_t Size){
  /* TODO, implement your code here */
  return;
}

/*
 * Callback used by stm324xg_eval_audio_codec.c.
 * Refer to stm324xg_eval_audio_codec.h for more info.
 */
uint16_t EVAL_AUDIO_GetSampleCallBack(void){
  /* TODO, implement your code here */
  return -1;
}
