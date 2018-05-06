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

/* Size of the Data Set*/
#define SIZE 40

int main()
{
  /* Variable Declaration */
  char array[SIZE]={200, 235, 170,  34,  56,  94, 177, 83, 17, 45,\
                    188,  21,   1,  99,  12,  33, 155, 73,  7, 14,\
                    244, 114, 168,  95,  63,  91,   9, 11, 15, 53,\
                    211, 171, 234, 176, 222, 111,  93,  6,  3,  8};
  unsigned char * ptr = array;
  unsigned char max, min, mean, med=0;

  /*Statistics and Printings Functions */
  printf("Source array:\n");
  print_array(ptr, SIZE);

  max  = find_maximum(ptr, SIZE);
  min  = find_minimum(ptr, SIZE);
  mean = find_mean(ptr, SIZE);
  med  = find_median(ptr, SIZE);
  print_statistics(max,min,mean,med);

  printf("Sorted array:\n");
  print_array(ptr, SIZE);
  return(0);
}

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
  unsigned int i;
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
    printf("\tarray[%2d] = %3d\n", i, (*(ptr+i)));
  } 

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


