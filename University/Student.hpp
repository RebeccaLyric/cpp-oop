/******************************************************************************
** Program name: OSU Information System
** Author: Rebecca L. Taylor
** Date: 22 October 2017
** Description: This header file defines the member variables and functions
    of the Student class, which is inherited from the Person class.
******************************************************************************/

#ifndef STUDENT_HPP
#define STUDENT_HPP

#include "Person.hpp"

class Student : public Person
{
private:
    double GPA;
public:
    Student();
    Student(const string &studentName, const int &ageIn,
               const double &GPAIn);
    void setGPA();
    string getScore() const override;
    void do_work() override;
};

#endif //STUDENT_HPP
