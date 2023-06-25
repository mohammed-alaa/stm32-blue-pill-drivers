/**
 * @file GPIO_interface.h
 * @author Mohamed Alaa
 * @version 1.0.0
 * @brief This file is the interface file for the GPIO module.
 * @details This file contains the prototypes of the functions of the GPIO module.
 * @date 2023-06-25
 */

#ifndef _GPIO_INTERFACE_H_
#define _GPIO_INTERFACE_H_

/**
 * @addtogroup mcal
 * @{
 */

/**
 * @addtogroup gpio_module
 * @{
 */

/**
 * @typedef t_GPIO_Ports
 * @brief GPIO Ports
 * @details This type is used to select a GPIO port
 */
typedef enum
{
	/**
	 * @brief GPIO Port A
	 */
	t_GPIO_Ports_A = 0,
	/**
	 * @brief GPIO Port B
	 */
	t_GPIO_Ports_B,
	/**
	 * @brief GPIO Port C
	 */
	t_GPIO_Ports_C,
	/**
	 * @brief GPIO Port D
	 */
	t_GPIO_Ports_D,
	/**
	 * @brief GPIO Port E
	 */
	t_GPIO_Ports_E,
	/**
	 * @brief GPIO Port F
	 */
	t_GPIO_Ports_F,
	/**
	 * @brief GPIO Port G
	 */
	t_GPIO_Ports_G
} t_GPIO_Ports;

/**
 * @typedef t_GPIO_Pins
 * @brief GPIO Pins
 * @details This type is used to select a GPIO pin
 */
typedef enum
{
	/**
	 * @brief GPIO Pin 0
	 */
	t_GPIO_Pins_0 = 0,
	/**
	 * @brief GPIO Pin 1
	 */
	t_GPIO_Pins_1,
	/**
	 * @brief GPIO Pin 2
	 */
	t_GPIO_Pins_2,
	/**
	 * @brief GPIO Pin 3
	 */
	t_GPIO_Pins_3,
	/**
	 * @brief GPIO Pin 4
	 */
	t_GPIO_Pins_4,
	/**
	 * @brief GPIO Pin 5
	 */
	t_GPIO_Pins_5,
	/**
	 * @brief GPIO Pin 6
	 */
	t_GPIO_Pins_6,
	/**
	 * @brief GPIO Pin 7
	 */
	t_GPIO_Pins_7,
	/**
	 * @brief GPIO Pin 8
	 */
	t_GPIO_Pins_8,
	/**
	 * @brief GPIO Pin 9
	 */
	t_GPIO_Pins_9,
	/**
	 * @brief GPIO Pin 10
	 */
	t_GPIO_Pins_10,
	/**
	 * @brief GPIO Pin 11
	 */
	t_GPIO_Pins_11,
	/**
	 * @brief GPIO Pin 12
	 */
	t_GPIO_Pins_12,
	/**
	 * @brief GPIO Pin 13
	 */
	t_GPIO_Pins_13,
	/**
	 * @brief GPIO Pin 14
	 */
	t_GPIO_Pins_14,
	/**
	 * @brief GPIO Pin 15
	 */
	t_GPIO_Pins_15
} t_GPIO_Pins;

/** @} */
/** @} */
#endif /* _GPIO_INTERFACE_H_ */
