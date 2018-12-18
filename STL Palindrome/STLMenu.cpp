/******************************************************************************
** Program name: Stack and Queue STL Containers
** Author: Rebecca L. Taylor
** Date: 26 November 2017
** Description: This implementation file defines the functions which provide
    the user options for working with the STL containers.
******************************************************************************/

#include "STLMenu.hpp"
#include "getInteger.hpp"
#include "STL_functions.hpp"

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <string>

/******************************************************************************
//Definition of mainMenu
//The function offers the user the main options to demonstrate a queue,
//demonstrate a stack, or quit. User input is validated and returned as an int.
******************************************************************************/
void mainMenu()
{
    std::string input;             //String to hold user input
    int minimum = 1;               //Minimum range of allowed user choice
    int maximum = 3;               //Maximum range of allowed user choice

    cout << "Choose from the following options:" << endl;
    cout << "Enter '1' to demonstrate a queue (buffer simulation)," << endl;
    cout << "Enter '2' to demonstrate a stack (create palindrome)," << endl;
    cout << "Or enter '3' to exit the program." << endl;

    //Get user input, validate, and check one of specified options
    int choice = getInteger(minimum, maximum);

    //Pass choice to STL menu
    STLOptions(choice);
}

/******************************************************************************
//Definition of STLOptions menu
//The function takes an int parameter indicating the user's choice. A switch
//statement prompts the user for the needed input depending on whether the
//buffer or palindrome was selected.
******************************************************************************/
void STLOptions(int optionIn)
{
    std::string numInput;

    switch (optionIn)
    {
        case 1:                      //Demonstrate STL queue (buffer simulation)
        {
            int minimum = 1;         //Minimum range of allowed user choice
            int maximum = 100;       //Maximum range of allowed user choice

            //Get number of rounds from user
            cout << "How many rounds will be simulated?" << endl;
            int numRounds = getInteger(minimum, maximum);

            //Get random chance of adding number to buffer
            cout << "Enter the chance to put a randomly generated number "
                 << "at the end of buffer" << endl;
            int addChance = getInteger(minimum, maximum);

            //Get random chance of removing number from buffer
            cout << "Enter the chance to take out a randomly generated number "
                 << "from the front of the buffer" << endl;
            int removeChance = getInteger(minimum, maximum);

            //Call buffer function to demonstrate STL queue
            buffer(numRounds, addChance, removeChance);

            break;
        }

        case 2:                      //Demonstrate STL stack (palindrome function)
        {
            std::string userWord;

            //Get string from user input
            cout << "Enter a string to create the palindrome: " << endl;
            getline(cin, userWord);

            //Call palindrome function to demonstrate STL stack
            string palindromeString = palindrome(userWord);
            cout << "Your string as palindrome: " << palindromeString << endl;

            break;
        }

        default:
        {
            cout << "Not a valid option" << endl;
            break;
        }
    }
}


