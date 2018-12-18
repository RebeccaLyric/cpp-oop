/******************************************************************************
** Program name: OSU Information System
** Author: Rebecca L. Taylor
** Date: 22 October 2017
** Description: This header file declares the member variables and functions
    of the Person class.
******************************************************************************/

#ifndef PERSON_HPP
#define PERSON_HPP

#include <string>
using std::string;

class Person
{
protected:
    string name;
    int age;
public:
    Person();
    Person(const string &nameIn, const int &ageIn);
    void setName(const string &nameIn);
    string getName() const;
    void setAge();
    int getAge() const;
    virtual string getScore() const = 0;
    virtual void do_work() = 0;
};

#endif //PERSON_HPP
