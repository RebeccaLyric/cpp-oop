/******************************************************************************
** Program name: Fantasy Combat Tournament
** Author: Rebecca L. Taylor
** Date: 19 November 2017
** Description: This header file defines the member functions of the Blue Men
    class derived from the Character base class, including a constructor and
    overrides for the getName and defend functions. It also adds a variable
    and the diceLost function because the Blue Men lose one defense die for
    every four points of accumulated damage.
******************************************************************************/

#ifndef BLUEMEN_HPP
#define BLUEMEN_HPP

#include "Character.hpp"

class BlueMen : public Character
{
private:
    int totalDamage;              //Variable to keep track of cumulative damage

public:
    BlueMen();
    string getType() const override;
    bool defend(const int &attackRoll) override;
    void diceLost();
};

#endif //BLUEMEN_HPP
