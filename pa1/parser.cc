#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <sstream>
#include "common.h"
#include "parser.h"
#include "tokenizer.h"
#include "treeNode.h"
using namespace std;

Tokens current_token;
Lexer lex;
int nextTokenIndex = 0;
TreeNodes *parseFormula();
TreeNodes *parseConjterm();
TreeNodes *parseTerm();
TreeNodes *getTreeRoot();
void getNextToken();
Tokens getLookAheadToken(int);
std::map<std::string, bool> parseAssignment();
TreeNodes *treenodes[50];
int treeNodesIndex;
int nodesCount = 0;
std::map<std::string, bool> assignmentMap;



bool parse::evaluvateExpression()
{
  //std::cout << "Inside evaluvateExpression()" << std::endl;
  //std::cout << "Nodes count is " << nodesCount << std::endl;
  TreeNodes tree;
  TreeNodes *root = getTreeRoot();
  //std::cout << "Root node " << root->content << std::endl;
  //std::cout << "AST generated (Level Order Traversal):" << std::endl;
  //tree.printLevelOrder(root);
  //std::cout << std::endl;
  bool output = Eval(root);
  return output;
}

int parse::validateExpression(std::string str){
  //std::cout << "Inside validateExpression" << std::endl;
  std::map<std::string, bool>::iterator it;
  int found;
  bool error = false;
  for(int i=0; i < formulaTokensCount; i++){
    found = 0;
    //std::cout << "Inside outer loop" << std::endl;
    if(formulatokenList[i].type == 2){
      for (it = assignmentMap.begin(); it != assignmentMap.end(); it++)
      {   
          //std::cout << "it->first " << it->first << std::endl;
          if(formulatokenList[i].content == it->first){
            //std::cout << "Inside if(formulatokenList[i].content == it->first)" << std::endl;
              found = 1;
              break;
          }
      }
      //std::cout << "Found " << found << endl;
      if(found == 0){
        error = true;
        break;
      }
    }



  }
  //std::cout << "Error " << error << std::endl;
  if(error)
    return 2;
  else 
    return 1;
}

bool parse::validateFormula(std::string str){
  //std::cout << "Inside validateFormula()" << std::endl;
  int p_open = 0, p_close = 0;

  for(int i=0; i < formulaTokensCount; i++){
    if(formulatokenList[i].type == 6) p_open++;
    if(formulatokenList[i].type == 7) p_close++;
  }

  if(p_open != p_close) return false;

  if(formulaTokensCount == 2){
    if(formulatokenList[0].type == 2){
    //std::cout << "Inside first if(formulatokenList[i].type == 2)" << std::endl;
      if( (formulatokenList[1].type == 3 || formulatokenList[1].type == 4 || formulatokenList[1].type == 7) )
      {
        return true;
      }
      else
      {
        return false;
      }
    }

    if(formulatokenList[0].type == 1){
      //std::cout << "Inside if(formulatokenList[i].type == 1)" << std::endl;
      if( (formulatokenList[1].type == 3 || formulatokenList[1].type == 4 || formulatokenList[1].type == 7) )
      {
        return true;
      }
      else
      {
        return false;
      }
    }

    if(formulatokenList[0].type == 3){
      //std::cout << "Inside if(formulatokenList[i].type == 3)" << std::endl;
      if( (formulatokenList[1].type == 8 || formulatokenList[1].type == 6 || formulatokenList[1].type == 7
            || formulatokenList[1].type == 1 || formulatokenList[1].type == 2) )
      {
        return true;
      }
      else
      {
        return false;
      }
    }

    if(formulatokenList[0].type == 4){
      //std::cout << "Inside if(formulatokenList[i].type == 4)" << std::endl;
      if( (formulatokenList[1].type == 8 || formulatokenList[1].type == 6 || formulatokenList[1].type == 7
            || formulatokenList[1].type == 1 || formulatokenList[1].type == 2) )
      {
        return true;
      }
      else
      {
        return false;
      }
    }

    if(formulatokenList[0].type == 8){
      //std::cout << "Inside if(formulatokenList[i].type == 8)" << std::endl;
      if( (formulatokenList[1].type == 6 || formulatokenList[1].type == 1 || formulatokenList[1].type == 2 || formulatokenList[1].type == 8 ) )
      {
        return true;
      }
      else
      {
        return false;
      }
    }

    if(formulatokenList[0].type == 6){
      //std::cout << "Inside if(formulatokenList[i].type == 6)" << std::endl;
      if( (formulatokenList[1].type == 8 || formulatokenList[1].type == 6 || formulatokenList[1].type == 1 || formulatokenList[1].type == 2) )
      {
        return true;
      }
      else
      {
        return false;
      }
    }

    if(formulatokenList[0].type == 7){
      //std::cout << "Inside if(formulatokenList[i].type == 7)" << std::endl;
      if( (formulatokenList[1].type == 3 || formulatokenList[1].type == 4 || formulatokenList[1].type == 7) )
      {
        return true;
      }
      else
      {
        return false;
      }
    }
  }

  else{
      for(int i=1; i < (formulaTokensCount - 1); i++){
      if(formulatokenList[i].type == 2){
      //std::cout << "Inside if(formulatokenList[i].type == 2)" << std::endl;
        if( (formulatokenList[i-1].type == 3 || formulatokenList[i-1].type == 4 || formulatokenList[i-1].type == 8 || formulatokenList[i-1].type == 6 ) 
          && (formulatokenList[i+1].type == 3 || formulatokenList[i+1].type == 4 || formulatokenList[i+1].type == 7) )
        {
          continue;
        }
        else
        {
          return false;
        }
      }

      if(formulatokenList[i].type == 1){
        //std::cout << "Inside if(formulatokenList[i].type == 1)" << std::endl;
        if( (formulatokenList[i-1].type == 3 || formulatokenList[i-1].type == 4 || formulatokenList[i-1].type == 8 || formulatokenList[i-1].type == 6 ) 
          && (formulatokenList[i+1].type == 3 || formulatokenList[i+1].type == 4 || formulatokenList[i+1].type == 7) )
        {
          continue;
        }
        else
        {
          return false;
        }
      }

      if(formulatokenList[i].type == 3){
        //std::cout << "Inside if(formulatokenList[i].type == 3)" << std::endl;
        if( (formulatokenList[i-1].type == 7 || formulatokenList[i-1].type == 1 || formulatokenList[i-1].type == 2 ) 
          && (formulatokenList[i+1].type == 8 || formulatokenList[i+1].type == 6 || formulatokenList[i+1].type == 7
              || formulatokenList[i+1].type == 1 || formulatokenList[i+1].type == 2) )
        {
          continue;
        }
        else
        {
          return false;
        }
      }

      if(formulatokenList[i].type == 4){
        //std::cout << "Inside if(formulatokenList[i].type == 4)" << std::endl;
        if( (formulatokenList[i-1].type == 7 || formulatokenList[i-1].type == 1 || formulatokenList[i-1].type == 2 ) 
          && (formulatokenList[i+1].type == 8 || formulatokenList[i+1].type == 6 || formulatokenList[i+1].type == 7
              || formulatokenList[i+1].type == 1 || formulatokenList[i+1].type == 2) )
        {
          continue;
        }
        else
        {
          return false;
        }
      }

      if(formulatokenList[i].type == 8){
        //std::cout << "Inside if(formulatokenList[i].type == 8)" << std::endl;
        if( (formulatokenList[i-1].type == 3 || formulatokenList[i-1].type == 4 || formulatokenList[i-1].type == 8 || formulatokenList[i-1].type == 6) 
          && (formulatokenList[i+1].type == 6 || formulatokenList[i+1].type == 1 || formulatokenList[i+1].type == 2 || formulatokenList[i+1].type == 8 ) )
        {
          continue;
        }
        else
        {
          return false;
        }
      }

      if(formulatokenList[i].type == 6){
        //std::cout << "Inside if(formulatokenList[i].type == 6)" << std::endl;
        if( (formulatokenList[i-1].type == 3 || formulatokenList[i-1].type == 4 || formulatokenList[i-1].type == 8 || formulatokenList[i-1].type == 6) 
          && (formulatokenList[i+1].type == 8 || formulatokenList[i+1].type == 6 || formulatokenList[i+1].type == 1 || formulatokenList[i+1].type == 2) )
        {
          continue;
        }
        else
        {
          return false;
        }
      }

      if(formulatokenList[i].type == 7){
        //std::cout << "Inside if(formulatokenList[i].type == 7)" << std::endl;
        if( (formulatokenList[i-1].type == 7 || formulatokenList[i-1].type == 1 || formulatokenList[i-1].type == 2 ) 
          && (formulatokenList[i+1].type == 3 || formulatokenList[i+1].type == 4 || formulatokenList[i+1].type == 7) )
        {
          continue;
        }
        else
        {
          return false;
        }
      }
    } 
  }
  return true;
}

bool parse::validateAssignment(std::map<std::string, bool> table){
  //std::cout << "Inside validateAssignment()" << std::endl;
  // vector <int> v;
  // map<string, bool>::iterator it;

  // for(it = table.begin(); it != table.end(); ++it ) {
  //     v.push_back( it->second );
  // }
  
  for(int i=1; i < (assignmentTokensCount - 1); i++){
    if(assignmenttokenList[i].type == 2){
    //std::cout << "Inside if(formulatokenList[i].type == 2)" << std::endl;
      if( (assignmenttokenList[i-1].type == 10) && (assignmenttokenList[i+1].type == 9) )
      {
        continue;
      }
      else
      {
        return false;
      }
    }

    if(assignmenttokenList[i].type == 1){
      //std::cout << "Inside if(formulatokenList[i].type == 1)" << std::endl;
      if( (assignmenttokenList[i-1].type == 9) && (assignmenttokenList[i+1].type == 10) )
      {
        continue;
      }
      else
      {
        return false;
      }
    }

    if(assignmenttokenList[i].type == 10){
      //std::cout << "Inside if(formulatokenList[i].type == 3)" << std::endl;
      if( (assignmenttokenList[i-1].type == 10 || assignmenttokenList[i-1].type == 1) 
        && (assignmenttokenList[i+1].type == 10 || assignmenttokenList[i+1].type == 2) )
      {
        continue;
      }
      else
      {
        return false;
      }
    }

    if(assignmenttokenList[i].type == 9){
      //std::cout << "Inside if(formulatokenList[i].type == 4)" << std::endl;
      if( (assignmenttokenList[i-1].type == 2) && (assignmenttokenList[i+1].type == 1) )
      {
        continue;
      }
      else
      {
        return false;
      }
    }

  }
  return true;
}

TreeNodes *parse::getTreeRoot()
{
  //std::cout << "Inside getTreeRoot()" << std::endl;
  getNextToken();
  TreeNodes *formulaNode = parseFormula();
  //std::cout << "Nodes count is " << nodesCount << std::endl;
  if ((nodesCount > 1) && (formulaNode->content != "+" && formulaNode->content != "*" && formulaNode->content != "-"))
  {
    std::cout << "Error : invalid input" << std::endl;
  }
  // else
  // {
  //   std::cout << "Formula node content " << formulaNode->content << std::endl;
  //   std::cout << "Formula node left child content " << formulaNode->leftChild->content << std::endl;
  //   std::cout << "Formula node right child content " << formulaNode->rightChild->content << std::endl;
  //   //std::cout << "Formula node right child left child content " << formulaNode->rightChild->leftChild->content << std::endl;
  //   //std::cout << "Formula node right child right child content " << formulaNode->rightChild->rightChild->content << std::endl;
  // }
  return formulaNode;
}

TreeNodes *parse::parseFormula()
{
  int lookAheadIndex;
  Tokens lookAheadToken;
  TreeNodes *leftchild;
  TreeNodes *rightchild;
  //std::cout << "Inside parseFormula()" << std::endl;
  // getNextToken();
  //std::cout << "Formula tokens index " << tokensIndex << std::endl;
  //std::cout << "Current token content " << current_token.content << std::endl;
  TreeNodes *node1 = parseConjterm();
  //std::cout << "node1 content inside parseFormula " << node1->content << std::endl;
  // TreeNodes *node1 = tempnode1;
  // getNextToken();
  lookAheadIndex = tokensIndex + 1;
  if (lookAheadIndex < formulaTokensCount)
  {
    lookAheadToken = lex.getLookAheadToken(lookAheadIndex);
    //std::cout << "lookAheadToken inside parseFormula " << lookAheadToken.content << std::endl;
    if (lookAheadToken.type == 3)
    {
      tokensIndex = lookAheadIndex + 1;
      current_token = lex.getToken();
      TreeNodes *node1 = parseFormula();
      (void)node1;
      TreeNodes *plusNode = new OperatorNodes("+");
      leftchild = treenodes[treeNodesIndex - 2];
      rightchild = treenodes[treeNodesIndex - 1];
      //std::cout << "node1 before updating child " << leftchild->content << std::endl;
      //std::cout << "node2 before updating child " << rightchild->content << std::endl;
      plusNode->updateChildren(leftchild, rightchild);
      treeNodesIndex = treeNodesIndex - 2;
      treenodes[treeNodesIndex] = plusNode;
      treeNodesIndex++;
      nodesCount++;
      //std::cout << "Nodes count is " << nodesCount << std::endl;
      //std::cout << "plusNode->content " << plusNode->content << std::endl;
      //std::cout << "plusNode->leftChild " << plusNode->leftChild << std::endl;
      //std::cout << "plusNode->rightChild " << plusNode->rightChild << std::endl;
      return plusNode;
    }
  }
  return node1;
}

TreeNodes *parse::parseConjterm()
{
  int lookAheadIndex;
  Tokens lookAheadToken;
  TreeNodes *leftchild;
  TreeNodes *rightchild;
  //std::cout << "Inside parseConjterm()" << std::endl;
  // getNextToken();
  TreeNodes *node1 = parseTerm();
  //std::cout << "node1 content inside parseConjterm " << node1->content << std::endl;
  // getNextToken();
  lookAheadIndex = tokensIndex + 1;
  if (lookAheadIndex < formulaTokensCount)
  {
    lookAheadToken = lex.getLookAheadToken(lookAheadIndex);
    //std::cout << "lookAheadToken inside parseConjterm " << lookAheadToken.content << std::endl;
    if (lookAheadToken.type == 4)
    {
      tokensIndex = lookAheadIndex + 1;
      current_token = lex.getToken();
      TreeNodes *node1 = parseConjterm();
      (void)node1;
      TreeNodes *starNode = new OperatorNodes("*");
      leftchild = treenodes[treeNodesIndex - 2];
      rightchild = treenodes[treeNodesIndex - 1];
      //std::cout << "node1 before updating child " << leftchild->content << std::endl;
      //std::cout << "node2 before updating child " << rightchild->content << std::endl;
      starNode->updateChildren(leftchild, rightchild);
      treeNodesIndex = treeNodesIndex - 2;
      treenodes[treeNodesIndex] = starNode;
      treeNodesIndex++;
      nodesCount++;
      //std::cout << "Nodes count is " << nodesCount << std::endl;
      //std::cout << "starNode->content " << starNode->content << std::endl;
      //std::cout << "starNode->leftChild " << starNode->leftChild << std::endl;
      //std::cout << "starNode->rightChild " << starNode->rightChild << std::endl;
      return starNode;
    }
  }
  return node1;
}

TreeNodes *parse::parseTerm()
{
  //std::cout << "Inside parseTerm()" << std::endl;
  TreeNodes *leftchild;
  // getNextToken();
  TreeNodes *tnode;
  //std::cout << "current_token.type " << current_token.type << std::endl;
  if (current_token.type == 6)
  {
    tokensIndex++;
    current_token = lex.getToken();
    tnode = parseFormula();
    //getNextToken();
    tokensIndex++;
    current_token = lex.getToken();
    //std::cout << "Inside if -- current_token.type " << current_token.type << std::endl;
    if (current_token.type != 7)
    {
      std::cout << "Error: invalid input" << std::endl;
    }
    else
      return tnode;
  }

  if (current_token.type == 1)
  {
    TreeNodes *constNode = new ConstantNodes(current_token.content);
    constNode->updateChildren(NULL, NULL);
    treenodes[treeNodesIndex] = constNode;
    treeNodesIndex++;
    nodesCount++;
    //std::cout << "Nodes count is " << nodesCount << std::endl;
    //std::cout << "constNode->content " << constNode->content << std::endl;
    //std::cout << "constNode->leftChild " << constNode->leftChild << std::endl;
    //std::cout << "constNode->rightChild " << constNode->rightChild << std::endl;
    return constNode;
  }

  if (current_token.type == 8)
  {
    //std::cout << "Inside current_token.type == 8" << std::endl;
    tokensIndex++;
    current_token = lex.getToken();
    tnode = parseTerm();
    TreeNodes *notNode = new OperatorNodes("-");
    leftchild = treenodes[treeNodesIndex - 1];
    notNode->updateLeftChild(leftchild);
    treeNodesIndex = treeNodesIndex - 1;
    treenodes[treeNodesIndex] = notNode;
    treeNodesIndex++;
    nodesCount++;
    return notNode;
  }

  if (current_token.type == 2)
  {
    //std::cout << "Inside current_token.type == 2 " << std::endl;
    //std::cout << "Current token content " << current_token.content << std::endl;
    TreeNodes *varNode = new VariableNodes(current_token.content);
    varNode->updateChildren(NULL, NULL);
    treenodes[treeNodesIndex] = varNode;
    treeNodesIndex++;
    nodesCount++;
    //std::cout << "Nodes count is " << nodesCount << std::endl;
    //std::cout << "varNode->content " << varNode->content << std::endl;
    //std::cout << "varNode->leftChild " << varNode->leftChild << std::endl;
    //std::cout << "varNode->rightChild " << varNode->rightChild << std::endl;
    return varNode;
  }

  return nullptr;
}
  
bool parse::Eval(TreeNodes *root)
{
  //std::cout << "Inside Eval" << std::endl;
  std::string temp = " ";
  VariableNodes *vnode = new VariableNodes(temp);
  int nodeType;
  bool result;
  if (root != NULL)
  {
    for (int i = 0; i < formulaTokensCount; i++)
    {
      if (root->content == formulatokenList[i].content)
      {
        nodeType = formulatokenList[i].type;
        break;
      }
      else
        continue;
    }

    //std::cout << "Node type is" << nodeType << std::endl;

    if (nodeType == 1)
    {
      if (root->content == "1")
        result = true;
      if (root->content == "0")
        result = false;
      return result;
    }

    if(nodeType == 2){
      //std::cout << "if(nodeType == 2)" << std::endl;
      bool value = vnode->evaluate(assignmentMap, root->content);
      return value;
    }

    if(nodeType == 3){
      return (Eval(root->leftChild) || Eval(root->rightChild));
    }

    if(nodeType == 4){
      return (Eval(root->leftChild) && Eval(root->rightChild));
    }

    if(nodeType == 8){
      return (!Eval(root->leftChild));
    }

  }

  return true;
}


void FormulaParser::tokenizeFormula(std::string str){
  lex.tokenizeFormula(str);
}

void AssignmentParser::tokenizeAssignment(std::string str){
  lex.tokenizeAssignment(str);
}

std::map<std::string, bool> AssignmentParser::parseAssignment()
{
  //std::cout << "Inside parseAssignment()" << std::endl;
  std::map<std::string, bool> results;
  bool value;
  int errorFlag = 0;
  errorCode = 0;
  for (int i = 0; i < assignmentTokensCount; i++)
  {
    //std::cout << "Insdie parseAssignment() for loop" << std::endl;
    //std::cout << "assignmenttokenList[i].type " << assignmenttokenList[i].type <<std::endl;
    if (assignmenttokenList[i].type == 2)
    {
      //std::cout << "Inside assignmenttokenList[i].type == 2 check"<<std::endl;
      for(int j=0; j < assignmentTokensCount; j++){
        if(assignmenttokenList[i].content == assignmenttokenList[j].content){
          if( assignmenttokenList[i + 2].content == assignmenttokenList[j + 2].content){
            continue;
          }
          else{
            //std::cout << "Inside else of if(assignmenttokenList[i+2].content == assignmenttokenList[j+2].content)"<<std::endl;
            //std::cout << "Error: contradicting assignment" << std::endl;
            errorFlag = 1;
            errorCode = 3;
            break;
          }
        }
      }

      if(errorFlag != 1){
        if (assignmenttokenList[i + 2].content == "0")
          value = false;
        else if (assignmenttokenList[i + 2].content == "1")
          value = true;
        else{
          errorCode = 4;
          break;
        }
        results.insert({assignmenttokenList[i].content, value});
      }
      else
        break;
    }
  }

  if(errorCode == 4){
    return results;
  }

  //std::cout << "Results map empty or full " << results.empty() << std::endl;

  // if(!results.empty()){
  //   std::cout << "Assignment map: " << std::endl;
  //   map<string, bool>::iterator it;
  //   std::string assignment = "{ ";
  //   for (it = results.begin(); it != results.end(); it++)
  //   {
  //     assignment += it->first;
  //     assignment += ":";
  //     assignment += std::to_string(it->second);
  //     assignment += ",";
  //   }
  //   assignment = assignment.substr(0, assignment.size()-1);
  //   std::cout << assignment << " }" << std::endl;
  // }

  return results;
}

void getNextToken()
{
  Lexer lex;
  //std::cout << "Inside getNextToken()" << std::endl;
  //bool hasTok = false;
  bool advToken = lex.advanceToken();
  if (advToken)
    current_token = lex.getToken();
  // if(hasTok)
  //   current_token = lex.getToken();
}


