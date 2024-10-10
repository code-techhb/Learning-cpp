// Houlaymatou B. | @code_techhb

// ------------------------- prompt -------------------------
// Chap 5: Looping
// Goal 🎯: Practice while, do while, and for loops.

/*Programming Challenges - Problem 5: Math Tutor V.3
To-dos: 1- Display a menu for different operations and let user pick one. 
The final selection on the menu should let the user quit the program. 
2- Generate two random numbers and ask user to perform computation based on operations they chose in todo 1.
After the user has finished the math problem, the program should display the menu again. This process must repeat until the user chooses to quit the program. If the user selects an item not on the menu, the program should print an error message and then display the menu again.
*/
// ------------------------- code -------------------------
#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;

int main(){
  // variable declaration and initialization 
  string name;
  int choice;
  char operation, more_practice;
  double num1=0.0, num2=0.0, result=0.0, user_answer, dummy_var;
  const int MIN_VALUE = 1, MAX_VALUE=1000;
  const double EPSILON = 0.01;  // tolerance for floating-point comparison
  unsigned seed;

  // generate random numbers 
  seed = time(0);
  srand(seed);
  
  // prompt user
  cout<<"\nEnter your name please: ";
  getline(cin, name);
  system("clear");
  cout<<"Hey "<<name<<",\nLet's do some math problems 🤓"<<endl;

  do{
    num1 = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;
    num2 = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;

    cout<<"\nPick an operation from the menu below\n";
    cout<<"1-Addition\n2-Substraction\n3-Multiplication\n4-Division\nOr type 900 to exit.\n\nEnter your Choice here: ";
    cin>>choice;

    // Check if input was valid
    if (cin.fail()) {
      // Clear the error state
      cin.clear();
      // Discard invalid input
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      cout << "Invalid input! Please enter a valid number.\n";
      } else {
        // evaluate choice
        switch(choice){
          case 1:
            operation = '+';
            result = num1 + num2;
            break;
          case 2:
            operation = '-';
            result = num1 - num2;
            break;
          case 3:
            operation = '*';
            result = num1 * num2;
            break;
          case 4:
            operation = '/';
            // Check for division by zero for good practice
            if(num2==0){
              cout << "Division by zero is not possible. Skipping this operation.\n";
              continue;  // Go back to menu
            } else{
              result = num1 / num2;
            }
            break;
          case 900:
            cout<<"See you soon, "<<name<<"!\n\n";
            break;
          default:
            cout<<"\nInvalid choice! Please try again\n";
            continue;
        }

        if (choice != 900){
          cout<<fixed<<setprecision(2); //format result before checking
          cout<<"What is "<<num1<<" "<<operation<<" "<<num2<<" = ? ";
          cin>>user_answer;
          // check answer
          if(abs(user_answer - result) < EPSILON){
            cout<<"🥳 Bravoo! You're a Genius.\n\n";
          }else{
            cout << "Oops, that's not correct. The correct answer was "<< result << ".\n"<<endl;
          }

          cout<<"Press any Key to continue...";
          cin>>more_practice;
          cin.ignore();
          system("clear");
        }
    }

  }while(choice != 900);

// end program
  return 0;
}
