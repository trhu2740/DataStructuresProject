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
        temp->fileVersion = "_01"; //need to increment this though just testing (will be changed)
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
    void Git::removeFile(string filename){

    }
    void Git::commitChanges(){

    }
    void Git::checkOut(){

    }