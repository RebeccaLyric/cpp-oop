/******************************************************************************
** Program name: Path to Principal: A Ballet Game
** Author: Rebecca L. Taylor
** Date: 5 December 2017
** Description: This header file declares the member variables and functions
    of the Stage class, a derived class of DanceSpace.
******************************************************************************/

#ifndef STAGE_HPP
#define STAGE_HPP

#include "DanceSpace.hpp"

class Stage : public DanceSpace
{
public:
    Stage();

    int outcome() override;
    void printSpaceInfo(const char &option) override;
};

#endif //STAGE_HPP
