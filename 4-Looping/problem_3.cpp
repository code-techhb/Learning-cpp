// Houlaymatou B. | @code_techhb

// -------------------------
// Chap 5: Looping
// Goal 🎯: Practice while, do while, and for loops.

/*Programming Challenges - Problem 3: Pennies Pay
Write a program that calculates how much a person earns in a month if the salary is one penny the first day, two pennies the second day, four pennies the third day, and so on with the daily pay doubling each day the employee works. The program should ask the user for the number of days the employee worked during the month, validate that it is between 1 and 31, and then display a table showing how much the salary was for each day worked, as well as the total pay earned for the month. The output should be displayed in dollars with two decimal points, not in pennies.
*/
// -------------------------
#include <iostream>
#include <iomanip>
using namespace std;

int main(){
  // variable declaration
  int num_days; 
  double salary, total;

  // initialization
  salary = 0.01; // 1 penny = $0.01
  total = 0.0;

  // prompt user
  cout<<"\nWelcome to your Salary Calculator 🧮\n";
  cout<<"Please enter the number of days you worked this month.\nType here: ";
  cin >> num_days;

  // validate user input
  while(num_days<1 || num_days>31){
    cout<<"Please enter a number between 1-31: ";
    cin>>num_days;
  }

  // table of salary
  cout<<"Days \t\tSalary\n";
  cout<<"-----------------------\n";
  for (int i=1; i<=num_days; i++){
    // print table 
    cout<<i<<"\t\t"<<fixed<<setprecision(2)<<"$"<<salary<<"\n";

    // Accumulate total salary
    total += salary;
    // Double the salary for the next day
    salary *= 2;
  }
  cout<<"-----------------------\n";
  cout<< right << setw(5)<<"Total Salary: $"<<total<<"\n\n";

  return 0;
}
