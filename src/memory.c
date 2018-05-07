/******************************************************************************
*
* Copyrigth (C) 2018 by Lukoyanova Tatyana - Company of Nizhniy Novgorod
*
******************************************************************************/

/**
 * @file memory.c 
 * @brief Memory manipulation functions
 *
 * @autor Lukoyanova Tatyana
 * @date 06/05/2018
 *  
 **/

#include "memory.h"

/***********************************************************
 Function Definitions
***********************************************************/
void set_value(char * ptr, unsigned int index, char value){
  ptr[index] = value;
}

void clear_value(char * ptr, unsigned int index){
  set_value(ptr, index, 0);
}

char get_value(char * ptr, unsigned int index){
  return ptr[index];
}

void set_all(char * ptr, char value, unsigned int size){
  unsigned int i;
  for(i = 0; i < size; i++) {
    set_value(ptr, i, value);
  }
}

void clear_all(char * ptr, unsigned int size){
  set_all(ptr, 0, size);
}

uint8_t * my_memmove(uint8_t * src, uint8_t * dst, size_t length){
  int i;
  //Check of null pointers
  if (src==NULL || dst==NULL || length==0){ 
    return NULL;
  }
  //Move src to temporary array	
  uint8_t * temp = (uint8_t *)malloc(length*sizeof(uint8_t));
  for (i = 0 ; i < length ; i++){
    *(temp + i) = *(src + i) ;
  }
  //Move temporary array to dst
  for (i = 0 ; i < length ; i++){
    *(dst + i) = *(temp + i) ;
  }
  free(temp);
  //Return dst pointer
  return dst;
}

uint8_t * my_memcopy(uint8_t * src, uint8_t * dst, size_t length){
  uint32_t i;
  //Check of null pointers
  if (src==NULL || dst==NULL || length==0){ 
    return NULL;
  }
  for (i = 0 ; i < length ; i++){
    *(dst + i) = *(src + i) ;
  }
  //Return dst pointer
  return dst;
}

uint8_t * my_memset(uint8_t * src, size_t length, uint8_t value){
  uint32_t i;
  //Check of null pointer
  if (src==NULL || length==0){
    return NULL;
  }
  for ( i = 0 ; i < length ; i++){
    *(src + i) = value ; 
  }
  //Return src pointer
  return src;
}

uint8_t * my_memzero(uint8_t * src, size_t length){
  uint32_t i;
  //Check of null pointer
  if (src==NULL || length==0){
    return NULL;
  }
  for ( i = 0 ; i < length ; i++){
    *(src + i) = 0 ; 
  }
  //Return src pointer
  return src;
}
   
uint8_t * my_reverse(uint8_t * src, size_t length){
  int i;
  uint8_t temp;
  //Check of null pointer
  if (src==NULL || length==0){
    return NULL;
  }
  for (i = 0 ; i < (length / 2 ) ; i++){
    temp = *(src+i);
    *(src+i) = *(src + length - 1  - i);
    *(src + length - 1  - i) = temp;
  }
  //Return src pointer
  return src;
}

int32_t * reserve_words(size_t length){
  return malloc(length*sizeof(int32_t));
}
 
void free_words(uint32_t * src){
  free(src);
  src=NULL;
}


