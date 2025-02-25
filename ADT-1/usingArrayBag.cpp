// Houlaymatou B. | @code_techhb
// Description: This program implements a bag data structure that stores unique integer 
// values and allows users to add, remove, display, and
// find the smallest and largest values through a menu-driven interface.

//📚: Data Abstraction & Problem Solving with C++: Walls and Mirrors 7th Edition
//-------------------------------- code --------------------------------------
#include <iostream>
#include <string>
#include "ArrayBag.h"
#include <limits>

using namespace std;

// Function prototypes
void displayMenu();
void processChoice(ArrayBag<int>& bag);
void addValue(ArrayBag<int>& bag);
void removeValue(ArrayBag<int>& bag);
void displayBag(const ArrayBag<int>& bag);

int main()
{
    // Array bag to hold integers
	ArrayBag<int> bag;
    
    // Initial values
    int initialValues[] = {1, 33, 6, 9, 2, 65, 4, 29, 5, 8, 39, 88, 7, 25, 51};
    //Adding initial values to the bag
    for (int i = 0; i < 15; i++)
    {	// Check for duplicates
        if (!bag.contains(initialValues[i])) 
            bag.add(initialValues[i]);
    }
    
    // User prompts
    cout << "\nWelcome to the Bag 🎒 Program!\n";

    bool shouldContinue = true;
    while (shouldContinue)
    {
        displayMenu();
        processChoice(bag);
        
        cout << "\nWould you like to continue? (1 for yes, 0 for no): ";
        cin >> shouldContinue;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    
    cout << "Thank you for using the Bag 🎒 Program!\n\n";
    return 0;
}

// /****************************************************************/
// /* Function:   DisplayMenu
// /* Inputs:     none
// /* Outputs:    none
// /* Purpose:    This function displays a menu to the user
// /****************************************************************/
void displayMenu()
{
    cout << "\nPlease choose from the following options:\n"
         << "1. Add a value\n"
         << "2. Remove a value\n"
         << "3. Display bag\n"
         << "4. Find smallest value\n"
         << "5. Find largest value\n"
         << "6. Quit\n"
         << "Enter your choice (1-6): ";
}

// /****************************************************************/
// /* Function:   Process
// /* Inputs:     the array bag
// /* Outputs:    none
// /* Purpose:    This function prompts the user for a their choice and process the choice to call the appropriate function.
// /****************************************************************/
void processChoice(ArrayBag<int>& bag)
{
    int choice;
    cin >> choice;
    while(choice <1 || choice >6){
        cout << "❌Invalid choice. Please try again using only numbers 1 through 6.\n\n";
        displayMenu();
        cin >> choice;
    }
    
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    try 
    {
        switch (choice)
        {
            case 1:
                addValue(bag);
                break;
            case 2:
                removeValue(bag);
                break;
            case 3:
                displayBag(bag);
                break;
            case 4:
                if (bag.isEmpty())
                    cout << "OOPS! The bag is empty. Please fill it with something 🥲!\n";
                else
                    cout << "Smallest value: " << bag.findSmallest() << endl;
                break;
            case 5:
                if (bag.isEmpty())
                    cout << "OOPS! The bag is empty. Please fill it with something 🥲!\n";
                else
                    cout << "Largest value: " << bag.findLargest() << endl;
                break;
            case 6:
                cout << "See you Soon!\n\n";
                exit(0);
        }
    }
    catch (const std::runtime_error& e)
    {
        cout << "🚨 OOPS! Error: " << e.what() << endl;
    }
}

// /****************************************************************/
// /* Function:   AddValue
// /* Inputs:     the array bag
// /* Outputs:    none
// /* Purpose:    This function asks a user to add a value in the array bag
// /****************************************************************/
void addValue(ArrayBag<int>& bag)
{
    int value;
    cout << "Enter the Number to add: ";
    cin >> value;
    
    if (bag.contains(value))
    {
        cout << "Value " << value << " already exists in the bag!\n";
    }
    else if (bag.add(value))
    {
        cout << "Number " << value << " added successfully!\n";
    }
    else
    {
        cout << "OOPS! The Bag is full. Cannot add more values. Remove some elements first.\n";
    }
}

// /****************************************************************/
// /* Function:   Remove
// /* Inputs:     the array bag
// /* Outputs:    none
// /* Purpose:    This function remove an element entered by the user from the array bag
// /****************************************************************/
void removeValue(ArrayBag<int>& bag)
{
    int value;
    cout << "Enter the value to remove: ";
    cin >> value;
    
    if (bag.remove(value))
    {
        cout << "Value " << value << " removed successfully!\n";
    }
    else
    {
        cout << "Value " << value << " not found in the bag!\n";
    }
}

// /****************************************************************/
// /* Function:   Display Bag
// /* Inputs:     the array bag
// /* Outputs:    none
// /* Purpose:    This function displays the content of the array bag
// /****************************************************************/
void displayBag(const ArrayBag<int>& bag)
{
    if (bag.isEmpty())
    {
        cout << "The bag is empty. Add some values!\n";
        return;
    }
    
    vector<int> bagItems = bag.toVector();
    cout << "Bag contents: ";
    for (int item : bagItems)
    {
        cout << item << " ";
    }
    cout << "\nNumber of items: " << bag.getCurrentSize() << endl;
}
