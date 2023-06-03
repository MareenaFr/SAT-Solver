#ifndef PARSER_H
#define PARSER_H

#include <string>
#include <map>

#include "tokenizer.h"

class TreeNodes;

class parse
{
  public:
    bool evaluvateExpression();
    int validateExpression(std::string);
    TreeNodes *getTreeRoot();
    TreeNodes *parseFormula();
    TreeNodes *parseConjterm();
    TreeNodes *parseTerm();
    bool Eval(TreeNodes*);
    bool validateFormula(std::string);
    bool validateAssignment(std::map<std::string, bool>);
};

class FormulaParser
{
  public:
    FormulaParser()
    {
    }

    void tokenizeFormula(std::string);
};

class AssignmentParser
{
  public:
    AssignmentParser()
    {
    }

    void tokenizeAssignment(std::string);
    std::map<std::string, bool> parseAssignment();

};

#endif
