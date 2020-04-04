#include "SyntaxChecker.h"

int main(int argc, char** argv)
{
  GenStack<char> stack;
  string fileInput = argv[1];
  SyntaxChecker checker;
  char choice = 'y';
  bool fileCheck = false;
  while(choice == 'y')
  {
    checker.checkSyntax(fileInput);
    cout << "Do you want to check another file? (Please type in 'y' or 'n')" << endl;
    cin >> choice;
    //choice = tolower(choice);
    if(choice == 'y')
    {
      cout << "What is the name of the next file you would like to check?" << endl;
      cin >> fileInput;
    }
    else
    {
      cout << "Thank you for using my program!" << endl;
      choice = 'n';
    }
  }
  stack.~GenStack();
  exit(0);
}
