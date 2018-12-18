/******************************************************************************
** Program name: OSU Information System
** Author: Rebecca L. Taylor
** Date: 22 October 2017
** Description: This header file defines the member variables and functions
    of the Instructor class, which is inherited from the Person class.
******************************************************************************/

#ifndef INSTRUCTOR_HPP
#define INSTRUCTOR_HPP

#include "Person.hpp"

class Instructor : public Person
{
private:
    double rating;
public:
    Instructor();
    Instructor(const string &instrucName, const int &ageIn,
               const double &ratingIn);
    void setRating();
    virtual string getScore() const override;
    void do_work() override;
};


#endif //INSTRUCTOR_HPP
