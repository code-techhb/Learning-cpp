// Houlaymatou B. | @code_techhb

// -------------------------
// Chap 12: C-String and String class
// Goal 🎯: Practice strings manip

/*Programming Challenges - Problem 2: Case Manipulator 
Write a program with three functions:  upper, lower, and flip.  Each function should accept a C-string as an argument.  The upper function should step through all the characters in the string, converting each to uppercase.  The lower function,  should step through all the characters in the string converting, each to lowercase.   The  flip  steps through the string, testing each character to determine whether it is upper or lowercase.   If upper, it should convert to lower.  If lower, it should convert to upper.
The main function should accept one string from the user, then pass it to each of the functions.
*/ 
// ------------------------- code ------------------------------
#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

// function prototype
void transformUpper(char*);
void transformLower(char*);
void transformFlip(char*);

// ------------------------- main program ------------------------------
int main(){
  // variable declaration
  const int SIZE = 100;
  char words[SIZE], wordsCopy[SIZE];

  // prompt user
  cout<<"\nEnter a word: ";
  cin.getline(words, SIZE);

  cout << "Original String: " << words << endl;

  // function calls
  transformUpper(words);
  cout << "\nUppercase: " << words << endl;

  transformLower(words);
  cout << "Lowercase: " << words << endl;

  transformFlip(words);
  cout << "Flipped case: " << words << endl;


  return 0;
}

// ---------------- Function definitions ---------------------
// Note to self: word > is a pointer; *word > is the value
void transformUpper(char *word){
  while (*word != 0) {
    *word = toupper(*word);
    word++;
  }
 
}

void transformLower(char *word){
  while (*word != 0) {
    *word = tolower(*word);
    word++;
  }
}

void transformFlip(char *word) {
  bool toUpper = true;
  while (*word != 0) {
    if (isalpha(*word)) {
      if (toUpper) {
        *word = toupper(*word);
      } else {
        *word = tolower(*word);
      }
      // change state
      toUpper = !toUpper;
    }
    word++;
  }
}