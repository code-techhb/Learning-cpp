// Houlaymatou B. | @code_techhb

// -------------------------
// Chap 4: Conditional statements
// Goal 🎯: Practice if/else and switch statements

/*Programming Challenges - Problem 3: Book Club Points 
An online book club awards points to its customers based on the number of books purchased each month. Points are awarded as follows:

Books Purchased	Points Earned
0	0
1	5
2	15
3	30
4 or more	50
Write a program that asks the user to enter the number of books purchased this month and then displays the number of points awarded.
*/
// -------------------------
#include<iostream>
using namespace std;

int main(){
  // variable declaration
  int number_of_books, points_gained;
  // Constants for points
  const int POINTS_0_BOOKS = 0;
  const int POINTS_1_BOOK = 5;
  const int POINTS_2_BOOKS = 15;
  const int POINTS_3_BOOKS = 30;
  const int POINTS_4_OR_MORE_BOOKS = 50;

  // prompt user
  cout<<"\nWelcome to your favorite Book club 📚!\nTell us how many books you've purchased this month 🤓? ";
  cin>>number_of_books;

  // determine points earned
  switch(number_of_books){
    case 0:
      points_gained=POINTS_0_BOOKS;
      cout<<"This month, you've earned "<<points_gained<<" points!\nPurchase a book today and earn your first points 🤩!\n\n";
      break;
    case 1:
      points_gained=POINTS_1_BOOK;
      cout<<"This month, you've earned "<<points_gained<<" points!\nKeep on reading 🤩!\n";
      break;
    case 2:
      points_gained=POINTS_2_BOOKS;
      cout<<"This month, you've earned "<<points_gained<<" points.\nFantastic Job! Keep it up🎉\n";
      break;
    case 3:
      points_gained=POINTS_3_BOOKS;
      cout<<"This month, you've earned "<<points_gained<<" points.\nWOW! You rock at this 🌟📚Keep reading🎉\n";
      break;
   default:
      points_gained=POINTS_4_OR_MORE_BOOKS;
      cout<<"This month, you've earned "<<points_gained<<" points.\nYou're a real bookworm 📚🦄!\n";
      break;
  }
   cout << "Thank you for being a part of our Book Club! Happy reading! 📖\n\n";
}