/******************************************************************************
** Program name: getInteger (input validation)
** Author: Rebecca L. Taylor
** Date: 29 September 2017
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
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::stoi;

int getInteger(string inputIn)
{
   bool isInteger = false;   //bool variable set to false

   while (isInteger == false)
     {
	//Test if first element is '-' or a digit
	if ( (inputIn.at(0) == '-') || (isdigit(inputIn.at(0)))) 
            {
		isInteger = true; 		//set bool to true
            
		//loop tests if following elements are digits	
   		for (int i = 1; i < inputIn.length(); i++)
		   {
                      if (!isdigit(inputIn[i]) ) //if element is not digit
                          {
			    cout << "Error: not an integer. "
                                 << "Please enter a whole number." << endl; 

                            cin >> inputIn;
                            
			    isInteger = false;   //bool set to false to
						 //repeat loop	
                          }	
		   }	
	    }

	//If first element is not '-' or digit 
	else if ( (inputIn.at(0) != '-') && (!isdigit(inputIn.at(0))) ) 
                   {
                       cout << "Error: not an integer. "
                            << "Please enter a whole number." << endl; 

                       cin >> inputIn;

                       isInteger = false;   //Set bool to false to repeat loop
           } 
      }
   
   //Convert validated string to int
   int validInt = stoi(inputIn);

   return validInt;
} 


