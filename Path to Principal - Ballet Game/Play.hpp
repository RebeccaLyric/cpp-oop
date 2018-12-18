/******************************************************************************
** Program name: Path to Principal: A Ballet Game
** Author: Rebecca L. Taylor
** Date: 5 December 2017
** Description: This header file declares the member variables and functions
    of the Play class used to execute the ballet game.
******************************************************************************/

#ifndef PLAY_HPP
#define PLAY_HPP

#include "PracticeStudio.hpp"
#include "Physio.hpp"
#include "Stage.hpp"

#include "Dancer.hpp"

class Play
{
private:
    enum Status {WIN, LOSE, UNFINISHED};         //Game status
    Status status;

    PracticeStudio *studio1;                     //Game Spaces
    PracticeStudio *studio2;
    PracticeStudio *studio3;
    Physio *physio;
    Stage *petiteStage;
    Stage *grandStage;

    Dancer *dancer;                              //Game player

public:
    Play();
    ~Play();

    void play();
    void dance(DanceSpace *danceSpace, Dancer *dancer);
    void unlock(Space *currentSpace);
    void gameOver();
    void reset(Dancer *dancer);
};

#endif //PLAY_HPP
