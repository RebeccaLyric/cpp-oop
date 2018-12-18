/******************************************************************************
** Program name: Stack and Queue STL Containers
** Author: Rebecca L. Taylor
** Date: 26 November 2017
** Description: This implementation file defines the functions which demonstrate
    the STL queue container by simulating a buffer and the STL stack
    container by creating a palindrome.
******************************************************************************/

#include "STL_functions.hpp"

#include <cstdlib>

#include <queue>
using std::queue;

#include <stack>
using std::stack;

#include <iostream>
using std::cout;
using std::endl;

#include <iomanip>

/******************************************************************************
//Definition of buffer function
//The function takes three int values by reference as its parameters: the
//number of rounds, the percent chance to add a value, and the percent
//chance to remove a value. For each round, the function calls the appendN and
//removeN functions to add or remove values from the queue. After all rounds
//are completed, the end buffer size is printed, followed by all values and the
//average buffer length.
******************************************************************************/
void buffer(const int &numRounds, const int &addChance, const int &removeChance)
{
    std::queue<int> buffer;                      //Create buffer queue
    int currentLength = 0;                       //Current length of queue
    double avgLength = 0.0;                      //Average length of queue

    for (int i = 0; i < numRounds; i++)          //Queue operations for each round
    {
        cout << "Round " << i+1 << ": " << endl; //Print round number

        appendN(buffer, addChance);              //Append a number to queue
        removeN(buffer, removeChance);           //Remove number from queue
        cout << endl;

        //Get current queue length and call function to calculate average
        currentLength = static_cast<int>(buffer.size());
        avgLength = getAvgLength(currentLength, i, avgLength);
    }

    //Print size of queue and current values
    cout << "Size of buffer: " << currentLength << endl;

    cout << "Values in buffer: ";
    while (!buffer.empty())
    {
        cout << buffer.front() << " ";
        buffer.pop();
    }
    cout << endl;

    //Print average queue length
    cout << "Average buffer length: " << std::fixed << std::setprecision(2)
         << avgLength << endl << endl;
}

/******************************************************************************
//Definition of randInt
//The function uses the passed in min and max ints to generate a random int
//within the specified range.
******************************************************************************/
int randInt(int min, int max)
{
    return min + (rand() % (max - min + 1));;
}

/******************************************************************************
//Definition of appendN
//The function takes the buffer (STL queue) and chance of adding a number (int)
//as reference parameters. It generates a random int N and the chance of
//adding it to the queue. The number is added if percent chance is greater.
******************************************************************************/
void appendN(std::queue<int> &bufferIn, const int &chance)
{
    int min = 1;                            //Minimum value
    int N_max = 1000;                       //Maximum value of N
    int percent_max = 100;                  //Maximum percent value

    int N = randInt(min, N_max);            //Generate random number

    //Test if N will be appended to queue
    int appendNum = randInt(min, percent_max);
    if (appendNum <= chance)
    {
        cout << "Adding " << N << " to buffer" << endl;
        bufferIn.push(N);
    }
}

/******************************************************************************
//Definition of removeN
//The function takes the buffer (STL queue) and chance of removing a number (int)
//as reference parameters. The front of the queue is removed if not empty.
******************************************************************************/
void removeN(std::queue<int> &bufferIn, const int &chance)
{
    int min = 1;                            //Minimum value
    int percent_max = 100;                  //Maximum percent value

    //See if N will be removed from queue
    int removeN = randInt(min, percent_max);
    if (removeN <= chance)
    {
        if (!bufferIn.empty())              //Remove only if queue not empty
        {
            cout << "Removing " << bufferIn.front() << " from buffer" << endl;
            bufferIn.pop();
        }
    }
}

/******************************************************************************
//Definition of getAvgLength
//The function takes two int parameters (buffer size and round number) as well
//as a double of the current average. The new average is calculated and
//returned as a double.
******************************************************************************/
double getAvgLength(int size, int round, double rollingAvg)
{
    rollingAvg = ((rollingAvg * round) + size) / (round + 1);
    return rollingAvg;
}

/******************************************************************************
//Definition of palindrome
//The function takes a string parameter, then uses a stack to add the values
//of the original string to the stack. Characters are popped off one by one
//and appended to the original string in reverse order. The new word is
//returned as a string.
******************************************************************************/
std::string palindrome(std::string &word)
{
    std::stack<char> letters;                    //Create the stack
    std::string reverseWord;

    //Add characters to stack and reverseWord
    for (int i = 0; i < word.length(); i++)
    {
        letters.push(word[i]);
    }

    //Add top letter to reverse word, pop from stack
    while (!letters.empty())
    {
        reverseWord.push_back(letters.top());
        letters.pop();
    }

    return word + reverseWord;
}


