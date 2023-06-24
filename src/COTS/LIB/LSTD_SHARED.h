/**
 * @file LSTD_SHARED.h
 * @author Mohamed Alaa
 * @brief Shared library for all the standard types
 * @version 1.0.0
 * @date 2023-06-24
 */

#ifndef LSTD_SHARED_H_
#define LSTD_SHARED_H_

#include "LSTD_TYPES.h"

/**
 * @def SET_REGISTER_BIT_STATUS
 * @brief Set register bit status (1 or 0)
 * @details This macro is used to set a specific bit in a specific register
 * @param REG Register name
 * @param BIT Bit name
 * @param bEnable Bit status (TRUE or FALSE)
 */
#define SET_REGISTER_BIT_STATUS(PERPH, REG, BIT, bEnable) (PERPH.REG.BIT = (bEnable == TRUE) ? 1U : 0U)

#endif
