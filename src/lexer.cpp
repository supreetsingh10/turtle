#include "../include/lexer.hpp"
#include <cstddef>
#include <fstream>


std::string Lexer::read_file(const std::string& file_name) {
    const size_t MAX_SIZE = std::size_t(4096); 
    std::ifstream stream = std::ifstream(file_name); 

    std::string out = std::string(); 
    std::string buffer = std::string(MAX_SIZE, '\0');

    while (stream.read(&buffer[0], MAX_SIZE)) {
       out.append(buffer, 0, stream.gcount()); 
    }

    out.append(buffer, 0, stream.gcount());
    return out;
}

