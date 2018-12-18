/****************************************************************************
** Author: Rebecca L. Taylor
** Date: 17 May 2017
** Description: This function calculates the standard deviation of
                the ages of a given group of people.
 * *************************************************************************/

#include <cmath>
#include "Person.hpp"

double stdDev(Person personArray[], int arraySize)
{
   double total = 0.0;
   double sd = 0.0;
   double avg;

   //Find the average
   for (int count = 0; count < arraySize; count++)
      total += personArray[count].getAge();
      avg = total / arraySize;

   //Find the standard deviation
   for (int count = 0; count < arraySize; count++)
       sd += pow((personArray[count].getAge() - avg), 2);

   return sqrt(sd / arraySize);   
}

