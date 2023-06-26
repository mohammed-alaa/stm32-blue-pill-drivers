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
 * @def IS_PIN_IN_LOW_REGISTER
 * @brief Check if the pin is in the low register
 * @details This macro checks if the pin is in the low register (CRL)
 * @param[in] GPIO_PIN_SPAN The span of the pin in the configuration register (CRL or CRH)
 */
#define IS_PIN_IN_LOW_REGISTER(GPIO_PIN) (GPIO_PIN <= t_GPIO_Pins_7)

/**
 * @brief This function gets the base address of a GPIO port
 * @details This function gets the base address of a GPIO port
 * @param[in] tPort The GPIO port to get its base address
 * @param[out] ppu32PortBaseAddress The base address of the GPIO port
 */
STATIC void GPIO_vGetPortAddress(t_GPIO_Ports tPort, P2VAR(P2VAR(t_GPIOx_RegisterMap)) ppu32PortBaseAddress)
{
	P2VAR(VOLATILE t_GPIOx_RegisterMap)
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

	*ppu32PortBaseAddress = (P2VAR(t_GPIOx_RegisterMap))pu32PortBaseAddress;
}

/**
 * @brief This function gets the pin span
 * @details This function gets the pin span, which is the number of bits to shift to reach the target pin mode and configuration bits
 * @param[in] tPin The target pin
 * @return t_u8 The pin span
 */
STATIC t_u8 GPIO_vGetPinSpan(t_GPIO_Pins tPin)
{
	/* Get the pin span (the number of bits to shift to reach the target pin mode and configuration bits) */
	return (t_u8)(((tPin <= t_GPIO_Pins_7) ? tPin : (tPin - t_GPIO_Pins_8)) * PIN_SHIFT_VALUE);
}

void GPIO_vSetPinDirection(t_GPIO_Ports tPort, t_GPIO_Pins tPin, t_GPIO_Direction tDirection)
{
	/* Get the pin span (the number of bits to shift to reach the target pin mode and configuration bits) */
	t_u8 u8PinSpan = GPIO_vGetPinSpan(tPin);
	/* Get the pin reset mask (the mask to reset the pin mode and configuration bits) */
	t_u32 u32PinResetMask = PIN_RESET_MASK(u8PinSpan);
	/* Get the default pin configuration based on the direction  (input or output) */
	t_u32 u32DefaultPinType = (tDirection == t_GPIO_Direction_Input) ? DEFAULT_PIN_INPUT_TYPE : DEFAULT_PIN_OUTPUT_TYPE;
	/* Set the new mode and configuration bits of the target pin */
	t_u32 u32TargetPinNewModeConfig = (tDirection | (u32DefaultPinType << PIN_CONFIGURATION_BITS_SHIFT_VALUE));
	/* Store the base address of the GPIO port */
	P2VAR(t_GPIOx_RegisterMap)
	pu32PortBaseAddress = NULL;
	/* Store the pin mode and configuration bits of the pin */
	P2VAR(t_u32)
	pu32TargetPinModeConfig = NULL;

	/* Get the base address of the GPIO port */
	GPIO_vGetPortAddress(tPort, &pu32PortBaseAddress);
	/* Get the pin mode and configuration bits of the pin */
	pu32TargetPinModeConfig = IS_PIN_IN_LOW_REGISTER(tPin) ? &pu32PortBaseAddress->CRL : &pu32PortBaseAddress->CRH;
	/* Set the mode and configuration bits of the pin */
	*pu32TargetPinModeConfig = (*pu32TargetPinModeConfig & u32PinResetMask) | (u32TargetPinNewModeConfig << u8PinSpan);
}

void GPIO_vSetPinInputType(t_GPIO_Ports tPort, t_GPIO_Pins tPin, t_GPIO_Input_Type tInputType)
{
	/* Get the pin span (the number of bits to shift to reach the target pin mode and configuration bits) */
	t_u8 u8PinSpan = GPIO_vGetPinSpan(tPin);
	/* Store the base address of the GPIO port */
	P2VAR(t_GPIOx_RegisterMap)
	pu32PortBaseAddress = NULL;
	/* Store the pin mode and configuration bits of the pin */
	P2VAR(t_u32)
	pu32TargetPinModeConfig = NULL;

	/* Get the base address of the GPIO port */
	GPIO_vGetPortAddress(tPort, &pu32PortBaseAddress);
	/* Get the pin mode and configuration bits of the pin */
	pu32TargetPinModeConfig = IS_PIN_IN_LOW_REGISTER(tPin) ? &pu32PortBaseAddress->CRL : &pu32PortBaseAddress->CRH;
	/* Set the mode and configuration bits of the pin */
	*pu32TargetPinModeConfig = (*pu32TargetPinModeConfig & PIN_RESET_CONFIGURATIONS_MASK(u8PinSpan)) | (t_u32)(tInputType << (u8PinSpan + PIN_CONFIGURATION_BITS_SHIFT_VALUE));
}

void GPIO_vSetPinOutputType(t_GPIO_Ports tPort, t_GPIO_Pins tPin, t_GPIO_Output_Type tOutputType)
{
	/* Get the pin span (the number of bits to shift to reach the target pin mode and configuration bits) */
	t_u8 u8PinSpan = GPIO_vGetPinSpan(tPin);
	/* Store the base address of the GPIO port */
	P2VAR(t_GPIOx_RegisterMap)
	pu32PortBaseAddress = NULL;
	/* Store the pin mode and configuration bits of the pin */
	P2VAR(t_u32)
	pu32TargetPinModeConfig = NULL;

	/* Get the base address of the GPIO port */
	GPIO_vGetPortAddress(tPort, &pu32PortBaseAddress);
	/* Get the pin mode and configuration bits of the pin */
	pu32TargetPinModeConfig = IS_PIN_IN_LOW_REGISTER(tPin) ? &pu32PortBaseAddress->CRL : &pu32PortBaseAddress->CRH;
	/* Set the mode and configuration bits of the pin */
	*pu32TargetPinModeConfig = (*pu32TargetPinModeConfig & PIN_RESET_CONFIGURATIONS_MASK(u8PinSpan)) | (t_u32)(tOutputType << (u8PinSpan + PIN_CONFIGURATION_BITS_SHIFT_VALUE));
}

void GPIO_vSetPinValue(t_GPIO_Ports tPort, t_GPIO_Pins tPin, t_GPIO_Value tValue)
{
	/* Store the base address of the GPIO port */
	P2VAR(t_GPIOx_RegisterMap)
	pu32PortBaseAddress = NULL;

	/* Get the base address of the GPIO port */
	GPIO_vGetPortAddress(tPort, &pu32PortBaseAddress);

	/* Set the value of the pin */
	if (tValue == t_GPIO_Value_High)
	{
		pu32PortBaseAddress->BSRR = (t_u32)(TRUE << tPin);
	}
	else if (tValue == t_GPIO_Value_Low)
	{
		pu32PortBaseAddress->BSRR = (t_u32)(TRUE << (tPin + PIN_RESET_SHIFT_VALUE));
	}
	else
	{
		/* Do nothing */
	}
}

t_GPIO_Value GPIO_tGetPinValue(t_GPIO_Ports tPort, t_GPIO_Pins tPin)
{
	/* Store the base address of the GPIO port */
	P2VAR(t_GPIOx_RegisterMap)
	pu32PortBaseAddress = NULL;

	/* Get the base address of the GPIO port */
	GPIO_vGetPortAddress(tPort, &pu32PortBaseAddress);

	/* Get the value of the pin */
	return (t_GPIO_Value)((pu32PortBaseAddress->IDR >> tPin) & TRUE);
}
