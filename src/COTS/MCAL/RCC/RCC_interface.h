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
	 * @brief Multiply the PLL1 input clock by 4
	 */
	RCC_PLLMulFactors_4 = 0b0010,
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
	 * @brief Multiply the PLL1 input clock by 6.5
	 */
	RCC_PLLMulFactors_6_5 = 0b1101,
};


/** @} */
/** @} */

#endif /* _RCC_INTERFACE_H_ */
