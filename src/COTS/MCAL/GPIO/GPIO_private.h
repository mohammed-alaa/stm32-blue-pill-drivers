/**
 * @file GPIO_private.h
 * @author Mohamed Alaa
 * @version 1.0.0
 * @brief This file contains the private macros and registers for the GPIO module.
 * @details This file contains the private macros and registers for the GPIO module.
 * @date 2023-06-25
 */

/**
 * @dir MCAL/GPIO
 * @brief GPIO Module
 * @details This module contains all the APIs related to the GPIO module
 */

#ifndef _GPIO_PRIVATE_H_
#define _GPIO_PRIVATE_H_

#include "../../LIB/LSTD_TYPES.h"
#include "../../LIB/LSTD_HW_REGS.h"

/**
 * @addtogroup mcal
 * @{
 */

/**
 * @defgroup gpio_module GPIO Module
 * @brief GPIO Module
 * @details This module contains all the APIs related to the GPIO module
 * @{
 */

/**
 * @defgroup gpio_registers GPIO Registers
 * @brief GPIO Registers
 * @{
 */

/**
 * @struct t_GPIOx_RegisterMap
 * @brief GPIO Register Map
 * @details This type is used to access the GPIO registers
 */
typedef struct
{
	/**
	 * @brief Port Configuration Register Low
	 */
	t_u32 CRL;
	/**
	 * @brief Port Configuration Register High
	 */
	t_u32 CRH;
	/**
	 * @brief Port Input Data Register
	 * @warning This register is read-only
	 */
	t_u32 IDR;
	/**
	 * @brief Port Output Data Register
	 */
	t_u32 ODR;
	/**
	 * @brief Port Bit Set/Reset Register
	 */
	t_u32 BSRR;
	/**
	 * @brief Port Bit Reset Register
	 */
	t_u32 BRR;
} t_GPIOx_RegisterMap;

/** @} */

/**
 * @defgroup afio_registers AFIO Registers
 * @brief AFIO Registers
 * @{
 */

/**
 * @struct t_EVCR
 * @brief Event Control Register
 * @details This type is used to access the EVCR register
 */
typedef struct
{
	/**
	 * @brief Pin selection
	 * @details This field specifies the pin to be used as the Event Output.
	 */
	t_u32 PIN : 4;
	/**
	 * @brief Port selection
	 * @details This field specifies the port to be used as the Event Output.
	 */
	t_u32 PORT : 3;
	/**
	 * @brief Event Output Enable
	 * @details This bit enables the Event Output.
	 */
	t_u32 EVOE : 1;
	/**
	 * @brief Reserved bit(s)
	 * @attention This field is reserved and must be kept at reset value.
	 */
	t_u32 : 24;
} t_EVCR;

/**
 * @struct t_MAPR
 * @brief AF remap and debug I/O configuration register
 * @details This type is used to access the MAPR register
 */
typedef struct
{
	/**
	 * @brief SPI1 remapping
	 * @details This bit controls the mapping of SPI1 (NSS, SCK, MISO and MOSI) alternate functions on the GPIO ports
	 */
	t_u32 SPI1_REMAP : 1;
	/**
	 * @brief I2C1 remapping
	 * @details This bit controls the mapping of I2C1 (SDA and SCL) alternate functions on the GPIO ports
	 */
	t_u32 I2C1_REMAP : 1;
	/**
	 * @brief Reserved bit(s)
	 * @attention This field is reserved and must be kept at reset value.
	 */
	t_u32 : 3;
	/**
	 * @brief TIM1 remapping
	 * @details These bits control the mapping of TIM1 alternate functions on the GPIO ports
	 */
	t_u32 TIM1_REMAP : 2;
	/**
	 * @brief TIM2 remapping
	 * @details These bits control the mapping of TIM2 alternate functions on the GPIO ports
	 */
	t_u32 TIM2_REMAP : 2;
	/**
	 * @brief TIM3 remapping
	 * @details These bits control the mapping of TIM3 alternate functions on the GPIO ports
	 */
	t_u32 TIM3_REMAP : 2;
	/**
	 * @brief Reserved bit(s)
	 * @attention This field is reserved and must be kept at reset value.
	 */
	t_u32 : 1;
	/**
	 * @brief CAN remapping
	 * @details These bits control the mapping of CAN alternate functions on the GPIO ports
	 */
	t_u32 CAN_REMAP : 2;
	/**
	 * @brief Port D0/Port D1 mapping on OSCIN/OSCOUT
	 * @details These bits control the mapping of PD0 and PD1 alternate functions on the OSCIN and OSCOUT pins
	 */
	t_u32 PD01_REMAP : 1;
	/**
	 * @brief Reserved bit(s)
	 * @attention This field is reserved and must be kept at reset value.
	 */
	t_u32 : 8;
	/**
	 * @brief Serial wire JTAG configuration
	 * @details This bit controls the mapping of the JTAG pins (PA15, PB3, PB4 and PB5) on the GPIO ports
	 * @warning This field is write-only
	 */
	t_u32 SWJ_CFG : 3;
	/**
	 * @brief Reserved bit(s)
	 * @attention This field is reserved and must be kept at reset value.
	 */
	t_u32 : 5;
} t_MAPR;

/**
 * @struct t_AFIOx_RegisterMap
 * @brief AFIO Register Map
 * @details This type is used to access the AFIO registers
 */
typedef struct
{
	/**
	 * @brief Event Control Register
	 */
	t_EVCR EVCR;
	/**
	 * @brief Remap and debug I/O configuration register
	 */
	t_MAPR MAPR;
	/**
	 * @brief External interrupt configuration register 1
	 */
	t_u32 EXTICR[4];
} t_AFIOx_RegisterMap;

/** @} */

/**
 * @defgroup gpio_addresses GPIO Addresses
 * @brief GPIO Addresses
 * @details This module contains the addresses of the GPIO registers
 * @{
 */

/**
 * @def BASE_ADDRESS_PORT_A
 * @brief Base Address of Port A
 */
#define BASE_ADDRESS_PORT_A REGISTER_ADDRESS(0x40010800, 0)

/**
 * @def GPIO_A
 * @brief GPIO Port A
 */
#define GPIO_A REGISTER(t_GPIOx_RegisterMap, BASE_ADDRESS_PORT_A)

/**
 * @def BASE_ADDRESS_PORT_B
 * @brief Base Address of Port B
 */
#define BASE_ADDRESS_PORT_B REGISTER_ADDRESS(0x40010C00, 0)

/**
 * @def GPIO_B
 * @brief GPIO Port B
 */
#define GPIO_B REGISTER(t_GPIOx_RegisterMap, BASE_ADDRESS_PORT_B)

/**
 * @def BASE_ADDRESS_PORT_C
 * @brief Base Address of Port C
 */
#define BASE_ADDRESS_PORT_C REGISTER_ADDRESS(0x40011000, 0)

/**
 * @def GPIO_C
 * @brief GPIO Port C
 */
#define GPIO_C REGISTER(t_GPIOx_RegisterMap, BASE_ADDRESS_PORT_C)

/**
 * @def BASE_ADDRESS_PORT_D
 * @brief Base Address of Port D
 */
#define BASE_ADDRESS_PORT_D REGISTER_ADDRESS(0x40011400, 0)

/**
 * @def GPIO_D
 * @brief GPIO Port D
 */
#define GPIO_D REGISTER(t_GPIOx_RegisterMap, BASE_ADDRESS_PORT_D)

/**
 * @def BASE_ADDRESS_PORT_E
 * @brief Base Address of Port E
 */
#define BASE_ADDRESS_PORT_E REGISTER_ADDRESS(0x40011800, 0)

/**
 * @def GPIO_E
 * @brief GPIO Port E
 */
#define GPIO_E REGISTER(t_GPIOx_RegisterMap, BASE_ADDRESS_PORT_E)

/**
 * @def BASE_ADDRESS_PORT_F
 * @brief Base Address of Port F
 */
#define BASE_ADDRESS_PORT_F REGISTER_ADDRESS(0x40011C00, 0)

/**
 * @def GPIO_F
 * @brief GPIO Port F
 */
#define GPIO_F REGISTER(t_GPIOx_RegisterMap, BASE_ADDRESS_PORT_F)

/**
 * @def BASE_ADDRESS_PORT_G
 * @brief Base Address of Port G
 */
#define BASE_ADDRESS_PORT_G REGISTER_ADDRESS(0x40012000, 0)

/**
 * @def GPIO_G
 * @brief GPIO Port G
 */
#define GPIO_G REGISTER(t_GPIOx_RegisterMap, BASE_ADDRESS_PORT_G)

/** @} */

/**
 * @defgroup afio_addresses AFIO Addresses
 * @brief AFIO Addresses
 * @details This module contains the addresses of the AFIO registers
 * @{
 */

/**
 * @def BASE_ADDRESS_AFIO
 * @brief Base Address of AFIO
 */
#define BASE_ADDRESS_AFIO REGISTER_ADDRESS(0x40010000, 0)

/**
 * @def AFIO
 * @brief AFIO (Alternate Function I/O)
 */
#define AFIO REGISTER(t_AFIOx_RegisterMap, BASE_ADDRESS_AFIO)

/** @} */

/**
 * @defgroup gpio_pins_constants GPIO Pins Constants
 * @brief GPIO Pins Constants
 * @details This module contains a set of constants used in configuring the GPIO pins in the configuration register (CRL or CRH)
 * @{
 */

/**
 * @def PIN_SHIFT_VALUE
 * @brief Pin Shift Value
 * @details This value is used to shift to the start of a specific pin in the configuration register (CRL or CRH)
 */
#define PIN_SHIFT_VALUE (4)

/**
 * @def PIN_RESET_MASK_VALUE
 * @brief Pin Reset Mask Value
 * @details This value is used to reset the mode and configuration bits of a certain pin
 */
#define PIN_RESET_MASK_VALUE ((t_u32)0x0000000FU)

/**
 * @def PIN_RESET_CONFIGURATION_MASK_VALUE
 * @brief Pin Reset Configuration Mask Value
 * @details This value is used to reset the configuration bits of a certain pin
 */
#define PIN_RESET_CONFIGURATION_MASK_VALUE ((t_u32)0x0000000CU)

/**
 * @def PIN_RESET_ODR_MASK_VALUE
 * @brief Pin Reset ODR Mask Value
 * @details This value is used to reset the ODR bit of a certain pin (in the BSRR register)
 */
#define PIN_RESET_ODR_MASK_VALUE ((t_u32)0x00000001U)

/**
 * @def PIN_CONFIGURATION_BITS_SHIFT_VALUE
 * @brief Pin Mode Bits Shift Value
 * @details This value is used to shift to the configuration bits of a certain pin
 */
#define PIN_CONFIGURATION_BITS_SHIFT_VALUE (2)

/**
 * @def PIN_RESET_SHIFT_VALUE
 * @brief Pin Reset Shift Value
 * @details This value is used to shift to the start of the position of the first pin bit in the BSRR register
 */
#define PIN_RESET_SHIFT_VALUE (16)

/**
 * @def PIN_RESET_MASK
 * @brief Pin Reset Mask
 * @details This mask is used to reset the mode and configuration bits of a certain pin
 * @param[in] GPIO_PIN_SPAN The span of the pin in the configuration register (CRL or CRH)
 */
#define PIN_RESET_MASK(GPIO_PIN_SPAN) ~(PIN_RESET_MASK_VALUE << GPIO_PIN_SPAN)

/**
 * @def PIN_RESET_CONFIGURATIONS_MASK
 * @brief Pin Reset Configurations Mask
 * @details This mask is used to reset the configuration bits of a certain pin
 * @param[in] GPIO_PIN_SPAN The span of the pin in the configuration register (CRL or CRH)
 */
#define PIN_RESET_CONFIGURATIONS_MASK(GPIO_PIN_SPAN) ~(PIN_RESET_CONFIGURATION_MASK_VALUE << GPIO_PIN_SPAN)

/**
 * @def PIN_RESET_ODR_MASK
 * @brief Pin Reset ODR Mask
 * @details This mask is used to reset the ODR bit of a certain pin (in the BSRR register)
 * @param[in] GPIO_PIN_SPAN The span of the pin in the configuration register (CRL or CRH)
 */
#define PIN_RESET_ODR_MASK(GPIO_PIN_SPAN) ~(PIN_RESET_ODR_MASK_VALUE << GPIO_PIN_SPAN)

/** @} */
/** @} */
/** @} */

#endif /* _GPIO_PRIVATE_H_ */
