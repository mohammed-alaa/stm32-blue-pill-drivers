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
