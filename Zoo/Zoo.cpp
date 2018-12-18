/******************************************************************************
** Program name: Zoo Tycoon
** Author: Rebecca L. Taylor
** Date: 22 October 2017
** Description: This implementation file defines the functions of the Zoo
    class. It includes use functions (constructor and destructor),
    functions to buy and add animals to the Zoo, functions to execute
    daily operations (e.g., select random event), and functions to
    calculate bank money and profit.
******************************************************************************/

#include "Zoo.hpp"
#include "getInteger.hpp"

#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>
#include <cstdlib>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::rand;

/******************************************************************************
//Definition of Zoo::Zoo constructor
//The constructor assigns values to class variables and allocates memory for 
//each animal type.
******************************************************************************/
Zoo::Zoo()
{
    adultAge = 3;           //Adults are 3 days old
    animalTypes = 3;        //3 types of animals in zoo
    tigPosition = 0;        //Tiger position in array is 0
    pengPosition = 1;       //Penguin position in array is 1
    turtPosition = 2;       //Turtle position in array is 2
    
    //Size of animal arrays
    tigerCapacity = 10;
    penguinCapacity = 10;
    turtleCapacity = 10;

    //Number of each animal
    numTigers = 0;
    numPenguins = 0;
    numTurtles = 0;

    //Value of money in bank and bonus
    bankMoney = 0;
    bonus = 0;

    //Double pointer zoo allocated dynamic memory for each animal type
    zoo = new Animal*[animalTypes];

    zoo[tigPosition] = new Tiger[tigerCapacity];
    zoo[pengPosition] = new Penguin[penguinCapacity];
    zoo[turtPosition] = new Turtle[turtleCapacity];
}

/******************************************************************************
//Definition of Zoo::~Zoo destructor
//The destructor deallocates the memory of the dynamic array for each type
//of animal.
******************************************************************************/
Zoo::~Zoo()
{
    //Free memory of each array of animal objects
    delete [] zoo[tigPosition];
    delete [] zoo[pengPosition];
    delete [] zoo[turtPosition];

    //Free memory of double zoo pointer
    delete [] zoo;
}

/******************************************************************************
//Definition of Zoo::resizeTigArr
//The function creates a temporary double pointer to Animal which double the
//Tiger capacity. Then the values for each animal are copied to temp, the
//memory of zoo is freed, and temp is copied to zoo.
******************************************************************************/
void Zoo::resizeTigArr()
{
    //Sources: https://www.whitman.edu/mathematics/c++_online/section04.03.html
    //https://www.youtube.com/watch?v=175wL-M7qio
   
    //Create tempory array to store values
    Animal **temp = new Animal *[animalTypes];

    temp[tigPosition] = new Tiger[tigerCapacity * 2];  //Tiger capacity doubled
    temp[pengPosition] = new Penguin[penguinCapacity];
    temp[turtPosition] = new Turtle[turtleCapacity];

    //Copy zoo at Tiger position values to temp
    for (int i = 0; i < tigerCapacity; i++)
    {
        temp[tigPosition][i] = zoo[tigPosition][i];
    }
                          
    //Copy zoo at Penguin position values to temp
    for (int i = 0; i < penguinCapacity; i++)
    {
        temp[pengPosition][i] = zoo[pengPosition][i];
    }                          

    //Copy zoo at Turtle position values to temp
    for (int i = 0; i < turtleCapacity; i++)
    {
        temp[turtPosition][i] = zoo[turtPosition][i];
    }                         

    //Double tiger array capacity
    tigerCapacity = tigerCapacity * 2;

    //Free memory of zoo
    delete [] zoo[tigPosition];
    delete [] zoo[pengPosition];
    delete [] zoo[turtPosition];

    delete [] zoo;

    //Copy temp to zoo
    zoo = temp;
}

/******************************************************************************
//Definition of Zoo::resizePengArr
//The function creates a temporary double pointer to Animal which double the
//Penguin capacity. Then the values for each animal are copied to temp, the
//memory of zoo is freed, and temp is copied to zoo.
******************************************************************************/
void Zoo::resizePengArr()
{
    //Sources: https://www.whitman.edu/mathematics/c++_online/section04.03.html
    //https://www.youtube.com/watch?v=175wL-M7qio
   
    //Create tempory array to store values
    Animal **temp = new Animal *[animalTypes];

    temp[tigPosition] = new Tiger[tigerCapacity];  
    temp[pengPosition] = new Penguin[penguinCapacity * 2]; //Double penguins 
    temp[turtPosition] = new Turtle[turtleCapacity];

    //Copy zoo at Tiger position values to temp
    for (int i = 0; i < tigerCapacity; i++)
    {
        temp[tigPosition][i] = zoo[tigPosition][i];
    }
                          
    //Copy zoo at Penguin position values to temp
    for (int i = 0; i < penguinCapacity; i++)
    {
        temp[pengPosition][i] = zoo[pengPosition][i];
    }                          

    //Copy zoo at Turtle position values to temp
    for (int i = 0; i < turtleCapacity; i++)
    {
        temp[turtPosition][i] = zoo[turtPosition][i];
    }                         

    //Double penguin array capacity
    penguinCapacity = penguinCapacity * 2;

    //Free memory of zoo
    delete [] zoo[tigPosition];
    delete [] zoo[pengPosition];
    delete [] zoo[turtPosition];

    delete [] zoo;

    //Copy temp to zoo
    zoo = temp;
}

/******************************************************************************
//Definition of Zoo::resizeTurtArr
//The function creates a temporary double pointer to Animal which double the
//Turtle capacity. Then the values for each animal are copied to temp, the
//memory of zoo is freed, and temp is copied to zoo.
******************************************************************************/
void Zoo::resizeTurtArr()
{
    //Sources: https://www.whitman.edu/mathematics/c++_online/section04.03.html
    //https://www.youtube.com/watch?v=175wL-M7qio
   
    //Create tempory array to store values
    Animal **temp = new Animal *[animalTypes];

    temp[tigPosition] = new Tiger[tigerCapacity];  
    temp[pengPosition] = new Penguin[penguinCapacity];
    temp[turtPosition] = new Turtle[turtleCapacity * 2]; //Turtle capacity doubled

    //Copy zoo at Tiger position values to temp
    for (int i = 0; i < tigerCapacity; i++)
    {
        temp[tigPosition][i] = zoo[tigPosition][i];
    }
                          
    //Copy zoo at Penguin position values to temp
    for (int i = 0; i < penguinCapacity; i++)
    {
        temp[pengPosition][i] = zoo[pengPosition][i];
    }                          

    //Copy zoo at Turtle position values to temp
    for (int i = 0; i < turtleCapacity; i++)
    {
        temp[turtPosition][i] = zoo[turtPosition][i];
    }                         

    //Double turtle array capacity
    turtleCapacity = turtleCapacity * 2;

    //Free memory of zoo
    delete [] zoo[tigPosition];
    delete [] zoo[pengPosition];
    delete [] zoo[turtPosition];

    delete [] zoo;

    //Copy temp to zoo
    zoo = temp;
}

/******************************************************************************
//Definition of Zoo::buyAnimalsStart
//The function is executed at the start of the program to buy either one or
//two of each animal at the beginning of the game.
******************************************************************************/
void Zoo::buyAnimalsStart()
{
    string input;        //Variables for user input
    int option;

    //Buy tigers to start the zoo
    //Ask user to buy 1 or 2 tigers
    cout << "You have $" << bankMoney << " left in the bank." << endl;
    cout << "Each tiger costs $" << zoo[tigPosition][0].getCost() << endl;

    cout << "Would you like to buy 1 or 2 tigers?" << endl;

    //Get and validate user input
    getline(cin, input);
    option = getInteger(input);

    //Check user choice is one of specified options
    while (option != 1 && option != 2)
    {
        cout << "Please enter '1' or '2'" << endl;
        getline(cin, input);
        option = getInteger(input);
    }

    //Pass number of tigers to buyTiger function
    buyTiger(option);

    //Buy penguins to start the zoo
    //Ask user to buy 1 or 2 penguins
    cout << "You have $" << bankMoney << " left in the bank." << endl;
    cout << "Each penguin costs $" << zoo[pengPosition][0].getCost() << endl;

    cout << "Would you like to buy 1 or 2 penguins?" << endl;

    //Get and validate user input
    getline(cin, input);
    option = getInteger(input);

    //Check user choice is one of specified options
    while (option != 1 && option != 2)
    {
        cout << "Please enter '1' or '2'" << endl;
        getline(cin, input);
        option = getInteger(input);
    }

    //Pass number of penguins to buyPenguin function
    buyPenguin(option);

    //Buy turtles to start the zoo
    //Ask user to buy 1 or 2 turtles
    cout << "You have $" << bankMoney << " left in the bank." << endl;
    cout << "Each turtle costs $" << zoo[turtPosition][0].getCost() << endl;

    cout << "Would you like to buy 1 or 2 turtles?" << endl;

    //Get and validate user input
    getline(cin, input);
    option = getInteger(input);

    //Check user choice is one of specified options
    while (option != 1 && option != 2)
    {
        cout << "Please enter '1' or '2'" << endl;
        getline(cin, input);
        option = getInteger(input);
    }

    //Pass number of turtles to buyTurtle function
    buyTurtle(option);
}

/******************************************************************************
//Definition of Zoo::buyAnimalsEOD (end of day)
//The function is executed at the end of each game day loop to allow the user
//buy one animal or no animals.
 ******************************************************************************/
void Zoo::buyAnimalsEOD()
{
    const int ANIMAL_NUM = 1;         //User can buy one animal at end of day
    string input;                     //Variable for user input

    //At end of day
    cout << "Would you like to buy an adult (3 day old) animal? Enter: " << endl;
    cout << "'1' for tiger ($10,000), " << endl;
    cout << "'2' for penguin ($1,000), " << endl;
    cout << "'3' for turtle ($100), or " << endl;
    cout << "'4' to start the next day without buying a new animal." << endl;
    cout << endl;

    getline(cin, input);
    int option = getInteger(input);

    while (option < 1 || option > 4)
    {
        cout << "Please enter a number between 1 and 4" << endl;
        getline(cin, input);
        option = getInteger(input);
    }

    //If user chooses to buy a tiger
    if (option == 1)
    {
        buyTiger(ANIMAL_NUM);
        zoo[tigPosition][numTigers-1].setAge(adultAge);
        cout << "Goodnight!" << endl;
    }

    //If user chooses to buy a penguin
    if (option == 2)
    {
        buyPenguin(ANIMAL_NUM);
        zoo[pengPosition][numPenguins-1].setAge(adultAge);
        cout << "Goodnight!" << endl;
    }

    //If user chooses to buy a turtle
    if (option == 3)
    {
        buyTurtle(ANIMAL_NUM);
        zoo[turtPosition][numTurtles-1].setAge(adultAge);
        cout << "Goodnight!" << endl;
    }

    //Else if user chooses not to buy an animal
    else if (option == 4)
    {
        cout << "Goodnight!" << endl;
    }
}

/******************************************************************************
//Definition of Tiger::buyTiger
//The function takes an int parameter indicating the number of tigers to buy.
//It checks if the array needs to be resized to hold additional tigers,
//then subtracts the cost of the tiger from the bank and increments the
//number of tigers.
******************************************************************************/
void Zoo::buyTiger(int numIn)
{
    //Resize array if necessary
    if ((numTigers + numIn) >= tigerCapacity)
    {
        resizeTigArr();
    }

    //For each tiger purchased
    for (int i = 0; i < numIn; i++)
    {
        //Subtract cost from bank and increment number of tigers
        bankMoney = bankMoney - (zoo[tigPosition][0].getCost());
        numTigers++;
    }

    cout << "Congratulations! You now have " << numTigers
         << " tiger(s)." << endl;
    cout << endl;
}

/******************************************************************************
//Definition of Zoo::buyPenguin
//The function takes an int parameter indicating the number of penguins to buy.
//It checks if the array needs to be resized to hold additional penguins,
//then subtracts the cost of the penguin from the bank and increments the
//number of penguins.
******************************************************************************/
void Zoo::buyPenguin(int numIn)
{
    //Resize array if necessary
    if ((numPenguins + numIn) >= penguinCapacity)
    {
        resizePengArr();
    }

    //For each penguin purchased
    for (int i = 0; i < numIn; i++)
    {
        //Subtract cost from bank and increment number of penguins
        bankMoney = bankMoney - (zoo[pengPosition][0].getCost());
        numPenguins++;
    }

    cout << "Congratulations! You now have " << numPenguins
         << " penguin(s)." << endl;
    cout << endl;
}

/******************************************************************************
//Definition of Zoo::buyTurtle
//The function takes an int parameter indicating the number of turtles to buy.
//It checks if the array needs to be resized to hold additional turtles,
//then subtracts the cost of the turtle from the bank and increments the
//number of turtles.
******************************************************************************/
void Zoo::buyTurtle(int numIn)
{
    //Resize array if necessary
    if ((numTurtles + numIn) >= turtleCapacity)
    {
        resizeTurtArr();
    }

    //For each turtle purchased
    for (int i = 0; i < numIn; i++)
    {
        //Subtract cost from bank and increment number of penguins
        bankMoney = bankMoney - (zoo[turtPosition][0].getCost());
        numTurtles++;
    }

    cout << "Congratulations! You now have " << numTurtles
         << " turtle(s)." << endl;
    cout << endl;
}

/******************************************************************************
//Definition of Zoo::selectBaby
//The function creates a vector to store the animals old enough to have
//babies. For each animal, every animal in the array is checked and if old
//enough a char representing that animal is added to the vector. An animal
//is selected at random from the vector to have babies. If no animal is old
//enough, the char 'n' is returned for none.
******************************************************************************/
char Zoo::selectBaby()
{
    std::vector<char> babies;   //Vector to store animals able to have babies
    char baby;                  //Variable to store selected baby animal

    //Check if tigers can have babies
    if (numTigers > 0)
    {
        //Check if tigers old enough (>= adult age)
        for (int i = 0; i < numTigers; i++)
        {
            if (zoo[tigPosition][i].getAge() >= adultAge)
            {
                //Add tiger to babies vector
                babies.push_back('t');
            }
        }
    }

    //Check if penguins can have babies
    if (numPenguins > 0)
    {
        //Check if penguins old enough (>= adult age)
        for (int i = 0; i < numPenguins; i++)
        {
            if (zoo[pengPosition][i].getAge() >= adultAge)
            {
                //Add penguins to babies vector
                babies.push_back('p');
            }
        }
    }

    //Check if turtles can have babies
    if (numTurtles > 0)
    {
        //Check if turtles old enough (>= adult age)
        for (int i = 0; i < numTurtles; i++)
        {
            if (zoo[turtPosition][i].getAge() >= adultAge)
            {
                //Add turtles to babies vector
                babies.push_back('r');
            }
        }
    }

    //If vector is empty (no eligible animals)
    if (babies.empty())
    {
        baby = 'n';        //'n' for no babies possible
    }

    //If eligible animals are in vector, choose one
    else
    {
        //Source: http://www.cplusplus.com/forum/beginner/35440/
        int babyIndex = rand() % babies.size();
        baby = babies[babyIndex];
    }

    //Return randomly selected animal to have babies
    return baby;
}

/******************************************************************************
//Definition of Zoo::addBabyAnimal
//The function takes a char parameter indicating which animal will have
//babies. A switch statement checks if the respective array needs to be
//resized to hold additional animals, then subtracts the cost of the animal
//from the bank and increments the number of the animal. If no babies are
//possible, it prints a message to the user.
******************************************************************************/
void Zoo::addBabyAnimal(char babyIn)
{
    //Add baby of selected animal
    switch (babyIn)
    {
        //If tiger babies
        case 't':
        {
            cout << "A tiger had " << zoo[tigPosition][0].getNumBabies()
                 << " baby!" << endl;

            //Resize array if necessary 
            if ((numTigers + zoo[tigPosition][0].getNumBabies() 
                 >= tigerCapacity))  
            {
                resizeTigArr();
            }

            //Add tiger to the zoo, age = 0
            for (int i = 0; i < zoo[tigPosition][0].getNumBabies(); i++)
            {
                numTigers++;
                zoo[tigPosition][numTigers + 1].setAge(0);
            }

            break;
        }

        //If penguin babies
        case 'p':
        {
            cout << "A penguin had " << zoo[pengPosition][0].getNumBabies()
                 << " babies!" << endl;

            //Resize array if necessary 
            if ((numPenguins + zoo[pengPosition][0].getNumBabies() 
                 >= penguinCapacity))
            {
                resizePengArr();
            }

            //Add penguins to the zoo, age = 0
            for (int i = 0; i < zoo[pengPosition][0].getNumBabies(); i++)
            {
                numPenguins++;
                zoo[pengPosition][numPenguins + 1].setAge(0);
            }

            break;
        }

        //If turtle babies
        case 'r':
        {
            cout << "A turtle had " << zoo[turtPosition][0].getNumBabies()
                 << " babies!" << endl;

            //Resize array if necessary 
            if ((numTurtles + zoo[turtPosition][0].getNumBabies() 
                 >= turtleCapacity))
            {
                resizeTurtArr();
            }

            //Add turtles to the zoo, age = 0
            for (int i = 0; i < zoo[turtPosition][0].getNumBabies(); i++)
            {
                numTurtles++;
                zoo[turtPosition][numTurtles + 1].setAge(0);
            }

            break;
        }

        //If no babies possible
        case 'n':
        {
            cout << "But no animals are old enough to have a baby." << endl;
            break;
        }
    }
}

/******************************************************************************
//Definition of Zoo::ageAnimals
//The function is called at the start of each day of the game play loop. For
//each animal, it calls the incrementAge() function of the parent Animal class
//to age the animal by one day. It also prints the age of each animal once
//incremented.
******************************************************************************/
void Zoo::ageAnimals()
{
    for (int i = 0; i < numTigers; i++)
    {
        zoo[tigPosition][i].incrementAge();
        cout << "Tiger " << (i+1) << " is "
             << (zoo[tigPosition][i].getAge()) << " day(s) old."
             << endl;
    }

    for (int i = 0; i < numPenguins; i++)
    {
        zoo[pengPosition][i].incrementAge();
        cout << "Penguin " << (i+1) << " is "
             << (zoo[pengPosition][i].getAge()) << " day(s) old."
             << endl;
    }

    for (int i = 0; i < numTurtles; i++)
    {
        zoo[turtPosition][i].incrementAge();
        cout << "Turtle " << (i+1) << " is "
             << (zoo[turtPosition][i].getAge()) << " day(s) old."
             << endl;
    }
}

/******************************************************************************
//Definition of Zoo::feedAnimals
//The function is called at the start of each day of the game play loop. For
//each animal, the cost of food is added to the respective food variable. It
//then prints a message indicating the total cost to feed each type of animal.
//Lastly, the food cost of each animal is subtracted from the bank and a
//message is printed with the amount of money left.
******************************************************************************/
void Zoo::feedAnimals()
{
    //Accumulators for food cost of each animal
    int tigerFood = 0;
    int penguinFood = 0;
    int turtleFood = 0;

    //Calculate tiger food cost
    for (int i = 0; i < numTigers; i++)
    {
        tigerFood += zoo[tigPosition][i].getFoodCost();
    }

    cout << "Your " << numTigers << " tiger(s) cost $"
         << tigerFood << " to feed." << endl;

    //Calculate penguin food cost
    for (int i = 0; i < numPenguins; i++)
    {
        penguinFood += zoo[pengPosition][i].getFoodCost();
    }

    cout << "Your " << numPenguins << " penguin(s) cost $"
         << penguinFood << " to feed." << endl;

    //Calculate turtle food cost
    for (int i = 0; i < numTurtles; i++)
    {
        turtleFood += zoo[turtPosition][i].getFoodCost();
    }

    cout << "Your " << numTurtles << " turtle(s) cost $"
         << turtleFood  << " to feed." << endl;

    //Subtract food cost from bank
    bankMoney = bankMoney - (tigerFood + penguinFood + turtleFood);

    cout << "You have $" << bankMoney
         << " left after feeding all the animals." << endl;
}

/******************************************************************************
//Definition of Zoo::randomEvent
//The function randomly selects one of four events to occur within each game
//day loop: an animal gets sick and dies, a boom in zoo attendance occurs,
//a baby animal is born, or nothing happens. It uses a switch statement to call
//the function(s) needed to execute the selected event.
******************************************************************************/
void Zoo::randomEvent()
{
    //First randomly select one of four events
    cout << "Today at the zoo: " ;
    int min = 1;
    int max = 4;
    int eventChoice = min + (rand() % (max - min + 1));

    switch(eventChoice)
    {
        //A sickness occurs to an animal in the zoo
        case 1:
        {
            cout << "Oh no! An animal may die due to " ;
            animalSickness();
            break;
        }

        //Boom in zoo attendance
        case 2:
        {
            cout << "There's been a boom in zoo attendance!" << endl;
            zooBoom();
            break;
        }

        //A baby animal is born
        case 3:
        {
            cout << "An animal might have babies today!" << endl;
            char babyChoice = selectBaby();
            addBabyAnimal(babyChoice);
            break;
        }

        //Nothing happens
        case 4:
        {
            cout << "Today passed without incident." << endl;
            break;
        }
    }
}

/******************************************************************************
//Definition of Zoo::randomAnimal
//The function selects and returns a random animal represented by the integers
//1 to 3.
******************************************************************************/
int Zoo::randomAnimal()
{
    int min = 1;
    int max = 3;
    int animalChoice = min + (rand() % (max - min + 1));

    return animalChoice;
}

/******************************************************************************
//Definition of Zoo::animalSickness
//The function chooses an animal at random to become ill. A switch statement
//with cases for each animal decrements the number of that animal and prints a
//message to the user. If the user has zero of that animal, nothing happens
//and a message is printed.
******************************************************************************/
void Zoo::animalSickness()
{
    //Select random animal
    int animalChoice = randomAnimal();

    switch (animalChoice)
    {
        //Tiger randomly selected for illness
        case 1:
        {
            cout << "illness in the tiger area." << endl;

            if (numTigers > 0)
            {
                //Decrement number of tigers and print message
                numTigers--;
                cout << "A tiger died. Now only " << numTigers 
                     << " tiger(s) are in the zoo." << endl;
            }

            else if (numTigers == 0)
            {
                //Tigers not decremented, print message
                cout << "You have zero tigers, so no tigers got sick." << endl;
            }

            break;
        }

        //Penguin randomly selected for illness
        case 2:
        {
            cout << "illness in the penguin area." << endl;

            if (numPenguins > 0)
            {
                //Decrement number of penguins and print message
                numPenguins--;
                cout << "A penguin died. Now only "
                     << numPenguins << " penguin(s) are in the zoo." << endl;
            }

            else if (numPenguins == 0)
            {
                //Penguins not decremented, print message
                cout << "You have zero penguins, so no penguins got sick." << endl;
            }

            break;
        }

        //Turtle randomly selected for illness
        case 3:
        {
            cout << "illness in the turtle area." << endl;

            if (numTurtles > 0)
            {
                //Decrement number of turtles and print message
                numTurtles--;
                cout << "A turtle died. Now only "
                     << numTurtles << " turtle(s) are in the zoo." << endl;
            }

            else if (numTurtles == 0)
            {
                //Turtles not decremented, print message
                cout << "You have zero turtles, so no turtles got sick." << endl;
            }

            break;
        }
    }
}

/******************************************************************************
//Definition of Zoo::zooBoom
//The function calculates a random bonus (from $250-$500) for each tiger in
//the zoo. The amount is added to the bonus member variable.
******************************************************************************/
void Zoo::zooBoom()
{
    //Ensure bonus is reset to zero
    bonus = 0;

    cout << "You get a bonus for each tiger in the zoo!" << endl;

    for (int i = 0; i < numTigers; i++)
    {
        //Select bonus amount
        int min = 250;
        int max = 500;
        int bonusAmt = min + (rand() % (max - min + 1));

        //Print bonus 
        cout << "Bonus for Tiger " << (i+1) << ": $" << bonusAmt << endl;

        //Add bonus
        bonus = bonus + bonusAmt;
    }

    //Print total bonus amount
    cout << "Total bonus: $" << bonus << endl;
}

/******************************************************************************
//Definition of Zoo::setBankMoney
//The function is called at the beginning of the program to set the amount of
//money in the bank, which it is passed as an int.
******************************************************************************/
void Zoo::setBankMoney(int moneyIn)
{
    bankMoney = moneyIn;
}

/******************************************************************************
//Definition of Zoo::getBankMoney
//The function returns the amount of money in the bank as an int.
******************************************************************************/
int Zoo::getBankMoney()
{
    return bankMoney;
}

/******************************************************************************
//Definition of Zoo::calcProfit
//The function calculates and prints the payoff of each animal and prints each
//amount. The total profit is added to the bank and printed before the bank
//total is printed.
******************************************************************************/
void Zoo::calcProfit()
{
    //Calculate payoff of each animal
    double tigerProfit = numTigers * zoo[tigPosition][0].getPayoff();
    double penguinProfit = numPenguins * zoo[pengPosition][0].getPayoff();
    double turtleProfit = numTurtles * zoo[turtPosition][0].getPayoff();

    //Print payoff of each animal
    cout << "Today's profit for " << numTigers << " tiger(s): $"
         <<  tigerProfit << endl;
    cout << "Today's profit for " << numPenguins << " penguin(s): $"
         << penguinProfit << endl;
    cout << "Today's profit for " << numTurtles << " turtle(s): $"
         << turtleProfit << endl;

    //Add profit to bank money
    bankMoney += tigerProfit + penguinProfit + turtleProfit;

    //Print daily total profit
    cout << "Today's total profit (including any bonus): $"
         << tigerProfit + penguinProfit + turtleProfit + bonus << endl;
    cout << endl;

    //Clear bonus
    bonus = 0;

    //Print amount of money in bank
    cout << "You now have $" <<  bankMoney << " in the bank." << endl;
}
