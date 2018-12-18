/******************************************************************************
** Program name: OSU Information System
** Author: Rebecca L. Taylor
** Date: 22 October 2017
** Description: This implementation file defines the methods of the Instructor
    class, which is inherited from the Person class. It includes constructors,
    set and get functions, and the overridden do_work function.
******************************************************************************/

#include "Instructor.hpp"
#include <cstdlib>

#include <iostream>
#include <sstream>
#include <iomanip>
using std::cout;
using std::endl;

/******************************************************************************
//Definition of Instructor::Instructor (no parameters)
//The function sets the name, age, and rating  of the Instructor object to
//default values.
******************************************************************************/
Instructor::Instructor()
{
    name = "Instructor";
    setAge();
    setRating();
}

/******************************************************************************
//Definition of Instructor::Instructor (3 parameters)
//The function takes a string, int, and double as parameters to set the name,
//age, and rating of the Instructor.
******************************************************************************/
Instructor::Instructor(const string &instrucName, const int &ageIn,
                       const double &ratingIn)
{
    name = instrucName;
    age = ageIn;
    rating = ratingIn;
}

/******************************************************************************
//Definition of Instructor::setRating()
//The function sets the rating of the Instructor to a random value between 0.0
//and 5.0
******************************************************************************/
void Instructor::setRating()
{
    int min = 0.0;
    int max = 5.0;
    rating = min + (rand() % (max - min + 1));
}

/******************************************************************************
//Definition of Instructor::getScore()
//The function returns the string "Rating: " plus the rating of the Instructor
******************************************************************************/
string Instructor::getScore() const
{
    //Source: https://stackoverflow.com/questions/16605967/
    //set-precision-of-stdto-string-when-converting-floating-point-values
    std::ostringstream output;
    output << std::fixed << std::setprecision(1) << rating;
    return "Rating: " + output.str();
}

/******************************************************************************
//Definition of Instructor::do_work()
//The function selects a random number of grading hours between 2 and 40.
//It then prints a message indicating the hours of grading done.
******************************************************************************/
void Instructor::do_work()
{
    int min = 2;
    int max = 40;
    int gradingHours = min + (rand() % (max - min + 1));
    cout << getName() << " graded papers for "
         << gradingHours << " hours." << endl;
    cout << endl;
}
