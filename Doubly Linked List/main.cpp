/******************************************************************************
** Program name: Doubly-linked List
** Author: Rebecca L. Taylor
** Date: 5 November 2017
** Description: This main file implements a program to create a simple doubly-
    linked list of data structures consisting of Node objects.
******************************************************************************/

#include "linkMenu.hpp"
#include "NumberList.hpp"

#include <iostream>
using std::cout;
using std::endl;

int main()
{
    cout << "This program demonstrates a doubly-linked list." << endl << endl;

    NumberList *list = new NumberList; //Create a pointer to NumberList

    int option = mainMenu();           //Call the main menu to get user choice

    while (option != 8)                //While user does not opt to quit
    {
        //Call appropriate function from list options menu
        listOptions(list, option);
        option = mainMenu();           //Get new option from main menu
    }

    if (option == 8)                   //If user opts to quit
    {
        cout << "Goodbye!" << endl;
    }

    delete list;                       //Free memory of pointer to NumberList

    return 0;
}
