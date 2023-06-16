#ifndef	__MY_STM32F4_GPIO_DRIVER_H__
#define __MY_STM32F4_GPIO_DRIVER_H__
#include <stdint.h>

#include "My_stm32f4_common_driver.h"

#define		GPIOA_BASE				(AHB1PERIPH_BASE + 0x00U)
#define		GPIOB_BASE				(AHB1PERIPH_BASE + 0x0400U)
#define		GPIOC_BASE				(AHB1PERIPH_BASE + 0x0800U)
#define		GPIOD_BASE				(AHB1PERIPH_BASE + 0x0C00U)
#define		GPIOE_BASE				(AHB1PERIPH_BASE + 0x1000U)
#define		GPIOH_BASE				(AHB1PERIPH_BASE + 0x1C00U)



#define		__IO			volatile
	
typedef struct
{
	__IO	uint32_t MODER;
	__IO	uint32_t OTYPER;
	__IO	uint32_t OSPEEDR;
	__IO  	uint32_t PUPDR;
	__IO  	uint32_t IDR;
	__IO  	uint32_t ODR;
	__IO	uint32_t BSRR;
	__IO	uint32_t LCKR;
	__IO	uint32_t AFR[2];
	
}GPIO_TypeDef;

#define		GPIOA		((GPIO_TypeDef *)GPIOA_BASE)
#define		GPIOB		((GPIO_TypeDef *)GPIOB_BASE)
#define		GPIOC		((GPIO_TypeDef *)GPIOC_BASE)
#define		GPIOD		((GPIO_TypeDef *)GPIOD_BASE)
#define		GPIOE		((GPIO_TypeDef *)GPIOE_BASE)
#define		GPIOH		((GPIO_TypeDef *)GPIOH_BASE)

#define 	GPIOA_EN			1<<0
#define		GPIOB_EN			1<<1
#define		GPIOC_EN			1<<2
#define		GPIOD_EN			1<<3
#define		GPIOE_EN			1<<4
#define		GPIOH_EN			1<<7


#define		MODER_5_OUT		1<<10
#define		LED_PIN				1<<5
#endif
