/******************************************************************************
** Program name: Recursive functions
** Author: Rebecca L. Taylor
** Date: 29 October 2017
** Description: This header file declares three recursive functions. The first
    prints a string in reverse, the second recursively calculates the sun of
    an array of integers, and the third recursively calculates the
    triangular number of an integer N.
******************************************************************************/


#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <string>
using std::string;

//Function prototype for printReverse function
void printReverse(string wordsIn);
int arrSum(int *intArr, int arrSize);
int triNum(int numIn);