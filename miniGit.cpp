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

    // i am thinking we run this function in the main to see if the file exists alreay then we run the addFile function if the file does not exist in the directory
    bool Git::checkFile(singlyNode* head, string fileName)
    {
        singlyNode* current = head;  
        while (current != NULL) 
        { 
            if (current->key == fileName)
            {
                return true; 
            }
            current = current->next; 
        } 
        return false; 
    } 
    
    void Git::addFile(string filename){
        // singlyNode * temp = new singlyNode;
        // temp->fileName = filename;

    }
    void Git::removeFile(string filename){

    }
    void Git::commitChanges(){

    }
    void Git::checkOut(){

    }
  
