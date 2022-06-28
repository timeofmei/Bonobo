#ifndef BONOBO_LEXER_H
#define BONOBO_LEXER_H

#include <string>
#include "token/token.h"

struct Lexer
{
    std::string input;
    int position;
    int readPosition;
    char ch;

    void readChar();

    char peekChar();

    void skipWhiteSpace();

    std::string readIdentifier();

    std::string readNumber();

    static bool isLetter(char c);

    static bool isDigit(char c);

    explicit Lexer(std::string& input);

    static Token newToken(TokenType tokenType, char c);

    Token nextToken();
};

#endif //BONOBO_LEXER_H
