// Houlaymatou B. | @code_techhb

// -------------------------
// Chap 4: Conditional statements
// Goal 🎯: Practice if/else and switch statements

/*Programming Challenges - Problem 1: Maximum and minimum
Write a program that asks the user to enter two different integers. The program should use the conditional operator to determine which number is the smaller and which is the larger.
*/
// -------------------------

#include<iostream>
#include<string> //needed for the string data type
using namespace std;

int main(){
  // variable declaration
  float number_1, number_2;
  string name;

  // prompt user
  cout<<"Please enter your name: ";
  getline(cin, name); //read entire line including spaces
  cout<<"\nHello, "<<name<<"!\n";
  cout<<"Enter two numbers and I will tell you which one is greater 😁 \n";
  cout<<"Number 1: ";
  cin>>number_1;
  cout<<"Number 2: ";
  cin>>number_2;

  if (number_1>number_2){
    cout<<number_1 <<" is greater than "<<number_2;
  }else{
    cout<<number_2 <<" is greater than "<<number_1;
  }
}