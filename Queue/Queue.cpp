/******************************************************************************
** Program name: Circular Linked List
** Author: Rebecca L. Taylor
** Date: 12 November 2017
** Description: This implementation file defines the member functions of the
    Queue class. It includes functions to check if the queue is empty, add a
    value to the back of the queue, get the value at the front of the queue,
    remove the front node of the queue, and print the queue contents.
******************************************************************************/

#include "Queue.hpp"

#include <iostream>
using std::cout;
using std::endl;

/******************************************************************************
//Definition of Queue::Queue constructor (no parameters)
//The constructor sets the head pointer to NULL
******************************************************************************/
Queue::Queue()
{
    head = NULL;
}

/******************************************************************************
//Definition of Queue::Queue destructor
//The destructor frees the memory used by the list by progressing through
//and deleting each node after the head node. The head node is used to find
//the end of the queue and its memory freed last.
******************************************************************************/
Queue::~Queue()
{
    if (!isEmpty())
    {
        QueueNode *temp = head->next;           //Assign node after head to temp

        while (temp != head)                    //While temp is not head
        {
            QueueNode *current = temp->next;    //Assign temp's next to current
            delete temp;                        //Free memory of temp
            temp = current;                     //Assign current node to temp
        }

        delete head;                            //Free memory of head
    }
}

/******************************************************************************
//Definition of Queue::isEmpty
//The functions checks if the queue id empty by testing whether the head is
//NULL. The result is returned as a bool.
******************************************************************************/
bool Queue::isEmpty()
{
    return head == NULL;
}

/******************************************************************************
//Definition of Queue::addBack
//The function takes an integer parameter as the value to be added to the back
//of the queue. It first creates a new node and assigns its value as the number
//passed in. If the list is empty, the new node is assigned to the head and
//both the prev and next pointers point back to the head. If the list is not
//empty, the new node is inserted at the end of the list.
******************************************************************************/
void Queue::addBack(const int &numIn)
{
    //Create new node to add to list and assign value
    QueueNode *newNode = new QueueNode;
    newNode->val = numIn;

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
        QueueNode *last = head->prev;  //Assign head's prev to last

        //Add new node
        newNode->next = head;          //New node's next is head
        head->prev = newNode;          //Head's prev is set to new node
        newNode->prev = last;          //New node's prev is set to last
        last->next = newNode;          //last's next is set to new node
    }
}

/******************************************************************************
//Definition of Queue::getFront
//If the list is empty, the function returns -1 as an int. Otherwise,
//the function returns as an int the value of the node at the head of the list.
******************************************************************************/
int Queue::getFront()
{
    //If list is empty
    if (isEmpty())
    {
        return -1;
    }

    //Else if list is not empty
    else
    {
        return head->val;
    }
}

/******************************************************************************
//Definition of NumberList::removeFront
//If the queue is empty, the function prints a message. If the queue contained
//only one node, the head is set to NULL to empty the queue. Otherwise, a new
//node is created to temporarily store the information of the previous head
//and the previous head's pointers are disconnected. The new head's pointers
//are re-connected appropriately.
******************************************************************************/
void Queue::removeFront()
{
    //If list is empty
    if (isEmpty())
    {
        cout << "List is empty. Cannot remove node." << endl << endl;
    }

    //Else if list is not empty
    else
    {
        QueueNode *firstNode = head;   //QueueNode pointer to store current head
        head = firstNode->next;        //Assign current head node prev to head

        //If list contained only one node
        if (firstNode->next == firstNode)
        {
            head = NULL;               //Set head to NULL
        }

        //Else if list contained more than one node
        else
        {
            //Set head's prev to firstNode's prev
            head->prev = firstNode->prev;
            //Set firstNode's prev's next to head
            firstNode->prev->next = head;
        }

        delete firstNode;              //Free memory of previous head
    }
}

/******************************************************************************
//Definition of Queue::printQueue
//If the queue is empty, the function prints a message to the user. Otherwise,
//the function begins at the head of the queue and prints the value of each
//node. It stops printing when the next pointer is the head of the queue.
******************************************************************************/
void Queue::printQueue()
{
    cout << "Your queue is: ";

    //If list is empty
    if (isEmpty())
    {
        cout << "empty" << endl;
    }

    //Else if list is not empty
    else
    {
        QueueNode *current = head;          //Assign head to current node to print

        do
        {
            cout << current->val << " ";    //Print current value
            current = current->next;        //Assign next node to current
        }
        while (current != head);            //While current pointer is not head

    }

    cout << endl;
}


