/******************************************************************************
 ** Program name: War game with dice design
 ** Author: Rebecca L. Taylor
 ** Date: 15 October 2017
 ** Description:  This implementation file defines the functions of the
    LoadedDie class. It includes a default constructor, a constructor passed 
    the number of sides, and an overriden rollDie() function which biases
    the die to roll higher.
 ******************************************************************************/

#include "LoadedDie.hpp"
#include <ctime>
#include <cstdlib>
using std::rand;

/******************************************************************************
//Definition of LoadedDie::LoadedDie default constructor
//The function sets the number of die sides to 6 as a default.
******************************************************************************/
LoadedDie::LoadedDie()
{
    numSides = 6;
}

/******************************************************************************
//Definition of LoadedDie::LoadedDie constructor
//The function creates a Die object using the number of sides specified in
//the integer paramater.
******************************************************************************/
LoadedDie::LoadedDie(int numSides)
{
    this -> numSides = numSides;
}

/******************************************************************************
//Definition of LoadedDie::rollDie function
//The function
******************************************************************************/
int LoadedDie::rollDie()
{
    //Source 1: https://www.daniweb.com/programming/software-development
    //threads/331943/introducing-a-bias-during-random-number-generation,
    //Source 2: https://stackoverflow.com/questions/5008804/
    //generating-random-integer-from-a-range

    //Randomly select a number that will determine whether to use the bias
    int num = rand() % 10;  

    //If random number >= 3, use biased roll
    //Biased roll ensures number rolled is in upper half of die range
    if (num >= 3)
    {
        //Find middle number of die (will be truncated on odd-numbered die)
        int dieMiddle = numSides / 2;

        //Minimum set to middle of die, max set to number of sides 
        int min = dieMiddle;
        int max = numSides;
        return min + (rand() % (max - min + 1));
    }

    //If random number < 3, use regular roll
    else
    {
        //Minimum set to 1, max set to number of sides
        int min = 1;
        int max = numSides;
        return min + (rand() % (max - min + 1));
    }


}
