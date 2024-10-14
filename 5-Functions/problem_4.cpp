// Houlaymatou B. | @code_techhb

// -------------------------
// Chap 6: Functions
// Goal 🎯: Practice function prototype, definition and call.

/*Programming Challenges - Problem 4: Compare strings
You know that the == operator can be used to test if two string objects are equal. However, you will recall that they are not considered equal, even when they hold the exact same letters, if the cases of any letters are different. So, for example, if name1 = "Jack" and name2 = "JACK", they are not considered the same. Write a program that asks the user to enter two names and stores them in string objects. It should then report whether or not, ignoring case, they are the same.

To help the program accomplish its task, it should use two functions in addition to main, upperCaseIt() and sameString().

The sameString function, which receives the two strings to be compared, will need to call upperCaseIt for each of them before testing if they are the same. The upperCaseIt function should use a loop so that it can call the toupper function for every character in the string it receives before returning it to the sameString function.
*/
// ------------------------- code ------------------------------
#include <iostream>
#include <cctype>
#include <string>
using namespace std;

// function prototype
string upperCaseIt(string);
bool sameString(string, string);

// main
int main(){
  // variable declaration
  string string1, string2;
  bool is_same;

  // prompt user 
  cout<<"\nHey, enter two names and I'll tell if they are the same or not using c++\n\n";

  do {
    cout<<"Enter the first string: ";
    getline(cin, string1);
    cout<<"Enter the second string: ";
    getline(cin, string2);

    if(string1 == "" || string2==""){
      cout<<"\nI don't accept empty strings. Enter something to conitnue....\n";
    }
  }while(string1 == "" || string2=="");
 

  // function call
  is_same = sameString(string1, string2);

  cout<<"\n";
  if (is_same){
    cout<<string1<<" and "<<string2<<" are indeed the same!\n";
  } else{
    cout<<string1<<" and "<<string2<<" are not the same!\n";
  }

  return 0;
}

// function definition
string upperCaseIt(string name){
  string upper_cased = "";
  for (int i=0; i< name.length(); i++) {
    upper_cased += toupper(name[i]);
  }
  return upper_cased;
}

bool sameString(string name1, string name2){
  return (upperCaseIt(name1) == upperCaseIt(name2));
}
