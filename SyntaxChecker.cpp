#include "SyntaxChecker.h"

void SyntaxChecker::checkSyntax(string fileInput)
{
  GenStack<char> stack;
  ifstream inFS;
  inFS.open(fileInput);
  lines = 1;
  char c;
  while(!fileCheck)
  {
    if(!inFS)
    {
      inFS.close();
      cout << "The file could not be found. Please type in another." << endl;
      cin >> fileName;
      inFS.open(fileName);
      if(inFS)
      {
        fileCheck = true;
      }
    }
    else
    {
      fileCheck = true;
    }
  }
  while(!inFS.eof())
  {
    inFS >> noskipws >> c;
    if(c == '{' || c == '[' || c == '(')
    {
      stack.push(c);
    }
    else if(c == '\n')
    {
      ++lines;
    }
    else if(c == '}' || c == ']' || c== ')')
    {
      first = stack.peek();
      if(stack.isEmpty())
      {
        cout << "There is nothing in the stack." << endl;
        exit(0);
      }
      else if(first == '{' && c != '}')
      {
        cout << "Line " << lines << ": expected }, found " << c << endl;
        stack.~GenStack();
        exit(0);
      }
      else if (first == '[' && c != ']')
      {
        cout << "Line " << lines << ": expected ], found " << c << endl;
        stack.~GenStack();
        exit(0);
      }
      else if (first == '(' && c != ')')
      {
        cout << "Line" << lines << ": expected ), found " << c << endl;
        stack.~GenStack();
        exit(0);
      }
      stack.pop();
    }
  }
  inFS.close();
  if(stack.isEmpty())
  {
    cout << "This code has no syntax errors." << endl;
  }
  else if(!stack.isEmpty())
  {
    first = stack.peek();
    if(first == '{')
    {
      cout << "There were no closing brackets in the file. The first expected closing bracket is }." << endl;
      stack.~GenStack();
      exit(0);
    }
    else if(first == '(')
    {
      cout << "There were no closing brackets in the file. The first expected closing bracket is )." << endl;
      stack.~GenStack();
      exit(0);
    }
    else if(first == '[')
    {
      cout << "There were no closing brackets in the file. The first expected closing bracket is ]." << endl;
      stack.~GenStack();
      exit(0);
    }
  }
  fileCheck = false;
}
