#include <iostream>
#include <string>
#include <algorithm>
#include "tseitinTransformer.h"
#include "satSolver.h"
#include "parser.h"
#include "common.h"

// The program shall continuously ask for new inputs from standard input and output to the standard output
// The program should terminate gracefully (and quietly) once it sees EOF
int main()
{
  std::string line;
  while (std::getline(std::cin, line)) // continuously asking for new inputs from standard input
  {
    // your code starts here
    nodesCount = 0;
    errorCode = 0;
    tokensIndex = -1;
    tokenListIndex = 0;
    formulaTokensCount = 0;
    varIdCounter = 1;
    variablesCount = 0;
    cnf.clear();
    varIdTable.clear();
    variables.clear();
    int varCount = 0;
    parse objParse;
    TseitinTransformer objTseitin;
    bool whiteSpacesOnly = std::all_of(line.begin(), line.end(), isspace);
    if (whiteSpacesOnly)
    {
      std::cout << "Error: invalid input" << std::endl;
      continue;
    }
    else
    {
      FormulaParser fparse;
      fparse.tokenizeFormula(line);
      if (errorCode == 4)
      {
        std::cout << "Error: invalid input" << std::endl;
        continue;
      }
      bool formulaValid = objParse.validateFormula(line);
      if (!formulaValid)
      {
        std::cout << "Error: invalid input" << std::endl;
        continue;
      }
      cnf = objTseitin.transform();
      varCount = varIdCounter - 1;

      // std::cout << "CNF in vector form" << std::endl;
      // std::cout << "[";
      // for (const auto &v : cnf)
      // {
      //   std::cout << "[";
      //   for (auto i : v)
      //   {
      //     std::cout << i << " ";
      //   }
      //   std::cout << "]";
      // }
      // std::cout << "]";
      // std::cout << std::endl;

      satCallingMiniSat(varCount, cnf);
    }
  }
}
