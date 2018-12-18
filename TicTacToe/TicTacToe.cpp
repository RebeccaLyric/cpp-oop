/******************************************************************************
** Author: Rebecca L. Taylor
** Date: 31 May 2017
** Description: This implementation file contains the functions for a 
         constructor to identify which player has the first move and the play
         method to start the game. Last, the main method asks which player
         will go first, creates a new TicTacToe object, and starts the game.
******************************************************************************/

#include "TicTacToe.hpp"

#include <cctype>
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

/*****************************************************************************
 *                        TicTacToe::TicTacToe                               *
 *     Constructor identifies whether x or o has first move                  *
 ****************************************************************************/     
TicTacToe::TicTacToe(char firstMove)
   {
     playerTurn = firstMove; 
   }

/*****************************************************************************
 *                        TicTacToe::play                                    *
 *  Starts the game and continues looping until game is won or a draw.       *
 ****************************************************************************/     
void TicTacToe::play()
   {
      int x, y;       //Variables for gameboard coordinates

      while (gameBoard.gameState() == UNFINISHED)
         {
              gameBoard.print();    //Prints current board to the screen
        
              cout << "Player " << playerTurn << ": "; 
              cout << "please enter your move." << endl;
              cin >> x >> y;

              if (gameBoard.makeMove(x, y, playerTurn)) //If space empty
                 {                                      //record move
                    if (playerTurn == 'x')
                       playerTurn = 'o';             //Switch to next
                    else if (playerTurn == 'o')      //player's turn  
                       playerTurn = 'x';
                 } 
              else //If space occupied
                {
                  cout << "That square is already taken." << endl;
                }
         }
      gameBoard.print();   //After game ended, print final board to screen 

      if (gameBoard.gameState() == 0)      //Print game status
         cout << "Player x won!" << endl;   
      if (gameBoard.gameState() == 1)
         cout << "Player o won!" << endl;   
      if (gameBoard.gameState() == 2)
         cout << "Game was a draw!" << endl;   
   }

/*****************************************************************************
 *                        Main method                                        *
 ****************************************************************************/     
int main()
{
   char p1;      //Variable for first player
   
   cout << "Which player will go first? (Enter either x or o)" << endl;
   cin >> p1;
      p1 = tolower(p1);   //If user entered uppercase, convert to lower
   TicTacToe game1(p1);   //Pass first player to TicTacToe constructor

   game1.play();          //Begin game

   return 0;
}
