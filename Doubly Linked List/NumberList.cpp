/******************************************************************************
** Program name: Doubly-linked List
** Author: Rebecca L. Taylor
** Date: 5 November 2017
** Description: This implementation file defines the member functions of the
    NumberList class. It includes functions to add nodes, remove nodes, print
    the list forwards and backwards, and print the value of the first and
    last nodes.
******************************************************************************/

#include "NumberList.hpp"

#include <iostream>
using std::cout;
using std::endl;

/******************************************************************************
//Definition of NumberList::NumberList constructor
//The constructor sets both the head and tail pointers to NULL
******************************************************************************/
NumberList::NumberList()
{
    head = NULL;
    tail = NULL;
}

/******************************************************************************
//Definition of NumberList::NumberList destructor
//The destructor frees the memory used by the list by progressing through
//and deleting each node
******************************************************************************/
NumberList::~NumberList()
{
    Node *temp = head;                 //Assign current head to temp

    while (temp != NULL)               //While temp is not NULL  
    {
        Node *current = temp->next;    //Assign temp's next to current
        delete temp;                   //Free memory of temp
        temp = current;                //Assign current node to temp
    }
}

/******************************************************************************
//Definition of NumberList::addNodeHead
//The function takes an integer parameter as the value to be added to the head
//of the list. It first creates a new node. If the list is empty, the new node
//is assigned to both head and tail of the list. If the list is not empty,
//the new node is inserted at the front of the list. The modified list is
//then printed.
******************************************************************************/
void NumberList::addNodeHead(const int &numIn)
{
    //Resources: Gaddis, 9th ed., p. 1045
    //faculty.cs.niu.edu/~mcmahon/CS241/Notes/doubly_linked.html
    
    cout << "Adding " << numIn << " to list head..." << endl;

    Node *newNode = new Node(numIn);   //Create new node to add to list

    //If list is empty
    if (head == NULL)
    {
        head = newNode;                //New node assigned to head
        tail = newNode;                //New node assigned to tail
    }

    //Else if list is not empty
    else
    {
        newNode->next = head;          //Assign current head to next
        head->prev = newNode;          //Current head's prev set to new node
        head = newNode;                //New node assigned to head
    }

    printList();                       //Print modified list
}

/******************************************************************************
//Definition of NumberList::addNodeTail
//The function takes an integer parameter as the value to be added to the tail
//of the list. It first creates a new node. If the list is empty, the new node
//is assigned to both head and tail of the list. If the list is not empty,
//the new node is inserted at the end of the list. The modified list is then
//printed.
******************************************************************************/
void NumberList::addNodeTail(const int &num)
{
    //Resources: Gaddis, 9th ed., p. 1045
    //faculty.cs.niu.edu/~mcmahon/CS241/Notes/doubly_linked.html
    
    cout << "Adding " << num << " to list tail..." << endl;

    Node *newNode = new Node(num);     //Create new node to add to list

    //If list is empty
    if (head == NULL)
    {
        head = newNode;                //Head set to new node
        tail = newNode;                //Tail set to new node
    }

    //Else if list is not empty
    else
    {
        newNode->prev = tail;          //Assign current tail to prev
        tail->next = newNode;          //Current tail's next set to new node
        tail = newNode;                //New node assigned to tail
    }

    printList();                       //Print modified list
}

/******************************************************************************
//Definition of NumberList::removeNodeHead
//If the list is not empty, the function creates a pointer to store the current
//head, assigns the next node as the head, and frees the memory of the former
//head node. The modified list is then printed.
******************************************************************************/
void NumberList::removeNodeHead()
{
    //Resources: Gaddis, 9th ed., p. 1045
    //faculty.cs.niu.edu/~mcmahon/CS241/Notes/doubly_linked.html
    
    //If list is empty
    if (head == NULL)
    {
        cout << "List is empty. Cannot remove node." << endl << endl;
    }

    //Else if list is not empty
    else
    {
        cout << "Removing first node of the list..." << endl;

        Node *firstNode = head;         //Node pointer to store current head
        head = firstNode->next;         //Assign current head node prev to head

        //If list contained only one node
        if (head == NULL)
        {
            tail = NULL;               //Assign NULL to tail
        }

        //Else if list contained more than one node
        else
        {
            head->prev = NULL;         //Assign NULL to head's prev pointer
        }

        delete firstNode;              //Free memory of previous head

        printList();                   //Print modified list
    }
}

/******************************************************************************
//Definition of NumberList::removeNodeTail
//If the list is not empty, the function creates a pointer to store the current
//tail, assigns the prev node as the tail, and frees the memory of the former
//tail node. The modified list is then printed.
******************************************************************************/
void NumberList::removeNodeTail()
{
    //Resources: Gaddis, 9th ed., p. 1045
    //faculty.cs.niu.edu/~mcmahon/CS241/Notes/doubly_linked.html
    
    //If list is empty
    if (tail == NULL)
    {
        cout << "List is empty. Cannot remove node." << endl << endl;
    }

    //Else if list is not empty
    else
    {
        cout << "Removing last node of the list..." << endl;
        
        Node *lastNode = tail;         //Node pointer to store current tail
        tail = lastNode->prev;         //Assign current last node prev to tail

        //If list contained only one node
        if (tail == NULL)
        {
            head = NULL;               //Assign NULL to head
        }

        //Else if list contains more than one node
        else
        {
            tail->next = NULL;         //Assign NULL to tail's next pointer
        }

        delete lastNode;               //Free memory of previous tail

        printList();                   //Print modified list
    }
}

/******************************************************************************
//Definition of NumberList::printList
//If the list is empty, the function prints a message to the user. Otherwise,
//the function begins at the head of the list and prints the value of each
//node. It stops printing when the next pointer is NULL.
******************************************************************************/
void NumberList::printList()
{
    //References: Gaddis, 9th ed., p. 1043
    //https://www.youtube.com/watch?v=YJRRpXYIdVQ
    
    cout << "Your linked list is: ";

    Node *current = head;              //Assign head to current node to print

    //If list is empty
    if (current == NULL)
    {
        cout << "empty" << endl;
    }

    //Else if list is not empty
    else
    {
        while (current != NULL)        //While current pointer is not NULL
        {
            cout << current->val << " ";
            current = current->next;   //Assign next node to current
        }
    }

    cout << endl << endl;
}

/******************************************************************************
//Definition of NumberList::printReverse
//If the list is empty, the function prints a message to the user. Otherwise,
//the function begins at the tail of the list and prints the value of each
//node. It stops printing when the prev pointer is NULL.
******************************************************************************/
void NumberList::printReverse()
{
    //References: Gaddis, 9th ed., p. 1043
    //https://www.youtube.com/watch?v=YJRRpXYIdVQ
    
    cout << "Here is the list in reverse: ";

    Node *current = tail;              //Assign tail to current node to print

    //If list is empty
    if (current == NULL)
    {
        cout << "List is empty." << endl;
    }

    //Else if list is not empty
    else
    {
        while (current != NULL)        //While current pointer is not NULL
        {
            cout << current->val << " ";
            current = current->prev;   //Assign prev node to current
        }
    }

    cout << endl << endl;
}

/******************************************************************************
//Definition of NumberList::printHead
//If the list is empty, the function prints a message to the user. Otherwise,
//the function prints the value of the node at the head of the list.
******************************************************************************/
void NumberList::printHead()
{
    //If list is empty
    if (head == NULL)
    {
        cout << "List is empty." << endl << endl;
    }

    //Else if list is not empty
    else
    {
        cout << "Value at head of list: " << head->val << endl << endl;
    }
}

/******************************************************************************
//Definition of NumberList::printTail
//If the list is empty, the function prints a message to the user. Otherwise,
//the function prints the value of the node at the tail of the list.
******************************************************************************/
void NumberList::printTail()
{
    //If list is empty
    if (tail == NULL)
    {
        cout << "List is empty." << endl << endl;
    }

    //Else if list is not empty
    else
    {
        cout << "Value at tail of list: " << tail->val << endl << endl;
    }
}


