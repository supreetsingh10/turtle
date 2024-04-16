#include "../include/lexer.hpp"
#include <cstddef>
#include <fstream>
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

void Lexer::generate_tokens() {

}

void Lexer::read_file(const std::string& file_name) {
    const size_t MAX_SIZE = std::size_t(4096); 
    std::ifstream stream = std::ifstream(file_name); 

    std::string out = std::string(); 
    std::string buffer = std::string(MAX_SIZE, '\0');

    while (stream.read(&buffer[0], MAX_SIZE)) {
       out.append(buffer, 0, stream.gcount()); 
    }

    out.append(buffer, 0, stream.gcount());

    m_file_buffer = out; 
}

// Tokenize file 
// This will be going through the buffer we have generated and then generate the tokens. 
