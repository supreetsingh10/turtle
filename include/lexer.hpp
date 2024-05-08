#pragma  once
#include <cstdint>
#include "../include/source.hpp"
#include <memory>
#include <vector>
#include <string>
#include "../include/token.hpp"

class Lexer {
    typedef std::vector<Token*> Tokens;

    public: 
        Tokens *m_vptokens; 

        Lexer(): m_vptokens(new Tokens()), 
        m_pcurrent_token(nullptr), 
        m_current_type(TokenTypes::NONE) {

        }

        virtual ~Lexer();

        void scan(); 
        void read_file(const std::string& file_name); 
        void tokenize(); 
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
};

