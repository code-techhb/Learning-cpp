// Houlaymatou B. | @code_techhb

// -------------------------
// Chap 13: Advanced Files I/O operations
// Goal 🎯: Practice I/O in files

/*Programming Challenges - Problem 1: File Encryption
File encryption is the science of writing the contents of a file in a secret code.   Your encryption program should work like a filter reading the contents of one file, modifying each character in the input file into a code, and then writing the coded characters out to a second file.  The second file will be a version of the first file but written in a secret code.
In Notepad or something similar, you will create a file with text in it.  It should be several lines long.  Your program should read the file character by character and make some change to the character before writing that character to a second new encrypted file.
*/ 

// ------------------------- code ------------------------------
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Function prototype
void encrypt(ifstream &inputFile, ofstream &outputFile, int secretNumber);

// ------------------------- main program ------------------------------
int main() {
  // variables declaration
  string inputFileName = "input.txt";
  string outputFileName = "encrypted.txt";

  // Open files using constructors
  ifstream inputFile(inputFileName);
  ofstream outputFile(outputFileName);

  if (!inputFile) {
    cerr << "Error 🚨: Unable to open input file: " << inputFileName << endl;
    return 1;
  }
  if (!outputFile) {
    cerr << "Error 🚨: Unable to create output file: " << outputFileName << endl;
    return 1;
  }

  // Prompt user
  int secretNumber;
  cout << "\n\nHi There, \nEnter the secret number for encrypting your file: ";
  while (!(cin >> secretNumber)) {
    cin.clear(); 
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Invalid input 🚨.\nPlease enter an integer: ";
  }

  // Edge case
  if (secretNumber % 26 == 0) {
    cout << "\nWarning ⚠️: The secret number you entered is a multiple of 26, so it will be treated as 18 for encryption.\nDon't forget to keep 18 secret 🤫 and ONLY share it with the recipient of your message!!"<< endl;
    secretNumber = 18; 
  }
  // handle negative int
  secretNumber = (secretNumber % 26 + 26) % 26;

  // Call function
  encrypt(inputFile, outputFile, secretNumber);
 
  // Close files
  inputFile.close();
  outputFile.close();

  return 0;
}

// ---------------- Function definitions ---------------------
void encrypt(ifstream &inputFile, ofstream &outputFile, int secretNumber) {
  char ch;

  // Check if input file is empty
  if (inputFile.peek() == EOF) {
    cerr << "Error 🚨: Input file is empty." << endl;
    return;
  }

  // Read the file char by char
  while (inputFile.get(ch)) {
    char encryptedChar = ch;

    // Check if char is alphabetic
    if (isalpha(ch)) {
      if (isupper(ch)) {
        encryptedChar = 'A' + (ch - 'A' + secretNumber) % 26;
      } else if (islower(ch)) {
        encryptedChar = 'a' + (ch - 'a' + secretNumber) % 26;
        }
    }
    // Write the encrypted char to the output file
    outputFile.put(encryptedChar);
  }

  // get back to the user
  cout<<"\nEncryption ✅.\nCheck your files to look for `encrypted.txt`.\nSee you next time :)\n\n";
}

// -------------------------------------
//💡 to explore: could ask the user to enter the path to their inputfile and make the program more interactive :)