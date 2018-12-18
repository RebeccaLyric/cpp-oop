/******************************************************************************
** Program name: Searching and sorting
** Author: Rebecca L. Taylor
** Date: 19 November 2017
** Description: This implementation file defines the functions for simple
    search and sort operations, as well as a function to get the search target
    value and print the searched/sorted vector.
******************************************************************************/

#include "search.hpp"
#include "getInteger.hpp"
#include "read_write.hpp"

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <fstream>
using std::ofstream;
using std::ios;

/******************************************************************************
//Definition of getTarget
///The function prompts the user for an integer and validates input before
//returning the target value as an int.
******************************************************************************/
const int getTarget()
{
    string input;
    int target;
    int min = 0;
    int max = 9;

    cout << "Enter an integer between 0 and 9 for the target value: " << endl;
    getline(cin, input);
    target = getInteger(input);
    target = checkRange(target, min, max);

    return target;
}

/******************************************************************************
//Definition of simpleSearch
///The function takes a vector of ints and the target value passed by reference
//as its parameters. The linear search reads every value of the array until
//the target is found. A message indicating whether the value was found is
//printed.
******************************************************************************/
void simpleSearch(const std::vector<int> &numVector, const int &target)
{
    //Source: Gaddis, 9th ed., p. 605
    int index = 0;
    bool found = false;

    while (index < numVector.size() && !found)
    {
        if (numVector[index] == target)
        {
            found = true;
            cout << "target value found" << endl;
        }
        index++;
    }

    if (!found)
    {
        cout << "target value not found" << endl;
    }
}

/******************************************************************************
//Definition of bubbleSort
///The function takes a vector of ints passed by reference as its parameter.
//Starting at the beginning of the vector, the function compares pairs of
//elements and swaps them to put them in ascending order. A bool keeps track
//of whether a swap has been made, and the scan repeats until the bool remains
//false. The sorted vector is then printed.
******************************************************************************/
void bubbleSort(std::vector<int> &numVector)
{
    //Sources: Gaddis, 9th ed., p. 615
    int temp;
    bool swapMade;

    do
    {
        swapMade = false;
        for (unsigned i = 0; i < (numVector.size() - 1); i++)
        {
            if (numVector[i] > numVector[i+1])
            {
                temp = numVector[i];
                numVector[i] = numVector[i+1];
                numVector[i+1] = temp;
                swapMade = true;
            }
        }
    } while (swapMade);

    cout << "Sorted numbers: ";
    printVector(numVector);
}

/******************************************************************************
//Definition of binarySearch
///The function takes a string of a file name and an unsigned search target
//passed by reference as its parameters. Value from the file are read into a
//vector. The position at the middle of the vector is selected, then the
//vector is divided in two depending on whether the target is less or greater
//than the middle. A bool keeps track of whether the value was found and a
//message with the found status is printed.
******************************************************************************/
void binarySearch(std::string &fileName, int &target)
{
    std::vector<int> nums;             //Vector to store ints read from file
    ifstream readFile;

    //Open the input file, read numbers into vector
    readFile.open(fileName.c_str(), ios::in);
    getNums(readFile, nums);
    readFile.close();

    printVector(nums);

    //Source: Gaddis, 9th ed., p. 609; Searching.pdf (lecture slides), p. 11
    int first = 0;
    int last = nums.size() -1;
    int mid;
    bool found = false;

    while (!found && first <= last)
    {
        mid = (first + last) / 2;

        if (nums[mid] > target)
        {
            last = mid - 1;
        }

        else if (nums[mid] < target)
        {
            first = mid +1;
        }

        else
        {
            found = true;
            cout << "target found in binary search of file" << endl << endl;
        }
    }

    if (!found)
    {
        cout << "target not found in binary search of file" << endl << endl;
    }

}

/******************************************************************************
//Definition of printVector
///The function prints each element in a vector. It is used to display sorted
//values.
******************************************************************************/
void printVector(std::vector<int> &numVector)
{
    for (unsigned i = 0; i < numVector.size(); i++)
    {
        cout << numVector[i] << " ";
    }
    cout << endl;
}



