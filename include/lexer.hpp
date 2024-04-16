#pragma  once
#include <cstdint>
#include <map>
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

    struct Next_Token {
       uint32_t index;
       TokenTypes next_type;
       char next_value;
    };

    public: 
        Tokens *tokens; 

        Lexer(): tokens(new Tokens()), 
        m_pcurrent_token(nullptr), 
        m_current_type(TokenTypes::NONE) {
        
        }

        virtual ~Lexer(); 

        void read_file(const std::string& file_name); 
        void generate_tokens(); 
        void initialize();

    protected:
        Token* m_pcurrent_token; 
        TokenTypes m_current_type;
        std::string m_file_buffer;

        std::map<char, SOURCE_TYPE> m_source_map; 
};

