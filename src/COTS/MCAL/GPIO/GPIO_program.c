/**
 * @file GPIO_program.c
 * @author Mohamed Alaa
 * @version 1.0.0
 * @brief This file contains the implementation for the GPIO module.
 * @details This file contains the implementation for the GPIO module.
 * @date 2023-06-25
 */

#include "../../LIB/LSTD_TYPES.h"
#include "../../LIB/LSTD_BITMATH.h"
#include "../../LIB/LSTD_COMPILER.h"
#include "../../LIB/LSTD_VALUES.h"
#include "GPIO_private.h"
#include "GPIO_interface.h"
#include "GPIO_config.h"

/**
 * @brief This function gets the base address of a GPIO port
 * @details This function gets the base address of a GPIO port
 * @param[in] tPort The GPIO port to get its base address
 * @param[out] pu32PortBaseAddress The base address of the GPIO port
 */
STATIC void GPIO_vGetPortAddress(t_GPIO_Ports tPort, P2VAR(P2VAR(t_GPIOx_RegisterMap)) ppu32PortBaseAddress)
{
	P2VAR(t_GPIOx_RegisterMap)
	pu32PortBaseAddress = NULL;

	switch (tPort)
	{
	case t_GPIO_Ports_A:
		pu32PortBaseAddress = &GPIO_A;
		break;
	case t_GPIO_Ports_B:
		pu32PortBaseAddress = &GPIO_B;
		break;
	case t_GPIO_Ports_C:
		pu32PortBaseAddress = &GPIO_C;
		break;
	case t_GPIO_Ports_D:
		pu32PortBaseAddress = &GPIO_D;
		break;
	case t_GPIO_Ports_E:
		pu32PortBaseAddress = &GPIO_E;
		break;
	case t_GPIO_Ports_F:
		pu32PortBaseAddress = &GPIO_F;
		break;
	case t_GPIO_Ports_G:
		pu32PortBaseAddress = &GPIO_G;
		break;
	default:
		break;
	}
}

void GPIO_vSetPinDirection(t_GPIO_Ports tPort, t_GPIO_Pins tPin, t_GPIO_Direction tDirection)
{
	P2VAR(t_GPIOx_CR_Mode_CNF_x)
	MODE_CNF_x = NULL;
	P2VAR(t_GPIOx_RegisterMap)
	pu32PortBaseAddress = NULL;
	GPIO_vGetPortAddress(tPort, &pu32PortBaseAddress);

	if (tPin <= t_GPIO_Pins_7)
	{
		MODE_CNF_x = (P2VAR(t_GPIOx_CR_Mode_CNF_x))(&pu32PortBaseAddress->CRL + (tPin * 4));
	}
	else
	{
		MODE_CNF_x = (P2VAR(t_GPIOx_CR_Mode_CNF_x))(&pu32PortBaseAddress->CRH + (tPin * 4));
	}

	t_u8 u8PinSpan = (tPin * 2);
	t_u8 u8DefaultPinType = 0;

	// Set the mode bits of the pin
	MODE_CNF_x->MODE = ((MODE_CNF_x->MODE & ~(0b11 << u8PinSpan)) | (tDirection << u8PinSpan));

	// Set the default configuration bits of the pin
	u8DefaultPinType = (tDirection == t_GPIO_Direction_Input) ? DEFAULT_PIN_INPUT_TYPE : DEFAULT_PIN_OUTPUT_TYPE;
	// Set the configuration bits of the pin
	MODE_CNF_x->CNF = (MODE_CNF_x->CNF & ~(0b11 << u8PinSpan)) | (u8DefaultPinType << u8PinSpan);
}

void GPIO_vSetPinInputType(t_GPIO_Ports tPort, t_GPIO_Pins tPin, t_GPIO_Input_Type tInputType)
{
	P2VAR(t_GPIOx_CR_Mode_CNF_x)
	MODE_CNF_x = NULL;
	P2VAR(t_GPIOx_RegisterMap)
	pu32PortBaseAddress = NULL;
	GPIO_vGetPortAddress(tPort, &pu32PortBaseAddress);

	if (tPin <= t_GPIO_Pins_7)
	{
		MODE_CNF_x = (P2VAR(t_GPIOx_CR_Mode_CNF_x))(&pu32PortBaseAddress->CRL + (tPin * 4));
	}
	else
	{
		MODE_CNF_x = (P2VAR(t_GPIOx_CR_Mode_CNF_x))(&pu32PortBaseAddress->CRH + (tPin * 4));
	}

	MODE_CNF_x->CNF &= ~(0b11 << (tPin * 2));
	MODE_CNF_x->CNF &= ~(tInputType << (tPin * 2));
}
