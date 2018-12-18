/******************************************************************************
** Program name: Langton's Ant
** Author: Rebecca L. Taylor
** Date: 8 October 2017
** Description: This main file runs a program to simulate Langton's Ant. It
    creates an Ant object, calls the menu function to get the user's choice,
    dynamically allocates a 2D array for the board, executes the simulation,
    and frees the memory allocated for the 2D array. The menu is then called
    again to allow the user the repeat the simulation or exit the program.
******************************************************************************/

#include "Ant.hpp"
#include "menu.hpp"

#include <iostream>
using std::string;
using std::cin;
using std::cout;
using std::endl;

int main()
{
    //Create ant object
    Ant a1;

    cout << "Welcome to Langton's Ant!" << endl;

    //Call menu function
    int userChoice = menu();   //Variable to hold user's validated menu choice

    while (userChoice == 1)
    {
        cout << "Now starting Langton's Ant!" << endl;
        //Get user input
        a1.userInput();

        //Dynamically allocate space for 2D array
        int rowNum = a1.getRows();
        int colNum = a1.getCols();

        char **board = new char*[rowNum];
        for (int i = 0; i < rowNum; i++)
        {
            board[i] = new char[colNum];
        }

        //Assign position color to each space on board
        a1.setPositionColor(' ');            //Default blank space
        for (int j = 0; j < rowNum; j++)
        {
            for (int k = 0; k < colNum; k++)
                board[j][k] = a1.getPositionColor();
        }

        //Ant begins facing up
        a1.setAntFacing(UP);

        //Begin simulation
        a1.makeMove(board);

        //Free memory allocated for 2D array
        for (int i = 0; i < rowNum; i++)
        {
            delete [] board[i];
        }

        delete [] board;

        //Play again or quit
        userChoice = menu();
    }

    if (userChoice == 2)
    {
        cout << "Goodbye!" << endl;
    }

    return 0;
}
