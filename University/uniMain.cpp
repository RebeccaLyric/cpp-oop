/******************************************************************************
** Program name: OSU Information System
** Author: Rebecca L. Taylor
** Date: 22 October 2017
** Description: The main file
******************************************************************************/
#include "uniMenu.hpp"
#include "getInteger.hpp"
#include "University.hpp"
#include "Building.hpp"
#include "Person.hpp"
#include "Instructor.hpp"
#include "Student.hpp"

#include <iostream>
#include <cstdlib>
//#include <string>
using std::cin;
using std::cout;
using std::endl;
//using std::string;

int main()
{
    srand(time(NULL));
    string input;

    cout << "Welcome to the OSU Information System" << endl;
    cout << endl;

    University osu;

    //Instantiate students
    Student* s1 = new Student("Steven Universe", 18, 3.0);
    osu.addPerson(s1);

    Student* s2 = new Student("Sadie Miller", 21, 3.8);
    osu.addPerson(s2);

    //Instantiate instructors
    Instructor* i1 = new Instructor("Priyanka Maheswaran", 42, 4.8);
    osu.addPerson(i1);

    Instructor* i2 = new Instructor("Bill Dewey", 53, 1.9);
    osu.addPerson(i2);

    //Instantiate buildings
    Building* b1 = new Building("DC - Dairy Barn", 32878,
                                "4490 Harrison Blvd");
    osu.addBuilding(b1);

    Building* b2 = new Building("Gladys Valley Gymnastics Center", 18702,
                                "1701 SW Jefferson Ave");
    osu.addBuilding(b2);

    int option = uniMenu();
    while (option != 4)
    {
        switch (option)
        {
            case 1:
                osu.printBuildings();
                break;
            case 2:
                osu.printPeople();
                break;
            case 3:
                //do work
                cout << "Enter the number of the person who will do work "
                     << "at the university. " << endl;
                cout << "Number must be between 1 and " << osu.getPeople().size()
                     << "." << endl;

                //Get user input
                getline(cin, input);

                //Validate input
                int choice = getInteger(input);

                //Check user choice is one of existing people
                int max = osu.getPeople().size();
                while (choice <= 0 || choice > max)
                {
                    cout << "Please enter the number of one of the "
                         << "existing people." << endl;
                    getline(cin, input);
                    choice = getInteger(input);
                }

                osu.getPeople()[choice-1]->do_work();

                break;
        }
        option = uniMenu();
    }

    delete s1;
    delete s2;
    delete i1;
    delete i2;
    delete b1;
    delete b2;

    return 0;
}
