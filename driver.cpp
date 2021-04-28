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
int newCommitNumber = 0;
//fs::remove_all(".minigit"); // removes a directory and its contents
Git testGit; //test git 
//doublyNode starterNode;
//First, we want to prompt the user to initialize a new repository.
char initialize; //char for below
cout << "Would you like to initialize a new repository? (Y/N) -- Pick Yes" << endl;
cin >> initialize;

if (initialize == 'Y' || 'y'){ //add a new "blank" doubly node to begin our list
    testGit.starterNode->commitNumber = 0;
    //cout << "debug" << endl;
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
// cout << "A new repository has been created." << endl;
// cout << "---Current commit number: " << testGit.starterNode->commitNumber << endl;
// cout << "---Current path of singly linked list attached to StarterNode: " << testGit.starterNode->head << " (NULL)"<< endl;
// cout << "---StarterNode's next node: " << testGit.starterNode->next << " (NULL)" << endl;
// cout << "---StarterNode's previous node: " << testGit.starterNode->previous << " (NULL)" << endl;
//doublyNode * secondNode = new doublyNode; //this is the process of creating a new doubly node after a commit, then we can assign this into the doubly list from the access of the starter node

/* ---------- Below is everything involved with our menu, above is initializing our new repository ---------- */

doublyNode * head = testGit.starterNode;
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
                  cout << "Commit Number: " << testGit.starterNode->commitNumber << endl;
                  cout << " SLL --> ";
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
        //take user input
       string fileName;
       cout << "Enter a file name: " << endl;
       cin >> fileName;
       //create our node to traverse the linked list and find (or not find) the given filename
       singlyNode * traverser;
       traverser = testGit.starterNode->head;
       bool found = false;
       while (traverser != nullptr){
         if (traverser->fileName == fileName){
           found = true;
           break;
         }
         traverser = traverser->next;
       }
       //if we find the file, we remove it
       if (found == true){
         cout << endl;
         cout << "Found the file to be removed" << endl;
         cout << endl;
         testGit.removeFile(fileName);
       }
       //otherwise we exit to menu since the filename doesn't exist
       else{
         cout << "The filename does not exist in the singly linked list. Returning to menu." << endl;
         break;
       }
              //here is the cout statements as a visual to check that the nodes are actually being deleted
               if (testGit.starterNode->head != NULL){
                  singlyNode * theCoutTraverser = testGit.starterNode->head;
                  cout << endl;
                  cout << "Commit Number: " << testGit.starterNode->commitNumber << endl;
                  cout << " SLL --> ";
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
        cout << endl;
        break;
      }

      // committing changes
      case 3: {
        
        //cout << "step debug one - pre commitchanges" << endl;
        testGit.commitChanges();
        //cout << "step debug two - post commitchanges" << endl;

        /*
        //creating new doubly node
        doublyNode * additionalNode = new doublyNode;
        newCommitNumber = newCommitNumber +1;
        additionalNode->commitNumber = newCommitNumber;
        testGit.starterNode->next = additionalNode;
        additionalNode->previous = testGit.starterNode;
        singlyNode * traverserStarterNode = testGit.starterNode->head;
        singlyNode * traverserAdditionalNode = testGit.starterNode->next->head;
        cout << "StarterNode->next commit number ==== " << testGit.starterNode->next->commitNumber << endl;

        //cout << "debug step one" << endl;
        cout << endl;
        //copy all contents of SLL
        while (traverserStarterNode != nullptr){
          if (traverserAdditionalNode == nullptr){
            cout << "new doubly node head is NULL" << endl;
            singlyNode * deepCopy = new singlyNode;
            //set values of deepCopy node
            deepCopy->fileName = traverserStarterNode->fileName;
            deepCopy->fileVersion = traverserStarterNode->fileVersion;
            deepCopy->integerFileVersion = traverserStarterNode->integerFileVersion;
            deepCopy->next = nullptr;

            testGit.starterNode->next->head = deepCopy;
            //cout << "debug step two" << endl;
            cout << endl;
          }
          else{
            cout << "new doubly node head NOT null" << endl;
            singlyNode * deepCopy = new singlyNode;
            //set values of deepCopy node
            deepCopy->fileName = traverserStarterNode->fileName;
            deepCopy->fileVersion = traverserStarterNode->fileVersion;
            deepCopy->integerFileVersion = traverserStarterNode->integerFileVersion;
            deepCopy->next = nullptr;

            traverserAdditionalNode->next = deepCopy;
          }
          traverserAdditionalNode = traverserAdditionalNode->next;
          traverserStarterNode = traverserStarterNode->next;
        }
        testGit.starterNode = testGit.starterNode->next;
        */

        /*
        //then create new doubly node
        doublyNode * additionalNode = new doublyNode;
        doublyNode * traverser;
        doublyNode * prev;
        singlyNode * singlyTraverser;
        singlyTraverser = testGit.starterNode->head;
        prev = head;
        traverser = head;

        int newCommitNumber = 0;


        while (traverser != NULL){
          traverser = traverser->next;
          newCommitNumber +=1;
        }
        while (prev->next != NULL){
          prev = prev->next;
        }
        prev->next = additionalNode;
        additionalNode->commitNumber = newCommitNumber;
        additionalNode->previous = prev;
        cout << "The new commit number: " << newCommitNumber << endl;

        singlyNode * newDoublyNodeTraverser;
        newDoublyNodeTraverser = additionalNode->head;
          singlyNode * temp = new singlyNode;
          temp->fileName = singlyTraverser->fileName;
          temp->fileVersion = singlyTraverser->fileVersion;
          if (additionalNode->head == nullptr){
            additionalNode->head = temp;
          }
          else{
            while (singlyTraverser->next != nullptr){
            singlyTraverser = singlyTraverser->next;
            }
            singlyTraverser->next = temp;
          }
          testGit.starterNode = additionalNode;
          //Below prints the singly linked list of the new doubly node after being copied
                if (testGit.starterNode->head != NULL){
                  singlyNode * theCoutTraverser = testGit.starterNode->head;
                  cout << endl;
                  cout << "Commit Number: " << testGit.starterNode->commitNumber << endl;
                  cout << " SLL --> ";
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
        
        */
                 //Below prints the singly linked list of the new doubly node after being copied
                if (testGit.starterNode->head != NULL){
                  singlyNode * theCoutTraverser = testGit.starterNode->head;
                  cout << endl;
                  cout << "Commit Number: " << testGit.starterNode->commitNumber << endl;
                  cout << " SLL --> ";
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
        newCommitNumber = newCommitNumber +1;
        cout << "New Doubly Node created." << endl;
        cout << endl;
        break;
      }

      // checking out a specific version based on a unique commit number
      case 4: {
       int commitNumber;
       cout << "Enter a commit number: " << endl;
       cin >> commitNumber;
       if (commitNumber > newCommitNumber){
         cout << "Invalid commit number" << endl;
         break;
       }
       // if commit number = valid, then files should be overwritten by corresponding files in minigit
            char yesNo;
            cout << "Warning: You will lose your local changes if you check out from a different version before making a commit with your current local changes." << endl;
            cout << "Do you still want to do this? (Y/N)" << endl;
             cin >> yesNo;
            if(yesNo == 'Y' || yesNo == 'y') {
                testGit.checkOut(commitNumber);
             break;
            } else {
              cout << "Returning to menu -- user declined the warning." << endl;
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

/*
//add file to minigit directory
                char character;
                
                string newFile = fileName; //newFile being copied to minigit
                //Removes the ".txt" at the end of the newFile being created
                newFile.erase(newFile.end()-1);
                newFile.erase(newFile.end()-1);
                newFile.erase(newFile.end()-1);
                newFile.erase(newFile.end()-1);

                //Add version number to newFile
                newFile = newFile + "_00.txt"; //should always start as version zero i think
                cout <<"new file name with version number being copied to minigit ------ " << newFile;

                //need to still actually copy the file over to the directory
*/