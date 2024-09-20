// Houlaymatou B. | @code_techhb
// -------------------------
// Chap 2: Intro to c++ 
// Goal 🎯: Variable declaration and displaying a message on the screen

/*Programming Challenges - Problem 1: Sales Prediction

The East Coast sales division of a company generates 58 percent of total sales. Based on that percentage, write a program that will predict how much the East Coast division will generate if the company has $8.6 million in sales this year. Display the result on the screen. */

// -------------------------

#include <iostream> // preprocessor directive to include input-output functions
using namespace std; // standard namespace

int main() {
  // variables declaration
  float profit_percentage, profit, total_sales;

  // Initialization
  profit_percentage=0.58;
  total_sales = 8.6; //million

  // computation
  profit = profit_percentage * total_sales;

  // output result
  cout<<"\nWith 58 percent of total sales, if the company has $8.6 million in sales this year, they will generate $"<<profit<<" million.\n";

  
  return 0; //end of program
}