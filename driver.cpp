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


void menu();

int main(){
 int option = 0;
  // declare strings as needed
  while(option != 5) {
    menu();
    
    switch(option) {
      // adding a file
      case 1: {
       string fileName;
       cout << "Enter a file name: " << endl;
       cin >> fileName;
       // add conditionals to see if file name already exists
       // if file name exists, ask user to provide a valid name
       // remember: same name cannot be added twice
        // declare any necessary functions
        break;
      }

      // removing files
      case 2: {
       string fileName;
       cout << "Enter a file name: " << endl;
       cin >> fileName;
       // check if file exists, then delete the SLL node
        // declare any necessary functions
        break;
      }

      // committing changes
      case 3: {
       // traverse the entire SLL
             // check if file version already exists in minigit 
                  // No -> copy file from current directory into minigit, new file name should be from node's fileVersion member
                  // Yes -> check if current directory file has been changed
                       // if file is unchanged, do nothing
                       // if file is changed, copy file from current directory to minigit and assign name with version number, update SLL node name to version number
        // declare any necessary functions
        break;
      }

      // checking out a specific version based on a unique commit number
      case 4: {
        // declare any necessary functions
        break;
      }
      
      // quit the menu
      case 5: {
        cout << "Quitting..." << endl;
        break;
      }
      
      // invalid input
      default:
       cout << "Invalid Input" << endl;
       break;

    }
  }
    cout << "Goodbye :)" << endl;
    return 0;
}
}


void menu() {
  cout << "What would you like to do? Select a numerical option." << endl;
  cout << "1. Add files to the current commit" << endl;
  cout << "2. Remove files from the current commit" << endl;
  cout << "3. Commit changes" << endl;
  cout << "4. Check out a specific version based on a unique commit number" << endl;
  cout << "5. Quit" << endl;
}
