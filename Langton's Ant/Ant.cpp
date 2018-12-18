/******************************************************************************
** Program name: Langton's Ant
** Author: Rebecca L. Taylor
** Date: 8 October 2017
** Description: This implementation file defines the functions of the Ant 
    class used to simulate Langton's Ant.
******************************************************************************/

#include "Ant.hpp"
#include "getInteger.hpp"

#include <ctime>
#include <cstdlib>
using std::srand;
using std::time;
using std::rand;
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <string>
using std::string;

string input;

/******************************************************************************
//Definition of Ant::userInput() member function.
//The function gets the following information from the user: number of rows
//and columns for the board, the starting coordinates of the ant (including
//the option to start at a random location), and the number of steps the ant
//will take.
******************************************************************************/
void Ant::userInput()
{

    //Get number of rows from user
    cout << "How many rows would you like on the board?" << endl;
    cout << "Enter a number between 3 and 80." << endl;
    getline(cin, input);
    rows = getInteger(input);

    while (rows < 3 || rows > 80)
    {
        cout << "Please choose a number between 3 and 80." << endl;
        getline(cin, input);
        rows = getInteger(input);
    }

    //Get number of columns from user
    cout << "How many columns would you like on the board?" << endl;
    cout << "Enter a number between 3 and 80." << endl;
    getline(cin, input);
    cols = getInteger(input);

    while (cols < 3 || cols > 80)
    {
        cout << "Please choose a number between 3 and 80." << endl;
        getline(cin, input);
        cols = getInteger(input);
    }

    //Ask user if would like random starting place
    cout << "Would you like the ant to start at a random location?" << endl;
    cout << "Enter '1' for yes, or '2' for no." << endl;
    getline(cin, input);
    int randStart = getInteger(input);

    while (randStart != 1 && randStart != 2)
    {
        cout << "Please enter either '1' for yes, or '2' for no." << endl;
        getline(cin, input);
        randStart = getInteger(input);
    }

    if (randStart == 1)   //Select random coordinates for x and y start
    //Source: http://www.cplusplus.com/reference/cstdlib/rand/
    {
        srand(time(NULL));
        antX = rand() % (rows-1);
        antY = rand() % (cols-1);

        cout << "Ant starting at (" << antX << ", " << antY << ")" << endl;
    }

    if (randStart == 2)  //Allow user to manually enter x and y start
    {
        //Get starting x coordinate
        cout << "Enter x coordinate of where ant should start" << endl;
        getline(cin, input);
        antX = getInteger(input);

        while (antX > (rows-1))
        {
            cout << "X coordinate must be less than " << rows << endl;
            getline(cin, input);
            antX = getInteger(input);
        }

        //Get starting y coordinate
        cout << "Enter y coordinate of where ant should start" << endl;
        getline(cin, input);
        antY = getInteger(input);

        while (antY > (cols-1))
        {
            cout << "Y coordinate must be less than " << cols << endl;
            getline(cin, input);
            antY = getInteger(input);
        }
    }

    //Get number of steps
    cout << "How many moves should the ant make? (maximum 15000)" << endl;
    getline(cin, input);
    steps = getInteger(input);

    while (steps > 15000)
    {
        cout << "Must be between 0 and 15000." << endl;
        getline(cin, input);
        steps = getInteger(input);
    }

}

/******************************************************************************
//Definition of Ant::print() member function.
//The function takes a double pointer to the board as its parameter. It uses
//a loop to print the rows and columns of the board.
//Based on print function in TicTacToe assignment from CS161
******************************************************************************/
void Ant::print(char **boardIn)
{
    //Place ant on board
    boardIn[antX][antY] = '*';

    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < cols; col++)
        {
            cout << boardIn[row][col];
        }
        cout << endl;
    }

    //Print bottom-edge border
    string dashes;
    dashes.assign(cols, '_');    //Number of dashes equals # of cols
    cout << dashes << endl; 

    //Return ant location to positionColor
    boardIn[antX][antY] = positionColor;

}

/******************************************************************************
//Definition of Ant::antAdvance() member function.
//The function uses a switch statement to determine which direction the ant
//is facing. If not at the edge of the board, the ant moves forward one space.
//If at the edge, the ant is turned around 180 degrees (two quarter turns), 
//then moved forward one space.  
******************************************************************************/
void Ant::antAdvance()
{
    switch(antFacing)
    {
        //If ant is facing up
        case UP:
        {
            if ((antX > 0) && (antX < rows))  //Within board
            {
                antX--;                       //Move up 1 space
            }

            else if (antX == 0)       //If ant is at top of board
            {
                turnAnt(2);  //Turn 2 quarter turns (down)
                antX++;      //Move down one space
            }

            break;
        }

        //If ant is facing right
        case RIGHT:
        {
            if ((antY >= 0) && (antY < (cols - 1)))  //On board
            {
                antY++;                           //Move right 1 space
            }

            else if (antY == (cols - 1))    //If ant at right edge of board
            {
                turnAnt(2);       //Turn 2 quarter turns (left)
                antY--;           //Move left one space
            }

            break;
        }

        //If ant is facing down
        case DOWN:
        {
            if (antX < (rows - 1))  //If on board
            {
                antX++;                           //Move down 1 space
            }

            else if (antX == (rows - 1))    //If at bottom of board
            {
                turnAnt(2);       //Turn 2 quarter turns (up)
                antX--;           //Move up one space
            }

            break;
        }

        //If ant is facing left
        case LEFT:
        {
            if (antY > 0)  //If on board
            {
                antY--;                           //Move down 1 space
            }

            else if (antY == 0)    //If ant is at left edge of board
            {
                turnAnt(2);       //Turn 2 quarter turns (right)
                antY++;           //Move right one space
            }

            break;
        }

    }

}

/******************************************************************************
//Definition of Ant::turnAnt() member function.
//The function uses a switch statement to determine which direction the ant
//is facing. It takes the number of quarter turns as its parameter. An 
//accumulator variable keeps track of the number of quarter turns (one quarter
//turn = right, three quarteri turns = left). A while loops makes the desired
//number of turns until it is terminated.
******************************************************************************/
void Ant::turnAnt(int turnsIn)
{
    int turnsMade = 0;    //Accumulator variable for quarter turns completed

    while (turnsMade < turnsIn)
    {
        switch(antFacing)
        {
            case UP:
            {
                antFacing = RIGHT;
                turnsMade++;
                break;
            }

            case RIGHT:
            {
                antFacing = DOWN;
                turnsMade++;
                break;
            }

            case DOWN:
            {
                antFacing = LEFT;
                turnsMade++;
                break;
            }

            case LEFT:
            {
                antFacing = UP;
                turnsMade++;
                break;
            }
        }
    }
}

/******************************************************************************
//Definition of Ant::makeMove() member function.
//This is the primary function that begins the Langton's Ant simulation. It 
//takes a double pointer to the board as its parameter. An accumulator variable
//keeps track of the number of steps, and a while loop executes the ant's 
//movements until the step count is reached. A switch statement gives the ant
//instructions based on the current color of the board.
******************************************************************************/
void Ant::makeMove(char **boardIn)
{
    int stepCount = 0;

    while (stepCount < steps)
    {
        print(boardIn);      //Print board

        switch(positionColor)
        {
            case ' ':
            {
                turnAnt(1);    //1 quarter turn (right)
                positionColor = '#';
                boardIn[antX][antY] = positionColor;

                antAdvance();

                stepCount++;
                positionColor = boardIn[antX][antY];
                break;
            }

            case '#':
            {
                turnAnt(3);    //3 quarter turns (left)
                positionColor = ' ';
                boardIn[antX][antY] = positionColor;

                antAdvance();

                stepCount++;
                positionColor = boardIn[antX][antY];
                break;
            }

        }
    }

    print(boardIn);      //Print board

}

/******************************************************************************
//Definition of Ant::getPositionColor() member function.
//The function returns the position color of the current space on the board. 
******************************************************************************/
char Ant::getPositionColor()
{
    return positionColor;
}

/******************************************************************************
//Definition of Ant::setPositionColor() member function.
//The function sets the position color of the current space on the board. 
******************************************************************************/
void Ant::setPositionColor(char colorIn)
{
    positionColor = colorIn;
}

/******************************************************************************
//Definition of Ant::setAntFacing() member function.
//The function sets the direction the ant is facing.
******************************************************************************/
void Ant::setAntFacing(Direction facingIn)
{
    antFacing = facingIn;
}

/******************************************************************************
//Definition of Ant::getRows() member function.
//The function gets the number of rows for the board.
******************************************************************************/
int Ant::getRows()
{
    return rows;
}

/******************************************************************************
//Definition of Ant::getCols() member function.
//The function gets the number of columns for the board.
******************************************************************************/
int Ant::getCols()
{
    return cols;
}
