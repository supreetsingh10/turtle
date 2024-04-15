#include "../include/lexer.hpp"
#include <cstddef>
#include <fstream>

#define SAFE_RELEASE_VECTOR(vec) for(auto e : vec) delete e


Lexer::~Lexer() {
    SAFE_RELEASE_VECTOR(*tokens);
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
