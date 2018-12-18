/******************************************************************************
** Program name: Fantasy Combat Game
** Author: Rebecca L. Taylor
** Date: 19 November 2017
** Description: This header file defines the member functions of the Vampire
    class derived from the Character base class, including a constructor and
    overrides for the getName and defend functions. The additional charm
    function accounts for a Vampire's ability to prevent the opponent from
    actually attacking.
******************************************************************************/

#ifndef VAMPIRE_HPP
#define VAMPIRE_HPP

#include "Character.hpp"

class Vampire : public Character
{
public:
    Vampire();
    string getType() const override;
    bool defend(const int &attackRoll) override;
    int charm();
};

#endif //VAMPIRE_HPP
