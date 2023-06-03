#include <iostream>
#include <memory>
#include <map>
#include "common.h"
#include "satSolver.h"
#include "minisat/core/SolverTypes.h"
#include "minisat/core/Solver.h"

void satCallingMiniSat(unsigned int numVar, std::vector<std::vector<int>> cnf)
{
  // your code starts here
  // std::cout << "Inside satCallingMiniSat() - Number of variables " << numVar << std::endl;
  std::unique_ptr<Minisat::Solver> solver(new Minisat::Solver());
  Minisat::vec<Minisat::Lit> clauseVector;
  Minisat::Lit newLiteral, literal;
  std::map<int, Minisat::Lit> varToLiteralMap;

  if (!varIdTable.empty())
  {
    // std::cout << "Inside !varIdTable.empty()" << std::endl;
    std::map<int, int>::iterator it;
    std::string varToLiteral;
    for (it = varIdTable.begin(); it != varIdTable.end(); it++)
    {
      // std::cout << "Inside for (it = varIdTable.begin();" << std::endl;
      newLiteral = Minisat::mkLit(solver->newVar());
      varToLiteralMap.insert({it->second, newLiteral});
    }
  }

  for (const auto &v : cnf)
  {
    for (auto i : v)
    {
      // std::cout << "Inside for (auto i : v) i = " << i << "abs(i)" << abs(i) << std::endl;
      literal = varToLiteralMap.find(abs(i))->second;
      if (i < 0)
      {
        clauseVector.push(~literal);
      }
      if (i > 0)
      {
        clauseVector.push(literal);
      }
    }
    solver->addClause(clauseVector);
    clauseVector.clear();
  }

  bool res = solver->solve();
  std::string result;
  if (res)
    result = "sat";
  else
    result = "unsat";
  std::cout << result << std::endl;

  solver.reset(new Minisat::Solver());
}
