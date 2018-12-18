/******************************************************************************
** Program name: Zoo Tycoon
** Author: Rebecca L. Taylor
** Date: 22 October 2017
** Description: This main file executes the Zoo Tycoon program in which three
    animals (tigers, penguins, and turtles) can be bought and live. Each day
    a random event occurs. The game ends when the user runs out of money.
******************************************************************************/
#include "Zoo.hpp"
#include "getInteger.hpp"

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
    srand(time(NULL));       //Seed time for random functions

    cout << "Welcome to Zoo Tycoon!" << std::endl;
    cout << endl;

    Zoo z1;                  //Create zoo object
    string input;            //String for user input
    int play;                //User's choice for whether to keep playing
    int day = 1;             //Keep track of zoo days

    //First buy animals to start the zoo
    z1.setBankMoney(50000); //Set amount of money to start the zoo

    cout << "First buy animals to start the zoo." << endl;
    z1.buyAnimalsStart();
    cout << endl;

    do
    {
        //Begin zoo day
        cout << "Day " << day << " at the zoo!" << endl;

        //All animals age by one day
        z1.ageAnimals();
        cout << endl;

        //Feed all the animals
        cout << "The animals need to be fed." << endl;
        z1.feedAnimals();
        cout << endl;

        //Randomized event per day
        z1.randomEvent();
        cout << endl;

        //At end of day
        cout << "End of day " << day << ": " << endl;
        day++;

        //Calculate profit
        z1.calcProfit();
        cout << endl;

        //Check if money left in bank to keep playing
        if (z1.getBankMoney() <= 0)
        {
            cout << "Uh-oh! You overspent all your money. " << endl;
            cout << "The bank is angry you went into debt "
                 << "and closed the zoo. " << endl;
            cout << "Game over. Goodbye!" << endl;
            cout << endl;
            break;
        }
       
        else
        {
            //Ask if user wants to buy another animal at end of day
            z1.buyAnimalsEOD();

            //Ask if user wants to play next day
            cout << "Do you want to play the next day? "
                 << "Enter '1' for yes or '2' for no." << endl;

            //Check user input
            getline(cin, input);
            play = getInteger(input);

            while (play != 1 && play != 2)
            {
                cout << "Please enter either '1' or '2'" << endl;
                getline(cin, input);
                play = getInteger(input);
            }

            //If player opts to quit
            if (play == 2)
            {
                cout << "Goodbye!" << endl;
            }
        }

    } while (play == 1);          //While user opts to keep playing

    return 0;
}
