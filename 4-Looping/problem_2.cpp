// Houlaymatou B. | @code_techhb

// -------------------------
// Chap 5: Looping
// Goal 🎯: Practice while, do while, and for loops.

/*Programming Challenges - Problem 2: Sum of numbers
Write a program that asks the user for a positive integer value and that uses a loop to validate the input. The program should then use a second loop to compute the sum of all the integers from 1 up to the number entered. 
*/
// -------------------------
#include <iostream>
#include <cctype>
using namespace std;

int main(){
// variable declaration
int number,  sum;
char response;

// initialize sum
sum=0;

cout<<"\nWelcome to your SumMer Calculator ✚\n";
do {
  // prompt user
  cout<<"Enter a Positive integer number, and I'll give you the sum of all the integers from 1 up to the number entered 🤓\nType here: ";
  cin>>number;

  // check if user input is positive int
  while(number<=0){
    cout<<"Ooops! Remember we said POSITIVE integers. Please try again 🤓\nType here: ";
    cin>>number;
  }

  // compute sum
  for (int i=0; i<=number; i++){
    sum = (number *(number + 1))/2;
  }

  cout<<"\n🎉 The Sum of all the positive integers up to "<<number<<" is equal to "<<sum<<"\nAre you impressed🤓? (y/n)\n";
  cin>>response;

  if(tolower(response)=='y'){
    cout<<"🥳 I knew it! We are nerds here 🤓!\n\n";
  } else{
    cout<<"Well! We can try again with larger numbers. Let's goo🤓!\n\n";
  }
}while(response != 'y');

return 0;
}