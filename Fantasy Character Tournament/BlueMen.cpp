/******************************************************************************
** Program name: Fantasy Combat Tournament
** Author: Rebecca L. Taylor
** Date: 19 November 2017
** Description: This implementation file defines the member functions of the
    Blue Men class derived from the Character base class. It includes a
    constructor as well as overridden getName and defend functions. The last
    function calculates the dice lost after the character accrues damage.
******************************************************************************/

#include "BlueMen.hpp"

#include <iostream>
using std::cout;
using std::endl;

/******************************************************************************
//Definition of BlueMen::BlueMen
//The function sets the default values of a Blue Men character, including
//attack dice, defense dice, armor, strength, and total damage.
******************************************************************************/
BlueMen::BlueMen()
{
    //Blue Men attack with two ten-sided dice
    attackSides = 10;
    attackDice = 2;

    //Blue Men defend with three six-sided dice
    defenseSides = 6;
    defenseDice = 3;

    //Blue Men have three armor and begin with strength 12
    armor = 3;
    strength = 12;

    //Accumulator for total damage set to 0
    totalDamage = 0;
}

/******************************************************************************
//Definition of BlueMen::getName
//The function overrides the Base class pure virtual getName function and
//returns as a string the words "Blue Men"
******************************************************************************/
string BlueMen::getType() const
{
    return "Blue Men";
}

/******************************************************************************
//Definition of Blue Men::defend
//The function overrides the pure virtual defend function and takes the
//attacker's roll as an int parameter. It calls the base class calcDefense and
//calcDamage functions and assigns the returned damage to tempDamage. It calls
//the base class checkDeath function. If the character has not died, the
//function determines whether the Blue Men will lose a defense die. If so, the
//diceLost function is called. Then it returns a bool of whether the
//character died.
******************************************************************************/
bool BlueMen::defend(const int &attackRoll)
{
    int defense = calcDefense();       //Calculate defense roll

    //Calculate damage and strength loss, assign to tempDamage
    int tempDamage = calcDamage(attackRoll, defense);

    //If Blue Men still alive, test if lose defense die
    if (checkDeath() == false)
    {
        //Add to total of cumulative damage
        totalDamage += tempDamage;

        cout << endl << "Note: Blue Men will lose one die for every "
             << "four points of damage." << endl
             << "Total damage so far is: " << totalDamage << endl;

        //Calculate how many dice Blue Men lose due to damage
        if (totalDamage >=4)
        {
            diceLost();
        }
    }

    return checkDeath();
}

/******************************************************************************
//Definition of Blue Men::diceLost
//The function calculates how many defense dice Blue Men lose as a result of
//damage. Any remainder damage after dice lost is added to totalDamage.
******************************************************************************/
void BlueMen::diceLost()
{
    cout << "Uh-oh, Blue Men have accrued " << totalDamage
         << " points of damage." << endl;

    if (defenseDice > 0 && totalDamage >= 4)
    {
        int diceLost = totalDamage / 4;
        defenseDice -= diceLost;

        cout << "Blue Men lost " << diceLost << " defense di(c)e." << endl;
        cout << "Blue Men now have only " << defenseDice
             << " defense di(c)e. ";

        //Reset total damage to remainder of total damage after dice lost
        totalDamage = totalDamage % 4;

        cout << totalDamage << " point(s) of damage remain(s) "
             << "after di(c)e lost." << endl;
    }

    else if (defenseDice <= 0)
    {
        cout << "No defense dice left for Blue Men to lose." << endl;
    }
}
