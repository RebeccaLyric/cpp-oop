/******************************************************************************
** Program name: getInteger (input validation)
** Author: Rebecca L. Taylor
** Date: 19 November 2017
** Description: This implementation file defines functions used to get
    and validate integer input and ensure the input is within the specified
    range.
******************************************************************************/

#include "getInteger.hpp"

#include <iostream>
#include <string>
#include <stdlib.h>
using std::cin;
using std::cout;
using std::endl;
using std::string;

/******************************************************************************
//Definition of getInteger
//The function takes one parameter: a string of user input. A bool variable
//keeps track of whether each element of the string meets the integer
//conditions. If false, the user is prompted to enter a whole number. The
//function then converts the validated input to an int which is returned.
******************************************************************************/
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

/******************************************************************************
//Definition of checkRange
//The function takes three int parameters: an integer number and minimum and
//maximum ints for the number. It uses a while loop to check whether the
//number is within range and get new input if necessary. It then returns the
//validated number.
******************************************************************************/
int checkRange(int num, int min, int max)
{
    string input;

    while (num < min || num > max)
    {
        cout << "Please enter a number between " << min
             << " and " << max << "." << endl;
        getline(cin, input);
        num = getInteger(input);
    }

    return num;
}

