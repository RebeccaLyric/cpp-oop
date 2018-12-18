/******************************************************************************
** Program name: Doubly-linked List
** Author: Rebecca L. Taylor
** Date: 5 November 2017
** Description: This header file declares the Node class along with its member
    variables and functions. Nodes are linked together in the doubly-linked
    list.
******************************************************************************/

#ifndef NODE_HPP
#define NODE_HPP

class Node
{
    friend class NumberList;           //NumberList declared a friend
                                       //for access to private variables
    private:
        Node *next;                    //pointer to next Node object
        Node *prev;                    //pointer to previous Node object
        int val;                       //integer value the Node contains

    public:
        Node();                        //Node constructor
        Node(int val);                 //Node constructor passed val parameter
};

#endif //NODE_HPP
