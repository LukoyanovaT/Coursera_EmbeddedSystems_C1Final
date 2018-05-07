/******************************************************************************
 * Copyright (C) 2018 by Tatyana Lukoyanova - Company of Nizhniy Novgorog
 *
 *****************************************************************************/
/**
 * @file main.c
 * @brief Main entry point to the C1Final Assessment
 *
 * This file contains the main code for the C1Final assesment.
 *
 *
 */

#ifdef COURSE1
  #include "course1.h"
  
  int main(void){
    course1();
    return 0;
  }
#endif

#ifdef C1M2
  #include "platform.h"
  #include "memory.h"
    
  #define MAX_LENGTH (10)
  char buffer[MAX_LENGTH];

  int main(void) {
 
    unsigned int i;
    char value;

    /* Code below does some arbitrary memory Reads & writes */
    clear_all(buffer, MAX_LENGTH);
    set_all( ( buffer + 8 ), 43, 2); 
    set_value(buffer, 0, 0x61);
    value = get_value(buffer, 9);
    set_value(buffer, 9, (value + 0x27));
    set_value(buffer, 3, 0x37);
    set_value(buffer, 1, 88);
    set_value(buffer, 4, '2');
    value = get_value(buffer, 1);
    set_value(buffer, 2, 121);
    set_value(buffer, 7, (value - 12));
    set_value(buffer, 5, 0x5F);

    for ( i = 0; i < MAX_LENGTH; i++ ){
      PRINTF("%c", buffer[i]);
    }
    PRINTF("\n");
 
  return 0;
}
#endif

#ifdef C1M1

  #include <stdint.h>
  #include "stats.h"

  /* Size of the Data Set*/
  #define SIZE 40
 
  int main()
  {
    /* Variable Declaration */
    uint8_t array[SIZE]={200, 235, 170,  34,  56,  94, 177, 83, 17, 45,\
                      188,  21,   1,  99,  12,  33, 155, 73,  7, 14,\
                      244, 114, 168,  95,  63,  91,   9, 11, 15, 53,\
                      211, 171, 234, 176, 222, 111,  93,  6,  3,  8};
    uint8_t * ptr = array;
    uint8_t max, min, mean, med=0;
    
    /*Statistics and Printings Functions */
    PRINTF("Source array:\n");
    print_array(ptr, SIZE);

    max  = find_maximum(ptr, SIZE);
    min  = find_minimum(ptr, SIZE);
    mean = find_mean(ptr, SIZE);
    med  = find_median(ptr, SIZE);
    print_statistics(max,min,mean,med);

    PRINTF("Sorted array:\n");
    print_array(ptr, SIZE);
    return(0);
  }
#endif
