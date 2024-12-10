// Houlaymatou B. | @code_techhb

// -------------------------
// Chap 10: Pointers
// Goal 🎯: Practice Pointers and Dynamic memory allocation

/*Programming Challenges - Problem 3: Age
// Write a program that asks for the user’s name and year of birth, greets the user by name, and declares the user’s age in years. Users are assumed to be born between the years 1800 and 2099, and should enter the year of birth in one of the three formats 18XX, 19XX, or 20XX. A typical output should be “Hello Caroline, you are 23 years old.”
*/
// ------------------------- code ------------------------------
#include <iostream>
#include <string>
using namespace std;
 
int main(){
  // variable declaration
  int dob;
  string *name = new string;
  int *Pyear = &dob;

  // prompt user
  cout<<"\nEnter your name please: ";               
  getline(cin, *name); 

  cout<<"Enter your year of birth please: ";
  cin>>dob;

  // output
  cout << "\nHello " << *name << ", you are " << 2024 - *Pyear << " years old.\n" << endl;

  // free memory
  delete name;
  return 0;
}

