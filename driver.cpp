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
#include "miniGit.hpp"
#include <filesystem>

using namespace std;
namespace fs = std::filesystem;

/* 
------------------------------------------------------------

  To execute program in terminal use the following:

  g++ -std=c++17 driver.cpp miniGit.cpp

------------------------------------------------------------
*/ 

/*

  Terminal Process for adding to gitHub:

    1) Check git status using git status
      - add all files that were changed using git add (filename)
    2) Commit files to the git using Git commit -m "Insert comments here"
    3) Git push -u origin main

*/


void menu();

int main(){
Git testGit; //test git 
//doublyNode starterNode;
//First, we want to prompt the user to initialize a new repository.
char initialize; //char for below
cout << "Would you like to initialize a new repository? (Y/N) -- Pick Yes" << endl;
cin >> initialize;
if (initialize == 'Y' || 'y'){ //add a new "blank" doubly node to begin our list
    testGit.starterNode->commitNumber = 0;
    testGit.starterNode->head = NULL; //this is the head of the singly linked list
    testGit.starterNode->next = NULL; //pointer to the next node in doubly linked list (next commit)
    testGit.starterNode->previous = NULL; //pointer to previous node in doubly linked list (this is the first node, so this will always be NULL for this node)
    fs::create_directory(".minigit"); // create a new directory
}
else{ //create anyways or quit program..?
    testGit.starterNode->commitNumber = 0;
    testGit.starterNode->head = NULL; //this is the head of the singly linked list
    testGit.starterNode->next = NULL; //pointer to the next node in doubly linked list (next commit)
    testGit.starterNode->previous = NULL; //pointer to previous node in doubly linked list (this is the first node, so this will always be NULL for this node)
    fs::create_directory(".minigit"); // create a new directory

}
cout << "A new repository has been created." << endl;
cout << "---Current commit number: " << testGit.starterNode->commitNumber << endl;
cout << "---Current path of singly linked list attached to StarterNode: " << testGit.starterNode->head << " (NULL)"<< endl;
cout << "---StarterNode's next node: " << testGit.starterNode->next << " (NULL)" << endl;
cout << "---StarterNode's previous node: " << testGit.starterNode->previous << " (NULL)" << endl;
doublyNode * secondNode = new doublyNode; //this is the process of creating a new doubly node after a commit, then we can assign this into the doubly list from the access of the starter node

/* ---------- Below is everything involved with our menu, above is initializing our new repository ---------- */

 int option = 0;
  // declare strings as needed
  while(option != 5) {
    menu();
   cin >> option;
    
    switch(option) {
      // adding a file
      case 1: {
      string fileName;
      cout << "Enter a file name: " << endl;
      cin >> fileName;

      //check if file exists in working directory
      if (fs::exists(fileName)){
        cout << endl;
        cout << "Found file in working directory" << endl;
        cout << endl;
        //file exists, continue
      }
      else{ //file does not exist, break out to menu
        cout << endl;
        cout << "-----File does not exist in working directory. Returning to menu.-----" << endl;
        cout << endl;
        break;
      }


       // add conditionals to see if file name already exists
      // cout << "step debug one" << endl;
      singlyNode * traverser; //traverser node to check if filename already exists
      traverser = testGit.starterNode->head; //set to head of SLL
      bool found = false; //boolean for if file is found or not

      //Below while loop traverses the singly linked list checking to see if the file already exists
        while (traverser != nullptr){
          // cout << "step debug 1.5" << endl;
          // cout << "first while loop files::: " << traverser->fileName << endl;
          // if (traverser != NULL){
          //   cout << "(debug --- Before execution head file): " << traverser->fileName << endl;
          // }
          if (traverser->fileName == fileName){
            //cout << "debug --- found a file match" << endl;
            found = true;
            break;
          }
            // if (traverser->next->fileName == fileName){
            //   found = true;
            //   break;
            // }
            // if (traverser->next == nullptr){
            //   break;
            // }
            traverser = traverser->next;
            //bool found = false;
        }
        //cout << "step debug two" << endl;
            if (found == true){ //a file with the same name has been found
              cout << endl;
              cout << "--Filename already exists in list,  a file by the same name cannot be added twice. Returning to menu.--" << endl;
              cout << endl;
              break;
            }
            else{ //add the file
              cout << endl;
              cout << "filename is new. Adding to the SLL..." << endl;
              testGit.addFile(fileName);
            }
            //Below prints the singly linked list after a node is added
                if (testGit.starterNode->head != NULL){
                  singlyNode * theCoutTraverser = testGit.starterNode->head;
                  cout << endl;
                  cout << "SLL --> ";
                    while (theCoutTraverser != nullptr){
                      cout << theCoutTraverser->fileName << " --> ";
                      theCoutTraverser = theCoutTraverser->next;
                    }
                    cout << "NULL";
                    cout << endl;
                }
                else{
                  cout << "singly linked list head is still NULL" << endl;
                }
        traverser = testGit.starterNode->head; //reset traverser
        cout << endl;
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
             break;
            } else {
             // DON'T PERFORM FUNCTION
             break;
            }
       
        break;
      }
      
      // quit the menu
      case 5: {
        cout << "Quitting and closing directory..." << endl;
        break;
      }

      // invalid input
      default:
       cout << "Invalid Input :(" << endl;
       break;

    }
  }
    cout << "Goodbye :)" << endl;
    //when we quit we will remove the minigit directory created
    fs::remove_all(".minigit"); // removes a directory and its contents
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

