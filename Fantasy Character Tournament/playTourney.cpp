/******************************************************************************
** Program name: Fantasy Combat Tournament
** Author: Rebecca L. Taylor
** Date: 19 November 2017
** Description: This implementation file defines the member functions
    of the tourneyPlay class used to execute the fantasy combat game. It
    includes a constructor, the game flow, functions to select characters and
    play rounds, functions to handle the special cases when Medusa
    uses the glare ability, and functions to add team points and move players
    in the lineup when the round and tournament are over.
******************************************************************************/

#include "playTourney.hpp"
#include "getInteger.hpp"

#include <iostream>
#include <vector>
using std::vector;

using std::cin;
using std::cout;
using std::endl;

/******************************************************************************
//Definition of playTourney::playTourney constructor
//The function sets the initial attack roll to 0, the round number to 1, the
//battle number to 1, and the isDead bool to false to start the game.
******************************************************************************/
playTourney::playTourney()
{
    attack = 0;                    //Set attack score to 0
    roundNum = 1;                  //Set round number to 1
    battleNum = 1;                 //Set battle number to 1
    isDead = false;                //Set player death to false
}

/******************************************************************************
//Definition of playTourney::playGame
//The function calls the function to create team lineups, then continues to
//play rounds while both teams have players left in the lineup. When one
//team's lineup is empty, the tourneyOver function is called and team memory
//is freed.
******************************************************************************/
void playTourney::playGame()
{
    //Create lineups
    team1 = new TourneyQueue("Team 1");
    team2 = new TourneyQueue("Team 2");
    losers = new TourneyQueue("Defeated players");

    //Get players for team 1
    cout << "First select the players for team 1: " << endl;
    tourneyMenu::createLineups(team1);

    //Get players for team 2
    cout << "Next select the players for team 2: " << endl;
    tourneyMenu::createLineups(team2);

    //Play tournament battles while both teams have players in their lineups
    do
    {
        cout << "Beginning Tournament Battle " << battleNum << ": "
             << team1->getFront()->getName() << " versus "
             << team2->getFront()->getName() << endl;

        //Continue to play rounds while player is not dead
        while (!isDead)
        {
            cout << "Round " << roundNum << ": " << endl;

            //Play first round: player 1 attacks and player 2 defends
            playRound(team1, team2);

            //If player 2 did not die
            if (!isDead)
            {
                //Play second round: player 2 attacks and player 1 defends
                playRound(team2, team1);
            }

            //Increment round number
            roundNum++;
        }

        isDead = false;                //Reset isDead to false
        roundNum = 1;                  //Reset roundNum to 1
        battleNum++;                   //Increment battle number
        printScores();                 //Print team scores
        cout << endl;

    } while (!team1->isEmpty() && !team2->isEmpty());

    tourneyOver();       //Tournament ends after one of the team queues is empty
    clearLineups();      //Clear players from lineups

    //Free memory of team lineups
    delete team1;
    delete team2;
    delete losers;
}

/******************************************************************************
//Definition of playTourney::playRound
//The function passes in two pointers to team lineups. It first
//calculates the attack of the first player in the lineup. An attack of 100
//indicates Medusa glare, in which case specialized functions are called.
//Otherwise, the defense function of the firet player in the defending team's
//lineup is called.
******************************************************************************/
void playTourney::playRound(TourneyQueue *teamA, TourneyQueue *teamB)
{
    //First player in team A's lineup attacks
    attack = teamA->getFront()->attack();

    //First player in team B's lineup defends, unless Medusa glare
    if (attack != 100)
    {
        isDead = teamB->getFront()->defend(attack);

        //If defender died, game over
        if (isDead)
        {
            roundOver(teamB->getFront(), teamB);
            recycleWinner(teamA->getFront(), teamA);
        }

        cout << endl;
    }

    //Medusa's glare activated if attack is 100
    if (attack == 100)
    {
        //If defender is not a Vampire and is not Harry Potter
        if (teamB->getFront()->getType() != "Vampire" &&
            teamB->getFront()->getType() != "Harry Potter")
        {
            medusaGlare(teamA->getFront(), teamB->getFront(), teamA, teamB);
        }

        //If defender is Harry Potter
        if (teamB->getFront()->getType() == "Harry Potter")
        {
            medusaVShp(teamA->getFront(),
                       dynamic_cast<HarryPotter*>(teamB->getFront()),
                       teamA, teamB);
        }
 
        //If defender is Vampire
        if (teamB->getFront()->getType() == "Vampire")
        {
            medusaVSvamp(teamA->getFront(),
                         dynamic_cast<Vampire*>(teamB->getFront()),
                         teamA, teamB);
        }
    }
}

/******************************************************************************
//Definition of playTourney::medusaGlare
//The function takes a pointers to Character as the attacker and defender
//parameters. The defender dies from Medusa's glare and the round ends, then
//the winner (Medusa) is moved to the back of the team lineup.
******************************************************************************/
void playTourney::medusaGlare(Character *attacker, Character *defender,
                              TourneyQueue *winTeam, TourneyQueue *loseTeam)
{
    isDead = true;                     //Medusa turned opponent to stone
    roundOver(defender, loseTeam);     //Round is over, defender defeated
    recycleWinner(attacker, winTeam);  //Winner moved to back of lineup
}

/******************************************************************************
//Definition of playTourney::medusaVSvamp
//The function takes a pointer to Character as the attacker and Vampire as the
//defender, and pointers to the two team lineups. The Vampire's defend function
//is used to determine whether charm takes effect. If charm was not effective,
//Vampire dies from Medusa's glare.
******************************************************************************/
void playTourney::medusaVSvamp(Character *attacker, Vampire *vamp,
                               TourneyQueue *winTeam, TourneyQueue *loseTeam)
{
    int charmEffect = vamp->charm();   //Check whether Vampire's charm takes effect

    //If charm is effective
    if (charmEffect ==1)
    {
        cout << "No damage, Vampire strength remains at "
             << vamp->getStrength() << endl;
    }

    //Else if charm not effective, Vampire dies from Medusa glare
    else if (charmEffect == 2)
    {
        isDead = true;
        roundOver(vamp, loseTeam);
        recycleWinner(attacker, winTeam);
    }

    cout << endl;
}

/******************************************************************************
//Definition of playTourney::medusaVShp
//The function takes a pointer to Character as the attackers andHarryPotter as
//the defender, and pointers to the two team lineups. If Harry Potter has not
//already died, his Hogwarts power means strength is reset to 20 and the bool
//is set to true. Otherwise, if Harry Potter has already died once during the
//game, Medusa's glare kills Harry Potter.
******************************************************************************/
void playTourney::medusaVShp(Character *attacker, HarryPotter *hp,
                             TourneyQueue *winTeam, TourneyQueue *loseTeam)
{
    //If Harry Potter has not already died
    if (hp->getHPDeathCount() == false)
    {
        hp->setStrength(20);
        cout << "Harry Potter used his Hogwarts power to come back to life!"
             << endl << "His strength is now " << hp->getStrength()
             << "!" << endl << endl;

        hp->addHPDeath();
    }

    //Else if Harry Potter has already died
    else if (hp->getHPDeathCount() == true)
    {
        isDead = true;                    //Medusa turned opponent to stone
        roundOver(hp, loseTeam);          //Round is over, HP defeated
        recycleWinner(attacker, winTeam); //Winner moved to back of lineup
    }
}

/******************************************************************************
//Definition of playTourney::roundOver
//The function is passed a pointer to Character to get the name of the defeated
//player. It then prints a message and sets the isDead bool to true.
******************************************************************************/
void playTourney::roundOver(Character *loser, TourneyQueue *team)
{
    cout << "Oh no! " << loser->getName() << " died." << endl;
    cout << "Round over :-( " << endl << endl;

    //Set isDead to true
    isDead = true;

    cout << loser->getName() << " removed from the " << team->getLineupName()
         << " lineup and added to the list of defeated players" << endl;

    losers->addFront(loser);           //Add loser to head of losers queue
    team->removeFront();              //Remove loser from team queue
}

/******************************************************************************
//Definition of playTourney::recycleWinner
//The function is passed a pointer to Character (the winner) and a pointer to
//the winner's team lineup. Information about the winner is printed and the
//winner is removed from the front and added to the back of the team lineup.
//The recover function is called to recover a percentage of the winner's
//strength.
******************************************************************************/
void playTourney::recycleWinner(Character *winner, TourneyQueue *team)
{
    cout << winner->getName() << " won!" << endl;
    cout << winner->getName() << " moved to the end of the "
         << team->getLineupName() << " lineup and ";

    team->addBack(winner);             //Add winner to back of team queue
    team->removeFront();               //Remove winner from front of queue

    //Increment team score of winner
    team->setTeamScore(team->getTeamScore()+1);
    winner->recover();                 //Restore random percentage of strength
}

/******************************************************************************
//Definition of playTourney::tourneyOver
//The function prints the final scores and the winner of the tournament. The
//user is asked whether to view the contents of the queue of defeated players.
******************************************************************************/
void playTourney::tourneyOver()
{
    //Print final scores
    cout << "Tournament over! Final scores: " << endl;
    printScores();

    //Print winner
    if (team1->getTeamScore() > team2->getTeamScore())
    {
        cout << "Team 1 won!" << endl;

    }

    if (team2->getTeamScore() > team1->getTeamScore())
    {
        cout << "Team 2 won!" << endl;
    }

    if (team2->getTeamScore() == team1->getTeamScore())
    {
        cout << "The tourney was a tie!" << endl;
    }

    //Call menu function to ask if user wants to see contents of loser queue
    int show = tourneyMenu::viewLoserList();
    if (show == 1)
    {
        losers->printFighters("defeated players");
    }

}

/******************************************************************************
//Definition of playTourney::printScores
//The function prints the scores of both teams
******************************************************************************/
void playTourney::printScores()
{
    cout << team1->getLineupName() << " score: " << team1->getTeamScore() << endl;
    cout << team2->getLineupName() << " score: " << team2->getTeamScore() << endl;
}

/******************************************************************************
//Definition of playTourney::clearLineups
//The function removes all players from both teams
******************************************************************************/
void playTourney::clearLineups()
{
    while (team1->isEmpty() == false)
    {
        delete team1->getFront();
        team1->removeFront();
    }

    while (team2->isEmpty() == false)
    {
        delete team2->getFront();
        team2->removeFront();
    }

    while (losers->isEmpty() == false)
    {
        delete losers->getFront();
        losers->removeFront();
    }
}





