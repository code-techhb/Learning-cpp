// Houlaymatou B. | @code_techhb

// -------------------------
// Chap 10: Pointers
// Goal 🎯: Practice Pointers and Dynamic memory allocation

/*Programming Challenges - Problem 1: Median
In statistics, the median of a set of values is the value that lies in the middle when the values are arranged in sorted order.   If the set has an even number of values, the median is the average of the two middle values.  
Your program should start with two arrays of integers containing the following values:
Even numbered array:  17 32 45 68 99 101 67 89 22 27
Odd numbered array:   17 32 45 68 99 101 67 89 22 
Using a sort function of your choice, first sort the arrays.  
NOTE:  you may use the Standard Template Library sort function or your own sort function.  
Then, write a function that determines the median of a sorted array.   The function should take an array of numbers and an integer indicating the size of the array and return the median of the values in the array.   The same function should be called twice – once for the even array and once for the odd array.
Your program should also have a printArray function that can be used to print the sorted array. (It should be called twice, once for each array).   It should be passed the array and its size.
*/
// ------------------------- code ------------------------------
#include <iostream>
#include <algorithm> 
using namespace std;

// function prototype
void sortArray(int*, int);
int medianFinder(int* , int);
void printArray(int* , int);

// ---------------- main program ---------------------
int main(){
  // variable declaration
  int evenArr[] = {17, 32, 45, 68, 99, 101, 67, 89, 22, 27};
  int oddArr[] = {17, 32, 45, 68, 99, 101, 67, 89, 22};
    
  // compute array size
  int evenSize = sizeof(evenArr) / sizeof(evenArr[0]);
  int oddSize = sizeof(oddArr) / sizeof(oddArr[0]);

  // sort arrays
  sortArray(evenArr, evenSize);
  sortArray(oddArr, oddSize);

  // print sorted arrays
  cout << "\nSorted even array: ";
  printArray(evenArr, evenSize); 
  cout << "Sorted odd array: ";
  printArray(oddArr, oddSize);

  // find and print the medians 
  cout << "\nMedian of even array: " << medianFinder(evenArr, evenSize) << endl;
  cout << "Median of odd array: " << medianFinder(oddArr, oddSize) << endl<<endl;

  return 0;
}

// ---------------- Function definitions ---------------------
void sortArray(int *pArr, int size){
  sort(pArr, pArr+size);
};

void printArray(int *pArr, int size) {
  for (int i = 0; i < size; i++) {
    cout << *(pArr + i) << " ";
  }
  cout << endl;
}

int medianFinder(int *pArr, int size) {
  int medianVal;
  if (size % 2 == 0) { 
    medianVal = (*(pArr + size / 2 - 1) + *(pArr + size / 2)) / 2.0;
  } else { 
    medianVal = *(pArr + size / 2);
  }
  return medianVal;
}
