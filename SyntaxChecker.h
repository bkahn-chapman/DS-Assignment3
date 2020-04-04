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
