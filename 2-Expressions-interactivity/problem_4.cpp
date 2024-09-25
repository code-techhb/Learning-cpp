// Houlaymatou B. | @code_techhb

// -------------------------
// Chap 3: Expressions and Interactivity 
// Goal 🎯: Input-Output formated

/*Programming Challenges - Problem 4: Math Tutor
Write a program that can be used as a math tutor for a young student. The program should display two random numbers between 1 and 9 to be added.
After the student has entered an answer and pressed the [Enter] key, the program should display the correct answer so the student can see if his or her answer is correct.
*/

// -------------------------
#include <iostream>
#include <cstdlib> // Header file to get srand() function
#include <ctime> // Header file needed to use time

using namespace std;

int main(){
  // Variable declaration
  int result, number_1, number_2;
  unsigned seed; // Random generator seed  


  seed = time(0); //Using the time function to get a new seed anytime the program runs
  srand(seed); 

  cout<<"\nWelcome to your favorite math tutor 🧮\n";
  // generate numbers between 1 and 9
  number_1 = rand() % 9 + 1;
  number_2 = rand() % 9 + 1;
  result= number_1 + number_2;

  // Prompt user
  cout<<"What is "<<number_1 << "+"<<number_2<<"?\n";
  cout<<"Type the reseult here: ";
  cin>>result;
  
  // output result
  cout<<"Great Try! The Correct answer is: "<<result<<"!\n\n";
  return 0;
}