// Houlaymatou B. | @code_techhb

// -------------------------
// Chap 4: Conditional statements
// Goal 🎯: Practice if/else and switch statements

/*Programming Challenges - Problem 4: February Days
The month of February normally has 28 days. But if it is a leap year, February has 29 days. Write a program that asks the user to enter a year. The program should then display the number of days in February that year. Use the following criteria to identify leap years:

Determine whether the year is divisible by 100. If it is, then it is a leap year if and if only it is also divisible by 400. For example, 2000 is a leap year but 2100 is not.

If the year is not divisible by 100, then it is a leap year if and if only it is divisible by 4. For example, 2008 is a leap year but 2009 is not.
*/
// -------------------------
#include <iostream>
#include <math.h>
using namespace std;

int main(){
  // variable declaration
  int year, days_in_february;

  // prompt user
  cout<<"\nWelcome to your Leap year determinator 🗓️\nPlease Enter a year (yyyy) and I'll determine the number of days in the month of February 🤓\nType here: ";
  cin>>year;

  // logic implementation
  if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0)){
    days_in_february=29;
      cout<<"🎉 "<<year<<" is a Leap year. So February is "<<days_in_february<<" days 🤓!\n\n";
  }else{
    days_in_february = 28;
    cout<<year<<" is NOT a Leap year. So February is "<<days_in_february<<" days 🤓!\n\n";
  }

  // end of program
  return 0; 
}