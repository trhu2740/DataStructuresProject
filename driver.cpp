// CS2270 Spring 2021
// Troy Husted
// Final Project
// Driver.cpp

#include <iostream>
#include <iomanip>
#include <string>
#include <string.h>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <vector>
#include "miniGit.cpp"

using namespace std;


void displayMenu();

int main(){
 int option = 0;
  // declare strings as needed
  while(option != 5) {
    displayMenu();
    
    switch(option) {
      case 1: {
        // add test cases and declare functions
        break;
      }

      case 2: {
        // add test cases and declare functions
        break;
      }

      case 3: {
        // add test cases and declare functions
        break;
      }

      case 4: {
        // add test cases and declare functions
        break;
      }
      
      case 5: {
        cout << "Quitting..." << endl;
        break;
      }

    }
  }
    cout << "Goodbye!" << endl;
    return 0;
}
}


void displayMenu() {
  cout << "What would you like to do? Select a numerical option." << endl;
  cout << "1. Add files to the current commit" << endl;
  cout << "2. Remove files from the current commit" << endl;
  cout << "3. Commit changes" << endl;
  cout << "4. Check out a specific version based on a unique commit number" << endl;
  cout << "5. Quit" << endl;
}
