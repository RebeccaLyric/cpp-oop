/******************************************************************************
** Program name: Path to Principal: A Ballet Game
** Author: Rebecca L. Taylor
** Date: 5 December 2017
** Description: This header file defines the functions
    of the PracticeStudio class, a derived class of DanceSpace.
******************************************************************************/

#include "PracticeStudio.hpp"

#include <stdlib.h>
#include <iostream>
using std::cout;
using std::endl;

/******************************************************************************
//Definition of PracticeStudio::PracticeStudio constructor
//The function sets the variables of the class to default values.
******************************************************************************/
PracticeStudio::PracticeStudio()
{
    spaceName = "Practice Studio";
    danceStep = "step";
    actionName = "practice";
    item = "costume";
    exertion = 5;
    minComplete = 3;
}

/******************************************************************************
//Definition of PracticeStudio::printSpace
//The function prints the dance step and item of the practice studio.
******************************************************************************/
void PracticeStudio::printSpace()
{
    Space::printSpace();                         //Print the name of the space
    cout << "Practice " << danceStep << " to earn your "
         << item << endl << endl;
}

/******************************************************************************
//Definition of PracticeStudio::printSpaceInfo
//The function takes a char parameter and uses a switch statement to print
//the appropriate message depending on whether the player is practicing ('p'),
//the space is completed ('c'), or at the end of the space completion ('e').
******************************************************************************/
void PracticeStudio::printSpaceInfo(const char &option)
{
    switch (option)
    {
        case 'p':                           //If practicing
        {
            cout << "You must complete " << minComplete << " or more "
                 << danceStep << " to earn your " << item << endl;
            cout << "You will lose " << exertion
                 << " points of energy for each attempt." << endl << endl;
            break;
        }

        case 'c':                           //If space completed
        {
            cout << "\nYou have already earned your " << item << ". "
                 << "Go to another room." << endl << endl;
            break;
        }

        case 'e':                           //If at end of completion
        {
            cout << "You completed the required " << danceStep
                 << " and earned your " << item
                 << "!" << endl << endl;
            break;
        }
    }
}

/******************************************************************************
//Definition of PracticeStudio::outcome
//The function gets a random outcome result from the parent class function
//which is returned as an int. If statements determine whether the result
//indicated successful steps or a fall. The number of successful steps is
//returned as an int.
******************************************************************************/
int PracticeStudio::outcome()
{
    int result = DanceSpace::outcome();          //Get int result (from 1-3)

    if (result == 1 || result == 2)              //If 1 or 2
    {
        cout << "You did " << result << " "
             << danceStep << "!" << endl;

        return result;                           //Return result as num of
    }                                            //completed steps

    else if (result == 3)                        //If 3
    {
        cout << "Whoops! You fell :-( " << endl;
        return 0;                                //Return 0 completed steps
    }

}

/******************************************************************************
//Definition of Studio::setDanceStep
//The function takes a string parameter to set the name of the step.
******************************************************************************/
void PracticeStudio::setDanceStep(const string &danceStep)
{
    this->danceStep = danceStep;
}








