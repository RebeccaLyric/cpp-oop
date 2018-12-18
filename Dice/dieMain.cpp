/******************************************************************************
 ** Program name: War game with dice design
 ** Author: Rebecca L. Taylor
 ** Date: 15 October 2017
 ** Description:  This main file runs a program to simulate the War card
    game using dice. The menu asks if the user would like to play, then
    calls functions to get information on whether each player's die will 
    be regular or loaded and how many sides each die will have. Two loadedDie 
    objects are created, which can later be cast as regular die to call base
    class functions.
 ******************************************************************************/
#include "Game.hpp"
#include "Die.hpp"
#include "LoadedDie.hpp"

#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    string input;        //variable for user input
    string die1type;     //variable for die type (regular or loaded)
    string die2type;
    int sides = 6;       //variable for number of sides on die, 6 is default value

    srand(time(NULL));   //seed for random function of rollDie()
    Game game;           //create a Game object

    cout << "Welcome to War, a dice game for two players." << endl;
    int userChoice = game.menu();

    while (userChoice == 1)   //user chooses to play game
    {
        //Get number of rounds from user
        game.selectRounds();             
        cout << endl;

        //Information for player1
        cout << "First enter the information for player 1" << endl;
        game.selectDie(die1type, sides);
        LoadedDie *die1 = new LoadedDie(sides);
        cout << endl;

        //Information for player2
        cout << "Next enter the information for player 2" << endl;
        game.selectDie(die2type, sides);
        LoadedDie *die2 = new LoadedDie(sides);
        cout << endl;

        //Begin game
        game.playGame(die1, die1type, die2, die2type);

        //Free memory allocated to LoadedDie objects
        delete die1;
        delete die2;

        userChoice = game.menu();   //Ask if user wants to play again
    }

    if (userChoice == 2)            //user chooses to exit program
    {
        cout << "Goodbye!" << endl;
    }

    return 0;
}
