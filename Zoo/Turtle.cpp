/******************************************************************************
** Program name: Zoo Tycoon
** Author: Rebecca L. Taylor
** Date: 22 October 2017
** Description: This implementation file defines the constructor of the Turtle
    class. Other member variables and functions are inherited from the parent
    Animal class.
******************************************************************************/

#include "Turtle.hpp"

/******************************************************************************
//Definition of Turtle::Turtle constructor
//The function sets all member variables inherited from the Animal class to
//the appropriate amount.
******************************************************************************/
Turtle::Turtle()
{
    setAge(0);
    setCost(100);                //Turtles cost $100
    setNumBabies(10);            //Turtles have 10 babies
    setFoodCost((foodCost/2));   //Turtle's food cost is 50% of base food cost
    setPayoff((cost/20));        //Turtle's payoff is 5% of cost
}
