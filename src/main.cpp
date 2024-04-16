#include "../include/token.hpp"
#include "../include/lexer.hpp"
// tokens can be of type identifier, operator, literals.


// Abstract class, where the token types can change. 
// Tokens can be of type Interger, Identifier, Literal 

// start reading the file, peak the next token / word, decide it's type, then decide to keep going or terminate the reading. 
int main() {
    std::vector<Token*> *vt = new std::vector<Token*>();

    Lexer lexy = Lexer(); 
    lexy.initialize(); 

    lexy.read_file("./some.turt");
    lexy.generate_tokens();

    return 0; 
}
