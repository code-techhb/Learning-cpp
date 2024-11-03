// Houlaymatou B. | @code_techhb

// -------------------------
// Chap 9: Search and sorting Algorithms
// Goal 🎯: Practice Linear, binary search and bubble, selection sorting

/*Programming Challenges - Problem 1: Song playlist
You will write a program that allows the user to enter 10 songs and their artists into a playlist and will sort the entries by artist order.  The program should use a 10-element array of structure objects that holds two string variables:  artist and title.  Once the data has been read in and stored, it should sort the entries in ascending order by artist.  It should then display the sorted array with appropriate headings.
*/
// ------------------------- code ------------------------------
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// Constant for array size
const int SIZE_OF_ARR=10;

// define structure 
struct Song {
  string title;
  string artist;
};

// Function prototype
void getSongs(Song []); 
void selection_sort(Song []);
void printContent(Song []);

// ---------------- main program ---------------------
int main(){

  // variable declaration
  Song playlist[SIZE_OF_ARR];
  cout<<"\n\nList of your 10 favorite Songs to be sorted by artist name!";

  // function call
  getSongs(playlist);
  selection_sort(playlist);
  printContent(playlist);

  // end of program
  return 0;
}

// ---------------- Function definitions ---------------------
// Function to get song details from the user
void getSongs(Song arr[]){
  for(int i=0; i< SIZE_OF_ARR; i++){
    cout << "\nEnter details for song " << (i + 1) << ":" << endl;
    cout<<"Title: ";
    getline(cin, arr[i].title);
    cout<<"Artist: ";
    getline(cin, arr[i].artist);
  }
}

// Function to sort songs by artist name using selection sort
void selection_sort(Song arr[]){
  Song temp; 
  int min_index;
  for (int i=0; i<SIZE_OF_ARR-1; i++){
    min_index = i;
    // Find the minimum element in the unsorted part
    for (int j= i+1; j<SIZE_OF_ARR; j++ ){
      if (arr[min_index].artist > arr[j].artist){
        min_index = j;
      }
    }
   // Swap the Song objects
    temp = arr[i];
    arr[i] = arr[min_index];
    arr[min_index] = temp;
  }
}

// Function to print the sorted playlist
void printContent(Song arr[]) {
    cout << "\n\n";
    cout << setw(10) << right << "Playlist sorted alphabetically by artist\n" << endl;  // Centered title
    cout << left << setw(20) << "Artist" << "Title" << endl;
    cout << "===============================" << endl;
    // Loop through and display each song
    for(int i = 0; i < SIZE_OF_ARR; i++) {
        cout << left << setw(20) << arr[i].artist << arr[i].title << endl;
    }
}

