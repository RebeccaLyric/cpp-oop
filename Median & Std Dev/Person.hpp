/*****************************************************************************
** Author: Rebecca L. Taylor
** Date: 17 May 2017
** Description: This header file declares the class Person along with its
                member variables and functions.
*****************************************************************************/

#ifndef PERSON_HPP
#define PERSON_HPP
#include <string>

//Person class declaration
class Person
{
   private:
     std::string name;
     double age;

   public:
     //Constructor with two parameters to initialize name and age
     Person(std::string nameIn, double ageIn);

     //Get functions
     std::string getName();
     double getAge();

 };
#endif 
   
    
