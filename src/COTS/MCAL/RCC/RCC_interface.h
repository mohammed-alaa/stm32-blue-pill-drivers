/**
 * @file RCC_interface.h
 * @author Mohamed Alaa
 * @version 1.0.0
 * @brief This file is the interface file for the RCC module.
 * @details This file contains the prototypes of the functions of the RCC module.
 * @date 2023-06-18
 */

#ifndef _RCC_INTERFACE_H_
#define _RCC_INTERFACE_H_

/**
 * @addtogroup mcal
 * @{
 */

/**
 * @defgroup rcc_module RCC Module
 * @brief RCC Module
 * @{
 */

/**
 * @enum RCC_PLLMulFactors
 * @brief This enum contains the multiplication factors of the PLL
 * @details This enum contains the multiplication factors of the PLL
 */
enum RCC_PLLMulFactors
{
	/**
	 * @brief Multiply the PLL1 input clock by 2
	 */
	RCC_PLLMulFactors_2 = 0,
	/**
	 * @brief Multiply the PLL1 input clock by 3
	 */
	RCC_PLLMulFactors_3,
	/**
	 * @brief Multiply the PLL1 input clock by 4
	 */
	RCC_PLLMulFactors_4,
	/**
	 * @brief Multiply the PLL1 input clock by 5
	 */
	RCC_PLLMulFactors_5,
	/**
	 * @brief Multiply the PLL1 input clock by 6
	 */
	RCC_PLLMulFactors_6,
	/**
	 * @brief Multiply the PLL1 input clock by 7
	 */
	RCC_PLLMulFactors_7,
	/**
	 * @brief Multiply the PLL1 input clock by 8
	 */
	RCC_PLLMulFactors_8,
	/**
	 * @brief Multiply the PLL1 input clock by 9
	 */
	RCC_PLLMulFactors_9,
	/**
	 * @brief Multiply the PLL1 input clock by 10
	 */
	RCC_PLLMulFactors_10,
	/**
	 * @brief Multiply the PLL1 input clock by 11
	 */
	RCC_PLLMulFactors_11,
	/**
	 * @brief Multiply the PLL1 input clock by 12
	 */
	RCC_PLLMulFactors_12,
	/**
	 * @brief Multiply the PLL1 input clock by 13
	 */
	RCC_PLLMulFactors_13,
	/**
	 * @brief Multiply the PLL1 input clock by 14
	 */
	RCC_PLLMulFactors_14,
	/**
	 * @brief Multiply the PLL1 input clock by 15
	 */
	RCC_PLLMulFactors_15,
	/**
	 * @brief Multiply the PLL1 input clock by 16
	 */
	RCC_PLLMulFactors_16
};

/**
 * @enum RCC_AHBPrescaler
 * @brief This enum contains the prescaler factors of the AHB bus
 * @details This enum contains the prescaler factors of the AHB bus
 */
enum RCC_AHBPrescaler
{
	/**
	 * @brief AHB bus not divided
	 */
	RCC_AHBPrescaler_NotDivided = 0,
	/**
	 * @brief AHB bus divided by 2
	 */
	RCC_AHBPrescaler_DividedBy2 = 0b1000,
	/**
	 * @brief AHB bus divided by 4
	 */
	RCC_AHBPrescaler_DividedBy4,
	/**
	 * @brief AHB bus divided by 8
	 */
	RCC_AHBPrescaler_DividedBy8,
	/**
	 * @brief AHB bus divided by 16
	 */
	RCC_AHBPrescaler_DividedBy16,
	/**
	 * @brief AHB bus divided by 64
	 */
	RCC_AHBPrescaler_DividedBy64,
	/**
	 * @brief AHB bus divided by 128
	 */
	RCC_AHBPrescaler_DividedBy128,
	/**
	 * @brief AHB bus divided by 256
	 */
	RCC_AHBPrescaler_DividedBy256,
	/**
	 * @brief AHB bus divided by 512
	 */
	RCC_AHBPrescaler_DividedBy512,
};

/**
 * @enum RCC_APBPrescaler
 * @brief This enum contains the prescaler factors of the APB (1 & 2) bus
 * @details This enum contains the prescaler factors of the APB (1 & 2) bus
 */
enum RCC_APBPrescaler
{
	/**
	 * @brief APB1 bus not divided
	 */
	RCC_APBPrescaler_NotDivided = 0,
	/**
	 * @brief APB1 bus divided by 2
	 */
	RCC_APBPrescaler_DividedBy2 = 0b100,
	/**
	 * @brief APB1 bus divided by 4
	 */
	RCC_APBPrescaler_DividedBy4,
	/**
	 * @brief APB1 bus divided by 8
	 */
	RCC_APBPrescaler_DividedBy8,
	/**
	 * @brief APB1 bus divided by 16
	 */
	RCC_APBPrescaler_DividedBy16,
};

/**
 * @enum RCC_ADCPrescaler
 * @brief This enum contains the prescaler factors of the ADC bus
 * @details This enum contains the prescaler factors of the ADC bus
 */
enum RCC_ADCPrescaler
{
	/**
	 * @brief ADC bus divided by 2
	 */
	RCC_ADCPrescaler_DividedBy2 = 0,
	/**
	 * @brief ADC bus divided by 4
	 */
	RCC_ADCPrescaler_DividedBy4,
	/**
	 * @brief ADC bus divided by 6
	 */
	RCC_ADCPrescaler_DividedBy6,
	/**
	 * @brief ADC bus divided by 8
	 */
	RCC_ADCPrescaler_DividedBy8,
};

/**
 * @enum RCC_SystemClock
 * @brief This enum contains the system clock sources
 * @details This enum contains the system clock sources
 */
enum RCC_SystemClock
{
	/**
	 * @brief HSI clock selected as system clock
	 */
	RCC_SystemClock_HSI = 0,
	/**
	 * @brief HSE clock selected as system clock
	 */
	RCC_SystemClock_HSE,
	/**
	 * @brief PLL clock selected as system clock
	 */
	RCC_SystemClock_PLL,
};

/**
 * @enum RCC_PLLSource
 * @brief This enum contains the PLL clock sources
 * @details This enum contains the PLL clock sources
 */
enum RCC_PLLSource
{
	/**
	 * @brief HSI clock divided by 2 selected as PLL clock
	 */
	RCC_PLLSource_HSI_DividedBy2 = 0,
	/**
	 * @brief HSE clock selected as PLL clock
	 */
	RCC_PLLSource_HSE,
};

/**
 * @enum RCC_MCO
 * @brief This enum contains the MCO sources
 * @details This enum contains the MCO sources
 */
enum RCC_MCO
{
	/**
	 * @brief No clock selected as MCO
	 */
	RCC_MCO_NoClock = 0,
	/**
	 * @brief System clock selected as MCO
	 */
	RCC_MCO_SystemClock = 0b100,
	/**
	 * @brief HSI clock selected as MCO
	 */
	RCC_MCO_HSI,
	/**
	 * @brief HSE clock selected as MCO
	 */
	RCC_MCO_HSE,
	/**
	 * @brief PLL clock divided by 2 selected as MCO
	 */
	RCC_MCO_PLL_DividedBy2,
};

/**
 * @enum RCC_USBPrescaler
 * @brief This enum contains the USB prescaler factors
 * @details This enum contains the USB prescaler factors
 */
enum RCC_USBPrescaler
{
	/**
	 * @brief USB clock divided by 1.5
	 */
	RCC_USBPrescaler_1_5 = 0,
	/**
	 * @brief USB clock divided by 1
	 */
	RCC_USBPrescaler_1,
};

/**
 * @enum RCC_APB2Peripherals
 * @brief This enum contains the APB2 peripherals that are connected to the APB2 bus
 * @details This enum contains the APB2 peripherals that are connected to the APB2 bus
 */
enum RCC_APB2Peripherals
{
	/**
	 * @brief Alternate function I/O clock
	 */
	RCC_APB2Peripherals_AFIO = 0,
	/**
	 * @brief I/O port A clock
	 */
	RCC_APB2Peripherals_PORTA = 2,
	/**
	 * @brief I/O port B clock
	 */
	RCC_APB2Peripherals_PORTB,
	/**
	 * @brief I/O port C clock
	 */
	RCC_APB2Peripherals_PORTC,
	/**
	 * @brief I/O port D clock
	 */
	RCC_APB2Peripherals_PORTD,
	/**
	 * @brief I/O port E clock
	 */
	RCC_APB2Peripherals_PORTE,
	/**
	 * @brief I/O port F clock
	 */
	RCC_APB2Peripherals_PORTF,
	/**
	 * @brief I/O port G clock
	 */
	RCC_APB2Peripherals_PORTG,
	/**
	 * @brief ADC 1 interface clock
	 */
	RCC_APB2Peripherals_ADC1,
	/**
	 * @brief ADC 2 interface clock
	 */
	RCC_APB2Peripherals_ADC2,
	/**
	 * @brief Timer 1 (TIM1) clock
	 */
	RCC_APB2Peripherals_TIM1,
	/**
	 * @brief SPI 1 clock
	 */
	RCC_APB2Peripherals_SPI1,
	/**
	 * @brief Timer 8 (TIM8) clock
	 */
	RCC_APB2Peripherals_TIM8,
	/**
	 * @brief USART1 clock
	 */
	RCC_APB2Peripherals_USART1,
	/**
	 * @brief ADC 3 interface clock
	 */
	RCC_APB2Peripherals_ADC3,
	/**
	 * @brief Timer 9 (TIM9) clock
	 */
	RCC_APB2Peripherals_TIM9 = 19,
	/**
	 * @brief Timer 10 (TIM10) clock
	 */
	RCC_APB2Peripherals_TIM10,
	/**
	 * @brief Timer 11 (TIM11) clock
	 */
	RCC_APB2Peripherals_TIM11,
};

/**
 * @enum RCC_APB1Peripherals
 * @brief This enum contains the APB1 peripherals that are connected to the APB1 bus
 * @details This enum contains the APB1 peripherals that are connected to the APB1 bus
 */
enum RCC_APB1Peripherals
{
	/**
	 * @brief Timer 2 (TIM2) clock
	 */
	RCC_APB1Peripherals_TIM2 = 0,
	/**
	 * @brief Timer 3 (TIM3) clock
	 */
	RCC_APB1Peripherals_TIM3,
	/**
	 * @brief Timer 4 (TIM4) clock
	 */
	RCC_APB1Peripherals_TIM4,
	/**
	 * @brief Timer 5 (TIM5) clock
	 */
	RCC_APB1Peripherals_TIM5,
	/**
	 * @brief Timer 6 (TIM6) clock
	 */
	RCC_APB1Peripherals_TIM6,
	/**
	 * @brief Timer 7 (TIM7) clock
	 */
	RCC_APB1Peripherals_TIM7,
	/**
	 * @brief Timer 12 (TIM12) clock
	 */
	RCC_APB1Peripherals_TIM12,
	/**
	 * @brief Timer 13 (TIM13) clock
	 */
	RCC_APB1Peripherals_TIM13,
	/**
	 * @brief Timer 14 (TIM14) clock
	 */
	RCC_APB1Peripherals_TIM14,
	/**
	 * @brief Window watchdog (WWDG) clock
	 */
	RCC_APB1Peripherals_WWDG = 11,
	/**
	 * @brief SPI 2 clock
	 */
	RCC_APB1Peripherals_SPI2 = 14,
	/**
	 * @brief SPI 3 clock
	 */
	RCC_APB1Peripherals_SPI3,
	/**
	 * @brief USART 2 clock
	 */
	RCC_APB1Peripherals_USART2 = 17,
	/**
	 * @brief USART 3 clock
	 */
	RCC_APB1Peripherals_USART3,
	/**
	 * @brief UART 4 clock
	 */
	RCC_APB1Peripherals_UART4,
	/**
	 * @brief UART 5 clock
	 */
	RCC_APB1Peripherals_UART5,
	/**
	 * @brief I2C 1 clock
	 */
	RCC_APB1Peripherals_I2C1,
	/**
	 * @brief I2C 2 clock
	 */
	RCC_APB1Peripherals_I2C2,
	/**
	 * @brief USB clock
	 */
	RCC_APB1Peripherals_USB,
	/**
	 * @brief CAN clock
	 */
	RCC_APB1Peripherals_CAN = 25,
	/**
	 * @brief Backup interface clock
	 */
	RCC_APB1Peripherals_BKP = 27,
	/**
	 * @brief Power interface clock
	 */
	RCC_APB1Peripherals_PWR,
	/**
	 * @brief DAC interface clock
	 */
	RCC_APB1Peripherals_DAC
};

/**
 * @enum RCC_AHBPeripherals
 * @brief This enum contains the AHB peripherals that are connected to the AHB bus
 * @details This enum contains the AHB peripherals that are connected to the AHB bus
 */
enum RCC_AHBPeripherals
{
	/**
	 * @brief DMA 1 clock
	 */
	RCC_AHBPeripherals_DMA1 = 0,
	/**
	 * @brief DMA 2 clock
	 */
	RCC_AHBPeripherals_DMA2,
	/**
	 * @brief SRAM interface clock
	 */
	RCC_AHBPeripherals_SRAM,
	/**
	 * @brief FLITF clock
	 */
	RCC_AHBPeripherals_FLITF = 4,
	/**
	 * @brief CRC clock
	 */
	RCC_AHBPeripherals_CRC = 6,
	/**
	 * @brief FSMC clock
	 */
	RCC_AHBPeripherals_FSMC = 8,
	/**
	 * @brief SDIO clock
	 */
	RCC_AHBPeripherals_SDIO = 10,
};

/** @} */
/** @} */

#endif /* _RCC_INTERFACE_H_ */
