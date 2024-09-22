// Houlaymatou B. | @code_techhb

// -------------------------
// Chap 3: Expressions and Interactivity 
// Goal 🎯: Input-Output formated

/*Programming Challenges - Problem 2: Batting Average
Write a program to find a baseball player’s batting average. The program should ask the user to enter the number of times the player was at bat and the number of hits earned. Display the batting average as a decimal between .000 and 1.000. For example, if a player bats 40 times and gets 10 hits, which is 25% of the time, their batting average would be .250.
*/
// -------------------------

#include <iostream>
#include <iomanip>
using namespace std;

int main(){
  // variable declaration
  float number_of_bats, number_of_hits, batting_average;

  // get input from user
  cout<<"\nWelcome to the Batting Average determinatOR!\n";
  cout<<"Please enter the number of: \n";
  cout<<"Bat: ";
  cin>>number_of_bats;
  cout<<"Hit: ";
  cin>>number_of_hits;

  // computation
  batting_average = number_of_hits/number_of_bats;

  // output result
  cout<<"The batting average is: " << fixed <<setprecision(3) << batting_average <<"\n\n";
  return 0; 
}