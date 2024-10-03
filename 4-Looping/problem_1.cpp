// Houlaymatou B. | @code_techhb

// -------------------------
// Chap 5: Looping
// Goal 🎯: Practice while, do while, and for loops.

/*Programming Challenges - Problem 1: Sales Bar chart
Write a program that asks the user to enter today’s sales rounded to the nearest $100 for each of three stores. The program should then produce a bar graph displaying each store’s sales. Create each bar in the graph by displaying a row of asterisks. Each asterisk should represent $100 of sales.
*/
// -------------------------
#include <iostream>
#include <math.h>
using namespace std;

int main(){
  // Variable declaration
  float amount_sales, number_stars, store1_stars, store2_stars,store3_stars;
  char asterisks = '*';
  
  // prompt user
  cout<<"\nWelcome to your sales charter 📊\n";
  for(int counter=1; counter<=3; counter++){
    cout<<"Please enter today's sales for store #"<<counter<<": ";
    cin>>amount_sales;

    // validate user input
    while (amount_sales<0){
      cout<<"\nPlease ONLY enter Positive sales for store #"<<counter<<": ";
      cin>>amount_sales;
    }

    //the number of star for each store 
    number_stars=round(amount_sales/100);
    switch(counter){
      case 1: 
        store1_stars=number_stars;  
        break;
      case 2:
        store2_stars=number_stars;   
        break;
      case 3:
        store3_stars=number_stars;   
        break;
      default:
      cout<<"Sorry, we only have 3 stores!";

    }

  }

  // output the chart
  cout <<"\n\tDAILY SALES\n(Each Aestericks * = $100)\n\n";
  // store 1
  cout<<"Store 1: ";
  for (int i=1; i<=store1_stars; i++){
    cout<<asterisks;
  }
  cout<<"\n";

  // store 2
  cout<<"Store 2: "; 
  for (int i=1; i<=store2_stars; i++){
    cout<<asterisks;
  }
  cout<<"\n";

  // store 3
  cout<<"Store 3: ";
  for (int i=1; i<=store3_stars; i++){
    cout<<asterisks;
  }
  cout<<"\n\n";
 
 cout<<"Keep it up💰!\n\n";

  //end program
  return 0;
}