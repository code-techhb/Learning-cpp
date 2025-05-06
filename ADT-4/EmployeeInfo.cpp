/********************************************************************
 * Implementation file for the EmployeeInfo class
 * Contains implementations of all member functions declared in the
 * EmployeeInfo.h header file.
 ********************************************************************/

#include "EmployeeInfo.h"

/**
 * Default constructor: Initializes employee with default values
 */
EmployeeInfo::EmployeeInfo()
{
    employeeID = 0;
    employeeName = "";
}

/**
 * Parameterized constructor
 * Initializes employee with specified ID and name
 *
 * @param id - The employee's ID number
 * @param name - The employee's full name
 */
EmployeeInfo::EmployeeInfo(int id, const std::string &name)
{
    employeeID = id;
    employeeName = name;
}

/**
 * Returns the employee's ID number
 * @return The employee's ID as an integer
 */
int EmployeeInfo::getID() const
{
    return employeeID;
}

/**
 * Returns the employee's name
 * @return The employee's name as a string
 */
std::string EmployeeInfo::getName() const
{
    return employeeName;
}

/**
 * Sets the employee's ID number
 * @param id - The new ID number to assign
 */
void EmployeeInfo::setID(int id)
{
    employeeID = id;
}

/**
 * Sets the employee's name
 * @param name - The new name to assign
 */
void EmployeeInfo::setName(const std::string &name)
{
    employeeName = name;
}

/**
 * Less than operator
 * Compares based on employee ID for BST ordering
 * @param other - The EmployeeInfo object to compare with
 * @return true if this employee's ID is less than the other's
 */
bool EmployeeInfo::operator<(const EmployeeInfo &other) const
{
    return employeeID < other.employeeID;
}

/**
 * Greater than operator
 * Compares based on employee ID for BST ordering
 * @param other - The EmployeeInfo object to compare with
 * @return true if this employee's ID is greater than the other's
 */
bool EmployeeInfo::operator>(const EmployeeInfo &other) const
{
    return employeeID > other.employeeID;
}

/**
 * Equality operator
 * Compares based on employee ID for searching
 * @param other - The EmployeeInfo object to compare with
 * @return true if this employee's ID is equal to the other's
 */
bool EmployeeInfo::operator==(const EmployeeInfo &other) const
{
    return employeeID == other.employeeID;
}