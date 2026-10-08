#include "stm32f401xc.h"
#include<stdint.h>


void usart_init(void);
void gpio_init(void);
void usart_SendChar(char s);


int main(void)
{
	
	usart_init();
	gpio_init();
	
	while(1)
	{
	 if(GPIOA->IDR & (1<<0))
	 {
		 usart_SendChar('A');
	 }
	 
	 if(GPIOA->IDR & (1<<1))
	 {
		 usart_SendChar('B');
	 }
	 
	 if(GPIOA->IDR & (1<<2))
	 {
		 usart_SendChar('C');
	 }
	 
	 if(GPIOA->IDR & (1<<3))
	 {
		 usart_SendChar('D');
	 }
	 
	 if(GPIOA->IDR & (1<<4))
	 {
		 usart_SendChar('E');
	 }
	 
	 if(GPIOA->IDR & (1<<5))
	 {
		 usart_SendChar('F');
	 }
	 
	 if(GPIOA->IDR & (1<<6))
	 {
		 usart_SendChar('G');
	 }
	 
	 if(GPIOA->IDR & (1<<7))
	 {
		 usart_SendChar('H');
	 }
	 
	 if(GPIOA->IDR & (1<<8))
	 {
		 usart_SendChar('M');
	 }
	 
	 else
	 {
		 usart_SendChar('!');
	 }
 }
}

void usart_init(void)
{
    RCC->AHB1ENR |= (1U << 0);

    GPIOA->MODER &= ~(0x0003FFFFU);

    GPIOA->PUPDR &= ~(0x0003FFFFU);
    GPIOA->PUPDR |=  0x0002AAAAU;
}


void gpio_init(void)
{
    RCC->APB2ENR |= (1U << 4);

    GPIOA->MODER &= ~(3U << (9U * 2U));
    GPIOA->MODER |=  (2U << (9U * 2U));

    USART1->BRR = 0x008BU;

    GPIOA->AFR[1] &= ~(0xFU << 4U);
    GPIOA->AFR[1] |=  (0x7U << 4U);

    USART1->CR1 = (1U << 3) | (1U << 13);
}


void usart_SendChar(char s)
{
    while (!(USART1->SR & (1U << 7)))
    {
    }

    USART1->DR = s;
}