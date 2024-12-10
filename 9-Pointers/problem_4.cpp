// Houlaymatou B. | @code_techhb

// -------------------------
// Chap 10: Pointers
// Goal 🎯: Practice Pointers and Dynamic memory allocation

/*Programming Challenges - Problem 4: Pie a la Mode
In statistics the mode of a set of values is the value that occurs most often. Write a program that determines how many pieces of pie most people eat in a year. Set up an integer array that can hold responses from 30 people. For each person, enter the number of pieces they say they eat in a year. Then write a function that finds the mode of these 30 values. This will be the number of pie slices eaten by the most people. The function that finds and returns the mode should accept two arguments, an array of integers, and a value indicating how many elements are in the array.
*/
// ------------------------- code ------------------------------
#include <iostream>
using namespace std;

void swap(int &, int &);
void selectionSort(int [], int);
void printArray(int [] , int );
int findMode(int *, int);

int main(){
  // variable declaration
  int SIZE = 10;
  int pieSlices[SIZE];

  // prompt users
  cout<<"\n🥧 Welcome to pie mode 🥧\n";
  for (int i=0; i<SIZE; i++){
    cout<<"Enter the number of pie eaten by person #"<<i+1<<" this year: ";
    cin >> pieSlices[i];

    // input validation
    while (pieSlices[i] < 0) {
      cout << "Please enter a non-negative number: ";
      cin >> pieSlices[i];
    }
  }

  // function call
  cout << "\nUnsorted array: ";
  printArray(pieSlices, SIZE);
  selectionSort(pieSlices, SIZE);
  cout << "Sorted array: ";
  printArray(pieSlices, SIZE);
  cout << "\nThe most common number of pie slices eaten is: " << findMode(pieSlices, SIZE) << endl;
  return 0;
}

// ---------------- Function definitions ---------------------
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void selectionSort(int arr[], int size) {
  // Iterate through the array
  for (int i = 0; i < size - 1; i++) {
    int minIndex = i;
        
    for (int j = i + 1; j < size; j++) {
      // Update minIndex if we find a smaller element
      if (arr[j] < arr[minIndex]) {
        minIndex = j;
      }
    }
        
    if (minIndex != i) {
      swap(arr[i], arr[minIndex]);
    }
  }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}


int findMode(int *arr, int size){
  int maxCount = 0;
  int mode = *(arr+0);

  // Check each element
  for (int i = 0; i < size; i++) {
    //set count for curr el
    int count = 0; 
        
    // Count frequency of curr el
    for (int j = 0; j < size; j++) {
      if (*(arr+j) == *(arr+i)) {
        count++;
      }
    }
        
    if (count > maxCount) {
    maxCount = count;
    mode = arr[i];
    }
  }
  
  return mode;
}