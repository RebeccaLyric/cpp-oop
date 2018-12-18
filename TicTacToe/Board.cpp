/******************************************************************************
** Author: Rebecca L. Taylor
** Date: 31 May 2017
** Description: This implementation file defines the functions in the Board
      class: a default constructor, makeMove to record player moves,
      and gameState to return whether the game is unfinished, won, or a draw.
******************************************************************************/
#include "Board.hpp"

#include <iostream>
using std::cout;
using std::endl;

/*****************************************************************************
 *                        Board::Board                                       *
 *     Default constructor initializes the board as empty                    *
 ****************************************************************************/     
Board::Board()
{
  for (int row=0; row<3; row++)
     {
       for (int col=0; col<3; col++)
           playerMoves[row][col] = '.';  //Period denotes empty space on board
     }
}

/*****************************************************************************
 *                        Board::makeMove                                    *
 *     If space is empty, records x- and y-coordinates of player's move      *
 *     on board. If space is occupied, returns false.                        *
 ****************************************************************************/     
bool Board::makeMove(int xCoord, int yCoord, char playerTurn)
{ 
   if (playerMoves[xCoord][yCoord] == '.')   
      {
         switch(playerTurn)
         {
            case 'o': playerMoves[xCoord][yCoord] = 'o';
                      break;
            case 'x': playerMoves[xCoord][yCoord] = 'x';
                      break;
         } 
        return true; 
      }
   else 
        return false; 
}

/*****************************************************************************
 *                        Board::print                                       *
 *         Prints the current board to the screen                            *    
 ****************************************************************************/     
void Board::print()
{
    cout << "  0" << " 1" << " 2" << endl;  //Print column numbers
    for (int row = 0; row < 3; row++)
       {
         cout << row << " " ;               //Print row numbers
         for (int col=0; col<3; col++)
             cout << playerMoves[row][col] << " "; //Print game board
       
         cout << endl;
       }
}

/*****************************************************************************
 *                        Board::gameState                                   *
 *    Determines whether the game is unfinished, a win for player x,         *
 *    a win for player o, or a draw. The game status is then returned.       *
 ****************************************************************************/     
Status Board::gameState()
{
   //Game status initialized as unfinished 
   //Remains unfinished unless meets conditions for win or draw
   Status state = UNFINISHED;

   //Check for draw if all squares are filled (not blank)
   //If x or o won, status updated in following code
   if(playerMoves[0][0] != '.' &&
      playerMoves[0][1] != '.' &&
      playerMoves[0][2] != '.' &&
      playerMoves[1][0] != '.' &&
      playerMoves[1][1] != '.' &&
      playerMoves[1][2] != '.' &&
      playerMoves[2][0] != '.' &&
      playerMoves[2][1] != '.' &&
      playerMoves[2][2] != '.' ) 
     state = DRAW;

   //Check all rows for either x or o win
   for (int row = 0; row < 3; row++)
       {
         if(playerMoves[row][0] == 'x' && 
            playerMoves[row][1] == 'x' && 
            playerMoves[row][2] == 'x')
           state = X_WON;
 
         if(playerMoves[row][0] == 'o' && 
            playerMoves[row][1] == 'o' && 
            playerMoves[row][2] == 'o')
           state = O_WON; 
       }

   //Check all columns for either x or o win 
   for (int col = 0; col < 3; col++)
       {
         if(playerMoves[0][col] == 'x' && 
            playerMoves[1][col] == 'x' && 
            playerMoves[2][col] == 'x') 
          state = X_WON;
 
         if(playerMoves[0][col] == 'o' && 
            playerMoves[1][col] == 'o' && 
            playerMoves[2][col] == 'o')
          state = O_WON; 
       }

   //Check right-to-left diagonal for x or o win
   if(playerMoves[0][2] == 'x' && 
      playerMoves[1][1] == 'x' && 
      playerMoves[2][0] == 'x') 
    state = X_WON;
 
   if(playerMoves[0][2] == 'o' && 
      playerMoves[1][1] == 'o' && 
      playerMoves[2][0] == 'o') 
    state = O_WON;
 
   //Check left-to-right diagonal for x or o win
   if(playerMoves[0][0] == 'x' && 
      playerMoves[1][1] == 'x' && 
      playerMoves[2][2] == 'x') 
    state = X_WON;
 
   if(playerMoves[0][0] == 'o' && 
      playerMoves[1][1] == 'o' && 
      playerMoves[2][2] == 'o') 
    state = O_WON;

   return state; //return game status
}

