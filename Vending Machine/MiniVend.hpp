/*****************************************************************************
** Author: Rebecca L. Taylor
** Date: 10 May 2017
** Description: This header file declares the class MiniVend as well as its
     member variables and functions.
*****************************************************************************/

#ifndef MINIVEND_HPP
#define MINIVEND_HPP

#include "VendSlot.hpp"

//MiniVend class declaration
class MiniVend
{
   private:
     VendSlot vendSlot1;
     VendSlot vendSlot2;
     VendSlot vendSlot3;
     VendSlot vendSlot4;
     double machineMoney;

   public:
     //Constructor with five parameters to initialize four VendSlots  
     //and initial machineMoney
     MiniVend(VendSlot slot1, VendSlot slot2, VendSlot slot3, VendSlot slot4,
              double money);

     //Get function
     double getMoney();

     //Calculation functions
     int numEmptySlots();
     double valueOfSnacks();
     void buySnack(int slotNum);

 };
#endif 
   
    
