/******************************************************************************
** Program name: Path to Principal: A Ballet Game
** Author: Rebecca L. Taylor
** Date: 5 December 2017
** Description: This header file defines the member functions
    of the Stage class, a derived class of DanceSpace.
******************************************************************************/

#include "Stage.hpp"

#include <stdlib.h>
#include <iostream>
using std::cout;
using std::endl;

/******************************************************************************
//Definition of Stage::Stage constructor
//The function sets the default variables for a Stage.
******************************************************************************/
Stage::Stage()
{
    spaceName = "Stage";
    actionName = "perform";
    item = "flowers";
    exertion = 10;
    minComplete = 1;
}

/******************************************************************************
//Definition of Stage::printSpaceInfo
//The function takes a char parameter and uses a switch statement to print
//the appropriate message depending on whether the player is performing ('p'),
//the space is completed ('c'), or at the end of the space completion ('e').
******************************************************************************/
void Stage::printSpaceInfo(const char &option)
{
    switch (option)
    {
        case 'p':                                //If performing
        {
            cout << "You must charm the audience and get a standing ovation"
                 << " to earn your " << item << "." << endl;
            cout << "You will lose " << exertion
                 << " points of energy for each attempt." << endl << endl;
            break;
        }

        case 'c':                                //If space completed
        {
            cout << "\nYou have already performed on this stage. "
                 << "Give someone else a shot." << endl;
            break;
        }

        case 'e':                                //If at end of completion
        {
            cout << "You earned your " << item << "!" << endl;
            break;
        }
    }

}

/******************************************************************************
//Definition of Stage::outcome
//The function gets a random outcome result from the parent class function
//which is returned as an int. If statements determine whether the result
//indicated successful performance or a fall. The number of successful
//performances is returned as an int.
******************************************************************************/
int Stage::outcome()
{
    int result = DanceSpace::outcome();          //Get int result (from 1-3)

    switch (result)
    {
        case 1:
        {
            cout << "Your partner dropped you! "
                 << "How embarrassing :-(" << endl << endl;

            return 0;                            //0 successful performances
        }

        case 2:
        {
            cout << "You fell out of your pirouettes in Act II "
                 << "and your costume ripped." << endl;
            cout << "The audience was not impressed. " << endl << endl;
            return 0;                            //0 successful performances
        }

        default:
        {
            cout << "Your performance was brilliant!" << endl;
            cout << "You got a standing ovation and earned a "
                 << item << "!" << endl << endl;
            return 1;                            //1 successful performance
        }
    }





}




