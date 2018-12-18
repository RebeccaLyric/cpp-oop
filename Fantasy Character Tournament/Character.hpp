/******************************************************************************
** Program name: Fantasy Combat Tournament
** Author: Rebecca L. Taylor
** Date: 19 November 2017
** Description: This header file defines the member variables and functions of
    the Character class, the abstract parent class for the five characters of
    the fantasy combat game: Vampire, Barbarian, Blue Men, Medusa, and
    Harry Potter.
******************************************************************************/

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <string>
using std::string;

class Character
{
protected:
    string charName;

    int attackRoll;
    int defenseRoll;
    int armor;
    int strength;

    //Variables for dice information
    int attackSides;
    int attackDice;
    int defenseSides;
    int defenseDice;

public:
    Character();                       //Constructor

    //Getter and setter functions
    virtual string getType() const = 0;
    string getName() const;
    void setName(const string &charName);
    void setStrength(const int &strength);
    int getStrength() const;

    //Game use functions
    int rollDice(const int &dieSides, const int &numDice);
    virtual int attack();
    virtual bool defend(const int &attackRole) = 0;
    int calcDefense();
    virtual int calcDamage(int attackIn, int defenseIn);
    virtual void recover();
    bool checkDeath();
};

#endif //CHARACTER_HPP
