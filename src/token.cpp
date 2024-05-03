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
    POPULATE_MAP(m_symbol_map, 34, 47, TokenTypes::OPERATOR);
    POPULATE_MAP(m_symbol_map, 91, 96, TokenTypes::OPERATOR);
    POPULATE_MAP(m_symbol_map, 123, 126, TokenTypes::OPERATOR);

    m_symbol_map.insert(std::make_pair('_', TokenTypes::WHITESPACE));
    m_symbol_map.insert(std::make_pair('\n', TokenTypes::WHITESPACE));
    m_symbol_map.insert(std::make_pair('\r', TokenTypes::WHITESPACE));

}


// this will function like this for everyting. 
void Token::set_type(const TokenTypes& type) {
    this->token_type = type; 
}

bool Token::parse_end(char c) {
    this->token_value += c; 
    return true; 
}

bool Token::incompatible_type(char next) {
    if (TokenTypes::WHITESPACE == m_symbol_map[next])
        return true; 

    return false;
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

Literal* Literal::make_copy() {
    Literal* l = new Literal; 
    l = this; 
    return l; 
}

std::set<TokenTypes> Literal::m_compatible_types; 

bool Literal::parse(char cur, char next) {
    this->token_value += cur; 
    return incompatible_type(next); 
}

// We will need a class seperate for Operators and then we will need to add incompatible_types there, there will be a sub enum for specific operators. 
bool Literal::incompatible_type(char next) {
    TokenTypes next_type = Token::get_type(next); 
    Token::incompatible_type(next); 

    return true;
}


Identifier::Identifier() {

}

Identifier::~Identifier() {

}

std::set<TokenTypes> Identifier::m_compatible_types = {TokenTypes::IDENTIFIER, TokenTypes::NUMBER}; 


Identifier* Identifier::make_copy() {
    Identifier *i = new Identifier;
    i = this; 
    return i; 
}

bool Identifier::parse(char cur, char next) {
    this->token_value += cur; 
    return this->incompatible_type(next); 
}

bool Identifier::incompatible_type(char next_char) {
    bool flag = Token::incompatible_type(next_char); 
    if(Identifier::m_compatible_types.find(m_symbol_map[next_char]) != m_compatible_types.end())
        return false;

    return true;
}


Numbers::Numbers() {

}

Numbers::~Numbers() {
}


Numbers* Numbers::make_copy() {
    Numbers* n = new Numbers(); 
    n = this;
    return n;
}

std::set<TokenTypes> Numbers::m_compatible_types; 

bool Numbers::parse(char cur, char next) {
    this->token_value += cur; 
    return this->incompatible_type(next); 
}

bool Numbers::incompatible_type(char next) {
    Token::incompatible_type(next); 
    return false;
}


std::set<TokenTypes> Operators::m_compatible_types; 
std::map<std::string, OperatorTypes> Operators::operator_map; 

Operators::Operators() {}

Operators::~Operators() {}

bool Operators::parse(char cur, char next) {
    token_value += cur; 
    return this->incompatible_type(next); 
}

// can have whitespace in super.
bool Operators::incompatible_type(char next) {
    bool flag = Token::incompatible_type(next); 
    return flag;
}


Operators* Operators::make_copy() {
    Operators *o = new Operators(); 
    o = this; 
    return 0; 
}
