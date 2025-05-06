/********************************************************************
 * Houlaymatou B. | code_techhb
 * Lab 4: Binary Search Tree Implementation
 * This program implements a binary search tree to manage employee records.
 * It allows users to search for employees by ID, display all employees,
 * add new employees, and remove existing employees.
 *
 * The program initializes the tree with a set of employee records and
 * presents a menu-driven interface for user interaction.
 *******************************************************************
 */

#include <iostream>
#include <string>
#include <limits>
#include "BinarySearchTree.h"

// ---------------- Function prototypes ---------------------
void displayMenu();
void searchEmployee(BinarySearchTree &bst);
void addEmployee(BinarySearchTree &bst);
void removeEmployee(BinarySearchTree &bst);

// ---------------- main ---------------------
int main()
{
  BinarySearchTree employeeTree;

  // Initialize the tree with employee data 💜🤫😄
  employeeTree.insert(EmployeeInfo(1036, "Violetta Castillo"));
  employeeTree.insert(EmployeeInfo(1255, "Leon Vargas"));
  employeeTree.insert(EmployeeInfo(1071, "Ludmila Ferro"));
  employeeTree.insert(EmployeeInfo(2390, "Diego Hernandez"));
  employeeTree.insert(EmployeeInfo(1558, "Francesca Caviglia"));
  employeeTree.insert(EmployeeInfo(7406, "Camila Torres"));
  employeeTree.insert(EmployeeInfo(2162, "Federico Paccini"));
  employeeTree.insert(EmployeeInfo(3004, "Maxi Ponte"));
  employeeTree.insert(EmployeeInfo(4922, "Angie Carrara"));
  employeeTree.insert(EmployeeInfo(8483, "German Castillo"));

  // Menu
  int choice = 0;
  bool running = true;

  std::cout << "\n 🪪 Employee Management System " << std::endl;
  std::cout << "---------------------------------"
            << std::endl;

  while (running)
  {
    displayMenu();

    // user choice
    std::cin >> choice;

    // Clear input buffer
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    // Process user choice
    switch (choice)
    {
    case 1:
      searchEmployee(employeeTree);
      break;
    case 2:
      employeeTree.displayInOrder();
      break;
    case 3:
      addEmployee(employeeTree);
      break;
    case 4:
      removeEmployee(employeeTree);
      break;
    case 5:
      running = false;
      std::cout << "👋🏾 Exiting program. Byee!\n"
                << std::endl;
      break;
    default:
      std::cout << "🚨 Invalid option. Please try again using only 1 through 5." << std::endl;
    }
  }
  return 0;
}

// ------------------- Function definitions -------------------------------
void displayMenu()
{
  std::cout << "\nPlease select an option:" << std::endl;
  std::cout << "1. Search for an employee by ID" << std::endl;
  std::cout << "2. Display all employees" << std::endl;
  std::cout << "3. Add a new employee" << std::endl;
  std::cout << "4. Remove an employee" << std::endl;
  std::cout << "5. Exit" << std::endl;
  std::cout << "Enter your choice (1-5): ";
}

/**
 * Searches for an employee by ID
 * @param bst - Reference to the binary search tree
 */
void searchEmployee(BinarySearchTree &bst)
{
  int id;

  std::cout << "\nEnter Employee ID to search 🤓: ";
  std::cin >> id;
  std::cin.clear();
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

  EmployeeInfo *result = bst.search(id);

  // Display result
  if (result != nullptr)
  {
    std::cout << "🎉 Employee found!" << std::endl;
    std::cout << "ID: " << result->getID() << std::endl;
    std::cout << "Name: " << result->getName() << std::endl
              << std::endl;
    // Free the memory allocated by the search method
    delete result;
  }
  else
  {
    std::cout << "\n😔 Employee with ID " << id << " not found." << std::endl;
  }
}

/**
 * Adds a new employee to the tree
 * @param bst - Reference to the binary search tree
 */
void addEmployee(BinarySearchTree &bst)
{
  int id;
  std::string name;

  // Get employee details
  std::cout << "\nEnter new Employee ID 🤓: ";
  std::cin >> id;

  // Validate input
  if (std::cin.fail())
  {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "\nInvalid ID. Please enter a numeric value 😰." << std::endl;
    return;
  }
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

  std::cout << "Enter Employee Name 🤓: ";
  std::getline(std::cin, name);

  // Check if employee already exists
  EmployeeInfo *existing = bst.search(id);
  if (existing != nullptr)
  {
    std::cout << "\nAn employee with ID " << id << " already exists 😊." << std::endl;
    std::cout << "Would you like to update this employee? (y/n): ";

    char choice;
    std::cin >> choice;
    // Free memory allocated by search
    delete existing;

    if (choice != 'y' && choice != 'Y')
    {
      std::cout << "Employee not added or updated.\n"
                << std::endl;
      return;
    }
  }
  // Create and insert the new employee
  EmployeeInfo newEmployee(id, name);
  bst.insert(newEmployee);

  std::cout << "\n🎉 Employee added successfully!" << std::endl;
}

/**
 * Removes an employee from the tree
 * @param bst - Reference to the binary search tree
 */
void removeEmployee(BinarySearchTree &bst)
{
  int id;

  std::cout << "\nEnter Employee ID to remove: ";
  std::cin >> id;

  // Validate input
  if (std::cin.fail())
  {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "\nInvalid ID. Please enter a numeric value." << std::endl;
    return;
  }
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

  // Check if employee exists
  EmployeeInfo *existing = bst.search(id);
  if (existing == nullptr)
  {
    std::cout << "\nEmployee with ID " << id << " not found 😔." << std::endl;
    return;
  }
  // Free memory allocated by search
  delete existing;

  // Confirm removal
  std::cout << "⚠️ Are you sure you want to remove this employee? (y/n): ";

  char choice;
  std::cin >> choice;

  if (choice == 'y' || choice == 'Y')
  {
    // Remove the employee
    bool removed = bst.remove(id);

    if (removed)
    {
      std::cout << "\nEmployee removed successfully 😌!" << std::endl;
    }
    else
    {
      std::cout << "\nFailed to remove employee. Try again later 😔" << std::endl;
    }
  }
  else
  {
    std::cout << "\nRemoval cancelled 😊." << std::endl;
  }
}

// ------------------------------------------
// Ideas for future enhancements 💡:
// 1. Add options to update employee name or ID.
// 2. Implement sorting functionality by employee name.
// 3. Enable reading employee data from a file.
// 4. Store updated employee data back into the file.