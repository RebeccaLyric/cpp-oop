/******************************************************************************
** Program name: Zoo Tycoon
** Author: Rebecca L. Taylor
** Date: 22 October 2017
** Description: This header file includes the member variables and functions
    of the Zoo class.
******************************************************************************/

#ifndef ZOO_HPP
#define ZOO_HPP

#include "Tiger.hpp"
#include "Penguin.hpp"
#include "Turtle.hpp"

class Zoo
{
private:
    int adultAge;           
    int animalTypes;
    int tigPosition;             
    int pengPosition;            
    int turtPosition;            

    Animal **zoo;

    //Size of animal arrays
    int tigerCapacity;
    int penguinCapacity;
    int turtleCapacity;

    //Number of each animal
    int numTigers;
    int numPenguins;
    int numTurtles;

    //Value of money in bank and bonus
    int bankMoney;
    int bonus;

public:
    //Constructor and destructor, resize array
    Zoo();
    ~Zoo();
    void resizeTigArr();
    void resizePengArr();
    void resizeTurtArr(); 

    //Buy and add animals
    void buyAnimalsStart();            //Buy animals at start of game
    void buyAnimalsEOD();              //Buy animals at end of day
    void buyTiger(int numIn);
    void buyPenguin(int numIn);
    void buyTurtle(int numIn);
    char selectBaby();
    void addBabyAnimal(char babyIn);

    //Daily operations
    void ageAnimals();
    void feedAnimals();
    void randomEvent();
    int randomAnimal();                //Select a random animal
    void animalSickness();
    void zooBoom();

    //Money functions
    void setBankMoney(int moneyIn);
    int getBankMoney();
    void calcProfit();

};

#endif //ZOO_HPP
