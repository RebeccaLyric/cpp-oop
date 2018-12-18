/*****************************************************************************
** Author: Rebecca L. Taylor 
** Date: 17 May 2017
** Description: This file contains the function definitions for the methods
     of the Person class. They get the two data members of the class.
     A constructor initializes the data members.
*****************************************************************************/

#include "Person.hpp"

//Person::getName to get the name of the person 
std::string Person::getName()
{
   return name;
}

//Person::getAge to get age of the person
double Person::getAge()
{
   return age;
}

/****************************************************************************
 *                         Person::Person                                   *
 *      Constructor with two parameters to initialize name and age          *
 ***************************************************************************/           
Person::Person(std::string nameIn, double ageIn)
{
  name = nameIn;
  age = ageIn;
}

