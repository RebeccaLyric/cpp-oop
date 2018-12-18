/******************************************************************************
** Program name: Fantasy Combat Tournament
** Author: Rebecca L. Taylor
** Date: 19 November 2017
** Description: This main file implements a program to play a tournament of
    five characters in a fantasy combat game: Vampire, Barbarian, Blue Men,
    Medusa, and Harry Potter.
******************************************************************************/

#include "tourneyMenu.hpp"
#include "playTourney.hpp"

#include <iostream>
#include <stdlib.h>
#include <time.h>
using std::cout;
using std::endl;

int main()
{
    cout << "Welcome to Fantasy Combat Tournament!" << endl;

    srand(time(NULL));                  //Seed rand with current time
    playTourney game;                   //Create playTourney object
    tourneyMenu menu;                   //Create tourneyMenu object
    int play = menu.menuChoice();       //Get user choice for game

    while (play == 1)                   //While user selects '1' to play
    {
        game.playGame();                //Play game
        play = menu.menuChoice();       //Check if user wants to play again
    }

    if (play == 2)                      //If user selects '2' to quit
    {
        cout << "Goodbye!" << endl;
    }

    return 0;
}
