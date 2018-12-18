/******************************************************************************
** Program name: Path to Principal: A Ballet Game
** Author: Rebecca L. Taylor
** Date: 5 December 2017
** Description: This header file declares the member variables and functions
    of the dancePlay class used to execute the ballet game.
******************************************************************************/

#ifndef DANCEPLAY_HPP
#define DANCEPLAY_HPP

#include "PracticeStudio.hpp"
#include "Physio.hpp"
#include "Stage.hpp"
#include "Dancer.hpp"

enum Status {WIN, LOSE, UNFINISHED};

class DancePlay
{
private:
    Status status;

    PracticeStudio *studio1;
    PracticeStudio *studio2;
    PracticeStudio *studio3;
    Physio *physio;
    Stage *petiteStage;
    Stage *grandStage;

public:
    DancePlay();
    ~DancePlay();

    void play();
    void dance(DanceSpace *danceSpace, Dancer *dancer);
    void unlock(Space *currentSpace);
    void gameLost(Dancer *dancer);
    void gameWon();
    void reset(Dancer *dancer);
};

#endif //DANCEPLAY_HPP
