/**
 * @file EXTI_private.h
 * @author Mohamed Alaa
 * @version 1.0.0
 * @brief This file contains the private macros and registers for the EXTI module.
 * @details This file contains the private macros and registers for the EXTI module.
 * @date 2023-07-07
 */

/**
 * @dir EXTI
 * @brief EXTI Module
 * @details EXTI (External Interrupt) Module is used to handle the external interrupts.
 */

#ifndef _EXTI_PRIVATE_H_
#define _EXTI_PRIVATE_H_

#include "../../LIB/LSTD_HW_REGS.h"
#include "../../LIB/LSTD_TYPES.h"

/**
 * @addtogroup mcal
 * @{
 */

/**
 * @defgroup exti_module EXTI Module
 * @brief EXTI Module
 * @details EXTI (External Interrupt) Module is used to handle the external interrupts.
 * @{
 */

/**
 * @defgroup exti_registers EXTI Registers
 * @brief EXTI Registers
 * @{
 */

/**
 * @struct t_EXTI_RegisterMap
 * @brief EXTI Register Map
 */
typedef struct
{
	/**
	 * @brief Interrupt Mask Register
	 */
	t_u32 IMR;
	/**
	 * @brief Event Mask Register
	 */
	t_u32 EMR;
	/**
	 * @brief Rising Trigger Selection Register
	 */
	t_u32 RTSR;
	/**
	 * @brief Falling Trigger Selection Register
	 */
	t_u32 FTSR;
	/**
	 * @brief Software Interrupt Event Register
	 */
	t_u32 SWIER;
	/**
	 * @brief Pending Register
	 */
	t_u32 PR;
} t_EXTI_RegisterMap;

/** @} */

/**
 * @defgroup exti_addresses EXTI Registers Addresses
 * @brief EXTI Registers Addresses
 * @{
 */

/**
 * @def EXTI_BASE_ADDRESS
 * @brief EXTI Base Address
 */
#define EXTI_BASE_ADDRESS REGISTER_ADDRESS(0x40010400, 0)

/**
 * @def EXTI
 * @brief EXTI Registers
 */
#define EXTI REGISTER(t_EXTI_RegisterMap, EXTI_BASE_ADDRESS)

/**
 * @enum enuEXTI_SpecialLines
 * @brief EXTI Special Lines
 * @details EXTI Special Lines are the lines that are not connected to the GPIOs.
 */
enum enuEXTI_SpecialLines
{
	/**
	 * @brief Line 16
	 * @details Line 16 is connected to the PVD output
	 */
	EXTI_LINE_16_PVD_OUTPUT = 16,
	/**
	 * @brief Line 17
	 * @details Line 17 is connected to the RTC Alarm event
	 */
	EXTI_LINE_17_RTC_ALARM,
	/**
	 * @brief Line 18
	 * @details Line 18 is connected to the USB OTG FS Wakeup event
	 */
	EXTI_LINE_18_USB_OTG_FS_WAKEUP,
};

/** @} */
/** @} */
/** @} */

#endif /* _EXTI_PRIVATE_H_ */
