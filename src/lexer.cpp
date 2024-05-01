#include "../include/lexer.hpp"
#include "../include/source.hpp"
#include <memory>
#include "../include/utilities.hpp"

Lexer::~Lexer() 
{
    SAFE_RELEASE_VECTOR(*tokens);
}

void Lexer::initialize() 
{
    POPULATE_MAP(m_source_map, '!', '@', SOURCE_TYPE::SIGNS);
    POPULATE_MAP(m_source_map, '0', '9', SOURCE_TYPE::NUMBERIC);
    POPULATE_MAP(m_source_map, 'A', 'Z', SOURCE_TYPE::ALPHABET);
    POPULATE_MAP(m_source_map, 'a', 'z', SOURCE_TYPE::ALPHABET);

    m_source_map[' '] = SOURCE_TYPE::WHITESPACE; 
    m_source_map['\n'] = SOURCE_TYPE::WHITESPACE; 
    m_source_map['\r'] = SOURCE_TYPE::WHITESPACE; 
}


void Lexer::read_file(const std::string& file_name) 
{
    source_code = std::make_unique<Source>();
    source_code->initialize(file_name);
}

// m_pcurrent_token; 
void Lexer::tokenize(
        const std::string& out_value, 
        const SOURCE_TYPE& current_type,
        const SOURCE_TYPE& next_type
        ) 
{
    // this is the place where the current token type is fixed. 
    // This will be the function that will be fitting the specific types. 
    switch (current_type) {
        case SIGNS :
            break;
        case STRING:
            // anything goes here. 
            break;
        case ALPHABET:
            break; 
        case ALPHANUMERIC:
            break; 
        case NUMBERIC: 
            break; 
        case WHITESPACE:
            break;
        default:
            break; 
    }
}

// scans the file buffer line by line in the source. 
void Lexer::scan() {    
    std::string line; 
    // getting the line here. 
    while (std::getline(source_code->get_file_buffer(), line)) 
    {
        bool first_char = true; 
        SOURCE_TYPE current_type, next_type; 
        std::string token_value = "";
        // loop through the line, word by word. 
        for(int idx = 0; idx < line.length(); idx++) 
        {
            if(first_char) 
            {
               current_type = m_source_map[line[idx]]; 
               first_char = false; 
            }

            // get the overall token type for the next character. 
            int next_idx = idx + 1; 
            if(idx < line.length()) 
            {
                SOURCE_TYPE next_type = m_source_map[line[next_idx]]; 
                token_value += line[idx]; 
                tokenize(token_value, current_type, next_type); 
            } else {
               // just tokenize the current value.  
            }
        }

        m_line_number++; 
        m_index = 0; 
      // so the file is being read line by line.   
      // we want to parse through the string and check the current character, 
      // peek the next character. 
      // if the current charater is of a different type then break the checking through the loop but
      // 0
      }
}

// Tokenize file 
// This will be going through the buffer we have generated and then generate the tokens. 
