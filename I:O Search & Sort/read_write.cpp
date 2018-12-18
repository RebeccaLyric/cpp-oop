/******************************************************************************
** Program name: Searching and sorting
** Author: Rebecca L. Taylor
** Date: 19 November 2017
** Description: This implementation file defines the functions used to read
    and write files which are searched and sorted.
******************************************************************************/

#include "read_write.hpp"

#include <stdlib.h>
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <cstring>
#include <string>
using std::string;

#include <vector>

#include <fstream>
using std::ifstream;
using std::ofstream;
using std::ios;

/******************************************************************************
//Definition of openFile
///The function takes a vector of ints passed by reference and a string with a
//file name as its parameters. The user is prompted for a file name until the
//file is able to be opened. Once opened, the getNums function is called to
//read integers from the file into the vector. The file is then closed.
******************************************************************************/
void openFile(std::vector<int> &numVector, std::string &name)
{
    string fileName;
    ifstream readFile;

    //Open the input file
    cout << "Enter the name of a file to read:" << endl;
    getline(cin, fileName);
    readFile.open(fileName.c_str(), ios::in);

    while (!readFile)                  //Check file can be opened
    {
        cout << "Error opening file. ";
        cout << "Please enter the name of the file to read:" << endl;
        getline(cin, fileName);
        readFile.open(fileName.c_str(), ios::in);
    }

    if (readFile)
    {
        //Read numbers into vector
        getNums(readFile, numVector);
        name = fileName;
    }

    readFile.close();
}

/******************************************************************************
//Definition of getNums
///The function takes a vector of ints passed by reference and a file input
//stream as its parameters. Each character of the filestream is read any
//single-digit integer values are added to the vector.
******************************************************************************/
void getNums(ifstream &fileStream, std::vector<int> &numVector)
{
    char check;
    check = fileStream.get();

    while (check != EOF)
    {
        if (isdigit(check))
        {
            //Save check value as int and convert from ASCII
            int num = static_cast<int>(check) - 48;

            //Assign num to vector
            numVector.push_back(num);
        }

        check = fileStream.get();
    }
}

/******************************************************************************
//Definition of writeSorted
///The function takes a vector of ints passed by reference as its parameter.
//The user is prompted for a filename to write values to, then the contents
//of the vector are written to an output file stream. The file is closed
//and the file name is returned as a string so that the file can be read later.
******************************************************************************/
std::string writeSorted(std::vector<int> &numVector)
{
    string fileName;
    ofstream outputFile;

    //Prompt user for name of output file
    cout << "Please enter the name of the file to write sorted list to:"
         << endl;
    getline(cin, fileName);
    outputFile.open(fileName.c_str(), ios::out);

    if (!outputFile)                   //Check file can be opened
    {
        cout << "Error opening file.";
        cout << "Please enter the name of the file to write sorted list to:"
             << endl;
        getline(cin, fileName);
        outputFile.open(fileName.c_str(), ios::out);
    }

    //Write vector to file
    cout << "Writing to file" << endl;
    for (int i = 0; i < numVector.size(); i++)
    {
        outputFile.put(numVector[i]+48) << " ";
    }
    cout << endl;

    //Close file
    outputFile.close();

    return fileName;
}
