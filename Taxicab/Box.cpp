/***************************************************************************
** Name: Rebecca L. Taylor
** Date: 3 May 2017
** Description: This file contains the function definitions for the methods 
     in the Box class. They set the height, width, and length of a box, and
     calculate the volume and surface area. 
****************************************************************************/

#include "Box.hpp"

//Box::setHeight
void Box::setHeight(double h)
{  height = h;
}

//Box::setWidth
void Box::setWidth(double w)
{  width = w;
}

//Box::setLength
void Box::setLength(double l)
{  length = l;
}

/***************************************************************************
 *                            Box::Box                                     *
 *  Constructor with three parameters for height, width, and length        *
 **************************************************************************/
Box::Box(double h, double w, double l)
{   
   setHeight(h);
   setWidth(w);
   setLength(l);
}

/***************************************************************************
 *                            Box::Box                                     *
 *   Default Constructor initializing height, width, and length to 1.0     *
 **************************************************************************/
Box::Box()
{
   setHeight(1.0);
   setWidth(1.0);
   setLength(1.0);
}

/***************************************************************************
 *                            Box::calcVolume                              *
 *       This function calculates and returns the volume of a box.         *
 ***************************************************************************/
double Box::calcVolume()
{  return width * length * height;
}

/***************************************************************************
 *                            Box::calcSurfaceArea                         *
 *      This function calculates and returns the surface area of a box.    *
 ***************************************************************************/
double Box::calcSurfaceArea()
{  return (2 * height * width) + (2 * height * length) + (2 * width * length);
}

