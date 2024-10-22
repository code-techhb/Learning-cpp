// Houlaymatou B. | @code_techhb

// -------------------------
// Chap 6: Functions
// Goal 🎯: Practice function prototype, definition and call.

/*Programming Challenges - Problem 6: Prime numbers
A prime number is an integer greater than 1 that is evenly divisible by only 1 and itself. For example, the number 5 is prime because it can only be evenly divided by 1 and 5. The number 6, however, is not prime because it can be divided by 1, 2, 3, and 6.

Write a Boolean function named isPrime, which takes an integer as an argument and returns true if the argument is a prime number, and false otherwise. Demonstrate the function in a complete program.
*/
// ------------------------- code ------------------------------
#include <iostream>
#include <iomanip>
using namespace std;

// Function prototypes
bool isPrime(int );

// main
int main(){
  int number;
  char go_again = 'y';

  cout<<"\nWelcome to primeChecker\n";
  do {
    cout<<"Enter a number: ";
    cin>>number;

    if (isPrime(number)){
      cout<<number<<" is indeed a prime number!\n";
    } else{
      cout<<number<<" is NOT a prime number!\n";
    }

    cout<<"\n\nIs there another number you wanna check? Type(y/n): ";
    cin>>go_again;

    if(tolower(go_again)=='n'){
      cout<<"Okay, Byeeee!\n\n";
    }
  }while(tolower(go_again) != 'n');
  
  return 0;
}

// function definiton
bool isPrime(int n){
  // because all prime numbers are greater than one
  if(n <= 1){
    return false;
  } 
  // because 2 is the only even number
  if(n==2){
      return true;
  }
  // so let's exclude all even numbers after 2
  if (n%2 == 0){
    return false;
  }

  // check for divisibility up to sqrt of n
  for (int i=3; i*i <= n; i+=2){
    if (n % i == 0) {
      // it's not a prime
      return false;
    }
  }
  // else, we return true bc it's prime
  return true;
}

