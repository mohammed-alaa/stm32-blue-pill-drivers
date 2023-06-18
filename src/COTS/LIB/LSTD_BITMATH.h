/**
 * @file LSTD_BITMATH.h
 * @author Mohamed alaa
 * @brief This file contains the bit math manipulation macro-functions
 * @version 1.0.0
 * @date 2023-06-18
 */

#ifndef _LSTD_BITMATH_H_
#define _LSTD_BITMATH_H_

/**
 * @addtogroup standard_library
 * @{
 */

/**
 * @defgroup bitmath Bit Manipulation Math Macros
 * @brief This module contains the bit math manipulation macro-functions
 * @{
 */

/**
 * @def SET_BIT(REG, BITNUM)
 * @brief Set a certain bit's value
 * @param[in] REG The register to set its bit
 * @param[in] BITNUM The bit number to set
 */
#define SET_BIT(REG, BITNUM) (REG) |= (1 << (BITNUM))

/**
 * @def CLEAR_BIT(REG, BITNUM)
 * @brief Clear a certain bit's value to
 * @param[in] REG The register to clear its bit
 * @param[in] BITNUM The bit number to clear
 */
#define CLEAR_BIT(REG, BITNUM) (REG) &= ~(1 << (BITNUM))

/**
 * @def TOGGLE_BIT(REG, BITNUM)
 * @brief Toggle a bit to `0` if it's `1`, `1` otherwise
 * @param[in] REG The register to toggle its bit
 * @param[in] BITNUM The bit number to toggle
 */
#define TOGGLE_BIT(REG, BITNUM) (REG) ^= (1 << (BITNUM))

/**
 * @def GET_BIT(REG, BITNUM)
 * @brief Return the value of the bit whether it's `1` or `0`
 * @param[in] REG The register to get its bit
 * @param[in] BITNUM The bit number to get
 */
#define GET_BIT(REG, BITNUM) (((REG) >> (BITNUM)) & 1)

/** @} */
/** @} */

#endif /* _LSTD_BITMATH_H_ */
