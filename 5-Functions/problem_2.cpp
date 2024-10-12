// Houlaymatou B. | @code_techhb

// -------------------------
// Chap 6: Functions
// Goal 🎯: Practice function prototype, definition and call.

/*Programming Challenges - Problem 1: Retail
Write a program that asks the user to enter an item’s wholesale cost and its markup percentage. It should then display the item’s retail price.
The program should have a function named calculateRetail that receives the wholesale cost and the markup percentage as arguments and returns the retail price of the item.
*/
// ------------------------- code ------------------------------
#include <iostream>
#include <iomanip>
using namespace std;

// function prototype
float calculateRetail(float, float);

int main(){
  // variable declaration
  float wholesale, markup_percentage, price;

  // prompt user
  cout<<"\n\nWelcome to your Retail Price Calculator\n\n";
  cout<<"Please enter the following:\n";

  do{
    cout<<"Wholesale cost of your item: $";
    cin>>wholesale;
    cout<<"Markup Percentage (in decimal format like 0.5): ";
    cin>>markup_percentage;
    
    if(wholesale <0 || markup_percentage<0){
      cout<<"You can't use negative numbers! Try again....\n\n";
    }
  }while(wholesale <0 || markup_percentage<0);
 
  // function call
  price = calculateRetail(wholesale, markup_percentage);
  // output
  cout<<"\nThe Price of the item should be fixed at $"<<fixed<<showpoint<<setprecision(2)<<price<<endl<<endl;

  // end program
  return 0;
}

// function defintion
float calculateRetail(float wholesale_price, float markup){
  float addition_from_markup, actual_price;
  // computation
  addition_from_markup = wholesale_price * markup;
  actual_price = wholesale_price + addition_from_markup;
  return actual_price;
}

