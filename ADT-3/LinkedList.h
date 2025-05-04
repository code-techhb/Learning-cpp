/**
 * Lab 3
 * LinkedList class - Header file
 * Defines a LinkedList that stores category/line pairs in specific order
*/

#ifndef LINKEDLIST_H
#define LINKEDLIST_H
 
#include <string>
#include <vector>
#include "Node.h"
 
class LinkedList {
private:
  Node* headPtr;  
  int numItems;  
 
public:
  LinkedList();
     
  // Copy constructor
  LinkedList(const LinkedList& original);
     
  // Destructor
  ~LinkedList();
     
  // Accessor to get the number of items in the list
  int getItemCount() const;
     
  /**
    * Add a node with category and line
    * Inserts node in the linked list with categories in order of first appearance
    * Lines within each category are in alphabetical (ascending) order
  */
  void add(const std::string& category, const std::string& line);
     
  /**
    * Returns vector with the contents of the list
    * Contains category/line pairs as strings
  */
  std::vector<std::string> toVector() const;
 };
 
#include "LinkedList.cpp"
#endif 