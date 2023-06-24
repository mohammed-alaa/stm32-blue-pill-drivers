/**
 * @file RCC_config.h
 * @author Mohamed Alaa
 * @version 1.0.0
 * @brief This file contains the configuration parameters for the RCC module.
 * @details This file contains the configuration parameters for the RCC module.
 * @date 2023-06-18
 */

#ifndef _RCC_CONFIG_H_
#define _RCC_CONFIG_H_

#include "../../LIB/LSTD_VALUES.h"
#include "RCC_interface.h"

/**
 * @addtogroup mcal
 * @{
 */

/**
 * @addtogroup rcc_module
 * @{
 */

/**
 * @defgroup rcc_config RCC Configuration
 * @brief This group contains the configuration parameters of the RCC module
 * @{
 */

/**
 * @def RCC_PLL_SRC
 * @brief This macro defines the PLL source
 * @details This macro defines the PLL source
 * @see RCC_PLLSource
 */
#define RCC_PLL_SRC (RCC_PLLSource_HSE)

/**
 * @def RCC_PLL_MUL
 * @brief This macro defines the PLL multiplication factor
 * @details This macro defines the PLL multiplication factor
 * @see RCC_PLLMulFactors
 */
#define RCC_PLL_MUL (RCC_PLLMulFactors_9)

/**
 * @def RCC_PLL_HSE_DIVIDE_BY_2
 * @brief This macro defines the PLL entry HSE divider
 * @details This macro defines the PLL entry HSE divider
 * Options:
 * 	- FALSE: HSE clock is not divided
 * 	- TRUE: HSE clock divided by 2
 */
#define RCC_PLL_HSE_DIVIDE_BY_2 (TRUE)

/**
 * @def RCC_SYSTEM_CLOCK_SOURCE
 * @brief This macro defines the system clock source
 * @details This macro defines the system clock source
 * @see RCC_SystemClock
 */
#define RCC_SYSTEM_CLOCK_SOURCE (RCC_SystemClock_PLL)

/**
 * @def RCC_MCO_SOURCE
 * @brief This macro defines the MCO source
 * @details This macro defines the MCO source
 * @see RCC_MCOSources
 */
#define RCC_MCO_SOURCE (RCC_MCOSources_NoClock)

/**
 * @def RCC_ADC_PRESCALER
 * @brief This macro defines the ADC clock prescaler
 * @details This macro defines the ADC clock prescaler
 * @see RCC_ADCPrescaler
 */
#define RCC_ADC_PRESCALER (RCC_ADCPrescaler_DividedBy4)

/**
 * @def RCC_AHB_PRESCALER
 * @brief This macro defines the AHB clock prescaler
 * @details This macro defines the AHB clock prescaler
 * @see RCC_AHBPrescaler
 */
#define RCC_AHB_PRESCALER (RCC_AHBPrescaler_NotDivided)

/**
 * @def RCC_APB1_PRESCALER
 * @brief This macro defines the APB1 clock prescaler
 * @details This macro defines the APB1 clock prescaler
 * @see RCC_APBPrescaler
 */
#define RCC_APB1_PRESCALER (RCC_APBPrescaler_NotDivided)

/**
 * @def RCC_APB2_PRESCALER
 * @brief This macro defines the APB2 clock prescaler
 * @details This macro defines the APB2 clock prescaler
 * @see RCC_APBPrescaler
 */
#define RCC_APB2_PRESCALER (RCC_APBPrescaler_NotDivided)

/**
 * @def RCC_USB_PRESCALER
 * @brief This macro defines the USB clock prescaler
 * @details This macro defines the USB clock prescaler
 * @see RCC_USBPrescaler
 */
#define RCC_USB_PRESCALER (RCC_USBPrescaler_1)

/**
 * @def RCC_ENABLE_CSS
 * @brief This macro defines the clock security system state
 * @details This macro defines the clock security system state
 * Options:
 * 	- FALSE: CSS disabled
 * 	- TRUE: CSS enabled
 */
#define RCC_ENABLE_CSS (FALSE)

/** @} */
/** @} */
/** @} */

#endif /* _RCC_CONFIG_H_ */
