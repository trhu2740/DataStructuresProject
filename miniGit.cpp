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

    // i am thinking we run this function in the main to see if the file exsists alreay then we run the addFile function if the file does not exist in the directory
    bool Git::checkFile(string fileName)
    {
    // check if file exists in directory 
        for(int i =0; i< // number of entries in directory;)
        {
            if (fileName == files[i])
            {
                cout << "This file already exists please try again. "
                cout << "Enter a file name: " << endl;
                cin >> fileName;
            } else {

            }
        }   
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
  
