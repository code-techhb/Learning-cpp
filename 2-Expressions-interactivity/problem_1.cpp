// Houlaymatou B. | @code_techhb

// -------------------------
// Chap 3: Expressions and Interactivity 
// Goal 🎯: Input-Output formated

/*Programming Challenges - Problem 1: Miles per Gallon
There are three seating categories at a stadium. For a softball game, Class A seats cost $15, Class B seats cost $12, and Class C seats cost $9. Write a program that asks how many tickets for each class of seats were sold, then displays the amount of income generated from ticket sales. Format your dollar amount in a fixed-point notation with two decimal points and make sure the decimal point is always displayed.
*/
// -------------------------

#include <iostream>
#include <iomanip> 
using namespace std;

int main(){
  // variable declaration
  double class_A_seat_price, class_B_seat_price, class_C_seat_price;
  double tickets_sold_A, tickets_sold_B, tickets_sold_C, total_income;

  // Initialization
  class_A_seat_price = 15;
  class_B_seat_price = 12;
  class_C_seat_price = 9;

  // Get inputs
  cout << "\nWelcome to your Favorite part of this event 🥎 - Calculating Revenue 😁!\n";
  cout << "How many tickets were sold for class\n";
  cout << "A: ";
  cin >> tickets_sold_A;
  cout << "B: ";
  cin >> tickets_sold_B;
  cout << "C: ";
  cin >> tickets_sold_C;

  // computation
  total_income = (class_A_seat_price * tickets_sold_A) + 
                 (class_B_seat_price * tickets_sold_B) + 
                 (class_C_seat_price * tickets_sold_C);

  // Output result to user
  // cout  ;
  cout << "Today, we generated: $" << fixed << setprecision(2) << total_income << " - Let's keep it up Team!\n\n";
  
  return 0;
}
