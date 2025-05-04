/**
 * LinkedList class - Implementation file
 * Implements the methods defined in LinkedList.h
*/

#include "LinkedList.h"
#include <vector>
#include <string>
#include <algorithm>
  

LinkedList::LinkedList() {
  headPtr = nullptr;
  numItems = 0;
}
  
// Copy constructor
LinkedList::LinkedList(const LinkedList& original) {
  headPtr = nullptr;
  numItems = 0;
      
  if (original.headPtr != nullptr) {
    std::vector<std::string> categories;
    std::vector<std::string> lines;
          
    Node* origPtr = original.headPtr;
    while (origPtr != nullptr) {
        categories.push_back(origPtr->getCategory());
        lines.push_back(origPtr->getLine());
        origPtr = origPtr->getNext();
    }
          
    for (int i = 0; i < categories.size(); i++) {
        add(categories[i], lines[i]);
    }
  }
}
  
// Destructor
LinkedList::~LinkedList() {
  // Delete all nodes in the list
  Node* nodeToDelete = headPtr;
  while (nodeToDelete != nullptr) {
    Node* nextNode = nodeToDelete->getNext();
    delete nodeToDelete;
    nodeToDelete = nextNode;
  }
}
  
// Accessor to get the number of items in the list
int LinkedList::getItemCount() const {
  return numItems;
}
  
// Add a node with category and line
void LinkedList::add(const std::string& category, const std::string& line) {
  Node* newNodePtr = new Node();
  newNodePtr->setCategory(category);
  newNodePtr->setLine(line);
  newNodePtr->setNext(nullptr);
      
  if (headPtr == nullptr) {
    headPtr = newNodePtr;
    numItems++;
    return;
  }
      
  Node* currentPtr = headPtr;
  Node* previousPtr = nullptr;
  bool categoryFound = false;
      
  while (currentPtr != nullptr && !categoryFound) {
    if (currentPtr->getCategory() == category) {
      categoryFound = true;
    } else {
      previousPtr = currentPtr;
      currentPtr = currentPtr->getNext();
    }
  }
      
  if (!categoryFound) {
    previousPtr->setNext(newNodePtr);
    numItems++;
    return;
  }
  Node* categoryStart = currentPtr;
      
  while (currentPtr != nullptr && 
    currentPtr->getCategory() == category && 
    currentPtr->getLine() < line) {
    previousPtr = currentPtr;
    currentPtr = currentPtr->getNext();
  }
      
  if (previousPtr == nullptr) {
    newNodePtr->setNext(headPtr);
    headPtr = newNodePtr;
  } else {
    newNodePtr->setNext(currentPtr);
    previousPtr->setNext(newNodePtr);
  }
      
  numItems++;
}
  
// Returns vector with the contents of the list
std::vector<std::string> LinkedList::toVector() const {
  std::vector<std::string> result;
      
  if (headPtr == nullptr) {
    return result; 
  }
      
  Node* currentPtr = headPtr;
  std::string currentCategory = "";
      
  while (currentPtr != nullptr) {
    if (currentCategory != currentPtr->getCategory()) {
      currentCategory = currentPtr->getCategory();
      result.push_back(currentCategory);
    }   
    // Add the line (with indentation) to the vector
    result.push_back("              " + currentPtr->getLine());
          
    // Move to the next node
    currentPtr = currentPtr->getNext();
  }
      
  return result;
}