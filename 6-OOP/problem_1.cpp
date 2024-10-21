// Houlaymatou B. | @code_techhb

// -------------------------
// Chap 6: OOP Basics
// Goal 🎯: Practice Class & Object 

/*Programming Challenges - Problem 1: Tip
Design a Tips class that calculates the gratuity on a restaurant meal.  Its only class member variable, taxRate should be set by a one-parameter constructor to whatever rate is passed to it when a Tips object is created.  If no argument is passed, a default tax rate of .085 should be used. You may use a default constructor for the default value.  taxRate should be Private.  
The class should have just one public function, computeTip.  This function needs to accept two arguments, the total bill amount and the tip rate.   It should  use the total bill amount, along with the value stored in the taxRate member variable to compute the cost of the meal before the tax was added.  It should then apply the tip rate to just the meal cost portion of the bill to compute and return the tip amounts.  
 Demonstrate the class by creating a program that creates a single Tips object, and then loops to let the user retrieve the correct tip amount using various bill totals and desired tip rates.
Validation:  The tax rate entered by the user should be validated to ensure that it is greater than or equal to zero.

*/
// ------------------------- Code ------------------------------
#include <iostream>
#include <iomanip>
using namespace std;

// Class declaration
class Tips {
  private:
    float taxRate;

  public:
    // constructor if argument is passed to future obj
    Tips(float rate) {
      // Validate tax rate
      while (rate < 0) {
        cout << "Error: Tax rate must be a positive value. Please enter again: ";
        cin >> rate;
      }
      taxRate = rate;
    }

   // constructor if no argument is passed to future obj
    Tips() {
      taxRate = 0.085;
    }

    // Function to compute the tip amount
    float computeTip(float total_bill, float tip_rate) {
      float meal_cost, tip_amount;
      meal_cost = total_bill / (1 + taxRate);  
      tip_amount = meal_cost * tip_rate;      
      return tip_amount;
    }
};

// Main 
int main() {
  // Variable declarations
  float bill, tip_rate, tip_amount, userTaxRate;
  char tax_option, should_continue;
  Tips tips_Calculator; //tips obj

  cout<<"\nWelcome to your tip calculator 💰!";
  // Ask user if they want to specify a tax rate or use the default
  cout << "\n\nWould you like to specify a tax rate? (y/n): ";
  cin >> tax_option;
  
  // Create a Tips object based on user's choice
  if (tolower(tax_option) == 'y') {
    cout << "Please enter the Business's tax rate in decimals (example: 0.15 for 15%): ";
    cin >> userTaxRate;
    // use constructor w/ arg
    tips_Calculator = Tips(userTaxRate);
  } else {
    // Use default constructor w/ fixed rate
    cout<<"No worries! We'll apply the state tax rate of 0.085 😊";
    tips_Calculator = Tips();
  }

  // calculate tips
  do {
    // Prompt user 
    cout << "\nEnter the total bill amount: $";
    cin >> bill;
    cout << "Enter the tip rate in decimals (example: 0.15 for 15%): ";
    cin >> tip_rate;

    // Computation 
    tip_amount = tips_Calculator.computeTip(bill, tip_rate);

    // Output the result
    cout << fixed << setprecision(2);
    cout << "\nThe total tip amount is: $" << tip_amount << endl;

    // Ask if user wants to calculate another tip
    cout << "Would you like to compute another tip? (y/n): ";
    cin >> should_continue;
  } while (tolower(should_continue) != 'n');
  system("clear");
  
  cout<<"\nOkay. Have a lovely day 🌷!"<<endl;
  return 0;
}

