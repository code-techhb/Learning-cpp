// Houlaymatou B. | @code_techhb

// -------------------------
// Chap 8: Arrays  
// Goal 🎯: Practice Class & Object  & Arrays

/*Programming Challenges - Problem 2: Perfect Scores
Write a modular program that accepts up to 20 integer test scores in the range of 0 to 100 from the user and stores them in an array. Then main should report how many perfect scores were entered (i.e., scores of 100), using a value-returning countPerfect function to help it. Hint: Have the program count the scores as they are entered. Your program may need this information later.     
*/
// ------------------------- code ------------------------------
#include <iostream>
using namespace std;

// function prototypes
void getScores(int [], int );
int countPerfect(int [], int );

// ------------------------- main ------------------------------
int main(){
  // variable declaration
  int size = 5, perfect_scores;
  int scores[size] ;

  // function call
  getScores(scores, size);
  perfect_scores = countPerfect(scores, size);

  // output
  cout<<"There are "<<perfect_scores<<" students who got Perfect scores ( 100/100 )!\n\n";
  return 0;
}

// ------------------------- Function defintion ------------------------------
// Function to get scores
void getScores(int arr[], int size){
  int counter=0, perfect_count=0;
  cout<<"\nPerfect Score Finder\nYou're about to enter 5 students Scores\n\n";
 do {
    cout << "Please enter student " << counter + 1 << " score: ";
    cin >> arr[counter];

    // Check if the score is outside the range 0-100
    if (arr[counter] < 0 || arr[counter] > 100) {
      cout << "Invalid input. Please enter scores only between 0 and 100.\n";
    } else {
        // Valid input, proceed to the next score
        counter++;
    }
  } while (counter < size);
}

// Function to count perfect scores (100) in the array
int countPerfect(int arr[], int size) {
    int perfectCount = 0;
    for (int i = 0; i < size; ++i) {
        if (arr[i] == 100) {
            perfectCount++;
        }
    }
    return perfectCount;
}
