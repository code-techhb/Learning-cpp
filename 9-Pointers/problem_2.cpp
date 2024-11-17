// Houlaymatou B. | @code_techhb

// -------------------------
// Chap 10: Pointers
// Goal 🎯: Practice Pointers and Dynamic memory allocation

/*Programming Challenges - Problem 2: Movie Data
Write a program that will be used to gather statistical data about the number of movies college students see in a month.  The program should ask the user how many students were surveyed and dynamically allocate an array of that size.  The program then should allow the user to enter the number of movies each student has seen.  It should then sort the scores and calculate the average.
*/
// ------------------------- code ------------------------------
#include <iostream>
#include <algorithm>
using namespace std;

// function prototype
void getData(int *, int );
void sortData(int *, int );
void displayData(const int * , int );
double calcAverage(const int * , int );

// ------------------------- main program ------------------------------
int main() {
  // variable declaration
  int numStudents;

  // prompt user
  cout << "Enter the number of students surveyed: ";
  cin >> numStudents;

  // validate input
  while (numStudents <= 0) {
    cout << "Number of students must be a positive integer. Please try again: ";
    cin >> numStudents;
  }

  // dynamic memory allocation
  int *pMovies = new int[numStudents];

  // get data
  getData(pMovies, numStudents);
  // sort data
  sortData(pMovies, numStudents);

  // display sorted data
  cout << "\nNumber of Movies Watched\n------------------------" << endl;
  displayData(pMovies, numStudents);

  // compte avg
  double average = calcAverage(pMovies, numStudents);
  cout << "---------\nAverage: " << average << endl;

  // Free DA memory
  delete[] pMovies;

  return 0;
}

// ---------------- Function definitions ---------------------
void getData(int *pArr, int size) {
  for (int i = 0; i < size; ++i) {
    cout << "Enter the number of movies student " << (i + 1) << " watched: ";
    cin >> pArr[i];

    // validate input
    while (pArr[i] < 0) {
      cout << "Movies watched must be a non-negative integer. Please try again: ";
      cin >> pArr[i];
    }
  }
}

void sortData(int *pArr, int size) {
  sort(pArr, pArr + size);
}

void displayData(const int *pArr, int size) {
  for (int i = 0; i < size; ++i) {
    cout << pArr[i] << endl;
  }
}

double calcAverage(const int *pArr, int size) {
  double sum = 0;
  for (int i = 0; i < size; ++i) {
    sum += pArr[i];
  }
  return sum / size;
}

