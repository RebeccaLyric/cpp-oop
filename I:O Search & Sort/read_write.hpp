/******************************************************************************
** Program name: Searching and sorting
** Author: Rebecca L. Taylor
** Date: 19 November 2017
** Description: This header file provides the function declarations for the
    functions used to read and write files which are searched and sorted.
******************************************************************************/

#ifndef READ_WRITE_HPP
#define READ_WRITE_HPP

#include <string>
#include <vector>
#include <fstream>
using std::ifstream;

//Function declarations
void openFile(std::vector<int> &numVector, std::string &name);
void getNums(ifstream &fileStream, std::vector<int> &numVector);
std::string writeSorted(std::vector<int> &numVector);

#endif //READ_WRITE_HPP
