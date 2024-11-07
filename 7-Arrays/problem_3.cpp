// Houlaymatou B. | @code_techhb

// -------------------------
// Chap 8: Arrays  
// Goal 🎯: Practice Class & Object  & Arrays

/*Programming Challenges - Problem 3: Larger Than n
Create a program with a function that accepts three arguments: an integer array, an integer size that indicates how many elements are in the array, and an integer n. The function should display all of the numbers in the array that are greater than the number n.   
*/
// ------------------------- code ------------------------------
#include <iostream>
using namespace std;

void largerThan(int [], int , int );

int main(){
  // variable declaration
  int size, n;
 
  cout<<"\nHow many numbers do you want to enter: ";
  cin>>size;

  // declare array
  int numbers[size];

  for(int i=0; i<size; i++){
    cout<<"Enter element #"<<i+1<<" :";
    cin>>numbers[i];
  }
  cout<<"Give us a number: ";
  cin>>n;

  // function call
  cout<<"Numbers greater than from the array "<<n<<":\n";
  largerThan(numbers, size, n);

  return 0;
}
// ------------------------- Function defintion ------------------------------
void largerThan(int arr[], int size, int n){
  int counter=0;
  bool found=false;
  while(counter < size){
    if (arr[counter] > n){
      cout<<arr[counter];
      found = true;
      cout<<" , ";
    }
    counter++; 
  }
  if (!found) {
    cout << "None";
  }
  cout<<"\n";
}