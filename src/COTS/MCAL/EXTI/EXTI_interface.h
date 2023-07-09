/**
 * @file EXTI_interface.h
 * @author Mohamed Alaa
 * @version 1.0.0
 * @brief This file is the interface file for the EXTI module.
 * @details This file contains the prototypes of the functions of the EXTI module.
 * @date 2023-07-07
 */

#ifndef _EXTI_INTERFACE_H_
#define _EXTI_INTERFACE_H_

#include "../../LIB/LSTD_TYPES.h"
#include "../../LIB/LSTD_VALUES.h"

/**
 * @addtogroup mcal
 * @{
 */

/**
 * @addtogroup exti_module
 * @{
 */

/**
 * @enum t_EXTI_Lines
 * @brief This enum contains the EXTI lines
 * @details This enum contains the EXTI lines
 */
typedef enum
{
	/**
	 * @brief EXTI Line 0
	 */
	EXTI_Lines_0 = 0,
	/**
	 * @brief EXTI Line 1
	 */
	EXTI_Lines_1,
	/**
	 * @brief EXTI Line 2
	 */
	EXTI_Lines_2,
	/**
	 * @brief EXTI Line 3
	 */
	EXTI_Lines_3,
	/**
	 * @brief EXTI Line 4
	 */
	EXTI_Lines_4,
	/**
	 * @brief EXTI Line 5
	 */
	EXTI_Lines_5,
	/**
	 * @brief EXTI Line 6
	 */
	EXTI_Lines_6,
	/**
	 * @brief EXTI Line 7
	 */
	EXTI_Lines_7,
	/**
	 * @brief EXTI Line 8
	 */
	EXTI_Lines_8,
	/**
	 * @brief EXTI Line 9
	 */
	EXTI_Lines_9,
	/**
	 * @brief EXTI Line 10
	 */
	EXTI_Lines_10,
	/**
	 * @brief EXTI Line 11
	 */
	EXTI_Lines_11,
	/**
	 * @brief EXTI Line 12
	 */
	EXTI_Lines_12,
	/**
	 * @brief EXTI Line 13
	 */
	EXTI_Lines_13,
	/**
	 * @brief EXTI Line 14
	 */
	EXTI_Lines_14,
	/**
	 * @brief EXTI Line 15
	 */
	EXTI_Lines_15,
	/**
	 * @brief EXTI Line 16
	 * @note EXTI Line 16 is connected to the PVD output
	 */
	EXTI_Lines_16,
	/**
	 * @brief EXTI Line 17
	 * @note EXTI Line 17 is connected to the RTC Alarm event
	 */
	EXTI_Lines_17,
	/**
	 * @brief EXTI Line 18
	 * @note EXTI Line 18 is connected to the USB Wakeup from suspend event
	 */
	EXTI_Lines_18,
	/**
	 * @brief EXTI Line_Numebr
	 */
	EXTI_Lines_Number
} t_EXTI_Lines;

/**
 * @enum t_EXTI_TriggerMode
 * @brief This enum contains the EXTI trigger types
 * @details This enum contains the EXTI trigger types
 */
typedef enum
{
	/**
	 * @brief No trigger
	 */
	EXTI_TriggerMode_None = 0,
	/**
	 * @brief Rising edge trigger
	 */
	EXTI_TriggerMode_Rising,
	/**
	 * @brief Falling edge trigger
	 */
	EXTI_TriggerMode_Falling,
	/**
	 * @brief Rising and falling edge trigger
	 */
	EXTI_TriggerMode_Rising_Falling
} t_EXTI_TriggerMode;

/**
 * @brief This function enables the interrupt of a certain line.
 * @details This function enables the interrupt of a certain line.
 *
 * @param[in] tLine The line to enable its interrupt.
 * @param[in] tMode The mode to set the line to.
 * @see t_EXTI_Lines t_EXTI_TriggerMode
 */
void EXTI_vEnableLineInterrupt(t_EXTI_Lines tLine, t_EXTI_TriggerMode tMode);

/**
 * @brief This function disables the interrupt of a certain line.
 * @details This function disables the interrupt of a certain line.
 *
 * @param[in] tLine The line to disable its interrupt.
 * @see t_EXTI_Lines t_EXTI_TriggerMode
 */
void EXTI_vDisableLineInterrupt(t_EXTI_Lines tLine);

/**
 * @brief This function enables the event of a certain line.
 * @details This function enables the event of a certain line.
 *
 * @param[in] tLine The line to enable its event.
 * @param[in] tMode The mode to set the line to.
 * @see t_EXTI_Lines t_EXTI_TriggerMode
 */
void EXTI_vEnableLineEvent(t_EXTI_Lines tLine, t_EXTI_TriggerMode tMode);

/**
 * @brief This function disables the event of a certain line.
 * @details This function disables the event of a certain line.
 *
 * @param[in] tLine The line to disable its event.
 * @see t_EXTI_Lines t_EXTI_TriggerMode
 */
void EXTI_vDisableLineEvent(t_EXTI_Lines tLine);

/**
 * @brief This function sets the trigger mode of a certain line.
 * @details This function sets the trigger mode of a certain line.
 *
 * @param[in] tLine The line to set its trigger mode.
 * @param[in] tMode The mode to set the line to.
 * @see t_EXTI_Lines t_EXTI_TriggerMode
 */
void EXTI_vSetLineTriggerMode(t_EXTI_Lines tLine, t_EXTI_TriggerMode tMode);

/**
 * @brief This function sets the software interrupt event of a certain line.
 * @details This function sets the software interrupt event of a certain line.
 *
 * @param[in] tLine The line to set its software interrupt event.
 * @see t_EXTI_Lines
 */
void EXTI_vSetLineSoftwareInterruptEvent(t_EXTI_Lines tLine);

/**
 * @brief This function checks if a certain line is triggered.
 * @details This function checks if a certain line is triggered based on its configured trigger mode.
 *
 * @param[in] tLine The line to check its trigger status.
 *
 * @return t_bool Whether the line is triggered or not.
 * @see t_EXTI_Lines
 */
t_bool EXTI_bIsLineTriggered(t_EXTI_Lines tLine);

/**
 * @brief This function clears the pending status of a certain line.
 * @details This function clears the pending status of a certain line.
 *
 * @param[in] tLine The line to clear its interrupt status.
 */
void EXTI_vClearLinePendingStatus(t_EXTI_Lines tLine);

/** @} */
/** @} */

#endif /* _EXTI_INTERFACE_H_ */
