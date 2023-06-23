/**
 * @file RCC_program.c
 * @author Mohamed Alaa
 * @version 1.0.0
 * @brief This file contains the implementation for the RCC module.
 * @details This file contains the implementation for the RCC module.
 * @date 2023-06-18
 */

#include "../../LIB/LSTD_TYPES.h"
#include "../../LIB/LSTD_BITMATH.h"
#include "../../LIB/LSTD_COMPILER.h"
#include "../../LIB/LSTD_VALUES.h"
#include "RCC_private.h"
#include "RCC_interface.h"
#include "RCC_config.h"

/**
 * @brief This function initializes the HSE clock
 * @details This function initializes the HSE clock and waits until it is ready
 */
STATIC void RCC_vInitHSEClock(void)
{
	/* Enable HSE bypass */
	RCC.CR.HSEBYP = TRUE;
	/* Enable HSE */
	RCC.CR.HSEON = TRUE;
	/* Wait until HSE is ready */
	while (RCC.CR.HSERDY == FALSE)
		;
}

/**
 * @brief This function initializes the HSI clock
 * @details This function initializes the HSI clock and waits until it is ready
 */
STATIC void RCC_vInitHSIClock(void)
{
	/* Enable HSI */
	RCC.CR.HSION = TRUE;
	/* Wait until HSI is ready */
	while (RCC.CR.HSIRDY == FALSE)
		;
}

/**
 * @brief This function initializes the PLL clock
 * @details This function initializes the PLL clock and waits until it is ready
 */
STATIC void RCC_vInitPLL(void)
{
	if (RCC_PLL_SRC == RCC_PLLSource_HSE)
	{
		RCC_vInitHSEClock();
	}
	else if (RCC_PLL_SRC == RCC_PLLSource_HSI_DividedBy2)
	{
		RCC_vInitHSIClock();
	}
	else
	{
		/* Do nothing */
	}

	/* Set PLL source to HSE */
	RCC.CFGR.PLLSRC = RCC_PLL_SRC;
	/* Set PLL multiplication factor */
	RCC.CFGR.PLLMUL = RCC_PLL_MUL;
	/* Set PLL entry HSE divider */
	RCC.CFGR.PLLXTPRE = RCC_PLL_HSE_DIVIDE_BY_2;
	/* Enable PLL */
	RCC.CR.PLLON = TRUE;
	/* Wait until PLL is ready */
	while (RCC.CR.PLLRDY == FALSE)
		;
}

/**
 * @brief This function initializes the system clock
 * @details This function initializes the system clock
 */
STATIC void RCC_vInitSystemClock(void)
{
	/* Set system clock source */
	RCC.CFGR.SW = RCC_SYSTEM_CLOCK_SOURCE;
	/* Wait until system clock source is set */
	while (RCC.CFGR.SWS != RCC_SYSTEM_CLOCK_SOURCE)
		;
}

/**
 * @brief This function initializes the MCO
 * @details This function initializes the MCO (Microcontroller Clock Output) and waits until it is ready
 */
STATIC void RCC_vInitMCO(void)
{
	/* Set MCO source */
	RCC.CFGR.MCO = RCC_MCO_SOURCE;
}

/**
 * @brief This function initializes a certain peripheral clock on APB2 bus
 * @details This function initializes a certain peripheral clock on APB2 bus
 * @param enuPeripheral Peripheral to enable/disable its clock
 * @param bStatus Enable/Disable peripheral clock
 * @see RCC_APB2Peripherals
 */
STATIC void RCC_vSetAPB2PeripheralClockStatus(t_RCC_APB2Peripherals enuPeripheral, t_bool bStatus)
{
	switch (enuPeripheral)
	{
	case RCC_APB2Peripherals_AFIO:
		SETREGISTERBITSTATUS(APB2ENR, AFIOEN, bStatus);
		break;
	case RCC_APB2Peripherals_PORTA:
		SETREGISTERBITSTATUS(APB2ENR, IOPAEN, bStatus);
		break;
	case RCC_APB2Peripherals_PORTB:
		SETREGISTERBITSTATUS(APB2ENR, IOPBEN, bStatus);
		break;
	case RCC_APB2Peripherals_PORTC:
		SETREGISTERBITSTATUS(APB2ENR, IOPCEN, bStatus);
		break;
	case RCC_APB2Peripherals_PORTD:
		SETREGISTERBITSTATUS(APB2ENR, IOPDEN, bStatus);
		break;
	case RCC_APB2Peripherals_PORTE:
		SETREGISTERBITSTATUS(APB2ENR, IOPEEN, bStatus);
		break;
	case RCC_APB2Peripherals_PORTF:
		SETREGISTERBITSTATUS(APB2ENR, IOPFEN, bStatus);
		break;
	case RCC_APB2Peripherals_PORTG:
		SETREGISTERBITSTATUS(APB2ENR, IOPGEN, bStatus);
		break;
	case RCC_APB2Peripherals_ADC1:
		SETREGISTERBITSTATUS(APB2ENR, ADC1EN, bStatus);
		break;
	case RCC_APB2Peripherals_ADC2:
		SETREGISTERBITSTATUS(APB2ENR, ADC2EN, bStatus);
		break;
	case RCC_APB2Peripherals_TIM1:
		SETREGISTERBITSTATUS(APB2ENR, TIM1EN, bStatus);
		break;
	case RCC_APB2Peripherals_SPI1:
		SETREGISTERBITSTATUS(APB2ENR, SPI1EN, bStatus);
		break;
	case RCC_APB2Peripherals_USART1:
		SETREGISTERBITSTATUS(APB2ENR, USART1EN, bStatus);
		break;
	case RCC_APB2Peripherals_ADC3:
		SETREGISTERBITSTATUS(APB2ENR, ADC3EN, bStatus);
		break;
	default:
		/* Do nothing */
		break;
	}
}

/**
 * @brief This function initializes a certain peripheral clock on APB1 bus
 * @details This function initializes a certain peripheral clock on APB1 bus
 * @param enuPeripheral Peripheral to enable/disable its clock
 * @param bStatus Enable/Disable peripheral clock
 * @see t_RCC_APB1Peripherals
 */
STATIC void RCC_vSetAPB1PeripheralClockStatus(t_RCC_APB1Peripherals enuPeripheral, t_bool bStatus)
{
	switch (enuPeripheral)
	{
	case RCC_APB1Peripherals_TIM2:
		SETREGISTERBITSTATUS(APB1ENR, TIM2EN, bStatus);
		break;
	case RCC_APB1Peripherals_TIM3:
		SETREGISTERBITSTATUS(APB1ENR, TIM3EN, bStatus);
		break;
	case RCC_APB1Peripherals_TIM4:
		SETREGISTERBITSTATUS(APB1ENR, TIM4EN, bStatus);
		break;
	case RCC_APB1Peripherals_TIM5:
		SETREGISTERBITSTATUS(APB1ENR, TIM5EN, bStatus);
		break;
	case RCC_APB1Peripherals_TIM6:
		SETREGISTERBITSTATUS(APB1ENR, TIM6EN, bStatus);
		break;
	case RCC_APB1Peripherals_TIM7:
		SETREGISTERBITSTATUS(APB1ENR, TIM7EN, bStatus);
		break;
	case RCC_APB1Peripherals_WWDG:
		SETREGISTERBITSTATUS(APB1ENR, WWDGEN, bStatus);
		break;
	case RCC_APB1Peripherals_SPI2:
		SETREGISTERBITSTATUS(APB1ENR, SPI2EN, bStatus);
		break;
	case RCC_APB1Peripherals_SPI3:
		SETREGISTERBITSTATUS(APB1ENR, SPI3EN, bStatus);
		break;
	case RCC_APB1Peripherals_USART2:
		SETREGISTERBITSTATUS(APB1ENR, USART2EN, bStatus);
		break;
	case RCC_APB1Peripherals_USART3:
		SETREGISTERBITSTATUS(APB1ENR, USART3EN, bStatus);
		break;
	case RCC_APB1Peripherals_UART4:
		SETREGISTERBITSTATUS(APB1ENR, UART4EN, bStatus);
		break;
	case RCC_APB1Peripherals_UART5:
		SETREGISTERBITSTATUS(APB1ENR, UART5EN, bStatus);
		break;
	case RCC_APB1Peripherals_I2C1:
		SETREGISTERBITSTATUS(APB1ENR, I2C1EN, bStatus);
		break;
	case RCC_APB1Peripherals_I2C2:
		SETREGISTERBITSTATUS(APB1ENR, I2C2EN, bStatus);
		break;
	case RCC_APB1Peripherals_USB:
		SETREGISTERBITSTATUS(APB1ENR, USBEN, bStatus);
		break;
	case RCC_APB1Peripherals_CAN:
		SETREGISTERBITSTATUS(APB1ENR, CANEN, bStatus);
		break;
	case RCC_APB1Peripherals_BKP:
		SETREGISTERBITSTATUS(APB1ENR, BKPEN, bStatus);
		break;
	case RCC_APB1Peripherals_PWR:
		SETREGISTERBITSTATUS(APB1ENR, PWREN, bStatus);
		break;
	case RCC_APB1Peripherals_DAC:
		SETREGISTERBITSTATUS(APB1ENR, DACEN, bStatus);
		break;
	default:
		/* Do nothing */
		break;
	}
}

void RCC_vInit(void)
{
	if (RCC_SYSTEM_CLOCK_SOURCE == RCC_SystemClock_HSE)
	{
		RCC_vInitHSEClock();
	}
	else if (RCC_SYSTEM_CLOCK_SOURCE == RCC_SystemClock_HSI)
	{
		RCC_vInitHSIClock();
	}
	else if (RCC_SYSTEM_CLOCK_SOURCE == RCC_SystemClock_PLL)
	{
		RCC_vInitPLL();
	}
	else
	{
		/* Do nothing */
	}

	RCC_vInitSystemClock();
	RCC_vInitMCO();
}

void RCC_vEnablePeripheralABP2(t_RCC_APB2Peripherals enuPeripheral)
{
	RCC_vSetAPB2PeripheralClockStatus(enuPeripheral, TRUE);
}

void RCC_vDisablePeripheralABP2(t_RCC_APB2Peripherals enuPeripheral)
{
	RCC_vSetAPB2PeripheralClockStatus(enuPeripheral, FALSE);
}

void RCC_vEnablePeripheralABP1(t_RCC_APB1Peripherals enuPeripheral)
{
	RCC_vSetAPB1PeripheralClockStatus(enuPeripheral, TRUE);
}

void RCC_vDisablePeripheralABP1(t_RCC_APB1Peripherals enuPeripheral)
{
	RCC_vSetAPB1PeripheralClockStatus(enuPeripheral, FALSE);
}
