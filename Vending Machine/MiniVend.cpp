/*****************************************************************************
** Author: Rebecca L. Taylor 
** Date: 10 May 2017
** Description: This file contains the function definitions for the methods
     of the MiniVend class. A get function returns the amount of money in the 
     vending machine and a constructor initializes the four slots plus the
     amount of money in the machine. Other functions return the number of
     slots with no snacks left, calculate the value of snack in the machine,
     and adjust values when a snack is purchased.  
*******************************************************************************/

#include <string>
#include "MiniVend.hpp"

//MiniVend::getMoney to get the amount of money in the vending machine
double MiniVend::getMoney()
{
   return machineMoney;
}

/****************************************************************************
 *                         MiniVend::MiniVend                               *
 *      Constructor with five parameters to initialize four VendSlots       *
 *      and initial machineMoney                                            *
 ***************************************************************************/           
MiniVend::MiniVend(VendSlot slot1, VendSlot slot2, VendSlot slot3,
                   VendSlot slot4, double money)
{
  vendSlot1 = slot1;
  vendSlot2 = slot2;
  vendSlot3 = slot3;
  vendSlot4 = slot4;
  machineMoney = money;
}

/****************************************************************************
 *                         MiniVend::numEmptySlots                          *
 *   Function to return the number of slots that have no Snacks left        *
 ***************************************************************************/           
 int MiniVend::numEmptySlots()
{
  int empty = 0;

  if(vendSlot1.getAmount() == 0)
    empty++;

  if(vendSlot2.getAmount() == 0)
    empty++;

  if(vendSlot3.getAmount() == 0)
    empty++;

  if(vendSlot4.getAmount() == 0)
    empty++;

  return empty;
}

/***************************************************************************
 *                         MiniVend::valueOfSnacks                         *
 *   Function to return the total value of Snacks in the machine           * 
 ***************************************************************************/          
double MiniVend::valueOfSnacks()
{
  double slot1Value, slot2Value, slot3Value, slot4Value;

  slot1Value = vendSlot1.getSnack().getPrice() * vendSlot1.getAmount();
  slot2Value = vendSlot2.getSnack().getPrice() * vendSlot2.getAmount();
  slot3Value = vendSlot3.getSnack().getPrice() * vendSlot3.getAmount();
  slot4Value = vendSlot4.getSnack().getPrice() * vendSlot4.getAmount();

  return slot1Value + slot2Value + slot3Value + slot4Value;
}

/***************************************************************************
 *                         MiniVend::buySnack                              *
 *   If VendSlot is not empty, function adjusts VendSlot amount and        * 
 *   value of snacks                                                       *
 ***************************************************************************/          
void MiniVend::buySnack(int slotNum)
{
  switch(slotNum)
  {
    case 0: if(vendSlot1.getAmount() > 0) 
              {
                vendSlot1.decrementAmount();
                machineMoney += vendSlot1.getSnack().getPrice(); 
              }
            break;
    
    case 1: if(vendSlot2.getAmount() > 0) 
              {
                vendSlot2.decrementAmount();
                machineMoney += vendSlot2.getSnack().getPrice(); 
              }
            break;

    case 2: if(vendSlot3.getAmount() > 0) 
              {
                vendSlot3.decrementAmount();
                machineMoney += vendSlot3.getSnack().getPrice(); 
              }
            break;
    
    case 3: if(vendSlot4.getAmount() > 0) 
              {
                vendSlot4.decrementAmount();
                machineMoney += vendSlot4.getSnack().getPrice(); 
              }
            break;
    
    default:
            break;
  }

}


 
