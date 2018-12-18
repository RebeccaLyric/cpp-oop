/*****************************************************************************
** Author: Rebecca L. Taylor 
** Date: 3 May 2017
** Description: This file contains the function definitions for the methods
     of the Taxicab class. They get coordinates, move the Taxicab along
     x- and y-axes, and get the distance the Taxicab has traveled.
*****************************************************************************/

#include <cmath>
#include "Taxicab.hpp"

//Taxicab::getXCoord to get x coordinate
int Taxicab::getXCoord()
{
   return x;
}

//Taxicab::getYCoord to get Y coordinate
int Taxicab::getYCoord()
{
   return y;
}

//Taxicab::getDistanceTraveled returns the total distance 
int Taxicab::getDistanceTraveled()
{
   return distance; 
}

/****************************************************************************
 *                         Taxicab::Taxicab                                 *
 *      Constructor with two parameters to initialize coordinates           *
 ***************************************************************************/           
Taxicab::Taxicab(int x1, int y1)
{
  x = x1;
  y = y1;
  distance = 0;   
}

/****************************************************************************
 *                         Taxicab::Taxicab                                 *
 *      Default Constructor initializing coordinates to (0,0)               *
 ***************************************************************************/           
Taxicab::Taxicab()
{
  x = 0;
  y = 0;
  distance = 0; 
}

/****************************************************************************
 *                         Taxicab::moveX                                   *
 *   This function moves the Taxicab left or right along the x axis         *
 *   and adds the distance moved to the distance total.                     *
 ***************************************************************************/           
void Taxicab::moveX(int dx)
{
  x += dx;
  distance += std::abs(dx); 
}

/****************************************************************************
 *                         Taxicab::moveY                                   *
 *   This function moves the Taxicab up or down along the y axis            *
 *   and adds the distance moved to the distance total.                     *
 ***************************************************************************/           
void Taxicab::moveY(int dy)
{
  y += dy;
  distance += std::abs(dy);
}


