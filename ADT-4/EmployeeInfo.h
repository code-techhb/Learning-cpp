/********************************************************************
 * EmployeeInfo Class
 *
 * This class defines the employee information structure containing
 * an ID number and a name for each employee. This class is used
 * as the data component in the Binary Search Tree nodes.
 *
 * Comparison operators are implemented to enable sorting and searching
 * based on the employee ID in the Binary Search Tree.
 ********************************************************************/

#ifndef EMPLOYEE_INFO_H
#define EMPLOYEE_INFO_H

#include <string>

class EmployeeInfo
{
private:
    int employeeID;
    std::string employeeName;

public:
    EmployeeInfo();

    // Parameterized constructor
    EmployeeInfo(int id, const std::string &name);

    // Accessor functions
    int getID() const;
    std::string getName() const;

    // Mutator functions
    void setID(int id);
    void setName(const std::string &name);

    // Comparison operators needed for BST operations
    bool operator<(const EmployeeInfo &other) const;
    bool operator>(const EmployeeInfo &other) const;
    bool operator==(const EmployeeInfo &other) const;
};

#endif