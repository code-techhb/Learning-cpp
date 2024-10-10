/* 
Houlaymatou B. | @code_techhb
Project 1: Random Number Guessing Game
*/ 

// ------------------------ Code -------------------------------
#include <iostream>
#include <cctype>
#include <cstdlib> // Header file to get srand() function
#include <ctime> // Header file needed to use time
using namespace std;

int main(){
  // variable 
  int guess, random_num, counter;
  const int MIN_VALUE = 1, MAX_VALUE =150;
  char play_again;
  
  // seed for random number generation
  unsigned seed;
  seed = time(0); // Using the time function to get a new seed anytime the program runs
  srand(seed);

  // outer loop for play again option
  do {
    counter=0;

    // number between 1 - 150
    random_num = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;
    // cout<<"🚨Testing Purposes:  "<<random_num;

    // prompt user
    cout<<"\nWelcome to the Guessing Game 😁\n";

    // Inner loop for guessing the random number
    do {
      cout<<"I am an integer between 1 and 150. Can you guess who I AM 🤓?\nType here: ";
      cin>>guess;
      counter++;

      // comparing guess and random num
      if (guess > random_num){
        cout<<"Too high! Try again\n\n";
      } else if (guess < random_num){
        cout<<"Oopss! Too Low. Try again\n\n";
      } else {
        cout<<"Congratulations🎊! You got it with "<<counter<<" attempts.\n\n";
      }
    }while(guess!=random_num);

    // play again option
    cout<<"Would you like to play again 😁? Type (Y for yes or N for no): ";
    cin>>play_again;
    system("clear"); //clear the console for new game

  }while(tolower(play_again)=='y');

  cout<<"Alright! See ya later ✋\n\n";

  return 0;
}