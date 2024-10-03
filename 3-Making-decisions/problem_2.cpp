// Houlaymatou B. | @code_techhb

// -------------------------
// Chap 4: Conditional statements
// Goal 🎯: Practice if/else and switch statements

/*Programming Challenges - Problem 1: Magic dates
The date June 10, 1960, is special because when we write it in the following format, the month times the day equals the year.

6/10/60

Write a program that asks the user to enter a month (in numeric form), a day, and a two-digit year. The program should then determine whether the month times the day is equal to the year. If so, it should display a message saying the date is magic. Otherwise, it should display a message saying the date is not magic. Test your program with some dates that are magic and some that are not.

Input Validation: Think about what legal values the program should accept for month and day.
*/
// -------------------------
#include<iostream>
#include <cctype> //for isdigit() function
using namespace std;


int main(){
  // variable declaration
  int month, day, year, result;

  // prompt user 
  cout<<"\nWelcome to your Magic Dates determinator 🦄!\n";
  cout<<"Please enter the following in numeric form ONLY!\n\n";

  // prompt user for month input
  cout<<"Month: ";
  cin>>month;
  if (cin.fail()) {
      cout << "\nSorry😞! We only work with NUMERIC values! Try again.\n";
      return 1;
  }
  if(month<=0 || month>12){
    cout<<"Sorry! the month has to be between 1-12\n\n";
    return 1;
  }
  
  // prompt user for Day input
  cout<<"Day: ";
  cin>>day;
  if (cin.fail()) {
      cout << "\nSorry😞! We only work with NUMERIC values! Try again.\n";
      return 1;
  }
  if(day<=0 || day>31){
    cout<<"Sorry! the day has to be between 1-31\n\n";
    return 1;
  }

  // prompt user for year input
  cout<<"Last two digits of a year: ";
  cin>>year;
  if (cin.fail()) {
      cout << "\nSorry😞! We only work with NUMERIC values! Try again.\n";
      return 1;
  }
  //make user input last two digit of year
  if(year<0 || year>99){
    cout << "Sorry! The year should be a valid 2-digit number. Please restart the program.\n";
    return 1;
  }

  //  check if day times month = last two digits of the year
  if((day*month) == year){
    cout<<"🎉YAY "<<month<<"/"<<day<<"/"<<year<<" is a Magic Date!\n\n";
  }else{
    cout<<"OOPS! looks like "<<month<<"/"<<day<<"/"<<year<<" is not a Magic Date!\n\n";
  }
}
