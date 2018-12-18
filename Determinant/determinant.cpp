/******************************************************************************
** Program name: Matrix Calculator 
** Author: Rebecca L. Taylor
** Date: 29 September 2017
** Description: This implementation file defines the determinant function.
	It takes two parameters: a pointer to a dynamically allocated square 
	2D array and its size (number of rows/columns). The function uses a 
	switch statement to calculate either the determinant of a 2x2 matrix
	or a 3x3 matrix. It returns the determinant as an integer.
******************************************************************************/ 
#include "determinant.hpp"

int determinant(int **matrix, int sizeIn)
{
   int det = 0; //Variable to store determinant

   switch (sizeIn)
   {
      //If 2 by 2 matrix
      case 2:
       {
         //Assign each cell of matrix to letter variables
         int a = matrix[0][0]; 
         int b = matrix[0][1]; 
         int c = matrix[1][0]; 
         int d = matrix[1][1]; 
   
         //Calculate determinant
         det = (a*d) - (b*c);

         break;
       } 

      //If 3 by 3 matrix
      case 3:
       {
         //Assign each cell of matrix to letter variables
         int r = matrix[0][0]; 
         int s = matrix[0][1]; 
         int t = matrix[0][2]; 
         int u = matrix[1][0]; 
         int v = matrix[1][1]; 
         int w = matrix[1][2]; 
         int x = matrix[2][0]; 
         int y = matrix[2][1]; 
         int z = matrix[2][2]; 
   
         //Calculate determinant of each sub-matrix
         int m1 = (v*z) - (w*y);
         int m2 = (u*z) - (w*x);
         int m3 = (u*y) - (v*x);

         //Use sub-matrix determinants to calculate 3x3 determinant
         det = (r*m1) - (s*m2) + (t*m3);

         break;
       }
   }

   return det;
}
