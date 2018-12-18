/******************************************************************************
** Program name: Fantasy Combat Tournament
** Author: Rebecca L. Taylor
** Date: 19 November 2017
** Description: This implementation file defines the member functions for
    working with a doubly-linked circular list used to store player lineups.
******************************************************************************/

#include "tourneyQueue.hpp"

#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

/******************************************************************************
//Definition of TourneyQueue::TourneyQueue constructor (no parameters)
//The constructor sets the head pointer to NULL, the lineup name to "lineup",
//and the team score to zero.
******************************************************************************/
TourneyQueue::TourneyQueue()
{
    head = NULL;
    lineupName = "lineup";
    teamScore = 0;
}

/******************************************************************************
//Definition of TourneyQueue::TourneyQueue constructor w/string parameter
//The constructor sets the head pointer to NULL, the lineup name to the
//passed-in parameter,
//and the team score to zero.
******************************************************************************/
TourneyQueue::TourneyQueue(const string &teamName)
{
    head = NULL;
    lineupName = teamName;
    teamScore = 0;
}

/******************************************************************************
//Definition of TourneyQueue::TourneyQueue destructor
//The destructor frees the memory used by the list by progressing through
//and deleting each node after the head node. The head node is used to find
//the end of the queue and its memory is freed last.
******************************************************************************/
TourneyQueue::~TourneyQueue()
{
    if (!isEmpty())
    {
        fighterNode *temp = head->next;         //Assign node after head to temp

        while (temp != head)                    //While temp is not head
        {
            fighterNode *current = temp->next;  //Assign temp's next to current
            delete temp;                        //Free memory of temp
            temp = current;                     //Assign current node to temp
        }

        delete head;                            //Free memory of head
    }
}

/******************************************************************************
//Definition of TourneyQueue::isEmpty
//The functions checks if the queue is empty by testing whether the head is
//NULL. The result is returned as a bool.
******************************************************************************/
bool TourneyQueue::isEmpty()
{
    return head == NULL;
}

/******************************************************************************
//Definition of TourneyQueue::addBack
//The function takes a pointer to Character parameter to be added to the back
//of the queue. It first creates a new node. If the list is empty, the new node
//is assigned to the head and both the prev and next pointers point back to
//the head. If the list is not empty, the new node is inserted at the end of
//the list.
******************************************************************************/
void TourneyQueue::addBack(Character *fighterIn)
{
    //Create new node to add to list and assign value
    fighterNode *newNode = new fighterNode;
    newNode->fighter = fighterIn;

    //If list is empty
    if (isEmpty())
    {
        head = newNode;                //Head set to new node
        head->next = newNode;          //Next and prev set to point to itself
        head->prev = newNode;
    }

    //Else if list is not empty
    else
    {
        fighterNode *last = head->prev; //Assign head's prev to last

        //Add new node
        newNode->next = head;          //New node's next is head
        head->prev = newNode;          //Head's prev is set to new node
        newNode->prev = last;          //New node's prev is set to last
        last->next = newNode;          //last's next is set to new node
    }

    //printFighters(lineupName);       //Print modified list to check
}

/******************************************************************************
//Definition of TourneyQueue::addFront
//The function
******************************************************************************/
void TourneyQueue::addFront(Character *fighterIn)
{
    //Reference: http://www.geeksforgeeks.org/
    //doubly-circular-linked-list-set-1-introduction-and-insertion/

    //Create new node to add to list and assign value
    fighterNode *newNode = new fighterNode;
    newNode->fighter = fighterIn;

    //If list is empty
    if (isEmpty())
    {
        head = newNode;                //Head set to new node
        head->next = newNode;          //Next and prev set to point to itself
        head->prev = newNode;
    }

    //Else if list is not empty
    else
    {
        fighterNode *last = head->prev; //Assign head's prev to last

        //Add new node
        newNode->next = head;          //New node's next is head
        newNode->prev = last;          //New node's prev is set to last
        last->next = head->prev = newNode;
        head = newNode;                //Head set to new node
    }

    //printFighters(lineupName);       //Print modified list to check
}

/******************************************************************************
//Definition of TourneyQueue::getFront
//If the list is empty, the function returns a NULL pointer to Character.
//Otherwise, the function returns a pointer to the Character at the head of
//the list.
******************************************************************************/
Character* TourneyQueue::getFront()
{
    //If list is empty
    if (isEmpty())
    {
        return NULL;
    }

    //Else if list is not empty
    else
    {
        return head->fighter;
    }
}

/******************************************************************************
//Definition of TourneyQueue::removeFront
//If the queue is empty, the function prints a message. If the queue contained
//only one node, the head is set to NULL to empty the queue. Otherwise, a new
//node is created to temporarily store the information of the previous head
//and the previous head's pointers are disconnected. The new head's pointers
//are re-connected appropriately.
******************************************************************************/
void TourneyQueue::removeFront()
{
    //If list is empty
    if (isEmpty())
    {
        cout << "List is empty. Cannot remove front." << endl << endl;
    }

    //Else if list is not empty
    else
    {
        fighterNode *firstNode = head;   //fighterNode pointer to store current head
        head = firstNode->next;          //Assign current head node prev to head

        //If list contained only one node
        if (firstNode->next == firstNode)
        {
            head = NULL;                 //Set head to NULL
        }

        //Else if list contained more than one node
        else
        {
            //Set head's prev to firstNode's prev
            head->prev = firstNode->prev;
            //Set firstNode's prev's next to head
            firstNode->prev->next = head;
        }

        delete firstNode;                //Free memory of previous head

        //printFighters(lineupName);     //Print modified list to check
    }
}

/******************************************************************************
//Definition of TourneyQueue::printFighters
//If the queue is empty, the function prints a message to the user. Otherwise,
//the function begins at the head of the queue and prints the fighter's name
//at each node. It stops printing when the next pointer is the head of the
//queue.
******************************************************************************/
void TourneyQueue::printFighters(const string &lineup)
{
    cout << "Here are the players on the " << lineup << " list: ";

    //If list is empty
    if (isEmpty())
    {
        cout << "empty" << endl;
    }

    //Else if list is not empty
    else
    {
        fighterNode *current = head;         //Assign head to current node to print

        do
        {
            cout << current->fighter->getName() << " ";
            current = current->next;        //Assign next node to current
        }
        while (current != head);            //While current pointer is not head

    }

    cout << endl << endl;
}

/******************************************************************************
//Definition of TourneyQueue::getLineupName
//The function returns as a string the team's name.
******************************************************************************/
string TourneyQueue::getLineupName() const
{
    return lineupName;
}

/******************************************************************************
//Definition of TourneyQueue::setLineupName
//The function takes a string parameter to set the team name.
******************************************************************************/
void TourneyQueue::setLineupName(const string &name)
{
    lineupName = name;
}

/******************************************************************************
//Definition of TourneyQueue::getTeamScore
//The function returns as an int the team score.
******************************************************************************/
int TourneyQueue::getTeamScore() const
{
    return teamScore;
}

/******************************************************************************
//Definition of TourneyQueue::setTeamScore
//The function accepts an int parameter to set the team's score.
******************************************************************************/
void TourneyQueue::setTeamScore(const int &teamScore)
{
    this->teamScore = teamScore;
}












