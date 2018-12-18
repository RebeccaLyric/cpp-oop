/******************************************************************************
** Program name: Fantasy Combat Tournament
** Author: Rebecca L. Taylor
** Date: 19 November 2017
** Description: This header file declares the member functions of the Harry
    Potter class derived from the Character base class, including a constructor
    and overrides for the getName and defend functions. An additional variable
    and functions are added to account for Harry Potter's Hogwarts ability to
    come back to life one time.
******************************************************************************/

#ifndef HARRYPOTTER_HPP
#define HARRYPOTTER_HPP

#include "Character.hpp"

class HarryPotter : public Character
{
private:
    bool hpDeath;                  //Counter for number of times HP dies

public:
    HarryPotter();
    string getType() const override;
    bool defend(const int &attackRoll) override;
    int calcDamage(int attackIn, int defenseIn) override;

    bool getHPDeathCount();
    void addHPDeath();
};

#endif //HARRYPOTTER_HPP
