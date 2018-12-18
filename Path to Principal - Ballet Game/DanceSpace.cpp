/******************************************************************************
** Program name: Path to Principal: A Ballet Game
** Author: Rebecca L. Taylor
** Date: 5 December 2017
** Description: This implementation file defines the member functions
    of the DanceSpace class, a derived class of Space and the parent class of
    PracticeStudio and Stage.
******************************************************************************/

#include "DanceSpace.hpp"

#include <iostream>
using std::cout;
using std::endl;

#include <stdlib.h>

/******************************************************************************
//Definition of DanceSpace::DanceSpace constructor
//The function initializes room completion to false.
******************************************************************************/
DanceSpace::DanceSpace()
{
    complete = false;
}

/******************************************************************************
//Definition of DanceSpace::outcome
//The function overrides the base class function and returns a random int
//indicating the outcome of the action.
******************************************************************************/
int DanceSpace::outcome()
{
    int min = 1;                            //Minimum for random outcome
    int max = 3;                            //Maximum for random outcome

    int result = min + (rand() % (max - min + 1));

    return result;
}

/******************************************************************************
//Definition of DanceSpace::setItem
//The function takes a string parameter used to set the dance bag item
//earned from the space.
******************************************************************************/
void DanceSpace::setItem(const string &item)
{
    this->item = item;
}

/******************************************************************************
//Definition of DanceSpace::getItem
//The function returns the dance bag item earned from the space as a string.
******************************************************************************/
string DanceSpace::getItem() const
{
    return item;
}

/******************************************************************************
//Definition of DanceSpace::getExertion
//The function returns an int of the amount of energy lost each attempt
******************************************************************************/
int DanceSpace::getExertion() const
{
    return exertion;
}

/******************************************************************************
//Definition of DanceSpace::getMinComplete
//The function returns as an int the minimum number of steps or performances
//required to complete the space.
******************************************************************************/
int DanceSpace::getMinComplete() const
{
    return minComplete;
}


