#pragma  once
#include <cstdint>
#include <map>
#include "../include/source.hpp"
#include <memory>
#include <vector>
#include <string>
#include "../include/token.hpp"


enum SOURCE_TYPE {
    SIGNS,
    NUMBERIC,
    ALPHANUMERIC,
    WHITESPACE,
}; 

class Lexer {
    typedef std::vector<Token*> Tokens;

    public: 
        Tokens *tokens; 

        Lexer(): tokens(new Tokens()), 
        m_pcurrent_token(nullptr), 
        m_current_type(TokenTypes::NONE) {
        
        }

        virtual ~Lexer(); 

        void read_file(const std::string& file_name); 
        void scan(); 
        void generate_tokens(); 
        // initializes the hash map that has the values for character types
        void initialize();

    protected:
        Token* m_pcurrent_token; 
        TokenTypes m_current_type;
        // Add source file here. 
        std::unique_ptr<Source> source_code; 
        uint32_t cursor; 

        std::map<char, SOURCE_TYPE> m_source_map; 
};

