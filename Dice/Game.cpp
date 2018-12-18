/******************************************************************************
 ** Program name: War game with dice design
 ** Author: Rebecca L. Taylor
 ** Date: 15 October 2017
 ** Description:  This implementation file defines the member functions of the
    Game class.
 ******************************************************************************/

#include "Game.hpp"
#include "getInteger.hpp"
#include "LoadedDie.hpp"

#include <iostream>
#include <string>
using std::string;
using std::cin;
using std::cout;
using std::endl;

/******************************************************************************
//Definition of Game::menu() member function.
//The function asks if the user would like to play, and uses input validation
//to ensure the user enters valid input. It then returns the user's choice as
//an int.
******************************************************************************/
int Game::menu()
{
    string input;     //Variable to hold user input

    //Print menu options
    cout << "Please choose one of the following options:" << endl;
    cout << "Enter '1' to play the game." << endl;
    cout << "Or enter '2' to quit." << endl;

    //Get and validate user input
    getline(cin, input);
    int choice = getInteger(input);

    //Check user choice is one of specified options
    while (choice != 1 && choice != 2)
    {
        cout << "Please enter '1' to start or '2' to quit." << endl;
        getline(cin, input);
        choice = getInteger(input);
    }

    return choice;
}

/******************************************************************************
//Definition of Game::selectRounds() member function.
//The function allows the user to select the number of rounds to play,
//between 1 and 100. A call to getInteger() validates the user's input.
******************************************************************************/
void Game::selectRounds()
{
    string input;

    cout << "How many rounds will you play?" << endl;
    cout << "Select a number between 1 and 100." << endl;

    //Get and validate user input
    getline(cin, input);
    numRounds = getInteger(input);
    
    //Check user choice is one of specified options
    while (numRounds < 1 || numRounds > 100) 
    {
        cout << "Please enter either '1' or '2'" << endl;
        numRounds = getInteger(input);
    }
}

/******************************************************************************
//Definition of Game::selectDie() member function.
//The function asks the user to choose the type of die (regular or loaded)
//and the number of sides. Both variables are passed by reference.
******************************************************************************/
void Game::selectDie(string &die, int &sides)
{
    string input;          //Variable to store user input

    //First select regular or loaded die
    cout << "Would you like a regular or loaded die?" << endl;
    cout << "Enter '1' for regular die or '2' for loaded." << endl;
    
    //Get and validate user input
    getline(cin, input);
    int dieNum = getInteger(input);

    //Check user choice is one of specified options
    while (dieNum != 1 && dieNum != 2)
    {
        cout << "Please enter either '1' or '2'" << endl;
        dieNum = getInteger(input);
    }
   
    //If user selects regular die 
    if (dieNum == 1)      
    {
        die = "regular";
    }

    //If user selects loaded die
    if (dieNum == 2)     
    {
        die = "loaded";
    }

    //Next choose number of sides for the die
    cout << "How many sides will the die have?" << endl;
    cout << "Enter a number between 2 and 24." << endl;
    
    //Get and validate user input
    getline(cin, input);
    sides = getInteger(input);

    //Check user choice is one of specified options
    while (sides < 2 || sides > 24)
    {
        cout << "Please enter a number between 2 and 24" << endl;
        sides = getInteger(input);
    }
}

/******************************************************************************
//Definition of Game::playGame member function.
//The function accepts as parameters pointers to two LoadedDie objects and
//their types (regular or loaded).
//It uses accumulator variables to keep track of the number of 
//rounds, each player's rolls, and each player's score. If the die is regular
//(not loaded) a static cast of the loaded die is used to call the base class 
//roll() function. 
//Die and roll information is printed at the end of each round. After all 
//rounds are played, final score and winner information is printed. 
******************************************************************************/
void Game::playGame(LoadedDie *loadedDie1, string d1Type, 
                    LoadedDie *loadedDie2, string d2Type)
                   
{
    int roundsPlayed = 0;             //Accumulator to hold number of rounds
    int d1Roll, d2Roll;               //Variables to hold roll results
    int d1Score = 0;                  //Initialize player 1 score to 0
    int d2Score = 0;                  //Initialize player 2 score to 0
    int tiedRounds = 0;               //Initialize tied rounds counter to 0


    //Cast loaded die as regular die for base class (regular roll) access
    Die *regularDie1 = static_cast<Die*>(loadedDie1);
    Die *regularDie2 = static_cast<Die*>(loadedDie2);

    cout << "Now starting War game!" << endl;
    cout << endl;

    //While loop executes rolls until all rounds are played
    while (roundsPlayed < numRounds)
    {

        cout << "Round " << (roundsPlayed+1) << endl;

        //Roll die 1
        if(d1Type == "regular")
        {
            d1Roll = regularDie1->rollDie();      //call regular roll for die 1
        }

        else if(d1Type == "loaded")
        {
            d1Roll = loadedDie1->rollDie();       //call loaded roll for die 1
        }

        //Roll die 2
        if(d2Type == "regular")
        {
            d2Roll = regularDie2->rollDie();      //call regular roll for die 2
        }

        else if(d2Type == "loaded")
        {
            d2Roll = loadedDie2->rollDie();       //call loaded roll for die 2
        }

        //Print results of round
        cout << "Player 1 rolling a " << d1Type << " die with "
             << loadedDie1->getSides() << " sides " << "rolled: "
             << d1Roll << endl;

        cout << "Player 2 rolling a " << d2Type << " die with "
             << loadedDie2->getSides() << " sides " << "rolled: "
             << d2Roll << endl;

        //If player 1 rolled higher
        if (d1Roll > d2Roll)             
        {
            d1Score++;
            cout << "Player 1 wins this round!" << endl;
            cout << endl;
        }

        //If player 2 rolled higher
        if (d2Roll > d1Roll)
        {
            d2Score++;
            cout << "Player 2 wins this round!" << endl;
            cout << endl;
        }

        //If the rolls were equal
        if (d1Roll == d2Roll)
        {
            tiedRounds++;
            cout << "This round was a tie!" << endl;
            cout << endl;
        }

        roundsPlayed++;          //Increment number of rounds played
    }

    //Print end of game results
    cout << "Final score results: " << endl;
    cout << "Player 1 won: " << d1Score << " round(s)." << endl;
    cout << "Player 2 won: " << d2Score << " round(s)." << endl;
    cout << "Tied rounds: " << tiedRounds << endl;

    //If player 1 score is higher
    if (d1Score > d2Score)
    {
        cout << "Player 1 wins the game!" << endl;
        cout << endl;
    }

    //If player 2 score is higher
    if (d2Score > d1Score)
    {
        cout << "Player 2 wins the game!" << endl;
        cout << endl;
    }

    //If player 1 and player 2 scores are equal 
    if (d1Score == d2Score)
    {
        cout << "The game was a tie!" << endl;
        cout << endl;
    }

}
