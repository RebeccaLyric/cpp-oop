/******************************************************************************
** Author: Rebecca L. Taylor
** Date: 31 May 2017
** Description: This header file defines the class TicTacToe along with its
         member objects and functions.
******************************************************************************/

#ifndef TICTACTOE_HPP
#define TICTACTOE_HPP

#include "Board.hpp"

class TicTacToe
{
   private:
      Board gameBoard;
      char playerTurn;

   public:
      TicTacToe(char firstMove);
      void play();
};

#endif
