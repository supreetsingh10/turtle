#include "../include/token.hpp"
#include <cassert>
#include <iostream>
#include <map>
#include <set>
#include <stdexcept>
#include <utility>
#include "../include/utilities.hpp"

std::map<char, TokenTypes> Token::m_symbol_map; 

Token::Token() {
}

Token::~Token() {
}

void Token::initialize_map() {
    POPULATE_MAP(m_symbol_map, '0', '9', TokenTypes::NUMBER);
    POPULATE_MAP(m_symbol_map, 'a', 'z', TokenTypes::IDENTIFIER);
    POPULATE_MAP(m_symbol_map, 'A', 'Z', TokenTypes::IDENTIFIER);

    m_symbol_map.insert(std::make_pair('_', TokenTypes::WHITESPACE));
    m_symbol_map.insert(std::make_pair('\n', TokenTypes::WHITESPACE));
    m_symbol_map.insert(std::make_pair('\r', TokenTypes::WHITESPACE));

    m_symbol_map.insert(std::make_pair('=', TokenTypes::EQUAL));
    m_symbol_map.insert(std::make_pair('"', TokenTypes::D_QUOTES));
    m_symbol_map.insert(std::make_pair('\'', TokenTypes::S_QUOTES));
}

TokenTypes Token::get_type(char c) {
    TokenTypes type = NONE;

    try {
        type = m_symbol_map.at(c); 
    } catch (std::out_of_range o) {
        std::cerr << "Character " << c << " is not found " << o.what() << std::endl;  
        assert(!"Character not found");
    }

    return type; 
}

Literal::Literal() {

}

Literal::~Literal() {

}

std::set<TokenTypes> Literal::m_compatible_types; 

bool Literal::parse(char cur, char next) {
    this->token_value += cur; 
    return incompatible_type(next); 
}

// We will need a class seperate for Operators and then we will need to add incompatible_types there, there will be a sub enum for specific operators. 
bool Literal::incompatible_type(char next_char) {
    TokenTypes next_type = Token::get_type(next_char); 

    return true;
}


Identifier::Identifier() {

}

Identifier::~Identifier() {

}

std::set<TokenTypes> Identifier::m_compatible_types; 

bool Identifier::parse(char cur, char next) {
    this->token_value += cur; 
    return true;
}

bool Identifier::incompatible_type(char next_char) {
    return true; 
}


Numbers::Numbers() {

}

Numbers::~Numbers() {
}

std::set<TokenTypes> Numbers::m_compatible_types; 

bool Numbers::parse(char cur, char next) {
    this->token_value += cur; 
    return true; 
}

bool Numbers::incompatible_type(char next) {
    return false;
}
