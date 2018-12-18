/******************************************************************************
** Program name: Path to Principal: A Ballet Game
** Author: Rebecca L. Taylor
** Date: 5 December 2017
** Description: This header file declares the member variables and functions
    of the DanceSpace class, a derived class of Space and the parent class of
    PracticeStudio and Stage.
******************************************************************************/

#ifndef DANCESPACE_HPP
#define DANCESPACE_HPP

#include "Space.hpp"

class DanceSpace : public Space
{
protected:
    string item;                       //Dance bag item earned from space
    int exertion;                      //Energy loss per attempted step
    int minComplete;                   //Steps required to complete the space

public:
    DanceSpace();
    int outcome() override;
    virtual void printSpaceInfo(const char &option) = 0;

    //Getter and setter functions
    void setItem(const string &item);
    string getItem() const;
    int getExertion() const;
    int getMinComplete() const;

};

#endif //DANCESPACE_HPP
