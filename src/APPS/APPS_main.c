/**
 * @file APPS_main.c
 * @author Mohamed Alaa
 * @brief This file contains the implementation of the main function that is responsible for running the applications
 * @version 1.0.0
 * @date 2023-06-16
 */

#include "APPS_main.h"

/**
 * @brief Change this to the macro of the desired application to run
 **/
#define TestingGPIO

#if defined TestingGPIO
#include "TestingGPIO/TestApp_TestingGPIO_main.h"
#endif

void vAPPS_main(void)
{
#ifdef TestingGPIO
	vTestApp_TestingGPIO_main();
#endif

	for (;;)
	{
		/* Do nothing */
	}
}
