#include "../include/token.hpp"
#include <cassert>
#include <cstdint>
#include <cstdlib>
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
    POPULATE_MAP(m_symbol_map, 33, 47, TokenTypes::OPERATOR);
    POPULATE_MAP(m_symbol_map, 58, 64, TokenTypes::OPERATOR);
    POPULATE_MAP(m_symbol_map, 91, 96, TokenTypes::OPERATOR);
    POPULATE_MAP(m_symbol_map, 123, 126, TokenTypes::OPERATOR);

    m_symbol_map.insert(std::make_pair(' ', TokenTypes::WHITESPACE));
    m_symbol_map.insert(std::make_pair('\n', TokenTypes::WHITESPACE));
    m_symbol_map.insert(std::make_pair('\r', TokenTypes::WHITESPACE));

}


// this will function like this for everyting. 
void Token::set_type(const TokenTypes& type) {
    this->token_type = type; 
}

void Token::set_line_number(const uint32_t line_number) {
    m_line_number = line_number;
}

bool Token::parse_end(char c) {
    this->token_value += c; 
    return true; 
}

const std::string Token::get_value() const {
    return this->token_value; 
}

// this is a getter. 
const TokenTypes Token::get_type() const {
    return this->token_type; 
}

TokenTypes Token::get_type(char c) {
    TokenTypes type = NONE;

    try {
        type = m_symbol_map.at(c); 
    } catch (std::out_of_range o) {
        std::cerr << "Character " << (int)c << " " << c << " is not found " << o.what() << std::endl;  
        assert(!"Character not found");
    }

    return type; 
}

Literal::Literal() {
}

Literal::~Literal() {
}

Literal* Literal::make_copy() {
    return new Literal(this); 
}

// will parse as long as there are quotes. So avoid this.
std::set<TokenTypes> Literal::m_compatible_types; 
bool Literal::parse(char cur, char next) {
    this->token_value += cur; 
    return incompatible_type(next); 
}

// We will need a class seperate for Operators and then we will need to add incompatible_types there, there will be a sub enum for specific operators. 
bool Literal::incompatible_type(char next) {
    TokenTypes next_type = Token::get_type(next); 
    return true;
}


Identifier::Identifier() {
}

Identifier::~Identifier() {
}

std::set<TokenTypes> Identifier::m_compatible_types = {TokenTypes::IDENTIFIER, TokenTypes::NUMBER}; 


Identifier* Identifier::make_copy() {
     return new Identifier(this); 
}

bool Identifier::parse(char cur, char next) {
    this->token_value += cur; 
    return this->incompatible_type(next); 
}

bool Identifier::incompatible_type(char next_char) {
    if(Identifier::m_compatible_types.find(m_symbol_map[next_char]) != m_compatible_types.end()) {
        return false;
    }

    return true;
}


Numbers::Numbers() {
}

Numbers::~Numbers() {
}


Numbers* Numbers::make_copy() {
    return new Numbers(this); 
}

std::set<TokenTypes> Numbers::m_compatible_types = {TokenTypes::NUMBER};
bool Numbers::parse(char cur, char next) {
    this->token_value += cur; 
    return this->incompatible_type(next); 
}


bool Numbers::incompatible_type(char next) {
    if(Numbers::m_compatible_types.find(m_symbol_map[next]) != m_compatible_types.end())
        return false;

    if(Token::get_type(next) == TokenTypes::OPERATOR) {
        
    }

    return true;
}

Operators::Operators() {}
Operators::~Operators() {}


std::map<std::string, Operator> Operators::OperatorMap = {
{
        "+", Operator(OperatorEnum::ADD, 1)
    }, 
{
        "-", Operator(OperatorEnum::SUB, 1)
    },
{
        "*", Operator(OperatorEnum::MUL, 1)
    },
{
        "/", Operator(OperatorEnum::DIV, 1)
    },
{
        ">", Operator(OperatorEnum::GRT_THN, 1)
    },
{
        "<", Operator(OperatorEnum::LSS_THN, 1)
    },
{
        "=", Operator(OperatorEnum::EQUAL, 1)
    },
{
        "(", Operator(OperatorEnum::R_PAREN, 1)
    },
{
        ")", Operator(OperatorEnum::L_PAREN, 1)
    },
{
        "{", Operator(OperatorEnum::R_CURL, 1)
    },
{
        "}", Operator(OperatorEnum::L_CURL, 1)
    },
{
        ",", Operator(OperatorEnum::COMMA, 1)
    },
{
        ";", Operator(OperatorEnum::SEM_COM, 1)
    },
{
        "[", Operator(OperatorEnum::R_SQBRA, 1)
    },
{
        "]", Operator(OperatorEnum::L_SQBRA, 1)
    },
{
        "_", Operator(OperatorEnum::UNDER_SC, 1)
    },
{
        "-", Operator(OperatorEnum::DASH, 1)
    },
{
        "@", Operator(OperatorEnum::AT_RATE, 1)
    },
{
        "$", Operator(OperatorEnum::DOLLAR, 1)
    },
{
        "?", Operator(OperatorEnum::QUES, 1)
    },
{
        "|", Operator(OperatorEnum::STRAIGHT, 1)
    },
{
        "~", Operator(OperatorEnum::TILDE, 1)
    },
{
        "`", Operator(OperatorEnum::BACK_TICK, 1)
    },
{
        "#", Operator(OperatorEnum::HASH, 1)
    },
{
        "%", Operator(OperatorEnum::PERCENT, 1)
    },
{
        "!", Operator(OperatorEnum::EXCLAIM, 1)
    },
{
        "^", Operator(OperatorEnum::CARET, 1)
    },
{
        "&", Operator(OperatorEnum::AMPERSAND, 1)
    },
{
        "\\", Operator(OperatorEnum::BACK_SLASH, 1)
    },
{
        "\"", Operator(OperatorEnum::D_QUOTES, 1)
    },
{
        "'", Operator(OperatorEnum::S_QUOTES, 1)
    },
{
        ".", Operator(OperatorEnum::DOT, 1)
    },
};

bool Operators::parse(char cur, char next) {
    token_value += cur; 
    return this->incompatible_type(next); 
}

std::set<TokenTypes> Operators::m_compatible_types = {OPERATOR}; 
// if it finds the type in compatible type then it returns true, otherwise it returns false.
bool Operators::incompatible_type(char next) {
    if(m_compatible_types.find(Token::get_type(next)) == m_compatible_types.end())
        return true;

    return false;
}

bool Operators::check_set_valid_token_type() {
    try {
        this->m_operator_type = OperatorMap.at(token_value);
    } catch (std::out_of_range) {
       assert(!"Failed to find the operator"); 
       std::cerr << "Failed the operator, check at line number " << m_line_number << std::endl;
       exit(1);
    }
    return true;
}

Operators* Operators::make_copy() {
     return new Operators(this); 
}
