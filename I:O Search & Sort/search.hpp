/******************************************************************************
** Program name: Searching and sorting
** Author: Rebecca L. Taylor
** Date: 19 November 2017
** Description: This header file provides the function declarations for simple
    search and sort operations, as well as a function to get the search target
    value and print the searched/sorted vector.
******************************************************************************/

#ifndef SEARCH_HPP
#define SEARCH_HPP

#include <string>
#include <vector>
using std::vector;

//Function prototypes for search functions
const int getTarget();
void simpleSearch(const std::vector<int> &numVector, const int &target);
void bubbleSort(std::vector<int> &numVector);
void binarySearch(std::string &fileName, int &target);
void printVector(std::vector<int> &numVector);

#endif //SEARCH_HPP
