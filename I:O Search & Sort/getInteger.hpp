/******************************************************************************
** Program name: getInteger (input validation)
** Author: Rebecca L. Taylor
** Date: 19 November 2017
** Description: This header file provides the prototype for the getInteger
    function used to validate that user input is an integer.
******************************************************************************/

#ifndef GETINTEGER_HPP
#define GETINTEGER_HPP

#include <string>
using std::string;

int getInteger(string inputIn);
int checkRange(int numIn, int min, int max);

#endif //GETINTEGER_HPP
