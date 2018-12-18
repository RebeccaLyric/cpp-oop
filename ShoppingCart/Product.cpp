/*****************************************************************************
** Author: Rebecca L. Taylor
** Date: 8 June 2017
** Description: This implementation file defines the methods of the Product
     class.
******************************************************************************/

#include "Product.hpp"

/*****************************************************************************
 *                             Product::Product                              *
 *     Constructor to initialize five variables: idCode, title,              *
 *     description, price, and quantity available                            *
 ****************************************************************************/
Product::Product(std::string id, std::string t, std::string d, double p, int qa)
{
   idCode = id;
   title = t;
   description = d;
   price = p;
   quantityAvailable = qa;
}

/*****************************************************************************
 *                          Product::decreaseQuantity                        *
 *                   Decreases quantity available by one                     *
 ****************************************************************************/
void Product::decreaseQuantity()
{
   if(quantityAvailable > 0) //Check if quantity greater than zero 
      quantityAvailable--;   //so not decremented to negative number
}

/*****************************************************************************
 *                  get methods for Product class                            * 
 ****************************************************************************/
std::string Product::getIdCode()
{
   return idCode;
}

std::string Product::getTitle()
{
   return title;
}

std::string Product::getDescription()
{
   return description;
}

double Product::getPrice()
{
   return price;
}

int Product::getQuantityAvailable()
{
   return quantityAvailable;
}


