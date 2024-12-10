#ifndef PALINDROME_H
#define PALINDROME_H
#include <string>

using namespace std;

// Palindrome class
class Palindrome : public string {
public:
    Palindrome(const string& str);
    // member function
    bool isPalindrome() const; 
};

#endif
