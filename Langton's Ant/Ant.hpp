/******************************************************************************
** Program name: Langton's Ant
** Author: Rebecca L. Taylor
** Date: 8 October 2017
** Description: This header file describes the Ant class used to simulate 
    Langton's Ant. The class includes an enumerated type for the ant's
    direction, along with private member variables and public memnber
    functions.
******************************************************************************/

#ifndef ANT_HPP
#define ANT_HPP

enum Direction {UP = 1, RIGHT, DOWN, LEFT};

class Ant
{
    private:
        char positionColor; //Set all squares to blank
        Direction antFacing;
        int rows, cols;
        int antX, antY;
        int steps;

    public:
        void userInput();
        void print(char **boardIn);
        void antAdvance();
        void turnAnt(int turnsIn);
        void makeMove(char **boardIn);
        char getPositionColor();
        void setPositionColor(char colorIn);
        void setAntFacing(Direction facingIn);
        int getRows();
        int getCols();

};

#endif //ANT_HPP
