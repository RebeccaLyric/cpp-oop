/******************************************************************************
** Program name: Stack and Queue STL Containers
** Author: Rebecca L. Taylor
** Date: 26 November 2017
** Description: This header file declares the functions which demonstrate
    the STL queue container by simulating a buffer and the STL stack
    container by creating a palindrome.
******************************************************************************/

#ifndef STL_FUNCTIONS_HPP
#define STL_FUNCTIONS_HPP

#include <string>
#include <queue>
#include <stack>

void buffer(const int &numRounds, const int &addChance, const int &removeChance);
int randInt(int min, int max);
void appendN(std::queue<int> &bufferIn, const int &chance);
void removeN(std::queue<int> &bufferIn, const int &chance);
double getAvgLength(int size, int round, double rollingAvg);
std::string palindrome(std::string &word);

#endif //STL_FUNCTIONS_HPP
