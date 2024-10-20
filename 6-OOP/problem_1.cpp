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
// ------------------------- Quick Draft code ------------------------------
// PS: need to come back and improve program

#include <iostream>
#include <iomanip>
using namespace std;

// Class declaration
class Tips {
  private:
    float taxRate;

  public:
    // constructor if argument is passed to future obj
    Tips(float rate){
      taxRate = rate;
      // need to validate user input later
    }

    // constructor if no argument is passed to future obj
    Tips(){
      taxRate = 0.085;
    }

    float computeTip(float total_bill, float tip_rate){
      float meal_cost, tip_amount;

      meal_cost = (total_bill/(1+taxRate));
      tip_amount = meal_cost * tip_rate;

      return tip_amount;
    }
};

// main
int main(){
  //variable declaration
  float bill, tip_rate, tip_amount;

  // prompt user
  cout<<"This program will compute a restaurant tip based on total bill amount and tip rate.\nPlease enter: \n";
  cout<<"The Total bill: $"<<endl;
  cin>>bill;
  cout<<"The tip percentage in decimals:  "<<endl;
  cin>>tip_rate;

  // object 
  Tips tips_Calculator;
  tip_amount = tips_Calculator.computeTip(bill, tip_rate);

  // output
  cout<<"The total tip amount is $"<<tip_amount<<endl;

  return 0;
}

