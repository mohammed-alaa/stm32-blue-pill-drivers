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
 * @enum RCC_PreDivisionFactors
 * @brief This enum contains the pre-division factors of the input clock
 * @details This enum contains the pre-division factors of the input clock
 */
enum RCC_PreDivFactors
{
	/**
	 * @brief Do not divide the input clock
	 */
	RCC_PreDivFactors_DividedNot = 0,
	/**
	 * @brief Divide the input clock by 2
	 */
	RCC_PreDivFactors_DividedBy2,
	/**
	 * @brief Divide the input clock by 3
	 */
	RCC_PreDivFactors_DividedBy3,
	/**
	 * @brief Divide the input clock by 4
	 */
	RCC_PreDivFactors_DividedBy4,
	/**
	 * @brief Divide the input clock by 5
	 */
	RCC_PreDivFactors_DividedBy5,
	/**
	 * @brief Divide the input clock by 6
	 */
	RCC_PreDivFactors_DividedBy6,
	/**
	 * @brief Divide the input clock by 7
	 */
	RCC_PreDivFactors_DividedBy7,
	/**
	 * @brief Divide the input clock by 8
	 */
	RCC_PreDivFactors_DividedBy8,
	/**
	 * @brief Divide the input clock by 9
	 */
	RCC_PreDivFactors_DividedBy9,
	/**
	 * @brief Divide the input clock by 10
	 */
	RCC_PreDivFactors_DividedBy10,
	/**
	 * @brief Divide the input clock by 11
	 */
	RCC_PreDivFactors_DividedBy11,
	/**
	 * @brief Divide the input clock by 12
	 */
	RCC_PreDivFactors_DividedBy12,
	/**
	 * @brief Divide the input clock by 13
	 */
	RCC_PreDivFactors_DividedBy13,
	/**
	 * @brief Divide the input clock by 14
	 */
	RCC_PreDivFactors_DividedBy14,
	/**
	 * @brief Divide the input clock by 15
	 */
	RCC_PreDivFactors_DividedBy15,
	/**
	 * @brief Divide the input clock by 16
	 */
	RCC_PreDivFactors_DividedBy16
};

/**
 * @enum RCC_PLL1MulFactors
 * @brief This enum contains the multiplication factors of the PLL1
 * @details This enum contains the multiplication factors of the PLL1
 */
enum RCC_PLL1MulFactors
{
	/**
	 * @brief Multiply the PLL1 input clock by 4
	 */
	RCC_PLL1MulFactors_4 = 0b0010,
	/**
	 * @brief Multiply the PLL1 input clock by 5
	 */
	RCC_PLL1MulFactors_5,
	/**
	 * @brief Multiply the PLL1 input clock by 6
	 */
	RCC_PLL1MulFactors_6,
	/**
	 * @brief Multiply the PLL1 input clock by 7
	 */
	RCC_PLL1MulFactors_7,
	/**
	 * @brief Multiply the PLL1 input clock by 8
	 */
	RCC_PLL1MulFactors_8,
	/**
	 * @brief Multiply the PLL1 input clock by 9
	 */
	RCC_PLL1MulFactors_9,
	/**
	 * @brief Multiply the PLL1 input clock by 6.5
	 */
	RCC_PLL1MulFactors_6_5 = 0b1101,
};

/**
 * @enum RCC_PLL2MulFactors
 * @brief This enum contains the multiplication factors of the PLL2 and PLL3
 * @details This enum contains the multiplication factors of the PLL2 and PLL3
 */
enum RCC_PLL23MulFactors
{
	/**
	 * @brief Multiply the PLL2 and PLL3 input clock by 8
	 */
	RCC_PLL23MulFactors_8 = 0b0110,
	/**
	 * @brief Multiply the PLL2 and PLL3 input clock by 9
	 */
	RCC_PLL23MulFactors_9,
	/**
	 * @brief Multiply the PLL2 and PLL3 input clock by 10
	 */
	RCC_PLL23MulFactors_10,
	/**
	 * @brief Multiply the PLL2 and PLL3 input clock by 11
	 */
	RCC_PLL23MulFactors_11,
	/**
	 * @brief Multiply the PLL2 and PLL3 input clock by 12
	 */
	RCC_PLL23MulFactors_12,
	/**
	 * @brief Multiply the PLL2 and PLL3 input clock by 13
	 */
	RCC_PLL23MulFactors_13,
	/**
	 * @brief Multiply the PLL2 and PLL3 input clock by 14
	 */
	RCC_PLL23MulFactors_14,
	/**
	 * @brief Multiply the PLL2 and PLL3 input clock by 16
	 */
	RCC_PLL23MulFactors_16 = 0b1110,
	/**
	 * @brief Multiply the PLL2 and PLL3 input clock by 20
	 */
	RCC_PLL23MulFactors_20
};

/** @} */
/** @} */

#endif /* _RCC_INTERFACE_H_ */
