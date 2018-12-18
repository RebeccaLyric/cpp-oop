/******************************************************************************
** Program name: Matrix Calculator 
** Author: Rebecca L. Taylor
** Date: 29 September 2017
** Description: This implementation file defines the readMatrix function.
	It takes two parameters: a pointer to a dynamically allocated square 
	2D array and its size (number of rows/columns). The function asks
	the user for values to fill the array and stores the input in the
	array without returning any values.
******************************************************************************/ 
#include "getInteger.hpp"

#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;

void readMatrix(int **matrixIn, int sizeIn)
{
   string input; //Variable to hold user input
   int validInteger; //Variable to hold validated integer

   //Prompt user for values to fill array
   cout << "Please enter " << (sizeIn * sizeIn) 
        << " values to fill the array." << endl;
               
   //Fill array with user input 
   for (int row = 0; row < sizeIn; row++)
        {
          for (int col = 0; col < sizeIn; col++)
               {
                   cin >> input; 
                   
                   validInteger = getInteger(input); //Validate input is int
                   matrixIn[row][col] = validInteger;

                   //Matrix input without input validation
                   //cin >> matrixIn[row][col];  
                    
               }            
        }  

   return;
}
