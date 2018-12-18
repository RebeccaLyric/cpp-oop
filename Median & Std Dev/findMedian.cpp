/*****************************************************************************
** Author: Rebecca L. Taylor
** Date: 17 May 2017
** Description: This function returns the median of an array.
******************************************************************************/
 
#include <algorithm>

double findMedian(int intArray[], int arraySize)

{
   double med;

   //Sort the array
   std::sort(intArray, intArray + arraySize);

   //If array size is odd, get element from middle of sorted array
   if (arraySize % 2 != 0)         
      med = intArray[arraySize/2];

   //If array size is even, average two middle elements of sorted array
   else                            
      med = (intArray[arraySize/2] + intArray[(arraySize/2)-1]) / 2.0;

   return med;   
}
