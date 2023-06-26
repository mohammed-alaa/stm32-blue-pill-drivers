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

/**
 * @typedef t_GPIO_Direction
 * @brief GPIO Direction
 * @details This type is used to select a GPIO pin direction
 */
typedef enum
{
	/**
	 * @brief GPIO Pin Input
	 */
	t_GPIO_Direction_Input = 0,
	/**
	 * @brief GPIO Pin Output with max speed of 10 MHz
	 */
	t_GPIO_Direction_Output_10MHz,
	/**
	 * @brief GPIO Pin Output with max speed of 2 MHz
	 */
	t_GPIO_Direction_Output_2MHz,
	/**
	 * @brief GPIO Pin Output with max speed of 50 MHz
	 */
	t_GPIO_Direction_Output_50MHz
} t_GPIO_Direction;

/**
 * @typedef t_GPIO_Output_Type
 * @brief GPIO Output Type
 * @details This type is used to select a GPIO pin output type
 */
typedef enum
{
	/**
	 * @brief GPIO Pin Output Type: push-pull
	 */
	t_GPIO_Output_Type_Push_Pull = 0,
	/**
	 * @brief GPIO Pin Output Type: open-drain
	 */
	t_GPIO_Output_Type_Open_Drain,
	/**
	 * @brief GPIO Pin Output Type: alternate push-pull
	 */
	t_GPIO_Output_Type_Alternate_Push_Pull,
	/**
	 * @brief GPIO Pin Output Type: alternate open-drain
	 */
	t_GPIO_Output_Type_Alternate_Open_Drain
} t_GPIO_Output_Type;

/**
 * @enum t_GPIO_Input_Type
 * @brief GPIO Input Type
 * @details This type is used to select a GPIO pin input type
 */
typedef enum
{
	/**
	 * @brief GPIO Pin Input Type: analog
	 */
	t_GPIO_Input_Type_Analog = 0,
	/**
	 * @brief GPIO Pin Input Type: floating
	 */
	t_GPIO_Input_Type_Floating,
	/**
	 * @brief GPIO Pin Input Type: pull-up / pull-down
	 */
	t_GPIO_Input_Type_Pull_Up_Down
} t_GPIO_Input_Type;

/**
 * @enum t_GPIO_Value
 * @brief GPIO Pin Value
 * @details This type is used to select a GPIO pin value
 */
typedef enum
{
	/**
	 * @brief GPIO Pin Value: LOW (0)
	 */
	t_GPIO_Value_Low = 0,
	/**
	 * @brief GPIO Pin Value: HIGH (1)
	 */
	t_GPIO_Value_High
} t_GPIO_Value;

/**
 * @brief This function is used to set the direction of a GPIO pin
 * @details This function is used to set the direction of a GPIO pin
 * @param[in] tPort The GPIO port
 * @param[in] tPin The GPIO pin
 * @param[in] tDirection The GPIO pin direction
 * @see t_GPIO_Ports t_GPIO_Pins t_GPIO_Direction
 */
void GPIO_vSetPinDirection(t_GPIO_Ports tPort, t_GPIO_Pins tPin, t_GPIO_Direction tDirection);

/**
 * @brief This function is used to set the input type of a GPIO pin
 * @details This function is used to set the input type of a GPIO pin
 * @param[in] tPort The GPIO port
 * @param[in] tPin The GPIO pin
 * @param[in] tInputType The GPIO pin input type
 * @see t_GPIO_Ports t_GPIO_Pins t_GPIO_Input_Type
 */
void GPIO_vSetPinInputType(t_GPIO_Ports tPort, t_GPIO_Pins tPin, t_GPIO_Input_Type tInputType);

/**
 * @brief This function is used to set the output type of a GPIO pin
 * @details This function is used to set the output type of a GPIO pin
 * @param[in] tPort The GPIO port
 * @param[in] tPin The GPIO pin
 * @param[in] tOutputType The GPIO pin output type
 * @see t_GPIO_Ports t_GPIO_Pins t_GPIO_Output_Type
 */
void GPIO_vSetPinOutputType(t_GPIO_Ports tPort, t_GPIO_Pins tPin, t_GPIO_Output_Type tOutputType);

/**
 * @brief This function is used to set the value of a GPIO pin
 * @details This function is used to set the value of a GPIO pin
 * @param[in] tPort The GPIO port
 * @param[in] tPin The GPIO pin
 * @param[in] tValue The GPIO pin value
 * @see t_GPIO_Ports t_GPIO_Pins t_GPIO_Value
 */
void GPIO_vSetPinValue(t_GPIO_Ports tPort, t_GPIO_Pins tPin, t_GPIO_Value tValue);

/**
 * @brief This function is used to get the value of a GPIO pin
 * @details This function is used to get the value of a GPIO pin
 * @param[in] tPort The GPIO port
 * @param[in] tPin The GPIO pin
 * @return The GPIO pin value
 * @see t_GPIO_Ports t_GPIO_Pins t_GPIO_Value
 */
t_GPIO_Value GPIO_tGetPinValue(t_GPIO_Ports tPort, t_GPIO_Pins tPin);

/** @} */
/** @} */
#endif /* _GPIO_INTERFACE_H_ */
