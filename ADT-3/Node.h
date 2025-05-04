/**
 * Node class - Header file
 * Defines a Node for a linked list that stores category and line information
*/

#ifndef NODE_H
#define NODE_H
 
#include <string>
 
class Node {
private:
  std::string category;  
  std::string line;     
  Node* next;
 
public:
  Node();
 
  // Destructor
  ~Node();
 
  // Accessor for category
  std::string getCategory() const;
 
  // Mutator for category
  void setCategory(const std::string& newCategory);
 
  // Accessor for line
  std::string getLine() const;
 
  // Mutator for line
  void setLine(const std::string& newLine);
 
  // Accessor for next pointer
  Node* getNext() const;
 
  // Mutator for next pointer
  void setNext(Node* newNext);
 };
 
#include "Node.cpp"
 
#endif 