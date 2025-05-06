/********************************************************************
 * Implementation file for the BinaryNode class
 * Contains implementations of all member functions declared in the
 * BinaryNode.h header file.
 ********************************************************************/

#include "BinaryNode.h"

/**
 * Default constructor
 * Initializes node with default values and null child pointers
 */
BinaryNode::BinaryNode()
{
    data = EmployeeInfo();
    leftChild = nullptr;
    rightChild = nullptr;
}

/**
 * Parameterized constructor
 * Initializes node with specified employee data and null child pointers
 * @param emp - The EmployeeInfo object to store in this node
 */
BinaryNode::BinaryNode(const EmployeeInfo &emp)
{
    data = emp;
    leftChild = nullptr;
    rightChild = nullptr;
}

/**
 * Returns the employee information stored in this node
 * @return The EmployeeInfo object in this node
 */
EmployeeInfo BinaryNode::getData() const
{
    return data;
}

/**
 * Returns a reference to the left child pointer of this node
 * @return Reference to the left child pointer
 */
BinaryNode *&BinaryNode::getLeft()
{
    return leftChild;
}

/**
 * Returns a reference to the right child pointer of this node
 * @return Reference to the right child pointer
 */
BinaryNode *&BinaryNode::getRight()
{
    return rightChild;
}

/**
 * Returns the pointer to the left child of this node
 * @return Pointer to the left child BinaryNode
 */
BinaryNode *BinaryNode::getLeft() const
{
    return leftChild;
}

/**
 * Returns the pointer to the right child of this node
 * @return Pointer to the right child BinaryNode
 */
BinaryNode *BinaryNode::getRight() const
{
    return rightChild;
}

/**
 * Sets the employee information for this node
 * @param emp - The EmployeeInfo object to store in this node
 */
void BinaryNode::setData(const EmployeeInfo &emp)
{
    data = emp;
}

/**
 * Sets the left child pointer of this node
 * @param left - Pointer to the BinaryNode to set as left child
 */
void BinaryNode::setLeft(BinaryNode *left)
{
    leftChild = left;
}

/**
 * Sets the right child pointer of this node
 * @param right - Pointer to the BinaryNode to set as right child
 */
void BinaryNode::setRight(BinaryNode *right)
{
    rightChild = right;
}

/**
 * Destructor
 The BinarySearchTree class is responsible for proper memory management of all nodes in the tree.
 */
BinaryNode::~BinaryNode()
{
}