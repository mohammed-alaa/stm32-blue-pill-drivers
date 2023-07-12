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

#include "../../LIB/LSTD_TYPES.h"

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
	GPIO_Ports_A = 0,
	/**
	 * @brief GPIO Port B
	 */
	GPIO_Ports_B,
	/**
	 * @brief GPIO Port C
	 */
	GPIO_Ports_C,
	/**
	 * @brief GPIO Port D
	 */
	GPIO_Ports_D,
	/**
	 * @brief GPIO Port E
	 */
	GPIO_Ports_E,
	/**
	 * @brief GPIO Port F
	 */
	GPIO_Ports_F,
	/**
	 * @brief GPIO Port G
	 */
	GPIO_Ports_G
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
	GPIO_Pins_0 = 0,
	/**
	 * @brief GPIO Pin 1
	 */
	GPIO_Pins_1,
	/**
	 * @brief GPIO Pin 2
	 */
	GPIO_Pins_2,
	/**
	 * @brief GPIO Pin 3
	 */
	GPIO_Pins_3,
	/**
	 * @brief GPIO Pin 4
	 */
	GPIO_Pins_4,
	/**
	 * @brief GPIO Pin 5
	 */
	GPIO_Pins_5,
	/**
	 * @brief GPIO Pin 6
	 */
	GPIO_Pins_6,
	/**
	 * @brief GPIO Pin 7
	 */
	GPIO_Pins_7,
	/**
	 * @brief GPIO Pin 8
	 */
	GPIO_Pins_8,
	/**
	 * @brief GPIO Pin 9
	 */
	GPIO_Pins_9,
	/**
	 * @brief GPIO Pin 10
	 */
	GPIO_Pins_10,
	/**
	 * @brief GPIO Pin 11
	 */
	GPIO_Pins_11,
	/**
	 * @brief GPIO Pin 12
	 */
	GPIO_Pins_12,
	/**
	 * @brief GPIO Pin 13
	 */
	GPIO_Pins_13,
	/**
	 * @brief GPIO Pin 14
	 */
	GPIO_Pins_14,
	/**
	 * @brief GPIO Pin 15
	 */
	GPIO_Pins_15
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
	GPIO_Direction_Input = 0,
	/**
	 * @brief GPIO Pin Output with max speed of 10 MHz
	 */
	GPIO_Direction_Output_10MHz,
	/**
	 * @brief GPIO Pin Output with max speed of 2 MHz
	 */
	GPIO_Direction_Output_2MHz,
	/**
	 * @brief GPIO Pin Output with max speed of 50 MHz
	 */
	GPIO_Direction_Output_50MHz
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
	GPIO_Output_Type_Push_Pull = 0,
	/**
	 * @brief GPIO Pin Output Type: open-drain
	 */
	GPIO_Output_Type_Open_Drain,
	/**
	 * @brief GPIO Pin Output Type: alternate push-pull
	 */
	GPIO_Output_Type_Alternate_Push_Pull,
	/**
	 * @brief GPIO Pin Output Type: alternate open-drain
	 */
	GPIO_Output_Type_Alternate_Open_Drain
} t_GPIO_Output_Type;

/**
 * @enum t_GPIO_Input_Type
 * @brief GPIO Input Type
 * @details This type is used to select a GPIO pin input type
 */
typedef enum
{
	/**
	 * @brief GPIO Pin Input Type: Analog
	 */
	GPIO_Input_Type_Analog = 0,
	/**
	 * @brief GPIO Pin Input Type: Floating
	 */
	GPIO_Input_Type_Floating,
	/**
	 * @brief GPIO Pin Input Type: Pull-Down
	 */
	GPIO_Input_Type_Pull_Down,
	/**
	 * @brief GPIO Pin Input Type: Pull-Up
	 */
	GPIO_Input_Type_Pull_Up
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
	GPIO_Value_Low = 0,
	/**
	 * @brief GPIO Pin Value: HIGH (1)
	 */
	GPIO_Value_High
} t_GPIO_Value;

/**
 * @enum t_AFIO_Timer2_Remap
 * @brief Enumeration to hold the possible remap configurations of timer 2
 * @details The enumeration holds the possible remap configurations of timer 2
 */
typedef enum
{
	/**
	 * @brief No remap (CH1/ETR/PA0, CH2/PA1, CH3/PA2, CH4/PA3)
	 */
	AFIO_Timer2_Remap_None = 0,
	/**
	 * @brief Partial remap 1 (CH1/ETR/PA15, CH2/PB3, CH3/PA2, CH4/PA3)
	 */
	AFIO_Timer2_Remap_Partial1,
	/**
	 * @brief Partial remap 2 (CH1/ETR/PA0, CH2/PA1, CH3/PB10, CH4/PB11)
	 */
	AFIO_Timer2_Remap_Partial2,
	/**
	 * @brief Full remap (CH1/ETR/PA15, CH2/PB3, CH3/PB10, CH4/PB11)
	 */
	AFIO_Timer2_Remap_Full
} t_AFIO_Timer2_Remap;

/**
 * @enum t_AFIO_SWJ_Remap
 * @brief Enumeration to hold the possible remapping options for the SWJ pins
 */
typedef enum
{
	/**
	 * @brief Full SWJ (JTAG-DP + SW-DP): Reset State
	 */
	AFIO_SWJ_Remap_JTAG_DP_SW_DP_Reset_State = 0,
	/**
	 * @brief Full SWJ (JTAG-DP + SW-DP) but without NJTRST
	 */
	AFIO_SWJ_Remap_JTAG_DP_SW_DP_But_Without_NJTRST,
	/**
	 * @brief JTAG-DP Disabled and SW-DP Enabled
	 */
	AFIO_SWJ_Remap_JTAG_DP_Disabled_SW_DP_Enabled,
	/**
	 * @brief JTAG-DP Disabled and SW-DP Disabled
	 */
	AFIO_SWJ_Remap_JTAG_DP_Disabled_SW_DP_Disabled
} t_AFIO_SWJ_Remap;

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

/**
 * @brief This function is used to initialize the cortex event for a GPIO pin
 * @details This function is used to initialize the cortex event for a GPIO pin
 * @param[in] tPort The GPIO port
 * @param[in] tPin The GPIO pin
 * @see t_GPIO_Ports t_GPIO_Pins
 */
void GPIO_AFIO_vInitCortexEvent(t_GPIO_Ports tPort, t_GPIO_Pins tPin);

/**
 * @brief This function is used to configure the EXTI line for a GPIO pin
 * @details This function is used to configure the EXTI line for a GPIO pin
 * @param[in] tPort The GPIO port
 * @param[in] tPin The GPIO pin
 * @see t_GPIO_Ports t_GPIO_Pins
 */
void GPIO_AFIO_vConfigEXTILine(t_GPIO_Ports tPort, t_GPIO_Pins tPin);

/**
 * @brief This function is used to remap the SPI1 pins
 * @details This function is used to remap the SPI1 pins.\n
 * This bit controls the mapping of SPI1 NSS, SCK, MISO, MOSI alternate functions on the GPIO ports.\n
 * Remaping options:
 * - FALSE: No remap (NSS/PA4, SCK/PA5, MISO/PA6, MOSI/PA7)
 * - TRUE: Remap (NSS/PA15, SCK/PB3, MISO/PB4, MOSI/PB5)
 *
 * @param[in] bRemap TRUE to remap, FALSE to not remap
 */
void GPIO_AFIO_vRemapSPI1(t_bool bRemap);

/**
 * @brief This function is used to remap the I2C1 pins
 * @details This function is used to remap the I2C1 pins.
 * This bit controls the mapping of I2C1 SCL and SDA alternate functions on the GPIO ports.\n
 * Remaping options:
 * - FALSE: No remap (SCL/PB6, SDA/PB7)
 * - TRUE: Remap (SCL/PB8, SDA/PB9)
 * @param[in] bRemap TRUE to remap, FALSE to not remap
 */
void GPIO_AFIO_vRemapI2C1(t_bool bRemap);

/**
 * @brief This function is used to remap the timer1 pins
 * @details This function is used to remap the timer1 pins.
 * This bit controls the mapping of TIM1 channels 1 to 4, 1N to 3N, external trigger (ETR) and Break input (BKIN) alternate functions on the GPIO ports.\n
 * Remaping options:
 * - FALSE: No remap (ETR/PA12, CH1/PA8, CH2/PA9, CH3/PA10, CH4/PA11, CH1N/PB13, CH2N/PB14, CH3N/PB15, BKIN/PB12)
 * - TRUE: Partial remap (ETR/PA12, CH1/PA8, CH2/PA9, CH3/PA10, CH4/PA11, CH1N/PA7, CH2N/PB0, CH3N/PB1, BKIN/PA6)
 * @param[in] bRemap TRUE to remap, FALSE to not remap
 */
void GPIO_AFIO_vRemapTimer1(t_bool bRemap);

/**
 * @brief This function is used to remap the timer2 pins
 * @details This function is used to remap the timer2 pins.
 * @param[in] tTimer2Remap The timer2 remap option
 * @see t_AFIO_Timer2_Remap
 */
void GPIO_AFIO_vRemapTimer2(t_AFIO_Timer2_Remap tTimer2Remap);

/**
 * @brief This function is used to remap the timer3 pins
 * @details This function is used to remap the timer3 pins.\n
 * This bit controls the mapping of TIM3 channels 1 to 4 alternate functions on the GPIO ports.\n
 * Remaping options:
 * - FALSE: No remap (CH1/PA6, CH2/PA7, CH3/PB0, CH4/PB1)
 * - TRUE: Partial remap (CH1/PB4, CH2/PB5, CH3/PB0, CH4/PB1)
 * @param[in] bRemap TRUE to remap, FALSE to not remap
 */
void GPIO_AFIO_vRemapTimer3(t_bool bRemap);

/**
 * @brief This function is used to remap the CAN pins
 * @details This function is used to remap the CAN pins.\n
 * This bit controls the mapping of CAN RX and TX alternate functions on the GPIO ports.\n
 * Remaping options:
 * - FALSE: No remap (RX/PA11, TX/PA12)
 * - TRUE: Remap (RX/PB8, TX/PB9)
 * @param[in] bRemap TRUE to remap, FALSE to not remap
 */
void GPIO_AFIO_vRemapCan(t_bool bRemap);

/**
 * @brief This function is used to remap the PortD0 and PortD1 pins
 * @details This function is used to remap the PortD0 and PortD1 pins to OSC_IN and OSC_OUT.\n
 * Remaping options:
 * - FALSE: No remap
 * - TRUE: Remap (OSC_IN/PD0, OSC_OUT/PD1)
 * @param[in] bRemap TRUE to remap, FALSE to not remap
 */
void GPIO_AFIO_vRemapPD01(t_bool bRemap);

/**
 * @brief This function is used to remap the Serial wire JTAG pins
 * @details This function is used to remap the Serial wire JTAG pins.\n
 * @param[in] tSWJRemap The SWJ remap option
 * @see t_AFIO_SWJ_Remap
 */
void GPIO_AFIO_vRemapSWJ(t_AFIO_SWJ_Remap tSWJRemap);

/** @} */
/** @} */
#endif /* _GPIO_INTERFACE_H_ */
