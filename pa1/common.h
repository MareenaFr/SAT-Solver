#include <string>
#include <map>

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