/******************************************************************************
*
* Copyrigth (C) 2018 by Lukoyanova Tatyana - Company of Nizhniy Novgorod
*
******************************************************************************/

/**
 * @file stats.c 
 * @brief Char array statistical analytics
 *
 * This is a simple applicationi prints the statistics of an data array 
 * including minimum, maximum, mean and median.
 *
 *
 * @autor Lukoyanova Tatyana
 * @date 15/04/2018
 *  
 **/

#include <stdio.h>
#include "stats.h"

/* This function finds the maximum value of the array. */
unsigned char find_maximum(unsigned char * ptr, unsigned int sz){
  unsigned int i;
  unsigned char max;
  max=*ptr;
  for(i=0;i<sz;i++){
    if(*(ptr+i)>max){
       max=*(ptr+i);
    }
  }
  return(max);
}

/* This function finds the miminum value of the array. */
unsigned char find_minimum(unsigned char * ptr, unsigned int sz){
  unsigned int i;
  unsigned char min;
  min=*ptr;
  for(i=1;i<sz;i++){
      if(*(ptr+i)<min){
             min=*(ptr+i);
          }
    }
  return (min);
}

/* This function find the mean value of the array. */
unsigned char find_mean(unsigned char * ptr, unsigned int sz){
  unsigned int i;
  unsigned int sum=0;
 
  for(i=0;i<sz;i++){
    sum += *(ptr+i);
  }
  return(sum/sz);
}

/*This function find median value of the array. */
unsigned char find_median(unsigned char * ptr, unsigned int sz){
  unsigned int med=0;

  sort_array(ptr, sz);
  if(sz%2) {
    med = (*(ptr + sz/2));
  }
  else {
    med = ( *(ptr+sz/2) + *(ptr + sz/2 - 1) ) / 2;
  }
  return(med);
}

/*This function sorts the contents of the array. */
void sort_array(unsigned char * ptr, unsigned int sz){
  unsigned int i, j;
  unsigned char swap;

  for(j=0;j<(sz-1);j++){
    for(i=0;i<(sz-j-1);i++){
      if(*(ptr+i)>*(ptr+i+1)){
        swap       = *(ptr+i);
        *(ptr+i)   = *(ptr+i+1);
        *(ptr+i+1) = swap;
      }
    }
  }
}

/* This function prints the contents of the array. */
void print_array(unsigned char * ptr, unsigned int sz){
  unsigned int i;
  for(i=0;i<sz;i++){
    PRINTF("\tarray[%2d] = %2x\n", i, (*(ptr+i)));
  }
    PRINTF("\n\n"); 
}

/* This function prints the statistics of the array. */
void print_statistics(unsigned char max, unsigned char min,\
		     unsigned char mean, unsigned char med){
  printf("Statistics:\n");
  printf("\tThe maximum of data array\t= %3d\n", max);
  printf("\tThe minimum of data array\t= %3d\n", min);
  printf("\tThe median of data array \t= %3d\n", med);
  printf("\tThe mean of data array   \t= %3d\n", mean);
}


