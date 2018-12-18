/******************************************************************************
** Program name: Path to Principal: A Ballet Game
** Author: Rebecca L. Taylor
** Date: 5 December 2017
** Description: This implementation file defines the member functions
    of the dancePlay class used to execute the ballet game.
******************************************************************************/

#include "DancePlay.hpp"
#include "Dancer.hpp"
#include "Menu.hpp"

#include <iostream>
using std::cout;
using std::endl;

#include <algorithm>
using std::find;

/******************************************************************************
//Definition of DancePlay::DancePlay
//The function
******************************************************************************/
DancePlay::DancePlay()
{
    status = UNFINISHED;

    //Create game spaces and initialize variables
    studio1 = new PracticeStudio;
    studio1->setSpaceName("Practice Studio 1");
    studio1->setDanceStep("plies and tendus");
    studio1->setItem("pointe shoes");
    studio1->setPath("go to Practice Studio 1");
    studio1->setLock(false);                     //Room unlocked at start

    studio2 = new PracticeStudio;
    studio2->setSpaceName("Practice Studio 2");
    studio2->setDanceStep("arabesques");
    studio2->setItem("tutu");
    studio2->setPath("go to Practice Studio 2");

    studio3 = new PracticeStudio;
    studio3->setSpaceName("Practice Studio 3");
    studio3->setDanceStep("pirouettes");
    studio3->setItem("tiara");
    studio3->setPath("go to Practice Studio 3");

    physio = new Physio;                         //Variables initialized in constructor

    petiteStage = new Stage;
    petiteStage->setSpaceName("the Petite Stage");
    petiteStage->setItem("bouquet of carnations");
    petiteStage->setPath("go downstairs to the Petite Stage");

    grandStage = new Stage;
    grandStage->setSpaceName("the Grand Stage");
    grandStage->setItem("bouquet of roses");
    grandStage->setPath("go downstairs to the Grand Stage");

    //Set doors for each dance space (order of up, right, down, left)
    studio1->setDoors(NULL, studio2, studio3, NULL);
    studio2->setDoors(NULL, NULL, physio, studio1);
    studio3->setDoors(studio1, physio, petiteStage, NULL);
    physio->setDoors(studio2, NULL, petiteStage, studio3);
    petiteStage->setDoors(physio, NULL, grandStage, NULL);
    grandStage->setDoors(petiteStage, NULL, NULL, NULL);
}

/******************************************************************************
//Definition of DancePlay::~DancePlay destructor
//The function
******************************************************************************/
DancePlay::~DancePlay()
{
    delete studio1;
    delete studio2;
    delete studio3;
    delete physio;
    delete petiteStage;
    delete grandStage;
}

/******************************************************************************
//Definition of DancePlay::playGame
//The function
******************************************************************************/
void DancePlay::play()
{
    //Create dancer object and begin in Practice Studio 1 with 100 energy
    Dancer *dancer = new Dancer;
    dancer->setCurrentSpace(studio1);
    dancer->setEnergy(100);

    //Print game info
    Menu::printIntro();
    Menu::printMap();

    cout << "\nYou have " << dancer->getEnergy()
         << " points of energy to begin." << endl;

    while (status == UNFINISHED)                      //Play game
    {
        //Print info for current space and get user option
        Space *current = dancer->getCurrentSpace();
        current->printSpace();
        cout << "Your energy is: " << dancer->getEnergy() << endl;
        int option = Menu::spaceOptions(current);

        if (option == 1)                              //If chooses to interact
        {
            if (current != physio)                    //If in a dance space
            {
                //Cast current room as practice studio and call dance function
                DanceSpace *danceSpace = dynamic_cast<DanceSpace*>(current);
                dance(danceSpace, dancer);

                if (status == UNFINISHED)             //If game did not end
                {
                    unlock(current);                  //Unlock next space(s)
                    danceSpace->setComplete(true);    //Set room to complete
                }
            }

            if (current == physio)                    //If in physical therapy
            {
                //Cast current room as physio and call recuperate function
                dancer->calcEnergy(physio->actionOutcome());
            }
        }

        else if (option == 2)                         //Else if change spaces
        {
            //Print map and select next space
            Menu::printMap();
            dancer->setCurrentSpace(current->selectSpace(current));
        }
    }

    //Free memory and reset variables for next game
    reset(dancer);
    delete dancer;
}

/******************************************************************************
//Definition of DancePlay::dance
//The function
******************************************************************************/
void DancePlay::dance(DanceSpace *danceSpace, Dancer *dancer)
{
    int numAttempts = 0;                    //Reset number of attempts to 0
    int numComplete = 0;                    //Reset completed steps to 0

    if (danceSpace->getComplete())          //If space already complete
    {
        danceSpace->printSpaceInfo('c');    //Print completed message
    }

    else                                    //If room not complete
    {
        danceSpace->printSpaceInfo('p');    //Print space info

        while (dancer->getEnergy() > 0 &&
               numComplete < danceSpace->getMinComplete())
        {
            numAttempts++;
            cout << "Attempt " << numAttempts << ": " << endl;

            //Do practice step and add to number completed
            numComplete += danceSpace->actionOutcome();

            //Adjust dancer's energy
            dancer->calcEnergy(danceSpace->getExertion() * -1);

            //If dancer out of energy, game over
            if (dancer->checkEnergy() <= 0)
            {
                gameLost(dancer);
                return;
            }
        }
        cout << endl;

        danceSpace->printSpaceInfo('e');    //Print message for space ended

        cout << "You now have " << dancer->getEnergy()
             << " points of energy." << endl;

        //Add item earned from practice studio to dance bag
        dancer->addItem(danceSpace->getItem());
        dancer->printDanceBag();

        //Game won if roses added to dance bag
        if (dancer->findRoses())
        {
            gameWon();
        }
    }
}

/******************************************************************************
//Definition of DancePlay::unlock
//The function
******************************************************************************/
void DancePlay::unlock(Space *currentSpace)
{
    //If Practice Studio 1 completed, unlock Practice Studios 2 and 3
    if (currentSpace == studio1 && !studio1->getComplete())
    {
        cout << "\nPractice Studio 2 and Practice Studio 3 are unlocked!"
             << endl << endl;
        studio2->setLock(false);
        studio3->setLock(false);
    }

    //If Practice Studios 2 and 3 are completed, unlock Petite Stage
    if ((currentSpace == studio2 && !studio2->getComplete() &&
         studio3->getComplete()) ||
        (currentSpace == studio3 && !studio3->getComplete() &&
         studio2->getComplete()))
    {
        cout << "\nYou completed all three practice rooms! " << endl
             << "The Petite Stage is unlocked!" << endl << endl;
        petiteStage->setLock(false);
    }

    //If Petite Stage completed, unlock Grand Stage
    if (currentSpace == petiteStage && !petiteStage->getComplete())
    {
        cout << "\nThe Grand Stage is unlocked! " << endl
             << "You're only one successful performance away "
             << "from winning the game!" << endl << endl;
        grandStage->setLock(false);
    }
}

/******************************************************************************
//Definition of DancePlay::gameLost
//The function
******************************************************************************/
void DancePlay::gameLost(Dancer *dancer)
{
    cout << "You have " << dancer->getEnergy()
         << " points of energy." << endl;

    cout << "Oh no! You ran out of energy before getting roses." << endl;
    cout << "You lose :-(" << endl << endl;
    status = LOSE;
}

/******************************************************************************
//Definition of DancePlay::gameWon
//The function
******************************************************************************/
void DancePlay::gameWon()
{
    cout << "You won the game! You are now a principal dancer!" << endl;
    cout << "CONGRATULATIONS!!!" << endl << endl;

    status = WIN;
}

/******************************************************************************
//Definition of DancePlay::reset
//The function
******************************************************************************/
void DancePlay::reset(Dancer *dancer)
{
    status = UNFINISHED;

    studio1->setLock(false);
    studio1->setComplete(false);

    studio2->setLock(true);
    studio2->setComplete(false);

    studio3->setLock(true);
    studio3->setComplete(false);

    physio->setLock(false);
    physio->setComplete(false);

    petiteStage->setLock(true);
    petiteStage->setComplete(false);

    grandStage->setLock(true);
    grandStage->setComplete(false);

    dancer->emptyDanceBag();
    dancer->setEnergy(100);
}








