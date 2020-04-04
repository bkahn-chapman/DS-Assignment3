/*
* Name: Benjamin Kahn
* ID: 2316793
* Class: CPSC-350-01
* Assignment: Programming Assignment 3: Syntax Checker
* About: SyntaxChecker.cpp checks the syntax of a given file from a user.
*/

#include "SyntaxChecker.h"

void SyntaxChecker::checkSyntax(string fileInput)
{
  GenStack<char> stack; //creates a new stack
  //opens the user's file
  ifstream inFS;
  inFS.open(fileInput);
  //variables
  lines = 1;
  char c;
  //while the file is not valid
  while(!fileCheck)
  {
    //if the file cannot be found
    if(!inFS)
    {
      inFS.close(); //close the original file
      //get the new file
      cout << "The file could not be found. Please type in another." << endl;
      cin >> fileName;
      //opens the new file
      inFS.open(fileName);
      //if the new file is valid, end the loop
      if(inFS)
      {
        fileCheck = true;
      }
    }
    //the file is found
    else
    {
      fileCheck = true;
    }
  }

  //while the file is not empty
  while(!inFS.eof())
  {
    inFS >> noskipws >> c;
    //checks for opening brackets and pushes
    if(c == '{' || c == '[' || c == '(')
    {
      stack.push(c);
    }
    //increments the line counter
    else if(c == '\n')
    {
      ++lines;
    }
    //if it finds a closing bracket
    else if(c == '}' || c == ']' || c== ')')
    {
      //gets the first value in the stack
      first = stack.peek();
      //if the stack is empty
      if(stack.isEmpty())
      {
        cout << "There is nothing in the stack." << endl;
        exit(0);
      }
      //if the first is a {
      else if(first == '{' && c != '}')
      {
        cout << "Line " << lines << ": expected }, found " << c << endl;
        stack.~GenStack();
        exit(0);
      }
      //if the first is a [
      else if (first == '[' && c != ']')
      {
        cout << "Line " << lines << ": expected ], found " << c << endl;
        stack.~GenStack();
        exit(0);
      }
      //if the first is a (
      else if (first == '(' && c != ')')
      {
        cout << "Line" << lines << ": expected ), found " << c << endl;
        stack.~GenStack();
        exit(0);
      }
      //pops the value off of the stack
      stack.pop();
    }
  }
  //closes the file
  inFS.close();
  //if the code is clean
  if(stack.isEmpty())
  {
    cout << "This code has no syntax errors." << endl;
  }
  //if there are no closing brackets at all
  else if(!stack.isEmpty())
  {
    first = stack.peek();
    //if the first opening bracket was a {
    if(first == '{')
    {
      cout << "There were no closing brackets in the file. The first expected closing bracket is }." << endl;
      stack.~GenStack();
      exit(0);
    }
    //if the first opening bracket was a (
    else if(first == '(')
    {
      cout << "There were no closing brackets in the file. The first expected closing bracket is )." << endl;
      stack.~GenStack();
      exit(0);
    }
    //if the first opening bracket was a [
    else if(first == '[')
    {
      cout << "There were no closing brackets in the file. The first expected closing bracket is ]." << endl;
      stack.~GenStack();
      exit(0);
    }
  }
  fileCheck = false; //resets the fileCheck variable for future uses
}
