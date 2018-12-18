/******************************************************************************
** Program name: War game with dice design
** Author: Rebecca L. Taylor
** Date: 15 October 2017
** Description:  This header file declares the Die class along with its 
    member variable and functions. Die is the base class for the LoadedDie
    class.
******************************************************************************/

#ifndef DIE_HPP
#define DIE_HPP

class Die
{
protected:
    int numSides;

public:
    Die();
    Die(int numSides);
    int rollDie();
    int getSides() const;
};

#endif //DIE_HPP
