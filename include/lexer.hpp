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
    ALPHABET,
    STRING,
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

        SOURCE_TYPE reset_type(SOURCE_TYPE& current_type, SOURCE_TYPE& next_type); 
        void initialize();
        void scan(); 
        void tokenize(const std::string& value, const SOURCE_TYPE& current_type, const SOURCE_TYPE& next_type); 
        void read_file(const std::string& file_name); 
        // initializes the hash map that has the values for character types
    protected:
        char peek_next_char(); 
        char current_char(); 


    protected:
        Token* m_pcurrent_token; 
        TokenTypes m_current_type;
        // Add source file here. 
        std::unique_ptr<Source> source_code; 
        uint32_t m_index, m_line_number; 
        std::map<char, SOURCE_TYPE> m_source_map; 
};

