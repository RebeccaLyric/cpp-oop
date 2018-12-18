/******************************************************************************
** Program name: OSU Information System
** Author: Rebecca L. Taylor
** Date: 22 October 2017
** Description: This implementation file defines the methods of the Student
    class, which is inherited from the Person class. It includes constructors,
    set and get functions, and the overridden do_work function.
******************************************************************************/

#include "Student.hpp"
#include <cstdlib>

#include <iostream>
#include <sstream>
#include <iomanip>
using std::cout;
using std::endl;

/******************************************************************************
//Definition of Student::Student (no parameters)
//The function sets the name, age, and GPA of the Student object to default
//values.
******************************************************************************/
Student::Student()
{
    name = "Student";
    setAge();
    setGPA();
}

/******************************************************************************
//Definition of Student::Student (3 parameters)
//The function takes a string, int, and double as parameters to set the name,
//age, and GPA of the Student.
******************************************************************************/
Student::Student(const string &studentName, const int &ageIn,
                       const double &GPAIn)
{
    name = studentName;
    age = ageIn;
    GPA = GPAIn;
}

/******************************************************************************
//Definition of Student::setGPA()
//The function sets the GPA of the Student to a random value between 0.0 and
//4.0
******************************************************************************/
void Student::setGPA()
{
    int min = 0.0;
    int max = 4.0;
    GPA = min + (rand() % (max - min + 1));
}

/******************************************************************************
//Definition of Student::getScore()
//The function returns the string "GPA: " plus the GPA of the Student
******************************************************************************/
string Student::getScore() const
{
    //Source: https://stackoverflow.com/questions/16605967/
    //set-precision-of-stdto-string-when-converting-floating-point-values
    std::ostringstream output;
    output << std::fixed << std::setprecision(1) << GPA;
    return "GPA: " + output.str();
}

/******************************************************************************
//Definition of Student::do_work()
//The function selects a random number of homework hours between 2 and 40.
//It then prints a message indicating the hours of homework done.
******************************************************************************/
void Student::do_work()
{
    int min = 2;
    int max = 40;
    int homeworkHours = min + (rand() % (max - min + 1));
    cout << getName() << " did " << homeworkHours
         << " hours of homework." << endl;
    cout << endl;
}
