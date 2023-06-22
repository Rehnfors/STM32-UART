#include "My_stm32f4_gpio_lib.h"
#include "My_stm32f4_uart_lib.h"
#include <stdio.h>

GPIO_InitTypeDef;    GPIO_struct;
UART_TypeDef	     UART_struct;


int main(int argc, char const *argv[])
{
    GPIO_struct.Mode 		= GPIO_MODE_OUTPUT_PP;
	GPIO_struct.Pin  		= GPIO_PIN_5;
	GPIO_struct.Pull		= GPIO_NOPULL;

    __LIB_RCC_GPIOA_CLK_ENABLE();           // Aktivera klockan för GPIOA
	LIB_GPIO_Init(GPIOA, &GPIO_struct);     

	UART2_init(GPIOA);                      // Initiera UART
	UART2_enable(&UART_struct, 1);          // Aktivera UART
	while(1)
    {
        for(int i = 0; i < 900000; i++){}
		LIB_GPIO_TogglePin(GPIOA, GPIO_PIN_5);
    }

    UART2_disable(&UART_struct);             // Avaktivera UART

	return 0;
}