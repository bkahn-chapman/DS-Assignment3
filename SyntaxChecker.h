#include <iostream>
#include <string>
using namespace std;

class SyntaxChecker
{
  public:
      SyntaxChecker();
      SyntaxChecker(string fileName);
      ~SyntaxChecker();

      bool checkSyntax();

      int lines;
      string fileName;
      bool fileCheck;
};
