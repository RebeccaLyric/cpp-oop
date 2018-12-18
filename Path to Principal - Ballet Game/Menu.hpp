/******************************************************************************
** Program name: Path to Principal: A Ballet Game
** Author: Rebecca L. Taylor
** Date: 5 December 2017
** Description: This header file provides the prototypes for the functions
    to give the user options to play the ballet game.
******************************************************************************/

#ifndef MENU_HPP
#define MENU_HPP

#include "Space.hpp"

#include <string>
using std::string;

class Menu
{
public:
    static int menuChoice();
    static int spaceOptions(Space *currentSpace);
    static void printIntro();
    static void printMap();
};

#endif //MENU_HPP

