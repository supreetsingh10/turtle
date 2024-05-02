#include "../include/lexer.hpp"
#include "../include/source.hpp"
#include <cassert>
#include <memory>
#include "../include/utilities.hpp"

Lexer::~Lexer() 
{
    SAFE_RELEASE_VECTOR(*tokens);
}


void Lexer::read_file(const std::string& file_name) 
{
    source_code = std::make_unique<Source>();
    source_code->initialize(file_name);
}

// m_pcurrent_token; 
// scans the file buffer line by line in the source. 
void Lexer::scan() 
{    
    std::string line; 
    // getting the line here. 
    while (std::getline(source_code->get_file_buffer(), line)) 
    {
        m_index = 0; 
        while (m_index < line.length()) {
           if(m_pcurrent_token == nullptr) 
           {
               const TokenTypes current_type = Token::get_type(line[m_index]); 
               switch (current_type) {
                   case IDENTIFIER:
                       m_pcurrent_token = new Identifier(); 
                       break; 
                   case NUMBER: 
                       m_pcurrent_token = new Numbers(); 
                       break;
                       // Will need to handle the double and single quotes here. 
                   case LITERAL: 
                       m_pcurrent_token = new Literal(); 
                       break; 
                    case WHITESPACE:
                       m_pcurrent_token = nullptr; 
                       break; 
                   default:
                       m_pcurrent_token = nullptr; 
                       break; 
               }
               // if current_token is a nullptr, then I want to check the character. 
               // if it is not then we keep on parsing
           } else 
           {
               bool flag = m_pcurrent_token->parse(line[m_index], line[m_index + 1]); 
              // check if we have to keep parsing the current character in the current token.  

           }
        }
    }
}
