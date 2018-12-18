/******************************************************************************
** Program name: Doubly-linked List
** Author: Rebecca L. Taylor
** Date: 5 November 2017
** Description: This header file declares the NumberList class along with its
    member variables and functions. Its two pointers to Node identify the
    start and end of the doubly-linked list.
******************************************************************************/

#ifndef NUMBERLIST_HPP
#define NUMBERLIST_HPP

#include "Node.hpp"

class NumberList
{
    private:
    Node *head;                       //pointer to first Node in linked list
    Node *tail;                       //pointer to last Node in linked list

    public:
    NumberList();                  //Constructor
    ~NumberList();                 //Destructor

    //Functions to work with the doubly-linked list
    void addNodeHead(const int &numIn);
    void addNodeTail(const int &numIn);
    void removeNodeHead();
    void removeNodeTail();
    void printList();
    void printReverse();
    void printHead();
    void printTail();
};

#endif //NUMBERLIST_HPP
