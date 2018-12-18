/******************************************************************************
** Program name: File I/O
** Author: Rebecca L. Taylor
** Date: 8 October 2017
** Description: This main file implements a program to read a file, count the
    letter frequencies in each paragraph, and write the results to a new file.  
******************************************************************************/ 
#include "count_letters.hpp"
#include "output_letters.hpp"

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include<string>
using std::string;

#include <fstream>
using std::ifstream;
using std::ofstream;
using std::ios;

int main()
{
    const int LETTER_COUNT = 26;
    string fileName;
    string input;
    ifstream readFile;
    ofstream writeFile;

    //Allocate memory for array to store letter counts
    int *letters = new int[LETTER_COUNT];

    //Initialize each element to 0
    for (int i = 0; i < LETTER_COUNT; i++)
    {
        letters[i] = 0;
    }

    cout << "Please enter the name of the file to read:" << endl;
    getline(cin, fileName);

    //Open the input file
    readFile.open(fileName.c_str(), ios::in);
    if (!readFile)
    {
        cout << "Error opening file.";
        return 1;
    }

    //Call count_letters to get letter count
    //Function to output count to new file called from within count_letters
    count_letters(readFile, letters);

    //Close file
    readFile.close();

    //Free memory allocated to array
    delete [] letters;

    return 0;
}
