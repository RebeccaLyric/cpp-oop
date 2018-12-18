/******************************************************************************
** Program name: Fantasy Combat Tournament
** Author: Rebecca L. Taylor
** Date: 19 November 2017
** Description: This implementation file defines the member functions of the
    Harry Potter class derived from the Character base class. It includes a
    constructor as well as overridden getName, defend, and calcDamage
    functions. Two additional functions allow outside classes to access and
    change the variable for whether Harry Potter has already used the Hogwarts
    ability to come back from the dead.
******************************************************************************/

#include "HarryPotter.hpp"

#include <iostream>
using std::cout;
using std::endl;

/******************************************************************************
//Definition of HarryPotter::HarryPotter constructor
//The function sets the default values of a Harry Potter character, including
//attack dice, defense dice, armor, and strength.
******************************************************************************/
HarryPotter::HarryPotter()
{
    //Harry Potter attacks with two six-sided dice
    attackSides = 6;
    attackDice = 2;

    //Harry Potter defends with two six-sided dice
    defenseSides = 6;
    defenseDice = 2;

    //Harry Potter has zero armor and begins with 10 strength
    armor = 0;
    strength = 10;

    //bool for whether Harry Potter has died
    hpDeath = false;
}

/******************************************************************************
//Definition of HarryPotter::getName
//The function overrides the Base class pure virtual getName function and
//returns as a string the words "Harry Potter"
******************************************************************************/
string HarryPotter::getType() const
{
    return "Harry Potter";
}

/******************************************************************************
//Definition of HarryPotter::defend
//The function overrides the pure virtual defend function and takes the
//attacker's roll as an int parameter. It calls the base class calcDefense,
//calcDamage, and checkDeath functions, then returns a bool indicating whether
//the character has died as a result of the attack.
******************************************************************************/
bool HarryPotter::defend(const int &attackRollIn)
{
    int defense = calcDefense();       //Calculate defense roll
    calcDamage(attackRollIn, defense); //Calculate damage and strength loss
    return checkDeath();               //Test if character has died
}

/******************************************************************************
//Definition of HarryPotter::calcDamage
//The function overrides the calcDamage of the base class. It takes two int
//parameters of the attack and defense values. First the base class damage
//sets the damage and strength loss. If strength is <= 0 and Harry Potter has
//not already died, his strength is set to 20, a message is printed, and the
//counter for number of times Harry Potter has died is incremented. Harry
//Potter's strength is returned as an int.
******************************************************************************/
int HarryPotter::calcDamage(int attackIn, int defenseIn)
{
    Character::calcDamage(attackIn, defenseIn);

    if (strength <= 0 && hpDeath == 0)
    {
        strength = 20;

        cout << "Harry Potter used his Hogwarts power to come back to life!"
             << endl << "His strength is now " << strength << "!" 
             << endl;

        hpDeath = true;
    }

    return strength;
}

/******************************************************************************
//Definition of Character::getHPDeathCount
//The function returns as a bool whether Harry Potter has already died.
******************************************************************************/
bool HarryPotter::getHPDeathCount()
{
    return hpDeath;
}

/******************************************************************************
//Definition of Character::addHPDeathCount
//The function sets the bool for whether Harry Potter has died to true
******************************************************************************/
void HarryPotter::addHPDeath()
{
    hpDeath = true;
}

