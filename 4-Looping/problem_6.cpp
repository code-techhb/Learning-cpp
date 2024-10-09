// Houlaymatou B. | @code_techhb

// -------------------------
// Chap 5: Looping
// Goal 🎯: Write to a file.

/*Programming Challenges - Problem 6: Savings Account Balance

Write a program that calculates the balance of a savings account at the end of a three-month period. It should ask the user for the starting balance and the annual interest rate. A loop should then iterate once for every month in the period, performing the following steps:

Ask the user for the total amount deposited into the account during that month and add it to the balance. Do not accept negative numbers.

Ask the user for the total amount withdrawn from the account during that month and subtract it from the balance. Do not accept negative numbers or numbers greater than the balance after the deposits for the month have been added in.

Calculate the interest for that month. The monthly interest rate is the annual interest rate divided by 12. Multiply the monthly interest rate by the average of that month’s starting and ending balance to get the interest amount for the month. This amount should be added to the balance.

After the last iteration, the program should display a nicely formatted report that includes the starting balance, total deposits, total withdrawals, total interest, and final balance.
*/
// ------------------------- code ------------------------------
#include <iostream>
#include <iomanip>
#include <fstream> //needed for files R/W
using namespace std;

int main(){
  // variable declaration
  float annual_interest=0.0, 
        starting_balance=0.0, 
        deposit=0.0,
        total_deposit=0.0, 
        withdraw=0.0,
        total_withdraw=0.0, 
        month_starting_balance=0.0,
        month_ending_balance=0.0,
        monthly_interest=0.0, 
        total_interest=0.0, 
        final_balance=0.0;

  ofstream output_file; //creating a file object

  // prompt user
  cout<<"\nWelcome to Budget++\n";
  cout<<"Let's calculate your 3-month period balance 💰\nPlease enter the following\n";

  cout<<"Current Balance: $";
  do {
      cin >> starting_balance;
      if (starting_balance < 0) {
        cout << "Invalid input! Please enter a positive amount: ";
      }
  } while (starting_balance < 0);
  month_starting_balance = starting_balance;
  final_balance += starting_balance; //add to final balance

  cout<<"Annual Interest Rate (In decimal point please. Example 3% = 0.03): ";
  cin>>annual_interest;

  // 3-month Period data collection
  for(int i=1; i<=3; i++){
    cout<<"\n\nMonth #"<<i<<"\n";
    cout<<"Enter your total deposit for this month: $";
    // Deposit Input with Validation
    do {
      cin >> deposit;
      if (deposit < 0) {
        cout << "Invalid input! Please enter a positive deposit amount: ";
      }
    } while (deposit < 0);
    final_balance += deposit;

    cout<<"Enter the total amount withdrawn this month: $";
    // Withdraw Input with Validation
    do {
      cin >> withdraw;
      if (withdraw < 0 || withdraw >final_balance) {
        cout << "Invalid! Withdraw cannot exceed available balance after deposits or be less than 0.\nTry again: ";
      }
    } while (withdraw < 0 || withdraw >final_balance);
    final_balance -= withdraw;

    // compute monthly interest
    month_ending_balance = (month_starting_balance + deposit) - withdraw;
    monthly_interest = (annual_interest/12)*((month_starting_balance+month_ending_balance)/2);
    //update starting balance for next month
    month_starting_balance = month_ending_balance + monthly_interest; 
    

    // update totals
    total_interest += monthly_interest;
    total_deposit += deposit;
    total_withdraw += withdraw;
    final_balance += monthly_interest;
  }

  // write report to a file
  output_file.open("report.txt"); //open a file to write into
  output_file << "----- Three-Month Period Report -----\n";
  output_file << left << setw(20) << "Starting Balance:" 
              << right << "$" << setw(10) << fixed << setprecision(2) << starting_balance << endl;
  output_file << left << setw(20) << "Total Deposits:" 
              << right << "$" << setw(10) << total_deposit << endl;
  output_file << left << setw(20) << "Total Withdrawn:" 
              << right << "$" << setw(10) << total_withdraw << endl;
  output_file << left << setw(20) << "Total Interest:" 
              << right << "$" << setw(10) << total_interest << endl;
  output_file << left << setw(20) << "Final Balance:" 
              << right << "$" << setw(10) << final_balance << endl;
  output_file.close(); // Close the file

  // Orient user
  cout<<"\nYou can download the Report file!\nSee you in 3 months for your next report 🤓!\n"<<endl;

return 0;
}