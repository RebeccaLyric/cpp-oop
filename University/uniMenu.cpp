/******************************************************************************
** Program name: OSU Information System
** Author: Rebecca L. Taylor
** Date: 22 October 2017
** Description: This implementation file defines the menu function which
    allows the user to use whether to print building info, print peole info,
    choose a person to do work (do homeowrk or grade papers), or exit.
******************************************************************************/

#include "uniMenu.hpp"
#include "getInteger.hpp"

#include <iostream>
using std::string;
using std::cin;
using std::cout;
using std::endl;

//Function definition for menu function
int uniMenu()
{
    string input;                  //Variable to hold user input

    //Print menu options
    cout << "Please choose one of the following options:" << endl;
    cout << "Enter '1' to print information on all university buildings."
         << endl;
    cout << "Enter '2' to print information on all people at OSU." << endl;
    cout << "Enter '3' to choose a person to do work." << endl;
    cout << "Or enter '4' to exit the program." << endl;

    //Get user input
    getline(cin, input);

    //Validate input
    int choice = getInteger(input);

    //Check user choice is one of specified options
    while (choice < 1 || choice > 4)
    {
        cout << "Please enter a number between 1 and 4." << endl;
        getline(cin, input);
        choice = getInteger(input);
    }

    return choice;
}

