/******************************************************************************
** Program name: Fantasy Combat Tournament
** Author: Rebecca L. Taylor
** Date: 19 November 2017
** Description: This implementation file defines the menu functions which
    allow the user to choose to keep playing, select which characters to play,
    and set the player's character choice.
******************************************************************************/

#include "tourneyMenu.hpp"

#include "getInteger.hpp"
#include "Vampire.hpp"
#include "Barbarian.hpp"
#include "BlueMen.hpp"
#include "Medusa.hpp"
#include "HarryPotter.hpp"

#include <iostream>
#include <string>
using std::string;
using std::cin;
using std::cout;
using std::endl;

#include <memory>

/******************************************************************************
//Definition of tourneyMenu::menuChoice
//The function prints the user's options to play or quit, then gets the user's
//choice. THe validated choice is returned as an integer.
******************************************************************************/
int tourneyMenu::menuChoice()
{
    string input;                  //Variable to hold user input
    int minimum = 1;               //Minimum of allowed user choice
    int maximum = 2;               //Maximum of allowed user choice

    //Print menu options
    cout << "Please choose one of the following options:" << endl;
    cout << "Enter '1' to play a tournament of "
         << "fantasy characters." << endl;
    cout << "Or enter '2' to exit the program." << endl;

    //Get user input, validate, and check one of specified options
    getline(cin, input);
    int choice = getInteger(input);
    choice = checkRange(choice, minimum, maximum);

    return choice;
}

/******************************************************************************
//Definition of tourneyMenu::createLineups()
//The function creates three lineups: both teams and the losers queue, calling
//the appropriate menu function to get user input for each.
******************************************************************************/
void tourneyMenu::createLineups(TourneyQueue *team)
{
    int numPlayers = tourneyMenu::getTeamSize();

    for (int i = 0; i < numPlayers; i++)
    {
        int charChoice = tourneyMenu::selectChar();
        tourneyMenu::setPlayer(team, charChoice);
    }

    team->printFighters(team->getLineupName());
}

/******************************************************************************
//Definition of tournemyMenu::getTeamSize
//The function asks the user how many players should be on the team, validates
//the input, then gets user input on type and name of each character on the
//team. The completed team is returned as a pointer to TourneyQueue.
******************************************************************************/
int tourneyMenu::getTeamSize()
{
    string input;                  //Variable to hold user input
    int minimum = 1;               //Minimum of allowed user choice
    int maximum = 5;               //Maximum of allowed user choice

    cout << "How many players would you like on the team? "
         << "Enter a number between 1 and 5." << endl;

    //Get user input, validate, and check one of specified options
    getline(cin, input);
    int numPlayers = getInteger(input);
    numPlayers = checkRange(numPlayers, minimum, maximum);

    return numPlayers;
}

/******************************************************************************
//Definition of tourneyMenu::selectChar
//The function prints the list of available characters, then gets the user's
//choice. The validated choice is returned as an integer which can then be
//passed to the setPlayer function.
******************************************************************************/
int tourneyMenu::selectChar()
{
    string input;                  //Variable to hold user input
    int minimum = 1;               //Minimum of allowed user choice
    int maximum = 5;               //Maximum of allowed user choice

    //Print character options
    cout << "Select a character type: " << endl;
    cout << "1: Vampire" << endl;
    cout << "2: Barbarian" << endl;
    cout << "3: Blue Men" << endl;
    cout << "4: Medusa" << endl;
    cout << "5: Harry Potter" << endl;

    //Get user input, validate, and check one of specified options
    getline(cin, input);
    int charNum = getInteger(input);
    charNum = checkRange(charNum, minimum, maximum);

    return charNum;
}

/******************************************************************************
//Definition of setPlayer
//The function takes an int of the user's Character selection. It uses a
//switch statement to print the name of the selected Character and returns a
//pointer to the appropriate Character object.
******************************************************************************/
void tourneyMenu::setPlayer(TourneyQueue *team, const int &charChoice)
{
    string name;

    switch (charChoice)
    {
        case 1:
        {
            cout << "Enter a name for the Vampire: " << endl;
            getline(cin, name);

            Vampire *vamp = new Vampire;
            vamp->setName(name);
            team->addBack(vamp);

            break;
        }

        case 2:
        {
            cout << "Enter a name for the Barbarian: " << endl;
            getline(cin, name);

            Barbarian *barb = new Barbarian;
            barb->setName(name);
            team->addBack(barb);

            break;
        }

        case 3:
        {
            cout << "Enter a name for the Blue Men: " << endl;
            getline(cin, name);

            BlueMen *bm = new BlueMen;
            bm->setName(name);
            team->addBack(bm);

            break;
        }

        case 4:
        {
            cout << "Enter a name for the Medusa: " << endl;
            getline(cin, name);

            Medusa *med = new Medusa;
            med->setName(name);
            team->addBack(med);

            break;
        }

        case 5:
        {
            cout << "Enter a name for the Harry Potter: " << endl;
            getline(cin, name);

            HarryPotter *hp = new HarryPotter;
            hp->setName(name);
            team->addBack(hp);

            break;
        }

    }
}

/******************************************************************************
//Definition of viewLoserList
//The function asks and validates user input on whether to display the lineup
//of defeated players. The user's choice is returned as an int.
******************************************************************************/
int tourneyMenu::viewLoserList()
{
    string input;
    int minimum = 1;
    int maximum = 2;

    //Ask if user wants to see list of defeated players
    cout << "Do you want to see the list of defeated players? "
         << "Enter '1' for yes or '2' for no." << endl;

    //Get user input, validate, and check one of specified options
    getline(cin, input);
    int choice = getInteger(input);
    choice = checkRange(choice, minimum, maximum);

    return choice;
}



