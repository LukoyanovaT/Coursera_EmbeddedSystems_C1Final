/******************************************************************************
*
* Copyrigth (C) 2018 by Lukoyanova Tatyana - Company of Nizhniy Novgorod
*
******************************************************************************/

/**
 * @file stats.h
 * @brief Char array statistical analitics
 *
 * This is a simple applicationi prints the statistics of an data array 
 * including minimum, maximum, mean and median.
 *
 *
 * @autor Lukoyanova Tatyana
 * @date 15/04/2018
 *
 */

/**
 *  @brief   Prints the statistics 
 *
 *  This function prints the statistics of an data array including minimum,
 *          maximum, mean and median.
 *
 *  @param  min: the minimum value
 *  @param  max: the maximum value
 *  @param  med: the median value
 *  @param  mean: the mean value
 *  @return None
 *
 **/
void print_statistics(unsigned char min, unsigned char max, 
		      unsigned char med, unsigned char mean);

/**
 *  @brief   Prints the array to the screen
 *
 *  This function prints an data array.
 *
 *  @param  ptr: pointer to data array
 *  @param  sz: size of data array 
 *  @return None
 **/
void print_array(unsigned char * ptr, unsigned int sz);

/**
 *  @brief   Find the mean in an data array
 *
 *  This function take the pointer to an data array and returns the mean.
 *
 *  @param  ptr: pointer to a data array
 *  @param  sz: size of the data array 
 *  @return The mean value of the data array
 **/
unsigned char find_mean(unsigned char * ptr, unsigned int sz);

/**
 *  @brief   Find the median in an data array
 *
 *  This function take the pointer to an data array and returns the median.
 *
 *  @param  ptr: pointer to a data array
 *  @param  sz: size of the data array 
 *  @return The median value ot the data array
 */
unsigned char find_median(unsigned char * ptr, unsigned int sz);

/**
 *  @brief   Find the minimum in an data array
 *
 *  This function take the pointer to an data array and returns the minimum.
 *
 *  @param  ptr: pointer to a data array
 *  @param  sz: size of the data array 
 *  @return The minimum value of the data array
 */
unsigned char find_minimum(unsigned char * ptr, unsigned int sz);

/**
 *  @brief   Find the maximum in an data array
 *
 *  This function take the pointer to an data array and returns the maximum.
 *
 *  @param  ptr: pointer to a data array
 *  @param  sz: size of the data array 
 *  @return The maximum value of the data array
 */
unsigned char find_maximum(unsigned char * ptr, unsigned int sz);

/**
 *  @brief   Sorted the array
 * 
 *  This function take the pointer to an data array and sorts the array 
 *  from largest to smallest.
 *
 *  @param  ptr: pointer to a data array
 *  @param  sz: size of the data array 
 *  @return The median value of the data array
 **/
void sort_array(unsigned char * ptr, unsigned int sz);

