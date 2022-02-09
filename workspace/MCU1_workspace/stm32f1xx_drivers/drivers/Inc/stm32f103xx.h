/*
 * stm32f103xx.h
 *
 *  Created on: Jan 9, 2022
 *      Author: José Wanderson
 */

#ifndef INC_STM32F103XX_H_
#define INC_STM32F103XX_H_

#include <stdint.h>

#define __vo 			volatile
#define __weak 			__attribute__((weak))

/******** Start Processor Specific Details **************
 *   													*
 *   ARM Cortex Mx Processor NVIC ISERx register addr	*
 *   													*
 ******************************************************/
#define NVIC_ISER0               ((__vo uint32_t*)0xE000E100)
#define NVIC_ISER1               ((__vo uint32_t*)0xE000E104)
#define NVIC_ISER2               ((__vo uint32_t*)0xE000E108)
#define NVIC_ISER3               ((__vo uint32_t*)0xE000E10C)

/*
 *   ARM Cortex Mx Processor NVIC ICERx register addr
 */
#define NVIC_ICER0               ((__vo uint32_t*)0XE000E180)
#define NVIC_ICER1               ((__vo uint32_t*)0XE000E184)
#define NVIC_ICER2               ((__vo uint32_t*)0XE000E188)
#define NVIC_ICER3               ((__vo uint32_t*)0xE000E18C)

/*
 *   ARM Cortex Mx Processor Priority Register Addr Calculation
 */
#define NVIC_PR_BASE_ADDR        ((__vo uint32_t*)0xE000E400)

/*
 *   ARM Cortex Mx Processor Number of priority bits implemented in Priority Register
 */
#define NO_PR_BITS_IMPLEMENTED   4

/*
 *  base addr of FLASH and SRAM  memories
 */
#define FLASH_BASE_ADDR           0x08000000U     /*base address flash bluepill*/
#define SRAM1_BASE_ADDR           0x20000000U     /*base address sram bluepill*/
#define ROM_BASE_ADDR             0x1FFFF000U     /*base address system memory bluepill*/
#define SRAM                      SRAM1_BASE_ADDR

/*
 * AHBx and APBX Bus Peripheral base addr
 */
#define PERIPH_BASE_ADDR          0x40000000U
#define APB1_PERIPH_BASE_ADDR     PERIPH_BASE_ADDR
#define APB2_PERIPH_BASE_ADDR     0x40010000U
#define AHB1_PERIPH_BASE_ADDR     0x40018000U

/*
 * Base addr of peripherals which are hanging on AHB1 bus
 * TODO : Complete for all other peripherals
 */
#define RCC_BASE_ADDR             0x40021000U

#define USB_OTG_FS_BASE_ADDR      0x50000000U

#define CRC_BASE_ADDR             0x40023000U

#define DMA1_BASE_ADDR            0x40020000U
#define DMA2_BASE_ADDR            0x40020400U

#define SDIO_BASE_ADDR            AHB1_PERIPH_BASE_ADDR

/*
 * Base addr of peripherals which are hanging on APB1 bus
 * TODO : Complete for all other peripherals
 */
#define DAC_BASE_ADDR        (APB1_PERIPH_BASE_ADDR + 0x7400)

#define BKP_BASE_ADDR        (APB1_PERIPH_BASE_ADDR + 0x6C00)

#define CAN1_BASE_ADDR       (APB1_PERIPH_BASE_ADDR + 0x6400)
#define CAN2_BASE_ADDR       (APB1_PERIPH_BASE_ADDR + 0x6800)

#define IWDG_BASE_ADDR       (APB1_PERIPH_BASE_ADDR + 0x3000)

#define I2C1_BASE_ADDR       (APB1_PERIPH_BASE_ADDR + 0x5400)
#define I2C2_BASE_ADDR       (APB1_PERIPH_BASE_ADDR + 0x5800)

#define PWR_BASE_ADDR        (APB1_PERIPH_BASE_ADDR + 0x7000)

#define RTC_BASE_ADDR        (APB1_PERIPH_BASE_ADDR + 0x2800)

#define SPI2_BASE_ADDR       (APB1_PERIPH_BASE_ADDR + 0x3800)
#define SPI3_BASE_ADDR       (APB1_PERIPH_BASE_ADDR + 0x3C00)

#define TIMER2_BASE_ADDR     (APB1_PERIPH_BASE_ADDR + 0x0000)
#define TIMER3_BASE_ADDR     (APB1_PERIPH_BASE_ADDR + 0x0400)
#define TIMER4_BASE_ADDR     (APB1_PERIPH_BASE_ADDR + 0x0800)
#define TIMER5_BASE_ADDR     (APB1_PERIPH_BASE_ADDR + 0x0C00)
#define TIMER6_BASE_ADDR     (APB1_PERIPH_BASE_ADDR + 0x1000)
#define TIMER7_BASE_ADDR     (APB1_PERIPH_BASE_ADDR + 0x1400)
#define TIMER12_BASE_ADDR    (APB1_PERIPH_BASE_ADDR + 0x1800)
#define TIMER13_BASE_ADDR    (APB1_PERIPH_BASE_ADDR + 0x1C00)
#define TIMER14_BASE_ADDR    (APB1_PERIPH_BASE_ADDR + 0x2000)

#define USART2_BASE_ADDR     (APB1_PERIPH_BASE_ADDR + 0x4400)
#define USART3_BASE_ADDR     (APB1_PERIPH_BASE_ADDR + 0x4800)
#define UART4_BASE_ADDR      (APB1_PERIPH_BASE_ADDR + 0x4C00)
#define UART5_BASE_ADDR      (APB1_PERIPH_BASE_ADDR + 0x5000)

#define WWDG_BASE_ADDR       (APB1_PERIPH_BASE_ADDR + 0x2C00)

/*
 * Base addr of peripherals which are hanging on APB2 bus
 * TODO : Complete for all other peripherals
 */
#define ADC1_BASE_ADDR       (APB2_PERIPH_BASE_ADDR + 0x2400)
#define ADC2_BASE_ADDR       (APB2_PERIPH_BASE_ADDR + 0x2800)
#define ADC3_BASE_ADDR       (APB2_PERIPH_BASE_ADDR + 0x3C00)

#define AFIO_BASE_ADDR       (APB2_PERIPH_BASE_ADDR + 0x0000)

#define EXTI_BASE_ADDR       (APB2_PERIPH_BASE_ADDR + 0x0400)

#define GPIOA_BASE_ADDR      (APB2_PERIPH_BASE_ADDR + 0x0800)
#define GPIOB_BASE_ADDR      (APB2_PERIPH_BASE_ADDR + 0x0C00)
#define GPIOC_BASE_ADDR      (APB2_PERIPH_BASE_ADDR + 0x1000)
#define GPIOD_BASE_ADDR      (APB2_PERIPH_BASE_ADDR + 0x1400)
#define GPIOE_BASE_ADDR      (APB2_PERIPH_BASE_ADDR + 0x1800)
#define GPIOF_BASE_ADDR      (APB2_PERIPH_BASE_ADDR + 0x1C00)
#define GPIOG_BASE_ADDR      (APB2_PERIPH_BASE_ADDR + 0x2000)

#define SPI1_BASE_ADDR       (APB2_PERIPH_BASE_ADDR + 0x3000)

#define TIMER1_BASE_ADDR     (APB2_PERIPH_BASE_ADDR + 0x2C00)
#define TIMER8_BASE_ADDR     (APB2_PERIPH_BASE_ADDR + 0x3400)
#define TIMER9_BASE_ADDR     (APB2_PERIPH_BASE_ADDR + 0x4C00)
#define TIMER10_BASE_ADDR    (APB2_PERIPH_BASE_ADDR + 0x5000)
#define TIMER11_BASE_ADDR    (APB2_PERIPH_BASE_ADDR + 0x5400)

#define USART1_BASE_ADDR     (APB2_PERIPH_BASE_ADDR + 0x3800)


/******* Peripheral Register Definition Structures *********/

/*
 * Note : Registers of a peripheral are specific to MCU
 */

/*
 * peripheral register definition structure for GPIOx
 */
typedef struct{
	__vo uint32_t CR[2];                          /*!< Port configuration register low [0] and high [1],       Addr offset: 0x00  */
	__vo uint32_t IDR;                          /*!< Port input data register,              Addr offset: 0x08  */
	__vo uint32_t ODR;                          /*!< Port output data register,             Addr offset: 0x0C  */
	__vo uint32_t BSRR;                         /*!< Port bit set/reset register,           Addr offset: 0x10  */
	__vo uint32_t BRR;                          /*!< Port bit reset register,               Addr offset: 0x14  */
	__vo uint32_t LCKR;                         /*!< Port configuration lock register,      Addr offset: 0x18  */

}GPIO_RegDef_t;

/*
 * peripheral register definition structure for RCC
 */
typedef struct{
	__vo uint32_t CR;                           /*!< Clock control register,                Addr offset: 0x00  */
	__vo uint32_t CFGR;                         /*!< Clock configuration register,          Addr offset: 0x04  */
	__vo uint32_t CIR;                          /*!< Clock interrupt register,              Addr offset: 0x08  */
	__vo uint32_t APB2RSTR;                     /*!< APB2 peripheral reset register,        Addr offset: 0x0C  */
	__vo uint32_t APB1RSTR;                     /*!< APB1 peripheral reset register,        Addr offset: 0x10  */
	__vo uint32_t AHBENR;                       /*!< AHB peripheral clock enable register,  Addr offset: 0x14  */
	__vo uint32_t APB2ENR;                      /*!< APB2 peripheral clock enable register, Addr offset: 0x18  */
	__vo uint32_t APB1ENR;                      /*!< APB1 peripheral clock enable register, Addr offset: 0x1C  */
	__vo uint32_t BDCR;                         /*!< Backup domain control register,        Addr offset: 0x20  */
	__vo uint32_t CSR;                          /*!< Control/status register,               Addr offset: 0x24  */

}RCC_RegDef_t;

/*
 * peripheral register definition structure for EXTI
 */
typedef struct{
	__vo uint32_t IMR;                          /*!< Interrupt mask register,               Addr offset: 0x00  */
	__vo uint32_t EMR;                          /*!< Event mask register,                   Addr offset: 0x04  */
	__vo uint32_t RTSR;                         /*!< Rising trigger selection register,     Addr offset: 0x08  */
	__vo uint32_t FTSR;                         /*!< Falling trigger selection register,    Addr offset: 0x0C  */
	__vo uint32_t SWIER;                        /*!< Software interrupt event register,     Addr offset: 0x10  */
	__vo uint32_t PR;                           /*!< Pending register,                      Addr offset: 0x14  */

}EXTI_RegDef_t;

/*
 * peripheral register definition structure for AFIO
 */
typedef struct{
	__vo uint32_t EVCR;                          /*!< Event control register ,               			 Addr offset: 0x00  */
	__vo uint32_t MAPR;                          /*!< AF remap and debug I/O configuration register,     Addr offset: 0x04  */
	__vo uint32_t EXTICR[4];                     /*!< External interrupt configuration register,		 Addr offset: 0x08  */
	__vo uint32_t MAPR2;                         /*!< AF remap and debug I/O configuration register2,    Addr offset: 0x1C  */

}AFIO_RegDef_t;

/*
 * peripheral register definition structure for SPIx
 */
typedef struct{
	__vo uint32_t CR1;                           /*!< SPI control register ,               			     Addr offset: 0x00  */
	__vo uint32_t CR2;                           /*!< SPI control register ,               			     Addr offset: 0x04  */
	__vo uint32_t SR;                            /*!< status register,                                   Addr offset: 0x08  */
	__vo uint32_t DR;                     		 /*!< data register,									 Addr offset: 0x0C  */
	__vo uint32_t CRCPR;                         /*!< polynomial register   							 Addr offset: 0x10  */
	__vo uint32_t RXCRCR;						 /*!< CRC register			   							 Addr offset: 0x14  */
	__vo uint32_t TXCRCR;						 /*!< CRC register			   							 Addr offset: 0x18  */
	__vo uint32_t I2SCFGR;						 /*!< I2S configuration register			   			 Addr offset: 0x1C  */
	__vo uint32_t I2SPR;						 /*!< I2S prescaler register			   			 	 Addr offset: 0x20  */

}SPI_RegDef_t;

/*
 * peripheral register definition structure for I2Cx
 */
typedef struct{
	__vo uint32_t CR1;                           /*!< Control register 1,               			     Addr offset: 0x00  */
	__vo uint32_t CR2;                           /*!< Control register 2,               			     Addr offset: 0x04  */
	__vo uint32_t OAR1;                          /*!< Own address register 1,                            Addr offset: 0x08  */
	__vo uint32_t OAR2;                          /*!< Own address register 2,                            Addr offset: 0x0C  */
	__vo uint32_t DR;                     		 /*!< Data register,									 Addr offset: 0x10  */
	__vo uint32_t SR1;                         	 /*!< Status register 1,	   							 Addr offset: 0x14  */
	__vo uint32_t SR2;                         	 /*!< Status register 2,	   							 Addr offset: 0x18  */
	__vo uint32_t CCR;						 	 /*!< Clock control register    						 Addr offset: 0x1C  */
	__vo uint32_t TRISE;						 /*!< TRISE register			   						 Addr offset: 0x20  */

}I2C_RegDef_t;

/*
 * peripheral register definition structure for USARTx
 */
typedef struct{
	__vo uint32_t SR;                           /*!< Status register,               			     Addr offset: 0x00  */
	__vo uint32_t DR;                           /*!< Data register,               			     	 Addr offset: 0x04  */
	__vo uint32_t BRR;                          /*!< Baud rate register,                             Addr offset: 0x08  */
	__vo uint32_t CR1;                          /*!< Control register 1,                             Addr offset: 0x0C  */
	__vo uint32_t CR2;                     		/*!< Control register 2,							 Addr offset: 0x10  */
	__vo uint32_t CR3;                         	/*!< Control register 3,	   						 Addr offset: 0x14  */
	__vo uint32_t GTPR;                         /*!< Guard time and prescaler register,	   		     Addr offset: 0x18  */

}USART_RegDef_t;

/*
 * Peripheral definitions ( Peripheral base addresses typecasted to xxx_RegDef_t )
 */
#define GPIOA              ((GPIO_RegDef_t*) GPIOA_BASE_ADDR)
#define GPIOB              ((GPIO_RegDef_t*) GPIOB_BASE_ADDR)
#define GPIOC              ((GPIO_RegDef_t*) GPIOC_BASE_ADDR)
#define GPIOD              ((GPIO_RegDef_t*) GPIOD_BASE_ADDR)
#define GPIOE              ((GPIO_RegDef_t*) GPIOE_BASE_ADDR)
#define GPIOF              ((GPIO_RegDef_t*) GPIOF_BASE_ADDR)
#define GPIOG              ((GPIO_RegDef_t*) GPIOG_BASE_ADDR)

#define RCC                ((RCC_RegDef_t*) RCC_BASE_ADDR)

#define EXTI			   ((EXTI_RegDef_t*) EXTI_BASE_ADDR)

#define AFIO			   ((AFIO_RegDef_t*) AFIO_BASE_ADDR)

#define SPI1			   ((SPI_RegDef_t*) SPI1_BASE_ADDR)
#define SPI2			   ((SPI_RegDef_t*) SPI2_BASE_ADDR)
#define SPI3			   ((SPI_RegDef_t*) SPI3_BASE_ADDR)

#define I2C1			   ((I2C_RegDef_t*) I2C1_BASE_ADDR)
#define I2C2			   ((I2C_RegDef_t*) I2C2_BASE_ADDR)

#define USART1			   ((USART_RegDef_t*) USART1_BASE_ADDR)
#define USART2			   ((USART_RegDef_t*) USART2_BASE_ADDR)
#define USART3			   ((USART_RegDef_t*) USART3_BASE_ADDR)
#define UART4			   ((USART_RegDef_t*) UART4_BASE_ADDR)
#define UART5			   ((USART_RegDef_t*) UART5_BASE_ADDR)

/*
 * Clock Enable Macros for GPIOx peripherals
 */
#define GPIOA_PCLK_EN()            ( RCC->APB2ENR |= ( 1 << 2 ) )             /*!<  GPIO port A clock enabled */
#define GPIOB_PCLK_EN()            ( RCC->APB2ENR |= ( 1 << 3 ) )             /*!<  GPIO port B clock enabled */
#define GPIOC_PCLK_EN()            ( RCC->APB2ENR |= ( 1 << 4 ) )             /*!<  GPIO port C clock enabled */
#define GPIOD_PCLK_EN()            ( RCC->APB2ENR |= ( 1 << 5 ) )             /*!<  GPIO port D clock enabled */
#define GPIOE_PCLK_EN()            ( RCC->APB2ENR |= ( 1 << 6 ) )             /*!<  GPIO port E clock enabled */
#define GPIOF_PCLK_EN()            ( RCC->APB2ENR |= ( 1 << 7 ) )             /*!<  GPIO port F clock enabled */
#define GPIOG_PCLK_EN()            ( RCC->APB2ENR |= ( 1 << 8 ) )             /*!<  GPIO port G clock enabled */

/*
 * returns port code for given GPIOx base addr
 */
#define GPIO_BASE_ADDR_TO_CODE(x)      ((x == GPIOA) ? 0 :\
										(x == GPIOB) ? 1 :\
										(x == GPIOC) ? 2 :\
										(x == GPIOD) ? 3 :\
										(x == GPIOE) ? 4 :\
										(x == GPIOF) ? 5 :\
										(x == GPIOG) ? 6 : -1)
/*
 * Clock Disable Macros for GPIOx Peripherals
 */
#define GPIOA_PCLK_DI()            ( RCC->APB2ENR &= ~( 1 << 2 ) )             /*!<  GPIO port A clock disabled */
#define GPIOB_PCLK_DI()            ( RCC->APB2ENR &= ~( 1 << 3 ) )             /*!<  GPIO port B clock disabled */
#define GPIOC_PCLK_DI()            ( RCC->APB2ENR &= ~( 1 << 4 ) )             /*!<  GPIO port C clock disabled */
#define GPIOD_PCLK_DI()            ( RCC->APB2ENR &= ~( 1 << 5 ) )             /*!<  GPIO port D clock disabled */
#define GPIOE_PCLK_DI()            ( RCC->APB2ENR &= ~( 1 << 6 ) )             /*!<  GPIO port E clock disabled */
#define GPIOF_PCLK_DI()            ( RCC->APB2ENR &= ~( 1 << 7 ) )             /*!<  GPIO port F clock disabled */
#define GPIOG_PCLK_DI()            ( RCC->APB2ENR &= ~( 1 << 8 ) )             /*!<  GPIO port G clock disabled */

/*
 *  Macros to reset GPIOx peripherals
 */
#define GPIOA_REG_RESET()			do{ (RCC->APB2RSTR |= (1 << 2)); (RCC->APB2RSTR &= ~(1 << 2)); }while(0)
#define GPIOB_REG_RESET()           do{ (RCC->APB2RSTR |= (1 << 3)); (RCC->APB2RSTR &= ~(1 << 3)); }while(0)
#define GPIOC_REG_RESET()           do{ (RCC->APB2RSTR |= (1 << 4)); (RCC->APB2RSTR &= ~(1 << 4)); }while(0)
#define GPIOD_REG_RESET()           do{ (RCC->APB2RSTR |= (1 << 5)); (RCC->APB2RSTR &= ~(1 << 5)); }while(0)
#define GPIOE_REG_RESET()           do{ (RCC->APB2RSTR |= (1 << 6)); (RCC->APB2RSTR &= ~(1 << 6)); }while(0)
#define GPIOF_REG_RESET()           do{ (RCC->APB2RSTR |= (1 << 7)); (RCC->APB2RSTR &= ~(1 << 7)); }while(0)
#define GPIOG_REG_RESET()           do{ (RCC->APB2RSTR |= (1 << 8)); (RCC->APB2RSTR &= ~(1 << 8)); }while(0)

/*
 * Clock Enable Macros for I2Cx peripherals
 */
#define I2C1_PCLK_EN()             ( RCC->APB1ENR |= ( 1 << 21 ) )             /*!<  I2C1 clock enabled */
#define I2C2_PCLK_EN()             ( RCC->APB1ENR |= ( 1 << 22 ) )             /*!<  I2C2 clock enabled */

/*
 * Clock Disable Macros for I2Cx peripherals
 */
#define I2C1_PCLK_DI()             ( RCC->APB1ENR &= ~( 1 << 21 ) )            /*!<  I2C1 clock disabled */
#define I2C2_PCLK_DI()             ( RCC->APB1ENR &= ~( 1 << 22 ) )            /*!<  I2C2 clock disabled */

/*
 *  Macros to reset I2Cx peripherals
 */
#define I2C1_REG_RESET()			do{ (RCC->APB1RSTR |= (1 << 21)); (RCC->APB1RSTR &= ~(1 << 21)); }while(0)
#define I2C2_REG_RESET()            do{ (RCC->APB1RSTR |= (1 << 22)); (RCC->APB1RSTR &= ~(1 << 22)); }while(0)

/*
 * Clock Enable Macros for SPIx peripherals
 */
#define SPI1_PCLK_EN()             ( RCC->APB2ENR |= ( 1 << 12 ) )             /*!<  SPI1 clock enabled */
#define SPI2_PCLK_EN()             ( RCC->APB1ENR |= ( 1 << 14 ) )             /*!<  SPI2 clock enabled */
#define SPI3_PCLK_EN()             ( RCC->APB1ENR |= ( 1 << 15 ) )             /*!<  SPI3 clock enabled */

/*
 * Clock Disable Macros for SPIx peripherals
 */
#define SPI1_PCLK_DI()             ( RCC->APB2ENR &= ~( 1 << 12 ) )            /*!<  SPI1 clock disabled */
#define SPI2_PCLK_DI()             ( RCC->APB1ENR &= ~( 1 << 14 ) )            /*!<  SPI2 clock disabled */
#define SPI3_PCLK_DI()             ( RCC->APB1ENR &= ~( 1 << 15 ) )            /*!<  SPI3 clock disabled */

/*
 *  Macros to reset SPIx peripherals
 */
#define SPI1_REG_RESET()		   do{ (RCC->APB2RSTR |= (1 << 12)); (RCC->APB2RSTR &= ~(1 << 12)); }while(0)
#define SPI2_REG_RESET()           do{ (RCC->APB1RSTR |= (1 << 14)); (RCC->APB1RSTR &= ~(1 << 14)); }while(0)
#define SPI3_REG_RESET()           do{ (RCC->APB1RSTR |= (1 << 15)); (RCC->APB1RSTR &= ~(1 << 15)); }while(0)

/*
 * Clock Enable Macros for USARTx peripherals
 */
#define USART1_PCLK_EN()           ( RCC->APB2ENR |= ( 1 << 14 ) )             /*!<  USART1 clock enabled */
#define USART2_PCLK_EN()           ( RCC->APB1ENR |= ( 1 << 17 ) )             /*!<  USART2 clock enabled */
#define USART3_PCLK_EN()           ( RCC->APB1ENR |= ( 1 << 18 ) )             /*!<  USART3 clock enabled */
#define UART4_PCLK_EN()            ( RCC->APB1ENR |= ( 1 << 19 ) )             /*!<  UART4 clock enabled */
#define UART5_PCLK_EN()            ( RCC->APB1ENR |= ( 1 << 20 ) )             /*!<  UART5 clock enabled */

/*
 * Clock Disable Macros for USARTx peripherals
 */
#define USART1_PCLK_DI()           ( RCC->APB2ENR &= ~( 1 << 14 ) )             /*!<  USART1 clock disabled */
#define USART2_PCLK_DI()           ( RCC->APB1ENR &= ~( 1 << 17 ) )             /*!<  USART2 clock disabled */
#define USART3_PCLK_DI()           ( RCC->APB1ENR &= ~( 1 << 18 ) )             /*!<  USART3 clock disabled */
#define UART4_PCLK_DI()            ( RCC->APB1ENR &= ~( 1 << 19 ) )             /*!<  UART4 clock disabled */
#define UART5_PCLK_DI()            ( RCC->APB1ENR &= ~( 1 << 20 ) )             /*!<  UART5 clock disabled */

/*
 * Clock Enable Macros for AFIO peripherals
 */
#define AFIO_PCLK_EN()            ( RCC->APB2ENR |= ( 1 << 0 ) )             /*!<  GPIO port A clock enabled */

/*
 * IRQ(Interrupt Request) Numbers of STM32F103x MCU
 * NOTE: update these macros with valid values according to your MCU
 * TODO: You may complete this list for other peripherals
 * OBS: Find in RM0008 Table 6.1 Vector Table - Position
 */
#define IRQ_NO_EXTI0 		6
#define IRQ_NO_EXTI1 		7
#define IRQ_NO_EXTI2 		8
#define IRQ_NO_EXTI3 		9
#define IRQ_NO_EXTI4 		10
#define IRQ_NO_EXTI9_5		23
#define IRQ_NO_EXTI15_10 	40
#define IRQ_NO_SPI1		 	35
#define IRQ_NO_SPI2		 	36
#define IRQ_NO_SPI3		 	51
#define IRQ_NO_I2C1_EV     	31
#define IRQ_NO_I2C1_ER     	32
#define IRQ_NO_I2C2_EV     	33
#define IRQ_NO_USART1     	37
#define IRQ_NO_USART2     	38
#define IRQ_NO_USART3     	39
#define IRQ_NO_UART4     	52
#define IRQ_NO_UART5     	60

/*
 * IRQ(Interrupt Request) Numbers of Priority possible
 */
#define NVIC_IRQ_PRIO0		0
#define NVIC_IRQ_PRIO1		1
#define NVIC_IRQ_PRIO2		2
#define NVIC_IRQ_PRIO3		3
#define NVIC_IRQ_PRIO4		4
#define NVIC_IRQ_PRIO5		5
#define NVIC_IRQ_PRIO6		6
#define NVIC_IRQ_PRIO7		7
#define NVIC_IRQ_PRIO8		8
#define NVIC_IRQ_PRIO9		9
#define NVIC_IRQ_PRIO10		10
#define NVIC_IRQ_PRIO11		11
#define NVIC_IRQ_PRIO12		12
#define NVIC_IRQ_PRIO13		13
#define NVIC_IRQ_PRIO14		14
#define NVIC_IRQ_PRIO15		15

/*
 * Generics Macros
 */
#define ENABLE    			1
#define DISABLE   			0
#define SET       			ENABLE
#define RESET     			DISABLE
#define GPIO_PIN_SET		SET
#define GPIO_PIN_RESET  	RESET
#define FLAG_RESET			RESET
#define FLAG_SET			SET
#define HIGH       			ENABLE
#define LOW     			DISABLE
#define NULL				((void *)0) // maybe include <stddef.h>

/*
 * Bits position definitions of SPI peripheral
 */
#define SPI_CR1_CPHA			0
#define SPI_CR1_CPOL			1
#define SPI_CR1_MSTR			2
#define SPI_CR1_BR				3
#define SPI_CR1_SPE				6
#define SPI_CR1_LSBFIRST		7
#define SPI_CR1_SSI				8
#define SPI_CR1_SSM				9
#define SPI_CR1_RXONLY			10
#define SPI_CR1_DFF				11
#define SPI_CR1_CRCNXT			12
#define SPI_CR1_CRCEN			13
#define SPI_CR1_BIDIOE			14
#define SPI_CR1_BIDIMODE		15

#define SPI_CR2_RXDMAEN			0
#define SPI_CR2_TXDMAEN			1
#define SPI_CR2_SSOE			2
#define SPI_CR2_ERRIE			3
#define SPI_CR2_RXNEIE			6
#define SPI_CR2_TXEIE			7

#define SPI_SR_RXNE				0
#define SPI_SR_TXE				1
#define SPI_SR_CHSIDE			2
#define SPI_SR_UDR				3
#define SPI_SR_CRCERR			4
#define SPI_SR_MODF				5
#define SPI_SR_OVR				6
#define SPI_SR_BSY				7

/*
 * Bits position definitions of I2C peripheral
 */
#define I2C_CR1_PE				0
#define I2C_CR1_SMBUS			1
#define I2C_CR1_SMBTYPE			3
#define I2C_CR1_ENARP			4
#define I2C_CR1_ENPEC			5
#define I2C_CR1_ENGC			6
#define I2C_CR1_NOSTRETCH		7
#define I2C_CR1_START			8
#define I2C_CR1_STOP			9
#define I2C_CR1_ACK				10
#define I2C_CR1_POS				11
#define I2C_CR1_PEC				12
#define I2C_CR1_ALERT			13
#define I2C_CR1_SWRST			15

#define I2C_CR2_FREQ			0
#define I2C_CR2_ITERREN			8
#define I2C_CR2_ITEVTEN			9
#define I2C_CR2_ITBUFEN			10
#define I2C_CR2_DMAEN			11
#define I2C_CR2_LAST			12

#define I2C_OAR1_ADD			0
#define I2C_OAR1_ADD71 			1
#define I2C_OAR1_ADD98  		8
#define I2C_OAR1_ADDMODE   		15

#define I2C_OAR2_ENDUAL   		0
#define I2C_OAR2_ADD71   		1

#define I2C_SR1_SB 				0
#define I2C_SR1_ADDR 			1
#define I2C_SR1_BTF 			2
#define I2C_SR1_ADD10 			3
#define I2C_SR1_STOPF 			4
#define I2C_SR1_RXNE 			6
#define I2C_SR1_TXE 			7
#define I2C_SR1_BERR 			8
#define I2C_SR1_ARLO 			9
#define I2C_SR1_AF 				10
#define I2C_SR1_OVR 			11
#define I2C_SR1_TIMEOUT 		14

#define I2C_SR2_MSL				0
#define I2C_SR2_BUSY 			1
#define I2C_SR2_TRA 			2
#define I2C_SR2_GENCALL 		4
#define I2C_SR2_DUALF 			7

#define I2C_CCR_CCR 			0
#define I2C_CCR_DUTY 			14
#define I2C_CCR_FS  			15

/*
 * Bits position definitions of USART peripheral
 */
#define USART_SR_PE				0
#define USART_SR_FE				1
#define USART_SR_NE				2
#define USART_SR_ORE			3
#define USART_SR_IDLE			4
#define USART_SR_RXNE			5
#define USART_SR_TC				6
#define USART_SR_TXE			7
#define USART_SR_LBD			8
#define USART_SR_CTS			9

#define USART_DR				0

#define USART_BRR_DIV_FRAC		0
#define USART_BRR_DIV_MANT		4

#define USART_CR1_SBK			0
#define USART_CR1_RWU			1
#define USART_CR1_RE			2
#define USART_CR1_TE			3
#define USART_CR1_IDLEIE		4
#define USART_CR1_RXNEIE		5
#define USART_CR1_TCIE			6
#define USART_CR1_TXEIE			7
#define USART_CR1_PEIE			8
#define USART_CR1_PS			9
#define USART_CR1_PCE			10
#define USART_CR1_WAKE			11
#define USART_CR1_M				12
#define USART_CR1_UE			13

#define USART_CR2_ADD			0
#define USART_CR2_LBDL			5
#define USART_CR2_LBCL			8
#define USART_CR2_CPHA			9
#define USART_CR2_CPOL			10
#define USART_CR2_CLKEN			11
#define USART_CR2_STOP			12
#define USART_CR2_LINEN			14

#define USART_CR3_EIE			0
#define USART_CR3_IREN			1
#define USART_CR3_IRLP			2
#define USART_CR3_HDSEL			3
#define USART_CR3_NACK			4
#define USART_CR3_SCEN			5
#define USART_CR3_DMAR			6
#define USART_CR3_DMAT			7
#define USART_CR3_RTSE			8
#define USART_CR3_CTSE			9
#define USART_CR3_CTSIE			10

#define USART_GTPR_PSC			0
#define USART_GTPR_GT			8

#include "stm32f103xx_gpio_driver.h"
#include "stm32f103xx_spi_driver.h"
#include "stm32f103xx_i2c_driver.h"
#include "stm32f103xx_usart_driver.h"

#endif /* INC_STM32F103XX_H_ */
