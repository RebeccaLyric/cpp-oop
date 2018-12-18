/******************************************************************************
** Program name: Doubly-linked List
** Author: Rebecca L. Taylor
** Date: 5 November 2017
** Description: This implementation file defines the functions designed to
    give the user options and execute the selected doubly-linked list
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
//The function offers the user the main options to add a new node to the head,
//add a new node to the tail, delete the first node in the list, delete the
//last node in the list, traverse the list in reverse, print the value of the
//list head, or print the value of the list tail. It returns an int of the
//user's choice.
******************************************************************************/
int mainMenu()
{
    string input;                  //String to hold user input
    int minimum = 1;               //Minimum range of allowed user choice
    int maximum = 8;               //Maximum range of allowed user choice

    cout << "Choose from the following options:" << endl;
    cout << "Enter '1' to add a new node to the head of the list," << endl;
    cout << "Enter '2' to add a new node to the tail of the list," << endl;
    cout << "Enter '3' to delete the first node (head) of the list," << endl;
    cout << "Enter '4' to delete the last node (tail) of the list," << endl;
    cout << "Enter '5' to traverse (and print) the list in reverse," << endl;
    cout << "Enter '6' to print the first value in the list," << endl;
    cout << "Enter '7' to print the last value in the list," << endl;
    cout << "Or enter '8' to exit the program." << endl;

    //Get user input, validate, and check one of specified options
    getline(cin, input);
    int choice = getInteger(input);
    choice = checkRange(choice, minimum, maximum);

    return choice;
}

/******************************************************************************
//Definition of listOptions menu
//The function takes two parameters: a pointer to a NumberList object, and an
//int of the user's choice. It then uses a switch statement to execute the
//selected function on the passed-in number list.
******************************************************************************/
void listOptions(NumberList *listIn, int optionIn)
{
    std::string numInput;
    int num;

    switch (optionIn)
    {
        //Add a node to the head of the list
        case 1:
        {
            cout << "Please enter a positive integer "
                 << "to add to the head of the list." << endl;

            //Get input and validate integer
            getline(cin, numInput);
            num = getInteger(numInput);

            //Call addNodeHead with validated int
            listIn->addNodeHead(num);

            break;
        }

        //Add a node to the tail of the list
        case 2:
        {
            cout << "Please enter a positive integer "
                 << "to add to the tail of the list." << endl;

            //Get input and validate integer
            getline(cin, numInput);
            num = getInteger(numInput);

            //Call addNodeHead with validated int
            listIn->addNodeTail(num);

            break;
        }

        //Delete the node at the head of the list
        case 3:
        {
            listIn->removeNodeHead();
            break;
        }

        //Delete the node at the tail of the list
        case 4:
        {
            listIn->removeNodeTail();
            break;
        }

        //Traverse the list reversely
        case 5:
        {
            listIn->printReverse();
            break;
        }

        //Print value at list head
        case 6:
        {
            listIn->printHead();
            break;
        }

        //Print value at list tail
        case 7:
        {
            listIn->printTail();
            break;
        }
    }
}
