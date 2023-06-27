/**
 * @file GPIO_config.h
 * @author Mohamed Alaa
 * @version 1.0.0
 * @brief This file contains the configuration parameters for the GPIO module.
 * @details This file contains the configuration parameters for the GPIO module.
 * @date 2023-06-25
 */

#ifndef _GPIO_CONFIG_H_
#define _GPIO_CONFIG_H_

#include "GPIO_interface.h"

/**
 * @addtogroup mcal
 * @{
 */

/**
 * @addtogroup gpio_module
 * @{
 */

/**
 * @def DEFAULT_PIN_INPUT_TYPE
 * @brief The default input type for the GPIO pins
 * @details This macro defines the default input type for the GPIO pins
 */
#define DEFAULT_PIN_INPUT_TYPE (GPIO_Input_Type_Floating)

/**
 * @def DEFAULT_PIN_OUTPUT_TYPE
 * @brief The default output type for the GPIO pins
 * @details This macro defines the default output type for the GPIO pins
 */
#define DEFAULT_PIN_OUTPUT_TYPE (GPIO_Output_Type_Push_Pull)

/** @} */
/** @} */

#endif /* _GPIO_CONFIG_H_ */
