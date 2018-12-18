/******************************************************************************
** Program name: Recursive functions
** Author: Rebecca L. Taylor
** Date: 29 October 2017
** Description: This main file implements a program to test three recursive
    functions. The first prints a string in reverse, the second recursively
    calculates the sum of an array of integers, and the third recursively
    calculates the triangular number of an integer N.
******************************************************************************/

#include "recursionMenu.hpp"

#include <iostream>
using std::cout;
using std::endl;

int main()
{
    cout << "This program demonstrates three recursive functions." << endl;
    cout << endl;

    //Call the menu to allow user to choose recursive function
    mainMenu();

    //End program
    cout << "Goodbye!" << endl;

    return 0;
}