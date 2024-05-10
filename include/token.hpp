#pragma once
// #include "utilities.hpp"
#include <cstdint>
#include <map>
#include <set>
#include <string>
#include "../include/operators.hpp"

enum TokenTypes {
    NONE,
    WHITESPACE,
    IDENTIFIER, // variables and all. fn name. 
    NUMBER, // number can be of type integer or float. 
    LITERAL, // strings.
    KEYWORD, // the syntax of the language that cannot be used as an Identifier. 
    OPERATOR
};


class Token {
    public:
        static std::map<char, TokenTypes> m_symbol_map; 
        static TokenTypes get_type(char c); 

    protected:
        TokenTypes token_type;
        std::string token_value;
        uint32_t m_line_number; 

        // if this returns false then it means that the type is compatible, if it returns true, then the type is not compatible. 
        virtual bool incompatible_type(char next_char) = 0; 

    public:
        Token(); 
        virtual ~Token(); 
        Token(const Token* t) {
            this->token_type = t->token_type;
            this->token_value = t->token_value; 
            this->m_line_number = t->m_line_number; 
        }

        static void initialize_map(); 
        const TokenTypes get_type() const; 
        const std::string get_value() const; 
        virtual Token* make_copy() = 0; 

        virtual bool parse(char cur, char next) = 0;
        virtual bool parse_end(char cur); 

        virtual void set_type(const TokenTypes& type); 
        virtual void set_line_number(const uint32_t line_number); 
}; 

class Literal : public Token {
    private:
        static std::set<TokenTypes> m_compatible_types; 

    protected:
        virtual bool incompatible_type(char next_char) override; 
        bool double_quot_enabled, single_quot_enabled; 
        virtual Literal* make_copy() override; 

    public:
        Literal(); 
        virtual ~Literal(); 
        Literal(const Literal* l) {
            this->token_type = l->token_type;
            this->token_value = l->token_value;
            this->m_line_number = l->m_line_number;
        }

        virtual bool parse(char cur, char next) override; 
};


class Identifier : public Token {
    private:
        static std::set<TokenTypes> m_compatible_types; 


    protected:
        virtual bool incompatible_type(char next_char) override; 

    public:
        Identifier(); 
        virtual ~Identifier(); 
        Identifier(const Identifier* i) {
            this->token_type = i->token_type;
            this->token_value = i->token_value; 
            this->m_line_number = i->m_line_number; 
        }

        virtual bool parse(char cur, char next) override;
        virtual Identifier* make_copy() override; 
};

class Numbers: public Token {
    private: 
        static std::set<TokenTypes> m_compatible_types; 

    protected:
        virtual bool incompatible_type(char next_char) override; 

    public: 
        Numbers(); 
        virtual ~Numbers(); 
        Numbers(const Numbers* n) {
           this->token_type = n->token_type;  
           this->token_value = n->token_value;  
           this->m_line_number = n->m_line_number; 
        }

        virtual bool parse(char cur, char next) override; 
        virtual Numbers* make_copy() override; 
};



class Operators: public Token {
    private: 
        static std::set<TokenTypes> m_compatible_types; 
        static std::map<std::string, Operator> OperatorMap; 

    protected:
        Operator m_operator_type;

    public: 
        Operators(); 
        virtual ~Operators();
        Operators(const Operators* o) {
           this->token_type = o->token_type; 
           this->token_value = o->token_value; 
           this->m_operator_type = o->m_operator_type; 
           this->m_line_number = o->m_line_number;
        }

        bool check_set_valid_token_type(); 
        virtual bool parse(char cur, char next) override; 
        virtual bool incompatible_type(char next_char) override; 
        virtual Operators* make_copy() override; 
};
