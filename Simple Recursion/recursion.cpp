/******************************************************************************
** Program name: Recursive functions
** Author: Rebecca L. Taylor
** Date: 29 October 2017
** Description: This implementation file defines three recursive functions.
    The first prints a string in reverse, the second recursively calculates
    the sum of an array of integers, and the third recursively calculates the
    triangular number of an integer N.
******************************************************************************/

#include "recursion.hpp"

/******************************************************************************
//Definition of printReverse
//The function takes a string as its parameter and uses recursion to print the
//string in reverse order.
******************************************************************************/
void printReverse(string wordsIn)
{
    int last;                     //Holds position of last element of string

    //Base case when the string is empty
    if (wordsIn.empty())
    {
        //Print newline character
        cout << "\n";            
    }

    else                         //If string is not empty
    {
        //Assign string size to last
        last = wordsIn.size();   

        //Print last element
        cout << wordsIn[last-1]; 

        //Decrease array size by 1 
        wordsIn.resize(wordsIn.size()-1);

        //Call function again
        printReverse(wordsIn);   
    }
}

/******************************************************************************
//Definition of arrSum
//The function takes a pointer to an array of integers and the size of the
//array as its parameters. It uses recursion to calculate and return the sum of
//all integers in the array.
******************************************************************************/
int arrSum(int *intArr, int arrSize)
{
    //Base case when array size is zero
    if (arrSize == 0)
    {
        return 0;
    }

    else                         //If array size is not zero
    {
        return intArr[arrSize-1] + arrSum(intArr, (arrSize-1));
    }
}

/******************************************************************************
//Definition of triNum
//The function takes an integer parameter and uses recursion to calculate its
//triangular number, which is returned as an int.
******************************************************************************/
int triNum(int numIn)
{
    //Help from: https://chortle.ccsu.edu/java5/Notes/chap71/ch71_6.html
    //Base case when number equals zero
    if (numIn == 0)
    {
        return 0;
    }

    //Base case when number equals one
    else if (numIn == 1)
    {
        return 1;
    }

    //For numbers other than 0 and 1
    else
    {
        return numIn + triNum(numIn-1);
    }
}
