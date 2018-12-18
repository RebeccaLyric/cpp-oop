/******************************************************************************
** Program name: War game with dice design
** Author: Rebecca L. Taylor
** Date: 15 October 2017
** Description:  This header file declares the Game class along with its
    member variables and functions.
******************************************************************************/

#ifndef GAME_HPP
#define GAME_HPP

#include "Die.hpp"
#include "LoadedDie.hpp"

#include <string>
using std::string;

class Game
{
private:
    int numRounds;

public:
    int menu();
    void selectRounds();
    void selectDie(string &die, int &sides);
    void playGame(LoadedDie *loadedDie1, string d1Type, 
                  LoadedDie *loadedDie2, string d2Type);
};

#endif //GAME_HPP
