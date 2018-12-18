/******************************************************************************
** Program name: Fantasy Combat Tournament
** Author: Rebecca L. Taylor
** Date: 19 November 2017
** Description: This header file declares the member functions of the Medusa
    class derived from the Character base class. It includes a
    constructor as well as overridden getName, attack, and defend functions.
******************************************************************************/

#ifndef MEDUSA_HPP
#define MEDUSA_HPP

#include "Character.hpp"

class Medusa : public Character
{
public:
    Medusa();
    string getType() const override;
    int attack() override;
    bool defend(const int &attackRoll) override;
};


#endif //MEDUSA_HPP
