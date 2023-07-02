/**
 * @file GPIO_program.c
 * @author Mohamed Alaa
 * @version 1.0.0
 * @brief This file contains the implementation for the GPIO module.
 * @details This file contains the implementation for the GPIO module.
 * @date 2023-06-25
 */

#include "../../LIB/LSTD_TYPES.h"
#include "../../LIB/LSTD_COMPILER.h"
#include "../../LIB/LSTD_BITMATH.h"
#include "../../LIB/LSTD_VALUES.h"
#include "GPIO_private.h"
#include "GPIO_interface.h"
#include "GPIO_config.h"

/**
 * @def IS_PIN_IN_LOW_REGISTER
 * @brief Check if the pin is in the low register
 * @details This macro checks if the pin is in the low register (CRL)
 * @param[in] GPIO_PIN The pin to check if it is in the low register (CRL) or not
 */
#define IS_PIN_IN_LOW_REGISTER(GPIO_PIN) (GPIO_PIN <= GPIO_Pins_7)

/**
 * @brief This function gets the base address of a GPIO port
 * @details This function gets the base address of a GPIO port
 * @param[in] tPort The GPIO port to get its base address
 * @param[out] ppu32PortBaseAddress The base address of the GPIO port
 */
STATIC void GPIO_vGetPortAddress(t_GPIO_Ports tPort, P2VAR(P2VAR(t_GPIOx_RegisterMap)) ppu32PortBaseAddress)
{
	P2VAR(VOLATILE t_GPIOx_RegisterMap)
	pu32PortBaseAddress = (P2VAR(t_GPIOx_RegisterMap))NULL;

	switch (tPort)
	{
	case GPIO_Ports_A:
		pu32PortBaseAddress = &GPIO_A;
		break;
	case GPIO_Ports_B:
		pu32PortBaseAddress = &GPIO_B;
		break;
	case GPIO_Ports_C:
		pu32PortBaseAddress = &GPIO_C;
		break;
	case GPIO_Ports_D:
		pu32PortBaseAddress = &GPIO_D;
		break;
	case GPIO_Ports_E:
		pu32PortBaseAddress = &GPIO_E;
		break;
	case GPIO_Ports_F:
		pu32PortBaseAddress = &GPIO_F;
		break;
	case GPIO_Ports_G:
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
	return (t_u8)(((tPin <= GPIO_Pins_7) ? tPin : (tPin - GPIO_Pins_8)) * PIN_SHIFT_VALUE);
}

/**
 * @brief This function is used to set the pin input type
 * @details This function is used to set the pin input type in case of it is pull-up or pull-down in the ODR register
 * @param[in] pu32PortBaseAddress The base address of the GPIO port
 * @param[in] tPin The target pin
 * @param[in] tInputType The input type of the target pin (pull-up or pull-down)
 * @see t_GPIO_Input_Type
 */
STATIC void GPIO_vSetPinInputTypePullUpDown(P2VAR(t_GPIOx_RegisterMap) pu32PortBaseAddress, t_GPIO_Pins tPin, t_GPIO_Input_Type tInputType)
{
	if (tInputType >= GPIO_Input_Type_Pull_Down)
	{
		/* Get the pin input type (pull-up or pull-down) */
		t_u8 u8PinInputType = GET_BIT(tInputType, 0);

		/* Set the pull-up/pull-down resistor */
		pu32PortBaseAddress->ODR = (pu32PortBaseAddress->ODR & PIN_RESET_ODR_MASK(tPin)) | (t_u32)(u8PinInputType << tPin);
	}
	else
	{
		/* Do nothing */
	}
}

void GPIO_vSetPinDirection(t_GPIO_Ports tPort, t_GPIO_Pins tPin, t_GPIO_Direction tDirection)
{
	/* Get the pin span (the number of bits to shift to reach the target pin mode and configuration bits) */
	t_u8 u8PinSpan = GPIO_vGetPinSpan(tPin);
	/* Store the base address of the GPIO port */
	P2VAR(t_GPIOx_RegisterMap)
	pu32PortBaseAddress = (P2VAR(t_GPIOx_RegisterMap))NULL;
	/* Store the pin mode and configuration bits of the pin */
	P2VAR(t_u32)
	pu32TargetPinModeConfig = (P2VAR(t_u32))NULL;

	/* Get the base address of the GPIO port */
	GPIO_vGetPortAddress(tPort, &pu32PortBaseAddress);
	/* Get the pin mode and configuration bits of the pin */
	pu32TargetPinModeConfig = IS_PIN_IN_LOW_REGISTER(tPin) ? &pu32PortBaseAddress->CRL : &pu32PortBaseAddress->CRH;
	/* Set the mode and configuration bits of the pin */
	*pu32TargetPinModeConfig = (*pu32TargetPinModeConfig & PIN_RESET_MASK(u8PinSpan)) | (tDirection << u8PinSpan);

	/* Set the pull-up/pull-down resistor */
	if (tDirection == GPIO_Direction_Input)
	{
		GPIO_vSetPinInputType(tPort, tPin, DEFAULT_PIN_INPUT_TYPE);
	}
	else
	{
		GPIO_vSetPinOutputType(tPort, tPin, DEFAULT_PIN_OUTPUT_TYPE);
	}
}

void GPIO_vSetPinInputType(t_GPIO_Ports tPort, t_GPIO_Pins tPin, t_GPIO_Input_Type tInputType)
{
	/* Get the pin span (the number of bits to shift to reach the target pin mode and configuration bits) */
	t_u8 u8PinSpan = GPIO_vGetPinSpan(tPin);
	/* Check if the input type is pull-up or pull-down */
	t_GPIO_Input_Type u8PinInputTypeModeConfigurations = (tInputType == GPIO_Input_Type_Pull_Up) ? GPIO_Input_Type_Pull_Down : tInputType;
	/* Store the base address of the GPIO port */
	P2VAR(t_GPIOx_RegisterMap)
	pu32PortBaseAddress = (P2VAR(t_GPIOx_RegisterMap))NULL;
	/* Store the pin mode and configuration bits of the pin */
	P2VAR(t_u32)
	pu32TargetPinModeConfig = (P2VAR(t_u32))NULL;

	/* Get the base address of the GPIO port */
	GPIO_vGetPortAddress(tPort, &pu32PortBaseAddress);
	/* Get the pin mode and configuration bits of the pin */
	pu32TargetPinModeConfig = IS_PIN_IN_LOW_REGISTER(tPin) ? &pu32PortBaseAddress->CRL : &pu32PortBaseAddress->CRH;
	/* Set the mode and configuration bits of the pin */
	*pu32TargetPinModeConfig = (*pu32TargetPinModeConfig & PIN_RESET_CONFIGURATIONS_MASK(u8PinSpan)) | (u8PinInputTypeModeConfigurations << (u8PinSpan + PIN_CONFIGURATION_BITS_SHIFT_VALUE));
	/* Set the pull-up/pull-down resistor */
	GPIO_vSetPinInputTypePullUpDown(pu32PortBaseAddress, tPin, tInputType);
}

void GPIO_vSetPinOutputType(t_GPIO_Ports tPort, t_GPIO_Pins tPin, t_GPIO_Output_Type tOutputType)
{
	/* Get the pin span (the number of bits to shift to reach the target pin mode and configuration bits) */
	t_u8 u8PinSpan = GPIO_vGetPinSpan(tPin);
	/* Store the base address of the GPIO port */
	P2VAR(t_GPIOx_RegisterMap)
	pu32PortBaseAddress = (P2VAR(t_GPIOx_RegisterMap))NULL;
	/* Store the pin mode and configuration bits of the pin */
	P2VAR(t_u32)
	pu32TargetPinModeConfig = (P2VAR(t_u32))NULL;

	/* Get the base address of the GPIO port */
	GPIO_vGetPortAddress(tPort, &pu32PortBaseAddress);
	/* Get the pin mode and configuration bits of the pin */
	pu32TargetPinModeConfig = IS_PIN_IN_LOW_REGISTER(tPin) ? &pu32PortBaseAddress->CRL : &pu32PortBaseAddress->CRH;
	/* Set the mode and configuration bits of the pin */
	*pu32TargetPinModeConfig = (*pu32TargetPinModeConfig & PIN_RESET_CONFIGURATIONS_MASK(u8PinSpan)) | (t_u32)(tOutputType << (u8PinSpan + PIN_CONFIGURATION_BITS_SHIFT_VALUE));
}

void GPIO_vSetPinValue(t_GPIO_Ports tPort, t_GPIO_Pins tPin, t_GPIO_Value tValue)
{
	/* Get the pin location (the number of bits to shift to reach the target pin) */
	t_u32 u32PinLocation = tPin;
	/* Store the base address of the GPIO port */
	P2VAR(t_GPIOx_RegisterMap)
	pu32PortBaseAddress = (P2VAR(t_GPIOx_RegisterMap))NULL;

	/* Get the base address of the GPIO port */
	GPIO_vGetPortAddress(tPort, &pu32PortBaseAddress);

	if (tValue == GPIO_Value_Low)
	{
		u32PinLocation += PIN_RESET_SHIFT_VALUE;
	}
	else
	{
		/* Do nothing */
	}

	/* Set the value of the pin */
	pu32PortBaseAddress->BSRR = (t_u32)(TRUE << u32PinLocation);
}

t_GPIO_Value GPIO_tGetPinValue(t_GPIO_Ports tPort, t_GPIO_Pins tPin)
{
	/* Store the base address of the GPIO port */
	P2VAR(t_GPIOx_RegisterMap)
	pu32PortBaseAddress = (P2VAR(t_GPIOx_RegisterMap))NULL;

	/* Get the base address of the GPIO port */
	GPIO_vGetPortAddress(tPort, &pu32PortBaseAddress);

	/* Get the value of the pin */
	return (t_GPIO_Value)((pu32PortBaseAddress->IDR >> tPin) & TRUE);
}

void GPIO_AFIO_vInitCortexEvent(t_GPIO_Ports tPort, t_GPIO_Pins tPin)
{
	AFIO.EVCR.PORT = tPort;
	AFIO.EVCR.PIN = tPin;
	AFIO.EVCR.EVOE = FALSE;
}

void GPIO_AFIO_vConfigEXTILine(t_GPIO_Ports tPort, t_GPIO_Pins tPin)
{
	/* Get the index of the target EXTI line */
	t_u32 u32EXTILineTargetIndex = (t_u32)(tPin / PIN_SHIFT_VALUE);

	/* Store the address of the target EXTI line */
	P2VAR(VOLATILE t_u32)
	pu32TargetExtiLine = &AFIO.EXTICR[u32EXTILineTargetIndex];

	/* Set the target EXTI line */
	*pu32TargetExtiLine = (*pu32TargetExtiLine & PIN_RESET_MASK(u32EXTILineTargetIndex)) | (t_u32)(TRUE << tPort);
}
