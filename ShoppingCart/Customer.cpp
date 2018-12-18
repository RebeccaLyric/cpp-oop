/*****************************************************************************
** Author: Rebecca L. Taylor
** Date: 8 June 2017
** Description: This implementation file defines the methods of the Customer
     class.
******************************************************************************/

#include "Customer.hpp"

/*****************************************************************************
 *                          Customer::Customer
 *    Constructor initializes three variables: name, account ID,
 *    and whether premium member
 *****************************************************************************/
Customer::Customer(std::string n, std::string a, bool pm)
{
   name = n;
   accountID = a;
   premiumMember = pm;
}

/*****************************************************************************
 *                    get methods for Customer class                         * 
 *****************************************************************************/
std::string Customer::getAccountID()
{
   return accountID;
}

std::vector<std::string> Customer::getCart()
{
   return cart;
}

/*****************************************************************************
 *                          Customer::addProductToCart
 *                   Adds product ID code to Customer's cart
 * ***************************************************************************/
void Customer::addProductToCart(std::string pid)
{
   cart.push_back(pid);
}

/*****************************************************************************
 *                          Customer::isPremiumMember
 *                Returns whether customer is premium member
 * ***************************************************************************/
bool Customer::isPremiumMember()
{
   return premiumMember;
}

/*****************************************************************************
 *                          Customer::emptyCart
 *                     Empties the customer's cart
 * ***************************************************************************/
void Customer::emptyCart()
{
   cart.clear();
} 
