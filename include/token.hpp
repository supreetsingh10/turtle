#pragma once
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
    // OPERATOR

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
        virtual bool incompatible_type(char next_char) = 0; 

    public:
        Token(); 
        virtual ~Token(); 

        static void initialize_map(); 
        const TokenTypes get_type() const; 

        virtual bool parse(char cur, char next) = 0;
}; 

class Literal : public Token {
    private:
        int precedence; 
        static std::set<TokenTypes> m_compatible_types; 

    protected:
        virtual bool incompatible_type(char next_char) override; 
        bool double_quot_enabled, single_quot_enabled; 

    public:
        Literal(); 
        virtual ~Literal(); 

        virtual bool parse(char cur, char next) override; 
};


class Identifier : public Token {
    private:
        int precedence; 
        static std::set<TokenTypes> m_compatible_types; 


    protected:
        virtual bool incompatible_type(char next_char) override; 

    public:
        Identifier(); 

        virtual ~Identifier(); 

        virtual bool parse(char cur, char next) override;
};

class Numbers: public Token {
    private: 
        static std::set<TokenTypes> m_compatible_types; 

    protected:
        virtual bool incompatible_type(char next_char) override; 

    public: 
        Numbers(); 
        virtual ~Numbers(); 

        virtual bool parse(char cur, char next) override; 
};
