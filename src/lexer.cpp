#include "../include/lexer.hpp"
#include "../include/source.hpp"
#include <iostream>
#include <memory>
#include "../include/utilities.hpp"

Lexer::~Lexer() {
    SAFE_RELEASE_VECTOR(*tokens);
}

void Lexer::initialize() {
    POPULATE_MAP(m_source_map, '!', '@', SOURCE_TYPE::SIGNS);
    POPULATE_MAP(m_source_map, '0', '9', SOURCE_TYPE::NUMBERIC);
    POPULATE_MAP(m_source_map, 'A', 'Z', SOURCE_TYPE::ALPHANUMERIC);
    POPULATE_MAP(m_source_map, 'a', 'z', SOURCE_TYPE::ALPHANUMERIC);

    m_source_map[' '] = SOURCE_TYPE::WHITESPACE; 
    m_source_map['\n'] = SOURCE_TYPE::WHITESPACE; 
    m_source_map['\r'] = SOURCE_TYPE::WHITESPACE; 
}


void Lexer::read_file(const std::string& file_name) {
    source_code = std::make_unique<Source>();
    source_code->initialize(file_name);
}

// scans the file buffer line by line in the source. 
void Lexer::scan() {    
}

// Tokenize file 
// This will be going through the buffer we have generated and then generate the tokens. 
