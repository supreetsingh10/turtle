#pragma once
#include <string>
#include <iostream>


enum TokenTypes {
    NONE,
    IDENTIFIER, // variables and all. fn name. 
    NUMBER, // number can be of type integer or float. 
    LITERAL, // strings.
    OPERATORS, // All different kind of operators. 
    CHARACTER, // when we are reading the 
    KEYWORD, // the syntax of the language that cannot be used as an Identifier. 
};


class Token {
    protected:
        TokenTypes token_type;
        std::string token_value;

    public:
        Token() {
        }

        virtual ~Token() {
        }

        virtual void parse() = 0;
}; 

class Literal : public Token {
    private:
        int precedence; 

    public:
        Literal() {
        }

        virtual ~Literal() {
            std::cout << "Deleted Liter" << std::endl; 
        }

        virtual void parse() override; 
};


class Identifier : public Token {
    private:
        int precedence; 

    public:
        Identifier() {
        }

        virtual ~Identifier() {
            std::cout << "Deleted Iden" << std::endl; 
        }

        virtual void parse() override;
};

