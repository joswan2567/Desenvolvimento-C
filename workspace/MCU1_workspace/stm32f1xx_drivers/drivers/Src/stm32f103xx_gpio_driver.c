/*
 * stm32f103xx_gpio_driver.c
 *
 *  Created on: Jan 10, 2022
 *      Author: José Wanderson
 */
#include "stm32f103xx_gpio_driver.h"

/*********************************************************************
 * @fn      		  - GPIO_PeriClockControl
 *
 * @brief             - This function enables or disables peripheral clock for the given GPIO port
 *
 * @param[in]         - base address of the gpio peripheral
 * @param[in]         - ENABLE or DISABLE macros
 *
 * @return            - none
 *
 * @Note              - none
 */
void GPIO_PeriClockControl(GPIO_RegDef_t *pGPIOx, uint8_t EnOrDi){
	if(EnOrDi){
		if      (pGPIOx == GPIOA) GPIOA_PCLK_EN();
		else if (pGPIOx == GPIOB) GPIOB_PCLK_EN();
		else if (pGPIOx == GPIOC) GPIOC_PCLK_EN();
		else if (pGPIOx == GPIOD) GPIOD_PCLK_EN();
		else if (pGPIOx == GPIOE) GPIOE_PCLK_EN();
		else if (pGPIOx == GPIOF) GPIOF_PCLK_EN();
		else if (pGPIOx == GPIOG) GPIOG_PCLK_EN();

		return;
	}

	if      (pGPIOx == GPIOA) GPIOA_PCLK_DI();
	else if (pGPIOx == GPIOB) GPIOB_PCLK_DI();
	else if (pGPIOx == GPIOC) GPIOC_PCLK_DI();
	else if (pGPIOx == GPIOD) GPIOD_PCLK_DI();
	else if (pGPIOx == GPIOE) GPIOE_PCLK_DI();
	else if (pGPIOx == GPIOF) GPIOF_PCLK_DI();
	else if (pGPIOx == GPIOG) GPIOG_PCLK_DI();
}

/*********************************************************************
 * @fn      		  - GPIO_Init
 *
 * @brief             - This function enables or disables peripheral clock for the given GPIO pin
 *
 * @param[in]         - base address of the gpio peripheral
 *
 * @return            - none
 *
 * @Note              - none
 */
void GPIO_Init(GPIO_Handle_t *pGPIOHandle){
	uint32_t temp = 0;

	uint8_t aux1, aux2;
	aux1 = pGPIOHandle->GPIO_PinCfg.GPIO_PinNumber / 8;
	aux2 = pGPIOHandle->GPIO_PinCfg.GPIO_PinNumber % 8;

	if(pGPIOHandle->GPIO_PinCfg.GPIO_PinMode <= GPIO_MODE_ANALOG)
		pGPIOHandle->pGPIOx->CR[pGPIOHandle->GPIO_PinCfg.GPIO_PinNumber / 8] &= ~(0x03 << pGPIOHandle->GPIO_PinCfg.GPIO_PinNumber);
	else{}

	if(pGPIOHandle->GPIO_PinCfg.GPIO_PinMode == GPIO_MODE_OUT){
		switch(pGPIOHandle->GPIO_PinCfg.GPIO_PinSpeed){
			case GPIO_SPEED_LOW:
				pGPIOHandle->pGPIOx->CR[aux1] &= (0xF << (4 * aux2 ));
				pGPIOHandle->pGPIOx->CR[aux1] |= (0x02 << pGPIOHandle->GPIO_PinCfg.GPIO_PinNumber);
				break;
			case GPIO_SPEED_MEDIUM:
				pGPIOHandle->pGPIOx->CR[aux1] &= (0xF << (4 * aux2 ));
				pGPIOHandle->pGPIOx->CR[aux1] |= (0x01 << pGPIOHandle->GPIO_PinCfg.GPIO_PinNumber);
				break;
			case GPIO_SPEED_FAST:
				pGPIOHandle->pGPIOx->CR[aux1] &= (0xF << (4 * aux2 ));
				pGPIOHandle->pGPIOx->CR[aux1] |= (0x03 << pGPIOHandle->GPIO_PinCfg.GPIO_PinNumber);
				break;
		}
		switch(pGPIOHandle->GPIO_PinCfg.GPIO_PinPuPdControl){
			case GPIO_OP_TYPE_PP:
				if(pGPIOHandle->GPIO_PinCfg.GPIO_PinMode == GPIO_MODE_ALTFN)
					pGPIOHandle->pGPIOx->CR[aux1] |= (0x08 << pGPIOHandle->GPIO_PinCfg.GPIO_PinNumber);
				else
					pGPIOHandle->pGPIOx->CR[aux1] |= (0x02 << pGPIOHandle->GPIO_PinCfg.GPIO_PinNumber);
				break;
			case GPIO_OP_TYPE_OD:
				if(pGPIOHandle->GPIO_PinCfg.GPIO_PinMode == GPIO_MODE_ALTFN)
					pGPIOHandle->pGPIOx->CR[aux1] |= (0x0C << pGPIOHandle->GPIO_PinCfg.GPIO_PinNumber);
				else
					pGPIOHandle->pGPIOx->CR[aux1] |= (0x04 << pGPIOHandle->GPIO_PinCfg.GPIO_PinNumber);
				break;
		}
	}
	/*else if(pGPIOHandle->GPIO_PinCfg.GPIO_PinMode == GPIO_MODE_IN){
		switch(pGPIOHandle->GPIO_PinCfg.GPIO_Pin){
			case GPIO_SPEED_LOW:
				pGPIOHandle->pGPIOx->CR[aux1] &= (0xF << (4 * aux2 ));
				pGPIOHandle->pGPIOx->CR[aux1] |= (0x02 << pGPIOHandle->GPIO_PinCfg.GPIO_PinNumber);
				break;
			case GPIO_SPEED_MEDIUM:
				pGPIOHandle->pGPIOx->CR[aux1] &= (0xF << (4 * aux2 ));
				pGPIOHandle->pGPIOx->CR[aux1] |= (0x01 << pGPIOHandle->GPIO_PinCfg.GPIO_PinNumber);
				break;
			case GPIO_SPEED_FAST:
				pGPIOHandle->pGPIOx->CR[aux1] &= (0xF << (4 * aux2 ));
				pGPIOHandle->pGPIOx->CR[aux1] |= (0x03 << pGPIOHandle->GPIO_PinCfg.GPIO_PinNumber);
				break;
			}
	}*/

}
void GPIO_DeInit(GPIO_RegDef_t *pGPIOx){
	if      (pGPIOx == GPIOA) GPIOA_REG_RESET();
	else if (pGPIOx == GPIOB) GPIOB_REG_RESET();
	else if (pGPIOx == GPIOC) GPIOC_REG_RESET();
	else if (pGPIOx == GPIOD) GPIOD_REG_RESET();
	else if (pGPIOx == GPIOE) GPIOE_REG_RESET();
	else if (pGPIOx == GPIOF) GPIOF_REG_RESET();
	else if (pGPIOx == GPIOG) GPIOG_REG_RESET();
}

/*
 * Data read and write
 */
uint8_t GPIO_ReadFromInputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber){

}
uint16_t GPIO_ReadFromInputPort(GPIO_RegDef_t *pGPIOx){

}
void GPIO_WriteToOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber, uint8_t Value){

}
void GPIO_WriteToOutputPort(GPIO_RegDef_t *pGPIOx, uint8_t Value){

}
void GPIO_ToggleOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber){

}

/*
 * IRQ configuration and ISR handling
 */
void GPIO_IRQCfg(uint8_t IRQNumber, uint8_t IRQPriority, uint8_t EnOrDi){

}
void GPIO_IRQHandling(uint8_t PinNumber){

}

