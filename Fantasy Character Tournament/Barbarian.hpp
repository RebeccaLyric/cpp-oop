/******************************************************************************
** Program name: Fantasy Combat Tournament
** Author: Rebecca L. Taylor
** Date: 19 November 2017
** Description: This header file defines the member functions of the Barbarian
    class derived from the Character base class, including a constructor and
    overrides for the getName and defend functions.
******************************************************************************/

#ifndef BARBARIAN_HPP
#define BARBARIAN_HPP

#include "Character.hpp"

class Barbarian : public Character
{
public:
    Barbarian();
    string getType() const override;
    bool defend(const int &attackRoll) override;
};

#endif //BARBARIAN_HPP
