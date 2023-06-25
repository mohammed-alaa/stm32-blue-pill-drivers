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

#define DEFAULT_PIN_INPUT_TYPE	(t_GPIO_Input_Type_Floating)
#define DEFAULT_PIN_OUTPUT_TYPE	(t_GPIO_Output_Type_Push_Pull)

/** @} */
/** @} */

#endif /* _GPIO_CONFIG_H_ */
