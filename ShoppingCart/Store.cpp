/*****************************************************************************
** Author: Rebecca L. Taylor
** Date: 8 June 2017
** Description: This implementation file defines the methods of the Store
     class.
******************************************************************************/

#include "Store.hpp"
#include <iostream>
using std::cout;
using std::endl;

/*****************************************************************************
 *                          Store::addProduct
 *                 Adds a product to the inventory
 *****************************************************************************/
void Store::addProduct(Product* p)
{
  inventory.push_back(p); 
}

/*****************************************************************************
 *                          Store::addMember
 *                 Adds a customer to the members
 *****************************************************************************/
void Store::addMember(Customer* c)
{
  members.push_back(c); 
}

/*****************************************************************************
 *                      Store::getProductFromID
 *          Returns pointer to product with matching ID
 *          Returns NULL if no matching ID is found
 *****************************************************************************/
Product* Store::getProductFromID(std::string pIdIn)
{
   int size = inventory.size(); //variable to hold size of inventory vector

   for (int i = 0; i < size; i++)
     {
        if(pIdIn == inventory[i]->getIdCode()) //test for matching product ID
             return inventory[i];
     }

   return NULL;
}

/*****************************************************************************
 *                      Store::getMemberFromID
 *          Returns pointer to customer with matching ID
 *          Returns NULL if no matching ID is found
 * ***************************************************************************/
Customer* Store::getMemberFromID(std::string mIdIn)
{
   int size = members.size(); //variable to hold size of members vector

   for (int i = 0; i < size; i++)
     {
        if(mIdIn == members[i]->getAccountID()) //test for matching member ID
             return members[i];
     }

   return NULL;
}

/*****************************************************************************
 *                      Store::productSearch
 *    Prints title, ID code, price, and description for every product
 *    that contains the search string; 
 *    First letter of search made non-case sensitive
 *****************************************************************************/
void Store::productSearch(std::string str)
{
  
   for (int count = 0; count < inventory.size(); count++)
       {
          int place = count; //variable to hold vector position

          //string variable for lowercase product title
          std::string lowerTitle =  inventory[count]->getTitle();
          //string variable for lowercase product description
          std::string lowerDescription =  inventory[count]->getDescription();

          //Check if first letter of search is uppercase 
          if(isupper(str.at(0))) 
             //Convert search string to lowercase
             {
               for (int i = 0; i < str.length(); i++)
                     str[i] = tolower(str[i]);
             }
 
          //Check if first letter of search is lowercase
          if(islower(str.at(0))) 
             {
               //Convert title to lowercase
               for (int i = 0; i < lowerTitle.length(); i++)
                       lowerTitle[i] = tolower(lowerTitle[i]);
                    
               //Convert description to lowercase
               for (int i = 0; i < lowerDescription.length(); i++)
                       lowerDescription[i] = tolower(lowerDescription[i]);
                     
               //Check if search term matches lowercase title or description 
               if (lowerTitle.find(str) != std::string::npos ||
                   lowerDescription.find(str) != std::string::npos)
                      {
                        //If matches, print product info
                        cout << inventory[place]->getTitle() << endl; 
                        cout << "ID code: " << inventory[place]->getIdCode() 
                             << endl;
                        cout << "price: $" <<inventory[place]->getPrice() 
                             << endl;
                        cout << inventory[place]->getDescription() << endl;
                        cout << endl; 
                          }
            }
        }            
}

/*****************************************************************************
 *                      Store::addProductToMemberCart
 *  If product in inventory and member found, adds product to cart.
 *  If product and/or member not found, prints error message.   
 * ***************************************************************************/
void Store::addProductToMemberCart(std::string pID, std::string mID)
{
   //Check for product number
   if (getProductFromID(pID) == NULL)
      cout << "Product #" << pID << " not found." << endl;

   //Check for member number
   if (getMemberFromID(mID) == NULL)
      cout << "Member #" << mID << " not found." << endl;

   //Add to cart if product and member match and product in stock
   if (getProductFromID(pID) != NULL &&
       getMemberFromID(mID) != NULL &&
       getProductFromID(pID)->getQuantityAvailable() > 0)
      {
         getMemberFromID(mID)->addProductToCart(pID);
      }
   
   //Error message if product and member match but product not in stock 
   if (getProductFromID(pID) != NULL &&
       getMemberFromID(mID) != NULL &&
       getProductFromID(pID)->getQuantityAvailable() == 0)
      {
        cout << "Sorry, product #" << pID << " is currently out of stock."
             << endl;
      }
}

/*****************************************************************************
 *                      Store::checkOutMember
 *           Allows member to check out items in cart 
 * ***************************************************************************/
void Store::checkOutMember(std::string mID)
{
   //Error message if non-matching member ID
   if(getMemberFromID(mID) == NULL)
      cout << "Member #" << mID << " not found." << endl;

   //Execute check out if matching member ID
   if(getMemberFromID(mID) != NULL)
      {
        double subtotal = 0.0;  //accumulator variable for cart subtotal
        double shipping;  //variable for shipping cost
        double total;     //variable for total cost 

        //variable for member cart 
        std::vector<std::string> cart = getMemberFromID(mID)->getCart();

        //Check out each item in cart 
        for (int i=0; i < cart.size(); i++)
           {
             std::string pid = cart[i]; //variable for each cart item
             
             //Error message if product no longer available 
             if (getProductFromID(pid)->getQuantityAvailable() == 0)
                 {
                     cout << "Sorry, product #" << pid << ", "
                     << getProductFromID(pid)->getTitle() 
                     << ", is no longer available." << endl;
                 }

             //If product available, print product info, 
             //add price to subtotal, and decrement quantity by one
             else
                { 
                 //Print product title and price
                 cout << getProductFromID(pid)->getTitle() << " - $"
                      << getProductFromID(pid)->getPrice() << endl;

                 //Add price to subtotal
                 subtotal += getProductFromID(pid)->getPrice();

                 //Decrement quantity
                 getProductFromID(pid)->decreaseQuantity();
                }
           }

          //Calculate shipping
          if (getMemberFromID(mID)->isPremiumMember())
             shipping = 0.0;              //free shipping for members
          else
             shipping = .07 * subtotal;   //7% shipping for non-members

          //Calculate total cost
          total = subtotal + shipping;
          
          //Error message if cart empty 
          if (cart.size() == 0)
           cout << "There are no items in the cart." << endl;
          //If cart not empty, print subtotal, shipping, and cart total
          else
             {
               cout << "Subtotal: $" << subtotal << endl;
               cout << "Shipping Cost: $" << shipping << endl;
               cout << "Total: $" << total << endl;
             }

         //Empty cart after check out complete
         getMemberFromID(mID)->emptyCart();            
      } 
}

