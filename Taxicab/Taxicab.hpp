/*****************************************************************************
** Author: Rebecca L. Taylor
** Date: 3 May 2017
** Description: This header file declares the class Taxicab as well as its
     member variables and functions.
*****************************************************************************/

#ifndef TAXI_HPP
#define TAXI_HPP

//Taxicab class declaration
class Taxicab
{
   private:
      int x, y, distance;

   public:
     //Constructor with two parameters to initialize coordinates
     Taxicab(int, int);

     //Default constructor 
     Taxicab();

     //Get functions
     int getXCoord();
     int getYCoord();
     int getDistanceTraveled();

     //Move functions
     void moveX(int);
     void moveY(int);
     
 };
#endif 
   
    
