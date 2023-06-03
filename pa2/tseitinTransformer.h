#ifndef TSEITIN_H
#define TSEITIN_H

#include <vector>
#include <map>
#include <string>
#include "treeNode.h"

class TseitinTransformer
{
public:
  TreeNodes *formulaRoot;
  // std::vector<std::vector<int>> cnf;                 // represent CNF in vector of vector
  int transSubformula(TreeNodes *subRoot);           // recursive function called on each subformula
  void addNegEq(int curID, int childID);             // add clauses for a negation subformula
  void addOrEq(int curID, int leftID, int rightID);  // add clauses for an or subformula
  void addAndEq(int curID, int leftID, int rightID); // add clauses for an and subformula
  // TseitinTransformer(TreeNodes *root);
  std::vector<std::vector<int>> transform();
  std::string cnfString() const; // a debug helper function to check whehter the correctness of transformation
  void mapToNum(TreeNodes *root);
  int typeOfNode(std::string content);
  TreeNodes *NNF(TreeNodes *root);
  TreeNodes *NNF_Neg(TreeNodes *node);
  void addToTokensList(std::string content);
};

#endif
