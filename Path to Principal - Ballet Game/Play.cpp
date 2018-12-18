/******************************************************************************
** Program name: Path to Principal: A Ballet Game
** Author: Rebecca L. Taylor
** Date: 5 December 2017
** Description: This implementation file defines the member functions
    of the dancePlay class used to execute the ballet game.
******************************************************************************/

#include "Play.hpp"
#include "Menu.hpp"

#include <iostream>
using std::cout;
using std::endl;

#include <algorithm>

/******************************************************************************
//Definition of DancePlay::DancePlay constructor
//The function sets up the game by allocating memory for 6 game Spaces,
//sets their variables, and assigns their 4 doors as pointers to other Spaces.
//Lastly, memory is allocated for the Dancer (player).
******************************************************************************/
Play::Play()
{
    status = UNFINISHED;

    //Allocate memory for six game Spaces, set variables
    studio1 = new PracticeStudio;
    studio1->setSpaceName("Practice Studio 1");
    studio1->setDanceStep("plies and tendus");
    studio1->setItem("pointe shoes");
    studio1->setPath("go to Practice Studio 1");
    studio1->setLock(false);                     //Space unlocked at start

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

    //Allocate memory for dancer and begin in Practice Studio 1 with 100 energy
    dancer = new Dancer;
    dancer->setCurrentSpace(studio1);
    dancer->setEnergy(100);
}

/******************************************************************************
//Definition of DancePlay::~DancePlay destructor
//The function frees the memory of the six game spaces and dancer.
******************************************************************************/
Play::~Play()
{
    delete studio1;
    delete studio2;
    delete studio3;
    delete physio;
    delete petiteStage;
    delete grandStage;

    delete dancer;
}

/******************************************************************************
//Definition of DancePlay::playGame
//The function first prints introductory info. While the game is unfinished,
//the user chooses to interact or move spaces. Functions are called based on
//user choice and whether the current space is a dance space or physio. After
//game is finished, the game variables are reset.
******************************************************************************/
void Play::play()
{
    Menu::printIntro();
    Menu::printMap();
    cout << "\nYou have " << dancer->getEnergy()
         << " points of energy to begin." << endl;

    while (status == UNFINISHED)                      //Play game
    {
        //Print info for current space
        Space *current = dancer->getCurrentSpace();
        current->printSpace();
        cout << "Your energy is: " << dancer->getEnergy() << endl;

        int option = Menu::spaceOptions(current);     //Get user option

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
                //Recuperate and add to energy
                dancer->calcEnergy(physio->outcome());
            }
        }

        else if (option == 2)                         //Else if change spaces
        {
            //Print map and select next space
            Menu::printMap();
            dancer->setCurrentSpace(current->selectSpace(current));
        }
    }

    //Reset variables for next game
    reset(dancer);
}

/******************************************************************************
//Definition of DancePlay::dance
//The function takes pointers to the current dance space and dancer as
//parameters. It executes the action of the space and has variables to keep
//track of the number of attempts and number of completed steps. For each
//attempt, the dancer loses energy and the function checks to see if energy
//has dropped below 0 to end the game. If the required number of steps was
//completed, the item is added to the dance bag. If roses are added, the
//game is won.
******************************************************************************/
void Play::dance(DanceSpace *danceSpace, Dancer *dancer)
{
    int numAttempts = 0;                    //Reset number of attempts to 0
    int numComplete = 0;                    //Reset completed steps to 0

    if (danceSpace->getComplete())          //If space already complete
    {
        danceSpace->printSpaceInfo('c');    //Print info for space completed
    }

    else                                    //If room not complete
    {
        danceSpace->printSpaceInfo('p');    //Print info for practice/perform

        while (dancer->getEnergy() > 0 &&
               numComplete < danceSpace->getMinComplete())
        {
            numAttempts++;
            cout << "Attempt " << numAttempts << ": " << endl;

            //Do practice step and add to number completed
            numComplete += danceSpace->outcome();

            //Adjust dancer's energy, pass as negative integer
            dancer->calcEnergy(danceSpace->getExertion() * -1);

            //If dancer out of energy, game over
            if (dancer->getEnergy() <= 0)
            {
                cout << "You have " << dancer->getEnergy()
                     << " points of energy." << endl;
                status = LOSE;              //Game lost
                gameOver();                 //Print game end message
                return;
            }
        }
        cout << endl;

        danceSpace->printSpaceInfo('e');    //Print info for space ended

        cout << "You now have " << dancer->getEnergy()
             << " points of energy." << endl;

        //Add item earned from practice studio to dance bag
        dancer->addItem(danceSpace->getItem());
        dancer->printDanceBag();

        //Game won if roses added to dance bag
        if (dancer->findRoses())
        {
            status = WIN;                   //Game won
            gameOver();                     //Print game end message
        }
    }
}

/******************************************************************************
//Definition of DancePlay::unlock
//The function takes a pointer to the current space as its parameter. After
//certain rooms are completed, others are unlocked.
******************************************************************************/
void Play::unlock(Space *currentSpace)
{
    //If in Practice Studio 1 and not already completed
    if (currentSpace == studio1 && !studio1->getComplete())
    {
        cout << "\nPractice Studio 2 and Practice Studio 3 are unlocked!"
             << endl << endl;
        studio2->setLock(false);                 //Unlock Practice Studio 2
        studio3->setLock(false);                 //Unlock Practice Studio 3
    }

    //If in Practice Studio 2 or 3 and not already completed
    if ((currentSpace == studio2 && !studio2->getComplete() &&
         studio3->getComplete()) ||
        (currentSpace == studio3 && !studio3->getComplete() &&
         studio2->getComplete()))
    {
        cout << "\nYou completed all three practice rooms! " << endl
             << "The Petite Stage is unlocked!" << endl << endl;
        petiteStage->setLock(false);             //Unlock Petite Stage
    }

    //If in Petite Stage and not already completed
    if (currentSpace == petiteStage && !petiteStage->getComplete())
    {
        cout << "\nThe Grand Stage is unlocked! " << endl
             << "You're only one successful performance away "
             << "from winning the game!" << endl << endl;
        grandStage->setLock(false);              //Unlock Grand Stage
    }
}

/******************************************************************************
//Definition of DancePlay::gameOver
//The function is called after Dancer's energy is <= 0. It prints a message
//depending on whether game was lost or won.
******************************************************************************/
void Play::gameOver()
{
    if (status == WIN)
    {
        cout << "\nYou won the game! You are now a principal dancer!" << endl;
        cout << "CONGRATULATIONS!!!" << endl << endl;
    }

    else if (status == LOSE)
    {
        cout << "\nOh no! You ran out of energy before getting roses." << endl;
        cout << "You lose :-(" << endl << endl;
    }

    cout << "~ FIN ~" << endl << endl;
}

/******************************************************************************
//Definition of DancePlay::reset
//The function takes a pointer to Dancer as its parameter. It resets all locks
//and completion statuses for the 6 game Spaces and empties the Dancer's
//dance bag and resets Dancer's energy to starting value of 100.
******************************************************************************/
void Play::reset(Dancer *dancer)
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
    dancer->setCurrentSpace(studio1);
}








