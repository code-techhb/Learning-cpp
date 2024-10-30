// Houlaymatou B. | @code_techhb

// -------------------------
// Chap 8: Arrays  
// Goal 🎯: Practice Class & Object  & Arrays

/*Programming Challenges - Problem 1: Array of Payroll Objects
Design a PayRoll class that has data members for an employee’s hourly pay rate and number of hours worked.  The class should have member functions to set the hourly pay rate and number of hours worked and to calculate gross pay. 
The main program should create an array of seven PayRoll objects.   It should contain two loops.   The first loop should read the number of hours each employee worked and their hourly pay rate from a file and call class set functions to store this information in the appropriate objects.
The second loop should call a class function, once for each object, to return the employee’s gross pay, and display it as follows.     
*/
// ------------------------- code ------------------------------

#include <iostream>
#include <iomanip>
#include <fstream> 
using namespace std;

// declare class
class PayRoll {
  private:
    double hourlyRate;
    double hoursWorked;

  public:
    // setter functions
    void setHourlyRate(double hRate){
      hourlyRate = hRate;
    }

    void setHoursWorked(double hWorked){
      hoursWorked = hWorked;
    }

    // calculate gross pay
    double calcGrossPay(){
      return hourlyRate * hoursWorked;
    }
};


int main(){
  // variable delcaration
  PayRoll employees[7];
  ifstream infile;

  // open the file 
  infile.open("payroll.txt");

  // loop to get hourly rate and hours worked 
  for (int i=0; i<7; i++){
    double hoursWorked, hourlyRate;
    // read from file
    infile >> hoursWorked;
    infile >> hourlyRate;
    // populate the array
    employees[i].setHoursWorked(hoursWorked);
    employees[i].setHourlyRate(hourlyRate);
  }

  cout<<"\nEmployee"<<"   "<<"Gross Income\n";
  cout<<"========"<<"   "<<"=============\n";
  // loop to calculate the gross income
  for (int i=0; i<7; i++){
    cout<<setw(4)<<i+1<<right<<setw(9)<<fixed<<setprecision(2)<<"$"<<employees[i].calcGrossPay()<<"\n";
  }
  // close file
  infile.close();
  return 0;
}