/*
 * stm32f401xx_gpio_driver.c
 *
 *  Created on: Apr 7, 2024
 *      Author: vinodhini
 */

#include "stm32f401xx_gpio_driver.h"

/*
 * Peripheral Clock Setup
 */

void GPIO_PClkControl(GPIO_RegDef_t *pGPIOx, uint8_t PinState)
{
	if(PinState == ENABLE)
	{
		if(pGPIOx == GPIOA)
		{
			GPIOA_PCLK_EN();
		}
		else if(pGPIOx == GPIOB)
		{
			GPIOB_PCLK_EN();
		}
		else if(pGPIOx == GPIOC)
		{
			GPIOC_PCLK_EN();
		}
		else if(pGPIOx == GPIOD)
		{
			GPIOD_PCLK_EN();
		}
		else if (pGPIOx == GPIOE)
		{
			GPIOE_PCLK_EN();
		}
		else if(pGPIOx == GPIOH)
		{
			GPIOH_PCLK_EN();
		}
	}
	else
	{
		if(pGPIOx == GPIOA)
		{
			GPIOA_PCLK_DI();
		}
		else if(pGPIOx == GPIOB)
		{
			GPIOB_PCLK_DI();
		}
		else if(pGPIOx == GPIOC)
		{
			GPIOC_PCLK_DI();
		}
		else if(pGPIOx == GPIOD)
		{
			GPIOD_PCLK_DI();
		}
		else if (pGPIOx == GPIOE)
		{
			GPIOE_PCLK_DI();
		}
		else if(pGPIOx == GPIOH)
		{
			GPIOH_PCLK_DI();
		}

	}
}

/*
 * GPIO_Init
 */
void GPIO_Init(GPIO_Handle_t *pGPIO_Handle)
{
	uint32_t temp = 0, temp1, temp2; //temp register

	//Configure the PinMode
	if(pGPIO_Handle->GPIO_PinConfig->GPIO_PinMode <= GPIO_MODE_ANALOG)
	{
		//Non-interrupt mode
		temp= ((pGPIO_Handle->GPIO_PinConfig->GPIO_PinMode) << (2 * pGPIO_Handle->GPIO_PinConfig->GPIO_PinNumber));
		pGPIO_Handle->pGPIOx->MODER &= ~(0x03 << (pGPIO_Handle->GPIO_PinConfig->GPIO_PinNumber));
		pGPIO_Handle->pGPIOx->MODER |= temp;

	}
	else
	{
		//Interrupt mode
	}
	temp = 0;

	//Configure the PinSpeed
	temp = ((pGPIO_Handle->GPIO_PinConfig->GPIO_PinSpeed) << (2 * pGPIO_Handle->GPIO_PinConfig->GPIO_PinNumber));
	pGPIO_Handle->pGPIOx->OSPEEDR &= ~(0x03 << (pGPIO_Handle->GPIO_PinConfig->GPIO_PinNumber));
	pGPIO_Handle->pGPIOx->OSPEEDR |= temp;

	temp = 0;

	//Configure the PuPd settings of the Pin
	temp = ((pGPIO_Handle->GPIO_PinConfig->GPIO_PinPuPdControl) << (2 * pGPIO_Handle->GPIO_PinConfig->GPIO_PinNumber));
	pGPIO_Handle->pGPIOx->PUPDR &= ~(0x03 << (pGPIO_Handle->GPIO_PinConfig->GPIO_PinNumber));
	pGPIO_Handle->pGPIOx->PUPDR |= temp;

	temp = 0;

	//Configure the Output type of the Pin
	temp = ((pGPIO_Handle->GPIO_PinConfig->GPIO_PinOPType) << (pGPIO_Handle->GPIO_PinConfig->GPIO_PinNumber));
	pGPIO_Handle->pGPIOx->OTYPER &= ~(0x01 << (pGPIO_Handle->GPIO_PinConfig->GPIO_PinNumber));
	pGPIO_Handle->pGPIOx->OTYPER |= temp;

	temp = 0;

	//Configure the alt funtionality of the Pin
	if(pGPIO_Handle->GPIO_PinConfig->GPIO_PinMode == GPIO_MODE_ALTFN)
	{
		temp1 = pGPIO_Handle->GPIO_PinConfig->GPIO_PinNumber / 8;
		temp2 = pGPIO_Handle->GPIO_PinConfig->GPIO_PinNumber % 8;

		if(temp1 == 0)
		{
			pGPIO_Handle->pGPIOx->AFRL &= ~(0xF << (4 * temp2));
			pGPIO_Handle->pGPIOx->AFRL |= (pGPIO_Handle->GPIO_PinConfig->GPIO_PinAltFunMode << (4*temp2));

		}
		else
		{
			pGPIO_Handle->pGPIOx->AFRH &= ~(0xF << (4 * temp2));
			pGPIO_Handle->pGPIOx->AFRH |= (pGPIO_Handle->GPIO_PinConfig->GPIO_PinAltFunMode << (4*temp2));
		}

	}
}


/*
 * GPIO_DeInit
 */
void GPIO_DeInit(GPIO_RegDef_t *pGPIOx)
{
	if(pGPIOx == GPIOA)
	{
		GPIOA_REG_REST();
	}
	else if(pGPIOx == GPIOB)
	{
		GPIOB_REG_REST();
	}
	else if(pGPIOx == GPIOC)
	{
		GPIOC_REG_REST();
	}
	else if(pGPIOx == GPIOD)
	{
		GPIOD_REG_REST();
	}
	else if (pGPIOx == GPIOE)
	{
		GPIOE_REG_REST();
	}
	else if(pGPIOx == GPIOH)
	{
		GPIOH_REG_REST();
	}
}

/*
 * GPIO_ReadPin
 */
uint8_t GPIO_ReadPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber)
{
	uint8_t value;
	value = (uint8_t)((pGPIOx->IDR >> PinNumber) & 0x00000001);
	return value;
}

/*
 * GPIO_ReadPort
 */
uint16_t GPIO_ReadPort(GPIO_RegDef_t *pGPIOx)
{
	uint16_t value;
	value = (uint16_t)(pGPIOx->IDR);
	return value;
}

/*
 * GPIO_WriteToPin
 */
void GPIO_WriteToPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber, uint8_t Value)
{
	if(Value == GPIO_PIN_SET)
	{
		pGPIOx->ODR |= (1 << PinNumber);
	}
	else if (Value == GPIO_PIN_RESET)
	{
		pGPIOx->ODR &= ~(1 << PinNumber);
	}
}

/*
 * GPIO_WriteToPort
 */
void GPIO_WriteToPort (GPIO_RegDef_t *pGPIOx, uint16_t Value)
{
	pGPIOx->ODR |= Value;
}

/*
 * GPIO_TogglePin
 */
void GPIO_TogglePin (GPIO_RegDef_t *pGPIOx, uint8_t PinNumber)
{
	pGPIOx->ODR ^= (1 << PinNumber);
}

/*
 * GPIO_IRQConfig
 */
void GPIO_IRQConfig (uint8_t IRQNumber, uint8_t IRQPriority, uint8_t IRQState);

/*
 * GPIO_IRQHandler
 */
void GPIO_IRQHandler (uint8_t PinNumber);
