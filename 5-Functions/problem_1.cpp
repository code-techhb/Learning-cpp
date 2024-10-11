// Houlaymatou B. | @code_techhb

// -------------------------
// Chap 6: Functions
// Goal 🎯: Practice function prototype, definition and call.

/*Programming Challenges - Problem 1: Winning Division
Write a program that determines which of a company’s four divisions (Northeast, Southeast, Northwest, and Southwest) had the greatest sales for a quarter. It should include the following two functions, which are called by main.

double getSales() is passed the name of a division. It asks the user for a division’s quarterly sales figure, validates that the input is not less than 0, then returns it. It should be called once for each division.

void findHighest() is passed the four sales totals. It determines which is the largest and prints the name of the high grossing division, along with its sales figure.
*/
// ------------------------- code ------------------------------


#include <iostream>
#include <string>
using namespace std;

// functions prototype
double GetSales(string);
void FindHighest(double, double, double, double);


// main 
int main(){
  // variable declaration
  string division_name;
  double northeast_sale, southeast_sale, northwest_sale, southwest_sale;
  
  // function calls
  northeast_sale=GetSales("Northeast");
  southeast_sale=GetSales("Southeast");
  northwest_sale=GetSales("Northwest");
  southwest_sale=GetSales("Southwest");

  FindHighest(northeast_sale, southeast_sale, northwest_sale, southwest_sale);

  // end program
  return 0;
}

// functions definiton

// getSales
double GetSales(string division){
  double quaterly_sales;
  do{
    cout<<"\nPlease enter the quaterly sales for "<<division<<" division: $";
    cin>>quaterly_sales;

    if (quaterly_sales < 0){
      cout<<"Invalid input! You can only enter Positive numbers.";
    }
  }while(quaterly_sales < 0);
  return quaterly_sales;
}

// FindHighest
void FindHighest(double ne_sale, double se_sale, double nw_sale, double sw_sale){
  double highest_sale;

  if((ne_sale > se_sale) && (ne_sale > nw_sale) && (ne_sale>sw_sale)){
    highest_sale = ne_sale;
    cout<<"The Northeast division had the highest sales this quarter.";
   
  } else if((se_sale > ne_sale) && (se_sale > sw_sale) && (se_sale > nw_sale)){
    highest_sale = se_sale;
    cout<<"The Southeast division had the highest sales this quarter.";

  } else if((sw_sale > ne_sale) && (sw_sale > se_sale) && (sw_sale > nw_sale)){
    highest_sale = sw_sale;
    cout<<"The Southwest division had the highest sales this quarter.";

  }else if((nw_sale > ne_sale) && (nw_sale > se_sale) && (nw_sale >sw_sale)) {
    highest_sale = nw_sale;
    cout<<"The Northwest division had the highest sales this quarter.";
    
  } else {
    highest_sale=nw_sale;
    cout<<"\nAll divisions had equally amount of sales.";
  }
  cout<<"\nTheir sales are evaluated at $"<<highest_sale<<endl<<endl;
}