/******************************************************************************
** Program name: Path to Principal: A Ballet Game
** Author: Rebecca L. Taylor
** Date: 5 December 2017
** Description: This header file declares the member variables and functions
    of the Space class, the abstract base class for other spaces of the
    game.
******************************************************************************/

#ifndef SPACE_HPP
#define SPACE_HPP

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <map>
using std::map;

class Space
{
protected:
    string spaceName;                  //Name of the space
    string actionName;                 //Name of outcome completed in the space
    string path;                       //Description of the route to the room

    bool complete;                     //Whether the room has been completed
    bool locked;                       //Whether the room is open or locked

    enum Directions{up = 0, right, down, left};
    map<Directions, Space*> doors;     //Map of doors in each Space

public:
    Space();                           //Constructor

    //Functions to work with spaces
    virtual void printSpace();
    Space* selectSpace(Space *currentSpace);
    int findOpenDoors(std::vector<int> &doorNums);
    virtual int outcome() = 0;

    //Setter and getter functions
    void setDoors(Space *upDoor, Space *rightDoor,
                  Space *downDoor, Space *leftDoor);
    void setLock(bool locked);
    void setSpaceName(const string &spaceName);
    string getActionName() const;
    void setPath(const string &pathName);
    bool getComplete() const;
    virtual void setComplete(bool complete);
};

#endif //SPACE_HPP
