#ifndef __MY_STM32F4_UART_LIB_H__
#define __MY_STM32F4_UART_LIB_H__

#include <stdint.h>
#include "My_stm32f4_uart_driver.h"
#include "My_stm32f4_common_driver.h"
#include "My_stm32f4_gpio_driver.h"

typedef enum
{

}UART_ComType;

typedef enum
{

}UART_BaudRateType;


int LIB_UART_WRITE(char ch);
int LIB_UART_READ();
void LIB_UART_INIT(UART_ComType *Com, UART_BaudRateType *Baud);

#endif