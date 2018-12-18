/******************************************************************************
** Program name: Recursive Functions
** Author: Rebecca L. Taylor
** Date: 29 October 2017
** Description: This implementation file defines two menu functions which
    allow the user to choose to reverse a string, add an array of integers,
    or find the triangular number of an integer.
******************************************************************************/

#include "recursionMenu.hpp"
#include "getInteger.hpp"
#include "recursion.hpp"

#include <iostream>
#include <string>
using std::string;
using std::cin;
using std::cout;
using std::endl;

/******************************************************************************
//Definition of mainMenu
//The function offers the user the main options to reverse a string, add an
//array of integers, or find the triangular number of an integer.
******************************************************************************/
void mainMenu()
{
    string input;                  //Variable to hold user input
    int option = 0;                //Variable to hold user's choice
    int minimum = 1;               //Variable for minimum range
    int maximum = 4;               //Variable for maximum range

    //Print menu options
    cout << "Please choose one of the following options:" << endl;
    cout << "Enter '1' to reverse a string." << endl;
    cout << "Enter '2' to add an array of integers." << endl;
    cout << "Enter '3' to get the triangular number of an integer." << endl;
    cout << "Or enter '4' to exit the program." << endl;

    //Get user input, validate int, and check is one of specified options
    getline(cin, input);
    option = getInteger(input);
    option = checkRange(option, minimum, maximum);

    if (option == 1 || option == 2 || option == 3)
    {
        //Call selected recursive function
        functionMenu(option);
    }

    else if (option == 4)
    {
        return;
    }

}

/******************************************************************************
//Definition of functionMenu
//The function executes the three recursive functions of the program based on
//which option is provided as the int parameter.
******************************************************************************/
void functionMenu(int option)
{
    string input;                  //Variable to hold user input
    int minimum;                   //Variable for minimum for range
    int maximum;                   //Variable of maximum for range


    switch (option)
    {
        //Recursive function 1: stringReverse
        case 1: {
            string words;          //String to be reversed
            cout << "Enter a string to reverse." << endl;

            //Get user input and reverse string
            getline(cin, words);
            printReverse(words);

            cout << endl;

            //Call mainMenu for user to choose next function
            mainMenu();

            break;
        }

        case 2:
        {
            //Recursive function 2: sumIntArray
            minimum = 2;           //Set minimum value of array size
            maximum = 10;          //Set maximum value of array size
            int size;              //Variable to hold array size

            cout << "Please enter the number of array elements. "
                 << "Number should be between " << minimum << " and "
                 << maximum << "." << endl;

            //Get user input, validate int, and check is within range
            getline(cin, input);
            size = getInteger(input);
            size = checkRange(size, minimum, maximum);

            //Create array of selected size
            int *numList = new int[size];

            //Ask user to fill values of array
            minimum = 0;
            maximum = 500;
            cout << "Enter " << size << " numbers between " << minimum 
                 << " and " << maximum << "." << endl;

            for (int i = 0; i < size; i++)
            {
                //Get user input and validate int
                getline(cin, input);
                int num = getInteger(input);
                num = checkRange(num, minimum, maximum);

                //Add validated value to array
                numList[i] = num;
            }

            //Print array
            cout << "Here is the array: " << endl;
            for (int i = 0; i < size; i++) {
                cout << numList[i] << " ";
            }
            cout << endl;

            //Sum array
            cout << "The sum of numbers in the array is: "
                 << arrSum(numList, size) << endl << endl;

            //Free memory
            delete [] numList;

            //Call mainMenu for user to choose next function
            mainMenu();

            break;
        }

        case 3: {
            //Recursive function 3: triNum
            int num;               //Variable for number used in calculation
            minimum = 0;
            maximum = 100;

            cout << "Enter a number between 0 and 100 "
                 << "to calculate its triangular number." << endl;

            //Get user input and validate int
            getline(cin, input);
            num = getInteger(input);
            num = checkRange(num, minimum, maximum);

            //Calculate triangular number
            cout << "Triangular number of " << num << " equals: "
                 << triNum(num) << endl << endl;

            //Call mainMenu for user to choose next function
            mainMenu();

            break;
        }
    }
}

