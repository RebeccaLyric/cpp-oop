/******************************************************************************
** Program name: Fantasy Combat Tournament
** Author: Rebecca L. Taylor
** Date: 19 November 2017
** Description: This implementation file defines the member functions of
    the Character class, the abstract parent class for the five characters of
    the fantasy combat game: Vampire, Barbarian, Blue Men, Medusa, and
    Harry Potter.
******************************************************************************/

#include "Character.hpp"

#include <iostream>
#include <stdlib.h>
using std::cout;
using std::endl;

/******************************************************************************
//Definition of Character::Character constructor
//The function sets default values for the variables used for a Character
//object's attack and defense functions, including number of dice sides and
//number of die as well as armor and strength.
******************************************************************************/
Character::Character()
{
    attackRoll = 0;
    attackSides = 6;
    attackDice = 1;

    defenseRoll = 0;
    defenseSides = 6;
    defenseDice = 1;

    armor = 0;
    strength = 0;
}

/******************************************************************************
//Definition of Character::getName
//The function returns as an int the Character's strength
******************************************************************************/
string Character::getName() const
{
    return charName;
}

/******************************************************************************
//Definition of Character::setName
//The function takes an int parameter to set the value of the strength variable
******************************************************************************/
void Character::setName(const string &charName)
{
    this->charName = charName;
}

/******************************************************************************
//Definition of Character::setStrength
//The function takes an int parameter to set the value of the strength variable
******************************************************************************/
void Character::setStrength(const int &strength)
{
    this->strength = strength;
}

/******************************************************************************
//Definition of Character::getStrength
//The function returns as an int the Character's strength
******************************************************************************/
int Character::getStrength() const
{
    return strength;
}

/******************************************************************************
//Definition of Character::rollDice
//The function takes the number of sides per die and the number of dice as int
//parameters. For each die, it executes a random roll. The total of both rolls
//is returned as an int.
******************************************************************************/
int Character::rollDice(const int &dieSides, const int &numDice)
{
    int roll = 0;
    int min = 1;
    int max = dieSides;

    //Calculate roll for each die and add to roll total
    for (int i = 0; i < numDice; i++)
    {
        int tempRoll = min + (rand() % (max - min + 1));
        roll+=tempRoll;
    }

    return roll;
}

/******************************************************************************
//Definition of Character::attack
//The function calls the rollDice function to get the current attack and prints
//the attack information. The attack value is returned as an int.
******************************************************************************/
int Character::attack()
{
    //Reset attack roll to 0 and call rollDice to get current attack
    attackRoll = 0;
    attackRoll = rollDice(attackSides, attackDice);

    //Print attack information
    cout << "Attacker: " << getType() << " " << getName() << " rolled "
         << attackRoll << " with " << attackDice << " " << attackSides
         << "-sided di(c)e" << endl;

    return attackRoll;
}

/******************************************************************************
//Definition of Character::calcDefense
//The function calls the rollDice function to get the current defense and
//prints the defense information. The defense value is returned as an int.
******************************************************************************/
int Character::calcDefense()
{
    //Reset defense roll to 0 and call rollDice to get current defense
    defenseRoll = 0;
    defenseRoll = rollDice(defenseSides, defenseDice);

    //Print defense roll information
    int defense = defenseRoll + armor;
    cout << "Defender: " << getType() << " " << getName() << " (Strength "
         << strength << ")" << " rolled " << defenseRoll << " with "
         << defenseDice << " " << defenseSides << "-sided di(c)e" << endl;

    //Print armor and total defense information
    cout << "Defense roll " << defenseRoll << ", plus " << armor << " armor equals: "
         << defense << " total defense points" << endl;

    return defense;
}

/******************************************************************************
//Definition of Character::calcDamage
//The function takes the attack and defense values as int parameters and uses
//them to calculate the total damage. The total damage is printed and
//subtracted from the Character's strength. If the damage is negative, it is
//reset to zero and the Character's strength remains the same. The damage
//is returned as an int.
******************************************************************************/
int Character::calcDamage(int attackIn, int defenseIn)
{
    //Calculate damage and effect on strength
    int damage = attackIn - defenseIn;
    cout << attackIn << " attack strength minus " << defenseIn
         << " defense strength equals: " << damage << " damage" << endl;

    //If damage is negative, set to zero
    if (damage < 0)
    {
        damage = 0;
        cout << getName() << " incur(s) zero damage!" << endl;
    }

    //Subtract damage from strength
    cout << strength << " strength minus " << damage << " damage: ";
    strength -= damage;

    cout << getType() << " " << getName() << " has " << strength
         << " strength remaining" << endl;

    return damage;
}

/******************************************************************************
//Definition of Character::recover
//The function takes a pointer to Character as its parameter. It calls the
//rollDie function to select a random number between 1 and the character's
//existing strength. The random number is added to the character's strength
//and the recovered strength is printed.
******************************************************************************/
void Character::recover()
{
    int recoverSides = strength;
    int recoverDice = 1;
    int recoverRoll = rollDice(recoverSides, recoverDice);

    strength += recoverRoll;

    cout << "recovered " << recoverRoll
         << " point(s) of strength. Strength is now: " << strength
         << endl;
}

/******************************************************************************
//Definition of Character::checkDeath
//If strength is <= 0, the Character has died. The information is returned as
//a bool.
******************************************************************************/
bool Character::checkDeath()
{
    bool dead = false;           //bool for whether character dead set to false

    if (strength <= 0)
    {
        dead = true;
    }

    return dead;
}



