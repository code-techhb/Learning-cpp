// Houlaymatou B. | @code_techhb

// -------------------------
// Chap 3: Expressions and Interactivity 
// Goal 🎯: Input-Output formated

/*Programming Challenges - Problem 3: male and female percentages
Write a program that asks the user for the number of males and number of females registered in a class. The program should then compute and report what percentage of the students are males and what percentage are females. Convert the decimal result of each calculation to percent form and display it with two decimal points. The two values should add up to 100.00 percent.
*/
// -------------------------

#include <iostream>
#include <iomanip>
using namespace std;

int main(){
  // variable declaration
  float number_of_female, number_of_male, total_number_of_students;
  float percentage_of_male, percentage_of_female;

  // get input from user;
  cout<<"\nHey yall,\nIn this class, how many students are\n";
  cout<<"male: ";
  cin>>number_of_male;
  cout<<"female: ";
  cin>>number_of_female;

  // Computation
  total_number_of_students=number_of_male + number_of_female;
  percentage_of_female = (number_of_female / total_number_of_students)*100;
  percentage_of_male = (number_of_male / total_number_of_students)*100;
  cout<<"The percentage of females in this class is: "<<fixed<<setprecision(2)<<percentage_of_female<< "%\ and males is: "<<fixed<<setprecision(2)<< percentage_of_male<<"%.\n";
return 0;
}