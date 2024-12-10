#ifndef NUMBERS_H 
#define NUMBERS_H

#include <string>
using namespace std;

class Numbers {
  private:
    int number; 

    // Static arrays and strings
    static string lessThan20[];
    static string tens[];      
    static string hundred;      
    static string thousand;

  public:
    // Constructor to initialize the number.
    Numbers(int num);

    // member function
    void print();
};

#endif
