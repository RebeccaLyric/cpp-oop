/******************************************************************************
** Program name: Doubly-linked List
** Author: Rebecca L. Taylor
** Date: 5 November 2017
** Description: This implementation file defines the two constructors for the
    Node class.
******************************************************************************/

#include "Node.hpp"
#include <iostream>

/******************************************************************************
//Definition of Node::Node constructor with no parameters
//The constructor sets both the next and prev pointer values to NULL
******************************************************************************/
Node::Node()
{
    next = NULL;
    prev = NULL;
}

/******************************************************************************
//Definition of Node::Node constructor with one parameter
//The constructor sets the val variable to the int value passed in,
//and sets both the next and prev pointer values to NULL
******************************************************************************/
Node::Node(int val)
{
    this->val = val;
    next = NULL;
    prev = NULL;
}


