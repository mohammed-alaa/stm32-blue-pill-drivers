/**
 * @file RCC_private.h
 * @author Mohamed Alaa
 * @version 1.0.0
 * @brief This file contains the private macros and registers for the RCC module.
 * @details This file contains the private macros and registers for the RCC module.
 * @date 2023-06-18
 */

#ifndef _RCC_PRIVATE_H_
#define _RCC_PRIVATE_H_

#include "../../LIB/LSTD_HW_REGS.h"
#include "../../LIB/LSTD_TYPES.h"

/**
 * @addtogroup mcal
 * @{
 */

/**
 * @defgroup rcc_module RCC Module
 * @brief RCC Module
 * @{
 */

/**
 * @defgroup rcc_registers RCC Registers
 * @brief RCC Registers
 * @{
 */

/**
 * @struct t_RCC_CR
 * @brief RCC clock control register
 */
typedef struct
{
	/**
	 * @brief Internal high-speed clock enable
	 * @details Enable or disable the internal high-speed clock (HSI)
	 */
	t_u32 HSION : 1;
	/**
	 * @brief Internal high-speed clock ready flag
	 * @details Whether the internal high-speed clock is ready or not
	 * @warning This field is read-only
	 */
	t_u32 HSIRDY : 1;
	/**
	 * @brief Reserved bit(s)
	 * @attention This field is reserved and must be kept at reset value.
	 */
	t_u32 : 1;
	/**
	 * @brief Internal high-speed clock trimming
	 * @details Adjusts the internal high-speed clock (HSI) frequency in conjunction with the HSICAL field
	 * @note Default value: 16
	 */
	t_u32 HSITRIM : 5;
	/**
	 * @brief Internal high-speed clock calibration
	 * @details This field holds the factory calibration value
	 * @warning This field is read-only
	 */
	t_u32 HSICAL : 8;
	/**
	 * @brief HSE clock enable
	 * @details Enable or disable the external high-speed clock (HSE)
	 */
	t_u32 HSEON : 1;
	/**
	 * @brief External high-speed clock ready flag
	 * @details Whether the external high-speed clock is ready or not
	 * @warning This field is read-only
	 */
	t_u32 HSERDY : 1;
	/**
	 * @brief External high-speed clock bypass
	 * @details Bypass the oscillator with an external clock
	 */
	t_u32 HSEBYP : 1;
	/**
	 * @brief Clock security system enable
	 * @details Enable or disable the clock security system
	 */
	t_u32 CSSON : 1;
	/**
	 * @brief Reserved bit(s)
	 * @attention This field is reserved and must be kept at reset value.
	 */
	t_u32 : 4;
	/**
	 * @brief PLL enable
	 * @details Enable or disable the PLL
	 * @note Software must disable the USB OTG FS clock before clearing this bit.
	 */
	t_u32 PLLON : 1;
	/**
	 * @brief PLL clock ready flag
	 * @details This bit is set by hardware to indicate that the PLL clock is locked
	 * @warning This field is read-only
	 */
	t_u32 PLLRDY : 1;
	/**
	 * @brief PLL2 enable
	 * @details Enable or disable PLL2
	 */
	t_u32 PLL2ON : 1;
	/**
	 * @brief PLL2 clock ready flag
	 * @details This bit is set by hardware to indicate that the PLL2 clock is locked
	 * @warning This field is read-only
	 */
	t_u32 PLL2RDY : 1;
	/**
	 * @brief PLL3 enable
	 * @details Enable or disable PLL3
	 */
	t_u32 PLL3ON : 1;
	/**
	 * @brief PLL3 clock ready flag
	 * @details This bit is set by hardware to indicate that the PLL3 clock is locked
	 * @warning This field is read-only
	 */
	t_u32 PLL3RDY : 1;
	/**
	 * @brief Reserved bit(s)
	 * @attention This field is reserved and must be kept at reset value.
	 */
	t_u32 : 2;
} t_RCC_CR;

/**
 * @struct t_RCC_CFGR
 * @brief RCC clock configuration register
 */
typedef struct
{
	/**
	 * @brief System clock switch
	 * @details Select the system clock source
	 */
	t_u32 SW : 2;
	/**
	 * @brief System clock switch status
	 * @details These bits are set and cleared by hardware to inform about which clock source is used as the system clock
	 * @warning This field is read-only
	 */
	t_u32 SWS : 2;
	/**
	 * @brief AHB prescaler
	 * @details Configure the AHB clock (HCLK) prescaler
	 */
	t_u32 HPRE : 4;
	/**
	 * @brief APB Low speed prescaler (APB1)
	 * @details Configure the APB1 clock (PCLK1) prescaler
	 * @warning Max frequency for APB1 is 36 MHz
	 */
	t_u32 PPRE1 : 3;
	/**
	 * @brief APB high-speed prescaler (APB2)
	 * @details Configure the APB2 clock (PCLK2) prescaler
	 * @warning Max frequency for APB2 is 72 MHz
	 */
	t_u32 PPRE2 : 3;
	/**
	 * @brief ADC prescaler
	 * @details Configure the ADC clock (ADCCLK) prescaler
	 * @warning Max frequency for ADC is 14 MHz
	 */
	t_u32 ADCPRE : 2;
	/**
	 * @brief PLL entry/input clock source
	 * @details Select the PLL input clock source
	 */
	t_u32 PLLSRC : 1;
	/**
	 * @brief LSB of PLL division factor PREDIV1
	 * @details Select the LSB of the division factor for PLL input clock
	 */
	t_u32 PLLXTPRE : 1;
	/**
	 * @brief PLL multiplication factor
	 * @details Configure the PLL multiplication factor
	 */
	t_u32 PLLMUL : 4;
	/**
	 * @brief USB OTG FS prescaler
	 * @details Configure the USB OTG FS clock (OTGFSCLK) prescaler
	 */
	t_u32 OTGFSPRE : 1;
	/**
	 * @brief Reserved bit(s)
	 * @attention This field is reserved and must be kept at reset value.
	 */
	t_u32 : 1;
	/**
	 * @brief Microcontroller clock output
	 * @details Configure the MCO clock
	 */
	t_u32 MCO : 4;
	/**
	 * @brief Reserved bit(s)
	 * @attention This field is reserved and must be kept at reset value.
	 */
	t_u32 : 4;
} t_RCC_CFGR;

/**
 * @struct t_RCC_CIR
 * @brief RCC clock interrupt register
 */
typedef struct
{
	/**
	 * @brief LSI ready interrupt flag
	 * @details This field indicates whether the LSI oscillator is stable or not
	 * @warning This field is read-only
	 */
	t_u32 LSIRDYF : 1;
	/**
	 * @brief LSE ready interrupt flag
	 * @details This field indicates whether the LSE oscillator is stable or not
	 * @warning This field is read-only
	 */
	t_u32 LSERDYF : 1;
	/**
	 * @brief HSI ready interrupt flag
	 * @details This field indicates whether the HSI oscillator is stable or not
	 * @warning This field is read-only
	 */
	t_u32 HSIRDYF : 1;
	/**
	 * @brief HSE ready interrupt flag
	 * @details This field indicates whether the HSE oscillator is stable or not
	 * @warning This field is read-only
	 */
	t_u32 HSERDYF : 1;
	/**
	 * @brief PLL ready interrupt flag
	 * @details This field indicates whether the PLL oscillator is stable or not
	 * @warning This field is read-only
	 */
	t_u32 PLLRDYF : 1;
	/**
	 * @brief PLL2 ready interrupt flag
	 * @details This field indicates whether the PLL2 oscillator is stable or not
	 * @warning This field is read-only
	 */
	t_u32 PLL2RDYF : 1;
	/**
	 * @brief PLL3 ready interrupt flag
	 * @details This field indicates whether the PLL3 oscillator is stable or not
	 * @warning This field is read-only
	 */
	t_u32 PLL3RDYF : 1;
	/**
	 * @brief Clock security system interrupt flag
	 * @details This field indicates whether a failure is detected on the external 3.3 V oscillator
	 * @warning This field is read-only
	 */
	t_u32 CSSF : 1;
	/**
	 * @brief LSI ready interrupt enable
	 * @details This field enables the LSI ready interrupt
	 */
	t_u32 LSIRDYIE : 1;
	/**
	 * @brief LSE ready interrupt enable
	 * @details This field enables the LSE ready interrupt
	 */
	t_u32 LSERDYIE : 1;
	/**
	 * @brief HSI ready interrupt enable
	 * @details This field enables the HSI ready interrupt
	 */
	t_u32 HSIRDYIE : 1;
	/**
	 * @brief HSE ready interrupt enable
	 * @details This field enables the HSE ready interrupt
	 */
	t_u32 HSERDYIE : 1;
	/**
	 * @brief PLL ready interrupt enable
	 * @details This field enables the PLL ready interrupt
	 */
	t_u32 PLLRDYIE : 1;
	/**
	 * @brief PLL2 ready interrupt enable
	 * @details This field enables the PLL2 ready interrupt
	 */
	t_u32 PLL2RDYIE : 1;
	/**
	 * @brief PLL3 ready interrupt enable
	 * @details This field enables the PLL3 ready interrupt
	 */
	t_u32 PLL3RDYIE : 1;
	/**
	 * @brief Reserved bit(s)
	 * @attention This field is reserved and must be kept at reset value.
	 */
	t_u32 : 1;
	/**
	 * @brief LSI ready interrupt clear
	 * @details This field clears the LSI ready interrupt
	 */
	t_u32 LSIRDYC : 1;
	/**
	 * @brief LSE ready interrupt clear
	 * @details This field clears the LSE ready interrupt
	 */
	t_u32 LSERDYC : 1;
	/**
	 * @brief HSI ready interrupt clear
	 * @details This field clears the HSI ready interrupt
	 */
	t_u32 HSIRDYC : 1;
	/**
	 * @brief HSE ready interrupt clear
	 * @details This field clears the HSE ready interrupt
	 */
	t_u32 HSERDYC : 1;
	/**
	 * @brief PLL ready interrupt clear
	 * @details This field clears the PLL ready interrupt
	 */
	t_u32 PLLRDYC : 1;
	/**
	 * @brief PLL2 ready interrupt clear
	 * @details This field clears the PLL2 ready interrupt
	 */
	t_u32 PLL2RDYC : 1;
	/**
	 * @brief PLL3 ready interrupt clear
	 * @details This field clears the PLL3 ready interrupt
	 */
	t_u32 PLL3RDYC : 1;
	/**
	 * @brief Clock security system interrupt clear
	 * @details This field clears the clock security system interrupt
	 */
	t_u32 CSSC : 1;
	/**
	 * @brief Reserved bit(s)
	 * @attention This field is reserved and must be kept at reset value.
	 */
	t_u32 : 8;
} t_RCC_CIR;

/**
 * @struct t_RCC_APB2RSTR
 * @brief RCC APB2 peripheral reset register
 */
typedef struct
{
	/**
	 * @brief Alternate function I/O reset
	 * @details This field resets the IO port configuration registers
	 */
	t_u32 AFIORST : 1;
	/**
	 * @brief Reserved bit(s)
	 * @attention This field is reserved and must be kept at reset value.
	 */
	t_u32 : 1;
	/**
	 * @brief IO port A reset
	 * @details This field resets the IO port A configuration registers
	 */
	t_u32 IOPARST : 1;
	/**
	 * @brief IO port B reset
	 * @details This field resets the IO port B configuration registers
	 */
	t_u32 IOPBRST : 1;
	/**
	 * @brief IO port C reset
	 * @details This field resets the IO port C configuration registers
	 */
	t_u32 IOPCRST : 1;
	/**
	 * @brief IO port D reset
	 * @details This field resets the IO port D configuration registers
	 */
	t_u32 IOPDRST : 1;
	/**
	 * @brief IO port E reset
	 * @details This field resets the IO port E configuration registers
	 */
	t_u32 IOPERST : 1;
	/**
	 * @brief Reserved bit(s)
	 * @attention This field is reserved and must be kept at reset value.
	 */
	t_u32 : 2;
	/**
	 * @brief ADC 1 interface reset
	 * @details This field resets the ADC 1 configuration registers
	 */
	t_u32 ADC1RST : 1;
	/**
	 * @brief ADC 2 interface reset
	 * @details This field resets the ADC 2 configuration registers
	 */
	t_u32 ADC2RST : 1;
	/**
	 * @brief TIM1 timer reset
	 * @details This field resets the TIM1 configuration registers
	 */
	t_u32 TIM1RST : 1;
	/**
	 * @brief SPI 1 reset
	 * @details This field resets the SPI 1 configuration registers
	 */
	t_u32 SPI1RST : 1;
	/**
	 * @brief Reserved bit(s)
	 * @attention This field is reserved and must be kept at reset value.
	 */
	t_u32 : 1;
	/**
	 * @brief USART1 reset
	 * @details This field resets the USART1 configuration registers
	 */
	t_u32 USART1RST : 1;
	/**
	 * @brief Reserved bit(s)
	 * @attention This field is reserved and must be kept at reset value.
	 */
	t_u32 : 17;
} t_RCC_APB2RSTR;

/**
 * @struct t_RCC_APB1RSTR
 * @brief RCC APB1 peripheral reset register
 */
typedef struct
{
	/**
	 * @brief TIM2 timer reset
	 * @details This field resets the TIM2 configuration registers
	 */
	t_u32 TIM2RST : 1;
	/**
	 * @brief TIM3 timer reset
	 * @details This field resets the TIM3 configuration registers
	 */
	t_u32 TIM3RST : 1;
	/**
	 * @brief TIM4 timer reset
	 * @details This field resets the TIM4 configuration registers
	 */
	t_u32 TIM4RST : 1;
	/**
	 * @brief TIM5 timer reset
	 * @details This field resets the TIM5 configuration registers
	 */
	t_u32 TIM5RST : 1;
	/**
	 * @brief TIM6 timer reset
	 * @details This field resets the TIM6 configuration registers
	 */
	t_u32 TIM6RST : 1;
	/**
	 * @brief TIM7 timer reset
	 * @details This field resets the TIM7 configuration registers
	 */
	t_u32 TIM7RST : 1;
	/**
	 * @brief Reserved bit(s)
	 * @attention This field is reserved and must be kept at reset value.
	 */
	t_u32 : 5;
	/**
	 * @brief Window watchdog reset
	 * @details This field resets the window watchdog configuration registers
	 */
	t_u32 WWDGRST : 1;
	/**
	 * @brief Reserved bit(s)
	 * @attention This field is reserved and must be kept at reset value.
	 */
	t_u32 : 2;
	/**
	 * @brief SPI 2 reset
	 * @details This field resets the SPI 2 configuration registers
	 */
	t_u32 SPI2RST : 1;
	/**
	 * @brief SPI 3 reset
	 * @details This field resets the SPI 3 configuration registers
	 */
	t_u32 SPI3RST : 1;
	/**
	 * @brief Reserved bit(s)
	 * @attention This field is reserved and must be kept at reset value.
	 */
	t_u32 : 1;
	/**
	 * @brief USART 2 reset
	 * @details This field resets the USART 2 configuration registers
	 */
	t_u32 USART2RST : 1;
	/**
	 * @brief USART 3 reset
	 * @details This field resets the USART 3 configuration registers
	 */
	t_u32 USART3RST : 1;
	/**
	 * @brief UART 4 reset
	 * @details This field resets the UART 4 configuration registers
	 */
	t_u32 UART4RST : 1;
	/**
	 * @brief UART 5 reset
	 * @details This field resets the UART 5 configuration registers
	 */
	t_u32 UART5RST : 1;
	/**
	 * @brief I2C 1 reset
	 * @details This field resets the I2C 1 configuration registers
	 */
	t_u32 I2C1RST : 1;
	/**
	 * @brief I2C 2 reset
	 * @details This field resets the I2C 2 configuration registers
	 */
	t_u32 I2C2RST : 1;
	/**
	 * @brief Reserved bit(s)
	 * @attention This field is reserved and must be kept at reset value.
	 */
	t_u32 : 2;
	/**
	 * @brief CAN 1 reset
	 * @details This field resets the CAN 1 configuration registers
	 */
	t_u32 CAN1RST : 1;
	/**
	 * @brief CAN 2 reset
	 * @details This field resets the CAN 2 configuration registers
	 */
	t_u32 CAN2RST : 1;
	/**
	 * @brief Backup interface reset
	 * @details This field resets the backup interface configuration registers
	 */
	t_u32 BKPRST : 1;
	/**
	 * @brief Power interface reset
	 * @details This field resets the power interface configuration registers
	 */
	t_u32 PWRRST : 1;
	/**
	 * @brief DAC interface reset
	 * @details This field resets the DAC interface configuration registers
	 */
	t_u32 DACRST : 1;
	/**
	 * @brief Reserved bit(s)
	 * @attention This field is reserved and must be kept at reset value.
	 */
	t_u32 : 2;
} t_RCC_APB1RSTR;

/**
 * @struct t_RCC_AHBENR
 * @brief RCC AHB peripheral clock register
 */
typedef struct
{
	/**
	 * @brief DMA1 clock enable
	 * @details This field enables the DMA1 clock
	 */
	t_u32 DMA1EN : 1;
	/**
	 * @brief DMA2 clock enable
	 * @details This field enables the DMA2 clock
	 */
	t_u32 DMA2EN : 1;
	/**
	 * @brief SRAM interface clock enable
	 * @details This field enables the SRAM interface clock
	 */
	t_u32 SRAMEN : 1;
	/**
	 * @brief Reserved bit(s)
	 * @attention This field is reserved and must be kept at reset value.
	 */
	t_u32 : 1;
	/**
	 * @brief FLITF clock enable
	 * @details This field enables the FLITF clock
	 */
	t_u32 FLITFEN : 1;
	/**
	 * @brief Reserved bit(s)
	 * @attention This field is reserved and must be kept at reset value.
	 */
	t_u32 : 1;
	/**
	 * @brief CRC clock enable
	 * @details This field enables the CRC clock
	 */
	t_u32 CRCEN : 1;
	/**
	 * @brief Reserved bit(s)
	 * @attention This field is reserved and must be kept at reset value.
	 */
	t_u32 : 5;
	/**
	 * @brief OTG FS clock enable
	 * @details This field enables the OTG FS clock
	 */
	t_u32 OTGFSEN : 1;
	/**
	 * @brief Reserved bit(s)
	 * @attention This field is reserved and must be kept at reset value.
	 */
	t_u32 : 1;
	/**
	 * @brief Ethernet MAC clock enable
	 * @details This field enables the Ethernet MAC clock
	 */
	t_u32 ETHMACEN : 1;
	/**
	 * @brief Ethernet MAC TX clock enable
	 * @details This field enables the Ethernet MAC TX clock
	 */
	t_u32 ETHMACTXEN : 1;
	/**
	 * @brief Ethernet MAC RX clock enable
	 * @details This field enables the Ethernet MAC RX clock
	 */
	t_u32 ETHMACRXEN : 1;
	/**
	 * @brief Reserved bit(s)
	 * @attention This field is reserved and must be kept at reset value.
	 */
	t_u32 : 15;
} t_RCC_AHBENR;

/**
 * @struct t_RCC_APB2ENR
 * @brief RCC APB2 peripheral clock enable register
 */
typedef struct
{
	/**
	 * @brief Alternate function I/O clock enable
	 * @details This field enables the alternate function I/O clock
	 */
	t_u32 AFIOEN : 1;
	/**
	 * @brief Reserved bit(s)
	 * @attention This field is reserved and must be kept at reset value.
	 */
	t_u32 : 1;
	/**
	 * @brief I/O port A clock enable
	 * @details This field enables the I/O port A clock
	 */
	t_u32 IOPAEN : 1;
	/**
	 * @brief I/O port B clock enable
	 * @details This field enables the I/O port B clock
	 */
	t_u32 IOPBEN : 1;
	/**
	 * @brief I/O port C clock enable
	 * @details This field enables the I/O port C clock
	 */
	t_u32 IOPCEN : 1;
	/**
	 * @brief I/O port D clock enable
	 * @details This field enables the I/O port D clock
	 */
	t_u32 IOPDEN : 1;
	/**
	 * @brief I/O port E clock enable
	 * @details This field enables the I/O port E clock
	 */
	t_u32 IOPEEN : 1;
	/**
	 * @brief Reserved bit(s)
	 * @attention This field is reserved and must be kept at reset value.
	 */
	t_u32 : 2;
	/**
	 * @brief ADC 1 interface clock enable
	 * @details This field enables the ADC 1 interface clock
	 */
	t_u32 ADC1EN : 1;
	/**
	 * @brief ADC 2 interface clock enable
	 * @details This field enables the ADC 2 interface clock
	 */
	t_u32 ADC2EN : 1;
	/**
	 * @brief TIM1 Timer clock enable
	 * @details This field enables the TIM1 Timer clock
	 */
	t_u32 TIM1EN : 1;
	/**
	 * @brief SPI 1 clock enable
	 * @details This field enables the SPI 1 clock
	 */
	t_u32 SPI1EN : 1;
	/**
	 * @brief Reserved bit(s)
	 * @attention This field is reserved and must be kept at reset value.
	 */
	t_u32 : 1;
	/**
	 * @brief USART1 clock enable
	 * @details This field enables the USART1 clock
	 */
	t_u32 USART1EN : 1;
	/**
	 * @brief Reserved bit(s)
	 * @attention This field is reserved and must be kept at reset value.
	 */
	t_u32 : 17;
} t_RCC_APB2ENR;

/**
 * @struct t_RCC_APB1ENR
 * @brief RCC APB1 peripheral clock enable register
 */
typedef struct
{
	/**
	 * @brief Timer 2 clock enable
	 * @details This field enables the Timer 2 clock
	 */
	t_u32 TIM2EN : 1;
	/**
	 * @brief Timer 3 clock enable
	 * @details This field enables the Timer 3 clock
	 */
	t_u32 TIM3EN : 1;
	/**
	 * @brief Timer 4 clock enable
	 * @details This field enables the Timer 4 clock
	 */
	t_u32 TIM4EN : 1;
	/**
	 * @brief Timer 5 clock enable
	 * @details This field enables the Timer 5 clock
	 */
	t_u32 TIM5EN : 1;
	/**
	 * @brief Timer 6 clock enable
	 * @details This field enables the Timer 6 clock
	 */
	t_u32 TIM6EN : 1;
	/**
	 * @brief Timer 7 clock enable
	 * @details This field enables the Timer 7 clock
	 */
	t_u32 TIM7EN : 1;
	/**
	 * @brief Reserved bit(s)
	 * @attention This field is reserved and must be kept at reset value.
	 */
	t_u32 : 5;
	/**
	 * @brief Window watchdog clock enable
	 * @details This field enables the Window watchdog clock
	 */
	t_u32 WWDGEN : 1;
	/**
	 * @brief Reserved bit(s)
	 * @attention This field is reserved and must be kept at reset value.
	 */
	t_u32 : 2;
	/**
	 * @brief SPI 2 clock enable
	 * @details This field enables the SPI 2 clock
	 */
	t_u32 SPI2EN : 1;
	/**
	 * @brief SPI 3 clock enable
	 * @details This field enables the SPI 3 clock
	 */
	t_u32 SPI3EN : 1;
	/**
	 * @brief Reserved bit(s)
	 * @attention This field is reserved and must be kept at reset value.
	 */
	t_u32 : 1;
	/**
	 * @brief USART 2 clock enable
	 * @details This field enables the USART 2 clock
	 */
	t_u32 USART2EN : 1;
	/**
	 * @brief USART 3 clock enable
	 * @details This field enables the USART 3 clock
	 */
	t_u32 USART3EN : 1;
	/**
	 * @brief UART 4 clock enable
	 * @details This field enables the UART 4 clock
	 */
	t_u32 UART4EN : 1;
	/**
	 * @brief UART 5 clock enable
	 * @details This field enables the UART 5 clock
	 */
	t_u32 UART5EN : 1;
	/**
	 * @brief I2C 1 clock enable
	 * @details This field enables the I2C 1 clock
	 */
	t_u32 I2C1EN : 1;
	/**
	 * @brief I2C 2 clock enable
	 * @details This field enables the I2C 2 clock
	 */
	t_u32 I2C2EN : 1;
	/**
	 * @brief Reserved bit(s)
	 * @attention This field is reserved and must be kept at reset value.
	 */
	t_u32 : 2;
	/**
	 * @brief CAN 1 clock enable
	 * @details This field enables the CAN 1 clock
	 */
	t_u32 CAN1EN : 1;
	/**
	 * @brief CAN 2 clock enable
	 * @details This field enables the CAN 2 clock
	 */
	t_u32 CAN2EN : 1;
	/**
	 * @brief Backup interface clock enable
	 * @details This field enables the Backup interface clock
	 */
	t_u32 BKPEN : 1;
	/**
	 * @brief Power interface clock enable
	 * @details This field enables the Power interface clock
	 */
	t_u32 PWREN : 1;
	/**
	 * @brief DAC interface clock enable
	 * @details This field enables the DAC interface clock
	 */
	t_u32 DACEN : 1;
	/**
	 * @brief Reserved bit(s)
	 * @attention This field is reserved and must be kept at reset value.
	 */
	t_u32 : 2;
} t_RCC_APB1ENR;

/**
 * @struct t_RCC_BDCR
 * @brief RCC Backup domain control register
 */
typedef struct
{
	/**
	 * @brief External Low Speed oscillator enable
	 * @details This field enables the external Low Speed oscillator (LSE)
	 */
	t_u32 LSEON : 1;
	/**
	 * @brief External Low Speed oscillator ready
	 * @details This field is set and cleared by hardware to indicate when the external Low Speed oscillator (LSE) is stable.
	 * @warning This field is read-only
	 */
	t_u32 LSERDY : 1;
	/**
	 * @brief External Low Speed oscillator bypass
	 * @details This field is used to bypass the oscillator with an external clock.
	 */
	t_u32 LSEBYP : 1;
	/**
	 * @brief Reserved bit(s)
	 * @attention This field is reserved and must be kept at reset value.
	 */
	t_u32 : 5;
	/**
	 * @brief RTC clock source selection
	 * @details This field selects the clock source to be used for the RTC.
	 */
	t_u32 RTCSEL : 2;
	/**
	 * @brief Reserved bit(s)
	 * @attention This field is reserved and must be kept at reset value.
	 */
	t_u32 : 5;
	/**
	 * @brief RTC clock enable
	 * @details This field enables the RTC clock
	 */
	t_u32 RTCEN : 1;
	/**
	 * @brief Backup domain software reset
	 * @details This field forces the Backup domain to reset.
	 */
	t_u32 BDRST : 1;
	/**
	 * @brief Reserved bit(s)
	 * @attention This field is reserved and must be kept at reset value.
	 */
	t_u32 : 15;
} t_RCC_BDCR;

/**
 * @struct RCC_RegisterMap
 * @brief RCC Register Map
 */
typedef struct
{
	/**
	 * @brief Clock control register
	 */
	t_RCC_CR CR;
	/**
	 * @brief Clock configuration register
	 */
	t_RCC_CFGR CFGR;
	/**
	 * @brief Clock interrupt register
	 */
	t_RCC_CIR CIR;
	/**
	 * @brief RCC APB2 peripheral reset register
	 */
	t_RCC_APB2RSTR APB2RSTR;
	/**
	 * @brief RCC APB1 peripheral reset register
	 */
	t_RCC_APB1RSTR APB1RSTR;
	/**
	 * @brief RCC AHB peripheral clock register
	 */
	t_RCC_AHBENR AHBENR;
	/**
	 * @brief RCC APB2 peripheral clock enable register
	 */
	t_RCC_APB2ENR APB2ENR;
	/**
	 * @brief RCC APB1 peripheral clock enable register
	 */
	t_RCC_APB1ENR APB1ENR;
	/**
	 * @brief RCC Backup domain control register
	 */
	t_RCC_BDCR BDCR;
} RCC_RegisterMap;

/** @} */

/**
 * @defgroup rcc_addresses RCC Addresses
 * @brief RCC Addresses
 * @{
 */

/**
 * @def RCC_BASE_ADDRESS
 * @brief RCC Base Address in the memory
 */
#define RCC_BASE_ADDRESS REGISTER_ADDRESS(0x40021000, 0)

/**
 * @def RCC
 * @brief RCC Register Map
 */
#define RCC REGISTER(RCC_RegisterMap, RCC_BASE_ADDRESS)

/** @} */
/** @} */
/** @} */

#endif /* _RCC_PRIVATE_H_ */
