#include "../include/lexer.hpp"
#include <cassert>


void Lexer::read_file(const std::string& file_name) {
    FILE* f = std::fopen(file_name.c_str(), "r");
    assert(f != nullptr); 

    int c;
    while ((c = fgetc(f)) != EOF) {
        std::cout << (char)c << std::endl; 
    }
}

