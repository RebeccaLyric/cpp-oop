/******************************************************************************
** Program name: Searching and sorting
** Author: Rebecca L. Taylor
** Date: 19 November 2017
** Description: This main file executes a program to demonstrate simple
    sort and search functions using input from a series of text files.
******************************************************************************/

#include "getInteger.hpp"
#include "read_write.hpp"
#include "search.hpp"

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include<string>
using std::string;

#include <vector>
using std::vector;

int main()
{
    const int NUM_FILES = 4;           //Four files will be searched
    string fileName;

    cout << "This program demonstrates search and sort functions using "
         << NUM_FILES << " text files." << endl;

    //Vectors to store numbers read from files and file names
    std::vector<std::vector<int> > numbers (NUM_FILES);
    std::vector<std::string> files (NUM_FILES);

    //Open each file and read numbers into vector, save each file name
    for (int i = 0; i < NUM_FILES; i++)
    {
        openFile(numbers[i], files[i]);
    }

    //Get target value
    int target = getTarget();

    //Perform search and sort on values from each file
    for (int i = 0; i < NUM_FILES; i++)
    {
        cout << files[i] << ": ";                //Print file name

        simpleSearch(numbers[i], target);        //Simple (linear) search
        bubbleSort(numbers[i]);                  //Bubble sort
        string name = writeSorted(numbers[i]);   //Returns string with name of output file
        binarySearch(name, target);              //Binary search on values in output file
    }

    return 0;
}
