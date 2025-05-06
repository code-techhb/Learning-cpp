/********************************************************************
 * BinaryNode Class
 *
 * This class defines the node structure for the Binary Search Tree.
 * Each node contains employee information and pointers to left and
 * right child nodes, forming the structure of the BST.
 *
 * The nodes are organized based on the Employee ID, allowing for
 * efficient search, insertion, and deletion operations in the tree.
 ********************************************************************/

#ifndef BINARY_NODE_H
#define BINARY_NODE_H

#include "EmployeeInfo.h"

class BinaryNode
{
private:
    EmployeeInfo data;
    BinaryNode *leftChild;  // smaller IDs
    BinaryNode *rightChild; // larger IDs

public:
    BinaryNode();

    // Parameterized constructor
    BinaryNode(const EmployeeInfo &emp);

    // Accessor functions
    EmployeeInfo getData() const;

    // return references to the nodes for modification
    BinaryNode *&getLeft();
    BinaryNode *&getRight();

    // for read only operations
    BinaryNode *getLeft() const;
    BinaryNode *getRight() const;

    // Mutator functions
    void setData(const EmployeeInfo &emp);
    void setLeft(BinaryNode *left);
    void setRight(BinaryNode *right);

    // Destructor
    ~BinaryNode();
};

#endif