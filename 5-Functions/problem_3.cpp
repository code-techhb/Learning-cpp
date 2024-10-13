// Houlaymatou B. | @code_techhb

// -------------------------
// Chap 6: Functions
// Goal 🎯: Practice function prototype, definition and call.

/*Programming Challenges - Problem 2: Most Fuel Efficient Car
Three cars drive a 500 mile route. Write a program that inputs the car make and the number of gallons of fuel used by each car. After calling a calcMPG() function once for each car, have main determine and display which car was the most fuel efficient and how many miles per gallon it got. The calcMPG() function should be passed the distance driven and the gallons of gas used as arguments, and should return the miles per gallon obtained.
*/
// ------------------------- code ------------------------------
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// function prototype
double calcMPG(double, double);

int main(){
  // variable declaration
  const double DISTANCE = 500;
  string carMake, make1, make2, make3;
  double num_gallon, mpg1, mpg2, mpg3;

  // prompt user
  cout<<"\nHey, Welcome to your MPG calculator!\nPlease enter the following information for your three cars\n";
  for (int i=1; i<=3; i++){
    cout<<"\nCar #"<<i<<" Make: ";
    getline(cin,carMake);
    cout<<"The number of gallons used by car #"<<i<<": ";
    cin>>num_gallon;
    cin.ignore();

    switch (i)
    {
      case 1:
        mpg1 = calcMPG(DISTANCE, num_gallon);
        make1 = carMake;
        break;
      case 2:
        mpg2 = calcMPG(DISTANCE, num_gallon);
        make2 = carMake;
        break;
      case 3:
        mpg3 = calcMPG(DISTANCE, num_gallon);
        make3 = carMake;
        break;
    }
  }

  // output
  cout<<fixed<<setprecision(3);
  if ((mpg1 > mpg2) && (mpg1 > mpg3)){
    cout << "\nThe most fuel-efficient car was the " << make1 << ".\nIt had " << mpg1 << " miles per gallon.\n\n";
  } else if ((mpg2 > mpg1) && (mpg2 > mpg3)){
    cout << "\nThe most fuel-efficient car was the " << make2 << ".\nIt had " << mpg2 << " miles per gallon.\n\n";
  }else if ((mpg3 > mpg1) && (mpg3 > mpg2)){
    cout << "\nThe most fuel-efficient car was the " << make3 << ".\nIt had " << mpg3 << " miles per gallon.\n\n";
  } else {
        if (mpg1 == mpg2 && mpg1 == mpg3) {
            cout << "\nAll three cars have the same efficiency of " << mpg1 << " miles per gallon." << endl;
        } else {
            if (mpg1 == mpg2) {
                cout << "\nCar #1 and Car #2 have the same efficiency of " << mpg1 << " miles per gallon." << endl;
            }
            if (mpg1 == mpg3) {
                cout << "\nCar #1 and Car #3 have the same efficiency of " << mpg1 << " miles per gallon." << endl;
            }
            if (mpg2 == mpg3) {
                cout << "\nCar #2 and Car #3 have the same efficiency of " << mpg2 << " miles per gallon." << endl;
            }
        }
  }

  // end program
  return 0;
}

// function definition
double calcMPG(double distance, double gallon){
  return distance/gallon;
}