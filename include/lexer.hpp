#pragma  once
#include <vector>
#include <string>
#include "../include/token.hpp"


class Lexer {
    public: 
        typedef std::vector<Token*> Tokens;
        Tokens *tokens; 
        Lexer(): tokens(new Tokens()) {}

        std::string read_file(const std::string& file_name); 
};

