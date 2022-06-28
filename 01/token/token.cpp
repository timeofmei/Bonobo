//
// Created by 杨焱焜 on 6/27/2022.
//

#include <map>
#include "token/token.h"

TokenType LookupIndent(std::string& ident)
{
    const std::map<std::string, TokenType> keywords = {
        { "fn",     TokenType::FUNCTION },
        { "let",    TokenType::LET },
        { "true",   TokenType::MYTRUE },
        { "false",  TokenType::MYFALSE },
        { "if",     TokenType::IF },
        { "else",   TokenType::ELSE },
        { "return", TokenType::RETURN },
    };
    if (keywords.contains(ident))
        return keywords.at(ident);
    else
        return TokenType::IDENT;
}
