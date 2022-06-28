#define CATCH_CONFIG_MAIN

#include <vector>
#include <catch2/catch.hpp>
#include "token/token.h"
#include "lexer/lexer.h"


TEST_CASE("test")
{
    std::string input{ "let five = 5;\n"
                       "let ten = 10;\n"
                       "let add = fn(x, y) {\n"
                       "  x + y;\n"
                       "};\n"
                       "let result = add(five, ten);\n"
                       "!-/*5;\n"
                       "5 < 10 > 5;\n"
                       "\n"
                       "if (5 < 10) {\n"
                       "    return true;\n"
                       "} else {\n"
                       "    return false;\n"
                       "}\n"
                       "10 == 10;\n"
                       "10 != 9;\n"
    };
    std::vector<Token> tests{
        { TokenType::LET,       "let" },
        { TokenType::IDENT,     "five" },
        { TokenType::ASSIGN,    "=" },
        { TokenType::INT,       "5" },
        { TokenType::SEMICOLON, ";" },
        { TokenType::LET,       "let" },
        { TokenType::IDENT,     "ten" },
        { TokenType::ASSIGN,    "=" },
        { TokenType::INT,       "10" },
        { TokenType::SEMICOLON, ";" },
        { TokenType::LET,       "let" },
        { TokenType::IDENT,     "add" },
        { TokenType::ASSIGN,    "=" },
        { TokenType::FUNCTION,  "fn" },
        { TokenType::LPAREN,    "(" },
        { TokenType::IDENT,     "x" },
        { TokenType::COMMA,     "," },
        { TokenType::IDENT,     "y" },
        { TokenType::RPAREN,    ")" },
        { TokenType::LBRACE,    "{" },
        { TokenType::IDENT,     "x" },
        { TokenType::PLUS,      "+" },
        { TokenType::IDENT,     "y" },
        { TokenType::SEMICOLON, ";" },
        { TokenType::RBRACE,    "}" },
        { TokenType::SEMICOLON, ";" },
        { TokenType::LET,       "let" },
        { TokenType::IDENT,     "result" },
        { TokenType::ASSIGN,    "=" },
        { TokenType::IDENT,     "add" },
        { TokenType::LPAREN,    "(" },
        { TokenType::IDENT,     "five" },
        { TokenType::COMMA,     "," },
        { TokenType::IDENT,     "ten" },
        { TokenType::RPAREN,    ")" },
        { TokenType::SEMICOLON, ";" },
        { TokenType::BANG,      "!" },
        { TokenType::MINUS,     "-" },
        { TokenType::SLASH,     "/" },
        { TokenType::ASTERISK,  "*" },
        { TokenType::INT,       "5" },
        { TokenType::SEMICOLON, ";" },
        { TokenType::INT,       "5" },
        { TokenType::LT,        "<" },
        { TokenType::INT,       "10" },
        { TokenType::GT,        ">" },
        { TokenType::INT,       "5" },
        { TokenType::SEMICOLON, ";" },
        { TokenType::IF,        "if" },
        { TokenType::LPAREN,    "(" },
        { TokenType::INT,       "5" },
        { TokenType::LT,        "<" },
        { TokenType::INT,       "10" },
        { TokenType::RPAREN,    ")" },
        { TokenType::LBRACE,    "{" },
        { TokenType::RETURN,    "return" },
        { TokenType::MYTRUE,    "true" },
        { TokenType::SEMICOLON, ";" },
        { TokenType::RBRACE,    "}" },
        { TokenType::ELSE,      "else" },
        { TokenType::LBRACE,    "{" },
        { TokenType::RETURN,    "return" },
        { TokenType::MYFALSE,   "false" },
        { TokenType::SEMICOLON, ";" },
        { TokenType::RBRACE,    "}" },
        { TokenType::INT,       "10" },
        { TokenType::EQ,        "==" },
        { TokenType::INT,       "10" },
        { TokenType::SEMICOLON, ";" },
        { TokenType::INT,       "10" },
        { TokenType::NOT_EQ,    "!=" },
        { TokenType::INT,       "9" },
        { TokenType::SEMICOLON, ";" },
        { TokenType::MYEOF,     "" },
    };

    Lexer l{ input };
    for (int i = 0; i < tests.size(); i++)
    {
        Token tok{ l.nextToken() };
        SECTION(std::to_string(i))
        {
            REQUIRE(tok.Literal == tests[i].Literal);
            REQUIRE(tok.Type == tests[i].Type);
        }
    }
}