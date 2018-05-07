/******************************************************************************
*
* Copyrigth (C) 2018 by Lukoyanova Tatyana - Company of Nizhniy Novgorod
*
******************************************************************************/

/**
 * @file data.c 
 * @brief This file should do some very basic data manipulation.
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

#include "data.h"

uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base){
  uint32_t i = 0;/*Return the length of the converted data*/
  uint32_t Remainder=0;
  bool negValue = false;

  /* Check the input parameters of the function */
  if(data>0xFFFFFFFF || ptr==NULL || base<2 || base>16){
    /*Anyone values is not valid*/
    i=0;   
  }else{     
    /*All values is valid*/
    if (data==0){
      /*If value is zero, then placed null terminator 
       *at the end of the converted c-string */
      *ptr = '0';
      i++;
      *(++ptr) = '\0';
      i++;
    }else{
      /*Integer value is different than zero*/
      /*Checking is value provided is negative and decimal base*/
      if (data<0){
        negValue = true;
        /*remove negative sign*/
        data=-data;
      }
      
      /*Convert the integer value in to base*/
      while (data!=0){
        Remainder = data % base;
        if(Remainder>9)
        {
          /*Character for hex values bigger than 9*/
          *(++ptr)=(Remainder-10)+0x41;// + ASCII "A"
        }else{
          *(++ptr)=Remainder+0x30;// + ASCII "0"
        }
        i++;
        /*calculate next 'bit'*/
        data = data/base;
      }

      /*If number is negative, added character '-'*/
      if (negValue){
        *(++ptr) = '-';
        i++;
      }

      /*Added string terminator*/
      *(++ptr) = '\0';
      i++;

      /* Reverse the string*/
      my_reverse(ptr-i,i);
    }
  }
  
  return i;
}

int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base){
  int32_t integerValue=0;
  uint32_t value=0;
  double power=1;
  bool negativeValue=false;

  if (ptr==NULL || digits<1 || digits>33 || base<2 || base>16){
    /*Pointer to array in NULL*/
    /*or*/
    /*Digits value is invalid */
    /*or*/
    /*Base value provided is invalid*/
    integerValue=0;
  }else{
    if(*ptr=='-'){
      /*String is a ASCII representation of a negative value*/
      negativeValue=true;
      ptr++;
      digits--;
    }

    /*Discounts string null termination*/
    digits--;

    /*Calculate the power valuer for the base conversion, starting from the highest weight*/
    for(int i=0;i<(digits-1);i++)
    {
      power=power*base;  
    }
    
    /*Check each element of array and converts the same to integer, based on provided base*/
    while(digits>0){ 
      if(*ptr>='0' && *ptr<='9'){
        value=*ptr-'0';
      }else{
        value=*ptr-'a'+10;
      }

      integerValue=integerValue+value*power;
      power=power/base;

      digits--;
      ptr++;
    }

    /*Apply the signal in case of negative value*/
    if(negativeValue==true){
      integerValue=-1*integerValue;
    }
  }
  return integerValue;
}
