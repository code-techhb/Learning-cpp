// Houlaymatou B. | @code_techhb

// -------------------------
// Chap 5: Looping
// Goal 🎯: Practice while, do while, and for loops.

/*Programming Challenges - Problem 4: Membership Fees Increase
A country club, which currently charges $3,000 per year for membership, has announced it will increase its membership fee by 3 percent each year for the next five years. Write a program that uses a loop to display the projected rates for each of the next five years.
*/
// -------------------------
#include <iostream>
#include<iomanip>
using namespace std;

int main(){
  // variable declaration and initialization
  const float INCREASE_RATE = 0.03;
  int current_year = 2024;
  float membership_fees = 3000;
  
  // predict
  cout<<"\nC++ Membership club fees Info for the next 5 years\n";
  cout<<"\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
  cout<<"2024 Membership fees: $"<<membership_fees<<"\nWith a 3 percent increase each year, see table below\n";

  cout<<"Year \t\tFees\n";
  cout<<"-----------------------\n";
  // next five years
  for (int i = 1; i<=5; i++){
    current_year += 1;
    // new fees
    membership_fees *= (1 + INCREASE_RATE);
    // print table 
    cout<<current_year<<"\t\t"<<fixed<<setprecision(2)<<"$"<<membership_fees<<"\n";
  }
  return 0;
}