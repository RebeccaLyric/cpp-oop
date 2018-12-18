/******************************************************************************
** Program name: File I/O
** Author: Rebecca L. Taylor
** Date: 8 October 2017
** Description: This implementation file defines the output_letters function.
    It takes a file stream object and pointer to an array of ints as its
    paramaters. The user is prompted for the name of the output file, then
    the letter count is written to the file.
******************************************************************************/ 

#include "output_letters.hpp"

#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include<fstream>
using std::ios;
#include <string>
using std::string;

void output_letters(ofstream &outputFile, int* letterArray)
{
    string fileName;
    const int LETTER_COUNT = 26;

    //Prompt user for name of output file
    cout << "Please enter the name of the file to write to:" << endl;
    getline(cin, fileName);

    //Open the output file
    outputFile.open(fileName.c_str(), ios::out);
    if (!outputFile)
    {
        cout << "Error opening file.";
        return;
    }

    //Write letters and letter counts to file
    for (int i = 0; i < LETTER_COUNT; i++)
    {
        outputFile.put(97+i);
        outputFile << ": " <<letterArray[i] << endl;
    }

    //Close file
    outputFile.close();

}
