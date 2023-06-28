/**
 * @file TestApp_TestingGPIO_main.c
 * @author Mohamed Alaa
 * @version 1.0.0
 * @brief This file contains the main implementation for the TestApp_TestingGPIO application.
 * @details This file contains the main implementation for the TestApp_TestingGPIO application.
 * @date 2023-06-25
 */

#include "TestApp_TestingGPIO_main.h"
#include "../../COTS/LIB/LSTD_TYPES.h"
#include "../../COTS/MCAL/RCC/RCC_interface.h"
#include "../../COTS/MCAL/GPIO/GPIO_interface.h"

void vTestApp_TestingGPIO_main(void)
{
	// t_u32 u32Counter = 0;
	RCC_vEnablePeripheralABP2(RCC_APB2Peripherals_PORTA);
	RCC_vEnablePeripheralABP2(RCC_APB2Peripherals_PORTB);
	GPIO_vSetPinDirection(GPIO_Ports_A, GPIO_Pins_1, GPIO_Direction_Output_10MHz);
	GPIO_vSetPinDirection(GPIO_Ports_B, GPIO_Pins_7, GPIO_Direction_Input);
	GPIO_vSetPinInputType(GPIO_Ports_B, GPIO_Pins_7, GPIO_Input_Type_Pull_Down);
	// GPIO_vSetPinInputType(GPIO_Ports_B, GPIO_Pins_7, GPIO_Input_Type_Pull_Up);

	for (;;)
	{
		if (GPIO_tGetPinValue(GPIO_Ports_B, GPIO_Pins_7) == GPIO_Value_High)
		{
			GPIO_vSetPinValue(GPIO_Ports_A, GPIO_Pins_1, GPIO_Value_High);
		}
		else
		{
			GPIO_vSetPinValue(GPIO_Ports_A, GPIO_Pins_1, GPIO_Value_Low);
		}

		// GPIO_vSetPinValue(GPIO_Ports_A, GPIO_Pins_1, GPIO_Value_High);
		// for (u32Counter = 0; u32Counter < 10000000; u32Counter++)
		// 	;
		// GPIO_vSetPinValue(GPIO_Ports_A, GPIO_Pins_1, GPIO_Value_Low);
		// for (u32Counter = 0; u32Counter < 10000000; u32Counter++)
		// 	;
	}
}
