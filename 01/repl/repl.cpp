#include <iostream>
#include "repl/repl.h"
#include "lexer/lexer.h"
#include "token/token.h"

void start()
{
    const std::string PROMPT = ">> ";

    while (true)
    {
        std::string line{};
        std::cout << PROMPT;
        getline(std::cin, line);
        if (line.empty())
            break;
        Lexer l{line};
        Token tok = l.nextToken();
        while(tok.Type != TokenType::MYEOF)
        {
            char tp[3];
            std::snprintf(tp, 3, "%2d", static_cast<int>(tok.Type));
            std::cout << "{ Type: " << tp << " Literal: " << tok.Literal << " }" << std::endl;
            tok = l.nextToken();
        }
    }
}