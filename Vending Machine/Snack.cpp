/*****************************************************************************
** Author: Rebecca L. Taylor 
** Date: 10 May 2017
** Description: This file contains the function definitions for the methods
     of the Snack class. They get the three data members of the class.
     Two constructors initialize the data members.
*****************************************************************************/

#include <string>
#include "Snack.hpp"

//Snack::getName to get the name of the snack
std::string Snack::getName()
{
   return snackName;
}

//Snack::getPrice to get price of the snack
double Snack::getPrice()
{
   return snackPrice;
}

//Snack::getNumCalories to get calories of the snack
int Snack::getNumCalories()
{
   return snackNumCalories; 
}

/****************************************************************************
 *                         Snack::Snack                                     *
 *      Constructor with three parameters to initialize snackName,          *
 *      snackPrice, and snackNumCalories                                    *
 ***************************************************************************/           
Snack::Snack(std::string name, double price, int calories)
{
  snackName = name;
  snackPrice = price;
  snackNumCalories = calories;
}

/****************************************************************************
 *                         Snack::Snack                                     *
 *      Default constructor initializing data members to "bottled water",   *
 *      1.75, and 0                                                         *
 ***************************************************************************/           
Snack::Snack()
{
  snackName = "bottled water";
  snackPrice = 1.75;
  snackNumCalories = 0;
}


