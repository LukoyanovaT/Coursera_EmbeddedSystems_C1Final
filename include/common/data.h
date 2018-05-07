/******************************************************************************
*
* Copyrigth (C) 2018 by Lukoyanova Tatyana - Company of Nizhniy Novgorod
*
******************************************************************************/
/**
 * @file data.h 
 * @brief This header file should do some very basic data manipulation.
 *
 * This is a simple functions converted data from a standard integer type 
 * into an ASCII string and converted data back from an ASCII represented 
 * string into an integer type
 *
 * 
 * @autor Lukoyanova Tatyana
 * @date 06/05/2018
 *  
 **/
#ifndef __DATA_H__
#define __DATA_H__

#include <stdint.h>
#include <stdbool.h>
#include <math.h>
#include "memory.h"

/**
 * @brief Convert data from a standard integer type into an ASCII string
 *
 * @param data Integer value
 * @param ptr Converted character string
 * @param base Base to convert to (support bases 2 to 16)
 *
 * @return Length of the converted data (including a negative sign)
 */
uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base);

/**
 * @brief Convert data back from an ASCII represented string into an integer type
 *
 * @param ptr Converted character string
 * @param digits Length of the converted data (including a negative sign)
 * @param base Base of converted data (support bases 2 to 16)
 *
 * @return Integer value
 */
int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base);

#endif /* __DATA_H__ */
