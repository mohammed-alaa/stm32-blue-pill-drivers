/**
 * @file TestApp_TestingEXTI_main.c
 * @author Mohamed Alaa
 * @version 1.0.0
 * @brief This file contains the main implementation for the TestApp_TestingEXTI application.
 * @details This file contains the main implementation for the TestApp_TestingEXTI application.
 * @date 2023-07-12
 */

#include "../../COTS/LIB/LSTD_COMPILER.h"
#include "../../COTS/MCAL/RCC/RCC_interface.h"
#include "../../COTS/MCAL/GPIO/GPIO_interface.h"
#include "../../COTS/MCAL/EXTI/EXTI_interface.h"
#include "TestApp_TestingEXTI_main.h"

STATIC void vTestApp_TestingEXTI_ToggleLed(void)
{
	t_u32 u32Counter = 0;
	GPIO_vSetPinValue(GPIO_Ports_A, GPIO_Pins_1, GPIO_Value_High);
	for (u32Counter = 0; u32Counter < 10000000; u32Counter++)
		;
	GPIO_vSetPinValue(GPIO_Ports_A, GPIO_Pins_1, GPIO_Value_Low);
	for (u32Counter = 0; u32Counter < 10000000; u32Counter++)
		;
}

void vTestApp_TestingEXTI_main(void)
{
	RCC_vEnablePeripheralABP2(RCC_APB2Peripherals_AFIO);
	RCC_vEnablePeripheralABP2(RCC_APB2Peripherals_PORTA);
	RCC_vEnablePeripheralABP2(RCC_APB2Peripherals_PORTB);

	GPIO_vSetPinDirection(GPIO_Ports_A, GPIO_Pins_1, GPIO_Direction_Output_10MHz);

	GPIO_vSetPinDirection(GPIO_Ports_B, GPIO_Pins_7, GPIO_Direction_Input);
	GPIO_vSetPinInputType(GPIO_Ports_B, GPIO_Pins_7, GPIO_Input_Type_Pull_Up);
	GPIO_AFIO_vConfigEXTILine(GPIO_Ports_B, GPIO_Pins_7);

	EXTI_vEnableLineInterrupt(EXTI_Lines_0, EXTI_TriggerMode_Falling, vTestApp_TestingEXTI_ToggleLed);

	for (;;)
	{
		/* Do nothing */
	}
}
