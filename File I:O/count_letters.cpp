/******************************************************************************
** Program name: File I/O
** Author: Rebecca L. Taylor
** Date: 8 October 2017
** Description: This implementation file defines the count_letters function.
    It takes a file stream object and pointer to an array of ints as its
    paramaters. For each paragraph, each letter of the alphabet is counted
    and stored in the array. The output_letters function is called to write
    the letter count of each paragraph to a new file.
******************************************************************************/ 
#include "count_letters.hpp"
#include "output_letters.hpp"

#include <iostream>
using std::cout;
using std::endl;
#include <string>
using std::string;

void count_letters(ifstream &fileStream, int *letterArray)
{
    string input;
    const int LETTER_COUNT = 26;

    getline(fileStream, input);
    while (!fileStream.fail())
    {
        //Check each element and add to respective letter count
        for (int i = 0; i < input.length(); i++)
        {
            for (int k = 0; k < LETTER_COUNT; k++)
            {
                //Check for uppercase or lowercase using ASCII codes
                if (input[i] == (65+k) || input[i] == (97+k))
                {
                    letterArray[k] += 1;
                }
            }
        }

        //Write letter count to new file using output_letters function
        ofstream output;
        output_letters(output, letterArray);

        //Reset each element of letterArray to 0
        for (int i = 0; i < LETTER_COUNT; i++)
        {
            letterArray[i] = 0;
        }

        getline(fileStream, input);
    }

}
