/******************************************************************************
** Program name: Zoo Tycoon
** Author: Rebecca L. Taylor
** Date: 22 October 2017
** Description: This implementation file defines the constructor of the Tiger
    class. Other member variables and functions are inherited from the parent
    Animal class.
******************************************************************************/

#include "Tiger.hpp"
#include "getInteger.hpp"

/******************************************************************************
//Definition of Tiger::Tiger constructor
//The function sets all member variables inherited from the Animal class to
//the appropriate amount.
******************************************************************************/
Tiger::Tiger()
{
    setAge(0);
    setCost(10000);             //Tiger cost equals $10,000
    setNumBabies(1);            //Tigers have one baby
    setFoodCost((foodCost*5));  //Tiger's food cost is 5 times base food cost
    setPayoff((cost/5));        //Tiger's payoff is 20% of cost
}


