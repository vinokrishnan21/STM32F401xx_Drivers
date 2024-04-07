/*
 * stm32f401xx.h
 *
 *  Created on: Apr 7, 2024
 *      Author: vinodhini
 */

#ifndef INC_STM32F401XX_H_
#define INC_STM32F401XX_H_

#include <stdint.h>

#define __vo volatile

/*
 * Base addresses of Flash, SRAM & System memory
 */

#define FLASH_BASEADDR				0x08000000U
#define SRAM1_BASEADDR				0x20000000U
#define SRAM2_BASEADDR				0x20001C00U
#define ROM_BASEADDR				0x1FFF0000U
#define SRAM						SRAM1_BASEADDR

/*
 * AHBx & APBx bus peripheral base address
 */

#define PERIPHERAL_BASEADDR			0x40000000U
#define AHB1_BASEADDR				0x40020000U
#define AHB2_BASEADDR				0x50000000U
#define APB1_BASEADDR				PERIPHERAL_BASEADDR
#define APB2_BASEADDR				0x40010000U

/*
 * Base address of the peripherals in AHB1 bus
 */

#define GPIOA_BASEADDR				(AHB1_BASEADDR + 0x0000U)
#define GPIOB_BASEADDR				(AHB1_BASEADDR + 0x0400U)
#define GPIOC_BASEADDR				(AHB1_BASEADDR + 0x0800U)
#define GPIOD_BASEADDR				(AHB1_BASEADDR + 0x0C00U)
#define GPIOE_BASEADDR				(AHB1_BASEADDR + 0x1000U)
#define GPIOH_BASEADDR				(AHB1_BASEADDR + 0x1C00U)
#define RCC_BASEADDR				(AHB1_BASEADDR + 0x3800U)
/*
 * Base address of the peripherals in APB1 bus
 */

#define I2C1_BASEADDR				(APB1_BASEADDR + 0x5400U)
#define I2C2_BASEADDR				(APB1_BASEADDR + 0x5800U)
#define I2C3_BASEADDR				(APB1_BASEADDR + 0x5C00U)

#define SPI2_BASEADDR				(APB1_BASEADDR + 0x3800U)
#define SPI3_BASEADDR				(APB1_BASEADDR + 0x3C00U)

#define TIM2_BASEADDR				(APB1_BASEADDR + 0x0000U)
#define TIM3_BASEADDR				(APB1_BASEADDR + 0x0400U)
#define TIM4_BASEADDR				(APB1_BASEADDR + 0x0800U)
#define TIM5_BASEADDR				(APB1_BASEADDR + 0x0C00U)

#define USART2_BASEADDR				(APB1_BASEADDR + 0x4400U)

/*
 * Base address of the peripherals in APB2 bus
 */

#define ADC1_BASEADDR				(APB2_BASEADDR + 0x2000U)
#define EXTI_BASEADDR				(APB2_BASEADDR + 0x3C00U)

#define SPI1_BASEADDR				(APB2_BASEADDR + 0x3000U)
#define SPI4_BASEADDR				(APB2_BASEADDR + 0x3400U)

#define SYSCFG_BASEADDR				(APB2_BASEADDR + 0x3800U)

#define TIM1_BASEADDR				(APB2_BASEADDR + 0x0000U)
#define TIM9_BASEADDR				(APB2_BASEADDR + 0x4000U)
#define TIM10_BASEADDR				(APB2_BASEADDR + 0x4400U)
#define TIM11_BASEADDR				(APB2_BASEADDR + 0x4800U)

#define USART1_BASEADDR				(APB2_BASEADDR + 0x1000U)
#define USART6_BASEADDR				(APB2_BASEADDR + 0x1400U)


/*
 * GPIO peripheral register structure definition
 * Note : This might be varied for MCUs of different family
 * Please check the reference manual of the MCU
 */

typedef struct
{
	__vo uint32_t MODER;
	__vo uint32_t OTYPER;
	__vo uint32_t OSPEEDR;
	__vo uint32_t PUPDR;
	__vo uint32_t IDR;
	__vo uint32_t ODR;
	__vo uint32_t BSRR;
	__vo uint32_t LCKR;
	__vo uint32_t AFRL;
	__vo uint32_t AFRH;
}GPIO_RegDef_t;

typedef struct
{
	__vo uint32_t CR;
	__vo uint32_t PLLCFGR;
	__vo uint32_t CFGR;
	__vo uint32_t CIR;
	__vo uint32_t AHB1RSTR;
	__vo uint32_t AHB2RSTR;
	uint32_t RESERVED0;
	uint32_t RESERVED1;
	__vo uint32_t APB1RSTR;
	__vo uint32_t APB2RSTR;
	uint32_t RESERVED2;
	uint32_t RESERVED3;
	__vo uint32_t AHB1ENR;
	__vo uint32_t AHB2ENR;
	uint32_t RESERVED4;
	uint32_t RESERVED5;
	__vo uint32_t APB1ENR;
	__vo uint32_t APB2ENR;
	uint32_t RESERVED6;
	uint32_t RESERVED7;
	__vo uint32_t AHB1LPENR;
	__vo uint32_t AHB2LPENR;
	uint32_t RESERVED8;
	uint32_t RESERVED9;
	__vo uint32_t APB1LPENR;
	__vo uint32_t APB2LPENR;
	uint32_t RESERVED10;
	uint32_t RESERVED11;
	__vo uint32_t BDCR;
	__vo uint32_t CSR;
	uint32_t RESERVED12;
	uint32_t RESERVED13;
	__vo uint32_t SSCGR;
	__vo uint32_t PLLI2SCFGR;
	uint32_t RESERVED14;
	uint32_t DCKCFGR;
}RCC_RegDef_t;


/*
 * Peripheral definitions
 */

#define GPIOA ((GPIO_RegDef_t*)GPIOA_BASEADDR)
#define GPIOB ((GPIO_RegDef_t*)GPIOB_BASEADDR)
#define GPIOC ((GPIO_RegDef_t*)GPIOC_BASEADDR)
#define GPIOD ((GPIO_RegDef_t*)GPIOD_BASEADDR)
#define GPIOE ((GPIO_RegDef_t*)GPIOE_BASEADDR)
#define GPIOH ((GPIO_RegDef_t*)GPIOH_BASEADDR)

#define RCC ((RCC_RegDef_t*)RCC_BASEADDR)

/*
 * Clock enable macros for GPIOx Peripherals
 */

#define GPIOA_PCLK_EN()		(RCC->AHB1ENR |= (1<<0))
#define GPIOB_PCLK_EN()		(RCC->AHB1ENR |= (1<<1))
#define GPIOC_PCLK_EN()		(RCC->AHB1ENR |= (1<<2))
#define GPIOD_PCLK_EN()		(RCC->AHB1ENR |= (1<<3))
#define GPIOE_PCLK_EN()		(RCC->AHB1ENR |= (1<<4))
#define GPIOH_PCLK_EN()		(RCC->AHB1ENR |= (1<<7))


/*
 * Clock enable macros for I2Cx Peripherals
 */

#define I2C1_PCLK_EN()		(RCC->APB1ENR |= (1<<21))
#define I2C2_PCLK_EN()		(RCC->APB1ENR |= (1<<22))
#define I2C3_PCLK_EN()		(RCC->APB1ENR |= (1<<23))

/*
 * Clock enable macros for SPIx Peripherals
 */

#define SPI1_PCLK_EN()		(RCC->APB2ENR |= (1<<12))
#define SPI2_PCLK_EN()		(RCC->APB1ENR |= (1<<14))
#define SPI3_PCLK_EN()		(RCC->APB1ENR |= (1<<15))
#define SPI4_PCLK_EN()		(RCC->APB2ENR |= (1<<13))

/*
 * Clock enable macros for USARTx Peripherals
 */

#define USART1_PCLK_EN()	(RCC->APB2ENR |= (1<<4))
#define USART2_PCLK_EN()	(RCC->APB1ENR |= (1<<17))
#define USART6_PCLK_EN()	(RCC->APB2ENR |= (1<<5))

/*
 * Clock enable macros for SYSCFG Peripheral
 */

#define SYSCFG_PCLK_EN()	(RCC->APB2ENR |= (1<<14))


/*
 * Clock disable macros for GPIOx Peripherals
 */

#define GPIOA_PCLK_DI()		(RCC->AHB1ENR &= ~(1<<0))
#define GPIOB_PCLK_DI()		(RCC->AHB1ENR &= ~(1<<1))
#define GPIOC_PCLK_DI()		(RCC->AHB1ENR &= ~(1<<2))
#define GPIOD_PCLK_DI()		(RCC->AHB1ENR &= ~(1<<3))
#define GPIOE_PCLK_DI()		(RCC->AHB1ENR &= ~(1<<4))
#define GPIOH_PCLK_DI()		(RCC->AHB1ENR &= ~(1<<7))


/*
 * Clock disable macros for I2Cx Peripherals
 */

#define I2C1_PCLK_DI()		(RCC->APB1ENR &= ~(1<<21))
#define I2C2_PCLK_DI()		(RCC->APB1ENR &= ~(1<<22))
#define I2C3_PCLK_DI()		(RCC->APB1ENR &= ~(1<<23))

/*
 * Clock disable macros for SPIx Peripherals
 */

#define SPI1_PCLK_DI()		(RCC->APB2ENR &= ~(1<<12))
#define SPI2_PCLK_DI()		(RCC->APB1ENR &= ~(1<<14))
#define SPI3_PCLK_DI()		(RCC->APB1ENR &= ~(1<<15))
#define SPI4_PCLK_DI()		(RCC->APB2ENR &= ~(1<<13))

/*
 * Clock disable macros for USARTx Peripherals
 */

#define USART1_PCLK_DI()	(RCC->APB2ENR &= ~(1<<4))
#define USART2_PCLK_DI()	(RCC->APB1ENR &= ~(1<<17))
#define USART6_PCLK_DI()	(RCC->APB2ENR &= ~(1<<5))

/*
 * Clock disable macros for SYSCFG Peripheral
 */

#define SYSCFG_PCLK_DI()	(RCC->APB2ENR &= ~(1<<14))


/*
 * Rest Macros for GPIO Ports
 */
#define GPIOA_REG_REST()	do{(RCC->AHB1RSTR |= (1 << 0)); (RCC->AHB1RSTR &= ~(1 << 0));} while(0)
#define GPIOB_REG_REST()	do{(RCC->AHB1RSTR |= (1 << 1)); (RCC->AHB1RSTR &= ~(1 << 1));} while(0)
#define GPIOC_REG_REST()	do{(RCC->AHB1RSTR |= (1 << 2)); (RCC->AHB1RSTR &= ~(1 << 2));} while(0)
#define GPIOD_REG_REST()	do{(RCC->AHB1RSTR |= (1 << 3)); (RCC->AHB1RSTR &= ~(1 << 3));} while(0)
#define GPIOE_REG_REST()	do{(RCC->AHB1RSTR |= (1 << 4)); (RCC->AHB1RSTR &= ~(1 << 4));} while(0)
#define GPIOH_REG_REST()	do{(RCC->AHB1RSTR |= (1 << 7)); (RCC->AHB1RSTR &= ~(1 << 7));} while(0)

/*
 * Generic Macros
 */

#define ENABLE				1
#define DISABLE				0
#define SET					ENABLE
#define RESET				DISABLE
#define GPIO_PIN_SET		SET
#define GPIO_PIN_RESET		RESET


#endif /* INC_STM32F401XX_H_ */
