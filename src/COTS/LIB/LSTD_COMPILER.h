/**
 * @file LSTD_COMPILER.h
 * @author Mohamed Alaa
 * @brief This file contains the compiler standard macros
 * @version 1.0.0
 * @date 2023-06-18
 */

#ifndef _LSTD_COMPILER_H_
#define _LSTD_COMPILER_H_

/**
 * @addtogroup standard_library
 * @{
 */

/**
 * @defgroup compiler Compiler standard macros
 * @brief This file contains the compiler standard macros
 * @{
 */

/**
 * @def CONST
 * @brief Declare a standard constant variable with the specified type
 */
#define CONST const

/**
 * @def STATIC
 * @brief Declare a standard static variable
 */
#define STATIC static

/**
 * @def VOLATILE
 * @brief Declare a standard volatile variable
*/
#define VOLATILE volatile

/**
 * @def P2VAR(ptrtype)
 * @brief Declare a pointer-to-variable with the specified type
 * @param[in] ptrtype The type of the pointer
 */
#define P2VAR(ptrtype) ptrtype *

/**
 * @def P2CONST(ptrtype)
 * @brief Declare a constant pointer-to-variable with the specified type
 * @param[in] ptrtype The type of the pointer
 */
#define P2CONST(ptrtype) CONST ptrtype *

/**
 * @def CONSTP2VAR(ptrtype)
 * @brief Declare a pointer-to-variable constant with the specified type
 * @param[in] ptrtype The type of the pointer
 */
#define CONSTP2VAR(ptrtype) ptrtype *CONST

/**
 * @def CONSTP2CONST(ptrtype)
 * @brief Declare a constant pointer-to-variable constant with the specified type
 * @param[in] ptrtype The type of the pointer
 */
#define CONSTP2CONST(ptrtype) CONST ptrtype *CONST

/**
 * @def P2FUNC(rettype, fctname)
 * @brief Declare a pointer-to-function with the specified return type
 * @param[in] rettype The return type of the function
 * @param[in] fctname The name of the function
 */
#define P2FUNC(rettype, fctname) rettype(*fctname)

/** @} */
/** @} */

#endif /* _LSTD_COMPILER_H_ */
