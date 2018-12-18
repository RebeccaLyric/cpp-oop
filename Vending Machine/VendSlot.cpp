/*****************************************************************************
** Author: Rebecca L. Taylor 
** Date: 10 May 2017
** Description: This file contains the function definitions for the methods
     of the VendSlot class. The get methods get the names of the data
     members. Two constructors initialize the data memers. The final 
     function decrements the amount of Snack in the VendSlot by 1.
*****************************************************************************/

#include <string>
#include "VendSlot.hpp"

//VendSlot::getSnack to get the name of a Snack
Snack VendSlot::getSnack()
{
   return snackFood;
}

//VendSlot::getAmount to get amount of snackFood in slot
int VendSlot::getAmount()
{
   return snackAmount;
}

/****************************************************************************
 *                         VendSlot::VendSlot                               * 
 *      Constructor with two parameters to initialize snackFood             * 
 *      and snackAmount                                                     *
 ***************************************************************************/           
VendSlot::VendSlot(Snack snackIn, int snackAmountIn)
{
  snackFood = snackIn;
  snackAmount = snackAmountIn;
}

/****************************************************************************
 *                        VendSlot::VendSlot                                *
 *      Default constructor initializing default Snack object and 5         *
 ***************************************************************************/           
VendSlot::VendSlot()
{
  snackFood = Snack();
  snackAmount = 5;
}

/****************************************************************************
 *                      VendSlot::decrementAmount                           *
 *         Function to decrease the snackAmount by 1                        *
 ****************************************************************************/

void VendSlot::decrementAmount()
{
  snackAmount--;
}                      
