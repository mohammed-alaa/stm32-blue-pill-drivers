/**
 * @file EXTI_program.c
 * @author Mohamed Alaa
 * @version 1.0.0
 * @brief This file contains the implementation for the EXTI module.
 * @details This file contains the implementation for the EXTI module.
 * @date 2023-07-07
 */

#include "../../LIB/LSTD_TYPES.h"
#include "../../LIB/LSTD_VALUES.h"
#include "../../LIB/LSTD_BITMATH.h"
#include "EXTI_private.h"
#include "EXTI_interface.h"
#include "EXTI_config.h"

/**
 * @brief This function sets the interrupt status of a certain line.
 * @details This function sets the interrupt status of a certain line.
 *
 * @param[in] tLine The line to set its interrupt status.
 * @param[in] bStatus The status to set the line to.
 */
STATIC void EXTI_vSetLineInterruptStatus(t_EXTI_Lines tLine, t_bool bStatus)
{
	if (bStatus == TRUE)
	{
		SET_BIT(EXTI.IMR, tLine);
	}
	else
	{
		CLEAR_BIT(EXTI.IMR, tLine);
	}
}

/**
 * @brief This function sets the event status of a certain line.
 * @details This function sets the event status of a certain line.
 *
 * @param[in] tLine The line to set its event status.
 * @param[in] bStatus The status to set the line to.
 */
STATIC void EXTI_vSetLineEventStatus(t_EXTI_Lines tLine, t_bool bStatus)
{
	if (bStatus == TRUE)
	{
		SET_BIT(EXTI.EMR, tLine);
	}
	else
	{
		CLEAR_BIT(EXTI.EMR, tLine);
	}
}

/**
 * @brief This function sets the line trigger mode to rising.
 * @details This function sets the line trigger mode to rising.
 *
 * @param[in] tLine The line to set its trigger mode.
 * @param[in] bStatus The status to set the line to.
 */
STATIC void EXTI_vSetLineTriggerModeRising(t_EXTI_Lines tLine, t_bool bStatus)
{
	if (bStatus == TRUE)
	{
		SET_BIT(EXTI.RTSR, tLine);
	}
	else
	{
		CLEAR_BIT(EXTI.RTSR, tLine);
	}
}

/**
 * @brief This function sets the trigger mode of a certain line to falling.
 * @details This function sets the trigger mode of a certain line to falling.
 *
 * @param[in] tLine The line to set its trigger mode to falling.
 * @param[in] bStatus The status to set the line to.
 */
STATIC void EXTI_vSetLineTriggerModeFalling(t_EXTI_Lines tLine, t_bool bStatus)
{
	if (bStatus == TRUE)
	{
		SET_BIT(EXTI.FTSR, tLine);
	}
	else
	{
		CLEAR_BIT(EXTI.FTSR, tLine);
	}
}

void EXTI_vEnableLineInterrupt(t_EXTI_Lines tLine, t_EXTI_TriggerMode tMode)
{
	EXTI_vSetLineInterruptStatus(tLine, TRUE);
	EXTI_vSetLineTriggerMode(tLine, tMode);
}

void EXTI_vDisableLineInterrupt(t_EXTI_Lines tLine)
{
	EXTI_vSetLineInterruptStatus(tLine, FALSE);
	EXTI_vSetLineTriggerMode(tLine, EXTI_TriggerMode_None);
}

void EXTI_vEnableLineEvent(t_EXTI_Lines tLine, t_EXTI_TriggerMode tMode)
{
	EXTI_vSetLineEventStatus(tLine, TRUE);
	EXTI_vSetLineTriggerMode(tLine, tMode);
}

void EXTI_vDisableLineEvent(t_EXTI_Lines tLine)
{
	EXTI_vSetLineEventStatus(tLine, FALSE);
	EXTI_vSetLineTriggerMode(tLine, EXTI_TriggerMode_None);
}

void EXTI_vSetLineTriggerMode(t_EXTI_Lines tLine, t_EXTI_TriggerMode tMode)
{
	if (tMode & EXTI_TriggerMode_Rising)
	{
		EXTI_vSetLineTriggerModeRising(tLine, TRUE);
	}
	else
	{
		EXTI_vSetLineTriggerModeRising(tLine, FALSE);
	}

	if (tMode & EXTI_TriggerMode_Falling)
	{
		EXTI_vSetLineTriggerModeFalling(tLine, TRUE);
	}
	else
	{
		EXTI_vSetLineTriggerModeFalling(tLine, FALSE);
	}
}

void EXTI_vSetLineSoftwareInterruptEvent(t_EXTI_Lines tLine)
{
	SET_BIT(EXTI.SWIER, tLine);
}

t_bool EXTI_bIsLineTriggered(t_EXTI_Lines tLine)
{
	/* This variable is used to store the status of the line. */
	t_bool bTriggered = GET_BIT(EXTI.PR, tLine) ? TRUE : FALSE;

	return bTriggered;
}

void EXTI_vClearLinePendingStatus(t_EXTI_Lines tLine)
{
	SET_BIT(EXTI.PR, tLine);
}
