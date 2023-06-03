#include <iostream>
#include "tseitinTransformer.h"
#include "treeNode.h"
#include "parser.h"
#include "common.h"
#include "tokenizer.h"
#include "treeNode.h"

std::map<int, int> varIdTable;
std::map<std::string, int> variables;
int varIdCounter = 1;
int variablesCount = 0;
std::vector<std::vector<int>> cnf;

// TseitinTransformer::TseitinTransformer(TreeNodes *root) : formulaRoot{root} {}

int TseitinTransformer::transSubformula(TreeNodes *subRoot)
{
  // your code starts here
  int nodeType;
  int temp1, temp2;
  nodeType = typeOfNode(subRoot->content);
  // std::cout << "Inside transSubformula() Root node is " << subRoot->content << " Node type is " << nodeType << std::endl;
  if (nodeType == 2)
  {
    // std::cout << "Inside if (nodeType == 2)" << std::endl;
    return varIdTable.find(subRoot->newVar)->second;
  }
  if (subRoot->content == "+")
  {
    // std::cout << "Inside if (subRoot->content == +)" << std::endl;
    addOrEq(varIdTable.find(subRoot->newVar)->second,
            varIdTable.find(subRoot->leftChild->newVar)->second,
            varIdTable.find(subRoot->rightChild->newVar)->second);
    temp1 = transSubformula(subRoot->leftChild);
    temp2 = transSubformula(subRoot->rightChild);
  }
  if (subRoot->content == "*")
  {
    // std::cout << "Inside if (subRoot->content == *)" << std::endl;
    addAndEq(varIdTable.find(subRoot->newVar)->second,
             varIdTable.find(subRoot->leftChild->newVar)->second,
             varIdTable.find(subRoot->rightChild->newVar)->second);
    temp1 = transSubformula(subRoot->leftChild);
    temp2 = transSubformula(subRoot->rightChild);
  }
  if (subRoot->content == "-")
  {
    // std::cout << "Inside if (subRoot->content == -)" << std::endl;
    addNegEq(varIdTable.find(subRoot->newVar)->second,
             varIdTable.find(subRoot->leftChild->newVar)->second);
    temp1 = transSubformula(subRoot->leftChild);
  }
  (void)temp1;
  (void)temp2;
  return 0;
}

void TseitinTransformer::addNegEq(int curID, int childID)
{
  // your code starts here
  // std::cout << "Inside addNegEq() " << curID << " <-> " << " ~ " << childID << std::endl;
  std::vector<int> v1, v2, v3;
  v1 = {-curID, -childID};
  v2 = {curID, childID};
  cnf.push_back(v1);
  cnf.push_back(v2);
  return;
}

void TseitinTransformer::addOrEq(int curID, int leftID, int rightID)
{
  // your code starts here
  // std::cout << "Inside addOrEq() " << curID << " <-> " << leftID << " + " << rightID << std::endl;
  // std::cout << "-curID + 1 " << -curID + 1 << std::endl;
  std::vector<int> v1, v2, v3;
  v1 = {-curID, leftID, rightID};
  v2 = {-leftID, curID};
  v3 = {-rightID, curID};
  cnf.push_back(v1);
  cnf.push_back(v2);
  cnf.push_back(v3);
  return;
}

void TseitinTransformer::addAndEq(int curID, int leftID, int rightID)
{
  // your code starts here
  // std::cout << "Inside addAndEq() " << curID << " <-> " << leftID << " . " << rightID << std::endl;
  std::vector<int> v1, v2, v3;
  v1 = {-curID, leftID};
  v2 = {-curID, rightID};
  v3 = {curID, -leftID, -rightID};
  cnf.push_back(v1);
  cnf.push_back(v2);
  cnf.push_back(v3);
  return;
}

int TseitinTransformer::typeOfNode(std::string content)
{
  int nodeType;
  for (int i = 0; i < formulaTokensCount; i++)
  {
    if (content == formulatokenList[i].content)
    {
      nodeType = formulatokenList[i].type;
      break;
    }
    else
      continue;
  }
  return nodeType;
}

void TseitinTransformer::addToTokensList(std::string content)
{
  // std::cout << "Inside addToTokensList() - content is " << content << std::endl;
  int i, tokenFound = 0;
  for (i = 0; i < formulaTokensCount; i++)
  {
    if (content == formulatokenList[i].content)
    {
      tokenFound = 1;
      break;
    }
  }
  if (tokenFound == 0)
  {
    formulatokenList[i].content = content;
    if (content == "+")
      formulatokenList[i].type = 3;
    if (content == "*")
      formulatokenList[i].type = 4;
    if (content == "-")
      formulatokenList[i].type = 8;
    formulaTokensCount++;
  }
  return;
}

void TseitinTransformer::mapToNum(TreeNodes *root)
{
  int nodeType;
  nodeType = typeOfNode(root->content);
  if (nodeType == 2)
  {
    if (variables.find(root->content) == variables.end())
    {
      variables.insert({root->content, varIdCounter});
      root->newVar = varIdCounter;
      varIdTable.insert({root->newVar, varIdCounter});
      varIdCounter++;
    }
    if (!(variables.find(root->content) == variables.end()))
    {
      root->newVar = variables.find(root->content)->second;
    }
  }

  if (root->content == "+")
  {
    root->newVar = varIdCounter;
    varIdTable.insert({root->newVar, varIdCounter});
    varIdCounter++;
    mapToNum(root->leftChild);
    mapToNum(root->rightChild);
  }

  if (root->content == "*")
  {
    root->newVar = varIdCounter;
    varIdTable.insert({root->newVar, varIdCounter});
    varIdCounter++;
    mapToNum(root->leftChild);
    mapToNum(root->rightChild);
  }

  if (root->content == "-")
  {
    root->newVar = varIdCounter;
    varIdTable.insert({root->newVar, varIdCounter});
    varIdCounter++;
    mapToNum(root->leftChild);
  }
  return;
}

TreeNodes *TseitinTransformer::NNF(TreeNodes *root)
{
  // std::cout << "Inside NNF() root node is " << root->content << std::endl;
  int nodeType;
  TreeNodes *leftchild;
  TreeNodes *rightchild;
  nodeType = typeOfNode(root->content);
  TreeNodes *temp = new TreeNodes();
  if (nodeType == 2)
  {
    return root;
  }
  if (root->content == "-")
  {
    root = NNF_Neg(root->leftChild);
    return root;
  }
  if (root->content == "+")
  {
    TreeNodes *plusNode = new OperatorNodes("+");
    leftchild = NNF(root->leftChild);
    rightchild = NNF(root->rightChild);
    plusNode->updateChildren(leftchild, rightchild);
    return plusNode;
  }
  if (root->content == "*")
  {
    TreeNodes *starNode = new OperatorNodes("*");
    leftchild = NNF(root->leftChild);
    rightchild = NNF(root->rightChild);
    starNode->updateChildren(leftchild, rightchild);
    return starNode;
  }
  return temp;
}

TreeNodes *TseitinTransformer::NNF_Neg(TreeNodes *node)
{
  // std::cout << "Inside NNF_Neg() root node is " << node->content << std::endl;
  int nodeType;
  TreeNodes *leftchild;
  TreeNodes *rightchild;
  TreeNodes *temp = new TreeNodes();
  nodeType = typeOfNode(node->content);
  if (nodeType == 2)
  {
    TreeNodes *notNode = new OperatorNodes("-");
    addToTokensList("-");
    TreeNodes *varNode = new VariableNodes(node->content);
    varNode->updateChildren(NULL, NULL);
    leftchild = varNode;
    notNode->updateLeftChild(leftchild);
    return notNode;
  }
  if (node->content == "-")
  {
    node = NNF(node->leftChild);
    return node;
  }
  if (node->content == "+")
  {
    TreeNodes *starNode = new OperatorNodes("*");
    addToTokensList("*");
    leftchild = NNF_Neg(node->leftChild);
    rightchild = NNF_Neg(node->rightChild);
    starNode->updateChildren(leftchild, rightchild);
    return starNode;
  }
  if (node->content == "*")
  {
    TreeNodes *plusNode = new OperatorNodes("+");
    addToTokensList("+");
    leftchild = NNF_Neg(node->leftChild);
    rightchild = NNF_Neg(node->rightChild);
    plusNode->updateChildren(leftchild, rightchild);
    return plusNode;
  }
  return temp;
}

std::vector<std::vector<int>> TseitinTransformer::transform()
{
  // your code starts here
  TreeNodes tree;
  // std::cout << "Inside transform()" << std::endl;
  parse objParse;
  TreeNodes *ASTroot = objParse.getTreeRoot();

  // std::cout << "AST Root node is " << ASTroot->content << std::endl;
  // tree.printLevelOrder(ASTroot);
  // std::cout << std::endl;

  TreeNodes *root = NNF(ASTroot);

  // std::cout << "NNF Root node is " << root->content << std::endl;
  // tree.printLevelOrder(root);
  // std::cout << std::endl;

  mapToNum(root);

  // std::cout << "Variable to number map: " << std::endl;
  // if (!varIdTable.empty())
  // {
  //   std::map<int, int>::iterator it;
  //   std::string assignment = "{ ";
  //   for (it = varIdTable.begin(); it != varIdTable.end(); it++)
  //   {
  //     assignment += std::to_string(it->first);
  //     assignment += ":";
  //     assignment += std::to_string(it->second);
  //     assignment += ",";
  //   }
  //   assignment = assignment.substr(0, assignment.size() - 1);
  //   std::cout << assignment << " }" << std::endl;
  // }

  int ret_val = transSubformula(root);
  (void)ret_val;
  std::vector<int> v1;
  v1 = {1};
  cnf.push_back(v1);
  return cnf;
}

std::string TseitinTransformer::cnfString() const
{
  std::string result = "";
  // your code starts here
  return result;
}
