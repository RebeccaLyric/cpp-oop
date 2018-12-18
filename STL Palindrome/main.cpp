/******************************************************************************
** Program name: Stack and Queue STL Containers
** Author: Rebecca L. Taylor
** Date: 26 November 2017
** Description: This main file executes a program to demonstrate data
    structures using the stack and queue STL containers.
******************************************************************************/

#include "STLMenu.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

int main()
{
    std::cout << "This program demonstrates STl containers." << std::endl;

    srand(time(NULL));                  //Seed rand with current time
    mainMenu();                         //Call main menu

    return 0;
}
