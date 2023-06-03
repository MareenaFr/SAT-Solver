#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <sstream>
#include "common.h"
#include "parser.h"
//#include "tree.cc"
using namespace std;

// a helper function parsing the input into the formula string and the assignment string
vector<std::string> parseLine(const std::string &line, std::string &formulaStr, std::string &assignmentStr)
{
  // your code starts here
  std::stringstream ss(line);
  std::string item;
  std::vector<std::string> stringlist;

  while (std::getline(ss, item, ';'))
  {
    stringlist.push_back(item);
  }
  return stringlist;
}

const std::string WHITESPACE = " \n\r\t\f\v";

std::string ltrim(const std::string &s)
{
    size_t start = s.find_first_not_of(WHITESPACE);
    return (start == std::string::npos) ? "" : s.substr(start);
}

// The program shall continuously ask for new inputs from standard input and output to the standard output
// The program should terminate gracefully (and quietly) once it sees EOF
int main()
{
  std::string line;
  while (std::getline(std::cin, line)) // continuously asking for new inputs from standard input
  {
    std::string formulaStr;    // store the formula string
    std::string assignmentStr; // store the assignment string
    vector<std::string> parsedLine;
    bool output;
    bool onlyFormula = false;
    // your code starts here
    nodesCount = 0;
    errorCode = 0;
    tokensIndex = -1;
    tokenListIndex = 0;
    formulaTokensCount = 0;
    assignmentTokensCount = 0;
    assignmentMap.clear();
    //getline(std::cin, line);
    char ch = ';';
    int errorFlag = 0;
    parse obj;
    if (line == "EOF")
    {
      break;
    }
    if (line.back() == ch)
    {
      formulaStr = line.substr(0, line.size() - 1);
      onlyFormula = true;
    }
    else if (line.find(ch) != string::npos)
    {
      parsedLine = parseLine(line, line, line);
      formulaStr = parsedLine[0];
      assignmentStr = parsedLine[1];
    }
    else
    {
      cout << "Error: invalid input" << endl;
      errorFlag = 1;
      continue;
    }

    if (errorFlag != 1)
    { 
      formulaStr = ltrim(formulaStr);
      formulaStr = formulaStr + ' ';
      //std::cout << "Input formula string to fparse start--" << formulaStr << "--end" << std::endl;
      FormulaParser fparse;
      fparse.tokenizeFormula(formulaStr);
      bool formulaValid = obj.validateFormula(formulaStr);
      if(!formulaValid){
        std::cout << "Error: invalid input" << std::endl;
        continue;
      }
      if(errorCode == 5){
        std::cout << "Error: invalid input" << std::endl;
        continue;
      }
      if(errorCode == 4)
      {
        std::cout << "Error: invalid input" << std::endl;
        continue;
      }
      else
      {
        if(!onlyFormula){
        //std::cout << "Inside if(!onlyFormula)" <<std::endl;
        AssignmentParser aparse;
        aparse.tokenizeAssignment(assignmentStr);

        if(errorCode == 4){
          std::cout << "Error: invalid input" << std::endl;
          continue;
        }

        assignmentMap = aparse.parseAssignment();
        //std::cout << "Assignment map empty or full " << assignmentMap.empty() << std::endl;
        
        bool assignmentValid = obj.validateAssignment(assignmentMap);

        if(!assignmentValid){
          std::cout << "Error: invalid input" << std::endl;
          continue;
          }
        }
        if(errorCode == 4){
          std::cout << "Error: invalid input" << std::endl;
          continue;
        }
        else{
          if(errorCode == 3){
          std::cout << "Error: contradicting assignment" << std::endl;
          continue;
          }
          else{
            parse objParse;
            int validate = objParse.validateExpression(formulaStr);
            if(validate == 2){
              std::cout << "Error: incomplete assignment" << std::endl;
              continue;
            }
            else{
              output = objParse.evaluvateExpression();
              std::cout << output << std::endl;
            }
          }
        }
      }
    }
  }
  return 0;
}
