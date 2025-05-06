/********************************************************************
 * BinarySearchTree Class
 *
 * This class implements a binary search tree data structure for
 * storing and managing employee information. The tree is organized
 * based on employee ID numbers, facilitating search, insertion, and deletion operations.
 ********************************************************************/

#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include "BinaryNode.h"
#include <iostream>

class BinarySearchTree
{
private:
    BinaryNode *root;

    // Private helper methods for recursive operations
    /**
     * Helper function for insert operation
     * Recursively finds the appropriate location and inserts the employee
     * @param node - Reference to the current node in the traversal
     * @param emp - The employee information to insert
     */
    void insertHelper(BinaryNode *&node, const EmployeeInfo &emp);

    /**
     * Helper function for in order traversal
     * Recursively visits nodes in ascending order of employee ID
     * @param node - The current node in the traversal
     */
    void displayInOrderHelper(BinaryNode *node) const;

    /**
     * Helper function to find a node by employee ID
     * @param node - The current node in the traversal
     * @param id - The employee ID to search for
     * @return Pointer to the node containing the ID, or nullptr if not found
     */
    BinaryNode *findNodeHelper(BinaryNode *node, int id) const;

    /**
     * Helper function to remove a node by employee ID
     * @param node - Reference to the current node in the traversal
     * @param id - The employee ID to remove
     * @return Pointer to the replacement node after removal
     */
    BinaryNode *removeNodeHelper(BinaryNode *&node, int id);

    /**
     * Finds the node with the minimum value in a subtree
     * Used for successor selection when removing a node with two children
     * @param node - The root of the subtree to search
     * @return Pointer to the node with the minimum value
     */
    BinaryNode *findMin(BinaryNode *node) const;

    /**
     * Recursively destroys all nodes in the tree
     * Used by the destructor to free allocated memory
     * @param node - Reference to the current node to destroy
     */
    void destroyTree(BinaryNode *&node);

public:
    /**
     * Default constructor
     */
    BinarySearchTree();

    /**
     * Destructor: Frees all memory allocated for tree nodes
     */
    ~BinarySearchTree();

    /**
     * Inserts a new employee into the binary search tree
     * @param emp - The employee information to insert
     */
    void insert(const EmployeeInfo &emp);

    /**
     * Removes an employee from the tree by ID
     * @param id - The employee ID to remove
     * @return true if the employee was found and removed, false otherwise
     */
    bool remove(int id);

    /**
     * Searches for an employee by ID
     * @param id - The employee ID to search for
     * @return Pointer to the employee info if found, nullptr otherwise
     */
    EmployeeInfo *search(int id) const;

    /**
     * Displays all employees in the tree in ascending order by ID
     */
    void displayInOrder() const;

    /**
     * Checks if the tree is empty
     * @return true if the tree is empty, false otherwise
     */
    bool isEmpty() const;
};

#endif