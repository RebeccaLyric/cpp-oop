/******************************************************************************
** Program name: menu (utility function)
** Author: Rebecca L. Taylor
** Date: 8 October 2017
** Description: This implementation file defines the menu function. It prints
    the options for the user, validates the input is an integer and one of the
    defined choices, then returns an integer representing the validated choice.
******************************************************************************/

#include "menu.hpp"
#include "getInteger.hpp"

#include <iostream>
using std::string;
using std::cin;
using std::cout;
using std::endl;

//Function definition for menu function
int menu()
{
    string input;                  //Variable to hold user input

    //Print menu options
    cout << "Please choose one of the following options:" << endl;
    cout << "Enter '1' to start Langton's Ant." << endl;
    cout << "Or enter '2' to quit." << endl;

    //Get user input
    getline(cin, input);

    //Validate input
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

