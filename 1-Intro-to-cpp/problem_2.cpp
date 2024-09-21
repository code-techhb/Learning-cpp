// Houlaymatou B. | @code_techhb

// -------------------------
// Chap 2: Intro to c++ 
// Goal 🎯: Variable declaration and displaying a message on the screen

/*Programming Challenges - Problem 2: Restaurant Bill
 Write a program that computes the tax and tip on a restaurant bill for a patron with a $44.50 meal charge. The tax should be 6.75 percent of the meal cost. The tip should be 15 percent of the total after adding the tax. Display the meal cost, tax amount, tip amount, and total bill on the screen.
 */
// -------------------------

#include <iostream>
using namespace std;

int main() {
  // variable declaration
  float tax_percentage, tip_percentage, tax, tip, bill, bill_with_tax, total;

  // constances 
  tax_percentage=0.0675;
  tip_percentage=0.15;
  bill=44.50;

  // Computations
  tax=tax_percentage*bill;
  bill_with_tax = bill + tax;
  tip=bill_with_tax*tip_percentage;
  total=bill_with_tax+tip;

  // Output to user
  cout<<"\nWe hope you enjoyed your meal today 😋.\n\n";
  cout<<"Meal Cost: $"<<bill<<"\n"<<"Tax amount: $"<<tax<<"\n"<<"Tip amount: $"<<tip<<"\n"<<"Total bill today: $"<<total<<"\n";
  cout<<"\nThank you for your business!\n";


  return 0; //end of program
}