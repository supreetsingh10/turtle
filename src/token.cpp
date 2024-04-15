#include "../include/token.hpp"
#include <iostream>

void Literal::parse() {
    std::cout << "Parse me" << std::endl; 
}

void Identifier::parse() {
    std::cout << "Parse the identifier" << std::endl; 
}
