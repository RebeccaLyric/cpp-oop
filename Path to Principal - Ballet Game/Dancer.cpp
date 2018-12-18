/******************************************************************************
** Program name: Path to Principal: A Ballet Game
** Author: Rebecca L. Taylor
** Date: 5 December 2017
** Description: This implementation file defines the member functions
    of the Dancer class representing the player of the game.
******************************************************************************/

#include "Dancer.hpp"

#include <iostream>
using std::cout;
using std::endl;

#include <algorithm>

/******************************************************************************
//Definition of Dancer::calcEnergy
//The function takes an int parameter which is added to the Dancer's energy.
******************************************************************************/
void Dancer::calcEnergy(const int &change)
{
    energy += change;
}

/******************************************************************************
//Definition of Dancer::addItem
//The function takes a string parameter. It checks if the string is already
//in the danceBag vector and adds it if not.
******************************************************************************/
void Dancer::addItem(const string &item)
{
   if (std::find(danceBag.begin(), danceBag.end(), item) == danceBag.end())
   {
       danceBag.push_back(item);
   }
}

/******************************************************************************
//Definition of Dancer::printDanceBag
//The function checks to make sure the danceBag is not empty. If not,
//each string element is printed.
******************************************************************************/
void Dancer::printDanceBag()
{
    cout << "Your dance bag has: ";

    if (danceBag.empty())
    {
        cout << "nothing. It's empty" << endl;
    }

    else
    {
        for (std::vector<string>::iterator iter = danceBag.begin(); 
             iter != danceBag.end(); iter++)
        {
            std::cout << *iter << " - ";
        }
    }
    cout << endl;
}

/******************************************************************************
//Definition of Dancer::findRoses
//The function returns a bool indicating whether roses are in the dance bag.
******************************************************************************/
bool Dancer::findRoses()
{
    return std::find(danceBag.begin(), danceBag.end(), "bouquet of roses")
           != danceBag.end();
}

/******************************************************************************
//Definition of Dancer::setCurrentSpace
//The function has a parameter of a pointer Space object which is used to set
//the current space.
******************************************************************************/
void Dancer::setCurrentSpace(Space *spaceIn)
{
    currentSpace = spaceIn;
}

/******************************************************************************
//Definition of Dancer::getCurrentSpace
//The function returns a pointer to Space object.
******************************************************************************/
Space *Dancer::getCurrentSpace() const
{
    return currentSpace;
}

/******************************************************************************
//Definition of Dancer::setEnergy
//The function takes an int parameter to set the Dancer's energy
******************************************************************************/
void Dancer::setEnergy(const int &energy)
{
    this->energy = energy;
}

/******************************************************************************
//Definition of Dancer::getEnergy
//The function returns the dancer's energy as an int
******************************************************************************/
int Dancer::getEnergy() const
{
    return energy;
}


/******************************************************************************
//Definition of Dancer::emptyDanceBag
//The function clears the vector containing the items of the dance bag.
******************************************************************************/
void Dancer::emptyDanceBag()
{
    danceBag.clear();
}















