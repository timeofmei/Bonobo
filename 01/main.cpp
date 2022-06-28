#include <iostream>
#include <cstdlib>
#include "repl/repl.h"

int main()
{
    std::cout << "Hello " << getenv("USER") << "! This is the Bonobo programming language!" << std::endl;
    std::cout << "Feel free to type in commands" << std::endl;
    start();
    return 0;
}
