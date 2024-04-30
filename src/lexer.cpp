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


void Lexer::tokenize(
        std::string& value, 
        const SOURCE_TYPE& current_type,
        const SOURCE_TYPE& next_type
        ) 
{
}

// scans the file buffer line by line in the source. 
void Lexer::scan() {    
    std::string line; 
    while (std::getline(source_code->get_file_buffer(), line)) {
        std::string token_value = "";


        m_line_number++; 
      // so the file is being read line by line.   
      // we want to parse through the string and check the current character, 
      // peek the next character. 
      // if the current charater is of a different type then break the checking through the loop but
      // 0
    }
}

// Tokenize file 
// This will be going through the buffer we have generated and then generate the tokens. 
