/******************************************************************************
** Program name: OSU Information System
** Author: Rebecca L. Taylor
** Date: 22 October 2017
** Description: This header file declares the member variables and functions
    of the University class.
******************************************************************************/

#ifndef UNIVERSITY_HPP
#define UNIVERSITY_HPP

#include "Building.hpp"
#include "Person.hpp"

#include <string>
#include <vector>

class University
{
private:
    std::string name;
    std::vector<Building*> buildings;
    std::vector<Person*> people;

public:
    University();
    std::vector<Person*> getPeople() const;
    void addBuilding(Building*);
    void addPerson(Person*);
    void printBuildings();
    void printPeople();
};

#endif //UNIVERSITY_HPP
