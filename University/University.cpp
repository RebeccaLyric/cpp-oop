/******************************************************************************
** Program name: OSU Information System
** Author: Rebecca L. Taylor
** Date: 22 October 2017
** Description: This implementation file defines the member functions of the
    University class, including methods to add people and buildings as well
    as to print the information af people and buildings at the university.
******************************************************************************/

#include "University.hpp"

#include <iostream>
#include <string>;
using std::cout;
using std::endl;

/******************************************************************************
//Definition of University::University constructor
//The constructor sets the university's name to Oregon State University.
******************************************************************************/
University::University()
{
    name = "Oregon State University";
}

/******************************************************************************
//Definition of University::getPeople
//The function returns the vector which stores all the Person objects
******************************************************************************/
std::vector<Person*> University::getPeople()const
{
    return people;
}

/*****************************************************************************
//Definition of University::addBuilding
//The function adds a Building object to the buildings vector
******************************************************************************/
void University::addBuilding(Building* buildingIn)
{
    //Source: https://stackoverflow.com/questions/15128444/
    //c-calling-a-function-from-a-vector-of-function-pointers-inside-a-class-where-t

    buildings.push_back(buildingIn);
}

/******************************************************************************
//Definition of University::addPerson
//The function adds a Person object to the people vector
******************************************************************************/
void University::addPerson(Person* personIn)
{
    //Source: https://stackoverflow.com/questions/15128444/
    //c-calling-a-function-from-a-vector-of-function-pointers-inside-a-class-where-t

    people.push_back(personIn);
}

/******************************************************************************
//Definition of University::printBuildings
//The function prints the name, size, and address of all objects in the
//buildings vector
******************************************************************************/
void University::printBuildings()
{
    cout << "OSU buildings: " << endl;
    for (int i = 0; i < buildings.size(); i++)
    {
        cout << "Building " << (i+1) << ": " << endl;
        cout << buildings[i]->getName() << endl;
        cout << buildings[i]->getSize() << " sq. ft." << endl;
        cout << buildings[i]->getAddress() << endl;
        cout << endl;
    }
}

/******************************************************************************
//Definition of University::printPeople
//The function prints the name, age, and score (either GPA or rating), of all
//objects in the people vector
******************************************************************************/
void University::printPeople()
{
    cout << "People at OSU: " << endl;
    for (int i = 0; i < people.size(); i++)
    {
        cout << "Person " << (i+1) << ": " << endl;
        cout << people[i]->getName() << endl;
        cout << people[i]->getAge() << endl;
        cout << people[i]->getScore() << endl;
        cout << endl;
    }

}

