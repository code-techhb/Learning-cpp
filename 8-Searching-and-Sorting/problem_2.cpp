// Houlaymatou B. | @code_techhb

// -------------------------
// Chap 9: Search and sorting Algorithms
// Goal 🎯: Practice Linear, binary search and bubble, selection sorting

/*Programming Challenges - Problem 2: Linear Search
Write a program that lets the user enter a charge account number. The program should determine if the number is valid by checking for it in the following list:

5658845	4520125	7895122	8777541	8451277	1302850
8080152	4562555	5552012	5050552	7825877	1250255
1005231	6545231	3852085	7576651	7881200	4581002

Initialize a one-dimensional array with these values. Then use a simple linear search to locate the number entered by the user. If the user enters a number that is in the array, the program should display a message saying the number is valid. If the user enters a number not in the array, the program should display a message indicating it is invalid.
*/
// ------------------------- code ------------------------------
#include <iostream>
using namespace std;

void linearSearch(int [] , int, int);

int main(){
  // variable declaration
  const int size = 18;
  int array[size] ={5658845,	4520125,	7895122,	8777541,	8451277,	1302850,
                8080152,	4562555,	5552012,	5050552,	7825877,	1250255,
                1005231,	6545231,	3852085,	7576651,	7881200, 4581002};
  int number;

  cout<<"\nWelcome\nEnter a charge account number: ";
  cin>>number;

  // function call
  linearSearch(array, size, number);

  return 0;
}

// ------------------------- Function defintion ------------------------------
void linearSearch(int arr[], int size, int target){
  bool found=false;

  for(int i=0; i<size; i++){
    if (arr[i] == target){
      cout<<"The account number is valid!\n";
      found = true;
      break;
    } 
  }

  if (!found) {
    cout << "The account number is invalid!\n";
  }
}