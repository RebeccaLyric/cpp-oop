/******************************************************************************
** Program name: Path to Principal: A Ballet Game
** Author: Rebecca L. Taylor
** Date: 5 December 2017
** Description: This implementation file defines the functions
    of the DanceSpace class, the abstract base class for other spaces of the
    game.
******************************************************************************/

#include "Space.hpp"
#include "getInteger.hpp"

#include <iostream>
using std::cout;
using std::endl;

/******************************************************************************
//Definition of Space::Space constructor
//The function initializes member variables and sets the four pointers to NULL.
******************************************************************************/
Space::Space()
{
    spaceName = "dance space";
    actionName = "outcome";
    locked = true;

    doors[up] = NULL;
    doors[right] = NULL;
    doors[down] = NULL;
    doors[left] = NULL;
}

/******************************************************************************
//Definition of Space::printSpace
//The function prints the player's current location
******************************************************************************/
void Space::printSpace()
{
    cout << "\nYou are at " << spaceName << endl;
}

/******************************************************************************
//Definition of Space::selectSpace
//The function takes a pointer to the current space as its parameter. It calls
//the findOpenDoors function to get the number of open doors and put the
//corresponding numbers in a vector. If any doors are open, the function
//gets the user's choice and iterates through the doors map to find the
//matching space, which is returned as a pointer to Space.
******************************************************************************/
Space* Space::selectSpace(Space *currentSpace)
{
    int numDoors = 0;                            //Set number of open doors to 0
    std::vector<int> doorNums;                   //Vector to store open doors

    Space::printSpace();                         //Print current space
    numDoors = findOpenDoors(doorNums);          //Get unlocked doors

    if (numDoors == 0)                           //If no open doors found
    {
        cout << "No doors are open. You must unlock "
             << currentSpace->spaceName << endl;

        return currentSpace;                     //Cannot move, return current
    }

    else if (numDoors > 0)                       //If open doors available
    {
        int choice = getInteger(1, numDoors);    //Get user choice
        int j = 0;                               //int to access numDoors vector

        //Iterate through doors map and doorNums vector to find matching choice
        for (std::map<Directions, Space*>::iterator  iter = doors.begin(); 
             iter != doors.end(); iter++)
        {
            if (choice != doorNums[j])           //If choice does not match
            {
                j++;                             //Go to next vector element
            }

            else if (choice == doorNums[j])      //If choice does match
            {
                return doors[iter->first];       //Return pointer to Space
            }
        }
    }
}

/******************************************************************************
//Definition of Space::findOpenDoors
//The function takes a vector of door nums by reference as its parameter. It
//iterates through the map of door pointers to see which are open. If open,
//the door is pushed to the vector and the number of open doors incremented.
//Otherwise, 0 is pushed to the vector to indicate a closed door. The number
//of open doors is returned as an int.
******************************************************************************/
int Space::findOpenDoors(std::vector<int> &doorNums)
{
    int numOpen = 0;                             //Number of open doors set to 0

    //Iterate through doors map to find open doors
    for (std::map<Directions, Space*>::iterator  iter = doors.begin(); 
         iter != doors.end(); ++iter)
    {
        //If Space pointer not null and door is not locked
        if (iter->second != NULL && !iter->second->locked)
        {
            numOpen++;                           //Increment open doors count
            cout << "Enter '" << numOpen << "' to "
                 << iter->second->path << endl;  //Print door option
            doorNums.push_back(numOpen);         //Add num to doorNums vector
        }

        else                                     //Else if not an open door
        {
            doorNums.push_back(0);               //Add 0 to indicate locked Space
        }
    }

    return numOpen;                              //Return number of open doors
}

/******************************************************************************
//Definition of Space::setDoors
//The function has four pointers to Space as parameters which are used to
//set the four door pointers.
******************************************************************************/
void Space::setDoors(Space *upDoor, Space *rightDoor,
                     Space *downDoor, Space *leftDoor)
{
    doors[up] = upDoor;
    doors[right] = rightDoor;
    doors[down] = downDoor;
    doors[left] = leftDoor;
}

/******************************************************************************
//Definition of Space::setLock
//The function takes a bool parameter to set whether or not the door is locked.
******************************************************************************/
void Space::setLock(bool locked)
{
    this->locked = locked;
}

/******************************************************************************
//Definition of Space::setSpaceName
//The function takes a string parameter to set the name of the space.
******************************************************************************/
void Space::setSpaceName(const string &spaceName)
{
    this->spaceName = spaceName;
}

/******************************************************************************
//Definition of Space::getActionName
//The function returns the space's action as a string.
******************************************************************************/
string Space::getActionName() const
{
    return actionName;
}

/******************************************************************************
//Definition of Space::setPath
//The function takes a string parameter to set the description of the path.
******************************************************************************/
void Space::setPath(const string &pathName)
{
    path = pathName;
}

/******************************************************************************
//Definition of Space::getComplete
//The function returns a bool indicating whether the space has been completed.
******************************************************************************/
bool Space::getComplete() const
{
    return complete;
}

/******************************************************************************
//Definition of DanceSpace::setComplete
//The function returns as an int the minimum number of steps or performances
//required to complete the space.
******************************************************************************/
void Space::setComplete(bool complete)
{
    this->complete = complete;
}


