/*
* Name: Benjamin Kahn
* ID: 2316793
* Class: CPSC-350-01
* Assignment: Programming Assignment 3: Syntax Checker
* About: Main.cpp handles the user input sections.
*/

#include "SyntaxChecker.h"

int main(int argc, char** argv)
{
  GenStack<char> stack; //creates a new stack
  string fileInput = argv[1]; //gets the input from the command line
  SyntaxChecker checker; //creates a new SyntaxChecker
  char choice = 'y'; //if the user wants to check another file
  //while the user wants to check another file
  while(choice == 'y')
  {
    checker.checkSyntax(fileInput); //runs the SyntaxChecker on the input
    cout << "Do you want to check another file? (Please type in 'y' or 'n')" << endl;
    cin >> choice;
    //if the user wants to check another file
    if(choice == 'y')
    {
      cout << "What is the name of the next file you would like to check?" << endl;
      cin >> fileInput;
    }
    //if the user does not want to check another file
    else
    {
      cout << "Thank you for using my program!" << endl;
      choice = 'n';
    }
  }
  stack.~GenStack(); //closes the last stack
  exit(0); //exits the program
}
