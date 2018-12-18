/******************************************************************************
** Program name: Path to Principal: A Ballet Game
** Author: Rebecca L. Taylor
** Date: 5 December 2017
** Description: This header file declares the member variables and functions
    of the Physio class, a derived class of Space.
******************************************************************************/

#ifndef PHYSIO_HPP
#define PHYSIO_HPP

#include "Space.hpp"

class Physio : public Space
{
public:
    Physio();
    int outcome() override;
};

#endif //PHYSIO_HPP
