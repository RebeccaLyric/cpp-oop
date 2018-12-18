/******************************************************************************
** Program name: OSU Information System
** Author: Rebecca L. Taylor
** Date: 22 October 2017
** Description: This implementation file defines the functions of the Building
    class. It includes constructors as well as get methods for variables.
******************************************************************************/

#include "Building.hpp"

/******************************************************************************
//Definition of Building::Building constructor (no arguments)
//The function sets default values for name, size, and address of the Building
//object.
******************************************************************************/
Building::Building()
{
    name = "Building name";
    size = 0;
    address = "address";
}

/******************************************************************************
//Definition of Building::Building constructor (3 arguments)
//The function takes 2 strings and an int as arguments to set the name, size,
//and address variables of the Building object.
******************************************************************************/
Building::Building(const string &nameIn, const int &sizeIn,
                   const string &addressIn)
{
    name = nameIn;
    size = sizeIn;
    address = addressIn;
}

/******************************************************************************
//Definition of Building::getName
//The function returns as a string the name of the Building object.
******************************************************************************/
string Building::getName() const
{
    return name;
}

/******************************************************************************
//Definition of Building::getSize
//The function returns as an int the size of teh Building object.
******************************************************************************/
int Building::getSize() const
{
    return size;
}

/******************************************************************************
//Definition of Building::getAddress
//The function returns as a string the address of the Building object.
******************************************************************************/
string Building::getAddress() const
{
    return address;
}