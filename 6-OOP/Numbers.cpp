#include "Numbers.h"
#include <iostream>
using namespace std;

// ------------------------- Static variables ------------------------------
string Numbers::lessThan20[] = {"zero", "one", "two", "three", "four", "five", "six",
                                "seven", "eight", "nine", "ten", "eleven", "twelve",
                                "thirteen", "fourteen", "fifteen", "sixteen", 
                                "seventeen", "eighteen", "nineteen"};
string Numbers::tens[] = {"", "", "twenty", "thirty", "forty", "fifty", 
                          "sixty", "seventy", "eighty", "ninety"};
string Numbers::hundred = "hundred";
string Numbers::thousand = "thousand";

// ------------------------- Constructor ------------------------------
Numbers::Numbers(int num) {
  if (num < 0 || num > 9999) {
    cout << "Error 🚨: Number out of range!" << endl;
    exit(1);
  }
  number = num;
}

// ------------------------- Print Function------------------------------
void Numbers::print() {
  if (number == 0) { 
    cout << lessThan20[0] << endl;
    return;
  }

  int tempNumber = number;
  //thousands place.
  if (tempNumber / 1000 > 0) {
    cout << lessThan20[tempNumber / 1000] << " " << thousand << " ";
    // Remove thousands place.
    tempNumber %= 1000; 
  }

  // hundreds place.
  if (tempNumber / 100 > 0) {
    cout << lessThan20[tempNumber / 100] << " " << hundred << " ";
    tempNumber %= 100; 
  }

  // tens and ones places.
  if (tempNumber >= 20) {
    cout << tens[tempNumber / 10] << " ";
    tempNumber %= 10; 
  }

  if (tempNumber > 0) { 
    cout << lessThan20[tempNumber] << " ";
  }

  cout << endl;
}
