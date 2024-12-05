// Houlaymatou B. | @code_techhb

// -------------------------
// Chap 13: Advanced Files I/O operations
// Goal 🎯: Practice I/O in files

/*Programming Challenges - Problem 2: File Decryption
Write a program that decrypts the file produced by the program in problem_1.cpp. The decryption program should read the contents of the coded file, restore the information to its original state and write it to another (third) file.  Example: If you added 10 to each character in the first program, subtract 10 from each character in this program.  (The output file of program 2 should be the same as the input file of program 1)
*/ 

// ------------------------- code ------------------------------
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Function prototype
void decrypt(ifstream &inputFile, ofstream &outputFile, int secretNumber);

// ------------------------- main program ------------------------------
int main() {
  // Variable declaration
  string encryptedFileName = "encrypted.txt";
  string decryptedFileName = "decrypted.txt";

  // Open files
  ifstream inputFile(encryptedFileName);
  ofstream outputFile(decryptedFileName);

  if (!inputFile) {
    cerr << "Error 🚨: Unable to open encrypted file: " << encryptedFileName << endl;
    return 1;
  }

  if (!outputFile) {
    cerr << "Error 🚨: Unable to create decrypted file: " << decryptedFileName << endl;
    return 1;
  }

  // Prompt user
  int secretNumber;
  cout << "\n\nHi There, \nEnter the secret number your friend shared with you to decrypt her message correctly: ";
  while (!(cin >> secretNumber)) {
    cin.clear(); 
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Invalid input 🚨.\nPlease enter an integer: ";
  }
  // handle negative int
  secretNumber = (secretNumber % 26 + 26) % 26;

  // Call function
  decrypt(inputFile, outputFile, secretNumber);

  // Close files
  inputFile.close();
  outputFile.close();

  return 0;
}

// ---------------- Function definitions ---------------------
void decrypt(ifstream &inputFile, ofstream &outputFile, int secretNumber) {
  char ch; 

  // Check if input file is empty
  if (inputFile.peek() == EOF) {
    cerr << "Error 🚨: Input file is empty." << endl;
    return;
  }

  while (inputFile.get(ch)) {
    char decryptedChar = ch;

    if (isalpha(ch)) {
      if (isupper(ch)) {
        decryptedChar = 'A' + (ch - 'A' - secretNumber + 26) % 26;
      } else if (islower(ch)) {
        decryptedChar = 'a' + (ch - 'a' - secretNumber + 26) % 26;
      }
    }
    // Write the decrypted character to the output file
    outputFile.put(decryptedChar);
  }
  // get back to the user
  cout<<"\nDecryption ✅.\nCheck your files to look for `decrypted.txt`.\nSee you next time :)\n\n";
}

// -------------------------------------
//💡 to explore: Combine the two programs and allow user to have the option to encrypt or decrypt using one program :)
