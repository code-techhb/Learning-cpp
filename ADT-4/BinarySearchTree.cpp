/********************************************************************
 * Implementation file for the BinarySearchTree class
 * Contains implementations of all member functions declared in the
 * BinarySearchTree.h header file.
 ********************************************************************/

#include <iostream>
#include "BinarySearchTree.h"
#include "BinaryNode.h"

/**
 * Default constructor: initializes an empty binary search tree
 */
BinarySearchTree::BinarySearchTree()
{
  root = nullptr;
}

/**
 * Destructor: Calls helper function to free all allocated memory
 */
BinarySearchTree::~BinarySearchTree()
{
  destroyTree(root);
}

/**
 * Destroys all nodes in the tree recursively
 * @param node - Reference to the current node to destroy
 */
void BinarySearchTree::destroyTree(BinaryNode *&node)
{
  if (node == nullptr)
  {
    return;
  }

  destroyTree(node->getLeft());
  destroyTree(node->getRight());

  delete node;
  node = nullptr;
}

/**
 * Public insert method
 * Calls the recursive helper to insert employee
 * @param emp - The employee information to insert
 */
void BinarySearchTree::insert(const EmployeeInfo &emp)
{
  insertHelper(root, emp);
}

/**
 * Private recursive helper for insertion
 * @param node - Reference to the current node in the traversal
 * @param emp - The employee information to insert
 */
void BinarySearchTree::insertHelper(BinaryNode *&node, const EmployeeInfo &emp)
{
  // Base case: found insertion point
  if (node == nullptr)
  {
    node = new BinaryNode(emp);
    return;
  }

  // Compare employee IDs to determine which subtree to insert into
  if (emp.getID() < node->getData().getID())
  {
    insertHelper(node->getLeft(), emp);
  }
  else if (emp.getID() > node->getData().getID())
  {
    insertHelper(node->getRight(), emp);
  }
  else
  {
    // update the information if ID already exists
    node->setData(emp);
  }
}

/**
 * Public method to search for an employee by ID
 * @param id - The employee ID to search for
 * @return Pointer to the employee info if found, nullptr otherwise
 */
EmployeeInfo *BinarySearchTree::search(int id) const
{
  BinaryNode *result = findNodeHelper(root, id);

  if (result == nullptr)
  {
    return nullptr;
  }
  else
  {
    EmployeeInfo *foundEmployee = new EmployeeInfo(result->getData());
    return foundEmployee;
  }
}

/**
 * Private helper to find a node by employee ID
 * @param node - The current node in the traversal
 * @param id - The employee ID to search for
 * @return Pointer to the node containing the ID, or nullptr if not found
 */
BinaryNode *BinarySearchTree::findNodeHelper(BinaryNode *node, int id) const
{
  // Base case: node is null or ID is found
  if (node == nullptr)
  {
    return nullptr;
  }

  // Compare IDs to determine which subtree to search
  if (id < node->getData().getID())
  {
    return findNodeHelper(node->getLeft(), id);
  }
  else if (id > node->getData().getID())
  {
    return findNodeHelper(node->getRight(), id);
  }
  else
  {
    return node;
  }
}

/**
 * Public method to remove an employee by ID
 * @param id - The employee ID to remove
 * @return true if the employee was found and removed, false otherwise
 */
bool BinarySearchTree::remove(int id)
{
  if (root == nullptr)
  {
    return false;
  }

  // Check if the employee exists before attempting removal
  if (findNodeHelper(root, id) == nullptr)
  {
    return false;
  }
  removeNodeHelper(root, id);
  return true;
}

/**
 * Private helper to recursively remove a node
 * @param node - Reference to the current node in the traversal
 * @param id - The employee ID to remove
 * @return Pointer to the replacement node after removal
 */
BinaryNode *BinarySearchTree::removeNodeHelper(BinaryNode *&node, int id)
{
  // Base case: node is null (ID not found)
  if (node == nullptr)
  {
    return nullptr;
  }

  // Determine which subtree to search based on ID comparison
  if (id < node->getData().getID())
  {
    node->setLeft(removeNodeHelper(node->getLeft(), id));
  }
  else if (id > node->getData().getID())
  {
    node->setRight(removeNodeHelper(node->getRight(), id));
  }
  else
  {
    // Case 1:  node with no children
    if (node->getLeft() == nullptr && node->getRight() == nullptr)
    {
      delete node;
      return nullptr;
    }

    // Case 2: node with only one child
    else if (node->getLeft() == nullptr)
    {
      BinaryNode *temp = node->getRight();
      delete node;
      return temp;
    }
    else if (node->getRight() == nullptr)
    {
      BinaryNode *temp = node->getLeft();
      delete node;
      return temp;
    }

    // Case 3: node with two children
    else
    {
      BinaryNode *successor = findMin(node->getRight());
      node->setData(successor->getData());
      node->setRight(removeNodeHelper(node->getRight(), successor->getData().getID()));
    }
  }
  return node;
}

/**
 * Finds the node with the minimum value in a subtree
 * @param node - The root of the subtree to search
 * @return Pointer to the node with the minimum value
 */
BinaryNode *BinarySearchTree::findMin(BinaryNode *node) const
{
  if (node == nullptr)
  {
    return nullptr;
  }

  // Base case: leftmost node
  if (node->getLeft() == nullptr)
  {
    return node;
  }

  // Recursively find the leftmost node which has the smallest ID
  return findMin(node->getLeft());
}

/**
 * Displays all employees in the tree in ascending order by ID
 */
void BinarySearchTree::displayInOrder() const
{
  if (isEmpty())
  {
    std::cout << "Tree is empty. Consider hiring new employees 🤓." << std::endl;
    return;
  }
  std::cout << "\n=== Employees (Sorted by ID) ===" << std::endl;
  std::cout << "ID\tName" << std::endl;
  std::cout << "------------------------" << std::endl;
  displayInOrderHelper(root);
  std::cout << std::endl;
}

/**
 * Private helper for in-order traversal display
 * @param node - The current node in the traversal
 */
void BinarySearchTree::displayInOrderHelper(BinaryNode *node) const
{
  // Base case: node is null
  if (node == nullptr)
  {
    return;
  }

  // Process left subtree first (smaller IDs)
  displayInOrderHelper(node->getLeft());

  std::cout << node->getData().getID() << "\t"
            << node->getData().getName() << std::endl;

  // Process right subtree last (larger IDs)
  displayInOrderHelper(node->getRight());
}

/**
 * Checks if the tree is empty
 * @return true if the tree is empty, false otherwise
 */
bool BinarySearchTree::isEmpty() const
{
  return (root == nullptr);
}