/******************************************************************************
** Program name: Fantasy Combat Tournament
** Author: Rebecca L. Taylor
** Date: 19 November 2017
** Description: This header file declares the TourneyQueue class along with its
    member variables and functions for working with a doubly-linked circular
    list used to store player lineups.
******************************************************************************/

#ifndef TOURNEYQUEUE_HPP
#define TOURNEYQUEUE_HPP

#include "Character.hpp"

#include <string>

class TourneyQueue
{
    friend class tourneyMenu;

private:
    struct fighterNode
    {
        fighterNode *next;             //pointer to next fighterNode object
        fighterNode *prev;             //pointer to previous fighterNode object
        Character *fighter;            //integer value the fighterNode contains
    };

    fighterNode *head;                 //pointer to first fighterNode
    string lineupName;
    int teamScore;

public:
    TourneyQueue();                        //Constructor
    TourneyQueue(const string &teamName);  //Constructor with string parameter
    ~TourneyQueue();                       //Destructor

    std::string getLineupName() const;
    void setLineupName(const string &name);
    int getTeamScore() const;
    void setTeamScore(const int &teamScore);

    //Functions to work with the circular linked list
    bool isEmpty();
    void addBack(Character *fighterIn);
    void addFront(Character *fighterIn);
    Character* getFront();
    void removeFront();
    void printFighters(const string &lineup);
};

#endif //TOURNEYQUEUE_HPP
