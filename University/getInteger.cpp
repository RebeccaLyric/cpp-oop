/******************************************************************************
** Program name: getInteger (input validation)
** Author: Rebecca L. Taylor
** Date: 22 October 2017
** Description: This implementation file defines the getInteger function.
	It takes one parameter: a string of user input. A bool variable keeps
	track of whether each element of the string meets the integer
	conditions. If false, the user is prompted to enter a whole number.
	The function then converts the validated input to an int which is
	returned.
******************************************************************************/

#include "getInteger.hpp"

#include <iostream>
#include <string>
#include <stdlib.h>
using std::cin;
using std::cout;
using std::endl;
using std::string;

int getInteger(string inputIn)
{
    bool isInteger = false;   //bool variable set to false

    while (isInteger == false)
    {

        //Check first element
        if (isdigit(inputIn[0]))
        {
            isInteger = true;
        }

        //loop tests if following elements are digits
        for (int i = 0; i < inputIn.length(); i++)
        {
            if (!isdigit(inputIn[i]))
            {
                cout << "Error: "
                     << "Please enter a positive whole number." << endl;

                getline(cin, inputIn);

                isInteger = false;   //bool set to false to repeat loop
            }

        }

    }

    //Convert validated string to int
    int validInt = atoi(inputIn.c_str());

    return validInt;
}

