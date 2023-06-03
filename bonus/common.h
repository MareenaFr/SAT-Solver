#include <string>
#include <map>
#include <vector>

extern int errorCode;
extern int nodesCount;
extern int formulaTokensCount;
struct Tokens
{
    std::string content;
    int type;
};
extern int tokensIndex;
extern int tokenListIndex;
extern int assignmentTokensCount;
extern std::map<std::string, bool> assignmentMap;
extern struct Tokens formulatokenList[];
extern struct Tokens assignmenttokenList[];
extern std::map<int, int> varIdTable;
extern int varIdCounter;
extern int variablesCount;
extern std::vector<std::vector<int>> cnf;
extern std::map<std::string, int> variables;
extern std::map<int, bool> assignment;
extern int varCount;