/******************************************************************************
** Program name: War game with dice design
** Author: Rebecca L. Taylor
** Date: 15 October 2017
** Description:  This header file declares the LoadedDie class along with its 
    member functions. It inherits an int variable for the number of sides on
    the die and overrides the rollDie() functions of the Die base class.
******************************************************************************/

#ifndef LOADEDDIE_HPP
#define LOADEDDIE_HPP

#include "Die.hpp"

class LoadedDie : public Die
{

public:
    LoadedDie();
    LoadedDie(int numSides);
    int rollDie();
};

#endif //LOADEDDIE_HPP
