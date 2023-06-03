#ifndef TNODE_H
#define TNODE_H

#include <string>
#include <map>

class TreeNodes
{
  public:
      std::string content;
      TreeNodes *leftChild = nullptr;
      TreeNodes *rightChild = nullptr;

  public:
      TreeNodes()
      {
      }

      void updateChildren(TreeNodes*, TreeNodes*);
      void updateLeftChild(TreeNodes*);
      void printLevelOrder(TreeNodes*);
};

class OperatorNodes : public TreeNodes
{
public:
    OperatorNodes(std::string cntt) : TreeNodes{}
    {
        //std::cout << "Inside OperatorNodes constructor" << std::endl;
        //std::cout << "Value passed to OperatorNodes constructor " << cntt << std::endl;
        content = cntt;
    }
};

class ConstantNodes : public TreeNodes
{
public:
    ConstantNodes(std::string cntt) : TreeNodes{}
    {
        //std::cout << "Inside ConstantNodes constructor" << std::endl;
        //std::cout << "Value passed to ConstantNodes constructor " << cntt << std::endl;
        content = cntt;
    }
};

class VariableNodes : public TreeNodes
{
public:
    VariableNodes(std::string cntt) : TreeNodes{}
    {
        //std::cout << "Inside VariableNodes constructor" << std::endl;
        //std::cout << "Value passed to VariableNodes constructor " << cntt << std::endl;
        content = cntt;
    }

    bool evaluate(std::map<std::string, bool>, std::string);
};



// // abstract superclass of the syntax tree node
// class TreeNode {
//     std::string content;
//     TreeNode *leftChild = nullptr;
//     TreeNode *rightChild = nullptr;
//   protected:
//     TreeNode *getLeftChild() const;
//     TreeNode *getRightChild() const;
//   public:
//     TreeNode(std::string cntt);
//     std::string getContent() const;
//     virtual bool evaluate(const std::map<std::string, bool> &assignment) const = 0; // pure virtual method
//     void updateLeftChild(TreeNode *lChild); // for the operator "-", the operand is stored in leftChild
//     void updateChildren(TreeNode *lChild, TreeNode *rChild);
//     virtual ~TreeNode();

// };

// // concrete tree node of opertaor type
// class OperatorNode : public TreeNode {
//   public:
//     OperatorNode(std::string cntt);
//     bool evaluate(const std::map<std::string, bool> &assignment) const override;
// };

// // concrete tree node of constant type
// class ConstantNode : public TreeNode {
//   public:
//     ConstantNode(std::string cntt);
//     bool evaluate(const std::map<std::string, bool> &assignment) const override;
// };

// // concrete tree node of varibale type
// class VariableNode : public TreeNode {
//   public:
//     VariableNode(std::string cntt);
//     bool evaluate(const std::map<std::string, bool> &assignment) const override;
// };

#endif
