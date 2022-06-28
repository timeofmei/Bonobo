#include "lexer/lexer.h"

void Lexer::readChar()
{
    if (readPosition >= input.length())
        ch = 0;
    else
        ch = input[readPosition];
    position = readPosition;
    readPosition++;
}

char Lexer::peekChar()
{
    if (readPosition >= input.length())
        return 0;
    else
        return input[readPosition];
}

void Lexer::skipWhiteSpace()
{
    while (ch == ' ' or ch == '\t' or ch == '\n' or ch == '\r')
        readChar();
}

std::string Lexer::readIdentifier()
{
    int pos = position;
    while (isLetter(ch))
    {
        readChar();
    }
    return input.substr(pos, position - pos);
}

std::string Lexer::readNumber()
{
    int pos = position;
    while (isDigit(ch))
    {
        readChar();
    }
    return input.substr(pos, position - pos);
}

bool Lexer::isLetter(char c)
{
    return ('a' <= c and c <= 'z') or ('A' <= c and c <= 'Z') or c == '_';
}

bool Lexer::isDigit(char c)
{
    return '0' <= c and c <= '9';
}

Lexer::Lexer(std::string& input)
{
    this->input = input;
    position = 0;
    readPosition = 0;
    ch = 0;
    readChar();
}

Token Lexer::newToken(TokenType tokenType, char c)
{
    std::string s{ c };
    return Token{ tokenType, s };
}

Token Lexer::nextToken()
{
    Token tok;

    skipWhiteSpace();

    switch (ch)
    {
        case '=':
            if (peekChar() == '=')
            {
                char c = ch;
                readChar();
                tok = Token{TokenType::EQ, std::string{c, ch}};
            }
            else
            {
                tok = newToken(TokenType::ASSIGN, ch);
            }
            break;
        case '+':
            tok = newToken(TokenType::PLUS, ch);
            break;
        case '-':
            tok = newToken(TokenType::MINUS, ch);
            break;
        case '!':
            if (peekChar() == '=')
            {
                char c = ch;
                readChar();
                tok = Token{TokenType::NOT_EQ, std::string{c, ch}};
            }
            else
            {
                tok = newToken(TokenType::BANG, ch);
            }
            break;
        case '/':
            tok = newToken(TokenType::SLASH, ch);
            break;
        case '*':
            tok = newToken(TokenType::ASTERISK, ch);
            break;
        case '<':
            tok = newToken(TokenType::LT, ch);
            break;
        case '>':
            tok = newToken(TokenType::GT, ch);
            break;
        case ';':
            tok = newToken(TokenType::SEMICOLON, ch);
            break;
        case '(':
            tok = newToken(TokenType::LPAREN, ch);
            break;
        case ')':
            tok = newToken(TokenType::RPAREN, ch);
            break;
        case ',':
            tok = newToken(TokenType::COMMA, ch);
            break;
        case '{':
            tok = newToken(TokenType::LBRACE, ch);
            break;
        case '}':
            tok = newToken(TokenType::RBRACE, ch);
            break;
        case 0:
            tok.Type = TokenType::MYEOF;
            tok.Literal = "";
            break;
        default:
            if (isLetter(ch))
            {
                tok.Literal = readIdentifier();
                tok.Type = LookupIndent(tok.Literal);
                return tok;
            }
            else if (isDigit(ch))
            {
                tok.Literal = readNumber();
                tok.Type = TokenType::INT;
                return tok;
            }
            else
            {
                tok = newToken(TokenType::ILLEGAL, ch);
            }
    }

    readChar();
    return tok;
}
