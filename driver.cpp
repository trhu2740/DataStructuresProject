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
             // 1. check if file version already exists in minigit 
                  // a. No -> copy file from current directory into minigit, new file name should be from node's fileVersion member
                  // b. Yes -> check if current directory file has been changed
                       // i. if file is unchanged, do nothing
                       // ii. if file is changed, copy file from current directory to minigit and assign name with version number, update SLL node name to version number
             // 2. create new DLL node of repo
                   // copy of SLL moved to DLL node
                   // commit number of DLL node increment by 1
       // declare any necessary functions
        break;
      }

      // checking out a specific version based on a unique commit number
      case 4: {
       int commitNumber;
       cout << "Enter a commit number: " << endl;
       cin >> commitNumber;
       // if commit number = valid, then files should be overwritten by corresponding files in minigit
            char yesNo;
            cout << "Warning: You will lose your local changes if you check out from a different version before making a commit with your current local changes." << endl;
            cout << "Do you still want to do this? (Y/N)" << endl;
             cin >> yesNo;
            if(yesNo == 'Y') {
              // declare any necessary functions
             // search DLL for a node with matching commit number
            } else {
             // DON'T PERFORM FUNCTION
             break;
            }
       
        break;
      }
      
      // quit the menu
      case 5: {
        cout << "Quitting..." << endl;
        break;
      }
      
      // invalid input
      default:
       cout << "Invalid Input :(" << endl;
       break;

    }
  }
    cout << "Goodbye :)" << endl;
    return 0;
}



void menu() {
  cout << "What would you like to do? Select a numerical option." << endl;
  cout << "1. Add files to the current commit" << endl;
  cout << "2. Remove files from the current commit" << endl;
  cout << "3. Commit changes" << endl;
  cout << "4. Check out a specific version based on a unique commit number" << endl;
  cout << "5. Quit" << endl;
}
