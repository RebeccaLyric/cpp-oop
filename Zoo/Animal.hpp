/******************************************************************************
** Program name: Zoo Tycoon
** Author: Rebecca L. Taylor
** Date: 22 October 2017
** Description: This header file declares the member variables and functions
    of the Animal class, which serves as a parent class to the Tiger, Penguin,
    and Turtle classes.
******************************************************************************/

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

class Animal
{
protected:
    int age;
    int cost;
    int numBabies;
    int foodCost;
    int payoff;

public:
    Animal();
    void setAge(int days);
    int getAge() const;
    void incrementAge();
    void setCost(int cost);
    int getCost() const;
    void setNumBabies(int numBabies);
    int getNumBabies() const;
    void setFoodCost(int foodCost);
    int getFoodCost() const;
    void setPayoff(int payoff);
    int getPayoff() const;
};

#endif //ANIMAL_HPP
