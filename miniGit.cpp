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
        temp->integerFileVersion = 00;

        string newFile = filename; //newFile being copied to minigit
                //Removes the ".txt" at the end of the newFile being created
                newFile.erase(newFile.end()-1);
                newFile.erase(newFile.end()-1);
                newFile.erase(newFile.end()-1);
                newFile.erase(newFile.end()-1);
                //.txt
                //Add version number to newFile
                newFile = newFile + "_" + to_string(temp->integerFileVersion) + ".txt";
                //newFile = newFile + "_00.txt"; //should always start as version zero i think
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
            minigitDirect.open(openfile);

            //create strings for comparssion - these strings will be composed of the entirety of the file
            string currDirectoryFile((istreambuf_iterator<char>(currDirect)), istreambuf_iterator<char>()); //reads in the file to the string
            string minigitDirectoryFile((istreambuf_iterator<char>(minigitDirect)), istreambuf_iterator<char>()); //reads in the file to the string

            //checking comparison of the strings
            if (currDirectoryFile == minigitDirectoryFile){ 
                cout << "Files match. Keeping file version and doing nothing." << endl;
            }
            else{ //copy a new file over and increment file version
                /*
                    the .erase function will remove the last element of the string. We do this six times for file versions
                    less than 10 (there are 6 chars in, for example, '_6.txt', and there will be 7 for two-digit file verisons).
                */
                cout << "Files do not match. Copying new file and incrementing file version." << endl;
                ifstream currDirectory2;
                ofstream theNewFile;
                traverser->integerFileVersion = traverser->integerFileVersion + 1; //__0, __1, __2 etc
                // _0.txt
                openfile.erase(openfile.end()-1);
                openfile.erase(openfile.end()-1);
                openfile.erase(openfile.end()-1);
                openfile.erase(openfile.end()-1);
                openfile.erase(openfile.end()-1);
                openfile.erase(openfile.end()-1);
                if (traverser->integerFileVersion > 10){
                    openfile.erase(openfile.end()-1);
                }
                //add to the end of the string
                openfile = openfile + "_" + to_string(traverser->integerFileVersion) + ".txt";
                currDirectory2.open(sourceFile);
                theNewFile.open(openfile);

                theNewFile << currDirectory2.rdbuf(); //read in contents to new file (incremented file version)

                //code to increment the file version stored at that node
                string newTraverserVersion = traverser->fileVersion;
                newTraverserVersion.erase(newTraverserVersion.end()-1);
                newTraverserVersion.erase(newTraverserVersion.end()-1);
                newTraverserVersion.erase(newTraverserVersion.end()-1);
                newTraverserVersion.erase(newTraverserVersion.end()-1);
                newTraverserVersion.erase(newTraverserVersion.end()-1);
                newTraverserVersion.erase(newTraverserVersion.end()-1);
                if (traverser->integerFileVersion > 10){
                    openfile.erase(openfile.end()-1);
                }
                newTraverserVersion = newTraverserVersion + "_" + to_string(traverser->integerFileVersion) + ".txt";
                traverser->fileVersion = newTraverserVersion; //update the current file version to incremented file version

                //close all streams
                currDirect.close();
                minigitDirect.close();
                currDirectory2.close();

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


        //create new doubly node && copy list
        doublyNode * newNode = new doublyNode; //creates the new doubly node
        newNode->previous = starterNode; //sets previous to starterNode
        newNode->next = NULL; //sets next doubly to NULL (this is the newest commit)
        newNode->commitNumber = starterNode->commitNumber+1; //Increment from previous commit
        newNode->head = nullptr;
        starterNode->next = newNode; //set next pointer from starterNode to newNode
        starterNode = starterNode->next; //finally set starterNode to the newNode (so we are on the new doublyNode/new commit)
        
        cout << "New Commit Number -> " << starterNode->commitNumber << endl;
        cout << "Copying previous SLL to new doubly node... ((((Performing a deep copy))))" << endl;
        //All there is to do now is copy the SLL over from the previous commit to the new commit
        singlyNode * prevDoubly;
        prevDoubly = starterNode->previous->head;
        singlyNode * currDoubly;
        currDoubly = starterNode->head;

        while (prevDoubly != nullptr){
            singlyNode * temp = new singlyNode;
            temp->fileName = prevDoubly->fileName;
            temp->fileVersion = prevDoubly->fileVersion;
            temp->integerFileVersion = prevDoubly->integerFileVersion;

            if (starterNode->head == nullptr){
                cout << "New doubly Node Head -> nullptr" << endl;
                starterNode->head = temp;
                temp->next = nullptr;
            }
            else{
                while (currDoubly->next != nullptr){
                    currDoubly = currDoubly->next;
                }
                cout << "-----Added Node to new Doubly node-----" << endl;
                currDoubly->next = temp;
                temp->next = nullptr;
            }

            currDoubly = starterNode->head;
            prevDoubly = prevDoubly->next;
        }

        cout << "----------Commit Completed.----------" << endl;
    }
    void Git::checkOut(int commit){
        doublyNode * traverser;
        traverser = starterNode;
        cout << "Traversing doubly linked list to find user requested checkout number... " << endl;

        while (traverser->commitNumber != commit){ //if the current commit number isn't the one we need -- 
            if (commit < traverser->commitNumber){ //we will go the previous if the commit number we need is less than current
                traverser =traverser->previous;
            }
            else{ //or we will go higher if the requested commit number is higher than the current commit number 
                traverser = traverser->next;
            } 
        }//end of while loop
        //create our singlyTraverser to traverse the files in the requested commit
        singlyNode * singlyTraverser;
        singlyTraverser = traverser->head;
        while (singlyTraverser != nullptr){
            ifstream in;
            string openfile = ".minigit/" + singlyTraverser->fileVersion;

            in.open(openfile);
            ofstream out (singlyTraverser->fileName); 
            //out.open(singlyTraverser->fileName);
            
            //string updateToCome((istreambuf_iterator<char>(in)), istreambuf_iterator<char>()); //reads in the file to the string
            out << in.rdbuf();


            in.close();
            out.close();

            singlyTraverser = singlyTraverser->next;
        }
        cout << "----------Checkout Completed. Local Directories have been Updated----------" << endl;
        cout << endl;
    }
