#ifndef TOKENIZER_H
#define TOKENIZER_H

#include <string>

struct Tokens;

class Lexer
{
  public:
    void tokenizeFormula(std::string);
    void tokenizeAssignment(std::string);
    Tokens getToken();
    Tokens getLookAheadToken(int);
    bool advanceToken();
};

// struct Token
// {
//     std::string content;
//     std::string type;
// };

// // a tokenzier breaks a stream of string into tokens
// class Tokenizer
// {
//   // your code starts here
//   public:
//     std::string stream; 
//     Token current_token;
//   public:
//     Tokenizer(std::string ln);
//     bool advanceToken(); // advance to the next token; return false if no more token exist
//     bool hasToken() const; // check whether there is a current token
//     Token getToken(); // returns the token being processed

// };

#endif
