// Houlaymatou B. | @code_techhb

// -------------------------
// Chap 6: Functions
// Goal 🎯: Practice function prototype, definition and call.

/*Programming Challenges - Problem 5: Drop lowest Score
Write a program that calculates the average of a group of test scores, where the lowest score in the group is dropped. It should use the following functions:

void getScore() should ask the user for a test score, store it in a reference parameter variable, and validate that it is not lower than 0 or higher than 100. This function should be called by main once for each of the five scores to be entered.

void calcAverage() should calculate and display the average of the four highest scores. This function should be called just once by main and should be passed the five scores.

double findLowest() should find and return the lowest of the five scores passed to it. It should be called by calcAverage, which uses the function to determine which one of the five scores to drop.
*/
// ------------------------- code ------------------------------
#include <iostream>
#include <iomanip>
using namespace std;

// Function prototypes
void getScore(double & );
void calcAverage(double, double, double, double, double );
double findLowest(double, double, double, double, double);

// main
int main(){
  // variable declaration
  double score1, score2, score3, score4, score5 ;

  // welcome msg
  cout<<"\n\n🎉Bravoo for making it to the end of the semester!\nLet's compute your final score 🤓\n";

  // call score getter
  getScore(score1);
  getScore(score2);
  getScore(score3);
  getScore(score4);
  getScore(score5);

  // call average calculator
  calcAverage(score1, score2, score3, score4, score5);


  return 0;
}

// function definiton
void getScore(double &studentScore){
  do{
    cout<<"Please enter a test score: ";
    cin>>studentScore;

     if(studentScore < 0 || studentScore > 100) {
      cout << "Invalid score. Please enter a score between 0 and 100." <<endl<<endl;
    }
  }while(studentScore < 0 || studentScore > 100);
  
}

double findLowest(double s1, double s2, double s3, double s4, double s5){
  if (s1 < s2 && s1<s3 && s1< s4 && s1 < s5){
    return s1;
  } else if (s2 < s1 && s2<s3 && s2< s4 && s2 < s5){
    return s2;
  } else if (s3 < s1 && s3<s2 && s3< s4 && s3 < s5){
    return s3;
  } else if (s4 < s1 && s4<s2 && s4< s3 && s4 < s5){
    return s4;
  } else {
    return s5;
  }
  }

void calcAverage(double s1, double s2, double s3, double s4, double s5){
  double average , lowestScore;

  // call find lowest 
  lowestScore = findLowest(s1, s2, s3, s4, s5);

  // drop
  if (lowestScore == s1){
    average = (s2 + s3 + s4 + s5)/4;
  } else if (lowestScore == s2){
    average = (s1 + s3 + s4 + s5)/4;
  }else if (lowestScore == s3){
    average = (s1 + s2 + s4 + s5)/4;
  } else if (lowestScore == s4){
    average = (s1 + s2 + s3 + s5)/4;
  }else {
    average = (s1 + s2 + s3 + s4)/4;
  }

  // output
  cout<<fixed << setprecision(2);
  cout<<"Your average score is: "<<average<<"\nKeep it up!\n\n";
}
