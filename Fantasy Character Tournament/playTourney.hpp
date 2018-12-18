/******************************************************************************
** Program name: Fantasy Combat Tournament
** Author: Rebecca L. Taylor
** Date: 19 November 2017
** Description: This header file declares the member variables and functions
    of the playTOurney class used to execute the fantasy combat tournament.
******************************************************************************/

#ifndef PLAYTOURNEY_HPP
#define PLAYTOURNEY_HPP

#include "Character.hpp"
#include "tourneyMenu.hpp"
#include "HarryPotter.hpp"
#include "Vampire.hpp"

#include <vector>
using std::vector;

class playTourney
{
private:
    TourneyQueue *team1;
    TourneyQueue *team2;
    TourneyQueue *losers;

    int attack;
    int roundNum;
    int battleNum;

    bool isDead;

public:
    playTourney();

    void playGame();
    void playRound(TourneyQueue *teamA, TourneyQueue *teamB);
    void medusaGlare(Character *attacker, Character *defender,
                     TourneyQueue *winTeam, TourneyQueue *loseTeam);
    void medusaVSvamp(Character *attacker, Vampire *vamp,
                      TourneyQueue *winTeam, TourneyQueue *loseTeam);
    void medusaVShp(Character *attacker, HarryPotter *hp,
                    TourneyQueue *winTeam, TourneyQueue *loseTeam);
    void roundOver(Character *loser, TourneyQueue *team);
    void recycleWinner(Character *winner, TourneyQueue *team);
    void tourneyOver();
    void printScores();
    void clearLineups();
};

#endif //PLAYTOURNEY_HPP
