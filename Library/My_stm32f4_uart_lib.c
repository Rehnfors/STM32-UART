#include "My_stm32f4_uart_lib.h"

void LIB_UART_INIT(GPIO_TypeDef* pin)
{
    RCC->APB1ENR |= 0x20000; // Aktivera klocka för USART2.
    RCC->AHB1ENR |= 0x01;    // Aktivera klocka för GPIO port A.

    GPIOA->MODER &= ~0x00F0; // Resettar pin 3, 4. Dvs bit 4, 5, 6, 7
    GPIOA->MODER |= 0x00A0;  // Aktiverar alternativa funktionen för pin 3, 4.

    GPIOA->AFR[0] &= ~0xFF00;// Rensar bitarna 8-15
    GPIOA->AFR[0] |= 0x7700; // Aktiverar alternativa funktionen för pin 7 och 6.
}

void LIB_UART_ENABLE(UART_TypeDef* UART, int BR_option)
{   
    if(BR_option == 1)
        UART2->BRR = 0x0683; // BR 9600.
    else if(BR_option == 2)
        UART2->BRR = 0x08B;  // BR 115200.

    UART2->CR1 &= ~0xFFFF;    // Rensar registret
    UART2->CR1 |= 0x000C;     // Transmitter enable, reciever enable.

    UART2->CR2 &= ~0xFFFF;
    UART2->CR2 |= 0x2000;     // Sätter bit 13 till 1, dvs en stop bit.

    UART2->CR3 &= ~0xFFFF;
    UART2->CR3 |= 0x0008;     // Aktiverar half-duplex. (mest bara för att visa).

    UART2->CR1 |= 0x2000;     // UART2 Enable.
}

void LIB_UART_DISABLE(UART_TypeDef* UART)
{
    UART2->CR1 &= ~0x2000;
}

int LIB_UART_READ()
{
    while(!(UART2->SR & 0x0020)){} // Kör så länge inte Recieved data is ready to be read.
	return UART2->DR;              // returnera sedan dataregistret.
}

int LIB_UART_WRITE(char ch)
{
    while(!(UART2->SR & 0x0080)){} // Kör så länge transmit data register inte är tomt.
	UART2->DR = (ch & 0xFF);       // Sätter 1 på det som stämmer överens med ch,
                                   // bitwise AND för att säkerställa att det endast blir 8 bitar, som registret.
	
     return ch; //returnera ch
}