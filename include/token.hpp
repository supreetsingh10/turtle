#pragma once
#include "utilities.hpp"
#include <cstdint>
#include <map>
#include <set>
#include <string>

enum TokenTypes {
    NONE,
    WHITESPACE,
    IDENTIFIER, // variables and all. fn name. 
    NUMBER, // number can be of type integer or float. 
    LITERAL, // strings.
    KEYWORD, // the syntax of the language that cannot be used as an Identifier. 
    OPERATOR
};

enum OperatorTypes {
    ADD, // +, -, *, /, >, < , , ;, 
    SUB,
    MUL,
    DIV,
    GRT_THN,
    LSS_THN,
    EQUAL,
    R_PAREN,
    L_PAREN,
    R_CURL,
    L_CURL,
    COMMA,
    SEM_COM,
    R_SQBRA,
    L_SQBRA,
    UNDER_SC,
    DASH,
    AT_RATE,
    DOLLAR,
    QUES,
    STRAIGHT,
    TILDE,
    BACK_TICK,
    HASH,
    PERCENT,
    EXCLAIM,
    CARET,
    AMPERSAND,
    BACK_SLASH,

    // These are single and double quotes. 
    // They will be later decided if they are right or left. 
    D_QUOTES,
    S_QUOTES,

    R_DQUOT,
    L_DQUOT,
    R_SINQUOT,
    L_SINQUOT,
};


class Token {
    public:
        static std::map<char, TokenTypes> m_symbol_map; 
        static TokenTypes get_type(char c); 

    protected:
        TokenTypes token_type;
        std::string token_value;

        // if this returns false then it means that the type is compatible, if it returns true, then the type is not compatible. 
        virtual bool incompatible_type(char next_char); 

    public:
        Token(); 
        virtual ~Token(); 
        Token(const Token* t) {
            Utils::logger("Coppy called for Token");
            this->token_type = t->token_type;
            this->token_value = t->token_value; 
        }

        static void initialize_map(); 
        const TokenTypes get_type() const; 
        const std::string get_value() const; 

        virtual bool parse(char cur, char next) = 0;
        virtual bool parse_end(char cur); 
        virtual void set_type(const TokenTypes& type); 
        virtual Token* make_copy() = 0; 
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
            Utils::logger("Coppy called for Identifier");
            this->token_type = i->token_type;
            this->token_value = i->token_value; 
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
           Utils::logger("Coppy called for Numbers");
           this->token_type = n->token_type;  
           this->token_value = n->token_value;  
        }

        virtual bool parse(char cur, char next) override; 
        virtual Numbers* make_copy() override; 
};

class Operators: public Token {
    private: 
        static std::set<TokenTypes> m_compatible_types; 
        static std::map<std::string, OperatorTypes> operator_map; 

    protected:
        OperatorTypes operator_type;
        uint32_t precedence;

    public: 
        Operators(); 
        virtual ~Operators();
        Operators(const Operators* o) {
           Utils::logger("Coppy called for Operators");
           this->token_type = o->token_type; 
           this->token_value = o->token_value; 
        }

        virtual bool parse(char cur, char next) override; 
        virtual bool incompatible_type(char next_char) override; 
        virtual Operators* make_copy() override; 
};
