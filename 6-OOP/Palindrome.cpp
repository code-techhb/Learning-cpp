#include "Palindrome.h"
#include <string>

// using namespace std;

// ------------------------- Constructor ------------------------------
Palindrome::Palindrome(const std::string& str) : std::string(str) {}

// ------------------------- Member function ------------------------------
bool Palindrome::isPalindrome() const {
  int len = this->length();  
    
  // Check characters from both ends toward the middle
  for (int i = 0; i < len / 2; ++i) {
    if ((*this)[i] != (*this)[len - i - 1]) {
      // If characters don't match, it's not a palindrome
      return false; 
    }
  }
  //it's a palindrome  
  return true;  
}

