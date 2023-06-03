#ifndef SOLVER_H
#define SOLVER_H

#include <vector>
#include <map>

class solver
{
public:
    bool DPLL(std::vector<std::vector<int>> cnf);
    std::vector<std::vector<int>> BCP(std::vector<std::vector<int>> formula);
    std::vector<std::vector<int>> PLP(std::vector<std::vector<int>> formula);
    bool checkForEmptyClause(std::vector<std::vector<int>> formula);
    int chooseVariable();
    void addToAssignmentMap(int key, bool value);
    std::vector<std::vector<int>> simplify(std::vector<std::vector<int>> formula);
};

#endif