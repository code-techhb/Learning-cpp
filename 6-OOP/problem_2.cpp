// Houlaymatou B. | @code_techhb

// -------------------------
// Chap 7: OOP 
// Goal 🎯: Practice Class & Object 

/*Programming Challenges - Problem 2: Date
Design a class called Date that has integer data members to store month, day, and year. The class should have a three-parameter default constructor that allows the date to be set at the time a new Date object is created. If the user creates a Date object without passing any arguments, or if any of the values passed are invalid, the default values of 1, 1, 2001 (i.e., January 1, 2001) should be used. The class should have member functions to print the date in the following formats:

3/15/20
March 15, 2020
15 March 2020
Demonstrate the class by writing a program that uses it. Be sure your program only accepts reasonable values for month and day. The month should be between 1 and 12. The day should be between 1 and the number of days in the selected month.
*/
// ------------------------- code ------------------------------
#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

// class declaration
class Date{
  private: 
    int month;
    int day;
    int year;

    // leap or not 
  bool isLeap(int y){
    if ((y%4==0) && (y%100!=0 || y%400==0)){
      return true;
    } else {
      return false;
    }
  }
  // check for validity
  bool isValid(int m, int d, int y){
    // check year
    if (y<0){
      return false;
    }

    // check months
    if (m<1 || m>12){
      return false;
    }

    // check days 
    if(d<1 || d>31){
      return false;
    }

    // catch edge cases
    if(m==2){
      // check if leap year
      if (isLeap(y)){
        // if true, then d cannot be greater than 29
        if(d>29){
          return false;
        } 
      } else{
          if(d>28){
            return false;
          }
      }
      
    } else if (m == 4 || m == 6 || m == 9 || m == 11) {
        if (d > 30) {
            return false;
        }
    } else {
      if(d>31) {
        return false;
      }
    }

    return true;
  }

    string nameMonth(int month){
    switch (month) {
      case 1:
        return "January";
        break;
      case 2:
        return "February";
        break;
      case 3:
        return "March";
        break;
      case 4:
        return "April";
        break;
      case 5:
        return "May";
        break;
      case 6:
        return "June";
        break;
      case 7:
        return "July";
        break;
      case 8:
        return "August";
        break;
      case 9:
        return "September";
        break;
      case 10:
        return "October";
        break;
      case 11:
        return "November";
        break;
      default:
        return "December";
    }
  }

  public:
  // Default constructor
  Date() {
      day = 1;
      month = 1;
      year = 2001;
  }
  // contructor with parameters
  Date(int passed_month, int passed_day, int passed_year){
    if (isValid(passed_month, passed_day, passed_year)){
      day = passed_day;
      month = passed_month;
      year = passed_year;
    } else{
      cout<<"\n\nThe values you entered were invalid. We resolved to the default date in the system!\n";
      day = 1;
      month = 1;
      year=2001;
    }
  }
  // write member functions to print the dates in different format
  void printDate(){
    string month_string = nameMonth(month);
    cout<<"Writing the date in 3 ways\n\n";
    cout<<"1-Numerical Format: "<<month<<"/"<<day<<"/"<<year<<endl;
    cout<<"2-Long-form: "<<month_string<<" "<<day<<", "<<year<<endl;
    cout<<"3-International Format: "<<day<<" "<<month_string<<" "<<year<<endl<<endl;
  }

};
 
// main
int main(){

  // variable
  char option;
  int month, day, year;
  Date mydate; //create object
  cout<<"\nHello, would you like to pass a date to our object or do you want to use the default date.\nType P to pass or D to use default date: ";
  cin>>option;

  if(tolower(option)=='p'){
    cout<<"Enter the month: ";
    cin>>month;
    cout<<"Enter the day: ";
    cin>>day;
    cout<<"Enter the year: ";
    cin>>year;
    mydate = Date(month, day, year);
  } else{
    mydate = Date();
  }
  // instantiate an obj
  mydate.printDate();
  return 0;
}