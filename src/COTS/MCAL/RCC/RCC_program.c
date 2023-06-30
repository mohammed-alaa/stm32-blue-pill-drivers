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

	if (RCC_ENABLE_CSS == TRUE)
	{
		/* Enable CSS */
		RCC.CR.CSSON = TRUE;
	}
	else
	{
		/* Disable CSS */
		RCC.CR.CSSON = FALSE;
	}
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
 * @param[in] enuPeripheral Peripheral to enable/disable its clock
 * @param[in] bStatus Enable/Disable peripheral clock
 * @see RCC_APB2Peripherals
 */
STATIC void RCC_vSetAPB2PeripheralClockStatus(t_RCC_APB2Peripherals enuPeripheral, t_bool bStatus)
{
	switch (enuPeripheral)
	{
	case RCC_APB2Peripherals_AFIO:
		RCC_SET_REGISTER_BIT_STATUS(APB2ENR, AFIOEN, bStatus);
		break;
	case RCC_APB2Peripherals_PORTA:
		RCC_SET_REGISTER_BIT_STATUS(APB2ENR, IOPAEN, bStatus);
		break;
	case RCC_APB2Peripherals_PORTB:
		RCC_SET_REGISTER_BIT_STATUS(APB2ENR, IOPBEN, bStatus);
		break;
	case RCC_APB2Peripherals_PORTC:
		RCC_SET_REGISTER_BIT_STATUS(APB2ENR, IOPCEN, bStatus);
		break;
	case RCC_APB2Peripherals_PORTD:
		RCC_SET_REGISTER_BIT_STATUS(APB2ENR, IOPDEN, bStatus);
		break;
	case RCC_APB2Peripherals_PORTE:
		RCC_SET_REGISTER_BIT_STATUS(APB2ENR, IOPEEN, bStatus);
		break;
	case RCC_APB2Peripherals_PORTF:
		RCC_SET_REGISTER_BIT_STATUS(APB2ENR, IOPFEN, bStatus);
		break;
	case RCC_APB2Peripherals_PORTG:
		RCC_SET_REGISTER_BIT_STATUS(APB2ENR, IOPGEN, bStatus);
		break;
	case RCC_APB2Peripherals_ADC1:
		RCC_SET_REGISTER_BIT_STATUS(APB2ENR, ADC1EN, bStatus);
		break;
	case RCC_APB2Peripherals_ADC2:
		RCC_SET_REGISTER_BIT_STATUS(APB2ENR, ADC2EN, bStatus);
		break;
	case RCC_APB2Peripherals_TIM1:
		RCC_SET_REGISTER_BIT_STATUS(APB2ENR, TIM1EN, bStatus);
		break;
	case RCC_APB2Peripherals_SPI1:
		RCC_SET_REGISTER_BIT_STATUS(APB2ENR, SPI1EN, bStatus);
		break;
	case RCC_APB2Peripherals_USART1:
		RCC_SET_REGISTER_BIT_STATUS(APB2ENR, USART1EN, bStatus);
		break;
	case RCC_APB2Peripherals_ADC3:
		RCC_SET_REGISTER_BIT_STATUS(APB2ENR, ADC3EN, bStatus);
		break;
	default:
		/* Do nothing */
		break;
	}
}

/**
 * @brief This function initializes a certain peripheral clock on APB1 bus
 * @details This function initializes a certain peripheral clock on APB1 bus
 * @param[in] enuPeripheral Peripheral to enable/disable its clock
 * @param[in] bStatus Enable/Disable peripheral clock
 * @see t_RCC_APB1Peripherals
 */
STATIC void RCC_vSetAPB1PeripheralClockStatus(t_RCC_APB1Peripherals enuPeripheral, t_bool bStatus)
{
	switch (enuPeripheral)
	{
	case RCC_APB1Peripherals_TIM2:
		RCC_SET_REGISTER_BIT_STATUS(APB1ENR, TIM2EN, bStatus);
		break;
	case RCC_APB1Peripherals_TIM3:
		RCC_SET_REGISTER_BIT_STATUS(APB1ENR, TIM3EN, bStatus);
		break;
	case RCC_APB1Peripherals_TIM4:
		RCC_SET_REGISTER_BIT_STATUS(APB1ENR, TIM4EN, bStatus);
		break;
	case RCC_APB1Peripherals_TIM5:
		RCC_SET_REGISTER_BIT_STATUS(APB1ENR, TIM5EN, bStatus);
		break;
	case RCC_APB1Peripherals_TIM6:
		RCC_SET_REGISTER_BIT_STATUS(APB1ENR, TIM6EN, bStatus);
		break;
	case RCC_APB1Peripherals_TIM7:
		RCC_SET_REGISTER_BIT_STATUS(APB1ENR, TIM7EN, bStatus);
		break;
	case RCC_APB1Peripherals_WWDG:
		RCC_SET_REGISTER_BIT_STATUS(APB1ENR, WWDGEN, bStatus);
		break;
	case RCC_APB1Peripherals_SPI2:
		RCC_SET_REGISTER_BIT_STATUS(APB1ENR, SPI2EN, bStatus);
		break;
	case RCC_APB1Peripherals_SPI3:
		RCC_SET_REGISTER_BIT_STATUS(APB1ENR, SPI3EN, bStatus);
		break;
	case RCC_APB1Peripherals_USART2:
		RCC_SET_REGISTER_BIT_STATUS(APB1ENR, USART2EN, bStatus);
		break;
	case RCC_APB1Peripherals_USART3:
		RCC_SET_REGISTER_BIT_STATUS(APB1ENR, USART3EN, bStatus);
		break;
	case RCC_APB1Peripherals_UART4:
		RCC_SET_REGISTER_BIT_STATUS(APB1ENR, UART4EN, bStatus);
		break;
	case RCC_APB1Peripherals_UART5:
		RCC_SET_REGISTER_BIT_STATUS(APB1ENR, UART5EN, bStatus);
		break;
	case RCC_APB1Peripherals_I2C1:
		RCC_SET_REGISTER_BIT_STATUS(APB1ENR, I2C1EN, bStatus);
		break;
	case RCC_APB1Peripherals_I2C2:
		RCC_SET_REGISTER_BIT_STATUS(APB1ENR, I2C2EN, bStatus);
		break;
	case RCC_APB1Peripherals_USB:
		RCC_SET_REGISTER_BIT_STATUS(APB1ENR, USBEN, bStatus);
		break;
	case RCC_APB1Peripherals_CAN:
		RCC_SET_REGISTER_BIT_STATUS(APB1ENR, CANEN, bStatus);
		break;
	case RCC_APB1Peripherals_BKP:
		RCC_SET_REGISTER_BIT_STATUS(APB1ENR, BKPEN, bStatus);
		break;
	case RCC_APB1Peripherals_PWR:
		RCC_SET_REGISTER_BIT_STATUS(APB1ENR, PWREN, bStatus);
		break;
	case RCC_APB1Peripherals_DAC:
		RCC_SET_REGISTER_BIT_STATUS(APB1ENR, DACEN, bStatus);
		break;
	default:
		/* Do nothing */
		break;
	}
}

/**
 * @brief This function initializes a certain peripheral clock on AHB bus
 * @details This function initializes a certain peripheral clock on AHB bus
 * @param[in] enuPeripheral Peripheral to enable/disable its clock
 * @param[in] bStatus Enable/Disable peripheral clock
 * @see t_RCC_AHBPeripherals
 */
STATIC void RCC_vSetAHBPeripheralClockStatus(t_RCC_AHBPeripherals enuPeripheral, t_bool bStatus)
{
	switch (enuPeripheral)
	{
	case RCC_AHBPeripherals_DMA1:
		RCC_SET_REGISTER_BIT_STATUS(AHBENR, DMA1EN, bStatus);
		break;
	case RCC_AHBPeripherals_DMA2:
		RCC_SET_REGISTER_BIT_STATUS(AHBENR, DMA2EN, bStatus);
		break;
	case RCC_AHBPeripherals_CRC:
		RCC_SET_REGISTER_BIT_STATUS(AHBENR, CRCEN, bStatus);
		break;
	default:
		/* Do nothing */
		break;
	}
}

/**
 * @brief This function sets the ADC prescaler
 * @details This function sets the ADC prescaler to be used by ADC
 */
STATIC void RCC_vSetADCPreScaler(void)
{
	/* Set ADC prescaler */
	RCC.CFGR.ADCPRE = RCC_ADC_PRESCALER;
}

/**
 * @brief This function sets the USB prescaler
 * @details This function sets the USB prescaler to be used by USB
 */
STATIC void RCC_vSetUSBPrescaler(void)
{
	/* Set USB prescaler */
	RCC.CFGR.USBPRE = RCC_USB_PRESCALER;
}

/**
 * @brief This function sets the AHB prescaler
 * @details This function sets the AHB prescaler to be used by AHB bus
 */
STATIC void RCC_vSetAHBPrescaler(void)
{
	/* Set AHB prescaler */
	RCC.CFGR.HPRE = RCC_AHB_PRESCALER;
}

/**
 * @brief This function sets the APB1 prescaler
 * @details This function sets the APB1 prescaler to be used by APB1 bus
 */
STATIC void RCC_vSetAPB1Prescaler(void)
{
	/* Set APB1 prescaler */
	RCC.CFGR.PPRE1 = RCC_APB1_PRESCALER;
}

/**
 * @brief This function sets the APB2 prescaler
 * @details This function sets the APB2 prescaler to be used by APB2 bus
 */
STATIC void RCC_vSetAPB2Prescaler(void)
{
	/* Set APB2 prescaler */
	RCC.CFGR.PPRE2 = RCC_APB2_PRESCALER;
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
	RCC_vSetAHBPrescaler();
	RCC_vSetAPB1Prescaler();
	RCC_vSetAPB2Prescaler();
	RCC_vSetADCPreScaler();
	RCC_vSetUSBPrescaler();
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

void RCC_vEnablePeripheralAHB(t_RCC_AHBPeripherals enuPeripheral)
{
	RCC_vSetAHBPeripheralClockStatus(enuPeripheral, TRUE);
}

void RCC_vDisablePeripheralAHB(t_RCC_AHBPeripherals enuPeripheral)
{
	RCC_vSetAHBPeripheralClockStatus(enuPeripheral, FALSE);
}
