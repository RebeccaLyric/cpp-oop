/******************************************************************************
** Program name: Path to Principal: A Ballet Game
** Author: Rebecca L. Taylor
** Date: 5 December 2017
** Description: This header file declares the member variables and functions
    of the Dancer class representing the player of the game.
******************************************************************************/

#ifndef DANCER_HPP
#define DANCER_HPP

#include "Space.hpp"

#include <vector>
using std::vector;

#include <string>
using std::string;

class Dancer
{
private:
    int energy;                             //Energy decremented during game
    Space *currentSpace;                    //Dancer's current space
    
    std::vector<std::string>danceBag;       //Vector to hold dance bag items  

public:
    void calcEnergy(const int &change);
    void addItem(const string &item);
    void printDanceBag();
    void emptyDanceBag();
    bool findRoses();

    //Setter and getter functions
    void setCurrentSpace(Space *spaceIn);
    Space* getCurrentSpace() const;
    void setEnergy(const int &energy);
    int getEnergy() const;
};

#endif //DANCER_HPP
