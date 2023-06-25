/**
 * @file GPIO_private.h
 * @author Mohamed Alaa
 * @version 1.0.0
 * @brief This file contains the private macros and registers for the GPIO module.
 * @details This file contains the private macros and registers for the GPIO module.
 * @date 2023-06-25
 */

/**
 * @dir GPIO
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
 * @struct t_GPIOx_CR_Mode_CNF_x
 * @brief Pin Mode and Configuration
 * @details This type is used to configure the mode and configuration of a pin.
 */
typedef struct
{
	/**
	 * @brief Pin Mode
	 */
	t_u32 MODE : 2;
	/**
	 * @brief Pin Configuration
	 */
	t_u32 CNF : 2;
} t_GPIOx_CR_Mode_CNF_x;

/**
 * @struct t_GPIOx_CRL
 * @brief Port Configuration Register Low
 * @details This type is used to configure the mode and configuration of the low pins of a port
 */
typedef struct
{
	/**
	 * @brief Pin Mode and Configuration for pin 0
	 */
	t_GPIOx_CR_Mode_CNF_x MODE_CNF_0;
	/**
	 * @brief Pin Mode and Configuration for pin 1
	 */
	t_GPIOx_CR_Mode_CNF_x MODE_CNF_1;
	/**
	 * @brief Pin Mode and Configuration for pin 2
	 */
	t_GPIOx_CR_Mode_CNF_x MODE_CNF_2;
	/**
	 * @brief Pin Mode and Configuration for pin 3
	 */
	t_GPIOx_CR_Mode_CNF_x MODE_CNF_3;
	/**
	 * @brief Pin Mode and Configuration for pin 4
	 */
	t_GPIOx_CR_Mode_CNF_x MODE_CNF_4;
	/**
	 * @brief Pin Mode and Configuration for pin 5
	 */
	t_GPIOx_CR_Mode_CNF_x MODE_CNF_5;
	/**
	 * @brief Pin Mode and Configuration for pin 6
	 */
	t_GPIOx_CR_Mode_CNF_x MODE_CNF_6;
	/**
	 * @brief Pin Mode and Configuration for pin 7
	 */
	t_GPIOx_CR_Mode_CNF_x MODE_CNF_7;
} t_GPIOx_CRL;

/**
 * @struct t_GPIOx_CRH
 * @brief Port Configuration Register High
 * @details This type is used to configure the mode and configuration of the high pins of a port
 */
typedef struct
{
	/**
	 * @brief Pin Mode and Configuration for pin 8
	 */
	t_GPIOx_CR_Mode_CNF_x MODE_CNF_8;
	/**
	 * @brief Pin Mode and Configuration for pin 9
	 */
	t_GPIOx_CR_Mode_CNF_x MODE_CNF_9;
	/**
	 * @brief Pin Mode and Configuration for pin 10
	 */
	t_GPIOx_CR_Mode_CNF_x MODE_CNF_10;
	/**
	 * @brief Pin Mode and Configuration for pin 11
	 */
	t_GPIOx_CR_Mode_CNF_x MODE_CNF_11;
	/**
	 * @brief Pin Mode and Configuration for pin 12
	 */
	t_GPIOx_CR_Mode_CNF_x MODE_CNF_12;
	/**
	 * @brief Pin Mode and Configuration for pin 13
	 */
	t_GPIOx_CR_Mode_CNF_x MODE_CNF_13;
	/**
	 * @brief Pin Mode and Configuration for pin 14
	 */
	t_GPIOx_CR_Mode_CNF_x MODE_CNF_14;
	/**
	 * @brief Pin Mode and Configuration for pin 15
	 */
	t_GPIOx_CR_Mode_CNF_x MODE_CNF_15;
} t_GPIOx_CRH;

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
	t_GPIOx_CRL CRL;
	/**
	 * @brief Port Configuration Register High
	 */
	t_GPIOx_CRH CRH;
	/**
	 * @brief Port Input Data Register
	 * @warning This register is read-only
	 */
	t_u32 IDRx;
	/**
	 * @brief Port Output Data Register
	 */
	t_u32 ODRx;
} t_GPIOx_RegisterMap;

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
#define BASE_ADDRESS_PORT_A REGISTER_ADDRESS(0x40010800)

/**
 * @def GPIO_A
 * @brief GPIO Port A
 */
#define GPIO_A REGISTER(t_GPIOx_RegisterMap, BASE_ADDRESS_PORT_A)

/**
 * @def BASE_ADDRESS_PORT_B
 * @brief Base Address of Port B
 */
#define BASE_ADDRESS_PORT_B REGISTER_ADDRESS(0x40010C00)

/**
 * @def GPIO_B
 * @brief GPIO Port B
 */
#define GPIO_B REGISTER(t_GPIOx_RegisterMap, BASE_ADDRESS_PORT_B)

/**
 * @def BASE_ADDRESS_PORT_C
 * @brief Base Address of Port C
 */
#define BASE_ADDRESS_PORT_C REGISTER_ADDRESS(0x40011000)

/**
 * @def GPIO_C
 * @brief GPIO Port C
 */
#define GPIO_C REGISTER(t_GPIOx_RegisterMap, BASE_ADDRESS_PORT_C)

/**
 * @def BASE_ADDRESS_PORT_D
 * @brief Base Address of Port D
 */
#define BASE_ADDRESS_PORT_D REGISTER_ADDRESS(0x40011400)

/**
 * @def GPIO_D
 * @brief GPIO Port D
 */
#define GPIO_D REGISTER(t_GPIOx_RegisterMap, BASE_ADDRESS_PORT_D)

/**
 * @def BASE_ADDRESS_PORT_E
 * @brief Base Address of Port E
 */
#define BASE_ADDRESS_PORT_E REGISTER_ADDRESS(0x40011800)

/**
 * @def GPIO_E
 * @brief GPIO Port E
 */
#define GPIO_E REGISTER(t_GPIOx_RegisterMap, BASE_ADDRESS_PORT_E)

/**
 * @def BASE_ADDRESS_PORT_F
 * @brief Base Address of Port F
 */
#define BASE_ADDRESS_PORT_F REGISTER_ADDRESS(0x40011C00)

/**
 * @def GPIO_F
 * @brief GPIO Port F
 */
#define GPIO_F REGISTER(t_GPIOx_RegisterMap, BASE_ADDRESS_PORT_F)

/** @} */
/** @} */
/** @} */

#endif /* _GPIO_PRIVATE_H_ */
