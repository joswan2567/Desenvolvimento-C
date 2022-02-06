/*
 * stm32f103xx_i2c_driver.h
 *
 *  Created on: Jan 31, 2022
 *      Author: José Wanderson
 */

#ifndef INC_STM32F103XX_I2C_DRIVER_H_
#define INC_STM32F103XX_I2C_DRIVER_H_

#include "stm32f103xx.h"

/*
 * This is a Configuration Structure for a I2Cx peripheral
 */
typedef struct{
	uint32_t I2C_SCLSpeed;             /*!<possible speed for SCL > */
	uint8_t I2C_DeviceAddr;           /*!<(if device mode slave) device addr >*/
	uint8_t I2C_ACKControl;			  /*!<Control ACK>*/
	uint8_t I2C_FMDutyCycle;		  /*!<TODO: >*/

}I2C_Cfg_t;

/*
 * This is a Handle Structure for a I2Cx peripheral
 */
typedef struct{
	I2C_RegDef_t *pI2Cx;
	I2C_Cfg_t	 I2C_Cfg;
	uint8_t		 *pTXBuf;			  /*!< To store the app. TX buf addr > */
	uint8_t		 *pRXBuf;			  /*!< To store the app. RX buf addr > */
	uint32_t	 TXLen;				  /*!< To store TX len > */
	uint32_t	 RXLen;				  /*!< To store RX len > */
	uint8_t		 TXRXState;			  /*!< To store Communication state > */ // Communication Half-Duplex
	uint8_t		 DevAddr;			  /*!< To store slave/device address > */
	uint32_t	 RXSize;			  /*!< To store RX size > */
	uint8_t		 Sr;				  /*!< To store repeated start value > */

}I2C_Handle_t;

/*
 * @I2C_SCLSpeed
 */
#define I2C_SCL_SPEED_SM		100000
#define I2C_SCL_SPEED_FM4K		400000
#define I2C_SCL_SPEED_FM2K		200000

/*
 * @I2C_ACKControl
 */
#define I2C_ACK_EN				1
#define I2C_ACK_DI				0

/*
 * @I2C_FMDutyCycle
 */
#define I2C_FM_DUTY_2			0
#define I2C_FM_DUTY_16_9		1

/*
 * I2C related status flags definitions
 */
#define I2C_FLAG_TXE		(1 << I2C_SR1_TXE)
#define I2C_FLAG_RXNE		(1 << I2C_SR1_RXNE)
#define I2C_FLAG_SB			(1 << I2C_SR1_SB)
#define I2C_FLAG_OVR  		( 1 << I2C_SR1_OVR)
#define I2C_FLAG_AF   		( 1 << I2C_SR1_AF)
#define I2C_FLAG_ARLO 		( 1 << I2C_SR1_ARLO)
#define I2C_FLAG_BERR 		( 1 << I2C_SR1_BERR)
#define I2C_FLAG_STOPF 		( 1 << I2C_SR1_STOPF)
#define I2C_FLAG_ADD10 		( 1 << I2C_SR1_ADD10)
#define I2C_FLAG_BTF  		( 1 << I2C_SR1_BTF)
#define I2C_FLAG_ADDR 		( 1 << I2C_SR1_ADDR)
#define I2C_FLAG_TIMEOUT 	( 1 << I2C_SR1_TIMEOUT)

#define I2C_DISABLE_SR  	RESET
#define I2C_ENABLE_SR   	SET

/*
 * I2C app states
 */
#define I2C_READY				0
#define I2C_BSY_IN_RX			1
#define I2C_BSY_IN_TX			2

/*
 * I2C application events macros
 */
#define I2C_EV_TX_CMPLT  	 	0
#define I2C_EV_RX_CMPLT  	 	1
#define I2C_EV_STOP       		2
#define I2C_ERROR_BERR 	 		3
#define I2C_ERROR_ARLO  		4
#define I2C_ERROR_AF    		5
#define I2C_ERROR_OVR   		6
#define I2C_ERROR_TIMEOUT 		7
#define I2C_EV_DATA_REQ         8
#define I2C_EV_DATA_RCV         9
/*****************************************************************
 *				 APIs supported by this driver                   *
 *  For more info. about the APIs check the function definition  *
 *****************************************************************/

/*
 * Peripheral Clock Setup
 */
void I2C_PeriClockControl(I2C_RegDef_t *pI2Cx, uint8_t EnOrDi);

/*
 * Init and DeInit
 */
void I2C_Init(I2C_Handle_t *pI2CHandle);
void I2C_DeInit(I2C_RegDef_t *pI2Cx);

/*
 * Data send and receive
 */
void I2C_MasterSendData(I2C_Handle_t *pI2CHandle, uint8_t *pTxBuffer, uint8_t Size, uint8_t SlaveAddr);
void I2C_MasterReadData(I2C_Handle_t *pI2CHandle, uint8_t *pRxBuffer, uint8_t Size, uint8_t SlaveAddr);

uint8_t I2C_MasterSendDataIT(I2C_Handle_t *pI2CHandle, uint8_t *pTxBuffer, uint32_t Size, uint8_t SlaveAddr, uint8_t Sr);
uint8_t I2C_MasterReadDataIT(I2C_Handle_t *pI2CHandle, uint8_t *pRxBuffer, uint8_t Size, uint8_t SlaveAddr);

/*
 * IRQ configuration and ISR handling
 */
void I2C_IRQITCfg(uint8_t IRQNumber, uint8_t EnOrDi);
void I2C_IRQPriorityCfg(uint8_t IRQNumber, uint8_t IRQPriority);
void I2C_EV_IRQHandling(I2C_Handle_t *pI2CHandle);
void I2C_ER_IRQHandling(I2C_Handle_t *pI2CHandle);

/*
 * Other Peripheral Control API's
 */
void I2C_PeripheralControl(I2C_RegDef_t *pI2Cx, uint8_t EnOrDi);
uint8_t I2C_GetFlagStatus(I2C_RegDef_t *pI2Cx, uint32_t FlagName);

/*
 * Application Callback
 */
void I2C_AppEventCallback(I2C_Handle_t *pI2CHandle, uint8_t AppEv);

#endif /* INC_STM32F103XX_I2C_DRIVER_H_ */
