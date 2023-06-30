/**
 * @file APPS_main.c
 * @author Mohamed Alaa
 * @brief This file contains the implementation of the main function that is responsible for running the applications
 * @version 1.0.0
 * @date 2023-06-16
 */

#include "APPS_main.h"
#include "../COTS/MCAL/RCC/RCC_interface.h"

/**
 * @brief This macro is used to define the main function of the application
 * @details This macro is used to define the main function of the application
 * @param[in] APP_NAME The name of the application
 **/
#define TESTING_APPLICATION_MAIN_FUNC(APP_NAME) vTestApp_##APP_NAME##_main()

#define TestingGPIO

#if defined TestingGPIO
#include "TestingGPIO/TestApp_TestingGPIO_main.h"
#endif

void vAPPS_main(void)
{
	RCC_vInit();
	TESTING_APPLICATION_MAIN_FUNC(TestingGPIO);

	for (;;)
	{
		/* Do nothing */
	}
}
