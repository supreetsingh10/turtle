#include "../include/lexer.hpp"
#include "../include/source.hpp"
#include <cassert>
#include <memory>
#include "../include/utilities.hpp"

Lexer::~Lexer() 
{
    assert(m_vptokens->size() != 0);
    SAFE_RELEASE_VECTOR(*m_vptokens);
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
    while (!source_code->get_file_buffer().eof()) 
    {
        char current_char = source_code->get_file_buffer().get(); 
        Utils::logger(current_char);
        if (m_pcurrent_token == nullptr) {
           TokenTypes current_type = Token::get_type(current_char); 
           switch (current_type) {
               case IDENTIFIER:
                   m_pcurrent_token = new Identifier(); 
                   m_pcurrent_token->set_type(TokenTypes::IDENTIFIER); 
                   break; 
               case NUMBER: 
                   m_pcurrent_token = new Numbers(); 
                   m_pcurrent_token->set_type(TokenTypes::NUMBER); 
                   break;
                       // Will need to handle the double and single quotes here. 
                case LITERAL: 
                   m_pcurrent_token = new Literal(); 
                   m_pcurrent_token->set_type(TokenTypes::LITERAL); 
                   break; 
                case WHITESPACE:
                   m_pcurrent_token = nullptr; 
                   break; 
                case OPERATOR:
                   m_pcurrent_token = new Operators(); 
                   m_pcurrent_token->set_type(TokenTypes::OPERATOR); 
                default:
                   m_pcurrent_token = nullptr; 
                   break; 
               }

        } 

        if (source_code->get_file_buffer().peek() != source_code->get_file_buffer().eof()) {
            // if it is not the end. 
            char next_char = source_code->get_file_buffer().peek(); 
            bool incompatible = m_pcurrent_token->parse(current_char, next_char); 

            if(incompatible) {
               m_vptokens->push_back(m_pcurrent_token->make_copy()); 
               delete m_pcurrent_token;
               m_pcurrent_token = nullptr;
               Utils::logger("Pushed");
            }
        } else {
            // handle the end; 
            if(m_pcurrent_token->parse_end(current_char)) {
               m_vptokens->push_back(m_pcurrent_token->make_copy()); 
               delete m_pcurrent_token;
               m_pcurrent_token = nullptr;
               break;
            }
        }
    }
}
