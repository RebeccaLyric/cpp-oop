/******************************************************************************
** Program name: Path to Principal: A Ballet Game
** Author: Rebecca L. Taylor
** Date: 5 December 2017
** Description: This implementation file defines the menu functions which
    allow the user to make choices in the ballet game.
******************************************************************************/

#include "Menu.hpp"
#include "getInteger.hpp"

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

/******************************************************************************
//Definition of Menu::menuChoice
//The function prints the user's options to play or quit, then gets the user's
//choice. The validated choice is returned as an integer.
******************************************************************************/
int Menu::menuChoice()
{
    int minimum = 1;               //Minimum of allowed user choice
    int maximum = 2;               //Maximum of allowed user choice

    cout << "Please choose one of the following options:" << endl;
    cout << "Enter '1' to play the ballet game," << endl;
    cout << "Or enter '2' to exit the program." << endl;

    return getInteger(minimum, maximum);
}

/******************************************************************************
//Definition of Menu::spaceOptions
//The function takes a pointer to the current Space as its parameter. It
//provides the option to interact with the space or change rooms. The
//validated user choice is returned as an int.
******************************************************************************/
int Menu::spaceOptions(Space *currentSpace)
{
    int minimum = 1;
    int maximum = 2;

    cout << "Enter '1' to " << currentSpace->getActionName() << ", " << endl;
    cout << "Or enter '2' to change rooms." << endl;

    return getInteger(minimum, maximum);
}

/******************************************************************************
//Definition of Menu::printIntro
//The function prints the overview information on how the ballet game is played.
******************************************************************************/
void Menu::printIntro()
{
    cout << "You are a dancer at Lyric Ballet Company. " << endl;
    cout << "- Practice steps and earn items for your dance bag "
         << "in the Practice Studios." << endl;
    cout << "- Perform and earn bouquets of flowers at the stages." << endl;
    cout << "- Win the game by getting a bouquet of roses "
         << "and becoming a principal dancer." << endl;
    cout << "- You lose energy for each practice and performance." << endl;
    cout << "- You can recover energy by visiting the physical therapist, " << endl;
    cout << "  but you can only visit one time per game." << endl;
    cout << "- If you run out of energy before getting roses, you lose."
         << endl << endl;
}

/******************************************************************************
//Definition of Menu::printMap
//The function prints the map of the ballet company building.
******************************************************************************/
void Menu::printMap()
{
    cout << "                LYRIC BALLET COMPANY                  " << endl;
    cout << "           _______________________________            " << endl;
    cout << "          |               |               |           " << endl;
    cout << "          |   Practice    |   Practice    |           " << endl;
    cout << "          |   Studio 1    |   Studio 2    |           " << endl;
    cout << "          |_______________|_______________|           " << endl;
    cout << "          |               |               |           " << endl;
    cout << "          |   Practice    |   Physical    |           " << endl;
    cout << "          |   Studio 3    |   Therapy     |           " << endl;
    cout << "        __|_______________|_______________|__         " << endl;
    cout << "       |                                     |        " << endl;
    cout << "       |             Petite Stage            |        " << endl;
    cout << "       |                                     |        " << endl;
    cout << "     __|_____________________________________|___     " << endl;
    cout << "    |                                            |    " << endl;
    cout << "    |                                            |    " << endl;
    cout << "    |                Grand Stage                 |    " << endl;
    cout << "    |                                            |    " << endl;
    cout << "    |____________________________________________|    " << endl;
}

