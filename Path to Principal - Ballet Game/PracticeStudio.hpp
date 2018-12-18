/******************************************************************************
** Program name: Path to Principal: A Ballet Game
** Author: Rebecca L. Taylor
** Date: 5 December 2017
** Description: This header file declares the member variables and functions
    of the PracticeStudio class, a derived class of DanceSpace, which is
    in turn derived from Space.
******************************************************************************/

#ifndef PRACTICESTUDIO_HPP
#define PRACTICESTUDIO_HPP

#include "DanceSpace.hpp"

#include <string>
using std::string;

class PracticeStudio : public DanceSpace
{
private:
    string danceStep;                  //Name of step practiced in the studio

public:
    PracticeStudio();

    void printSpace() override;
    void printSpaceInfo(const char &option) override;
    int outcome() override;

    void setDanceStep(const string &danceStep);
};


#endif //PRACTICESTUDIO_HPP
