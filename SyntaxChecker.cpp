#include "SyntaxChecker.h"
#include "GenStack.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

SyntaxChecker::SyntaxChecker()
{
  lines = 1;
  fileName = "";
  fileCheck = false;
}

SyntaxChecker::SyntaxChecker(string userInput)
{
  lines = 1;
  fileName = userInput;
  fileCheck = false;
}

SyntaxChecker::~SyntaxChecker()
{
  cout << "The checker has completed." << endl;
}

bool SyntaxChecker::checkSyntax()
{
  ifstream inFS;
  while(!fileCheck)
  {
    if(!inFS)
    {
      cout << "The file could not be found. Please type in another." << endl;
      cin >> fileName;
    }
    else
    {
      inFS.open(fileName);
      fileCheck = true;
    }
  }
  GenStack<char> stack;
  stack.push('a');
  for(int i = 0; i < stack.top; ++i)
  {

  }
}
