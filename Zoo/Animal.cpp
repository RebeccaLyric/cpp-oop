/******************************************************************************
** Program name: Zoo Tycoon
** Author: Rebecca L. Taylor
** Date: 22 October 2017
** Description: This implementation file defines the functions of the Animal
    class, which serves as a parent class to the Tiger, Penguin, and Turtle
    classes.
******************************************************************************/

#include "Animal.hpp"

/******************************************************************************
//Definition of Animal::Animal constructor
//The function sets default values for all member variables.
******************************************************************************/
Animal::Animal()
{
    setAge(0);
    setCost(0);
    setNumBabies(0);
    setFoodCost(10);       //base food cost is $10
    setPayoff(0);
}

/******************************************************************************
//Definition of Animal::setAge
//The function takes a constant int parameter used to set the age of the
//animal.
******************************************************************************/
void Animal::setAge(int daysIn)
{
    age = daysIn;
}

/******************************************************************************
//Definition of Animal::getAge
//The function returns as an int the age in days of the animal.
******************************************************************************/
int Animal::getAge() const
{
    return age;
}

/******************************************************************************
//Definition of Animal::incrementAge
//The function increments the age of the animal by one day.
******************************************************************************/
void Animal::incrementAge()
{
    age++;
}

/******************************************************************************
//Definition of Animal::setCost
//The function takes an int parameter to set the cost of the animal.
******************************************************************************/
void Animal::setCost(int cost)
{
    this->cost = cost;
}

/******************************************************************************
//Definition of Animal::getCost
//The function returns as an int the cost of the animal.
******************************************************************************/
int Animal::getCost() const
{
    return cost;
}

/******************************************************************************
//Definition of Animal::setNumBabies
//The function takes an int parameter to set the number of babies of an animal.
******************************************************************************/
void Animal::setNumBabies(int numBabies)
{
    this->numBabies = numBabies;
}

/******************************************************************************
//Definition of Animal::getNumBabies
//The function returns as an int the number of babies an animal has.
******************************************************************************/
int Animal::getNumBabies() const
{
    return numBabies;
}

/******************************************************************************
//Definition of Animal::setFoodCost
//The function takes an int parameter to set the food cost of an animal.
******************************************************************************/
void Animal::setFoodCost(int food)
{
    foodCost = food;
}

/******************************************************************************
//Definition of Animal::getFoodCost
//The function returns as an int the cost of an animal's food.
******************************************************************************/
int Animal::getFoodCost() const
{
    return foodCost;
}

/******************************************************************************
//Definition of Animal::setPayoff
//The function takes an int parameter to set the food cost of an animal.
******************************************************************************/
void Animal::setPayoff(int payoff)
{
    this->payoff = payoff;
}

/******************************************************************************
//Definition of Animal::getPayoff
//The function returns as an int the individual payoff (profit) amount of
//each animal.
******************************************************************************/
int Animal::getPayoff() const
{
    return payoff;
}

