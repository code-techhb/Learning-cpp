// Houlaymatou B. | @code_techhb

// -------------------------
// Chap 7: OOP 
// Goal 🎯: Practice Class & Object 

/*Programming Challenges - Problem 4: Populations
Design a Population class that stores a current population, annual number of births, and annual number of deaths for some geographic area. The class should allow these three values to be set in either of two ways: by passing arguments to a three-parameter constructor when a new Population object is created or by calling the setPopulation, setBirths, and setDeaths class member functions. In either case, if a population figure less than 2 is passed to the class, use a default value of 2. If a birth or death figure less than 0 is passed in, use a default value of 0. The class should also have getBirthRate and getDeathRate functions that compute and return the birth and death rates. Write a short program that uses the Population class and illustrates its capabilities.
*/
// ------------------------- code ------------------------------
#include <iostream>
#include <iomanip>
using namespace std;

class Population {
  private:
    double current_population;
    double annual_births;
    double annual_deaths;

    double validatePopulation (double p){
      return (p<2) ? 2:p ;
    }
    double validateBirthandDeath (double count){
      return (count <0) ? 0:count;
    }

  public:
    // default constructor
    Population(double p=2, double b=0, double d=0){
      current_population = validatePopulation(p);
      annual_births = validateBirthandDeath(b);
      annual_deaths = validateBirthandDeath(d);
    }

    // setters
    void setPopulation(double p){
      current_population = validatePopulation(p);
    }
    void setBirths(double b){
      annual_births = validateBirthandDeath(b);
    }
    void setDeaths(double d){
      annual_deaths = validateBirthandDeath(d);
    }

    // computational functions
    double getBirthRates(){
      return annual_births/current_population;
    }
    double getDeathRates(){
      return annual_deaths / current_population;
    }

};

int main(){
  // variable declaration
  double pop, birth, death, birth_rate, death_rate;
  Population loli_city;

  // prompt user
  cout<<"\nWelcome to your demography calculator"<<endl;
  cout<<"Enter the following information"<<endl;
  cout<<"Current Population: ";
  cin>>pop;
  cout<<"Annual number of birth: ";
  cin>>birth;
  cout<<"Annual number of death: ";
  cin>>death;

  // methods
  loli_city.setPopulation(pop);
  loli_city.setBirths(birth);
  loli_city.setDeaths(death);
  
  // output
  cout<<"\nThe Birth rate this year is: "<<fixed<<setprecision(2)<<loli_city.getBirthRates()*100<<"%"<<endl;
  cout<<"The Death rate this year is: "<<fixed<<setprecision(2)<<loli_city.getDeathRates()*100<<"%"<<endl<<endl;
}