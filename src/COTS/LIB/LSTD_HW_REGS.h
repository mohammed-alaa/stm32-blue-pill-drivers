/**
 * @file LSTD_HW_REGS.h
 * @author Mohamed Alaa
 * @brief This file contains the hardware registers macro-functions for memory addresses mapping and accessing
 * @version 1.0.0
 * @date 2023-06-18
 */

#ifndef _LSTD_HW_REGS_H
#define _LSTD_HW_REGS_H

#include "LSTD_TYPES.h"
#include "LSTD_COMPILER.h"

/**
 * @addtogroup standard_library
 * @{
 */

/**
 * @defgroup hw_registers Hardware registers macro-functions
 * @brief These macro-functions help in mapping and accessing the hardware registers
 * @{
 */

/**
 * @def REGISTER_ADDRESS(ADDRESS, OFFSET)
 * @brief Placeholder for declaring a register address
 * @param[in] ADDRESS The address of the register
 * @param[in] OFFSET The offset of the register
 * @return The final address of the register
 */
#define REGISTER_ADDRESS(ADDRESS, OFFSET) ((ADDRESS) + (OFFSET))

/**
 * @def REGISTER(REG_TYPE, ADDRESS)
 * @brief Map to a certain register by its address in the memory
 * @param[in] ADDRESS The address of the register
 * @param[in] REG_TYPE The type of the register
 * @note REG_TYPE can be a standard type (e.g. t_u8, t_u16, t_u32, ...) or a user-defined type
 * @return The value of the register
 * @see typedefs
 */
#define REGISTER(REG_TYPE, ADDRESS) (*(VOLATILE P2VAR(REG_TYPE))(ADDRESS))

/**
 * @def REGISTER_U8(ADDRESS)
 * @brief Map to a certain register by its 8-bit address in the memory (used for 8-bit registers)
 * @param[in] ADDRESS The address of the register
 * @return The value of the register
 */
#define REGISTER_U8(ADDRESS) REGISTER(t_u8, ADDRESS)

/**
 * @def REGISTER_U16(ADDRESS)
 * @brief Map to a certain register by its 16-bit address in the memory (used for 16-bit registers)
 * @param[in] ADDRESS The address of the register
 * @return The value of the register
 */
#define REGISTER_U16(ADDRESS) REGISTER(t_u16, ADDRESS)

/**
 * @def REGISTER_U32(ADDRESS)
 * @brief Map to a certain register by its 32-bit address in the memory (used for 32-bit registers)
 * @param[in] ADDRESS The address of the register
 * @return The value of the register
 */
#define REGISTER_U32(ADDRESS) REGISTER(t_u32, ADDRESS)

/** @} */
/** @} */

#endif /* _LSTD_HW_REGS_H */
