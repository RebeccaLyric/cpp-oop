/******************************************************************************
** Program name: Fantasy Combat Game
** Author: Rebecca L. Taylor
** Date: 19 November 2017
** Description: This implementation file defines the member functions of the
    Vampire class derived from the Character base class. It includes a
    constructor as well as overridden getName and defend functions. The charm
    functions determined whether the Vampire will prevent the opponent from
    attacking.
******************************************************************************/

#include "Vampire.hpp"

#include <iostream>
#include <stdlib.h>
using std::cout;
using std::endl;

/******************************************************************************
//Definition of Vampire::Vampire constructor
//The function sets the default values of a Barbarian character, including
//attack dice, defense dice, armor, and strength.
******************************************************************************/
Vampire::Vampire()
{
    //Vampire attacks with one twelve-sided die
    attackSides = 12;
    attackDice = 1;

    //Vampire defends with one six-sided die
    defenseSides = 6;
    defenseDice = 1;

    //Vampire has 1 armor and starts with strength 18
    armor = 1;
    strength = 18;
}

/******************************************************************************
//Definition of Vampire::getName
//The function overrides the Base class pure virtual getName function and
//returns as a string the word "Vampire"
******************************************************************************/
string Vampire::getType() const
{
    return "Vampire";
}

/******************************************************************************
//Definition of Vampire::defend
//The function overrides the pure virtual defend function and takes the
//attacker's roll as an int parameter. It first calls the charm function to
//determine whether charm will take effect. If charm is effective, Vampire
//occurs zero damage. If charm not effective, the base class calcDefense and
//calcDamage functions determine the result of the attack. The function then
//returns a bool indicating whether the character has died.
******************************************************************************/
bool Vampire::defend(const int &attackRoll)
{
    int charmEffect = charm();         //Determine whether charm effective

    //If charm is effective
    if (charmEffect == 1)
    {
        cout << "No damage, Vampire strength remains at " << strength << endl;
    }

    //Else if charm not effective
    else
    {
        //Calculate defense roll and effect on strength
        int defense = calcDefense();
        calcDamage(attackRoll, defense);
    }

    //Test if character has died.
    return checkDeath();
}

/******************************************************************************
//Definition of Vampire::charm
//Vampire's glare ability means there is a 50% chance the opponent does not
//actually attack. The function randomly selects either 1 or 2 to determine
//if charm is effective, then passes the result out as an integer. It also
//prints a message and returns an int indicating whether charm was effective.
******************************************************************************/
int Vampire::charm()
{
    //Determine 50% chance of whether charmNum takes effect
    int min = 1;
    int max = 2;
    int charmNum = min + (rand() % (max - min + 1));

    //If charmNum takes effect
    if (charmNum == 1)
    {
        cout << "The Vampire's charm prevented the opponent "
             << "from actually attacking!" << endl;

    }

    //Else if charm does not take effect
    else if (charmNum == 2)
    {
        cout << "The Vampire's charm failed to prevent opponent from attacking"
             << " :-(" << endl;
    }

    return charmNum;
}
