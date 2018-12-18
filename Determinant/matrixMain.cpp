/******************************************************************************
** Program name: Matrix Calculator 
** Author: Rebecca L. Taylor
** Date: 29 September 2017
** Description: This main file runs a program to create either a 2x2 or 3x3
	matrix using a dynamically allocated 2D array. The user is prompted to
	choose the size of the matrix then the 2D array is created. The
	readMatrix function prompts the user for the values in the matrix and 
	fills it. The determinant function then calculates the determinant
	of the matrix. The matrix and determinant are displayed before the 
	space allocated to the 2D array is freed using delete.
******************************************************************************/
#include "readMatrix.hpp"
#include "determinant.hpp"
#include "getInteger.hpp"

#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
   int size; //Variable for size of matrix
   int determ; //Variable for determinant
   string input; //Variable for user input

   //Prompt user to choose size of matrix
   do
    {
       cout << "Please enter either 2 or 3 to choose "
            << "the size of the matrix." << endl;
       cout <<  "Enter 2 for a 2x2 matrix. " 
            <<  "Or enter 3 for a 3x3 matrix." << endl;

       cin >> input;
       size = getInteger(input);        //Assign validated integer to size
    }
    while ((size != 2) && (size != 3)); //Validate user input is either 2 or 3

   //Dynamically allocate space for 2D array
   //Adapted from stackoverflow.com/questions/8767166/passing-a-2d-array-
   //to-a-c-function
   int **matrix = new int*[size];
   for (int i = 0; i < size; i++)
        {
           matrix[i] = new int[size];
        }

   //Call readMatrix function to prompt user to enter values to fill the array
   readMatrix(matrix, size);

   //Call determinant function to calculate the determinant
   determ = determinant(matrix, size);

   //Display the matrix 
   cout << "Matrix: " << endl;
   for (int row = 0; row < size; row++)
        {
          for (int col = 0; col < size; col++)
                 cout << matrix[row][col] << " ";

          cout << endl; 
        }

   //Display the determinant 
   cout << "Determinant = " << determ << endl;
   
   //Free memory allocated for 2D array
   //Adapted from stackoverflow.com/questions/30720594/deleting-a-
   //dynamically-allocated-2d-array
   for (int i = 0; i < size; i++) //Delete each sub-array
        {
           delete [] matrix[i];
        }

   delete [] matrix; //Delete the array
 
   return 0;
}
