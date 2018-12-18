/*****************************************************************************
** Author: Rebecca L. Taylor
** Date: 10 May 2017
** Description: This header file declares the class VendSlot as well as its
     member variables and functions.
*****************************************************************************/

#ifndef VENDSLOT_HPP
#define VENDSLOT_HPP

#include "Snack.hpp"

//VendSlot class declaration
class VendSlot
{
   private:
     Snack snackFood;
     int snackAmount;  

   public:
     //Constructor with two parameters to initialize snackFood
     //and snackAmount
     VendSlot(Snack snackIn, int snackAmountIn);

     //Default constructor 
     VendSlot();

     //Get functions
     Snack getSnack();
     int getAmount();

    //Function to decrement amount
    void decrementAmount();

 };
#endif 
   
    
