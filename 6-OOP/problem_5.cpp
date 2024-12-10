// Houlaymatou B. | @code_techhb
// -------------------------
// Chap 6: OOP Basics
// Goal 🎯: Practice Class & Object  - Inheritance

/*Programming Challenges - Problem 5:  Palindrome Testing
A palindrome is a string that reads the same backward as forward. For example, the words mom, dad, madam, and radar are all palindromes. Write a class Pstring that is derived from the STL string class. The Pstring class adds a member function

bool isPalindrome( )
that determines whether the string is a palindrome. Include a constructor that takes an STL string object as parameter and passes it to the string base class constructor. Test your class by having a main program that asks the user to enter a string. The program uses the string to initialize a Pstring object and then calls isPalindrome() to determine whether the string entered is a palindrome.

You may find it useful to use the subscript operator [] of the string class: If str is a string object and k is an integer, then str[k] returns the character at position k in the string.
*/
// ------------------------- Code ------------------------------
#include <iostream>
#include <string>
#include "Palindrome.h" 

using namespace std;

int main() {
    // variable declaration
    string input;

    // prompt user
    cout << "Enter a string all in lowercase or Uppercase, and I'll tell you if it's a palindrome 🤓: ";
    getline(cin, input);

    // Create a Palindrome object 
    Palindrome pStr(input);

    // Check if the string is a palindrome
    if (pStr.isPalindrome()) {
        cout << "The string is a palindrome." << endl;
    } else {
        cout << "The string is not a palindrome." << endl;
    }

    return 0;
}
