/*****************************************************************************
** Author: Rebecca L. Taylor
** Date: 31 May 2017
** Description: This header file defines the class Board that represents
                a tic-toe-board and includes the prototypes of its
                member functions.
*****************************************************************************/

#ifndef BOARD_HPP
#define BOARD_HPP

enum Status {X_WON, O_WON, DRAW, UNFINISHED};

class Board
{
   private:
      char playerMoves[3][3];  //3x3 array to store location of moves

   public:
      //default constructor to initialize empty board
      Board();

      //makeMove method 
      bool makeMove(int, int, char); 

      //gameState method
      Status gameState();
 
      //print method
      void print();
};

#endif  
