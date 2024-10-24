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

  public:
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

  // contructor
  Date(int passed_month, int passed_day, int passed_year){
    if (isValid(passed_month, passed_day, passed_year)){
      day = passed_day;
      month = passed_month;
      year = passed_year;
    } else{
      day = 1;
      month = 1;
      year=2001;
    }
  }

  // write member functions to print the dates in different format

};
 


// main
int main(){

  return 0;
}