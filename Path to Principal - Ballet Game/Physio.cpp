/******************************************************************************
** Program name: Path to Principal: A Ballet Game
** Author: Rebecca L. Taylor
** Date: 5 December 2017
** Description: This implementation file defines the functions
    of the Physio class, a derived class of Space.
******************************************************************************/

#include "Physio.hpp"

#include <stdlib.h>
#include <iostream>
using std::cout;
using std::endl;

/******************************************************************************
//Definition of Physio::Physio constructor
//The function sets the variables of the Physio class.
******************************************************************************/
Physio::Physio()
{
    spaceName = "Physical Therapy";
    actionName = "recuperate";
    path = "visit the physical therapist";
    locked = false;
    complete = false;
}

/******************************************************************************
//Definition of Physio::outcome
//The function randomly determines how much the player recovers returns the
//result as an int. If the space is already complete, a message is printed.
******************************************************************************/
int Physio::outcome()
{
    int recovery = 0;                            //Recovery set to 0

    if (!complete)                               //If Physio not completed
    {
        int min = 10;                            //Minimum energy recovery
        int max = 20;                            //Maximum energy recovery

        recovery = min + (rand() % (max - min + 1));
        cout << "\nYou recovered " << recovery << " point(s) of energy!" << endl << endl;

        complete = true;                         //Set space completion to true
    }

    else if (complete)                           //If Physio completed
    {
        cout << "The physical therapist is too busy to see you again. "
             << "Go to another room." << endl << endl;
    }

    return recovery;
}



