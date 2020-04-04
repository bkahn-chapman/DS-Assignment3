/*
* Name: Benjamin Kahn
* ID: 2316793
* Class: CPSC-350-01
* Assignment: Programming Assignment 3: Syntax Checker
* About: SyntaxChecker.h initializes all of the functions and variables necessary for SyntaxChecker.cpp.
*/

#include <iostream>
#include <string>
#include <fstream>
#include "GenStack.h"
using namespace std;

class SyntaxChecker
{
  public:
      void checkSyntax(string fileInput);

      int lines;
      string fileName;
      bool fileCheck = false;
      char first;
};
