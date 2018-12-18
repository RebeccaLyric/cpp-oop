/******************************************************************************
 ** Program name: War game with dice design
 ** Author: Rebecca L. Taylor
 ** Date: 15 October 2017
 ** Description:  This implementation file defines the functions of the
    Die class. It includes a default constructor, a constructor passed the
    number of sides, and the rollDie() function.  
 ******************************************************************************/

#include "Die.hpp"
#include <ctime>
#include <cstdlib>
using std::rand;

/******************************************************************************
//Definition of Die::Die default constructor
//The function sets the number of die sides to 6 as a default.
******************************************************************************/
Die::Die()
{
    numSides = 6;
}

/******************************************************************************
//Definition of Die::Die constructor
//The function creates a Die object using the number of sides specified in
//the integer paramater.
******************************************************************************/
Die::Die(int numSides)
{
    this -> numSides = numSides;
}

/******************************************************************************
//Definition of Die::rollDie() member function.
//The function simulates a random die roll. The minimum is set to 1 and 
//maximum is set to the number of sides on the die. 
******************************************************************************/
int Die::rollDie()
{
    //Source: https://stackoverflow.com/questions/5008804/
    //generating-random-integer-from-a-range
    int min = 1;
    int max = numSides;
    return min + (rand() % (max - min + 1));
}

/******************************************************************************
//Definition of Die::getSides() member function.
//The function returns the number of sides on the die.
******************************************************************************/
int Die::getSides() const
{
    return numSides;
}
