/******************************************************************************
** Author: Rebecca L. Taylor
** Date: 3 May 2017
** Description: This header file defines the class Box as well as its
     member variables and functions.
******************************************************************************/

#ifndef BOX_HPP
#define BOX_HPP

//Box class declaration
class Box
{
   private:
     double height;
     double width;
     double length;

   public:
     //Set functions
     void setHeight(double);
     void setWidth(double);
     void setLength(double);

     //Constructor with three parameters
     Box(double, double, double);

     //Default constructor
     Box();

     //Calculation functions
     double calcVolume();
     double calcSurfaceArea();

 };
#endif 
   
    
