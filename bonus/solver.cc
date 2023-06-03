#include <vector>
#include <algorithm>
#include <map>
#include <iostream>
#include "solver.h"
#include "parser.h"
#include "common.h"

void printFormula(std::vector<std::vector<int>> cnf)
{
    std::cout << "Formula in vector form : ";
    std::cout << "[";
    for (const auto &v : cnf)
    {
        std::cout << "[";
        for (auto i : v)
        {
            std::cout << i << " ";
        }
        std::cout << "]";
    }
    std::cout << "]";
    std::cout << std::endl;
}

bool solver::DPLL(std::vector<std::vector<int>> cnf)
{
    // std::cout << "Inside DPLL()" << std::endl;
    int choosenVar;
    bool hasEmptyClause;
    std::vector<std::vector<int>> F1 = BCP(cnf);
    // std::cout << "After BCP Before simplify()" << std::endl;
    // printFormula(F1);
    F1 = simplify(F1);
    // std::cout << "After simplify()" << std::endl;
    // printFormula(F1);
    hasEmptyClause = checkForEmptyClause(F1);
    // std::cout << "value of hasEmptyClause : " << bool(hasEmptyClause) << std::endl;
    if (F1.empty())
        return true;
    if (hasEmptyClause)
        return false;
    // std::cout << "F1 is not empty" << std::endl;
    std::vector<std::vector<int>> F2 = PLP(F1);
    // std::cout << "After PLP Before simplify()" << std::endl;
    // printFormula(F2);
    F2 = simplify(F2);
    hasEmptyClause = checkForEmptyClause(F2);
    // std::cout << "value of hasEmptyClause : " << bool(hasEmptyClause) << std::endl;
    if (F2.empty())
        return true;
    if (hasEmptyClause)
        return false;
    // std::cout << "F2 is not empty" << std::endl;
    choosenVar = chooseVariable();
    // std::cout << "Choosen variable is " << choosenVar << std::endl;
    addToAssignmentMap(choosenVar, true);
    if (DPLL(F2))
        return true;
    else
    {
        addToAssignmentMap(choosenVar, false);
        if (DPLL(F2))
            return true;
        else
            return false;
    }
}

std::vector<std::vector<int>> solver::BCP(std::vector<std::vector<int>> formula)
{
    // std::cout << "Inside BCP()" << std::endl;
    int unitLiteral;
    for (long unsigned int i = 0; i < formula.size(); i++)
    {
        if (formula[i].size() == 1)
        {
            unitLiteral = formula[i][0];
            // std::cout << "Inside BCP(), formula[i].size() == 1, Value of i : " << i << ", formula[i][0] : " << formula[i][0] << std::endl;
            for (long unsigned int j = 0; j < formula.size(); j++)
            {
                for (long unsigned int k = 0; k < formula[j].size(); k++)
                {
                    if (formula[j][k] == -unitLiteral)
                    {
                        formula[j].erase(formula[j].begin() + k);
                        k--;
                    }
                }
            }
            if (unitLiteral < 0)
            {
                addToAssignmentMap(abs(unitLiteral), false);
                for (long unsigned int q = 0; q < formula.size(); q++)
                {
                    if (std::find(formula[q].begin(), formula[q].end(), unitLiteral) != formula[q].end())
                    {
                        formula.erase(formula.begin() + q);
                        q--;
                    }
                }
            }

            if (unitLiteral > 0)
            {
                addToAssignmentMap(abs(unitLiteral), true);
                for (long unsigned int q = 0; q < formula.size(); q++)
                {
                    if (std::find(formula[q].begin(), formula[q].end(), unitLiteral) != formula[q].end())
                    {
                        formula.erase(formula.begin() + q);
                        q--;
                    }
                }
            }
            // formula.erase(formula.begin() + i);
            formula = BCP(formula);
        }
    }
    return formula;
}

std::vector<std::vector<int>> solver::PLP(std::vector<std::vector<int>> formula)
{
    // std::cout << "Inside PLP()" << std::endl;
    std::vector<int> pureLiterals;
    bool appearPositive = false, appearNegative = false;
    for (long unsigned int i = 0; i < varIdTable.size(); i++)
    {
        for (long unsigned int j = 0; j < formula.size(); j++)
        {
            for (long unsigned int k = 0; k < formula[j].size(); k++)
            {
                // std::cout << "formula[j][k] : " << formula[j][k] << " varIdTable[i] : " << varIdTable[i] << std::endl;
                if (formula[j][k] == varIdTable[i])
                {
                    appearPositive = true;
                }
                if (formula[j][k] == -varIdTable[i])
                {
                    appearNegative = true;
                }
            }
        }
        if (appearPositive && appearNegative)
            continue;
        if (appearPositive && !appearNegative)
        {
            addToAssignmentMap(varIdTable[i], true);
            pureLiterals.push_back(varIdTable[i]);
        }
        if (!appearPositive && appearNegative)
        {
            addToAssignmentMap(varIdTable[i], false);
            pureLiterals.push_back(-varIdTable[i]);
        }
    }

    // std::cout << "Pure literals: ";
    // std::cout << "[";
    // for (auto i : pureLiterals)
    // {
    //     std::cout << i << " ";
    // }
    // std::cout << "]";
    // std::cout << std::endl;

    for (long unsigned int p = 0; p < pureLiterals.size(); p++)
    {
        for (long unsigned int q = 0; q < formula.size(); q++)
        {
            if (std::find(formula[q].begin(), formula[q].end(), pureLiterals[p]) != formula[q].end())
            {
                formula.erase(formula.begin() + q);
                q--;
            }
        }
    }
    return formula;
}

int solver::chooseVariable()
{
    varCount++;
    return varIdTable[varCount];
}

bool solver::checkForEmptyClause(std::vector<std::vector<int>> formula)
{
    // std::cout << "Inside checkForEmptyClause()" << std::endl;
    bool emptyClauseFound = false;
    for (long unsigned int i = 0; i < formula.size(); i++)
    {
        if (formula[i].empty())
        {
            emptyClauseFound = true;
            // std::cout << "Empty clause found" << std::endl;
            break;
        }
    }
    // std::cout << "emptyClauseFound : " << bool(emptyClauseFound) << std::endl;
    if (emptyClauseFound)
        return true;
    if (!emptyClauseFound)
        return false;
    return false;
}

void solver::addToAssignmentMap(int key, bool value)
{
    if (assignment.find(key) == assignment.end())
        assignment.insert({key, value});
    if (!(assignment.find(key) == assignment.end()))
        assignment.at(key) = value;
}

std::vector<std::vector<int>> solver::simplify(std::vector<std::vector<int>> formula)
{
    // std::cout << "DPLL Assignment map: " << std::endl;
    // if (!varIdTable.empty())
    // {
    //     std::map<int, bool>::iterator it;
    //     std::string ass = "{ ";
    //     for (it = assignment.begin(); it != assignment.end(); it++)
    //     {
    //         ass += std::to_string(it->first);
    //         ass += ":";
    //         ass += std::to_string(it->second);
    //         ass += ",";
    //     }
    //     ass = ass.substr(0, ass.size() - 1);
    //     std::cout << ass << " }" << std::endl;
    // }

    if (!assignment.empty())
    {
        std::map<int, bool>::iterator it;
        for (it = assignment.begin(); it != assignment.end(); it++)
        {
            for (long unsigned int q = 0; q < formula.size(); q++)
            {
                for (long unsigned int r = 0; r < formula[q].size(); r++)
                {
                    if (((it->first == formula[q][r]) && (it->second == true)) || ((it->first == -formula[q][r]) && (it->second == false)))
                    {
                        formula.erase(formula.begin() + q);
                        q--;
                        break;
                    }
                    if (((it->first == formula[q][r]) && (it->second == false)) || ((it->first == -formula[q][r]) && (it->second == true)))
                    {
                        formula[q].erase(formula[q].begin() + r);
                        r--;
                    }
                }
            }
        }
    }
    return formula;
}
