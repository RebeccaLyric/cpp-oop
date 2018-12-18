/******************************************************************************
** Program name: Circular Linked List
** Author: Rebecca L. Taylor
** Date: 12 November 2017
** Description: This header file declares the Queue class along with its
    member variables and functions for working with a doubly-linked circular
    list.
******************************************************************************/

#ifndef QUEUE_HPP
#define QUEUE_HPP

class Queue
{
    private:
    struct QueueNode
    {
        QueueNode *next;               //pointer to next QueueNode object
        QueueNode *prev;               //pointer to previous QueueNode object
        int val;                       //integer value the QueueNode contains
    };

    QueueNode *head;                   //pointer to first QueueNode

    public:
    Queue();                           //Constructor
    ~Queue();                          //Destructor

    //Functions to work with the circular linked list
    bool isEmpty();
    void addBack(const int &numIn);
    int getFront();
    void removeFront();
    void printQueue();
};

#endif //QUEUE_HPP
