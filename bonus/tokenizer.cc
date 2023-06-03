#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include "common.h"
#include "tokenizer.h"

enum Token
{
    tok_const = 1,
    tok_VarName = 2,
    tok_plus = 3,
    tok_star = 4,
    tok_assign = 5,
    tok_open = 6,
    tok_close = 7,
    tok_negation = 8,
    tok_colon = 9,
    tok_comma = 10
};

struct Tokens formulatokenList[100];
struct Tokens assignmenttokenList[100];
int formulaTokensCount = 0;
int assignmentTokensCount;
int tokensIndex = -1;
int tokenListIndex = 0;
int errorCode = 0;

void Lexer::tokenizeFormula(std::string str)
{
    std::string identifier;
    // std::cout << "Formula string is " << str << std::endl;
    // std::cout << "Formula string length is " << str.length() << std::endl;
    // std::cout << "Inside getToken function" << std::endl;
    char firstChar;

    int k = 0;
    while (str[k] == ' ')
    {
        k++;
    }
    firstChar = str[k];
    if ((!isalnum(firstChar)) && (firstChar != '-') && (firstChar != '('))
    {
        errorCode = 4;
        // std::cout << "Error : invalid input 13" << std::endl;
        return;
    }

    for (size_t i = 0; i < str.length(); i++)
    {
        int lookahead = i + 1;
        (void)lookahead;
        size_t j;
        // std::cout << "Value of character is " << str[i] << std::endl;
        if (isalpha(str[i]))
        {
            // std::cout << "Inside isalpha(str[i])" << std::endl;
            identifier = str[i];
            for (j = i + 1; j < str.length(); j++)
            {
                if (isalnum(str[j]))
                {
                    identifier += str[j];
                }
                else
                    break;
            }
            if (identifier.length() > 10)
            {
                errorCode = 4;
                return;
            }
            formulatokenList[tokenListIndex].content = identifier;
            formulatokenList[tokenListIndex].type = 2;
            tokenListIndex++;
            i = j - 1;
        }

        else if (str[i] == ' ')
        {
            // std::cout << "Inside space check" << std::endl;
            continue;
        }

        else if (str[i] == '+')
        {
            // std::cout << "Inside + check" << std::endl;
            formulatokenList[tokenListIndex].content = '+';
            formulatokenList[tokenListIndex].type = 3;
            tokenListIndex++;
        }

        else if (str[i] == '*')
        {
            // std::cout << "Inside * check" << std::endl;
            formulatokenList[tokenListIndex].content = '*';
            formulatokenList[tokenListIndex].type = 4;
            tokenListIndex++;
        }

        // else if ((str[i] == '1') || (str[i] == '0'))
        // {
        //     // std::cout << "Inside 1 or 0 check" << std::endl;
        //     // std::cout << "value of str[lookahead] " << str[lookahead] << std::endl;
        //     if (str[lookahead] == ' ' || str[lookahead] == '+' || str[lookahead] == '*' || str[lookahead] == ';' || str[lookahead] == ')')
        //     {
        //         // std::cout << "Inside 1 or 0 lookahead check" << std::endl;
        //         formulatokenList[tokenListIndex].content = str[i];
        //         formulatokenList[tokenListIndex].type = 1;
        //         tokenListIndex++;
        //     }
        //     else
        //     {
        //         // std::cout << "Error: invalid input 2" << std::endl;
        //         errorCode = 4;
        //     }
        // }

        else if (str[i] == '(')
        {
            formulatokenList[tokenListIndex].content = str[i];
            formulatokenList[tokenListIndex].type = 6;
            tokenListIndex++;
        }

        else if (str[i] == ')')
        {
            formulatokenList[tokenListIndex].content = str[i];
            formulatokenList[tokenListIndex].type = 7;
            tokenListIndex++;
        }

        else if (str[i] == '-')
        {
            formulatokenList[tokenListIndex].content = str[i];
            formulatokenList[tokenListIndex].type = 8;
            tokenListIndex++;
        }

        else
        {
            // std::cout << "Error: invalid input 3" << std::endl;
            errorCode = 4;
            return;
        }
    }

    formulaTokensCount = tokenListIndex;

    // std::cout << "Formula tokens count " << formulaTokensCount << std::endl;

    // for (int k = 0; k < tokenListIndex; k++)
    // {
    //     std::cout << formulatokenList[k].content << " " << formulatokenList[k].type << " ";
    // }
    // std::cout << std::endl;
}

void Lexer::tokenizeAssignment(std::string str)
{
    std::string variable;
    int tokenListIndex = 0;
    int latestToken = 0;

    for (size_t i = 0; i < str.length(); i++)
    {
        size_t j;
        if (isalpha(str[i]))
        {
            // std::cout << "Inside isalpha(str[i])" << std::endl;
            variable = str[i];
            for (j = i + 1; j < str.length(); j++)
            {
                if (isalnum(str[j]))
                {
                    variable += str[j];
                }
                else
                    break;
            }
            assignmenttokenList[tokenListIndex].content = variable;
            assignmenttokenList[tokenListIndex].type = 2;
            tokenListIndex++;
            latestToken = 2;
            i = j - 1;
        }

        else if (str[i] == ' ')
        {
            // std::cout << "Inside space check" << std::endl;
            continue;
        }

        else if (str[i] == ':')
        {
            if (latestToken == 2)
            {
                assignmenttokenList[tokenListIndex].content = ':';
                assignmenttokenList[tokenListIndex].type = 9;
                tokenListIndex++;
                latestToken = 9;
            }
            else
            {
                std::cout << "Error: invalid input" << std::endl;
                errorCode = 4;
                return;
            }
        }
        else if ((str[i] == '0') || (str[i] == '1'))
        {
            if (latestToken == 9)
            {
                assignmenttokenList[tokenListIndex].content = str[i];
                assignmenttokenList[tokenListIndex].type = 1;
                tokenListIndex++;
                latestToken = 1;
            }
            else
            {
                // std::cout << "Error : invalid input 13" << std::endl;
                errorCode = 4;
                return;
            }
        }
        else if (str[i] == ',')
        {
            if (latestToken == 1)
            {
                assignmenttokenList[tokenListIndex].content = str[i];
                assignmenttokenList[tokenListIndex].type = 10;
                tokenListIndex++;
                latestToken = 10;
            }
            else
            {
                // std::cout << "Error: invalid input 10" << std::endl;
                errorCode = 4;
                return;
            }
        }
        else
        {
            // std::cout << "Error: invalid input 8" << std::endl;
            errorCode = 4;
            return;
        }
    }

    assignmentTokensCount = tokenListIndex;
    // std::cout << "Assignment tokens count " << assignmentTokensCount << std::endl;

    /*
    for(int k=0; k < tokenListIndex ; k++){
        std::cout << assignmenttokenList[k].content << " " << assignmenttokenList[k].type << std::endl;
    }
    */
}

bool Lexer::advanceToken()
{
    tokensIndex++;
    // std::cout << "Inside advanceToken() , tokensIndex = " << tokensIndex << std::endl;
    if (tokensIndex == formulaTokensCount)
        return false;
    else
        return true;
}

bool hasToken()
{
    Lexer lex;
    if (lex.advanceToken())
        return true;
    else
        return false;
}

Tokens Lexer::getToken()
{
    Tokens resultToken;
    resultToken = formulatokenList[tokensIndex];
    return resultToken;
}

Tokens Lexer::getLookAheadToken(int index)
{
    Tokens resultToken;
    resultToken = formulatokenList[index];
    return resultToken;
}
