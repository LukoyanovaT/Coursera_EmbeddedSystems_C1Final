/**
 * @file memory.h
 * @brief Abstraction of memory read and write operations
 *
 * This header file provides an abstraction of reading and
 * writing to memory via function calls. 
 *
 * @author Alex Fosdick
 * @date April 1 2017
 *
 */
#ifndef __MEMORY_H__
#define __MEMORY_H__

#include <stdint.h>
#include <stdlib.h>

/**
 * @brief Sets a value of a data array 
 *
 * Given a pointer to a char data set, this will set a provided
 * index into that data set to the value provided.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 * @param value value to write the the locaiton
 *
 * @return void.
 */
void set_value(char * ptr, unsigned int index, char value);

/**
 * @brief Clear a value of a data array 
 *
 * Given a pointer to a char data set, this will clear a provided
 * index into that data set to the value zero.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 *
 * @return void.
 */
void clear_value(char * ptr, unsigned int index);

/**
 * @brief Returns a value of a data array 
 *
 * Given a pointer to a char data set, this will read the provided
 * index into that data set and return the value.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 *
 * @return Value to be read.
 */
char get_value(char * ptr, unsigned int index);

/**
 * @brief Sets data array elements to a value
 *
 * Given a pointer to a char data set, this will set a number of elements
 * from a provided data array to the given value. The length is determined
 * by the provided size parameter.
 *
 * @param ptr Pointer to data array
 * @param value value to write the the locaiton
 * @param size Number of elements to set to value
 *
 * @return void.
 */
void set_all(char * ptr, char value, unsigned int size);

/**
 * @brief Clears elements in a data array
 *
 * Given a pointer to a char data set, this will set a clear a number
 * of elements given the size provided. Clear means to set to zero. 
 *
 * @param ptr Pointer to data array
 * @param size Number of elements to set to zero
 *
 * @return void.
 */
void clear_all(char * ptr, unsigned int size);

/**
 * @brief moves chunk of memory from place to another
 *
 * it takes two pointers , one source and another is destination
 * and number of bytes to be moved
 *
 * @param src source pointer to the beginning of chunk of memory to be moved 
 * @param dst destination pointer to move the chunk of memory tp
 * @param length number of bytes to be moved
 *
 * @return pointer to destination (dst)
 */
uint8_t * my_memmove(uint8_t * src, uint8_t * dst, size_t length);

/**
 * @brief takes pointer to chunck of memory and copy it else where
 *
 * it simply will be ginven pointer to the beginning of the memory chunk 
 * and the destination pointer and size of the chunk ,so it will copy the memory 
 * chunck at that destiantion
 *
 * @param src source pointer of data to be copied
 * @param dst destination pointer of where to copy data
 * @param length number of bytes to be copied
 *
 * @return pointer to destination
 */
uint8_t * my_memcopy(uint8_t * src, uint8_t * dst, size_t length);

/**
 * @brief sets a block of memory to a certain value
 *
 *
 * @param src source pointer of data to be set
 * @param length number of bytes to be set
 * @param value is the vlaue that memory will be set to
 *
 * @return pointer to source 
 */
uint8_t * my_memset(uint8_t * src, size_t length, uint8_t value);

/**
 * @brief set a chunk of memory to zero
 *
 *
 * @param  src source pointer of data to be set
 * @param length number of bytes to be set
 *
 * @return  pointer to source 
 */
uint8_t * my_memzero(uint8_t * src, size_t length);

/**
 * @brief reverse the order of number of bytes
 *
 *
 * @param  src source pointer of data to be reversed
 * @param length number of bytes to be reversed
 *
 * @return  pointer to source 
 */   
uint8_t * my_reverse(uint8_t * src, size_t length);

/**
 * @brief take number of words to allocate ni dynamic memory
 *
 * it returns pointer to the number of words in case of successful allocation and NULL otherwise
 *
 * @param  length number of bytes to be allocated
 *
 * @return pointer to memory if successful , or NULL if not successful
 */
int32_t * reserve_words(size_t length);

/**
 * @brief free a dynamic memory allocation
 *
 *
 * @param src pointer to the source of memory to be freed
 *
 * @return void.
 */ 
void free_words(uint32_t * src);

#endif /* __MEMORY_H__ */
