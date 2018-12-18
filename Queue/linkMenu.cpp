/******************************************************************************
** Program name: Circular Linked List
** Author: Rebecca L. Taylor
** Date: 12 November 2017
** Description: This implementation file defines the functions designed to
    give the user options and execute the selected circular linked list
    functions.
******************************************************************************/

#include "linkMenu.hpp"
#include "getInteger.hpp"

#include <iostream>
#include <string>
using std::string;
using std::cin;
using std::cout;
using std::endl;

/******************************************************************************
//Definition of mainMenu
//The function offers the user the main options to add a value to the back of
//the queue, display the first node, remove the firset node, display the
//queue contents, or quit.
******************************************************************************/
int mainMenu()
{
    string input;                  //String to hold user input
    int minimum = 1;               //Minimum range of allowed user choice
    int maximum = 5;               //Maximum range of allowed user choice

    cout << "Choose from the following options:" << endl;
    cout << "Enter '1' to add a value to the back of the queue," << endl;
    cout << "Enter '2' to display first node (front) value," << endl;
    cout << "Enter '3' to remove first node (front) value," << endl;
    cout << "Enter '4' to display the queue contents," << endl;
    cout << "Or enter '5' to exit the program." << endl;

    //Get user input, validate, and check one of specified options
    getline(cin, input);
    int choice = getInteger(input);
    choice = checkRange(choice, minimum, maximum);

    return choice;
}

/******************************************************************************
//Definition of listOptions menu
//The function takes two parameters: a pointer to a Queue object, and an
//int of the user's choice. It then uses a switch statement to execute the
//selected function on the passed-in queue.
******************************************************************************/
void listOptions(Queue *queueIn, int optionIn)
{
    std::string numInput;
    int num;

    switch (optionIn)
    {
        //Add a value to the back of the list
        case 1:
        {
            cout << "Please enter a positive integer "
                 << "to add to the back of the list." << endl;

            //Get input and validate integer
            getline(cin, numInput);
            num = getInteger(numInput);

            //Call addBack with validated int
            queueIn->addBack(num);

            break;
        }

        //Display the front value
        case 2:
        {
            //Call getFront
            int firstVal = queueIn->getFront();

            //If queue is not empty
            if (firstVal != -1)
            {
                cout << "The first node value is: " << firstVal << endl << endl;
            }

            //Else if queue is empty
            else if (firstVal == -1)
            {
                cout << "Queue is empty." << endl << endl;
            }

            break;
        }

        //Delete the node at the head of the list
        case 3:
        {
            queueIn->removeFront();
            break;
        }

        //Display queue's contents
        case 4:
        {
            queueIn->printQueue();
            break;
        }

        default:
        {
            break;
        }
    }
}
