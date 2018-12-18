/******************************************************************************
** Program name: Fantasy Combat Tournament
** Author: Rebecca L. Taylor
** Date: 19 November 2017
** Description: This header file provides the prototypes for the functions
    designed to give the user options to play the combat tournament.
******************************************************************************/

#ifndef TOURNEYMENU_HPP
#define TOURNEYMENU_HPP

#include "Character.hpp"
#include "tourneyQueue.hpp"

class tourneyMenu
{
public:
    int menuChoice();
    static void createLineups(TourneyQueue *team);
    static int getTeamSize();
    static int selectChar();
    static void setPlayer(TourneyQueue *team, const int &charChoice);
    static int viewLoserList();
};


#endif //TOURNEYMENU_HPP

