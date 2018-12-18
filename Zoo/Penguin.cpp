/******************************************************************************
** Program name: Zoo Tycoon
** Author: Rebecca L. Taylor
** Date: 22 October 2017
** Description: This implementation file defines the constructor of the Penguin
    class. Other member variables and functions are inherited from the parent
    Animal class.
******************************************************************************/

#include "Penguin.hpp"

/******************************************************************************
//Definition of Penguin::Penguin constructor
//The function sets all member variables inherited from the Animal class to
//the appropriate amount.
******************************************************************************/
Penguin::Penguin()
{
    setAge(0);
    setCost(1000);              //Penguin cost equals $1,000
    setNumBabies(5);            //Penguins have one baby
    setFoodCost(foodCost);      //Penguin's food cost equals base food cost
    setPayoff((cost/10));       //Penguin's payoff is 10% of cost
}
