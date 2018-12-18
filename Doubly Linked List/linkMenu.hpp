/******************************************************************************
** Program name: Doubly-linked List
** Author: Rebecca L. Taylor
** Date: 5 November 2017
** Description: This header file provides the prototype for the function
    designed to give the user options and execute the selected linked list
    functions.
******************************************************************************/

#ifndef LINKMENU_HPP
#define LINKMENU_HPP

#include "NumberList.hpp"

//Function headers for menu functions
int mainMenu();
void listOptions(NumberList *listIn, int optionIn);

#endif //LINKMENU_HPP

