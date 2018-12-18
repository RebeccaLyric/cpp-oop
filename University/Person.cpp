/******************************************************************************
** Program name: OSU Information System
** Author: Rebecca L. Taylor
** Date: 22 October 2017
** Description: This implementation file defines the methods of the Person
    class. It includes constructors and set and get functions for the member
    variables.
******************************************************************************/

#include "Person.hpp"
#include <cstdlib>

/******************************************************************************
//Definition of Person::Person (no arguments)
//The constructor sets the name and age variables of the Person object to
//default values.
******************************************************************************/
Person::Person()
{
    setName("name");
    setAge();
}

/******************************************************************************
//Definition of Person::Person (2 arguments)
//The constructor accepts a string and int parameter to set the name and age of
//the Person object.
******************************************************************************/
Person::Person(const string &nameIn, const int &ageIn)
{
    name = nameIn;
    age = ageIn;
}

/******************************************************************************
//Definition of Person::setName
//The function accepts a string to set the name of the Person object.
******************************************************************************/
void Person::setName(const string &nameIn)
{
    name = nameIn;
}

/******************************************************************************
//Definition of Person::getName
//The function returns as a string the name of the Person.
******************************************************************************/
string Person::getName()const
{
    return name;
}

/******************************************************************************
//Definition of Person::setAge
//The function selects a random age between 18 and 75 returned as an int.
******************************************************************************/
void Person::setAge()
{
    int min = 18;
    int max = 75;
    age = min + (rand() % (max - min + 1));
}

/******************************************************************************
//Definition of Person::getAge
//The function returns as an int the age of the Person.
******************************************************************************/
int Person::getAge()const
{
    return age;
}
