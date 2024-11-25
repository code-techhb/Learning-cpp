// Houlaymatou B. | @code_techhb

// -------------------------
// Chap 12: C-String and String class
// Goal 🎯: Practice strings manip

/*Programming Challenges - Problem 1: Word Separator 
Write a program that accepts as input a sentence with all the words running together, but the first character of each word is an uppercase letter and stores it in the form of a string object.  Convert the sentence to a string in which the words are separated by spaces and only the first word starts with an uppercase letter.    For example, the string “StopAndSmellTheRoses” would be converted to “Stop and smell the roses”.     Note:  += operator can be used with strings.
*/
// ------------------------- code ------------------------------
#include <iostream>
#include <cctype>
#include <string>
using namespace std;

// function prototype
void formatString(string );

// ------------------------- main program ------------------------------
int main(){
  // variable declaration
  string userInput;

  // prompt user
  cout<<"\nEnter a an expression that runs all together where the beginning of each word is uppercase: ";
  getline(cin, userInput);

  // call function
  formatString(userInput);

 return 0;
}

// ---------------- Function definitions ---------------------
void formatString(string input){
  string newString;
  // check for upper case
  for (int i=0; i<input.length(); i++){
    if (i==0){
      newString += toupper(input[i]);
    } else if (isupper(input[i])){
      newString += ' ';
      newString += tolower(input[i]);
    } else {
      newString += input[i];
    }
  }
  // output
  cout<<"\nFormatted Sentence: "<<newString<<"."<<endl<<endl;
}