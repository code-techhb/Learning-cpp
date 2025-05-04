/**
 *Houlaymatou B. | @code_techhb  
 *Lab 3 - Linked Lists 
 * This program processes lines from a text file using a linked list.
 * It reads category/line pairs from the file and organizes them in a linked list.
 * The categories are displayed in the order they first appear in the file,
 * and lines within each category are displayed in alphabetical order.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "LinkedList.h"
 
// ------------------------ Helper function ------------------------------
/**
* Displays the contents of the linked list
* Shows each category once with all its lines indented
 */
void displayList(const LinkedList& list) {

  std::vector<std::string> listContents = list.toVector();
     
  if (listContents.empty()) {
    std::cout << "OOOPS! The list is empty or doesn't contain enough information 🥲 .\n" << std::endl;
    return;
  }
     
  std::string currentCategory = "";
  for (size_t i = 0; i < listContents.size(); i++) {
    // If the line doesn't start with spaces, it's a category
    if (listContents[i][0] != ' ') {
      if (currentCategory != "") {
        std::cout << std::endl;
      }      
        currentCategory = listContents[i];
        std::cout << currentCategory << std::endl;
      } else {
      // Otherwise, it's a line in the current category
      std::cout << listContents[i] << std::endl;
    }
  }
}
 
// ------------------------ main ---------------------------------------
int main() {
  LinkedList list;
     
  // Read file name from user
  std::string fileName;
  std::cout << "\nHi there 🙋🏾‍♀️,\n";
  std::cout << "Please enter the file name: ";
  std::cin >> fileName;
     
  // Open the file
  std::ifstream inputFile(fileName);
     
  // Check if file opened successfully
  if (!inputFile) {
    std::cout << "Please ensure the file: " << fileName << " exists and try again 🥲 !\n" << std::endl;
    return 1;
  }
     
  // Read and process the file
  std::string category;
  std::string line;
     
  // Read until end of file
  while (std::getline(inputFile, category)) {
    if (std::getline(inputFile, line)) {
      list.add(category, line);
    }
  }
     
  inputFile.close();
     
  // Display the contents of the list
  std::cout << "\n🎉 Content of the list:" << std::endl;
  displayList(list);
     
  return 0;
}