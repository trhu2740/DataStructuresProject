// CS2270 Spring 2021
// Troy Husted
// Final Project
// miniGit.hpp

#include <iostream>
#include <iomanip>
#include <string>
#include <string.h>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <vector>

using namespace std;

struct singlyNode
{
  std::string fileName; //local file
  std::string fileVersion; //name of file in .minigit folder
  singlyNode * next;
};

struct doublyNode
{
  int commitNumber;
  singlyNode * head;
  doublyNode * previous;
  doublyNode * next;
};

class Git 
{
  public: 
    void addFile(string filename);
    void removeFile(string filename);
    void commitChanges();
    void checkOut();
    doublyNode * starterNode; //this is our access to the starterNode, I'm not sure if this needs to be changed but seems to work in the driver
  
  private: 
  //doublyNode * starterNode;
  
};