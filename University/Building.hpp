/******************************************************************************
** Program name: OSU Information System
** Author: Rebecca L. Taylor
** Date: 22 October 2017
** Description: This header file declares the member variables and functions
    of the Building class.
******************************************************************************/

#ifndef BUILDING_HPP
#define BUILDING_HPP

#include <string>
using std::string;

class Building
{
private:
    string name;
    int size;
    string address;
public:
    Building();
    Building(const string &nameIn, const int &sizeIn, const string &addressIn);
    string getName() const;
    int getSize() const;
    string getAddress() const;
};

#endif //BUILDING_HPP
