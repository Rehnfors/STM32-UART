#include "My_stm32f4_uart_lib.h"

void LIB_UART_Init(UART_ComType *Com, UART_BaudRateType *Baud)
{
RCC->APB1ENR |= 0x20000;
RCC->AHB1ENR |= 0x01;

GPIOA->MODER &= ~0x00F0;
GPIOA->MODER |= 0x00A0;

GPIOA->AFR[0] &= ~0xFF00;
GPIOA->AFR[0] |= 0x7700;

UART2->BRR = 0x0683;
UART2->CR1 = 0x000C;
UART2->CR2 = 0x000;
UART2->CR3 = 0x000;
UART2->CR1 |= 0x2000;
}

int LIB_UART_Read()
{

}

int LIB_UART_Write(char ch)
{

}