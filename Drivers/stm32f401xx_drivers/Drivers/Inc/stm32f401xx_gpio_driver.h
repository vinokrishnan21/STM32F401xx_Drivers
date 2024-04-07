/*
 * stm32f401xx_gpio_driver.h
 *
 *  Created on: Apr 7, 2024
 *      Author: vinodhini
 */

#ifndef INC_STM32F401XX_GPIO_DRIVER_H_
#define INC_STM32F401XX_GPIO_DRIVER_H_

#include "stm32f401xx.h"

/*
 * GPIO Pin Configuration
 */

typedef struct
{
	uint8_t GPIO_PinNumber;			/*! <possible values from @GPIO_PIN_NUMBERS> */
	uint8_t GPIO_PinMode;			/*! <possible values from @GPIO_PIN_MODES> */
	uint8_t GPIO_PinSpeed;			/*! <possible values from @GPIO_SPEED_CONFIG> */
	uint8_t GPIO_PinPuPdControl;	/*! <possible values from @GPIO_PUPD_CONFIG> */
	uint8_t GPIO_PinOPType;			/*! <possible values from @GPIO_OP_TYPES> */
	uint8_t GPIO_PinAltFunMode;		/*! <possible values from @GPIO_PIN_MODES> */
}GPIO_PinConfig_t;


/*
 * GPIO Handle structure definition
 */

typedef struct
{
	GPIO_RegDef_t *pGPIOx; //Base address of the GPIO port that the pin belongs to
	GPIO_PinConfig_t *GPIO_PinConfig; //Pin Configuration settings
}GPIO_Handle_t;

/*
 * @GPIO_PIN_NUMBERS
 * Possible values for GPIO pin numbers
 */
#define GPIO_PIN_0			0
#define GPIO_PIN_1			1
#define GPIO_PIN_2			2
#define GPIO_PIN_3			3
#define GPIO_PIN_4			4
#define GPIO_PIN_5			5
#define GPIO_PIN_6			6
#define GPIO_PIN_7			7
#define GPIO_PIN_8			8
#define GPIO_PIN_9			9
#define GPIO_PIN_10			10
#define GPIO_PIN_11			11
#define GPIO_PIN_12			12
#define GPIO_PIN_13			13
#define GPIO_PIN_14			14
#define GPIO_PIN_15			15

/*
 * @GPIO_PIN_MODES
 * Possible values for GPIO Pin Modes
 */
#define GPIO_MODE_IN		0
#define GPIO_MODE_OUT		1
#define GPIO_MODE_ALTFN		2
#define GPIO_MODE_ANALOG	3
#define GPIO_MODE_IN_FT		4
#define GPIO_MODE_IN_RT		5
#define GPIO_MODE_IN_RFT	6

/*
 * @GPIO_OP_TYPES
 * Possible values for GPIO Pin Output Modes
 */
#define GPIO_OP_TYPE_PP		0
#define GPIO_OP_TYPE_OD		1

/*
 * @GPIO_SPEED_CONFIG
 * Possible values for GPIO Pin Output Speed
 */
#define GPIO_SPEED_LOW		0
#define GPIO_SPEED_MEDIUM	1
#define GPIO_SPEED_FAST		2
#define GPIO_SPEED_HIGH		3

/*
 * @GPIO_PUPD_CONFIG
 * Possible values for GPIO Pin Push Pull Configuration
 */
#define GPIO_PIN_NOPUPD		0
#define GPIO_PIN_PU			1
#define GPIO_PIN_PD			2

/****************************************************************************************************
 * 							APIs Supported by this driver
 ****************************************************************************************************/


/*
 * @function 	- Peripheral Clock Setup
 * @breif 		-
 *
 * @param[1] 	-
 * @param[2]	-
 * @return		-
 * @note		-
 */

void GPIO_PClkControl(GPIO_RegDef_t *pGPIOx, uint8_t PinState);

/*
 * @function 	- GPIO_Init
 * @breif 		-
 *
 * @param[1] 	-
 * @param[2]	-
 * @return		-
 * @note		-
 */
void GPIO_Init(GPIO_Handle_t *pGPIO_Handle);


/*
 * @function 	- GPIO_DeInit
 * @breif 		-
 *
 * @param[1] 	-
 * @param[2]	-
 * @return		-
 * @note		-
 */
void GPIO_DeInit(GPIO_RegDef_t *pGPIOx);


/*
 * @function 	- GPIO_ReadPin
 * @breif 		-
 *
 * @param[1] 	-
 * @param[2]	-
 * @return		-
 * @note		-
 */
uint8_t GPIO_ReadPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber);


/*
 * @function 	- GPIO_ReadPort
 * @breif 		-
 *
 * @param[1] 	-
 * @param[2]	-
 * @return		-
 * @note		-
 */
uint16_t GPIO_ReadPort(GPIO_RegDef_t *pGPIOx);


/*
 * @function 	- GPIO_WriteToPin
 * @breif 		-
 *
 * @param[1] 	-
 * @param[2]	-
 * @return		-
 * @note		-
 */
void GPIO_WriteToPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber, uint8_t Value);


/*
 * @function 	- GPIO_WriteToPort
 * @breif 		-
 *
 * @param[1] 	-
 * @param[2]	-
 * @return		-
 * @note		-
 */
void GPIO_WriteToPort (GPIO_RegDef_t *pGPIOx, uint16_t Value);


/*
 * @function 	- GPIO_TogglePin
 * @breif 		-
 *
 * @param[1] 	-
 * @param[2]	-
 * @return		-
 * @note		-
 */
void GPIO_TogglePin (GPIO_RegDef_t *pGPIOx, uint8_t PinNumber);


/*
 * @function 	- GPIO_IRQConfig
 * @breif 		-
 *
 * @param[1] 	-
 * @param[2]	-
 * @return		-
 * @note		-
 */
void GPIO_IRQConfig (uint8_t IRQNumber, uint8_t IRQPriority, uint8_t IRQState);


/*
 * @function 	- GPIO_IRQHandler
 * @breif 		-
 *
 * @param[1] 	-
 * @param[2]	-
 * @return		-
 * @note		-
 */
void GPIO_IRQHandler (uint8_t PinNumber);


#endif /* INC_STM32F401XX_GPIO_DRIVER_H_ */
