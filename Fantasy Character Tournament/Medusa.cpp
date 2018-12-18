/******************************************************************************
** Program name: Fantasy Combat Tournament
** Author: Rebecca L. Taylor
** Date: 19 November 2017
** Description: This implementation file defines the member functions of the
    Medusa class derived from the Character base class. It includes a
    constructor as well as overridden attack and defend functions.
******************************************************************************/

#include "Medusa.hpp"

#include <iostream>
using std::cout;
using std::endl;

/******************************************************************************
//Definition of Medusa::Medusa constructor
///The function sets the default values of a Medusa character, including
//attack dice, defense dice, armor, and strength.
******************************************************************************/
Medusa::Medusa()
{
    //Medusa attacks with two six-sided dice
    attackSides = 6;
    attackDice = 2;

    //Medusa defends with one six-sided die
    defenseSides = 6;
    defenseDice = 1;

    //Medusa has three armor and begins with strength 8
    armor = 3;
    strength = 8;
}

/******************************************************************************
//Definition of Medusa::getName
//The function overrides the Base class pure virtual getName function and
//returns as a string the word "Medusa"
******************************************************************************/
string Medusa::getType() const
{
    return "Medusa";
}

/******************************************************************************
//Definition of Medusa::attack
//The function overrides the virtual attack function from the base class. The
//base class attack is assigned to medusaAttack. If medusaAttack is equals 12,
//it prints a message that the opponent was turned to stone and the attack
//value is set to 100 and returned.
******************************************************************************/
int Medusa::attack()
{
    //First execute base class attack function
    int medusaAttack = Character::attack();
    //int medusaAttack = 12;       //Test Glare ability 

    //If Medusa rolls 12, opponent turned to stone and instantly dies
    if (medusaAttack == 12)
    {
        cout << "Medusa attack roll of 12 means her glare "
             << "turns the opponent to stone!" << endl;

        medusaAttack = 100;        //Attack set to 100 to kill opponent
    }

    return medusaAttack;
}

/******************************************************************************
//Definition of Medusa::defend
//The function overrides the pure virtual defend function and takes the
//attacker's roll as an int parameter. It calls the base class calcDefense,
//calcDamage, and checkDeath functions, then returns a bool indicating whether
//the character has died as a result of the attack.
******************************************************************************/
bool Medusa::defend(const int &attackRollIn)
{
    int defense = calcDefense();       //Calculate defense roll
    calcDamage(attackRollIn, defense); //Calculate damage and strength loss
    return checkDeath();               //Test if character has died
}



