/**
 * Node class - Implementation file
 * Implements the methods defined in Node.h
*/

#include "Node.h"

Node::Node() {
  category = "";  
  line = "";     
  next = nullptr; 
}
 
// Destructor
Node::~Node() {
}
 
// Accessor for category
std::string Node::getCategory() const {
  return category;
}
 
// Mutator for category
void Node::setCategory(const std::string& newCategory) {
  category = newCategory;
}
 
// Accessor for line
std::string Node::getLine() const {
  return line;
}
 
// Mutator for line
void Node::setLine(const std::string& newLine) {
  line = newLine;
}
 
// Accessor for next pointer
Node* Node::getNext() const {
  return next;
}
 
// Mutator for next pointer
void Node::setNext(Node* newNext) {
  next = newNext;
}