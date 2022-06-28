#ifndef BONOBO_TOKEN_H
#define BONOBO_TOKEN_H

#include <string>

enum class TokenType
{
    ILLEGAL,
    MYEOF,

    IDENT,
    INT,

    ASSIGN,
    PLUS,
    MINUS,
    BANG,
    ASTERISK,
    SLASH,

    LT,
    GT,

    EQ,
    NOT_EQ,

    COMMA,
    SEMICOLON,

    LPAREN,
    RPAREN,
    LBRACE,
    RBRACE,

    FUNCTION,
    LET,
    MYTRUE,
    MYFALSE,
    IF,
    ELSE,
    RETURN
};

struct Token
{
    TokenType Type;
    std::string Literal;
};

TokenType LookupIndent(std::string& ident);

#endif //BONOBO_TOKEN_H
