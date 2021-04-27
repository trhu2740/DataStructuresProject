// CS2270 Spring 2021
// Troy Husted
// Final Project
// miniGit.cpp

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

namespace fs = std::filesystem;
using namespace std;

    /*
        For our addFile function, we are only concerned with actually adding the file. I took out the checkFile function
        and just checked if it already exists in the driver.
    */

    void Git::addFile(string filename){ 
        singlyNode * temp = new singlyNode;
        singlyNode * traverser;
        traverser = starterNode->head;

        temp->fileName = filename;

        string newFile = filename; //newFile being copied to minigit
                //Removes the ".txt" at the end of the newFile being created
                newFile.erase(newFile.end()-1);
                newFile.erase(newFile.end()-1);
                newFile.erase(newFile.end()-1);
                newFile.erase(newFile.end()-1);

                //Add version number to newFile
                newFile = newFile + "_00.txt"; //should always start as version zero i think
                cout <<"file version (to be copied to minigit) ------ " << newFile << endl;

        temp->fileVersion = newFile; //need to increment this though just testing (will be changed)
        temp->next = nullptr;

        if (starterNode->head == nullptr){ //if head is null
            starterNode->head = temp;
        }
        else{
            while (traverser->next != nullptr){
                traverser = traverser->next;
            }
            traverser->next = temp;
        }
        traverser=starterNode->head;

        cout <<"-----addFile function executed.-----" << endl; //just a debug statement to make sure this function was run
    }

    /*
        For our removeFile function, we are only concerned with removing the file from our singly linked list.
        Traversals to check if the file actually exists are in the driver function.
    */
    void Git::removeFile(string filename){
        singlyNode * traverser;
        singlyNode * prevNode;
        traverser = starterNode->head;
        prevNode = starterNode->head;

        if (starterNode->head->fileName == filename){ //if the node to be deleted is the head node
            if (starterNode->head->next == nullptr){
                delete starterNode->head;
                
            }
            else{
                prevNode = starterNode->head;
                traverser = traverser->next;
                delete prevNode;
                starterNode->head = traverser;
            }
        }
        else{ //the node to be deleted is not the head node
            while (traverser->fileName != filename){
                traverser = traverser->next;
            }
            while (prevNode->next->fileName != filename){
                prevNode = prevNode->next;
            }
            prevNode->next = prevNode->next->next;
            delete traverser;
        }

        cout << "-----removeFile function executed.-----" << endl;
    }

    /*
        With the commitChanges function being a bulk of the project, Just follow the flowchart below to make sense of all the code.
        It should be fairly self explanatory.

            // traverse the entire SLL
             // 1. check if file version already exists in minigit 
                  // a. No -> copy file from current directory into minigit, new file name should be from node's fileVersion member
                  // b. Yes -> check if current directory file has been changed
                       // i. if file is unchanged, do nothing
                       // ii. if file is changed, copy file from current directory to minigit and assign name with version number, update SLL node name to version number
             // 2. create new DLL node of repo
                   // copy of SLL moved to DLL node
                   // commit number of DLL node increment by 1

    */

    void Git::commitChanges(){
        singlyNode * traverser;
        traverser = starterNode->head;
        ifstream in;
        ofstream out;
        while (traverser != nullptr){
          string sourceFile = traverser->fileName;
          string openfile = ".minigit/" + traverser->fileVersion;
          if (fs::exists(openfile)){
            cout << "found file: " << traverser->fileVersion << " in minigit" << endl;
            //after we find the file, we check if the source file matches the the current file version in minigit
            
            ifstream currDirect;
            ifstream minigitDirect;
            currDirect.open(sourceFile);
            //currDirectoryFile << currDirect.rdbuf();
            minigitDirect.open(openfile);
            //minigitDirectoryFile << minigitDirect.rdbuf();
            string currDirectoryFile((istreambuf_iterator<char>(currDirect)), istreambuf_iterator<char>()); //reads in the file to the string
            string minigitDirectoryFile((istreambuf_iterator<char>(minigitDirect)), istreambuf_iterator<char>()); //reads in the file to the string

            //checking comparison of the strings
            if (currDirectoryFile == minigitDirectoryFile){ 
                cout << "Files match. Keeping file version and doing nothing." << endl;
            }
            else{ //copy a new file over and increment file version
                cout << "Files do not match. Copying new file and incrementing file version." << endl;

            }

          }
          else{
            cout << "File: " << traverser->fileVersion << " does not exist in minigit. Adding..." << endl;
            out.open(openfile); //source file in current working directory
            in.open(sourceFile); //new file in minigit directory with file version

            out << in.rdbuf(); //copies all of the contents from the sourceFile to the openFile (the new file being copied with file version)
            
            //make sure we close the previous file so that the next one will add (streams will reopen with different files over the next iteration)
            in.close();
            out.close();
            
          }
          traverser = traverser->next;
        }//end of while loop
        cout << "----------Commit Completed.----------" << endl;
    }
    void Git::checkOut(int commitNumber){
        // conditionals for matching commit number can go in the main and then declare the function (maybe)
        Node* temp = *reference;
   	 int position = 0;
    // Traverse the DLL
    while (temp->commitNumber != x && temp->next != NULL) {
        // Update position and overwrite file?       
        position++;
        // Update temp
        temp = temp->next;
    }
    // If the commitNumber is not present in the doubly linked list
    if (temp->commitNumber != x)
        return -1;
 
    // If the commitNumber is present in the doubly linked list, and overwrite file (not sure what to do)
    return (position + 1);

    }
