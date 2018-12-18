/*****************************************************************************
** Author: Rebecca L. Taylor
** Date: 10 May 2017
** Description: This header file declares the class Snack as well as its
     member variables and functions.
*****************************************************************************/

#ifndef SNACK_HPP
#define SNACK_HPP

#include <string>

//Snack class declaration
class Snack
{
   private:
     std::string snackName;
     double snackPrice;
     int snackNumCalories;  

   public:
     //Constructor with three parameters to initialize snackName,  
     //snackPrice, and snackNumCalories
     Snack(std::string, double, int);

     //Default constructor 
     Snack();

     //Get functions
     std::string getName();
     double getPrice();
     int getNumCalories();

 };
#endif 
   
    
