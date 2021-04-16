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

struct doublyNode
{
  int commitNumber;
  singlyNode * head;
  doublyNode * previous;
  doublyNode * next;
};

struct singlyNode
{
  std::string fileName;
  std::string fileVersion; 
  singlyNode * next;
};

class Git 
{
  public: 
    void addFile();
    void removeFile();
    void commitChanges();
    void checkOut();
  
  private: 
  
};

