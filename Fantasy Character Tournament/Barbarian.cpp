/******************************************************************************
** Program name: Fantasy Combat Tournament
** Author: Rebecca L. Taylor
** Date: 19 November 2017
** Description: This implementation file defines the member functions of the
    Barbarian class derived from the Character base class. It includes a
    constructor as well as overridden getName and defend functions.
******************************************************************************/

#include "Barbarian.hpp"

#include <iostream>
using std::cout;
using std::endl;

/******************************************************************************
//Definition of Barbarian::Barbarian constructor
//The function sets the default values of a Barbarian character, including
//attack dice, defense dice, armor, and strength.
******************************************************************************/
Barbarian::Barbarian()
{
    //Barbarian attacks with two six-sided dice
    attackSides = 6;
    attackDice = 2;

    //Barbarian defends with two six-sided dice
    defenseSides = 6;
    defenseDice = 2;

    //Barbarian has zero armor and begins with strength 12
    armor = 0;
    strength = 12;
}

/******************************************************************************
//Definition of Barbarian::getName
//The function overrides the Base class pure virtual getName function and
//returns as a string the word "Barbarian"
******************************************************************************/
string Barbarian::getType() const
{
    return "Barbarian";
}

/******************************************************************************
//Definition of Barbarian::defend
//The function overrides the pure virtual defend function and takes the
//attacker's roll as an int parameter. It calls the base class calcDefense,
//calcDamage, and checkDeath functions, then returns a bool indicating whether
//the character has died as a result of the attack.
******************************************************************************/
bool Barbarian::defend(const int &attackRollIn)
{
    int defense = calcDefense();       //Calculate defense roll
    calcDamage(attackRollIn, defense); //Calculate damage and strength loss
    return checkDeath();               //Test if character has died
}

