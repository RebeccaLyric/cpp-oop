/******************************************************************************
** Program name: Circular Linked List
** Author: Rebecca L. Taylor
** Date: 12 November 2017
** Description: This main file implements a program to create a simple circular
    linked list (queue).
******************************************************************************/

#include "linkMenu.hpp"
#include "Queue.hpp"

#include <iostream>
using std::cout;
using std::endl;

int main()
{
    cout << "Welcome to my queue!" << endl << endl;

    Queue *queue = new Queue; //Create a pointer to Queue

    int option = mainMenu();           //Call the main menu to get user choice

    while (option != 5)                //While user does not opt to quit
    {
        //Call appropriate function from queue options menu
        listOptions(queue, option);
        option = mainMenu();           //Get new option from main menu
    }

    if (option == 5)                   //If user opts to quit
    {
        cout << "Goodbye!" << endl;
    }

    delete queue;                       //Free memory of pointer to Queue

    return 0;
}
