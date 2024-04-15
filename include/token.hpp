#pragma once
#include <string>
#include <iostream>


enum TokenTypes {
    IDENTIFIER, 
    INTEGER, 
    LITERAL, 
    OPERATORS,
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

