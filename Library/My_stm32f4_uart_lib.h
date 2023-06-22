#ifndef __MY_STM32F4_UART_LIB_H__
#define __MY_STM32F4_UART_LIB_H__

#include <stdint.h>
#include "My_stm32f4_uart_driver.h"
#include "My_stm32f4_common_driver.h"
#include "My_stm32f4_gpio_driver.h"

void LIB_UART_INIT(GPIO_TypeDef*);
void LIB_UART_ENABLE(UART_TypeDef* UART, int BR_option);
void LIB_UART_DISABLE(UART_TypeDef* UART);
int LIB_UART_READ();
int LIB_UART_WRITE(char ch);

#endif