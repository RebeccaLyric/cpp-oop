/******************************************************************************
** Program name: Path to Principal: A Ballet Game
** Author: Rebecca L. Taylor
** Date: 5 December 2017
** Description: This main file implements a program to execute a single-player
    ballet game.
******************************************************************************/

#include "Menu.hpp"
#include "Play.hpp"

#include <stdlib.h>
#include <time.h>

#include <iostream>
using std::cout;
using std::endl;

int main()
{
    cout << "\nPath to Principal: A Ballet Game\n" << endl;

    srand(time(NULL));                      //Seed rand with current time

    Play game;                              //Create Play object

    int play = Menu::menuChoice();

    while (play == 1)                       //While user selects '1' to play
    {
        game.play();                        //Play game
        play = Menu::menuChoice();          //Check if user wants to play again
    }

    if (play == 2)                          //If user selects '2' to quit
    {
        cout << "Goodbye!" << endl;
    }

    return 0;
}


