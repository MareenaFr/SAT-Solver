#include <string>
#include <map>
#include <iostream>
#include "common.h"
#include "treeNode.h"

void TreeNodes::updateChildren(TreeNodes *lChild, TreeNodes *rChild)
{
    //std::cout << "Inside updateChildren" << std::endl;
    leftChild = lChild;
    rightChild = rChild;
}

void TreeNodes::updateLeftChild(TreeNodes *lChild)
{
    leftChild = lChild;
}

int height(TreeNodes* node)
{
    if (node == NULL)
        return 0;
    else {
        /* compute the height of each subtree */
        int lheight = height(node->leftChild);
        int rheight = height(node->rightChild);

        /* use the larger one */
        if (lheight > rheight) {
            return (lheight + 1);
        }
        else {
            return (rheight + 1);
        }
    }
}

void printCurrentLevel(TreeNodes* root, int level)
{
    if (root == NULL){
        std::cout << "null ";
        return;
    }
    if (level == 1)
        std::cout << root->content << " ";
    else if (level > 1) {
        printCurrentLevel(root->leftChild, level - 1);
        printCurrentLevel(root->rightChild, level - 1);
    }
}

void TreeNodes::printLevelOrder(TreeNodes* root)
{
    int h = height(root);
    int i;
    for (i = 1; i <= h; i++)
        printCurrentLevel(root, i);
}

// virtual ~TreeNodes()
// {
//     // your code starts here
// }

// bool evaluate(const std::map<std::string, bool> &assignment) const
// {
//     // your code starts here
//     return false;
// }

bool VariableNodes::evaluate(std::map<std::string, bool> assignmentMap, std::string index){
    //std::cout << "Inside evaluate" << std::endl;
    std::map<std::string, bool>::iterator it;
    for (it = assignmentMap.begin(); it != assignmentMap.end(); it++)
    {
        if(index == it->first){
            return it->second;
        }
    }
    return false;
}
